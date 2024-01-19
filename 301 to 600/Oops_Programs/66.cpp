#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author {
public:
    string name;

    Author(const string& n) : name(n) {}
};

class Book {
public:
    string title;
    Author* author;

    Book(const string& t, Author* a) : title(t), author(a) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Added book: " << book.title << " by " << book.author->name << endl;
    }

    void searchByAuthor(const Author& author) const {
        cout << "Books by " << author.name << ":" << endl;
        for (const auto& book : books) {
            if (book.author == &author) {
                cout << "- " << book.title << endl;
            }
        }
    }
};

int main() {
    Author author1("John Doe");
    Author author2("william");

    Book book1("Introduction to C++", &author1);
    Book book2("Advanced Programming", &author2);

    Library library;
    library.addBook(book1);
    library.addBook(book2);

    library.searchByAuthor(author1);

    return 0;
}
