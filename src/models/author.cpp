#include "author.h"

Author::Author(string id, string fullName, string country, string fieldOfStudy, int totalPublications)
    : id(id),
    fullName(fullName),
    country(country),
    fieldOfStudy(fieldOfStudy),
    totalPublications(totalPublications)
{
}

Author::Author(const Author& other)
    : id(other.id),
    fullName(other.fullName),
    country(other.country),
    fieldOfStudy(other.fieldOfStudy),
    totalPublications(other.totalPublications)
{
}

json Author::to_json() const {
    return json{
        {"id", id},
        {"fullName", fullName},
        {"country", country},
        {"fieldOfStudy", fieldOfStudy},
        {"totalPublications", totalPublications}
    };
}

// void Author::inputFromUser()
// {
//     cout << "=== Enter Author Details ===\n";

//     auto readLine = [](const string& prompt) -> string {
//         string line;
//         cout << prompt;
//         getline(cin >> ws, line);   // skip leading whitespace
//         return line;
//     };
//     // Helper lambda for integer input with validation
//     auto readInt = [](const string& prompt) -> int {
//         int value;
//         while (true) {
//             cout << prompt;
//             if (cin >> value) {
//                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                 return value;
//             }
//             cout << "  ** Invalid number, try again.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         }
//     };

//     this->fullName         = readLine("Full name        : ");
//     this->country          = readLine("Country          : ");
//     this->fieldOfStudy     = readLine("Field of study   : ");
//     this->totalPublications = readInt("Total publications: ");
//     cout << "-----------------------------\n";
// }
