/*************************************************************************/ /**
*	@file		LinkedList.h
*	@brief		单链表
*
*	《Ｃ＋＋语言程序设计》（郑莉 董渊 编著） 第 9 章 群体类 链表类
*	其中给了单链表的类声明，而类实现未给出。这里给出了类声明和实现。
*
*	为了防止自由随意性编码，
*		事先作出一些限制以利于编程。
*	因为 front 和 rear 决定了 size 值，约定：
*		先修改 front 或 rear 再修改 size
*	因为 position 决定了 prevPtr 和 currPtr 值，约定：
*		先修改 position 再修改 prevPtr 和 currPtr
*	允许空表，约定此时有：
*		front = rear = NULL, size = 0;
*	允许 position 是任何整数，约定：
*		position < 0 时 prevPtr = currPtr = NULL;
*		position = 0 时 prevPtr = NULL, currPtr = front;
*		position = size 时，prevPtr = rear, currPtr = NULL;
*		position > size 时，prevPtr = currPtr = NULL;
*	当链表发生变化时，先调节 front 和 rear 再调节 position。
*****************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    // 数据成员：
    Node<T> *front, *rear;      // 表头和表尾指针
    Node<T> *prevPtr, *currPtr; // 记录表当前遍历位置的指针，由插入和删除操作更新
    int size;                   // 表中的元素个数
    int position;               // 当前元素在表中的位置序号。由函数 Reset 使用

    // 函数成员：

    // 生成新结点，数据域为 item，指针域为 ptrNext
    Node<T> *newNode(const T &item, Node<T> *ptrNext = NULL);

    // 释放结点
    void freeNode(Node<T> *p);

    // 将链表 L 拷贝到当前表（假设当前表为空）。
    // 被复制构造函数和“operator =”调用
    void copy(const LinkedList<T> &L);

public:
    LinkedList(void);                                 // 构造函数
    LinkedList(const LinkedList<T> &L);               // 复制构造函数
    ~LinkedList();                                // 析构函数
    LinkedList<T> &operator=(const LinkedList<T> &L); // 重载赋值运算符

    int getSize(void) const;  // 返回链表中元素个数
    bool isEmpty(void) const; // 链表是否为空

    void reset(int pos = 0);         // 初始化游标的位置
    void next(void);                 // 使游标移动到下一个结点
    bool endOfList(void) const;      // 游标是否到了链尾
    int currentPosition(void) const; // 返回游标当前的位置

    void insertFront(const T &item);  // 在表头插入结点
    void insertRear(const T &item);   // 在表尾插入结点
    void insertBefore(const T &item); // 在当前结点之前插入结点
    void insertAfter(const T &item);  // 在当前结点之后插入结点

    T deleteFront(void);      // 删除头结点
    void deleteCurrent(void); // 删除当前结点

    T &data(void);             // 返回对当前结点成员数据的引用
    const T &data(void) const; // 返回对当前结点成员数据的常引用

    // 清空链表：释放所有结点的内存空间。被析构函数和“operator =”调用
    void clear(void);
};

/**
	@brief	生成新结点
	@param	item	数据域
	@param	ptrNext	指针域
	@return	新结点
*/
template <class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext)
{
    Node<T> *newNode;

    newNode = new Node<T>(item, ptrNext);

    if (newNode == NULL)
    {
        cerr << "Memory allocation failure!" << endl;
        exit(1);
    }

    return newNode;
}

/**
	@brief	释放结点
	@param	p	指定结点
*/
template <class T>
void LinkedList<T>::freeNode(Node<T> *p)
{
    delete p;
}

/**
	@brief	将同类链表拷贝到当前空表
	@param	L	同类链表
	@note	当前表为空表
	被复制构造函数和“operator =”调用
*/
template <class T>
void LinkedList<T>::copy(const LinkedList<T> &L)
{
    if (L.size == 0)
        return;

    front = rear = newNode(L.front->Data);

    for (Node<T> *srcNode = L.front->nextNode();
         srcNode != NULL;
         srcNode = srcNode->nextNode())
    {
        Node<T> *newNode = newNode(srcNode->Data);
        rear->insertAfter(newNode);
        rear = newNode;
    }

    size = L.size;
    reset(position = L.currentPosition());
}

/**
	@brief	构造函数
	@note	默认空表
*/
template <class T>
LinkedList<T>::LinkedList(void)
    : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0)
{
}

/**
	@brief	复制构造函数
	@param	L	复制对象
*/
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L)
    : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0)
{
    copy(L);
}

/**
	@brief	析构函数
*/
template <class T>
LinkedList<T>::~LinkedList(void)
{
    clear();
}

/**
	@brief	重载赋值运算符
	@param	L	复制对象
	@return	当前对象
*/
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &L)
{
    clear();
    copy(L);

    return *this;
}

/**
	@brief	返回链表中元素个数
	@return	当前链表中元素个数
*/
template <class T>
int LinkedList<T>::getSize(void) const
{
    return size;
}

/**
	@brief	判断是否空表
	@return	链表是否为空
*/
template <class T>
bool LinkedList<T>::isEmpty(void) const
{
    return (size == 0);
}

/**
	@brief	初始化游标的位置
	@param	pos	从零计起的位置编号
	@note	pos 无限制
	当 pos 在 0 和 size 之间时，prevPtr 和 currPtr 正常指示;
	当 pos 为 0 时，prevPtr = NULL, currPtr = front;
	当 pos 为 size 时，prevPtr = rear, currPtr = NULL;
	当 pos 取其他值时，prevPtr = currPtr = NULL。
*/
template <class T>
void LinkedList<T>::reset(int pos)
{
    if (0 <= pos && pos <= size)
    {
        position = 0;
        prevPtr = NULL;
        currPtr = front;
        // 游标回到头结点，再逐步前移
        while (pos--)
            next();
    }
    else
    {
        position = pos;
        prevPtr = NULL;
        currPtr = NULL;
    }
}

/**
	@brief	使游标移动到下一个结点
	@note	允许游标移出链表
*/
template <class T>
void LinkedList<T>::next(void)
{
    position++;
    prevPtr = currPtr;

    if (currPtr != NULL)
        currPtr = currPtr->nextNode();
}

/**
	@brief	游标是否到了链尾
	@return	游标是否到了链尾
	游标“到了链尾”意即游标“超出了链表”，
	当游标所示的当前结点不存在时即判断到了链尾。
*/
template <class T>
bool LinkedList<T>::endOfList(void) const
{
    return (currPtr == NULL);
}

/**
	@brief	返回游标当前的位置
	@return	从零计起的位置编号
	@note	游标可以在链表之外
*/
template <class T>
int LinkedList<T>::currentPosition(void) const
{
    return position;
}

/**
	@brief	在表头插入结点
	@param	item	新结点的数据域
*/
template <class T>
void LinkedList<T>::insertFront(const T &item)
{
    front = newNode(item, front);

    if (isEmpty())
        rear = front;

    size++;
    reset(++position);
}

/**
	@brief	在表尾插入结点
	@param	item	新结点的数据域
*/
template <class T>
void LinkedList<T>::insertRear(const T &item)
{
    Node<T> *newNode = newNode(item);

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->insertAfter(newNode);
        rear = newNode;
    }

    size++;
    reset(position);
}

/**
	@brief	在当前结点之前插入结点
	@param	item	新结点的数据域
	@note	只考虑当前位置的结点存在的情况
*/
template <class T>
void LinkedList<T>::insertBefore(const T &item)
{
    if (currPtr != NULL)
    {
        Node<T> *newNode = getNode(item, currPtr);

        if (prevPtr != NULL)
            prevPtr->insertAfter(newNode);
        else
            front = prevPtr = newNode;

        size++;
        reset(++position);
    }
}

/**
	@brief	在当前结点之后插入结点
	@param	item	新结点的数据域
	@note	只考虑当前位置的结点存在的情况
*/
template <class T>
void LinkedList<T>::insertAfter(const T &item)
{
    if (currPtr != NULL)
    {
        Node<T> *newNode = newNode(item, currPtr->nextNode());
        currPtr->insertAfter(newNode);

        if (rear == currPtr)
            rear = newNode;

        size++;
    }
}

/**
	@brief	删除头结点
*/
template <class T>
T LinkedList<T>::deleteFront(void)
{
    if (isEmpty())
    {
        cerr << "List is empty, delete error." << endl;
        exit(1);
    }

    Node<T> *delNode = front;
    front = front->nextNode();

    if (--size == 0)
        rear = NULL;

    reset(--position);

    T item = delNode->data;
    freeNode(delNode);

    return item;
}

/**
	@brief	删除当前结点
	@note	只考虑当前位置的结点存在的情况
*/
template <class T>
void LinkedList<T>::deleteCurrent(void)
{
    if (currPtr != NULL)
    {
        if (front == currPtr)
            front = currPtr->nextNode();

        if (rear == currPtr)
            rear = prevPtr;

        if (prevPtr != NULL)
            prevPtr->deleteAfter();

        freeNode(currPtr);
        size--;
        reset(position);
    }
}

/**
	@brief	返回对当前结点成员数据的引用
	@return	当前结点数据域
*/
template <class T>
T &LinkedList<T>::data(void)
{
    if (currPtr == NULL)
    {
        cerr << "Current node is invalid." << endl;
        exit(1);
    }

    return currPtr->data;
}

/**
	@brief	返回对当前结点成员数据的常引用
	@return	当前结点数据域
*/
template <class T>
const T &LinkedList<T>::data(void) const
{
    if (currPtr == NULL)
    {
        cerr << "Current node is invalid." << endl;
        exit(1);
    }

    return currPtr->data;
}

/**
	@brief	清空链表：释放所有结点的内存空间。
	被析构函数和“operator =”调用
*/
template <class T>
void LinkedList<T>::clear(void)
{
    while (!isEmpty())
        deleteFront();
}

#endif // LINKEDLIST_H
