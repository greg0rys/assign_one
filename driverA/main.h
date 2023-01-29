#include "main.h"
#include "Player.h"

int main()
{
    auto *testYard = new ChickenYard();
    cout << "Yard count before draw: " << testYard->getCount() << endl;
    auto *player1 = new Player();
    player1->generateHand(testYard);
    cout << "Yard count after draw: " << testYard->getCount();

    return 0;
}

