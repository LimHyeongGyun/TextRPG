#pragma once
#include <string>
#pragma once

class Item
{
protected:
    virtual std::string getName() const = 0;
    virtual void Use(class Character* character) = 0;
    virtual ~Item() {}
};


