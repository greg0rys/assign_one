#include <unistd.h>
#include "main.h"

int main()
{
    auto * yard = new ChickenYard();
    auto * player1 = new Player();
    auto * player2 = new Player();
    int p1Score = 0;
    int p2Score = 0;
    int x = 0;
    while(x != 5)
    {
        if(yard->isEmpty())
            break;
        sleep(1);
        cout << "before draw: " << yard->getCount() << endl;
        yard->getHand(player1);
        yard->getHand(player2);
        cout << "After draw: " << yard->getCount() << endl;
        player1->displayHand();
        player2->displayHand();
        player1->getPoints(p1Score);
        player2->getPoints(p2Score);
        sleep(1);
        cout << "p1 score: " << p1Score << endl;
        cout << "p2 score: " << p2Score << endl;

        cout << endl;
        x++;
    }



    delete yard;
    delete player1;
    delete player2;
    return 0;
}
