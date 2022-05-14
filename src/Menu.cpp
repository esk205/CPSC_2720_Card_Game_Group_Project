#include "Menu.h"
#include <iostream>
#include <limits>
#include "AppConstants.h"
#include "Game.h"
#include "GameFactory.h"
#include "RunTests.h"

void Menu::displayMainMenu()
{
    clearScreen();

    Game* game = nullptr;

    say(AppConstants::WELCOME_MESSAGE);
    say(AppConstants::TEAM_NAME);
    say(AppConstants::VERSION);

    string opts[] =
    {
        AppConstants::BLACK_JACK,
        AppConstants::CRAZY_EIGHTS,
        AppConstants::GO_FISH,
        AppConstants::ROCK_PAPER_SCISSORS,
        AppConstants::WAR,
        AppConstants::RUN_TESTS,
        AppConstants::HELP,
        AppConstants::QUIT
    };

    Choices c = Choices(opts, 8);
    int choice = prompt(AppConstants::MESSAGE_SELECT_GAME, c);

    game = GameFactory::makeGame(choice);

    if (game != nullptr)
    {
        game->startGame();
    }
    else if (choice == 6)
    {
        say("Running Unit Tests...");
        RunTests::tests();
        say(AppConstants::PRESS_ENTER);
        cin.get(); cin.get();
        displayMainMenu();
    }
    else if (choice == 7)
    {
        say("");
        say(AppConstants::BASIC_HELP);
        say("");

        say(AppConstants::PRESS_ENTER);
        cin.get(); cin.get();

        displayMainMenu();
    }
    else if (choice == 8)
    {
        exit(0);
    }
}

int Menu::prompt(string message, Choices choices)
{
    say(message);
    choices.display();

    int opt;
    cout << AppConstants::PROMPT;
    cin >> opt;

    if (!choices.check(opt))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clearScreen();
        say(AppConstants::MESSAGE_INVALID_SELECTION);
        return prompt(message, choices);
    }

    return opt;
}

void Menu::say(string message)
{
    std::cout << message << std::endl;
}

void Menu::decoratedSay(string message)
{
    int defaultPadding = 33;
    if (message.size() > 33)
        defaultPadding = message.size();

    string borderPadding = "";
    for (int i = 0; i < defaultPadding; i++)
        borderPadding += "*";

    // Remove two because they are spaces.
    int padding = (defaultPadding - 2) - message.size();
    if (message.size() % 2 == 0)
        padding -= 1;

    string messagePadding = "";
    for (int i = 0; i < padding / 2; i++)
        messagePadding += "*";

    say("");
    say(borderPadding);
    say(messagePadding + " " + message + " " + messagePadding);
    say(borderPadding);
    say("");
}

void Menu::decoratedSay(vector<string> message)
{
    int messageSize = message.size();
    vector<string> messagePaddings;

    int defaultPadding = 33;
    for (int i = 0; i < messageSize; i++)
        if (message[i].size() > 33)
            defaultPadding = message[i].size();

    string borderPadding = "";
    for (int i = 0; i < defaultPadding; i++)
        borderPadding += "*";


    for (int i = 0; i < messageSize; i++)
    {
        // Remove two because they are spaces.
        int padding = (defaultPadding - 2) - message[i].size();
        if (message[i].size() % 2 == 0)
            padding -= 1;

        string messagePadding = "";
        for (int i = 0; i < padding / 2; i++)
            messagePadding += "*";

        messagePaddings.push_back(messagePadding);
    }

    say("");
    say(borderPadding);

    for (int i = 0; i < messageSize; i++)
        say(messagePaddings[i] + " " + message[i] + " " + messagePaddings[i]);

    say(borderPadding);
    say("");
}

void Menu::clearScreen()
{
    system("clear");
}

void Menu::gameHelp(int gameType)
{
    say("");

    // If is the main menu
    say(AppConstants::HELP_OBJECTIVE);

    if (gameType == AppConstants::GO_FISH_TYPE)
        say(AppConstants::GO_FISH_OBJECTIVE);
    else if (gameType == AppConstants::BLACKJACK_TYPE)
        say(AppConstants::BLACKJACK_OBJECTIVE);
    else if (gameType == AppConstants::CRAZY_EIGHTS_TYPE)
        say(AppConstants::CRAZY_EIGHTS_OBJECTIVE);
    else if (gameType == AppConstants::RPS_TYPE)
        say(AppConstants::RPS_OBJECTIVE);
    else if (gameType == AppConstants::WAR_TYPE)
        say(AppConstants::WAR_OBJECTIVE);

    // If is the main menu
    say("");
    say(AppConstants::HELP_CARDS_DEALT);

    if (gameType == AppConstants::GO_FISH_TYPE)
        say(AppConstants::GO_FISH_CARDS_DEALT);
    else if (gameType == AppConstants::BLACKJACK_TYPE)
        say(AppConstants::BLACKJACK_CARDS_DEALT);
    else if (gameType == AppConstants::CRAZY_EIGHTS_TYPE)
        say(AppConstants::CRAZY_EIGHTS_CARDS_DEALT);
    else if (gameType == AppConstants::RPS_TYPE)
        say(AppConstants::RPS_CARDS_DEALT);
    else if (gameType == AppConstants::WAR_TYPE)
        say(AppConstants::WAR_CARDS_DEALT);

    // If is the main menu
    say("");
    say(AppConstants::HELP_HOW_TO);

    if (gameType == AppConstants::GO_FISH_TYPE)
        say(AppConstants::GO_FISH_HELP);
    else if (gameType == AppConstants::BLACKJACK_TYPE)
        say(AppConstants::BLACKJACK_HELP);
    else if (gameType == AppConstants::CRAZY_EIGHTS_TYPE)
        say(AppConstants::CRAZY_EIGHTS_HELP);
    else if (gameType == AppConstants::RPS_TYPE)
        say(AppConstants::RPS_HELP);
    else if (gameType == AppConstants::WAR_TYPE)
        say(AppConstants::WAR_HELP);
    else
        say(AppConstants::BASIC_HELP);

    say("");
}
