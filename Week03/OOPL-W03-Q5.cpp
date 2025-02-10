#include <iostream>
#include <string>
using namespace std;

class Book 
{
    private:
        string bookName;
        string isbn;
        string author;
        string publisher;

    public:
        Book(string name, string isbn, string author, string publisher) 
        {
            this->bookName = name;
            this->isbn = isbn;
            this->author = author;
            this->publisher = publisher;
        }

        string getBookName() const 
        {
            return bookName;
        }

        string getISBN() const 
        {
            return isbn;
        }

        string getAuthor() const 
        {
            return author;
        }

        string getPublisher() const 
        {
            return publisher;
        }

        string getBookInfo() const 
        {
            return "Book Name: " + bookName + ", ISBN: " + isbn + ", Author: " + author + ", Publisher: " + publisher;
        }
};

int main(int argc, char* argv[]) 
{
    if (argc != 21) 
    {
        cerr << "Usage: " << argv[0] << " <name1> <isbn1> <author1> <publisher1> ... <name5> <isbn5> <author5> <publisher5>" << endl;
        return 1;
    }

    Book books[5] = 
    {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    for (int i = 0; i < 5; i++) 
    {
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}