#ifndef SPECIALBOTPLAYERRPS_H
#define SPECIALBOTPLAYERRPS_H

#include "Player.h"

class SpecialBotPlayerRPS : public Player
{
    public:
        /**
        * @brief Default constructor.
        */
        SpecialBotPlayerRPS();

        /**
        * @brief Deconstructor.
        */
        virtual ~SpecialBotPlayerRPS();
    protected:
        /**
        * @brief Play method for the special RPS bot.
        **/
        int play(string message, Choices c);
    private:
        int promptCount;
};

#endif // SPECIALBOTPLAYERRPS_H
