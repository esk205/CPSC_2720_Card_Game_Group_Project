#ifndef MENU_H
#define MENU_H

#include <string>

#include "Choices.h"
#include <vector>

class Menu
{
public:
    Menu() {};
    virtual ~Menu() {};

    /**
    * @brief prompts user with a message and choices
    */
    virtual int prompt(string message, Choices choices);

    /**
    * @brief displays the main menu.
    */
    virtual void displayMainMenu();

    /**
    * @brief outputs a message.
    */
    virtual void say(string message);

    /**
    * @brief outputs a fancy message.
    */
    virtual void decoratedSay(string message);

    /**
    * @brief outputs a fancy multiline message.
    */
    virtual void decoratedSay(vector<string> message);

    /**
    * @brief clears the screen.
    */
    virtual void clearScreen();

    /**
    * @brief displays the help.
    */
    virtual void gameHelp(int gameType);

protected:

private:
};

#endif // MENU_H
