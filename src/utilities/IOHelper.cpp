#include "utilities/IOHelper.h"

template<>
int IOHelper::chooseFromMap<Author>(const unordered_map<int, Author> &data, const string &label) {
    int choose; 

    cout << "List of " + label << ": \n";
    for (auto it = data.begin(); it != data.end(); it++) {
            cout << label + "ID: " 
                << it->first
                << " - Author Name: "
                << it->second.getAuthorName()
                << "\n"; 
    }
    cout << "Choose or create new (0): "; 
    cin >> choose; cin.ignore(); 

    return choose; 
}

template<>
int IOHelper::chooseFromMap<Journal>(const unordered_map<int, Journal> &data, const string &label) {
    int choose; 
    cout << "List of " + label << ": \n"; 
    for (auto it = data.begin(); it != data.end(); it++) {
        cout << label + "ID: "
             << it->first
             << " - Author Name: "
             << it->second.getJournalName()
             << "\n"; 
    }
    cout << "Choose of create new (0): ";
    cin >> choose; cin.ignore();

    return choose; 
}


