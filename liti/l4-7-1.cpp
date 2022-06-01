////#include <stdexcept>
//void* _Unwind_Resume = nullptr;
//void* __gxx_personality_seh0 = nullptr;
//int main() { throw std::runtime_error("xxx");}

//new_feature.cpp
/*#include <iostream>
#include <string>

class MyClass
{
      public:
            std::string s ="Hello, world\n"; // Non-static data member initializer
};

int main()
{
      std::cout << MyClass().s;
}*/

#include <cstdio>
#include <string>
#include <iostream>
int main()
{
      std::string s;               //空字符串
      std::cin >> s;               //将string对象读入s，遇到空白停止
      std::cout << s << std::endl; //输出s
      return 0;
}
