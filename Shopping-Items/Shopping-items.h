#ifndef SHOPPING_ITEMS_H
#define SHOPPING_ITEMS_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class ShoppingItem {
private:
    string name;
    double price;
    int quantity;
public:
    virtual ~ShoppingItem() = default; //calling destructor
    virtual void persist(ofstream& ofs)=0; // pure virtual function for persistence
    virtual void load(istringstream& iss )=0; // pure virtual function for loading
// getters methods of abstract class
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    int getQuantity() const {
        return quantity;
    }
// setters methods of abstract class
    void setName(const string& itemName) {
        name = itemName;
    }
    void setPrice(double itemPrice) {
        price = itemPrice;
    }
    void setQuantity(int itemQuantity) {
        quantity = itemQuantity;
    }
    void displayItem() const {
        cout << "Item: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
    void TotalCost() const {
        double total = price * quantity;
        cout << "Total Cost for " << name << ": $" << total << endl;
    }




};


#endif