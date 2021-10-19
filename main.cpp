#include <iostream>
#include <fstream>

#include "src/arraylist.hpp"
#include "src/linkedlist.hpp"
#include "src/tools.hpp"
#define MAXPROJ 5
using namespace std;

struct Project
{
    int id;
    char name[25];
    float hoursPerWeek;
};

struct Employee
{
    int id;
    char name[25];
    char address[45];
    int nDepends;
    ArrayList<Project> *projects;
};

LinkedList<Employee> *employees;

void mainMenu();
void registerEmployee();
void insertProject();
void printAllEmployees();

int main()
{

    cout << "BEM VINDO AO SISTEMA DE DEPARTAMENTO PESSOAL\n";
    employees = create<Employee>();

    mainMenu();
    cout << "VOLTE SEMPRE!!";

    delete employees;

    return 0;
}
// ----------------------- Functions for Project and Employee ------------

void printProject(Project p)
{
    cout << "CODIGO: " << p.id
         << "\nNOME: " << p.name
         << "\nHORAS POR SEMANA: " << p.hoursPerWeek
         << endl;
}

void printEmployee(Employee e)
{
    cout << "\nCODIGO: " << e.id
         << "\nNOME: " << e.name
         << "\nENDERECO: " << e.address
         << "\nNUMERO DE DEPENDENTES: " << e.nDepends
         << "\nPROJETOS:\n\n";
    printList(e.projects, printProject);
}

// ----------------------- Business Rule Functions ---------------------

void mainMenu()
{
    int option;
    do
    {
        cout << "MENU PRINCIPAL\n";
        cout << "(1) - Inserir novo funcionario.\n";
        cout << "(2) - Inserir projeto a um funcionario.\n";
        cout << "(3) - Imprimir todos os funcionarios.\n";
        cout << "(0) - Sair. \n";
        cout << "Sua Opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            registerEmployee();
            break;

        case 2:
            insertProject();
            break;

        case 3:
            printAllEmployees();
            break;

        default:
            break;
        }

    } while (option != 0);
}

void cadProj(Employee *e)
{
    Project p;
    cout << "Digite o codigo do projeto: ";
    cin >> p.id;
    cout << "Digite o nome: ";
    cin.ignore();
    getLineConsole(p.name, 25);
    cout << "Digite as horas por semana para esse projeto: ";
    cin >> p.hoursPerWeek;

    cout << (insertItem<Project>(e->projects, p, MAXPROJ) == 1) ? "Inserido com sucesso" : "ERRO ao inserir";
}

void registerEmployee()
{
    Employee e;
    cout << "INCLUSAO DE NOVO FUNCIONARIO\n";
    cout << "Digite o codigo: ";
    cin >> e.id;
    cout << "Digite o nome: ";
    cin.ignore();
    getLineConsole(e.name, 25);
    cout << "Digite o endereco: ";
    getLineConsole(e.address, 45);
    cout << "Digite a quantidade de dependentes: ";
    cin >> e.nDepends;
    cout << "PROJETOS\n";
    char nextProject;

    e.projects = create<Project>(MAXPROJ);

    do
    {
        cadProj(&e);
        cout << "\nInserir mais projetos para este funcionario? (s/n) ";
        cin >> nextProject;
    } while (nextProject != 'n');

    insertItem<Employee>(e, employees);
    cout << "Inserido com sucesso\n";
}

void insertProject()
{
    cout << "INCLUSAO DE PROJETO A FUNCIONARIO\n";
    cout << "Digite o codigo do funcionario: ";
    int id;
    cin >> id;
    Employee *e = &searchItem(employees, id)->data;
    if (e == NULL)
    {
        cout << "ERRO: O funcionario nao existe\n";
        system("pause");
        return;
    }
    cout << "FUNCIONARIO ENCONTRADO!\n";
    printEmployee(*e);

    char nextProject;
    while (e->projects->size < MAXPROJ && nextProject != 'n')
    {
        cadProj(e);
        cout << "\n\nInserir mais projetos para este funcionario? (s/n) ";
        cin >> nextProject;
    }

    if (e->projects->size == MAXPROJ)
    {
        cout << "MAXIMO DE PROJETOS JA INSERIDOS";
        system("pause");
    }
}

void printAllEmployees()
{
    printList(employees, printEmployee);
    system("pause");
}

// ----------------------- File Operation Functions -----------------------

void saveEmployees()
{
    ofstream oust;
    oust.open("funcionarios.bin", ofstream::out | ofstream::trunc);

    if(!oust.is_open() || oust.fail()){
        cout << "\n\nERRO AO SALVAR OS DADOS\n\n";
        return;
    }
    ///print I'm here 

}
void getEmployees(){

}
