#pragma once

#include "Article.h"
#include <string> 
#include <vector>

using namespace std; 

class SCOPUS_Article : public Article {
public:
	// Constructor 
	SCOPUS_Article(
		string abstract = "",
		int n_citation = 0,
		string title = "",
		string venue = "",
		int year = 0,
    	string a_id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT
	);
	explicit SCOPUS_Article(const Article& other);

	// Destructor
	~SCOPUS_Article(); 

	// Methods
	void showDescription() const override; 
	[[nodiscard]] Article* clone() const override;
	[[nodiscard]] Article* input() const override;
};