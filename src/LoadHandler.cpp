#include "LoadHandler.h"
#include "Menu.h" // Remove

LoadHandler::LoadHandler(Game* game, string file)
{
    this->game = game;
    this->file = file;
}

LoadHandler::~LoadHandler()
{
    this->game = nullptr;
    this->file.clear();
}

void LoadHandler::handle()
{
    Menu menu = Menu();
    ifstream savefile(this->file);
    if(savefile.is_open())
    {
        menu.say("Opened");

        // Load file into memory
        string loadbuffer { istreambuf_iterator<char>(savefile), istreambuf_iterator<char>() };

        vector<string> lines = Tools::split(loadbuffer, "\n");

        int curPlayerIndex = -1;
        int stateStart = -1;
        bool playerLoop = false;

        menu.say("Loaded Players");

        // I'd like to rewrite this some day... I'm sorry.
        for(int i = 0; i < lines.size(); i++)
        {
            string line = lines[i];
            vector<string> data = Tools::split(line, ",");
            menu.say("Successfully split line");

            // If it's a header just skip it
            if(line[0] == '*' && line != "*PLAYERS\n")
            {
                // If it's the header after *PLAYERS
                if(playerLoop)
                {
                    playerLoop = false;
                    stateStart = i;
                    continue;
                }
                else
                    continue;
            }

            if(playerLoop)
            {
                const string strDiscard = "discard";

                Player p = Player();
                Hand* hnd = p.getHand();
                Deck* dk = p.getDiscard();

                int pIndex = atoi(data[0].c_str());
                p.setName(Tools::base64_decode(data[1]));
                p.setScore(atoi(data[2].c_str()));

                // Find where discard starts
                int discardStart = -1;
                // j = 3 because hand starts at 3
                for(int j = 3; j < data.size(); j++)
                {
                    string str = data[j];
                    // String::find does not like strings shorter than the arg
                    if(str.size() >= strDiscard.size())
                    {
                        if(str.find(strDiscard)!=string::npos)
                        {
                            discardStart = j;
                            break;
                        }
                    }
                }

                // Fill player hand and discard pile
                Deck tempHand = loadDeck(data, 3, discardStart);
                Deck tempDiscard = loadDeck(data, discardStart, data.size());

                for(int j = 0; j < tempHand.cardsRemaining(); j++)
                {
                    hnd->addCard(tempHand.getCard(j));
                }

                for(int j = 0; j < tempDiscard.cardsRemaining(); j++)
                {
                    dk->addCard(tempDiscard.getCard(j));
                }

                this->game->addPlayer(&p);
            } // end if(playerLoop)

            // Certain lines should always contain specific data
            switch(i)
            {
            // currentPlayer field
            case 1:
                curPlayerIndex = atoi(data[0].c_str());
                continue;
            // Turn field
            case 2:
                this->game->turn = atoi(data[0].c_str());
                continue;
            // PLAYERS header
            case 4:
                playerLoop = true;
                continue;
            };

            if(stateStart!=-1)
            {
                int position = i - stateStart;
                switch(position)
                {
                case 1:
                    this->game->state = static_cast<State>(atoi(data[0].c_str()));
                    continue;
                case 3:
                    this->game->deck = loadDeck(data, 0, data.size());
                    continue;
                case 4:
                    this->game->discard = loadDeck(data, 0, data.size());
                };
            }


        } // end for loop on line

        //this->game->currentPlayer = *this->game->players[curPlayerIndex];
        this->game->setCurrentPlayer(this->game->players[curPlayerIndex]);
    }
    else
    {
        // Throw exception?
        this->game->gameMenu.say("Save file does not exist.");
        this->game->gameMenu.say(AppConstants::PRESS_ENTER);
        cin.get(); cin.get();
        return;
    }
}

Deck LoadHandler::loadDeck(vector<string> data, int startIndex, int endIndex)
{
    Deck d = Deck();
    for(int i = startIndex; i < endIndex; i+=5)
    {
        string suit = data[i+1];
        string pip = data[i+2];
        int rankingvalue = atoi(data[i+3].c_str());
        int suitranking = atoi(data[i+4].c_str());

        Card c = Card(suit, pip);
        c.setRankingValue(rankingvalue);
        c.setSuitRanking(suitranking);

        d.addCard(c);
    }
    return d;
}
