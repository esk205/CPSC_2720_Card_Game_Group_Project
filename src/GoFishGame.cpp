#include "GoFishGame.h"

GoFishGame::GoFishGame()
{
    gameMenu.clearScreen();
    gameMenu.decoratedSay(AppConstants::WELCOME_GO_FISH);
    state = State::START;
    gameType = AppConstants::GO_FISH_TYPE;
}

GoFishGame::~GoFishGame()
{
}

void GoFishGame::update()
{
    switch(state)
    {
    case State::START:
        handler = new GameStartHandler(this, AppConstants::GO_FISH_MAX_PLAYERS, "gofish.txt");
        handler->handle();
        state = State::DEAL;
        break;
    case State::DEAL:
        handler = new GoFishDealHandler(this);
        handler->handle();
        state = State::PLAY;
    case State::PLAY:
        handler = new GoFishPlayHandler(this);
        handler->handle();
        state = State::END;
    case State::END:
        handler = new EndGameHandler();
        handler->handle();
        break;
    default:
        gameMenu.say("WHAT DO I DO?");
    }
}
