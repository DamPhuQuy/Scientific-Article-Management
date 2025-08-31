#include "utilities/IOHelper.h"

template<>
string IOHelper::chooseFromMap<Author>(const map<string, Author> &data, const string &label) {
    int choose = -1;
    vector<string> tokens;
    tokens.emplace_back("New");
    do {
        cout << "List of " + label << ": \n";
        int index = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            tokens.emplace_back(it->first);
            cout << index++ << ". "
                 << label + "ID: "
                 << it->first
                 << " - Author Name: "
                 << it->second.getAuthorName()
                 << "\n";
        }
        cout << "Choose or create new (0): ";
        cin >> choose; cin.ignore();
    } while (choose == -1);

    return tokens[choose];
}

template<>
string IOHelper::chooseFromMap<Journal>(const map<string, Journal> &data, const string &label) {
    int choose = -1;
    vector<string> tokens;
    tokens.emplace_back("New");
    do {
        cout << "List of " + label << ": \n";
        int index = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            tokens.emplace_back(it->first);
            cout << index++ << ". "
                 << label + "ID: "
                 << it->first
                 << " - Author Name: "
                 << it->second.getJournalName()
                 << "\n";
        }
        cout << "Choose of create new (0): ";
        cin >> choose; cin.ignore();

    } while (choose == -1);

    return tokens[choose];
}


