#pragma once

class JournalRepository {
private:
    vector<Journal> journals;
public:
    JournalRepository() = default;
    ~JournalRepository() = default;

    void addJournal(const Journal& journal);
    Journal getJournalById(const string& id) const;
    vector<Journal> getAllJournals() const;

    void updateJournal(const Journal& journal);
    void deleteJournal(const string& id); 

    vector<Journal> findByName(const string& keyword) const;

    vector<Journal> findByISSN(const string& issn) const;

};