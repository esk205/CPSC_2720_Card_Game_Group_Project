#ifndef RANDOMBOTPLAYERCRAZYEIGHTS_H
#define RANDOMBOTPLAYERCRAZYEIGHTS_H

#include "Player.h"
#include "CrazyEightsGame.h"

class RandomBotPlayerCrazyEights : public Player
{
    public:
        /**
        * @brief Default constructor.
        */
        RandomBotPlayerCrazyEights();

        /**
        * @brief Deconstructor.
        */
        virtual ~RandomBotPlayerCrazyEights();
    protected:
        /**
        * @brief play function for the bot.
        * @param string message.
        * @param Choice menu choices.
        */
        int play(string message, Choices c);
    private:
        int promptCount;
        int cardPick;
        CrazyEightsPlayHandler* crazyPtr;
        Game* game;
};

#endif // RANDOMBOTPLAYERCRAZYEIGHTS_H
