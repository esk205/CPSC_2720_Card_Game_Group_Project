#include "GameFactory.h"

#include "Game.h"
#include "BlackjackGame.h"
#include "CrazyEightsGame.h"
#include "GoFishGame.h"
#include "RockPaperScissorsGame.h"
#include "WarGame.h"

Game* GameFactory::makeGame(int choice)
{
    switch(choice)
    {
    case 1:
        return new BlackjackGame();
    case 2:
        return new CrazyEightsGame();
    case 3:
        return new GoFishGame();
    case 4:
        return new RockPaperScissorsGame();
    case 5:
        return new WarGame();
    default:
        return nullptr;
    }
}
