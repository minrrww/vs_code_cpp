#include <iostream>
#include <iomanip>
using namespace std;
int cuboid_volume(int length, int withth = 2, int height = 3);
int main()
{
    const int x=10, y=15, z=20;
    cout << "Some box data is:";
    cout << setw(5) << cuboid_volume(x, y, z)<<endl;
    cout << "Some box data is:";
    cout << setw(5) << cuboid_volume(x, y)<<endl;
    cout << "Some box data is:";
    cout << setw(5) << cuboid_volume(x)<<endl;
    getchar();
    return 0;
}
int cuboid_volume(int length,int withth/*=2*/,int height/*=3*/)
{
    cout << setw(5) << length << setw(5) << withth << setw(5) << height << '\t';
    return length * withth * height;
}
