// Copyright (c) 2019, Matthew Chalifoux.

#include <iostream>
#include <cassert>
using namespace std;

template<typename E>
struct Node
{
    // CONSTRUCTOR
    Node(E data1) : data(data1), next(0) {}
    E data;
    Node<E> *next;
};

template<typename E>
class Stack{
public:
    // CONSTRUCTOR
    Stack();
    void Push(E item);
    E Pop();
    bool Empty();
    E Top();
private:
    Node<E> *head;
};

template<typename E>
class Queue{
public:
    // CONSTRUCTPR
    Queue();
    // COPY CONSTRUCTOR
    Queue(const Queue &h);
    // ASSIGNMENT CONSTRUCTOR
    Queue & operator =(const Queue & h);
    void Push(E item);
    E Pop();
    bool Empty();
    E Top();
private:
    Node<E> *head;
    Node<E> *tail;
};

int main()
{
    Stack<int> test;

    Queue<int> test2;

    for(int i = 0; i < 10; ++i){
        test.Push(i);
    }
    while(!test.Empty()){
        cout << test.Pop() << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < 10; ++i){
        test2.Push(i);
    }
    while(!test2.Empty()){
        cout << test2.Pop() << " ";
    }


    return 0;
}

template<typename E>
E Stack<E>::Top()
{
    if(head == NULL)
    {
        return true;
    }
    else if(head != NULL)
    {
        return false;
    }
}

template<typename E>
bool Stack<E>::Empty()
{
    if(head == NULL)
    {
        return true;
    }
    else if(head != NULL)
    {
        return false;
    }
}

template<typename E>
Stack<E>::Stack()
{
    head = NULL;
}

template<typename E>
E Stack<E>::Pop()
{
    Node<E> *pnt;
    pnt = head;
    E sub;
    if(head == NULL)
    {}
    else if(head != NULL)
    {
        sub = head->data;
        head = head->next;
        delete pnt;
    }
    return sub;
}

template<typename E>
void Stack<E>::Push(E item)
{
    Node<E> *insert = new Node<E>(item);
    if(head == NULL)
    {
        head = insert;
    }
    else if(head != NULL)
    {
        insert->next = head;
        head = insert;
    }
}

template<typename E>
bool Queue<E>::Empty()
{
    if(head == NULL)
    {
        return true;
    }
    else if(head != NULL)
    {
        return false;
    }
}

template<typename E>
E Queue<E>::Top()
{
    assert(Empty() != true);

    if(Empty() != true)
    {
        return head->data;
    }
}

template<typename E>
E Queue<E>::Pop()
{
    assert(Empty() != true);
    Node<E> *pnt;
    pnt = head;
    E sub;
    if(head != NULL)
    {
        sub = head->data;
        head = head->next;
        delete pnt;
        return sub;
    }
}

template<typename E>
void Queue<E>::Push(E item)
{
    Node<E> *insert = new Node<E>(item);
    if(head == NULL)
    {
        head = insert;
        tail = insert;
    }
    else if(head != NULL)
    {
        tail->next = insert;
        tail = insert;
    }
}
template<typename E>
Queue<E> &Queue<E>::operator =(const Queue & a)
{
    Queue<E> test;
    E sub;
    Node<E> *i, *ipt;
    i = new Node<E>(sub);
    i->data = a.head->data;
    i->next = a.head->next;
    ipt = i;

    while(ipt != NULL)
    {
        test.Push(ipt->data);
        ipt = ipt->next;
    }

    head = test.head;
}

template<typename E>
Queue<E>::Queue(const Queue &a)
{
    Queue<E> test;
    E sub;
    Node<E> *i, *ipt;
    i = new Node<E>(sub);
    i->data = a.head->data;
    i->next = a.head->next;
    ipt = i;

    while(ipt != NULL)
    {
        test.Push(ipt->data);
        ipt = ipt->next;
    }

    head = test.head;
}

template<typename E>
Queue<E>::Queue()
{
    head = NULL;
    tail = NULL;
}
