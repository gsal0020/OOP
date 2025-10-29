#ifndef GROCERY_H
#define GROCERY_H
#include "Shopping-items.h"


class Grocery: public ShoppingItem {
    private:
    string type; // e.g., vegetable, fruit, dairy
public:
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
    
};

#endif