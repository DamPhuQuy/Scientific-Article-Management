#pragma once

#include "Article.h"
#include <string> 
#include <vector> 

using namespace std; 

class OTHER_Article : public Article {
public:
	OTHER_Article(
		string abstract = "",
		int n_citation = 0,
		string title = "",
		string venue = "",
		int year = 0,
    	string a_id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT
	);
	explicit OTHER_Article(const Article& other);

	~OTHER_Article(); 

	// utilities
	void showDescription() const override; 
	[[nodiscard]] Article* clone() const override;

	// input
	[[nodiscard]] Article* input() const override;
};
