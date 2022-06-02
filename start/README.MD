##1.2 初识输入输出
C++用一个全面的iostream标准库提供IO机制

iostream库：istream 输入流，ostream 输出流

istream类型：cin  标准输入
ostream类型：cout 标准输出
             cerr 输出警告和错误信息
             clog 输出程序运行时的一般信息

IO运算符:<< 输出运算符，>> 输入运算符
ostream类型对象<<右值
将右值写入ostream类型的对象中，返回ostream类型的对象作为计算结果
istream类型的对象>>右值
将读取的值存入右值，写入istream类型的对象中，并返回istream类型的对象作为计算结果

##1.3 注释简介
注释不能嵌套

##1.4 控制流

while语句：while (condition) statement
检测condition条件，为真时执行statement，为假时停止。

for语句：for(init-statement,condition,expression)statement
检测condition条件，为真时执行statement，为假时停止。

读取数量不定的输入数据：while(cin>>value)statement，if(cin>>value)statement
流为结束符或无效输入，条件为假，结束循环

if语句：if(condition)statement
检测condition条件，为真时执行statement，为假时停止或执行else语句。

1.5 类简介
数据结构 data structure
类，C++的数据结构，定义了一个类型，以及与其关联的一组操作。





