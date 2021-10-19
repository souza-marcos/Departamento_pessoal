#include <iostream>
#include <string.h>
void getLineConsole(char *c, int tam)
{
    std::string s;
    getline(std::cin, s);
    strcpy(c, s.c_str());
    c[tam - 1] = '\0';
}