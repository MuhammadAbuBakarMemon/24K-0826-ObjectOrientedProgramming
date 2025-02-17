#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string publisher;
    double price;
    int stock;

public:
    Book(std::string auth, std::string ttl, std::string pub, double prc, int stk)
        : author(auth), title(ttl), publisher(pub), price(prc), stock(stk) {}

    std::string getAuthor() const {
        return author;
    }

    std::string getTitle() const {
        return title;
    }

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Publisher: " << publisher << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << " copies" << std::endl;
    }

    bool isAvailable(int requiredCopies) const {
        return stock >= requiredCopies;
    }

    void sellCopies(int requiredCopies) {
        if (isAvailable(requiredCopies)) {
            stock -= requiredCopies;
            std::cout << "Total cost: $" << (price * requiredCopies) << std::endl;
        } else {
            std::cout << "Required copies not in stock." << std::endl;
        }
    }
};

int main() {
    Book book1("Author1", "Title1", "Publisher1", 20.0, 10);
    Book book2("Author2", "Title2", "Publisher2", 15.0, 5);

    std::string searchTitle, searchAuthor;
    std::cout << "Enter book title: ";
    std::getline(std::cin, searchTitle);
    std::cout << "Enter book author: ";
    std::getline(std::cin, searchAuthor);

    if (book1.getTitle() == searchTitle && book1.getAuthor() == searchAuthor) {
        book1.displayDetails();
        int copies;
        std::cout << "Enter number of copies required: ";
        std::cin >> copies;
        book1.sellCopies(copies);
    } else if (book2.getTitle() == searchTitle && book2.getAuthor() == searchAuthor) {
        book2.displayDetails();
        int copies;
        std::cout << "Enter number of copies required: ";
        std::cin >> copies;
        book2.sellCopies(copies);
    } else {
        std::cout << "Book not found in inventory." << std::endl;
    }

    return 0;
}