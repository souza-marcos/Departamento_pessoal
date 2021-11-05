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
        list->head = new Node<TData>; 
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
    if (node == list->head)
    {
        list->head = node->next;
        if (node->next == NULL)
        {
            list->last = list->head;
        }
    }
    else
    {
        Node<TData> *prev = list->head;
        while (prev->next != node)
        {
            prev = prev->next;
        }
        prev->next = node->next;
        if (node->next == NULL)
        {
            list->last = prev;
        }
    }
    delete node; 
    return true;
}