#ifndef RANDOMBOTPLAYERBLACKJACK_H
#define RANDOMBOTPLAYERBLACKJACK_H

#include "Player.h"

class RandomBotPlayerBlackJack : public Player
{
    public:
        /**
        * @brief Default constructor.
        */
        RandomBotPlayerBlackJack();

        /**
        * @brief Deconstructor.
        */
        virtual ~RandomBotPlayerBlackJack();
    protected:
        int play(string message, Choices c);
    private:
};

#endif // RANDOMBOTPLAYERBLACKJACK_H
