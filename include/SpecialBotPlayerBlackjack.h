#ifndef SPECIALBOTPLAYERBLACKJACK_H
#define SPECIALBOTPLAYERBLACKJACK_H

#include "Player.h"

class SpecialBotPlayerBlackjack : public Player
{
    public:
        /**
        * @brief Default constructor.
        */
        SpecialBotPlayerBlackjack();

        /**
        * @brief Deconstructor.
        */
        virtual ~SpecialBotPlayerBlackjack();
    protected:

        /**
        * @brief Play method for the Special Blackjack Bot
        * @param string message.
        * @param Choices menu.
        */
        int play(string message, Choices c);
    private:
};

#endif // SPECIALBOTPLAYERBLACKJACK_H
