#include "CrazyEightsCardsHandler.h"
#include "CrazyEightsPlayHandler.h"

CrazyEightsDealCardsHandler::CrazyEightsDealCardsHandler(Game* game) {
    this->game = game;
}

CrazyEightsDealCardsHandler::~CrazyEightsDealCardsHandler() {
    this->game = nullptr;
}

void CrazyEightsDealCardsHandler::handle() {
    game->gameMenu.say("\nStart Dealing Cards \n");
    game->gameMenu.say("The cards remaining in deck is " + to_string(game->deck.cardsRemaining()));
    game->deck.shuffle(1); // shuffles deck 1 times
    unsigned int i = 0;
        // Deal 5 cards to all players
        for (i = 0; i < game->players.size(); i++) {
            cout << "There are " << game->players.size() << " players in this game" << endl;
            game->gameMenu.say("\n*********************************************");
            game->gameMenu.say("Dealing Cards to " + game->players[i]->getName() );
            game->gameMenu.say("*********************************************\n");
            // // Deal 5 cards to the player[i]
            for(int j = 0; j < 5; j++) {
                Card sc = game->deck.drawCard(); // draw card from deck
                game->gameMenu.say("Card: " + sc.getName() + "\n"); // show pip
                game->players[i]->getHand()->addCard(sc); // add card to players hand
            }
        }
        game->gameMenu.say("The cards remaining in deck is " + to_string(game->deck.cardsRemaining()));
    game->gameMenu.say("Finished Dealing Cards \n");
    //game->gameMenu.clearScreen(); // clear screen
}
