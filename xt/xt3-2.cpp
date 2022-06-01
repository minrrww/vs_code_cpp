#include <iostream>

using namespace std;

int main()
{
    int intOne;
    int &rSomeRef = intOne;
    intOne = 5;
    cout << "intOne \t\t" << intOne << endl;
    cout << "rSomeRef \t" << rSomeRef << endl;
    int intTwo = 8;
    rSomeRef = intTwo;
    cout << "intOne \t\t" << intOne << endl;
    cout << "intTwo \t\t" << intTwo << endl;
    cout << "rSomeRef \t" << rSomeRef << endl;
    getchar();
    return 0;
}
