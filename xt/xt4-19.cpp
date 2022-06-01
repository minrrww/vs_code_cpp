#include <iostream>
enum Word_length
{
    _32bit,
    _64bit
};
enum Computer_count
{
    Single_core,
    Dual_core,
    Quad_core
};
using namespace std;
class CPU
{
public:
    CPU(unsigned short Clock_rate, Word_length Word_len, Computer_count Com_count, bool Hyper_threading)
    {
        clock_rate = Clock_rate;
        word_len = Word_len;
        com_count = Com_count;
        hyper_threading = Hyper_threading;
    }
    CPU(CPU &c)
    {
        clock_rate = c.clock_rate;
        word_len = c.word_len;
        com_count = c.com_count;
        hyper_threading = c.hyper_threading;
    }
    ~CPU() {}
    void show();

protected:
private:
    unsigned short clock_rate:12;
    Word_length word_len:1;
    Computer_count com_count:2;
    bool hyper_threading:1;
};
void CPU::show()
{
    cout << "Clock rate:\t\t" << clock_rate <<"MHz"<< endl;
    switch (word_len)
    {
    case _32bit:
        cout << "Word length:\t\t"
             << "_32bit" << endl;
        break;
    case _64bit:
        cout << "Word length:\t\t"
             << "_62bit" << endl;
    default:
        break;
    }
    switch (com_count)
    {
    case Single_core:
        cout << "Computer count:\t\t"
             << "single core" <<endl;
        break;
    case Dual_core:
        cout << "Computer count:\t\t"
             << "Dual core" <<endl;
        break;
    case Quad_core:
        cout << "Computer count:\t\t"
             << "Quad core" <<endl;
        break;
    default:
        break;
    }
    cout << "Hyper_threading:\t" << (hyper_threading ? "是" : "否") << endl;
}
int main()
{
    CPU cpu(3000,_64bit,Quad_core,1);
    cpu.show();
    cout << sizeof(CPU) << endl;
    cout << sizeof(Word_length) << endl;
    cout << sizeof(Computer_count) << endl;
    cout << sizeof(bool) << endl;
    return 0;
}
