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
		string id = "", 
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
		const vector<string>& r = {}
	);
	SCOPUS_Article(
		string abstract = "",
		int n_citation = 0,
		string title = "",
		string venue = "",
		int year = 0,
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
		const vector<string>& r = {}
	);
	explicit SCOPUS_Article(const Article& other);

	~SCOPUS_Article(); 

	// utilities
	void showDescription() const override; 
	[[nodiscard]] Article* clone() const override;

	// input
	[[nodiscard]] Article* input() const override;
};