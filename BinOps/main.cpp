#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Binops{
    double opnd1;
    char op;
    double opnd2;
};
bool parse_expression(const string& exp, Binops* binops);
double perform_operation(const Binops* binops);

int main(int, char**){
    string operation;
    double result;
    cout << "Please insert your operation: " ; getline(cin, operation); // storing whole line
    cout << "before: " + operation + "\n";
    operation.erase(remove(operation.begin(), operation.end(), ' '), operation.end()); //removing spaces in case user adds some
    cout << operation; // debug statement
    Binops* binops = new Binops[operation.length()]; // this will make an obj on the heap
    parse_expression(operation, binops);
    result = perform_operation(binops);
    cout<< result << '\n';


}

bool parse_expression(const string& exp, Binops* binops){
    istringstream iss(exp);
    char open_par, close_par;
    if (iss >> open_par >> binops->opnd1 >> binops->op >> binops->opnd2 >> close_par){ // still has problems (does not parse the decimal entirely)
        return (open_par == '(' && close_par == ')');
    }
    return false;
}

// bool isOperator(char c){
//     switch (c){
//         case '+':
//         case '-': 
//         case '*':
//         case '/': 
//             return true;
//         default:
//             cout << "Not an operator" << endl;
//             return false;
//     }
// }

double perform_operation(const Binops* binops){
    if(!binops) return 0.0;
    switch(binops->op){
        case '+':
            return binops->opnd1 + binops->opnd2;
            break;
        case '-':
            return binops->opnd1 - binops->opnd2;
            break;
        case '*':
            return binops->opnd1 * binops->opnd2;
            break;
        case '/':
            if (binops->opnd2 == 0.0f){
                cout<< "Logic error: division by 0\n";
            } else 
                {return binops->opnd1 / binops->opnd2; }
                break;
        default:
            cout << "Not a valid operator\n";
            return 0;
    }
}