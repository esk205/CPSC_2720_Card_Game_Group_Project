#include "BlackjackGame.h"

BlackjackGame::BlackjackGame()
{
    gameMenu.clearScreen();
    gameMenu.decoratedSay(AppConstants::WELCOME_BJ);
    state = State::START;
    gameType = AppConstants::BLACKJACK_TYPE;
}

BlackjackGame::~BlackjackGame()
{
    //dtor
}

void BlackjackGame::update()
{
    switch(state)
    {
        case State::START:
            handler = new GameStartHandler(this, 10, "blackjack.txt");
            handler->handle();
            state = State::DEAL;
            break;
        case State::DEAL:
            handler = new BlackjackDealHandler(this);
            handler->handle();
            state = State::PLAY;
            break;
        case State::PLAY:
            handler = new BlackjackPlayHandler(this);
            handler->handle();
            state = State::END;
            break;
        case State::END:
            handler = new EndGameHandler();
            handler->handle();
            handler = nullptr;
        default:
            gameMenu.say("Invalid state reached");
            handler = nullptr;
            break;
    }
}
