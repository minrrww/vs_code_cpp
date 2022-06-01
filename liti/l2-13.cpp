//2_11.cpp
#include <iostream>
using namespace std;

enum GameResult
{
    WIN,
    LOSE,
    TIE,
    CANCEL
}; //枚举类型

int main()
{
    GameResult result;                              //声明对象（变量）缺省enum关键词
    enum GameResult omit = CANCEL;                  //声明变量并初始化
    for (int count = WIN; count <= CANCEL; count++) //枚举类型隐含转换为int
    {
        result = GameResult(count); //int显示转换为枚举类型方法1
        //result = (GameResult)(count);//int显示转换为枚举类型方法2
        //result = static_cast<GameResult>(count);//int显示转换为枚举类型方法3
        if (result == omit)
            cout << "The game was cancelled" << endl;
        else
        {
            cout << "The game was Played";
            if (result == WIN)
                cout << " and we won";
            if (result == LOSE)
                cout << " and we lost";
            cout << endl;
        }
    }
    return 0;

}
/*输出
The game was Played and we won
The game was Played and we lost
The game was Played
The game was cancelled
*/
