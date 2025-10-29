#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Shopping-items.h"
#include "Clothing.h"
#include "Electronics.h"
#include "Grocery.h"
#include "ToyItem.h"
#include "Book.h"

using namespace std;

int main(int, char**){
    string name, user_input,material,type,ageGroup,author, publisher;
    char size;
    double price;
    int quantity, serialnumber;
    vector<unique_ptr<ShoppingItem>> ShoppingItems;

    // Add items from user's console input
    cout << "Welcome to the Shopping Item Manager!" << endl;
    
    
    while(user_input != "q" && user_input != "quit") {
        cout << "Enter item type (Clothing, Electronics, Grocery, ToyItem, Book) q, quit: ";
        getline(cin, user_input);
        switch(toupper(user_input[0])) {
            case 'C': {
                // Handle Clothing item input
                cout << "Enter Clothing item details (name, price, quantity, size, material): ";
                cin >> name >> price >> quantity >> size >> material;
                ShoppingItems.push_back(make_unique<Clothing>(name, price, quantity, string(1, size), material));
                break;
            }
            case 'E': {
                // Handle Electronics item input
                cout << "Enter Electronics item details (name, price, quantity, serialnumber): ";
                cin >> name >> price >> quantity >> serialnumber;
                ShoppingItems.push_back(make_unique<Electronics>(name, price, quantity, serialnumber));
                break;
            }
            case 'G': {
                // Handle Grocery item input
                cout << "Enter Grocery item details (name, price, quantity, type): ";
                cin >> name >> price >> quantity >> type;
                ShoppingItems.push_back(make_unique<Grocery>(name, price, quantity, type));
                break;
            }
            case 'T': {
                // Handle ToyItem item input
                cout << "Enter ToyItem item details (name, price, quantity, ageGroup): ";
                cin >> name >> price >> quantity >> ageGroup;
                ShoppingItems.push_back(make_unique<ToyItem>(name, price, quantity, ageGroup));
                break;
            }
            case 'B': {
                // Handle Book item input
                cout << "Enter Book item details (name, price, quantity, author, publisher): ";
                cin >> name >> price >> quantity >> author >> publisher;
                ShoppingItems.push_back(make_unique<Book>(name, price, quantity, author, publisher));
                break;
            }
            default:
                cout << "Invalid item type entered." << endl;
        }
    }
    cout << "You have added the following items:" << endl;
    for (const auto& item : ShoppingItems) {
        cout << "- " << item->getName() << endl;
        item->TotalCost();
    }
    return 0;
}
