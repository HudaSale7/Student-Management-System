#include <stdio.h>
#include <string.h>

FILE *studentFile;

int menu () {
    int option;
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\t\t\t\t\t\t1. Add Student\n");
    printf("\t\t\t\t\t\t2. Individual View\n");
    printf("\t\t\t\t\t\t3. Show All Students\n");
    printf("\t\t\t\t\t\t4. Modify Student\n");
    printf("\t\t\t\t\t\t5. Exit\n\n");
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

typedef struct st
{
    char name[50];
    int id;
    char department[10];
} studentInfo;

studentInfo student;

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
    stringInput(student.name);
    printf("\n\t\tEnter The Id Number: ");
    scanf("%d", &student.id);
    printf("\n\t\tEnter department Name: ");
    stringInput(student.department);

    read_write_create();
    fseek(studentFile, 0, SEEK_END);
    fwrite(&student, sizeof(studentInfo), 1, studentFile);

    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tAdd another student?(y/n)?");
    scanf("%c", &ch);
    system("cls"); 
    if (ch == 'n') break;
    }

    fclose(studentFile);
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
    while (fread(&student, sizeof(studentInfo), 1, studentFile))
    {
        if (searchId == student.id)
        {
            flag = 0;
            printf("\n\n\t\t--> Student Name: %s" , student.name);
            printf("\n\t\t--> Id Number: %d" , student.id);
            printf("\n\t\t--> department Name: %s" , student.department);
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
    fclose(studentFile);
}

void showAll () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    read_write_create();
    rewind(studentFile);
    int flag = 1;
    while (fread(&student, sizeof(studentInfo), 1, studentFile))
    {
            flag = 0;
            printf("\n\n\t\t--> Student Name: %s" , student.name);
            printf("\n\t\t--> Id Number: %d" , student.id);
            printf("\n\t\t--> department Name: %s" , student.department);
        } 
    if (flag) {
            printf("\n\n\t\t\t\t\t\tNo Student is Added Yet");
        }
    fclose(studentFile);

    fflush(stdin);
    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tBack To Menu?(y)?");
    scanf("%c", &ch);
    system("cls"); 
    if (ch == 'y') break;
    }}


void modifyData () {
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
    while (fread(&student, sizeof(studentInfo), 1, studentFile))
    {
        if (searchId == student.id)
        {
            int option;
            flag = 0;
            printf("\n\n\t\t--> Student Name: %s" , student.name);
            printf("\n\t\t--> Id Number: %d" , student.id);
            printf("\n\t\t--> department Name: %s" , student.department);
            printf("\n\n\n\n\n\t\t\t\t\t\tModify: 1. Name");
            printf("\n\t\t\t\t\t\t\t2. Id");
            printf("\n\t\t\t\t\t\t\t3. department");
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t\tEnter Your Option --> ");
            scanf("%d", &option);
            system("cls");
                printf("\n\t\t\t\t\t\tStudent Management System \n\n");
                printf("\t\t\t\t\t---------------------------------------\n\n");
            switch (option)
            {
            case 1:
                printf("\n\n\t\t - New Student Name: ");
                stringInput(student.name);
                break;
            case 2:
                printf("\n\n\t\t - New ID: ");
                scanf("%d", &student.id);
                break;
            case 3:
                printf("\n\n\t\t - New department Name: ");
                stringInput(student.department);
                break;
            default:
                break;
            }
            printf("\n\n\t\t\t\t\t---------------------------------------\n\n");
            printf("\n\n\t\t--> Student Name: %s", student.name);
            printf("\n\t\t--> Id Number: %d", student.id);
            printf("\n\t\t--> department Name: %s", student.department);
            fseek(studentFile, -sizeof(studentInfo), SEEK_CUR);
            fwrite(&student, sizeof(studentInfo), 1, studentFile);
            break;
        } 
    }
    if (flag) {
            printf("\n\n\t\tStudent Not Found");
        }
    fclose(studentFile);
    fflush(stdin);
    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tModify another student?(y/n)?");
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

