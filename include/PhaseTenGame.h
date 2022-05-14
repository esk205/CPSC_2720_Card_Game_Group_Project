#ifndef PHASETENGAME_H
#define PHASETENGAME_H

#include "Game.h"

class PhaseTenGame : public Game
{
public:

    /**
    * @brief Default constructor.
    */
    PhaseTenGame();

    /**
    * @brief Deconstructor.
    */
    virtual ~PhaseTenGame();

    /**
    * @brief checks the current state of the game
    */
    void checkState();

protected:
private:
};

#endif // PHASETENGAME_H
