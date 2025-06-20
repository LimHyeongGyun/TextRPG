#pragma once
#include <string>
#pragma once

class Item
{
private:
    static int nextItemNum;
public:
    int itemnum;
    int value;
    virtual std::string getName() const = 0;
    virtual void Use(class Character* character) = 0;
    virtual ~Item() {}
    Item() {
        itemnum = nextItemNum++;
    }
};

