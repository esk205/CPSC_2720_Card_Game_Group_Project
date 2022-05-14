#ifndef DUMBBOT_H
#define DUMBBOT_H

#include <Player.h>


class DumbBot : public Player
{
    /**
    * @brief Dumb bot, total idiot.
    */
    public:

        /**
        * @brief Default constructor.
        */
        DumbBot() {};

        /**
        * @brief Deconstructor.
        */
        virtual ~DumbBot() {};
    protected:

        /**
        * @return Always returns 1 as in the first prompt
        * @param message is the message that is displayed on screen for the player
        * @param c is the choices the player recieves and can select from
        */
        int play(string message, Choices c) {return 1;}
    private:
};

#endif // DUMBBOT_H
