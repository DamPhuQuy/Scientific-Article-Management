#pragma once

#include "models/Article.h"
#include <string> 
#include <vector>

using namespace std; 

class SCIE_Article : public Article {
public:
	SCIE_Article(
		string abstract = "",
		vector<string> authors = {},
		int n_citation = 0,
		vector<string> references = {},
		string title = "",
		string venue = "",
		int year = 0,
    	string a_id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT
	);
	explicit SCIE_Article(const Article& other);

	[[nodiscard]] Article *clone() const override;
	[[nodiscard]] Article* input() const override;
};