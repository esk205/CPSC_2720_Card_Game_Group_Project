#include "GameStartHandler.h"
#include "LoadHandler.h"

GameStartHandler::GameStartHandler(Game* game, int maxPlayers, string file)
{
    this->game = game;
    this->maxPlayers = maxPlayers;
    this->file = file;
}

GameStartHandler::~GameStartHandler()
{
    this->game = nullptr;
    this->maxPlayers = 0;
    file.clear();
}

void GameStartHandler::handle()
{
    string opts[] =
    {
        "New Game",
        "Load Game"
    };

    Choices c = Choices(opts, 2);
    int selection = this->game->gameMenu.prompt(AppConstants::MESSAGE_SELECT_OPTION, c);
    if (selection == 1)
    {
        this->game->gameMenu.clearScreen();
        this->game->createPlayer();
        this->game->gameMenu.clearScreen();
        this->game->getOpponents(maxPlayers);
        this->game->gameMenu.clearScreen();
    }
    else
    {
        // Does not function correctly.
        //LoadHandler lh = LoadHandler(game, file);
        //lh.handle();
        game->gameMenu.say("Unable to load");
        handle();
    }
}
