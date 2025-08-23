#pragma once

#include <filesystem>  
#include <string> 

namespace fs = std::filesystem;

class Constants {
private: 
    inline static const fs::path MODELS_PATH = "data/models"; 

public: 
    static fs::path getModelsPath(const std::string &file) {
        return MODELS_PATH / file; 
    }

    inline static const fs::path ARTICLE = getModelsPath("articles.csv"); 
    inline static const fs::path AUTHOR  = getModelsPath("authors.csv"); 
    inline static const fs::path JOURNAL = getModelsPath("journals.csv"); 

	inline string toString(ArticleStatus status) {
	    switch (status) {
	        case ArticleStatus::DRAFT: return "DRAFT";
	        case ArticleStatus::SUBMITTED: return "SUBMITTED";
	        case ArticleStatus::UNDER_REVIEW: return "UNDER_REVIEW";
	        case ArticleStatus::REVISIONS: return "REVISIONS";
	        case ArticleStatus::ACCEPTED: return "ACCEPTED";
	        case ArticleStatus::REJECTED: return "REJECTED";
	        case ArticleStatus::PUBLISHED: return "PUBLISHED";
	        default: return "UNKNOWN";
	    }
	}
};
