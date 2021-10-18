#include <iostream>
#include <ctime>
#include "./src/arraylist.hpp"
#include "./src/linkedlist.hpp"
#include <vector>
using namespace std;

struct Project
{
    int id;
    string name;
    float hoursPerWeek;
};

struct Employee
{
    int id;
    string name;
    string address;
    int nDepends;
    ArrayList<Project> projects;
};

// typedef struct
// {
//     int key;
//     char name[20];
//     char cpf[12]; //Only numbers and \0
// } Employee;

void mainMenu();
void registerEmployee();
int main()
{

    cout << "BEM VINDO AO SISTEMA DE DEPARTAMENTO PESSOAL\n";
    //mainMenu();

    ArrayList<Project> *ps = create<Project>(5);

    ArrayList<int> nus = *create<int>(10);


    Project p;
    p.name = "Marcos";

    cout << "COnseguiu? " << (insertItem(ps, p, 5)) ? "Sim" : "nao";

    cout << "VOLTE SEMPRE!!";
    return 0;
}
// ----------------------- Business Rule Functions ---------------------

void mainMenu()
{
    int option;
    do
    {
        cout << "MENU PRINCIPAL\n";
        cout << "(1) - Inserir novo funcionario.\n";
        cout << "(0) - Sair. \n";
        cout << "Sua Opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            registerEmployee();
            break;

        default:
            break;
        }

    } while (option != 0);
}

void registerEmployee()
{
    Employee e;
    cout << "INCLUSAO DE NOVO FUNCIONARIO\n";
    cout << "Digite o codigo: ";
    cin >> e.id;
    cout << "Digite o nome: ";
    cin >> e.name;
    cout << "Digite o endereco: ";
    cin >> e.address;
    cout << "Digite a quantidade de dependentes: ";
    cin >> e.nDepends;
    cout << "PROJETOS\n";
    char nextProject;
    do
    {
        Project p;
        cout << "Digite o codigo do projeto: ";
        cin >> p.id;
        cout << "Digite o nome: ";
        cin >> p.name;
        cout << "Digite as horas por semana para esse projeto: ";
        cin >> p.hoursPerWeek;
        cout << "\nExiste mais projetos para este funcionario? (s/n) ";
        cin >> nextProject;
    } while (nextProject != 'n');
}
