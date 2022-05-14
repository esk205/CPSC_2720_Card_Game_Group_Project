#include "CrazyEightsGame.h"
#include "EndGameHandler.h"
#include <vector>
#include <iostream>
using namespace std;

CrazyEightsGame::CrazyEightsGame()
{
    gameMenu.clearScreen();
    gameMenu.say("Welcome to Crazy8s");
    state = State::START;
    gameType = AppConstants::CRAZY_EIGHTS_TYPE;
}
CrazyEightsGame::~CrazyEightsGame()
{
    //dtor
}

void CrazyEightsGame::update()
{
    //cout << "Updating" << endl;
    switch(state)
    {
        case State::START:
            cout << "In start" << endl;
            handler = new GameStartHandler(this, AppConstants::CRAZY_EIGHTS_MAX_PLAYERS, "crazyeights.txt");
            handler->handle();
            state = State::DEAL;
            break;
        case State::DEAL:
            cout << "In deal" << endl;
            handler = new CrazyEightsDealCardsHandler(this);
            handler->handle();
            state = State::PLAY;
            break;
        case State::PLAY:
            cout << "In Play" << endl;
            handler = new CrazyEightsPlayHandler(this);
            handler->handle();
            state = State::END;
            break;
        case State::END:
            cout << "Ending game" << endl;
            handler = new EndGameHandler();
            handler->handle();
            handler = nullptr;
        break;
        default:
            gameMenu.say("WHAT DO I DO");
            break;
    }
}
