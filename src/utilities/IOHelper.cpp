#include "utilities/IOHelper.h"

template<typename T> 
int IOHelper::chooseFromMap(const unordered_map<int, T> &data, const string &label) {
    int choose; 

    cout << "List of " + label << ": \n";
    for (auto it = data.begin(); it != data.end(); it++) {
        if (label == "Author")
            cout << label + "ID: " 
                << it->first
                << " - Author Name: "
                << it->second.getAuthorName()
                << "\n"; 
        else if (label == "Journal") 
            cout << label + "ID: " 
                 << it->first
                 << " - Journal Name: "
                 << it->second.getJournalName()
                 << "\n";
    }
    cout << "Choose or create new (0)"; 
    cin >> choose; cin.ignore(); 

    return choose; 
}