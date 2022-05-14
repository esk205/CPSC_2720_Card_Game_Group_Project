#include <iostream>
#include <string>

#include "AppConstants.h"
#include "Game.h"
#include "GameFactory.h"
#include "Menu.h"
#include "StandardCard.h"

using namespace std;

int main()
{
    Menu menu = Menu();
    menu.displayMainMenu();

    return 0;
}
