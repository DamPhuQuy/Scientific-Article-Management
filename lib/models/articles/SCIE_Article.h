#pragma once

#include "Article.h"
#include <string> 
#include <vector>

using namespace std; 

class SCIE_Article : public Article {
public:
	SCIE_Article(
	string abstract = "",
		int n_citation = 0,
		string title = "",
		string venue = "",
		int year = 0,
		string id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
		const vector<string>& r = {}
	);

	explicit SCIE_Article(const Article& other);

	~SCIE_Article(); 

	// utilities
	void showDescription() const override; 
	[[nodiscard]] Article *clone() const override;
};