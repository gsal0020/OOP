#ifndef CLOTHING_H
#define CLOTHING_H
#include "Shopping-items.h"
using namespace std;

class Clothing: public ShoppingItem {
private:
    string size; // e.g., S, M, L, XL
    string material; // e.g., cotton, polyester
public:
// Constructor
    Clothing(const string& itemName, double itemPrice, int itemQuantity, const string& clothingSize, const string& clothingMaterial) {
        //set values using setter methods from base class
        setName(itemName);
        setPrice(itemPrice);
        setQuantity(itemQuantity);
        setSize(clothingSize);
        setMaterial(clothingMaterial);
    }
void setSize(const string& clothingSize) {
        size = clothingSize;
    }
    string getSize() const {
        return size;
    }
    void setMaterial(const string& clothingMaterial) {
        material = clothingMaterial;
    }
    string getMaterial() const {
        return material;
    }
    // Method to display clothing item details
    void displayClothingItem() const {
        cout << "Clothing Item - ";
        displayItem(); // Call base class method to display item details
        cout << "Size: " << size << ", Material: " << material << endl;
    }


};
#endif