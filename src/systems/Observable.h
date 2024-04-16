#pragma once

#include <vector>
#include <string>

#include "Observer.h"

class Observable 
{
public:
    void addObserver(Observer* observer) 
    {
        p_observers.push_back(observer);
    }

    void notifyObservers(const std::string& event, const std::string& data) 
    {
        for (auto observer : p_observers) 
        {
            observer->onNotify(event, data);
        }
    }
private:
    std::vector<Observer*> p_observers;
};
