#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    cout << "35��8����:" << std::oct << 35<< endl;  //oct �˽���
    cout << "35��10����:" << std::dec <<-0b01110000000000000000000000000001<< endl;  //dec ʮ����
    cout << "35��16����:" << std::hex << 35 << endl;  //hex ʮ������
    cout << "35��2����:" << bitset<17>(-49540) << endl; //<8>����ʾ����8λ���
    getchar();//getchar��һ��int�͵ķ���ֵ�����������getcharʱ������͵����û�������
    //�û�������ַ�������ڼ��̻������С�ֱ���û����س�Ϊֹ���س��ַ�Ҳ���ڻ������У���
    return 0;
}

