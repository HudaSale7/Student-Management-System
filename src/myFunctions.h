#include <stdio.h>
#include <string.h>

FILE *studentFile;

int menu () {
    int option;
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\t\t\t\t\t\t1. Add Student\n");
    printf("\t\t\t\t\t\t2. Individual View\n");
    printf("\t\t\t\t\t\t3. Exit\n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\t\t\t\t\t\tEnter Your Option --> ");
    scanf("%d", &option);
    system("cls");
    return option;
}


void read_write_create () {
        studentFile = fopen("database.bin", "rb+");
    if (studentFile == NULL)
    {
        studentFile = fopen("./database.bin", "wb+");
    }
}

typedef struct student
{
    char name[50];
    int id;
    char department[10];
} studentInfo;

studentInfo st;

void stringInput (char str[]) {
    fflush(stdin);
    char ch = 0;
    int i = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch  == '\n') break;
        str[i++] = ch;
    }
    str[i] = '\0';
}

void writeData () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\n\t\tEnter Student Name: ");
    stringInput(st.name);
    printf("\n\t\tEnter The Id Number: ");
    scanf("%d", &st.id);
    printf("\n\t\tEnter department Name: ");
    stringInput(st.department);

    read_write_create();
    fseek(studentFile, 0, SEEK_END);
    fwrite(&st, sizeof(studentInfo), 1, studentFile);

    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tAdd another student?(y/n)?");
    scanf("%c", &ch);
    system("cls");
    if (ch == 'n') break;
    }
}

void readData () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    int searchId;
    printf("\n\t\tEnter the ID: ");
    scanf("%d", &searchId);

    read_write_create();
    rewind(studentFile);
    int flag = 1;
    while (fread(&st, sizeof(studentInfo), 1, studentFile))
    {
        if (searchId == st.id)
        {
            flag = 0;
            printf("\n\n\t\t--> Student Name: %s", st.name);
            printf("\n\t\t--> Id Number: %d", st.id);
            printf("\n\t\t--> department Name: %s", st.department);
            break;
        } 
    }
    if (flag) {
            printf("\n\n\t\tStudent Not Found");
        }
    
    fflush(stdin);
    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tRead another student?(y/n)?");
    scanf("%c", &ch);
    system("cls");
    if (ch == 'n') break;
    }
}




















struct SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};

void adjustWindowSize()
{
    struct SMALL_RECT test; 

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 100;
    coord.Y = 50;
    ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = 0;
    test.Top = 0;
    test.Right = coord.X-1;
    test.Bottom = coord.Y-1;

    SetConsoleWindowInfo(hStdout, ok, &test);

}

