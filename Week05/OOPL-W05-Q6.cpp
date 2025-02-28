#include <iostream>
#include <string>

class CoffeeShop 
{
public:
    std::string name;
    std::string menu[6];
    float prices[6];
    std::string orders[10];
    int orderCount = 0;

    CoffeeShop(std::string shopName) 
    {
        name = shopName;
    }

    void addMenuItem(std::string item, float price) 
    {
        static int index = 0;
        if (index < 6) 
        {
            menu[index] = item;
            prices[index] = price;
            index++;
        }
    }

    std::string addOrder(std::string item) 
    {
        for (int i = 0; i < 6; i++) 
        {
            if (menu[i] == item) 
            {
                if (orderCount < 10) 
                {
                    orders[orderCount] = item;
                    orderCount++;
                    return "Order added!";
                } 
                else 
                {
                    return "Order limit reached!";
                }
            }
        }
        return "This item is currently unavailable!";
    }

    std::string fulfillOrder() 
    {
        if (orderCount == 0) 
        {
            return "All orders have been fulfilled";
        } 
        else 
        {
            std::string order = orders[0];
            for (int i = 0; i < orderCount - 1; i++) 
            {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + order + " is ready!";
        }
    }

    void listOrders() 
    {
        if (orderCount == 0) 
        {
            std::cout << "No orders taken." << std::endl;
        } 
        else 
        {
            std::cout << "Orders taken:" << std::endl;
            for (int i = 0; i < orderCount; i++) 
            {
                std::cout << orders[i] << std::endl;
            }
        }
    }

    float dueAmount() 
    {
        float total = 0;
        for (int i = 0; i < orderCount; i++) 
        {
            for (int j = 0; j < 6; j++) 
            {
                if (menu[j] == orders[i]) 
                {
                    total += prices[j];
                }
            }
        }
        return total;
    }

    std::string cheapestItem() 
    {
        float minPrice = prices[0];
        std::string cheapest = menu[0];

        for (int i = 1; i < 6; i++) 
        {
            if (prices[i] < minPrice) 
            {
                minPrice = prices[i];
                cheapest = menu[i];
            }
        }
        return cheapest;
    }

    void drinksOnly() 
    {
        std::cout << "Drinks: ";
        for (int i = 0; i < 6; i++) 
        {
            if (menu[i] == "Coffee" || menu[i] == "Tea" || menu[i] == "Juice") 
            {
                std::cout << menu[i] << " ";
            }
        }
        std::cout << std::endl;
    }

    void foodOnly() {
        std::cout << "Food: ";
        for (int i = 0; i < 6; i++) 
        {
            if (menu[i] == "Sandwich" || menu[i] == "Pastry" || menu[i] == "Cake") 
            {
                std::cout << menu[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    CoffeeShop shop("Java's Coffee Shop");
    shop.addMenuItem("Coffee", 3.5);
    shop.addMenuItem("Tea", 2.5);
    shop.addMenuItem("Juice", 4.0);
    shop.addMenuItem("Sandwich", 5.0);
    shop.addMenuItem("Pastry", 2.0);
    shop.addMenuItem("Cake", 3.0);

    std::cout << shop.addOrder("Coffee") << std::endl;
    std::cout << shop.addOrder("Sandwich") << std::endl;
    std::cout << shop.addOrder("Pizza") << std::endl;

    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;

    std::cout << "Total due: $" << shop.dueAmount() << std::endl;

    std::cout << "Cheapest item: " << shop.cheapestItem() << std::endl;

    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}