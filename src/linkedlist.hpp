template <typename TData>
struct Node;

template <typename TData>
struct LinkedList;

template <typename TData>
LinkedList<TData> *create();

template <typename TData>
void insertItem(TData, LinkedList<TData> *);

template <typename TData>
TData *searchItem(LinkedList<TData>, int);

template <typename TData>
void printList(LinkedList<TData> *list, void (*print)(TData));

template <typename TData>
bool deleteItem(LinkedList<TData> *list, Node<TData> *&node);

#include "linkedlist.cpp"
