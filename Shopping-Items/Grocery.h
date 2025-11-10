#ifndef GROCERY_H
#define GROCERY_H
#include "Shopping-items.h"


class Grocery: public ShoppingItem {
    private:
    string type; // e.g., vegetable, fruit, dairy
public:
    // default constructor
    Grocery() : ShoppingItem(), type("") {}
    // Constructor
    Grocery(const string& itemName, double itemPrice, int itemQuantity, const string& groceryType) {
        //set values using setter methods from base class
        setName(itemName);
        setPrice(itemPrice);
        setQuantity(itemQuantity);
        setType(groceryType);
    }
    // Method to display grocery item details
    void displayGroceryItem() const {
        cout << "Grocery Item - ";
        displayItem(); // Call base class method to display item details
    }
    void setType(const string& groceryType) {
        type = groceryType;
    }
    string getType() const {
        return type;
    }
    void persist(ofstream& ofs) override {
        ofs << "GROCERY|" << getName() << "|" << getPrice() << "|" 
            << getQuantity() << "|" << type << endl;
    }
    void load(istringstream& iss) override {
        string token;
        getline(iss, token, '|'); setName(token);
        getline(iss, token, '|'); setPrice(stod(token));
        getline(iss, token, '|'); setQuantity(stoi(token));
        getline(iss, token); setType(token);
    }

    
};

#endif