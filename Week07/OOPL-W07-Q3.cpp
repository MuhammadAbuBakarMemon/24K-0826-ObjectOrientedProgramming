#include <iostream>
#include <string>
#include <map>
#include <iomanip>

class Currency
{
protected:
    double amount;
    std::string currencyCode;
    std::string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, const std::string &code, const std::string &symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual ~Currency() {}

    virtual double convertToBase() const
    {
        return amount * exchangeRate;
    }

    virtual double convertTo(const std::string &targetCode, const std::map<std::string, double> &rates) const
    {
        if (rates.find(currencyCode) == rates.end() || rates.find(targetCode) == rates.end())
        {
            std::cerr << "Error: Missing exchange rate data for conversion\n";
            return 0.0;
        }
        double baseAmount = convertToBase();
        return baseAmount / rates.at(targetCode);
    }

    virtual void display() const
    {
        std::cout << currencySymbol << std::fixed << std::setprecision(2) << amount;
    }

    double getAmount() const { return amount; }
    std::string getCode() const { return currencyCode; }
    std::string getSymbol() const { return currencySymbol; }
    double getExchangeRate() const { return exchangeRate; }

    void setAmount(double amt) { amount = amt; }
    void setExchangeRate(double rate) { exchangeRate = rate; }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$") {}

    // USD is already base currency
    double convertToBase() const override
    {
        return amount;
    }

    void display() const override
    {
        std::cout << currencySymbol << std::fixed << std::setprecision(2) << amount;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt, double rate) : Currency(amt, "EUR", "€", rate) {}

    void display() const override
    {
        std::cout << std::fixed << std::setprecision(2) << amount << " " << currencySymbol;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt, double rate) : Currency(amt, "INR", "₹", rate) {}

    void display() const override
    {
        std::cout << currencySymbol << std::fixed << std::setprecision(2) << amount;
    }
};

class CurrencyConverter
{
private:
    std::map<std::string, double> exchangeRates;

public:
    CurrencyConverter()
    {
        exchangeRates["USD"] = 1.0;
        exchangeRates["EUR"] = 0.92;
        exchangeRates["INR"] = 83.25;
        exchangeRates["GBP"] = 0.79;
        exchangeRates["JPY"] = 151.50;
    }

    void updateRate(const std::string &code, double rate)
    {
        if (exchangeRates.find(code) != exchangeRates.end())
        {
            exchangeRates[code] = rate;
        }
        else
        {
            exchangeRates.insert({code, rate});
        }
    }

    double getRate(const std::string &code) const
    {
        auto it = exchangeRates.find(code);
        if (it != exchangeRates.end())
        {
            return it->second;
        }
        return 0.0;
    }

    double convert(const Currency &source, const std::string &targetCode) const
    {
        return source.convertTo(targetCode, exchangeRates);
    }

    // Display conversion result
    void displayConversion(const Currency &source, const std::string &targetCode) const
    {
        double convertedAmount = convert(source, targetCode);

        std::cout << "Conversion: ";
        source.display();
        std::cout << " (" << source.getCode() << ") = ";

        if (targetCode == "USD")
            std::cout << "$";
        else if (targetCode == "EUR")
            std::cout << convertedAmount << " €";
        else if (targetCode == "INR")
            std::cout << "₹";
        else if (targetCode == "GBP")
            std::cout << "£";
        else if (targetCode == "JPY")
            std::cout << "¥";

        std::cout << std::fixed << std::setprecision(2) << convertedAmount;
        std::cout << " (" << targetCode << ")\n";
    }
};

int main()
{
    CurrencyConverter converter;

    // Create some currencies
    Dollar usd(100.0);
    Euro eur(85.0, converter.getRate("EUR"));
    Rupee inr(5000.0, converter.getRate("INR"));

    std::cout << "Initial amounts:\n";
    usd.display();
    std::cout << "\n";
    eur.display();
    std::cout << "\n";
    inr.display();
    std::cout << "\n\n";

    std::cout << "Conversion examples:\n";
    converter.displayConversion(usd, "EUR");
    converter.displayConversion(usd, "INR");
    converter.displayConversion(eur, "USD");
    converter.displayConversion(eur, "INR");
    converter.displayConversion(inr, "USD");
    converter.displayConversion(inr, "EUR");

    std::cout << "\nUpdating EUR exchange rate to 0.95...\n";
    converter.updateRate("EUR", 0.95);
    eur.setExchangeRate(converter.getRate("EUR"));
    converter.displayConversion(usd, "EUR");
    converter.displayConversion(eur, "USD");

    return 0;
}