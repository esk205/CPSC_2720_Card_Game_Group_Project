#include "BlackjackDealHandler.h"

BlackjackDealHandler::BlackjackDealHandler(Game* game)
{
    this->game = game;
}

BlackjackDealHandler::~BlackjackDealHandler()
{
    this->game = nullptr;
}

void BlackjackDealHandler::handle()
{
    game->deck = createDeck(5);
    game->deck.shuffle(1); // Save the trees! /s

    dealCards();

    game->gameMenu.say("The dealer deals two cards to each player.");
}

Deck BlackjackDealHandler::createDeck(int sets)
{
    if(sets <=0)
        throw invalid_parameter_error("Sets must be greater than 0");

    int suitSize = sizeof(AppConstants::STANDARD_SUIT_DECK) / sizeof(*AppConstants::STANDARD_SUIT_DECK);
    int pipSize = sizeof(AppConstants::STANDARD_PIP_DECK) / sizeof(*AppConstants::STANDARD_PIP_DECK) -1;

    Deck d = Deck();

    // Empty deck
    while(d.cardsRemaining()>0) { d.drawCard(); }

    // Create "sets" number of 52-card decks.
    for(int s = 0; s < sets; s++)
    {
        for (int i = 0; i < suitSize; i++)
        {
            for (int j = 0; j < pipSize; j++)
            {
                d.addCard(BlackjackCard(AppConstants::STANDARD_SUIT_DECK[i], AppConstants::STANDARD_PIP_DECK[j]));
            }
        }
    }

    return d;
}

void BlackjackDealHandler::dealCards()
{
    // Hand out two cards to each player
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < game->players.size(); j++)
        {
            game->players[j]->getHand()->addCard(game->deck.drawCard());
        }
    }
}
