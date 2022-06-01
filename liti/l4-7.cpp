
#include <iostream>
#include <cstring>
#include <string>
//void* _Unwind_Resume = nullptr;
//void* __gxx_personality_seh0 = nullptr;
using namespace std;
/*class student
{
public:
    student(int _num = 97001, string _name = "LinLin", char _sex = 'F', int _age = 19)
    {
        num = _num;
        name = _name;
        sex = _sex;
        age = _age;
    }
    int getNum() { return num; }
    string getName() { return name; }
    char getSex() { return sex; }
    int getAge() { return age; }

private:
    int num;
    std::string name;
    char sex;
    int age;
};*/
struct student{
    int num = 97001;
    string name = "LinLin";
    char sex = 'F';
    int age = 19;
};
int main()
{
    student stu1;
    student stu2{97002, "HuaHua", 'F', 20};
    cout << "name:" << stu1.name << endl;
    cout << "name:" << stu2.name << endl;
    /*cout << "num:" << stu1.getNum() << endl;
    cout << "name:" << stu1.getName() << endl;
    cout << "sex:" << stu1.getSex() << endl;
    cout << "age:" << stu1.getAge() << endl;
    cout << "num:" << stu2.getNum() << endl;
    cout << "name:" << stu2.getName() << endl;
    cout << "sex:" << stu2.getSex() << endl;
    cout << "age:" << stu2.getAge() << endl;*/
    getchar();
    return 0;
}
