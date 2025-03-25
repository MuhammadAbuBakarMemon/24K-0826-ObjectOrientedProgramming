#include <iostream>
#include <string>
#include <vector>

class Media {
protected:
    std::string title;
    std::string publicationDate;
    std::string uniqueID;
    std::string publisher;
    bool checkedOut;

public:
    Media(std::string t, std::string pd, std::string id, std::string pub)
        : title(t), publicationDate(pd), uniqueID(id), publisher(pub), checkedOut(false) {}

    virtual void displayInfo() {
        std::cout << "Title: " << title << "\n"
                  << "Publication Date: " << publicationDate << "\n"
                  << "ID: " << uniqueID << "\n"
                  << "Publisher: " << publisher << "\n"
                  << "Status: " << (checkedOut ? "Checked Out" : "Available") << "\n";
    }

    virtual bool checkOut() {
        if (checkedOut) return false;
        checkedOut = true;
        return true;
    }

    virtual bool returnItem() {
        if (!checkedOut) return false;
        checkedOut = false;
        return true;
    }

    std::string getTitle() { return title; }
    std::string getPublicationDate() { return publicationDate; }
    std::string getID() { return uniqueID; }
};

class Book : public Media {
private:
    std::string author;
    std::string ISBN;
    int numberOfPages;

public:
    Book(std::string t, std::string pd, std::string id, std::string pub, std::string a, std::string isbn, int pages)
        : Media(t, pd, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        std::cout << "Author: " << author << "\n"
                  << "ISBN: " << ISBN << "\n"
                  << "Pages: " << numberOfPages << "\n";
    }

    std::string getAuthor() { return author; }
};

class DVD : public Media {
private:
    std::string director;
    int duration;
    std::string rating;

public:
    DVD(std::string t, std::string pd, std::string id, std::string pub, std::string dir, int dur, std::string r)
        : Media(t, pd, id, pub), director(dir), duration(dur), rating(r) {}

    void displayInfo() override {
        Media::displayInfo();
        std::cout << "Director: " << director << "\n"
                  << "Duration: " << duration << " minutes\n"
                  << "Rating: " << rating << "\n";
    }

    std::string getDirector() { return director; }
};

class CD : public Media {
private:
    std::string artist;
    int numberOfTracks;
    std::string genre;

public:
    CD(std::string t, std::string pd, std::string id, std::string pub, std::string art, int tracks, std::string g)
        : Media(t, pd, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        std::cout << "Artist: " << artist << "\n"
                  << "Tracks: " << numberOfTracks << "\n"
                  << "Genre: " << genre << "\n";
    }

    std::string getArtist() { return artist; }
};

class Magazine : public Media {
private:
    int issueNumber;
    std::string editor;

public:
    Magazine(std::string t, std::string pd, std::string id, std::string pub, int issue, std::string ed)
        : Media(t, pd, id, pub), issueNumber(issue), editor(ed) {}

    void displayInfo() override {
        Media::displayInfo();
        std::cout << "Issue: " << issueNumber << "\n"
                  << "Editor: " << editor << "\n";
    }

    std::string getEditor() { return editor; }
};

class Library {
private:
    std::vector<Media*> collection;

public:
    void addMedia(Media* m) {
        collection.push_back(m);
    }

    void displayAll() {
        for (Media* m : collection) {
            m->displayInfo();
            std::cout << "----------------\n";
        }
    }

    Media* searchByTitle(std::string title) {
        for (Media* m : collection) {
            if (m->getTitle() == title) {
                return m;
            }
        }
        return nullptr;
    }

    Media* searchByID(std::string id) {
        for (Media* m : collection) {
            if (m->getID() == id) {
                return m;
            }
        }
        return nullptr;
    }

    std::vector<Media*> searchByYear(std::string year) {
        std::vector<Media*> results;
        for (Media* m : collection) {
            if (m->getPublicationDate().find(year) != std::string::npos) {
                results.push_back(m);
            }
        }
        return results;
    }
};

int main() {
    Library library;

    Book book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd("Thriller", "1982-11-30", "C001", "Epic", "Michael Jackson", 9, "Pop");
    Magazine magazine("National Geographic", "2023-03-01", "M001", "National Geographic Society", 123, "Susan Goldberg");

    library.addMedia(&book);
    library.addMedia(&dvd);
    library.addMedia(&cd);
    library.addMedia(&magazine);

    library.displayAll();

    Media* found = library.searchByTitle("Inception");
    if (found) {
        std::cout << "\nFound item:\n";
        found->displayInfo();
    }

    std::vector<Media*> yearResults = library.searchByYear("2023");
    std::cout << "\nItems from 2023:\n";
    for (Media* m : yearResults) {
        m->displayInfo();
        std::cout << "----------------\n";
    }

    return 0;
}