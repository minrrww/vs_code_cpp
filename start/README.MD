1.2初识输入输出
C++用一个全面的iostream标准库提供IO机制

1.2.1类型

iostream库包括两个基础类型：
输入流类型 istream
输出流类型 ostream

1.2.2对象

istream类型 标准输入对象                 cin
ostream类型 标准输出对象                 cout
            输出警告和错误信息对象       cerr
            输出程序运行时的一般信息对象 clog

1.2.3运算符

<< 输出运算符
ostream类型对象<<右值
将右值写入ostream类型的对象中，返回ostream类型的对象作为计算结果

>> 输入运算符
istream类型的对象>>右值
将读取的值存入右值，写入istream类型的对象中，并返回istream类型的对象作为计算结果

:: 作用域运算符
命名空间::名字
指出定义在命名空间中的名字

1.2.4endl操纵符
结束当前行，并将设备关联的缓冲区中的内容刷到设备中

1.3注释简介
注释不能嵌套

1.4 控制流

1.4.1 while语句
while (condition) statement
检测condition条件，为真时执行statement，为假时停止。
condition条件为一个真或假的表达式。
1.4.2 for语句
for(init-statement,condition,expression)statement
1.4.3 读取数量不定的输入数据





