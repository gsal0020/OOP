#include <iostream>
#include "Binops_ClassV/Binops.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdexcept> // add if not already present

using namespace std;

// struct Binops {
//     double opnd1;
//     char op;
//     double opnd2;
// };
bool validate_operator(char oop);
bool parse_expression(const string& exp, Binops* binops);
double perform_operation(const Binops* binops);
void print_to_txt(const Binops* expressions, int count);
int main() {
    const int MAX_EXPRESSIONS = 100; // Fixed size
    Binops* expressions = new Binops[MAX_EXPRESSIONS]; // Fixed-sized array on heap
    int expressionCount = 0;
    
    cout << "Enter expressions following the format (number operator number), one per line.\n";
    cout << "Enter 'done' to finish.\n";
    
    string line;
    while (expressionCount < MAX_EXPRESSIONS) {
        cout << "Expression " << (expressionCount + 1) << ": ";
        getline(cin, line);
        
        if (line == "done") {
            break;
        }
        
        // Remove spaces
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        
        if (parse_expression(line, &expressions[expressionCount])) {
            expressionCount++;
        } else {
            cout << "Invalid expression format.\n";
        }
    }
    
    // Perform and display all operations
    cout << "\nResults:\n";
    for (int i = 0; i < expressionCount; i++) {
        double result = perform_operation(&expressions[i]);
        // cout << "(" << expressions[i].opnd1 << " " << expressions[i].op 
        //      << " " << expressions[i].opnd2 << ") = " << result << "\n";
        cout << "(" << expressions[i].get_opnd1() << " " << expressions[i].get_op() 
             << " " << expressions[i].get_opnd2() << ") = " << result << "\n";
    }
    
    // Clean up heap memory
    delete[] expressions;
    // Print results to text file
    print_to_txt(expressions, expressionCount);
    return 0;
}

// bool parse_expression(const string& exp, Binops* binops) {
//     if (!binops) return false;
    
//     istringstream iss(exp);
//     char open_par, close_par, op;
//     double opnd1, opnd2;
    
//     if (iss >> open_par >> binops->opnd1 >> binops->op >> binops->opnd2 >> close_par) {
//         return (open_par == '(' && close_par == ')');
//     }
//     return false;
// } 
// }
bool parse_expression(const string& exp, Binops* binops) {
    if (!binops) return false;
    istringstream iss(exp);
    char open_par = '\0', close_par = '\0';
    double opnd1 = 0.0, opnd2 = 0.0;
    char op = '\0';

    if (!(iss >> open_par >> opnd1 >> op >> opnd2 >> close_par)) return false;
    if (validate_operator(op) == false){
        cerr << "Invalid operator: " << op << '\n';
    }
    
    if (open_par != '(' || close_par != ')') return false;

    binops->set_opnd1(opnd1);
    binops->set_op(op);
    binops->set_opnd2(opnd2);
    return true;
}

double perform_operation(const Binops* binops) {
    if (!binops) return 0.0;
    
//     switch(binops->op) {
//         case '+': return binops->opnd1 + binops->opnd2;
//         case '-': return binops->opnd1 - binops->opnd2;
//         case '*': return binops->opnd1 * binops->opnd2;
//         case '/': 
//             if (binops->opnd2 == 0.0) {
//                 cout << "Error: division by zero\n";
//                 return 0.0;
//             }
//             return binops->opnd1 / binops->opnd2;
//         default:
//             cout << "Invalid operator: " << binops->op << '\n';
//             return 0.0;
//     }
// }
    switch(binops->get_op()) {
        case '+': return binops->get_opnd1() + binops->get_opnd2();
        case '-': return binops->get_opnd1() - binops->get_opnd2();
        case '*': return binops->get_opnd1() * binops->get_opnd2();
        case '/': 
            if (binops->get_opnd2() == 0.0) {
                cout << "Error: division by zero\n";
                return 0.0;
            }
            return binops->get_opnd1() / binops->get_opnd2();
        default:
            cout << "Invalid operator: " << binops->get_op() << '\n';
            return 0.0;
    }
}
void print_to_txt(const Binops* expressions, int count) {
    if (!expressions || count <= 0) return;
    try {
        ofstream outputFile("operations.txt");
        if (!outputFile.is_open()) {
            throw runtime_error("Could not open file for writing.");
        }

        // for (int j = 0; j < count; ++j) {
        //     outputFile << "(" << expressions[j].opnd1 << " " << expressions[j].op
        //                << " " << expressions[j].opnd2 << ") = "
        //                << perform_operation(&expressions[j]) << "\n";
        // }

        for (int j = 0; j < count; ++j) {
            outputFile << "(" << expressions[j].get_opnd1() << " " << expressions[j].get_op()
                       << " " << expressions[j].get_opnd2() << ") = "
                       << perform_operation(&expressions[j]) << "\n";
        }
        
        outputFile.close();
        cout << "Results written to operations.txt\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

bool validate_operator(char op){
    if (!(op == '+' || op == '-' || op == '*' || op == '/')){
        return false;
    }
}