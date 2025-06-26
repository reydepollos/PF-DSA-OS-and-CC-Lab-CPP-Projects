#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    string bookTitle;
    string bookAuthor;
    int publicationYear;
    bool isAvailable;
};

void searchBookByTitle(Book books[], int bookCount, const string& title) {
    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].bookTitle == title) {
            cout << "Book found:" << endl;
            cout << "Title: " << books[i].bookTitle << endl;
            cout << "Author: " << books[i].bookAuthor << endl;
            cout << "Year: " << books[i].publicationYear << endl;
            cout << "Availability: " << (books[i].isAvailable ? "Available" : "Issued") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

void displayBooksSortedByYear(Book books[], int bookCount) {
    sort(books, books + bookCount, [](Book a, Book b) {
        return a.publicationYear < b.publicationYear;
    });

    cout << "Books sorted by year of publication:" << endl;
    for (int i = 0; i < bookCount; ++i) {
        cout << "Title: " << books[i].bookTitle << ", Author: " << books[i].bookAuthor
             << ", Year: " << books[i].publicationYear
             << ", Availability: " << (books[i].isAvailable ? "Available" : "Issued") << endl;
    }
}

void updateBookAvailability(Book books[], int bookCount, const string& title, bool availability) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].bookTitle == title) {
            books[i].isAvailable = availability;
            cout << "Availability of book '" << books[i].bookTitle << "' updated successfully!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

int main() {
    int bookCount;

    do {
        cout << "Enter the number of books (2-30): ";
        cin >> bookCount;
        if (bookCount < 1 || bookCount > 30) {
            cout << "Please enter a valid number of books between 1 and 30." << endl;
        }
    } while (bookCount < 1 || bookCount > 30);

    Book books[30];

    for (int i = 0; i < bookCount; ++i) {
        cout << "Enter details for book " << i + 1 << ":" << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].bookTitle);

        cout << "Author: ";
        getline(cin, books[i].bookAuthor);

        cout << "Year of publication: ";
        cin >> books[i].publicationYear;

        cout << "Is the book available? (1 for available, 0 for issued): ";
        cin >> books[i].isAvailable;
    }

    int choice;
    do {
        cout << "\nLibrary System Menu:" << endl;
        cout << "1. Search for a book by title" << endl;
        cout << "2. Display all books sorted by year of publication" << endl;
        cout << "3. Update the availability of a book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title;
                cout << "Enter the title of the book to search: ";
                cin.ignore();
                getline(cin, title);
                searchBookByTitle(books, bookCount, title);
                break;
            }
            case 2:
                displayBooksSortedByYear(books, bookCount);
                break;
            case 3: {
                string title;
                bool availability;
                cout << "Enter the title of the book to update availability: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter the new availability status (1 for available, 0 for issued): ";
                cin >> availability;
                updateBookAvailability(books, bookCount, title, availability);
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
