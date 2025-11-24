#pragma once

#include <string>

const std::string DATA_FOLDER = "../../../data";

class Constants {
public:
    static std::string accountsData() {
        // 3. Now valid because we are adding std::string + char*
        return DATA_FOLDER + "/accounts.json";
    }

    static std::string dataSetJson() {
        return DATA_FOLDER + "/dataset.json";
    }

    static std::string auInfoJson() {
        return DATA_FOLDER + "/authors_dataset.json";
    }
};
