#pragma once

#include "Article.h"
#include <string>
#include <vector>

using namespace std;

class OTHER_Article : public Article
{
public:
	OTHER_Article(
		string abstract = "",
		int n_citation = 0,
		string title = "",
		string venue = "",
		int year = 0,
		string id = "",
		Type t = Type::OTHER,
		ArticleStatus st = ArticleStatus::DRAFT,
		const vector<string> &r = {});

	explicit OTHER_Article(const Article &other);

	~OTHER_Article();

	// utilities
	void showDescription() override;
	[[nodiscard]] Article *clone() const override;
};
