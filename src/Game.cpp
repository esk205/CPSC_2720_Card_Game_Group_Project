#include "Game.h"
#include "Menu.h"
#include "Tools.h"
#include "AppConstants.h"
#include "PlayerFactory.h"
#include "PlayerHandler.h"
#include "SaveHandler.h"
#include "LoadHandler.h"
#include <string>

Game::Game()
{
    // create a menu to be used by the game.
    gameMenu = Menu();
    gameType = 0;
}

void Game::startGame()
{
    paused = false;
    while (state != State::EXIT)
    {
        if (!paused)
            update();
    }
}

void Game::addPlayer(Player* player)
{
    players.push_back(player);
}

void Game::removePlayer(string name)
{
}

Game::~Game()
{
    players.clear();
}

Player* Game::getCurrentPlayer()
{
    return currentPlayer;
}

void Game::setCurrentPlayer(Player* player)
{
    currentPlayer = player;
}

void Game::save(string file)
{
    handler = new SaveHandler(this, file);
    handler->handle();
    handler = nullptr;
}

void Game::load(string file)
{
    handler = new LoadHandler(this, file);
    handler->handle();
    handler = nullptr;
}

void Game::createPlayer()
{
    handler = new PlayerHandler(this);
    handler->handle();
    handler = nullptr;
}

void Game::chooseOpponent()
{
    string opts[] =
    {
        AppConstants::DUMB_BOT_PLAYER,
        AppConstants::RANDOM_BOT_PLAYER,
        AppConstants::SMART_BOT_PLAYER,
        AppConstants::HUMAN
    };

    Choices c = Choices(opts, 4);
    int choice = gameMenu.prompt(AppConstants::CHOOSE_BOT_PLAYER + ", " + currentPlayer->getName() + ".", c);

    // Need to pass in the game here so the bots can be chosen correctly.
    Player* p = PlayerFactory::makePlayer(choice, this);

    if (choice == 4)
    {
        gameMenu.clearScreen();
        gameMenu.say("Please enter opponent name.");
        string playerName;
        cin >> playerName;
        p->setName(playerName);
    }

    players.push_back(p);
}

void Game::getOpponents(int maxPlayers)
{
    int currentPlayers = players.size();
    int selection = 0;
    while (currentPlayers < maxPlayers && selection != 2)
    {
        gameMenu.clearScreen();
        chooseOpponent();
        currentPlayers = players.size();
        if (currentPlayers != maxPlayers)
        {
            string opts[] = { "Yes", "No" };
            Choices c = Choices(opts, 2);
            gameMenu.clearScreen();
            selection = gameMenu.prompt("Add Another Opponent?", c);
            if (selection == 2 && players.size() < 2)
            {
                gameMenu.say("You are a sad, lonely individual.");
                selection = 1;
            }
        }
    }
}

int Game::getGameType()
{
    return gameType;
}

StateHandler* Game::getStateHandler()
{
    return handler;
}

void Game::setStateHandler(StateHandler* stateHandler)
{
    handler = stateHandler;
}

void Game::update()
{
    gameMenu.say("Updating");
}

void Game::dealCards()
{
    gameMenu.say("Dealing cards.");
}

void Game::makeChoices()
{
    gameMenu.say("Making Choices");
}
