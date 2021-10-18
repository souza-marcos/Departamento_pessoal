template <typename TData>
struct Node;

template <typename TData>
struct LinkedList;

template <typename TData>
LinkedList<TData> *create();

template <typename TData>
void insert(TData, LinkedList<TData> *);


#include "linkedlist.cpp"
