#include <iostream>
#include <string>

using namespace std;

class Book 
{
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) 
        : title(t), author(a), isbn(i) {}

    void displayInfo() const 
    {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog 
{
private:
    Book* bookIndex[100]; // Array to store pointers to books
    int currentIndex = 0;

public:
    void addBook(Book* book) 
    {
        if (currentIndex < 100) {
            bookIndex[currentIndex] = book;
            currentIndex++;
        } 
        else 
        {
            cout << "Catalog is full!" << endl;
        }
    }

    Book* findBookByISBN(const string& isbn) 
    {
        for (int i = 0; i < currentIndex; ++i) 
        {
            if (bookIndex[i]->isbn == isbn) 
            {
                return bookIndex[i];
            }
        }
        return nullptr;
    }
};

class Library 
{
private:
    Catalog catalog;
    Book* books[100];
    int bookCount = 0;
    string name;
    string address;

public:
    Library(string libraryName, string libraryAddress)
        : name(libraryName), address(libraryAddress) {}

    void addBook(Book* book) 
    {
        if (bookCount < 100) 
        {
            books[bookCount] = book;
            catalog.addBook(book);
            bookCount++;
        } 
        else 
        {
            cout << "Library is full!" << endl;
        }
    }

    void removeBook(const string& isbn) 
    {
        for (int i = 0; i < bookCount; ++i) 
        {
            if (books[i]->isbn == isbn) 
            {
                for (int j = i; j < bookCount - 1; ++j) 
                {
                    books[j] = books[j + 1];
                }
                books[bookCount - 1] = nullptr;
                bookCount--;
                return;
            }
        }
    }

    Book* findBookInCatalog(const string& isbn) 
    {
        return catalog.findBookByISBN(isbn);
    }

    void displayLibraryInfo() const 
    {
        cout << "Library Name: " << name << "\nAddress: " << address << endl;
    }
};

int main() 
{
    Library myLibrary("City Library", "123 Library St.");

    Book* book1 = new Book("C++ Programming", "Bjarne Stroustrup", "123456789");
    Book* book2 = new Book("Data Structures", "Robert Sedgewick", "987654321");

    myLibrary.addBook(book1);
    myLibrary.addBook(book2);

    myLibrary.displayLibraryInfo();

    cout << "Searching for ISBN 123456789 in catalog..." << endl;
    Book* foundBook = myLibrary.findBookInCatalog("123456789");

    if (foundBook) 
    {
        foundBook->displayInfo();
    } 
    else 
    {
        cout << "Book not found!" << endl;
    }

    cout << "Removing book with ISBN 987654321..." << endl;
    myLibrary.removeBook("987654321");

    cout << "Searching for ISBN 987654321 in catalog..." << endl;
    foundBook = myLibrary.findBookInCatalog("987654321");

    if (foundBook) 
    {
        foundBook->displayInfo();
    } 
    else 
    {
        cout << "Book not found!" << endl;
    }

    delete book1;
    delete book2;

    return 0;
}
