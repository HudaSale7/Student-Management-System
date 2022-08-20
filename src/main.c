#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "myFunctions.h"

int main () {
    while (1)
    {
    int userOption = menu();
    switch (userOption)
    {
    case 1:
        writeData();
        break;
    case 2:
        readData();
        break;
    case 3:
        showAll();
        break;
    case 4:
        modifyData();
        break;
    case 5:
        exit(1);
        break;
    default:
        break;
    }}
    getchar();
    system("pause");
    return 0;
}