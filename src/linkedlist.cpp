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
    Node<TData> *head = NULL;
    Node<TData> *last = NULL;
};

template <typename TData>
void insertItem(TData e, LinkedList<TData> *list)
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

template <typename TData>
bool isEmpty(LinkedList<TData> *list)
{
    return (list->head == NULL);
}

template <typename TData>
Node<TData> *searchItem(LinkedList<TData> *list, int val)
{
    if (isEmpty(list))
    {
        return NULL;
    }
    Node<TData> *current = list->head;

    do
    {
        if (current->data.id == val)
        {
            return current;
        }
        current = current->next;
    } while (current->next != NULL);
    return NULL;
}

template <typename TData>
void printList(LinkedList<TData> *list, void (*print)(TData))
{
    Node<TData> *current = list->head;
    do
    {
        print(current->data);
        current = current->next;
    } while (current != NULL);
    cout << endl;
}