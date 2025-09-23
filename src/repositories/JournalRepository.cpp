#include "repositories/JournalRepository.h"

#include <algorithm>
#include <iostream>
#include <regex>

JournalRepository::JournalRepository(const unordered_map<string, Journal>&j) : journals(j){

}

void JournalRepository::addJournal(const Journal &journal) {
    const string journalID = journal.getJournalID();

    if (const auto it = journals.find(journalID); it == journals.end()) {
        journals[journalID] = journal;
    } else {
        cout << "This journalID existed" << endl;
    }
}

Journal JournalRepository::getJournalById(const string& id) const {
    if (const auto it = journals.find(id); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return {};
    } else {
        return it->second;
    }
}

vector<Journal> JournalRepository::getAllJournals() const {
    vector<Journal> res;
    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        res.push_back(element.second);
    });
    return res;
}

void JournalRepository::updateJournal(const Journal &journal) {
    const string journalID = journal.getJournalID();
    if (const auto it = journals.find(journalID); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return;
    }
    else {
        it->second = journal;
    }
}

void JournalRepository::deleteJournal(const string& id) {
    if (const auto it = journals.find(id); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return;
    } else {
        journals.erase(it);
    }
}

vector<Journal> JournalRepository::findByName(const string &keyword) const {
    vector<Journal> res;

    const regex pattern(keyword, regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_search(element.second.getJournalName(), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

vector<Journal> JournalRepository::findByType(const string &type) const {
    vector<Journal> res;

    const regex pattern(type, regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_match(element.second.getJournalName(), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

vector<Journal> JournalRepository::findByYear(const int& year) const {
    vector<Journal> res;

    const regex pattern(to_string(year), regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_match(to_string(element.second.getPublishYear()), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

