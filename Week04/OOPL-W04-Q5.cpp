#include <iostream>
#include <string>

class MenuItem {
public:
    std::string name;
    std::string type;
    double price;

    MenuItem(std::string n = "", std::string t = "", double p = 0.0) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    std::string name;
    MenuItem* menu;
    int menuSize;
    std::string* orders;
    int ordersCapacity;
    int ordersCount;

public:
    CoffeeShop(std::string n, MenuItem* m, int size) 
        : name(n), menu(new MenuItem[size]), menuSize(size), orders(new std::string[10]), ordersCapacity(10), ordersCount(0) {
        for (int i = 0; i < menuSize; ++i) {
            menu[i] = m[i];
        }
    }

    ~CoffeeShop() {
        delete[] menu;
        delete[] orders;
    }

    std::string addOrder(std::string itemName) {
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i].name == itemName) {
                if (ordersCount >= ordersCapacity) {
                    int newCapacity = ordersCapacity * 2;
                    std::string* newOrders = new std::string[newCapacity];
                    for (int j = 0; j < ordersCount; ++j) {
                        newOrders[j] = orders[j];
                    }
                    delete[] orders;
                    orders = newOrders;
                    ordersCapacity = newCapacity;
                }
                orders[ordersCount++] = itemName;
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    std::string fulfillOrder() {
        if (ordersCount > 0) {
            std::string item = orders[0];
            for (int i = 1; i < ordersCount; ++i) {
                orders[i - 1] = orders[i];
            }
            ordersCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() const {
        for (int i = 0; i < ordersCount; ++i) {
            std::cout << orders[i] << " ";
        }
        std::cout << std::endl;
    }

    double dueAmount() const {
        double total = 0.0;
        for (int i = 0; i < ordersCount; ++i) {
            for (int j = 0; j < menuSize; ++j) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    std::string cheapestItem() const {
        if (menuSize == 0) return "";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; ++i) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    void drinksOnly() const {
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i].type == "drink") {
                std::cout << menu[i].name << " ";
            }
        }
        std::cout << std::endl;
    }

    void foodOnly() const {
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i].type == "food") {
                std::cout << menu[i].name << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    MenuItem menu[] = {
        MenuItem("Latte", "drink", 3.5),
        MenuItem("Cappuccino", "drink", 4.0),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Croissant", "food", 2.5)
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    CoffeeShop shop("My Coffee Shop", menu, menuSize);

    std::cout << shop.addOrder("Latte") << std::endl;
    std::cout << shop.addOrder("Sandwich") << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << "Orders: ";
    shop.listOrders();
    std::cout << "Total due: $" << shop.dueAmount() << std::endl;
    std::cout << "Cheapest item: " << shop.cheapestItem() << std::endl;
    std::cout << "Drinks: ";
    shop.drinksOnly();
    std::cout << "Food: ";
    shop.foodOnly();

    return 0;
}