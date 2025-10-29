#ifndef TOYITEM_H
#define TOYITEM_H
#include "Shopping-items.h"
using namespace std;
class ToyItem:public ShoppingItem {
private:
    string ageGroup; // e.g., 3-5 years, 6-8
public:
    // Constructor
    ToyItem(const string& itemName, double itemPrice, int itemQuantity, const string& toyAgeGroup) {
        //set values using setter methods from base class
        setName(itemName);
        setPrice(itemPrice);
        setQuantity(itemQuantity);
        setAgeGroup(toyAgeGroup);
    }
    void setAgeGroup(const string& toyAgeGroup) {
        ageGroup = toyAgeGroup;
    }
    string getAgeGroup() const {
        return ageGroup;
    }
    // Method to display toy item details
    void displayToyItem() const {
        cout << "Toy Item - ";
        displayItem(); // Call base class method to display item details
        cout << "Age Group: " << ageGroup << endl;
    }

};
#endif