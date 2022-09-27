#ifndef _MYLIST_H
#define _MYLIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T t;
    Node<T> *next;
};

template <typename T>
class MyList
{
public:
    MyList();
    ~MyList();
    int capacity();
    int clear();
    int length();
    int insert(T &t, int pos);
    int get(T &t, int pos);
    int del(T &t, int pos);

private:
    int m_capacity;
    int m_length;
    // 在链表中，建立一个带有头节点的链表
    Node<T> *m_head;
};

template <typename T>
MyList<T>::MyList()
{
    m_capacity = 0;
    m_length = 0;
    m_head = new Node<T>;
    m_head->next = nullptr;
}

template <typename T>
MyList<T>::~MyList()
{
    Node<T> *tmp;
    while (m_head)
    {
        tmp = m_head->next;
        delete m_head;
        m_head = tmp;
    }
}

template <typename T>
int MyList<T>::clear()
{
    return 0;
}

template <typename T>
int MyList<T>::length()
{
    return m_length;
}

template <typename T>
int MyList<T>::capacity()
{
    return m_capacity;
}

template <typename T>
int MyList<T>::insert(T &t, int pos)
{
    if (pos > m_length)
    {
        return -1;
    }
    Node<T> *current = m_head;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    Node<T> *tmp = new Node<T>;
    tmp->t = t;

    tmp->next = current->next;
    current->next = tmp;

    m_length++;
    return 0;
}

template <typename T>
int MyList<T>::get(T &t, int pos)
{
    if (pos > m_length)
    {
        return -1;
    }
    Node<T> *current = m_head;
    for (int i = 0; i <= pos; i++)
    {
        current = current->next;
    }
    t = current->t;
    return 0;
}

template <typename T>
int MyList<T>::del(T &t, int pos)
{
    if (pos > m_length)
    {
        return -1;
    }
    Node<T> *current = m_head;
    Node<T> *rmv = nullptr;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    rmv = current->next;
    if (rmv == nullptr)
    {
        return -1;
    }
    current->next = rmv->next;
    t = rmv->t;
    delete rmv;
    rmv = nullptr;

    m_length--;
    return 0;
}

#endif