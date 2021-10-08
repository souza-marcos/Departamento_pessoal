#include <iostream>
#include <ctime>
using namespace std;

struct Project
{
};

struct ArrayList
{
    Project *data;
    int size;
};
ArrayList *create(int);
bool isEmpty(ArrayList *);
bool insertItem(ArrayList *, int, int);
void printList(ArrayList *);
int searchItem(ArrayList *, int);
bool deleteItem(ArrayList *, int);

struct Employee
{
    int id;
    string name;
    string address;
    int nDepends;
    ArrayList projects;
};

// typedef struct
// {
//     int key;
//     char name[20];
//     char cpf[12]; //Only numbers and \0
// } Employee;

struct Node
{
    Employee data;
    Node *next = NULL;
};

typedef struct
{
    Node *head;
    Node *last;
} LinkedList;

LinkedList *create();
void insert(Employee, LinkedList *);

int main()
{

    return 0;
}
// -----------------------   Others Functions   ---------------------

// ----------------------- Array List Functions ---------------------

ArrayList *create(int maxSize)
{
    ArrayList *list = new ArrayList;
    list->data = new int[maxSize];
    list->size = 0;
    return list;
}
bool isEmpty(ArrayList *list)
{
    return list->size == 0;
}
bool insertItem(ArrayList *list, int item, int tamMax)
{
    if (list->size >= tamMax)
    {
        return false;
    }
    list->data[list->size] = item;
    list->size++;
    return true;
}
void printList(ArrayList *list)
{
    cout << "\nList: ";
    for (int i = 0; i < list->size; i++)
    {
        cout << list->data[i] << " ";
    }
    cout << endl;
}
int searchItem(ArrayList *list, int val)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == val)
        {
            return i;
        }
    }
    return -1;
}
bool deleteItem(ArrayList *list, int val)
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

// ----------------------- Linked List Functions ---------------------
void insert(Employee e, LinkedList *list)
{
    if (list->head == NULL)
    {
        list->head = new Node; //Segmentation fault
        list->last = list->head;
        list->head->next = NULL;
        list->last->data = e;
        return;
    }
    list->last->next = new Node;
    list->last = list->last->next;
    list->last->next = NULL;
    list->last->data = e;
}
LinkedList *create()
{
    LinkedList *list = new LinkedList;
    return list;
}
