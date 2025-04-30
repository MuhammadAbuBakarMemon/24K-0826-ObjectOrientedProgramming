#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

class Logger {
private:
    string logFile = "log.txt";
    const size_t maxSize = 1024 * 1024;

    int getNextLogIndex() {
        int index = 1;
        while (fs::exists("log" + to_string(index) + ".txt")) {
            index++;
        }
        return index;
    }

    void rotateLog() {
        int index = getNextLogIndex();
        fs::rename(logFile, "log" + to_string(index) + ".txt");
    }

public:
    void log(const string& message) {
        if (fs::exists(logFile) && fs::file_size(logFile) >= maxSize) {
            rotateLog();
        }
        ofstream fout(logFile, ios::app);
        fout << message << endl;
        fout.close();
    }
};

class ToDoList {
private:
    string taskFile = "tasks.txt";

public:
    void addTask(const string& task) {
        ofstream fout(taskFile, ios::app);
        fout << "[ ] " << task << endl;
        fout.close();
    }

    void viewTasks() {
        ifstream fin(taskFile);
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }

    void markTaskDone(int taskNumber) {
        vector<string> tasks;
        ifstream fin(taskFile);
        string line;
        while (getline(fin, line)) {
            tasks.push_back(line);
        }
        fin.close();

        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            if (tasks[taskNumber - 1].substr(0, 3) == "[ ]") {
                tasks[taskNumber - 1].replace(0, 3, "[x]");
            }
        }

        ofstream fout(taskFile);
        for (const auto& task : tasks) {
            fout << task << endl;
        }
        fout.close();
    }
};

int main() {
    Logger logger;
    ToDoList todo;

    logger.log("App started");

    todo.addTask("Buy groceries");
    todo.addTask("Call John");
    todo.addTask("Finish project");

    cout << "Current Tasks:" << endl;
    todo.viewTasks();

    todo.markTaskDone(2);

    cout << "Updated Tasks:" << endl;
    todo.viewTasks();

    logger.log("App finished");

    return 0;
}
