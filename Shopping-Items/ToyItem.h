#ifndef TOYITEM_H
#define TOYITEM_H
#include "Shopping-items.h"
using namespace std;
class ToyItem:public ShoppingItem {
private:
    string ageGroup; // e.g., 3-5 years, 6-8
public:
    // default constructor
    ToyItem() : ShoppingItem(), ageGroup("") {}
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
    void persist(ofstream& ofs) override {
        ofs << "TOYITEM|" << getName() << "|" << getPrice() << "|" 
            << getQuantity() << "|" << ageGroup << endl;
    }
    void load(istringstream& iss) override {
        string token;
        getline(iss, token, '|'); setName(token);
        getline(iss, token, '|'); setPrice(stod(token));
        getline(iss, token, '|'); setQuantity(stoi(token));
        getline(iss, token); setAgeGroup(token);
    }
    

};
#endif