#ifndef RANDOMBOTPLAYERRPS_H
#define RANDOMBOTPLAYERRPS_H

#include "Player.h"

class RandomBotPlayerRPS : public Player
{
    public:
        /**
        * @brief Default constructor.
        */
        RandomBotPlayerRPS();

        /**
        * @brief Deconstructor.
        */
        virtual ~RandomBotPlayerRPS();
    protected:

        /**
        * @brief Always chooses 1 on the first prompt then randomly chooses a number from the passed in prompts
        * @return Returns the chosen prompt integer
        * @param message is the message that is displayed on screen for the player
        * @param c is the choices the player recieves and can select from
        */
        int play(string message, Choices c);
    private:
        int promptCount;
};

#endif // RANDOMBOTPLAYERRPS_H
