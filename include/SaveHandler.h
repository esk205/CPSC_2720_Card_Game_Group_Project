#ifndef SAVEHANDLER_H
#define SAVEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "Tools.h"
#include "StateHandler.h"

class SaveHandler : public StateHandler
{
public:
    /**
    * @brief Default constructor.
    * @param Game* game pointer.
    * @param string file.
    */
    SaveHandler(Game* game, string file);

    /**
    * @brief Deconstructor.
    */
    virtual ~SaveHandler();

    /**
    * @brief Save handler.
    */
    void handle();
protected:
private:
    Game* game;
    string file;
};

#endif // SAVEHANDLER_H
