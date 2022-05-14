#ifndef RANDOMBOTPLAYERGOFISH_H
#define RANDOMBOTPLAYERGOFISH_H

#include "Player.h"

class RandomBotPlayerGoFish : public Player
{
    public:
        /**
        * @brief Default Constructor.
        */
        RandomBotPlayerGoFish();

        /**
        * @brief Deconstructor.
        */
        virtual ~RandomBotPlayerGoFish();
    protected:
        int play(string message, Choices c);
    private:
};

#endif // RANDOMBOTPLAYERGOFISH_H
