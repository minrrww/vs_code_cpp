#include <cstdlib>
#include <iostream>
using namespace std;
int rollDice()
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int sum = die1 + die2;
    return sum;
}
enum gameStatus
{
    WIN,
    LOSE,
    PLAYING
};
int main()
{
    int sum, mypoint;
    gameStatus status;
    unsigned seed;
    cin >> seed;
    srand(seed);
    sum = rollDice();
    switch (sum)
    {
    case 7:
    case 11:
        status = WIN;
        break;
    case 2:
    case 3:
    case 12:
        status = LOSE;
        break;
    default:
        status = PLAYING;
        mypoint = sum;
        break;
    }
    while (status == PLAYING)
    {
        sum = rollDice();
        if (sum == mypoint)
            status = WIN;
        else if (sum == 7)
            status = LOSE;
    }
    if (status == WIN)
        cout << "WIN" << endl;
    else
        cout << "LOSE" << endl;
}
