#include <iostream>

using namespace std;
class Tree
{
public:
Tree(int Ages):ages(Ages){}
void grow(int years) { ages+= years;}
void age()
{
    cout << "树龄：\t" << ages<< endl;
    }
protected:

private:
    int ages;
};
int main()
{
    Tree tree(2);
    tree.age();
    tree.grow(6);
    tree.age();
    return 0;
}
