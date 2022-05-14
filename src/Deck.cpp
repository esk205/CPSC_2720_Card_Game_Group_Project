#include <algorithm>
#include "AppConstants.h"
#include "Deck.h"
#include "Card.h"
#include "StandardCard.h"
#include "time.h"

Deck::Deck()
{
    // Makes a typical 52 card deck.
    int suitSize = sizeof(AppConstants::STANDARD_SUIT_DECK) / sizeof(*AppConstants::STANDARD_SUIT_DECK);
    int pipSize = sizeof(AppConstants::STANDARD_PIP_DECK) / sizeof(*AppConstants::STANDARD_PIP_DECK) -1;

    for (int i = 0; i < suitSize; i++)
    {
        for (int j = 0; j < pipSize; j++)
        {
            cards.push_back(StandardCard(AppConstants::STANDARD_SUIT_DECK[i], AppConstants::STANDARD_PIP_DECK[j]));
        }
    }
}

Deck::~Deck()
{
    cards.clear();
}

void Deck::addCard(Card card)
{
    cards.push_back(card);
}

Card Deck::drawCard()
{
    Card c = cards.back();
    cards.pop_back();
    return c;
}

/// Needs to be re written
void Deck::shuffle(int times)
{
    srand(time(NULL));
    int cycle = (rand() % 25) * times;
    for (int i = 0; i < cycle; i++)
    {
        std::random_shuffle(cards.begin(), cards.end());
    }
}

void Deck::badShuffle(int times)
{
    for (int i = 0; i < times; i++)
    {
        std::random_shuffle(cards.begin(), cards.end());
    }
}

int Deck::cardsRemaining()
{
    return cards.size();
}

Card Deck::getCard(int location)
{
    return cards[location];
}

void Deck::emptyStandardDeck()
{
     // Makes a typical 52 card deck.
    int suitSize = sizeof(AppConstants::STANDARD_SUIT_DECK) / sizeof(*AppConstants::STANDARD_SUIT_DECK);
    int pipSize = sizeof(AppConstants::STANDARD_PIP_DECK) / sizeof(*AppConstants::STANDARD_PIP_DECK) -1;

    for (int i = 0; i < suitSize; i++) {
        for (int j = 0; j < pipSize; j++) {
            cards.pop_back();
        }
    }
}

