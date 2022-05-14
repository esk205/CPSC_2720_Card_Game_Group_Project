#ifndef ENDGAMEHANDLER_H
#define ENDGAMEHANDLER_H

#include "StateHandler.h"
#include "Menu.h"

class EndGameHandler : public StateHandler
{
    /**
    * @brief Generic end of game handler.
    */
    public:
        /**
        * @brief Default constructor.
        */
        EndGameHandler();

        /**
        * @brief Deconstructor.
        */
        virtual ~EndGameHandler();

        /**
        * @brief Handler function.
        */
        void handle();
    protected:
    private:
        /**
        * @brief Menu used in the end game state.
        */
        Menu gameMenu;
};

#endif // ENDGAMEHANDLER_H
