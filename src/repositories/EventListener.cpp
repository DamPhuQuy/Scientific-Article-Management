#include "repositories/EventListener.h"

#include <algorithm>

void EventListener::addEventListener(const string& s, const function<void(const string&)> &func) {
    if (const auto it = listeners.find(s); it == listeners.end()) {
        listeners[s] = func;
    }
}

void EventListener::triggerEvent(const string& event) {
    listeners[event](event);
}
