//第八章 IO 库
/*C++语言不直接处理输入输出，而是通过一族定义在标准库中的类型来处理IO。
这些类型支持从设备读取数据、向设备写入数据的IO操作，设备可以是文件、控制台窗口等。
还有一些类型允许内存IO，即从string读取数据，向string写入数据。
已经介绍的大部分IO库设施：
istream（输入流）类型，提供输入操作
ostream（输出流）类型，提供输出操作
cin,一个istream对象，从标准输入读取数据。
cout,一个ostream对象，向标准输出写入数据。
cerr,一个ostream对象，通常用于输出程序错误信息，写入到标准错误。
>>运算符，用来从一个istream对象读取输入数据。
<<运算符，用来向一个ostream对象写入输出数据。
getline函数，从一个给定的istream读取一行数据，存入一个给定的string对象中。*/
//8.1 IO类
/*三个独立的头文件:
iostream定义类用于读写流的基本类型，
fstream定义类读写命名文件的类型，
sstream定义了读写内存string对象的类型。
表8.1：IO库类型和头文件
头文件     类型
iostream   istream，wistream从流读取数据
           ostream，wostream向流写入数据
           iostream，wiostream读写流
fstream    ifstream，wifstream从文件读取数据
           ofstream，wofstream向文件写入数据
           fstream，wfstream读写文件
sstream    istringstream，wistringstream从string读取数据
           ostringstream，wostringstream向string写入数据
           stringstream，wstringstream读写string
为类支持使用宽字符的语言，标准库定义类一组类型和对象来操纵wchar_t类型的数据。
wcin、wcout和wcerr分别对应cin、cout、cerr。
宽字符版本的类型和对象与其对应的普通char版本的类型定义在同一个头文件中。
1.IO类型间的关系
标准库使我们能忽略不同类型的流之间的差异，这是继承机制（inheritance）实现的。
ifstream和istringstream都继承自istream。*/
//8.1.1 IO对象无拷贝或赋值
/*不能拷贝或对IO对象赋值
不能将形参或返回类型设置为流类型。
进行IO操作的函数通常以引用方式传递和返回流。
读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的。*/
//8.1.2 条件状态
/*IO操作一个与生俱来的问题是可能发生错误。
表8.2：IO库条件状态
strm::iostate      strm是一种IO类型，iostate是一种机器相关的类型，
                   提供了表达条件状态的完整功能
strm::badbit       strm::badbit用来指出流已崩溃
strm::failbit      strm::failbit用来指出一个IO操作失败了
strm::eofbit       strm::eofbit用来指出流达到了文件结束
strm::goodbit      strm::goodbit用来指出流未处于错误状态。此值保证为零
s.eof()            若流s的eofbit置位，则返回true
s.fail()           若流s的failbit或badbit置位，则返回true
s.bad()            若流s的badbit置位，则返回true
s.good()           若流s处于有效状态，，则返回true
s.clear()          若流s中所有条件状态复位，将流的状态设置为有效。返回void
s.clear(flags)     根据给定的flags标志位，将流s中对应条件状态位复位。
                   flags的类型为strm::iostate。返回void
s.setstate(flags)  根据给定的flags标志位，将流s中对应条件状态位置位。
                   flags的类型为strm::iostate。返回voi
s.rdstate()        返回流s的当前条件状态，返回值类型为strm::iostate

确定流对象的状态的最简单的方法是将它当作一个条件来使用：
while (cin>>word)
//ok：读操作成功...
1.查询流的状态
IO库定义类一个与机器无关的iostate类型，提供了表达流状态的完整功能。
IO库定义类4个iostate类型的constexpr值，表示特定的位模式。
这些值表示特定类型的IO条件，可以与位运算符一起使用来一次性检测或设置多个标志位。
标准库定义类一组函数来查询这些标志位的状态。
将流当作条件使用的代码等价于!fail()。eof和bad操作只能表示特定的错误。
2.管理条件状态
流对象的rdstate成员返回一个iostate值，对应流的当前状态。
setstate操作给定条件位置位，表示发生对应错误。
clear成员时一个重载的成员：它有一个不接受参数本和一个接受一个iostate类型的参数两个版本。
*/
//8.1.3 管理输出缓冲
/*导致缓冲刷新的原因有很多：
程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区。
操纵符endl来显式刷新缓冲区。
每个输出操作之后，可以用操纵符unitbuf设置流的内部状态，来清空缓冲区。
    默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的。
一个输出流可能被关联到另一个流。当读写被关联的流时，
    关联到的流的缓冲区会被刷新。读cin或写cerr都会导致cout的缓冲区被刷新。
1.刷新输出缓冲区
endl 换行并刷新缓冲区
flush刷新缓冲区
ends向缓冲区插入一个空字符，然后刷新缓冲区
2.unitbuf操纵符
如果每次输出操作后都刷新缓冲区，可以使用unitbuf操纵符。
unitbuf告诉流接下来每次写操作之后都进行一次flush操作。
nounitbuf操纵符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制。
3.关联输入和输出流
当一个输入流被关联到一个输出流时，任何试图丛输入流读取数据的操作都会先
刷新管理的输出流。
tie有两个重载版本：一个版本不带参数，返回指向输出流的指针。
如果本对象当前关联到一个输出流，则返回的是指向这个流的指针，否则返回空指针。
tie的第二个版本接受一个指向ostream的指针，将自己关联到此ostream。
x.tie(&o)将流x关联到输出流o
每个流同时最多关联到一个流，但多个流可以同时关联到同一个ostream。*/
