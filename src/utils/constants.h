#pragma once

#include <QString>
#include <QCoreApplication>
#include <QDir>

class Constants {
public:
    static QString dataFolder() {
        return QCoreApplication::applicationDirPath() + QDir::separator() + "data";
    }

    static QString accountsData() {
        return dataFolder() + QDir::separator() + "accounts.json";
    }

    static QString dataSetJson() {
        return dataFolder() + QDir::separator() + "dataset.json";
    }

    static QString auInfoJson() {
        return dataFolder() + QDir::separator() + "authors_dataset.json";
    }
};
