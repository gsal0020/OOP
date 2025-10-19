#include <iostream>

struct Myclass{

    /*
    default Constructor
    */
    Myclass(): field1("default"), field2(0) {
        std::cout << "Default Constructor called" << std::endl;
    }

    /*
    Defualt Destructor
    */
    ~Myclass() {
        std::cout << "Destructor called" << std::endl;
    }

private: 
    std::string field1;
    int field2;

public: 
    std::string getField1() {
        return this->field1;
    }
    int getField2() {
        return this->field2;
    }

    std::string setField1(std::string field1) {
        this->field1 = field1;
    }


int main(int, char**){
    Myclass obj1; //stack
    Myclass* obj2;
    std::cout << "Hello, from cdemo!" << std::endl;
    std::cout << "Struct field values: field1: " << obj1.getField1() <<" field2" << obj1.getField2() << std::endl;
    obj2 = new Myclass(); //heap
    std::cout << "Struct field values: field1: " << obj2->getField1() <<" field2" << obj2->getField2() << std::endl;

    delete obj2; //free heap memory
    return 0;
}
