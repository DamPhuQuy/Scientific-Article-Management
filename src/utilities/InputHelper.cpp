#include "utilities/InputHelper.h"

template<> 
int InputHelper::chooseFromMap<Author>(const unordered_map<int, Author> &data, const string &label) {
    int choose; 

    cout << "List of " + label << ": \n";
    for (auto it = data.begin(); it != data.end(); it++) {
        cout << label + "ID: " 
             << it->first
             << " - Name: "
             << it->second.getAuthorName(); 
    }
    cout << "Choose or create new (0)"; 
    cin >> choose; cin.ignore(); 

    return choose; 
}