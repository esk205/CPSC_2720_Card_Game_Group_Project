#ifndef GOFISHDEALHANDLER_H
#define GOFISHDEALHANDLER_H

#include "StateHandler.h"
#include "Player.h"
#include "Hand.h"
#include "Game.h"

class GoFishDealHandler : public StateHandler
{
public:
    GoFishDealHandler(Game* game);
    virtual ~GoFishDealHandler();
    void handle();
protected:
private:
    /**
    * @brief Determines the dealer for this game.
    */
    Player* getDealer();

    /**
    * @brief Deals the cards, uses a pointer to the dealer to determine start of the deal
    */
    void deal(Player* dealer);

    /**
    * @brief Determines the starting hand size of each player based on number of players.
    */
    int getDealSize();

    /**
    * @brief Pointer to the game object we want to work with.
    */
    Game* game;
};

#endif // GOFISHDEALHANDLER_H
