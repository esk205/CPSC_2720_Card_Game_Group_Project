#include "EndGameHandler.h"

EndGameHandler::EndGameHandler()
{
    //ctor
}

EndGameHandler::~EndGameHandler()
{
    //dtor
}

void EndGameHandler::handle()
{
    Menu gameMenu = Menu();
    gameMenu.displayMainMenu();
}
