#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>

class Logger
{
private:
    std::vector<std::string> logs;
    size_t maxSize;
    std::string auditPassword;

    std::string getCurrentTimestamp() const
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm *now_tm = std::localtime(&now_time);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
        return std::string(buffer);
    }

    void addLog(const std::string &formattedMessage)
    {
        if (logs.size() >= maxSize)
        {
            logs.erase(logs.begin());
        }
        logs.push_back(formattedMessage);
    }

    void log(const std::string &severity, const std::string &module, const std::string &message)
    {
        std::string formatted = getCurrentTimestamp() + " [" + severity + "] [" + module + "] " + message;
        addLog(formatted);
    }

public:
    Logger(size_t maxLogs = 1000, const std::string &password = "secure123")
        : maxSize(maxLogs), auditPassword(password) {}

    void logInfo(const std::string &module, const std::string &message)
    {
        log("INFO", module, message);
    }

    void logWarning(const std::string &module, const std::string &message)
    {
        log("WARN", module, message);
    }

    void logError(const std::string &module, const std::string &message)
    {
        log("ERROR", module, message);
    }

    std::vector<std::string> getLogs(const std::string &password) const
    {
        if (password == auditPassword)
        {
            return logs;
        }
        return {};
    }
};

int main()
{
    Logger logger;

    logger.logInfo("Network", "Connection established");
    logger.logError("Network", "Timeout occurred");
    logger.logWarning("Database", "Slow query detected");

    for (int i = 0; i < 1005; ++i)
    {
        logger.logInfo("Test", "Message " + std::to_string(i));
    }

    std::vector<std::string> auditLogs = logger.getLogs("secure123");
    std::cout << "Audit Logs (" << auditLogs.size() << " entries):\n";
    for (const auto &entry : auditLogs)
    {
        std::cout << entry << '\n';
    }

    std::vector<std::string> invalidLogs = logger.getLogs("wrongpass");
    std::cout << "Invalid access attempt: " << invalidLogs.size() << " entries\n";

    return 0;
}