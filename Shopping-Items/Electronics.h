#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "Shopping-items.h"
using namespace std;
class Electronics : public ShoppingItem {
private:
    int componentSerialNumber;
public:
    //default constructor
    Electronics() : ShoppingItem(), componentSerialNumber(0) {}

    // Constructor
    Electronics(const string& itemName, double itemPrice, int itemQuantity, int serialNumber) {
        //set values using setter methods from base class
        setName(itemName);
        setPrice(itemPrice);
        setQuantity(itemQuantity);
        setComponentSerialNumber(serialNumber); 
    }
    // Method to display electronic item details
    void displayElectronicsItem() const {
        cout << "Electronics Item - ";
        displayItem(); // Call base class method to display item details
    }
    void setComponentSerialNumber(int serialNumber) {
        componentSerialNumber = serialNumber;
    }
    int getComponentSerialNumber() const {
        return componentSerialNumber;
    }
    void persist(ofstream& ofs) override {
        ofs << "ELECTRONICS|" << getName() << "|" << getPrice() << "|" 
            << getQuantity() << "|" << componentSerialNumber << endl;
    }
    void load(istringstream& iss) override {
        string token;
        getline(iss, token, '|'); setName(token);
        getline(iss, token, '|'); setPrice(stod(token));
        getline(iss, token, '|'); setQuantity(stoi(token));
        getline(iss, token); setComponentSerialNumber(stoi(token));
    }
};

#endif