#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(std::string number, std::string description, int qty, double price)
        : partNumber(number), partDescription(description), quantity(qty), pricePerItem(price) {
        if (quantity < 0) {
            quantity = 0;
        }
        if (pricePerItem < 0.0) {
            pricePerItem = 0.0;
        }
    }

    void setPartNumber(std::string number) {
        partNumber = number;
    }

    std::string getPartNumber() const {
        return partNumber;
    }

    void setPartDescription(std::string description) {
        partDescription = description;
    }

    std::string getPartDescription() const {
        return partDescription;
    }

    void setQuantity(int qty) {
        if (qty < 0) {
            quantity = 0;
        } else {
            quantity = qty;
        }
    }

    int getQuantity() const {
        return quantity;
    }

    void setPricePerItem(double price) {
        if (price < 0.0) {
            pricePerItem = 0.0;
        } else {
            pricePerItem = price;
        }
    }

    double getPricePerItem() const {
        return pricePerItem;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};