#include <iostream>

using namespace std;
class Dog
{
public:
    Dog(int Age, double Weight)
    {
        age = Age;
        weight = Weight;
    }
    int getAge() { return age; }
    double getWeight() { return weight; }

private:
    int age;
    double weight;
};
int main()
{
    Dog dog(3, 20);
    cout << dog.getAge() << endl;
    cout << dog.getWeight() << endl;
    return 0;
}
