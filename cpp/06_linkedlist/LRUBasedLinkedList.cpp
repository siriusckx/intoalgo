typedef int DataType;

class SNode
{
public:
    DataType data;
    SNode *next;
};

class SList
{
    public:
        SList();
        SList(int MaxSize);
        virtual ~SList();

        //头部插入节点
        void insertElemAtBegin(DataType x); 

        //查找x,存在则返回1,不存在则返回0
        bool findElem(DataType x);

        //删除尾节点
        void deleteElemAtEnd();

        //删除指定节点，如果存在则删除，返回1，如果不存在，则删除失败返回0
        bool deleteElem(DataType x);

        //查看链表是否为空，1表示不为空，0表示为空
        bool isEmpty();

        //查看链表是否满，1表示不满，0表示满
        bool isFull();

        void printAll();

        //针对此应用的优化，查找，返回指定元素的前一个节点的指针
        void * findElemOptim(DataType x);

        //针对此应用的优化，删除
        void deleteElemOptim(void *snode);

    private:
        int MaxSize;  //链表可以存放最大的数据
        int length;   //链表的长度
        SNode *head;  //指向头节点
};

#include <iostream>
using namespace std;

//初始化单链表
SList::SList()
{
    head = new SNode; //申请头节点
    head->next = NULL;
    this->MaxSize = 0;
    this->length = 0;
}

SList::SList(int MaxSize)
{
    head = new SNode; //申请头节点
    head->next = NULL;
    this->MaxSize = MaxSize;
    this->length = 0;
}

//销毁单链表，要把开辟的空间都释放，然后再销毁
SList::~SList()
{
    SNode *ptr, *temp;
    ptr = head;
    while (NULL != ptr->next)
    {
        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    delete head; //删除头节点
    this->head = NULL;
    this->length = 0;
}

//链表头部插入节点
void SList::insertElemAtBegin(DataType x)
{
    SNode *ptr = new SNode;
    ptr->data = x;

    ptr->next = head->next;
    head->next = ptr;

    this->length++;
}

//查找x，存在则返回1，不存在则返回0
bool SList::findElem(DataType x)
{
    SNode *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        if(ptr->next->data == x)
        {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}


