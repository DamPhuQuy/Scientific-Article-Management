#pragma once

#include <unordered_map>
#include "models/Journal.h"

class JournalRepository {
private:
    unordered_map<string, Journal> journals;
public:
    JournalRepository() = default;
    explicit JournalRepository(const unordered_map<string, Journal>&);
    ~JournalRepository() = default;

    void addJournal(const Journal& journal);
    Journal getJournalById(const string& id) const;
    vector<Journal> getAllJournals() const;

    void updateJournal(const Journal& journal);
    void deleteJournal(const string& id); 

    vector<Journal> findByName(const string& keyword) const;

    vector<Journal> findByType(const string& type) const;
    vector<Journal> findByYear(const int& year) const;
};