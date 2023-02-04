#include "Game.h"

Game::Game():boneYard(nullptr), hasBones(false), leadPlayer(nullptr)
{
    gameStart();
}

Game::Game(vector<Player> &players, ChickenYard *yard)
{
    this->players = players;
    this->boneYard = yard;
    // i.e. hasBones = oppposite of boneYard->isEmpty() results
    this->hasBones = !this->boneYard->isEmpty();
}


Game::Game(const Game &aGame):boneYard(nullptr), hasBones(false),
                             leadPlayer(nullptr)
{
    *this = aGame;
}


Game& Game::operator=(const Game &aGame)
{
    if(this == &aGame)
        return *this;
    if(boneYard)
        delete boneYard;

}

