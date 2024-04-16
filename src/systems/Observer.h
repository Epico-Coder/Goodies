#pragma once

class Observer 
{
public:
    virtual ~Observer() {}
    virtual void onNotify(const std::string& event, const std::string& data) = 0;
};
