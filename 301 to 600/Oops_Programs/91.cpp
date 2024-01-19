#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Author {
private:
    string name;

public:
    Author(const string& authorName) : name(authorName) {}

    const string& getName() const {
        return name;
    }
};

class Book {
private:
    string title;
    Author author;
    bool isAvailable;

public:
    Book(const string& bookTitle, const Author& bookAuthor) : title(bookTitle), author(bookAuthor), isAvailable(true) {}

    const string& getTitle() const {
        return title;
    }

    const Author& getAuthor() const {
        return author;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book \"" << title << "\" by " << author.getName() << " has been borrowed.\n";
        } else {
            cout << "Book \"" << title << "\" is not available for borrowing.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book \"" << title << "\" by " << author.getName() << " has been returned.\n";
        } else {
            cout << "Book \"" << title << "\" is already available.\n";
        }
    }
};

class Member {
private:
    string name;
    vector<Book*> borrowedBooks;

public:
    Member(const string& memberName) : name(memberName) {}

    const string& getName() const {
        return name;
    }

    void borrowBook(Book& book) {
        if (book.getIsAvailable()) {
            borrowedBooks.push_back(&book);
            book.borrowBook();
        } else {
            cout << "Book \"" << book.getTitle() << "\" is not available for borrowing.\n";
        }
    }

    void returnBook(Book& book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            book.returnBook();
        } else {
            cout << "You did not borrow book \"" << book.getTitle() << "\".\n";
        }
    }

    void displayBorrowedBooks() const {
        cout << "Borrowed Books by " << name << ":\n";
        cout << "------------------------\n";
        for (const Book* book : borrowedBooks) {
            cout << "Title: " << book->getTitle() << " by " << book->getAuthor().getName() << "\n";
        }
        cout << "------------------------\n";
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(const string& title, const string& authorName) {
        Author author(authorName);
        books.emplace_back(title, author);
    }

    void addMember(const string& memberName) {
        members.emplace_back(memberName);
    }

    Book* findBook(const string& title) {
        for (Book& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    Member* findMember(const string& memberName) {
        for (Member& member : members) {
            if (member.getName() == memberName) {
                return &member;
            }
        }
        return nullptr;
    }

    void displayBooks() const {
        cout << "Library Books:\n";
        cout << "------------------------\n";
        for (const Book& book : books) {
            cout << "Title: " << book.getTitle() << " by " << book.getAuthor().getName() << " - "
                 << (book.getIsAvailable() ? "Available" : "Not Available") << "\n";
        }
        cout << "------------------------\n";
    }
};

int main() {
    using namespace std;

    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    library.addMember("Alice");
    library.addMember("Bob");

    library.displayBooks();

    Member* alice = library.findMember("Alice");
    Member* bob = library.findMember("Bob");

    Book* gatsby = library.findBook("The Great Gatsby");
    Book* mockingbird = library.findBook("To Kill a Mockingbird");
    Book* nineteenEightyFour = library.findBook("1984");

    if (alice && bob && gatsby && mockingbird && nineteenEightyFour) {
        alice->borrowBook(*gatsby);
        bob->borrowBook(*mockingbird);

        alice->displayBorrowedBooks();
        bob->displayBorrowedBooks();

        alice->returnBook(*gatsby);
        bob->returnBook(*mockingbird);

        alice->displayBorrowedBooks();
        bob->displayBorrowedBooks();
    }

    return 0;
}
