#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter x and y." << endl;
    cin >> x >> y;
    if (x != y)
    {
        if (x > y)
            cout << x << ">" << y << endl;
        else
            cout << x << "<" << y << endl;
    }
    else
        cout << x << "=" << y << endl;

    int a, b;
    cout << "Enter a and b." << endl;
    cin >> a >> b;
    if (a == b)
        cout << "a=b" << endl;
    else if (a > b)
        cout << "a>b" << endl;
    else
        cout << "a<b" << endl;

    int day;
    cout << "Enter the Day." << endl;
    cin >> day;
    switch (day)
    {
    case 0:
        cout << "Sunday" << endl;
        break;
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    default:
        cout << "Day out of range Sunday...Saturday." << endl;
        break;
    }
    getchar();
    return 0;
}
