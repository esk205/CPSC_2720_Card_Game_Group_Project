#ifndef GOFISHGAME_H
#define GOFISHGAME_H

#include "Game.h"
#include "StandardCard.h"
#include "AppConstants.h"
#include "GameStartHandler.h"
#include "GoFishDealHandler.h"
#include "GoFishPlayHandler.h"
#include "EndGameHandler.h"

class GoFishGame : public Game
{
public:
    /**
    * @brief Default constructor.
    */
    GoFishGame();

    /**
    * @brief Deconstructor.
    */
    virtual ~GoFishGame();
protected:
    void update();
private:
};

#endif // GOFISHGAME_H
