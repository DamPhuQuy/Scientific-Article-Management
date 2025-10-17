#pragma once

#include "Article.h"
#include <string> 
#include <vector>

using namespace std; 

class SCOPUS_Article : public Article {
public:
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
	~SCOPUS_Article(); 
	explicit SCOPUS_Article(const Article& other);

	void showDescription() const override; 
	[[nodiscard]] Article* clone() const override;
	[[nodiscard]] Article* input() const override;
};