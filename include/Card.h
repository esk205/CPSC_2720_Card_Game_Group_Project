#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
public:
    Card() {};

    /**
    * @brief Constructor. Does nothing
    */
    Card(string suit, string pip) {};
    virtual ~Card() {suit.clear(); pip.clear();};

    /**
    * @brief get method for showing the cards suit.
    * @return the suit of the card object.
    */
    string getSuit()
    {
        return suit;
    };

    /**
    * @brief get method for showing the cards pip.
    * @return the pip of the card object.
    */
    string getPip()
    {
        return pip;
    };

    /**
    * @brief get method for showing the cards rank value.
    * @return the ranking of the card object.
    */
    int getRankingValue()
    {
        return rankingValue;
    };

    /**
    * @brief get method for showing the cards suit rank.
    * @return the suit ranking of the card object.
    */
    int getSuitRanking()
    {
        return suitRanking;
    };

    /**
    * @brief Set the ranking value of the card for comaprison
    * @param value is the ranking worth of the card (pip)
    */
    void setRankingValue(int value)
    {
        rankingValue=value;
    };

    /**
    * @brief sets the suit ranking for easy sorting
    * @param value is the ranking worth of the suit in terms of sorting
    */
    void setSuitRanking(int value)
    {
        suitRanking=value;
    };

    /**
    * @brief returns the name of the card with its pip and suit names.
    */
    string getName()
    {
        return getPip() + " of " + getSuit();
    };

    /**
    * @brief Overload of the == operator.
    */
    virtual bool operator== (Card& lCard)
    {
        return (suit == lCard.getSuit() && pip == lCard.getPip());
    }

    /**
    * @brief Overload of the != operator.
    */
    virtual bool operator!= (Card& lCard)
    {
        return (suit != lCard.getSuit() || pip != lCard.getPip());
    }

    /**
    * @brief Overload of the > operator.
    */
    virtual bool operator> (Card& lCard)
    {
        return (rankingValue > lCard.getRankingValue());
    }

    /**
    * @brief Overload of the < operator.
    */
    virtual bool operator< (Card& lCard)
    {
        return (rankingValue < lCard.getRankingValue());
    }

protected:

    /**
    * @brief The suit of the card.
    */
    string suit;

    /**
    * @brief The pip of the card.
    */
    string pip;

    /**
    * @brief The ranking value of the card.
    */
    int rankingValue;

    /**
    * @brief The suit ranking of the card.
    */
    int suitRanking;

private:
};

#endif // CARD_H
