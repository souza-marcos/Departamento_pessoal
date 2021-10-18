#include <iostream>
using namespace std;

template <typename TData>
struct ArrayList
{
    TData *data;
    int size;
};

template <typename TData>
ArrayList<TData>* create(int maxSize)
{
    ArrayList<TData> *list = new ArrayList<TData>;
    list->data = new TData[maxSize];
    list->size = 0;
    return list;
}

template <typename TData>
bool isEmpty(ArrayList<TData> *list)
{
    return list->size == 0;
}

template <typename TData>
bool insertItem(ArrayList<TData> *list, TData item, int tamMax)
{
    if (list->size >= tamMax)
    {
        return false;
    }
    list->data[list->size] = item;
    list->size++;
    return true;
}

template <typename TData>
void printList(ArrayList<TData> *list)
{
    cout << "\nList: ";
    for (int i = 0; i < list->size; i++)
    {
        cout << list->data[i].id << " ";
    }
    cout << endl;
}

template <typename TData>
int searchItem(ArrayList<TData> *list, int val)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i].id == val)
        {
            return i;
        }
    }
    return -1;
}

template <typename TData>
bool deleteItem(ArrayList<TData> *list, int val)
{
    int first = searchItem(list, val);
    if (first < 0)
    {
        return false;
    }
    list->size--;
    for (int i = first; i < list->size; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    return true;
}