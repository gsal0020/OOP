#ifndef BOOK_H
#define BOOK_H
#include "Shopping-items.h"
using namespace std;
class Book: public ShoppingItem {
private:
    string author;
    string publisher;
public:
    // Constructor
    Book(const string& itemName, double itemPrice, int itemQuantity, const string&
            bookAuthor, const string& bookPublisher) {
            //set values using setter methods from base class
            setName(itemName);
            setPrice(itemPrice);
            setQuantity(itemQuantity);
            setAuthor(bookAuthor);
            setPublisher(bookPublisher);
        }
    void setAuthor(const string& bookAuthor) {
        author = bookAuthor;
    }
    string getAuthor() const {
        return author;
    }
    void setPublisher(const string& bookPublisher) {
        publisher = bookPublisher;
    }
    string getPublisher() const {
        return publisher;
    }
    // Method to display book item details
    void displayBookItem() const {
        cout << "Book Item - ";
        displayItem(); // Call base class method to display item details
        cout << "Author: " << author << ", Publisher: " << publisher << endl;
    }
};
#endif
