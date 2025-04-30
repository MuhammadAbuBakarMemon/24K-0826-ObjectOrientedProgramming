#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class User {
public:
    string id, firstName, lastName, address, email;

    string toString() {
        return id + "," + firstName + "," + lastName + "," + address + "," + email;
    }

    static User fromString(const string& line) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) fields.push_back(field);
        return {fields[0], fields[1], fields[2], fields[3], fields[4]};
    }
};

class Product {
public:
    string id, name, description;
    int price;

    string toString() {
        return id + "," + name + "," + description + "," + to_string(price);
    }

    static Product fromString(const string& line) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) fields.push_back(field);
        return {fields[0], fields[1], fields[2], stoi(fields[3])};
    }
};

class Order {
public:
    string id, userId, productId;
    int totalPaid;

    string toString() {
        return id + "," + userId + "," + productId + "," + to_string(totalPaid);
    }

    static Order fromString(const string& line) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) fields.push_back(field);
        return {fields[0], fields[1], fields[2], stoi(fields[3])};
    }
};

class Database {
public:
    vector<User> users;
    vector<Product> products;
    vector<Order> orders;

    void insertDummyData() {
        ofstream uf("users.txt"), pf("products.txt"), of("orders.txt");

        uf << "u1,Linus,Torvalds,Helsinki,linus@example.com" << endl;
        uf << "u2,Ada,Lovelace,London,ada@example.com" << endl;

        pf << "p1,Laptop,Powerful laptop,1200" << endl;
        pf << "p2,Keyboard,Mechanical keyboard,100" << endl;
        pf << "p3,Mouse,Wireless mouse,50" << endl;

        of << "o1,u1,p1,1200" << endl;
        of << "o2,u1,p2,100" << endl;
        of << "o3,u2,p3,50" << endl;

        uf.close(); pf.close(); of.close();
    }

    void loadAll() {
        ifstream uf("users.txt"), pf("products.txt"), of("orders.txt");
        string line;

        while (getline(uf, line)) users.push_back(User::fromString(line));
        while (getline(pf, line)) products.push_back(Product::fromString(line));
        while (getline(of, line)) orders.push_back(Order::fromString(line));

        uf.close(); pf.close(); of.close();
    }

    void fetchProductsByUser(const string& userFirstName) {
        string userId;
        for (auto& u : users) {
            if (u.firstName == userFirstName) {
                userId = u.id;
                break;
            }
        }

        if (userId.empty()) {
            cout << "No user found with first name " << userFirstName << endl;
            return;
        }

        map<string, string> productMap;
        for (auto& p : products) {
            productMap[p.id] = p.name;
        }

        cout << "Products ordered by " << userFirstName << ":" << endl;
        for (auto& o : orders) {
            if (o.userId == userId) {
                cout << productMap[o.productId] << endl;
            }
        }
    }
};

int main() {
    Database db;
    db.insertDummyData();
    db.loadAll();
    db.fetchProductsByUser("Linus");
    return 0;
}
