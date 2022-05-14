#include "Hand.h"
#include "Card.h"

Hand::Hand()
{
    //ctor
}

Hand::~Hand()
{
    cards.clear();
}

void Hand::emptyHand()
{
    cards.clear();
}

void Hand::addCard(Card c)
{
    cards.push_back(c);
}

void Hand::removeCard(Card c)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (c == cards[i])
            cards.erase(cards.begin() + i);
    }
}

Card Hand::removeCard(int location)
{
    Card removedCard = cards[location];
    cards.erase(cards.begin() + location);
    return removedCard;
}

Card Hand::getCard(int location)
{
    return cards[location];
}

void Hand::sortByValue()
{
    for (int i = cards.size() - 1; i > 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (cards[j] > cards[j+1])
            {
                Card tmp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = tmp;
            }
        }
    }
}

void Hand::sortBySuit()
{
    for (int i = cards.size() - 1; i > 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (cards[j].getSuitRanking() > cards[j+1].getSuitRanking())
            {
                Card tmp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = tmp;
            }
        }
    }

    int suit1End, suit2End, suit3End;
    int suit4End = cards.size() - 1;

    vector<int> suitPositions;
    /// After being sorted into their repective suit categories then I should be able to find
    /// exactly where the category ends for each.
    /// Since cards have a definite four suits rule I can hard code 4 different conditions.
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getSuitRanking() == 2)
            suitPositions.push_back(i - 1);
        else if (cards[i].getSuitRanking() == 3)
            suitPositions.push_back(i - 1);
        else if (cards[i].getSuitRanking() == 4)
        {
            suitPositions.push_back(i - 1);

            /// Break out, the loop is no longer needed
            break;
        }
    }

    suitPositions.push_back(cards.size() - 1);

    int currentSuitIndex = 0;
    for (int i = 0; i <= suitPositions.size(); i++)
    {
        sortByValueAfterSuit(currentSuitIndex, suitPositions[i]);
        currentSuitIndex = suitPositions[i + 1];
    }
}

void Hand::sortByValueAfterSuit(int indexStart, int indexEnd)
{
    for (int i = indexEnd ; i > 0; i--)
    {
        for (int j = indexStart; j <= indexEnd - 1; j++)
        {
            if (cards[j] > cards[j+1])
            {
                Card tmp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = tmp;
            }
        }
    }
}

int Hand::cardsRemaining()
{
    return cards.size();
}

string Hand::to_string()
{
    string result = "";
    for (int i = 0; i < cards.size(); i++)
    {
        result += cards[i].getName() + " | ";
    }
    return result;
}
string Hand::to_stringOnce(unsigned int i)
{
    return cards[i].getName();
}

vector<Card> Hand::getCards()
{
    return cards;
}
