#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include "Shopping-items.h"
#include "Clothing.h"
#include "Electronics.h"
#include "Grocery.h"
#include "ToyItem.h"
#include "Book.h"

using namespace std;

int main(int, char**){
    string name, user_input,material,type,ageGroup,author, publisher,data;
    char size;
    double price;
    int quantity, serialnumber;
    vector<unique_ptr<ShoppingItem>> ShoppingItems;

    // Add items from user's console input
    cout << "Welcome to the Shopping Item Manager!" << endl;
    cout << "Do you want to load existing items from a file? (y/n): ";
    char load_choice;
    if (!(cin >> load_choice)) {
        cout << "Invalid input. Exiting." << endl;
        return 1;
    }
    cin.ignore(); // To ignore the newline character left in the buffer
    
    if (tolower(load_choice) == 'y') {
        ifstream ifs("shopping_items.txt");
        if (!ifs) {
            cout << "Error opening file for reading or file doesn't exist." << endl;
        } else {
            string line;
            while (getline(ifs, line)) {
                if (line.empty()) continue;
                
                istringstream iss(line);
                string itemType;
                getline(iss, itemType, '|');
                
                if (itemType == "CLOTHING") {
                    auto clothing = std::make_unique<Clothing>();
                    clothing->load(iss);
                    cout << "Loaded Clothing Item: " << clothing->getName() << endl;
                    ShoppingItems.push_back(std::move(clothing));
                } else if (itemType == "ELECTRONICS") {
                    auto electronics = std::make_unique<Electronics>(name, price, quantity, serialnumber);
                    electronics->load(iss);
                    ShoppingItems.push_back(std::move(electronics));
                } else if (itemType == "GROCERY") {
                    auto grocery = std::make_unique<Grocery>(name, price, quantity, type);
                    grocery->load(iss);
                    ShoppingItems.push_back(std::move(grocery));
                } else if (itemType == "TOY") {
                    auto toy = std::make_unique<ToyItem>(name, price, quantity, ageGroup);
                    toy->load(iss);
                    ShoppingItems.push_back(std::move(toy));
                } else if (itemType == "BOOK") {
                    auto book = std::make_unique<Book>(name, price, quantity, author, publisher);
                    book->load(iss);
                    ShoppingItems.push_back(std::move(book));
                }
            }
            cout << "Loaded " << ShoppingItems.size() << " items from file." << endl;
        }
    }
    
    
    while(user_input != "q" && user_input != "quit") {
        cout << "Enter item type (Clothing, Electronics, Grocery, ToyItem, Book) q, quit: ";
        //using i string stream
        cin>> user_input;
        cin.ignore(); // To ignore the newline character left in the buffer
        switch(toupper(user_input[0])){
            
            case 'C': {
                // Handle Clothing item input
                cout << "Enter Clothing item details (name, price, quantity, size, material): ";
                getline(cin, data);
                istringstream iss(data);
                if (!(iss >> name >> price >> quantity >> size >> material)) {
                    cout << "Invalid input format. Please try again." << endl;
                    continue; // Skip to the next iteration
                }
                ShoppingItems.push_back(make_unique<Clothing>(name, price, quantity, string(1, size), material));
                break;
            }
            case 'E': {
                // Handle Electronics item input
                cout << "Enter Electronics item details (name, price, quantity, serialnumber): ";
                getline(cin, data);
                istringstream iss(data);
                if (!(iss >> name >> price >> quantity >> serialnumber)) {
                    cout << "Invalid input format. Please try again." << endl;
                    continue; // Skip to the next iteration
                }
                ShoppingItems.push_back(make_unique<Electronics>(name, price, quantity, serialnumber));
                break;
            }
            case 'G': {
                // Handle Grocery item input
                cout << "Enter Grocery item details (name, price, quantity, type): ";
                getline(cin, data);
                istringstream iss(data);
                if (!(iss >> name >> price >> quantity >> type)) {
                    cout << "Invalid input format. Please try again." << endl;
                    continue; // Skip to the next iteration
                }
                ShoppingItems.push_back(make_unique<Grocery>(name, price, quantity, type));
                break;
            }
            case 'T': {
                // Handle ToyItem item input
                cout << "Enter ToyItem item details (name, price, quantity, ageGroup): ";
                getline(cin, data);
                istringstream iss(data);
                if (!(iss >> name >> price >> quantity >> ageGroup)) {
                    cout << "Invalid input format. Please try again." << endl;
                    continue; // Skip to the next iteration
                }
                ShoppingItems.push_back(make_unique<ToyItem>(name, price, quantity, ageGroup));
                break;
            }
            case 'B': {
                // Handle Book item input
                cout << "Enter Book item details (name, price, quantity, author, publisher): ";
                getline(cin, data);
                istringstream iss(data);
                if (!(iss >> name >> price >> quantity >> author >> publisher)) {
                    cout << "Invalid input format. Please try again." << endl;
                    continue; // Skip to the next iteration
                }
                ShoppingItems.push_back(make_unique<Book>(name, price, quantity, author, publisher));
                break;
            }
            default:
                cout << "Invalid item type entered." << endl;
        }
    }

    cout << "Do you want to save the items to a file? (y/n): ";
    char save_choice;
    if (!(cin >> save_choice)) {
        cout << "Invalid input. Exiting without saving." << endl;
        return 1;
    }
    if (tolower(save_choice) == 'y') {
        ofstream ofs("shopping_items.txt");
        if (!ofs) {
            cout << "Error opening file for writing." << endl;
            return 1;
        }
        for (const auto& item : ShoppingItems) {
            item->persist(ofs);
        }
        ofs.close();
        cout << "Items saved to shopping_items.txt" << endl;
    }
    cout << "You have added the following items:" << endl;
    for (const auto& item : ShoppingItems) {
        cout << "- " << item->getName() << endl;
        item->TotalCost();
    }
    return 0;
}
