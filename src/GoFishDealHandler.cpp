#include "GoFishDealHandler.h"

GoFishDealHandler::GoFishDealHandler(Game* game)
{
    this->game = game;
}

GoFishDealHandler::~GoFishDealHandler()
{
    game = nullptr;
}

void GoFishDealHandler::handle()
{
    deal(getDealer());
}

Player* GoFishDealHandler::getDealer()
{
    Card lowest;
    Player* dealer;
    game->deck.shuffle(10);
    lowest.setRankingValue(99); // value arbitrarily set high to be overwritten.

    for (int i = 0; i < game->players.size(); i++)
    {
        Player* p = game->players[i];
        Card c = game->deck.drawCard();
        game->gameMenu.say(p->getName() + " gets " + c.getName());

        if (c < lowest)
        {
            lowest = c;
            dealer = p;
        }
    }

    game->gameMenu.say("Player: " + dealer->getName() + " is the dealer.");
    return dealer;
}

void GoFishDealHandler::deal(Player* dealer)
{
    bool dealStarted = false;
    int dealSize = getDealSize();
    game->gameMenu.say("Dealing " + to_string(dealSize) + " cards to each player.");
    for (int j = 0; j <= dealSize; j++)
    {
        for (int i = 0; i < game->players.size(); i++)
        {
            if (dealStarted)
            {
                Player* currentPlayer = game->players[i];
                Hand* hand = currentPlayer->getHand();
                Card c = game->deck.drawCard();
                hand->addCard(c);
            }

            if (game->players[i]->getName() == dealer->getName())
                dealStarted = true;
        }
    }
}

int GoFishDealHandler::getDealSize()
{
    int players = game->players.size();
    return players <= 3 ? 7 : 5;
}
