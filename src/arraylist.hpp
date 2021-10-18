template <typename TData>
struct ArrayList;

template <typename TData>
ArrayList<TData> *create(int);

template <typename TData>
bool isEmpty(ArrayList<TData> *);

template <typename TData>
bool insertItem(ArrayList<TData> *, TData, int);

template <typename TData>
void printList(ArrayList<TData> *);

template <typename TData>
int searchItem(ArrayList<TData> *, TData);

template <typename TData>
bool deleteItem(ArrayList<TData> *, TData);

#include "arraylist.cpp"
