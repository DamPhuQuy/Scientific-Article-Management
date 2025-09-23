#pragma once

#include <functional>
#include <string>

using namespace std;

class EventListener {
private:
    unordered_map<string, function<void(const string&)>> listeners;
public:
    void addEventListener(const string&, const function<void(const string&)> &);
    void triggerEvent(const string& event);
};