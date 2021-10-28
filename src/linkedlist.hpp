#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename TData>
struct Node;

template <typename TData>
struct LinkedList;

template <typename TData>
LinkedList<TData> *create();

template <typename TData>
void insertItem(TData e, LinkedList<TData> *list);

template <typename TData>
bool isEmpty(LinkedList<TData> *list);

template <typename TData>
Node<TData> *searchItem(LinkedList<TData> *list, int val, bool (*compare)(TData, int));

template <typename TData>
void printList(LinkedList<TData> *list, void (*print)(TData));

template <typename TData>
bool deleteItem(LinkedList<TData> *list, Node<TData> *&node);

#include "linkedlist.cpp"
#endif