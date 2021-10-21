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
LinkedList<TData> *create()
{
    LinkedList<TData> *list = new LinkedList<TData>;
    return list;
}

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
bool isEmpty(LinkedList<TData> *list)
{
    return (list->head == NULL);
}

template <typename TData>
Node<TData> *searchItem(LinkedList<TData> *list, int val, bool (*compare)(TData, int))
{
    if (isEmpty(list))
    {
        return NULL;
    }
    Node<TData> *current = list->head;

    do
    {
        if (compare(current->data, val))
        {
            return current;
        }
        current = current->next;
    } while (current != NULL);
    return NULL;
}

template <typename TData>
void printList(LinkedList<TData> *list, void (*print)(TData))
{
    Node<TData> *current = list->head;
    while (current != NULL)
    {
        print(current->data);
        current = current->next;
    }
    cout << endl;
}

template <typename TData>
bool deleteItem(LinkedList<TData> *list, Node<TData> *&node)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->next == NULL) // The last position should be the before item || It looks like I will have to iterate the linkedlist
    {

        Node<TData> *&it = list->head; //*&
        while (it != NULL)
        {
            if (it->next == node)
            {
                //delete (it->next); // tambem
                it->next = NULL;
                list->last = it;
                break;
            }
            it = it->next;
        }
        //delete it; //tambem
        //delete node;
        //node = NULL;
    }
    else
    {
        Node<TData> *nextNode = node->next;
        node->data = nextNode->data;
        node->next = nextNode->next;
        //node = nextNode;
        if (node->next == NULL)
        {
            list->last = node;
        }
        delete nextNode;
    }

    return true;
}

/**
template <typename TData> 
void unAlloc(LinkedList<TData> *list){

}**/