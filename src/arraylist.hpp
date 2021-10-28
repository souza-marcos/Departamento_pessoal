#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template <typename TData>
struct ArrayList;

template <typename TData>
ArrayList<TData> *create(int maxSize);

template <typename TData>
bool isEmpty(ArrayList<TData> *list);

template <typename TData>
bool insertItem(ArrayList<TData> *list, TData item, int tamMax);

template <typename TData>
void printList(ArrayList<TData> *list, void (*print)(TData));

template <typename TData>
int searchItem(ArrayList<TData> *list, int val, bool (*compare)(TData, int));

template <typename TData>
bool deleteItem(ArrayList<TData> *list, int val, bool (*compare)(TData, int));

#include "arraylist.cpp"
#endif