#pragma once
#include <iostream>
#include <regex>
#include <functional>
#include <unordered_map>
#include <vector>
#include <conio.h>     // for getch()
#include <string>

using namespace std;

class SearchByRegex {
public: 
    template<typename T, typename Getter>
    static vector<T> searchByRegex(
        const unordered_map<string, T>& container,
        Getter fieldGetter,
        const string& pattern
    ) {
        vector<T> results;
        try {
            regex reg(pattern, regex_constants::icase);
            for (const auto& [id, item] : container) {
                string value = fieldGetter(item);
                if (regex_search(value, reg)) {
                    results.push_back(item);
                }
            }
        } catch (const regex_error& e) {
            cerr << "Invalid regex: " << e.what() << endl;
        }
        return results;
    }

    template <typename T, typename Getter, typename Printer>
    static int liveSearch(
        const unordered_map<string, T>& container,
        Getter fieldGetter,
        Printer printer
    )
    {
        string input;
        char c;
        int selectedIndex = 0;

        cout << "\n Start typing to search (ENTER = select, ESC = exit):\n";

        while (true) {
            if (_kbhit()) { // check keyboard press
                c = _getch();

                // esc
                if (c == 27) {
                    system("cls");
                    cout << "\nSearch cancelled.\n";
                    return -1;
                }

                // enter
                else if (c == 13) {
                    system("cls");
                    vector<T> results = searchByRegex(container, fieldGetter, input);
                    if (results.empty()) {
                        cout << "No results found.\n";
                        return -1;
                    }
                    cout << "You selected:\n";
                    printer(results[selectedIndex], true);
                    cout << "\n(Press any key to return...)\n";
                    _getch();
                    return selectedIndex;
                }

                // backspace
                else if (c == '\b') {
                    if (!input.empty()) input.pop_back();
                }

                // arrow
                else if (c == 0 || c == -32) { // special key (arrows)
                    c = _getch();
                    if (c == 72) { // UP
                        if (selectedIndex > 0) selectedIndex--;
                    } else if (c == 80) { // DOWN
                        selectedIndex++;
                    }
                }

                // printable character
                else if (isprint(c)) {
                    input.push_back(c);
                }

                // display
                system("cls");
                cout << "Search: " << input << "\n\n";

                vector<T> results = searchByRegex(container, fieldGetter, input);

                if (results.empty()) {
                    cout << "No results.\n";
                    selectedIndex = 0;
                } else {
                    if (selectedIndex >= (int)results.size()) 
                        selectedIndex = results.size() - 1;
                    for (int i = 0; i < (int)results.size(); ++i) {
                        printer(results[i], i == selectedIndex);
                    }
                }
            }
        }
    }
};