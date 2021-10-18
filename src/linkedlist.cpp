#include <iostream>

template <typename TData>
struct Node
{
    TData data;
    Node<TData> *next = NULL;
};

template <typename TData>
struct LinkedList
{
    Node<TData> *head;
    Node<TData> *last;
};

template <typename TData>
void insert(TData e, LinkedList<TData> *list)
{
    if (list->head == NULL)
    {
        list->head = new Node<TData>; //Segmentation fault
        list->last = list->head;
        list->head->next = NULL;
        list->last->data = e;
        return;
    }
    list->last->next = new Node<TData>;
    list->last = list->last->next;
    list->last->next = NULL;
    list->last->data = e;
}
template <typename TData>
LinkedList<TData> *create()
{
    LinkedList<TData> *list = new LinkedList<TData>;
    return list;
}
