#include <iostream>
#include <string>

class Books
{
protected:
    std::string genre;

public:
    Books(std::string genre) : genre(genre) {}

    virtual void displayDetails() = 0;

    virtual ~Books() {}
};

class Novel : public Books
{
private:
    std::string title;
    std::string author;

public:
    Novel(std::string title, std::string author)
        : Books("Novel"), title(title), author(author) {}

    void displayDetails() override
    {
        std::cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << std::endl;
    }
};

class Mystery : public Books
{
private:
    std::string title;
    std::string author;

public:
    Mystery(std::string title, std::string author)
        : Books("Mystery"), title(title), author(author) {}

    void displayDetails() override
    {
        std::cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << std::endl;
    }
};

int main()
{
    Books *book1 = new Novel("The Great Gatsby", "F. Scott Fitzgerald");
    Books *book2 = new Mystery("The Hound of the Baskervilles", "Arthur Conan Doyle");

    book1->displayDetails();
    book2->displayDetails();

    delete book1;
    delete book2;

    return 0;
}
