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
void deleteProject();
void printAllEmployees();
void saveEmployees();
void getEmployees();
void deleteEmp();
void printPayment();
void selectEmployee();

int main()
{
    system("cls");
    employees = create<Employee>();
    getEmployees();
    mainMenu();
    cout << "VOLTE SEMPRE!!";
    saveEmployees();

    delete employees;

    return 0;
}
// ----------------------- Functions for Project and Employee ------------
/**
 * Print a project struct
 * @param Project Struct that will be printed
 */
void printProject(Project p)
{

    cout << "\tCODIGO: " << p.id
         << "\n\tNOME: " << p.name
         << "\n\tHORAS POR SEMANA: " << p.hoursPerWeek
         << endl
         << endl;
}

/**
 * Print a employee struct
 * @param Employee Struct that will be printed
 */
void printEmployee(Employee e)
{
    cout << "\nCODIGO: " << e.id
         << "\nNOME: " << e.name
         << "\nENDERECO: " << e.address
         << "\nNUMERO DE DEPENDENTES: " << e.nDepends
         << "\nPROJETOS:\n\n";
    if (e.projects->size == 0)
    {
        cout << " ---- Sem Projetos ----\n";
        return;
    }
    printList(e.projects, printProject);
}

/**
 * Compare Employee with a identifier
 * @param e Employee that will be compared
 * @param val Unique Identifier
 * @return True if compare method is true 
 */
bool compareEmployee(Employee e, int val)
{
    return e.id == val;
}

/**
 * Compare Project with a identifier
 * @param p Project that will be compared
 * @param val Unique Identifier
 * @return True if compare method is true 
 */
bool compareProject(Project p, int val)
{
    return (p.id == val);
}

/**
 * Print a payment card of employee
 * @param e Employee whose payment will be printed
 */
void printPayCheck(Employee e)
{
    cout << "\nCODIGO: " << e.id
         << "\nNOME: " << e.name
         << "\nTOTAL DE HORAS SEMANAIS: ";
    float sumHours = 0;
    for (int i = 0; i < e.projects->size; i++)
    {
        sumHours += e.projects->data[i].hoursPerWeek;
    }
    cout << sumHours;
    float salary = 45 * sumHours + 35 * e.nDepends;
    float inss = 0.085 * salary;
    float ir = 0.15 * salary;
    float freeSalary = salary - (inss + ir);
    cout << "\nSALARIO BRUTO: " << salary
         << "\nDESCONTO INSS: " << inss
         << "\nDESCONTO IR: " << ir
         << "\nSALARIO LIQUIDO: " << freeSalary << endl;
}

// ----------------------- Business Rule Functions ---------------------

/**
 * Handle the user choice about main menu 
 */
void mainMenu()
{
    int option;
    do
    {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "(1) - Inserir novo funcionario.\n";
        cout << "(2) - Inserir projeto a um funcionario.\n";
        cout << "(3) - Excluir projeto.\n";
        cout << "(4) - Excluir funcionarios sem projeto.\n";
        cout << "(5) - Consulta de um funcionario.\n";
        cout << "(6) - Imprimir contra-cheque\n";
        cout << "(7) - Imprimir todos os funcionarios.\n";
        cout << "(0) - Sair. \n";
        cout << "Sua Opcao: ";
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
            registerEmployee();
            break;

        case 2:
            insertProject();
            break;

        case 3:
            deleteProject();
            break;

        case 4:
            deleteEmp();
            break;

        case 5:
            selectEmployee();
            break;

        case 6:
            printPayment();
            break;

        case 7:
            printAllEmployees();
            break;
        default:
            break;
        }

    } while (option != 0);
}

/**
 * Register a project into a employee
 * @param *e Pointer of employee
 */
void cadProj(Employee *e)
{
    Project p;

    while (true)
    {
        cout << "Digite o codigo do projeto: ";
        cin >> p.id;
        if (searchItem(e->projects, p.id, compareProject) == -1)
        {
            break;
        }
        cout << "Codigo ja existente! Deseja digitar um codigo diferente? (s/n) ";
        char c;
        cin >> c;
        cin.ignore();
        if (c == 'n')
        {
            cout << "Nao foi possivel inserir o Projeto";
            cout << endl;
            system("pause");
            return;
        }
    }

    cout << "Digite o nome: ";
    cin.ignore();
    getLineConsole(p.name, 25);
    cout << "Digite as horas por semana para esse projeto: ";
    cin >> p.hoursPerWeek;

    cout << (insertItem<Project>(e->projects, p, MAXPROJ) == 1 ? "Inserido com sucesso\n" : "ERRO ao inserir\n");
}

/**
 * Register a employee 
 */
void registerEmployee()
{
    Employee e;
    cout << "INCLUSAO DE NOVO FUNCIONARIO\n";
    while (true)
    {
        cout << "Digite o codigo: ";
        cin >> e.id;
        if (searchItem(employees, e.id, compareEmployee) != NULL)
        {
            cout << "Codigo ja existente! Deseja digitar um codigo diferente? (s/n) ";
            char c;
            cin >> c;
            if (c == 'n')
            {
                cout << "Nao foi possivel inserir o Funcionario\n";
                return;
            }
            continue;
        }
        break;
    }
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
        if (e.projects->size == MAXPROJ)
        {
            cout << "\nMaximo de projetos por funcionario ja inseridos\n";
            system("pause");
            break;
        }
        cadProj(&e);
        cout << "\nInserir mais projetos para este funcionario? (s/n) ";
        cin >> nextProject;
    } while (nextProject != 'n');

    insertItem<Employee>(e, employees);
    cout << "Funcionario inserido com sucesso\n";
}
/**
 * Handle the main menu option of insert projects into employee 
 */
void insertProject()
{
    cout << "INCLUSAO DE PROJETO A FUNCIONARIO\n";
    cout << "Digite o codigo do funcionario: ";
    int id;
    cin >> id;
    Employee *e = &searchItem(employees, id, compareEmployee)->data;
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
        cout << "MAXIMO DE PROJETOS JA INSERIDOS\n";
        system("pause");
    }
}

/**
 * Print all employees
 */
void printAllEmployees()
{
    printList(employees, printEmployee);
    system("pause");
}

/**
 * Handle the main menu option of delete projects
 */
void deleteProject()
{
    cout << "EXCLUSAO DE PROJETO DO FUNCIONARIO\n";
    cout << "Digite o codigo do funcionario: ";
    int id;
    cin >> id;
    Employee *e = &searchItem(employees, id, compareEmployee)->data;
    if (e == NULL)
    {
        cout << "ERRO: O funcionario nao existe\n";
        system("pause");
        return;
    }
    cout << "FUNCIONARIO ENCONTRADO!\n";
    printEmployee(*e);

    cout << "\nDigite o codigo do projeto: ";
    int idP;
    cin >> idP;

    cout << endl
         << (deleteItem(e->projects, idP, compareProject) ? "Projeto excluido" : "Nao foi possivel excluir o projeto") << endl;
    system("pause");
}

/**
 * Handle the main menu option of delete employees without projects
 */
void deleteEmp()
{
    cout << "EXCLUSAO DE FUNCIONARIOS SEM PROJETOS\n";
    Node<Employee> *node = employees->head;

    int count = 0;
    while (node != NULL)
    {
        if (node->data.projects->size == 0)
        {
            if (deleteItem(employees, node))
            {
                count++;
            }
        }
        node = node->next;
    }
    cout << "Foram apagados " << count << " funcionarios.\n";
    system("pause");
}

/**
 * Handle the main menu option of print payment
 */
void printPayment()
{
    printList(employees, printPayCheck);
    system("pause");
}

/**
 * Handle the main menu option of select employees 
 */
void selectEmployee()
{
    cout << "Digite o codigo do funcionario: ";
    int id;
    cin >> id;
    Node<Employee> *node = searchItem(employees, id, compareEmployee);
    if (node == NULL)
    {
        cout << "\nERRO: O funcionario nao existe\n";
        system("pause");
        return;
    }
    Employee e = node->data;
    printEmployee(e);
    cout << endl;
    system("pause");
}

// ----------------------- File Operation Functions -----------------------

/**
 * Save the employees into a file "funcionarios.bin"
 */
void saveEmployees()
{
    ofstream oust;
    oust.open("funcionarios.bin", ofstream::out | ofstream::trunc);

    if (!oust.is_open() || oust.fail())
    {
        cout << "\n\nERRO AO SALVAR OS DADOS\n\n";
        return;
    }

    Node<Employee> *current = employees->head;
    while (current != NULL)
    {
        oust << current->data.id << "\n"
             << current->data.name << "\n"
             << current->data.address << "\n"
             << current->data.nDepends << "\n"
             << current->data.projects->size;

        Project p;
        for (int i = 0; i < current->data.projects->size; i++)
        {
            p = current->data.projects->data[i];
            oust << "\n"
                 << p.id << "\n"
                 << p.name << "\n"
                 << p.hoursPerWeek;
        }
        if (current->next != NULL)
        {
            oust << "\n";
        }
        current = current->next;
    }

    oust.close();
}

/**
 * Get the employees saved from file "funcionarios.bin"
 */
void getEmployees()
{
    ifstream ist;
    ist.open("funcionarios.bin");

    if (!ist.is_open() || ist.fail())
    {
        cout << "\n\nERRO AO ABRIR O ARQUIVO\n\n";
        return;
    }

    ist.get();
    while (!ist.eof())
    {
        ist.unget();
        Employee e;
        ist >> e.id;
        ist.ignore();
        ist.getline(e.name, 25, '\n');
        ist.getline(e.address, 45, '\n');
        ist >> e.nDepends;

        e.projects = create<Project>(5);
        int size;
        ist >> size;

        Project p;
        for (int i = 0; i < size; i++)
        {
            ist >> p.id;
            ist.ignore();
            ist.getline(p.name, 25, '\n');
            ist >> p.hoursPerWeek;
            clog << (insertItem(e.projects, p, MAXPROJ) ? "" : "\nERRO AO INSERIR PROJETO (getEmployees)\n");
        }
        insertItem(e, employees);
        ist.get();
    }

    ist.close();
}
