#include <iostream>
#include <string.h>
using namespace std;
class person{
private:
    char *name;
    int age;
public:
    person(const char *Name,int Age)
    {
        name=new char[strlen(Name)+1];
        strcpy(name,Name);
        age=Age;
        cout<<"construct ..."<<endl;
    }
    ~person()
    {
        cout<<"destruct ..."<<age<<endl;
        delete name;
    }
    void dispaly()
    {
        cout<<name<<" "<<age<<endl;
    }
    void setage(int x)
    {
        age=x;
    }
};
int main()
{
   person p1("jack",23);
   person p2=p1;
   p1.setage(10);
//   p2.setage(20);
   p1.dispaly();
   p2.dispaly();
    return 0;
}
