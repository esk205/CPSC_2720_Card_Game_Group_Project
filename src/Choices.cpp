#include <iostream>
#include <map>
#include "Choices.h"

Choices::Choices()
{
    //ctor
}

Choices::Choices(string choices[], int length)
{
    for (int i = 0; i < length; i++)
    {
        add(i + 1, choices[i]);
    }
}

Choices::~Choices()
{
    _choices.clear();
}

void Choices::add(int key, string value)
{
    _choices.insert(std::make_pair(key,value));
}

void Choices::removeChoice(int key)
{
    _choices.erase(key);
}

void Choices::clearChoices()
{
    _choices.clear();
}

int Choices::_size()
{
    return _choices.size();
}

void Choices::display()
{
    for (const auto& kv : _choices)
    {
        std::cout << kv.first << " => " << kv.second << std::endl;
    }
}

bool Choices::check(int option)
{
    map<int, string>::iterator it = _choices.find(option);
    if (it != _choices.end())
    {
        return true;
    }
    return false;
}


