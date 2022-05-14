#ifndef CHOICES_H
#define CHOICES_H

#include <string>
#include <map>

using namespace std;

class Choices
{
    /**
    * A choices object to pass to the menu.
    */
public:

    /**
    * @brief Default constructor.
    */
    Choices();

    /**
    * @brief Constructor for the Choices object
    * @param Choices, array of string.
    * @param length, integer length of the array.
    */
    Choices(string choices[], int length);

    /**
    * @brief Deconstructor
    */
    virtual ~Choices();

    /**
    * @brief adds a choice
    */
    void add(int key, string value);

    /**
    * @brief removes one choice
    */
    void removeChoice(int key);

    /**
    * @brief clears the choices made
    */
    void clearChoices();

    /**
    * @brief displays all the available choices
    */
    void display();

    /**
    * @brief checks if choice is valid???
    */
    bool check(int option);

    /**
    * @brief returns the size of the _choices property.
    */
    int _size();
protected:
private:

    /**
    * @brief Private store for the choices map.
    */
    map<int, string> _choices;
};

#endif // CHOICES_H
