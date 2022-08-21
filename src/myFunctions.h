#include <stdio.h>
#include <string.h>

//file name

FILE *studentFile;

// show all option to the user
int menu () {
    int option;
    printf("\n\n\n\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\t\t\t\t\t\t1. Add Student\n");
    printf("\t\t\t\t\t\t2. Individual View\n");
    printf("\t\t\t\t\t\t3. Show All Students\n");
    printf("\t\t\t\t\t\t4. Modify Student\n");
    printf("\t\t\t\t\t\t5. Remove Student\n");
    printf("\t\t\t\t\t\t6. Exit\n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");
    printf("\t\t\t\t\t\tEnter Your Option --> ");
    scanf("%d", &option);
    system("cls"); 
    return option;
}

//create, read or write file 
void read_write_create () {
    //in case the file was exist
        studentFile = fopen("database.bin", "rb+"); 
    if (studentFile == NULL)
    {
        //if not then create new file
        studentFile = fopen("./database.bin", "wb+"); 
    }
}

//to read or write student data from the file
typedef struct st
{
    char name[50];
    int id;
    char department[10];
} studentInfo;

studentInfo student;

//function to take any string from user
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

//write student to the file
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

    //open file
    read_write_create();

    //move the pointer to last element and write before it
    fseek(studentFile, 0, SEEK_END);
    fwrite(&student, sizeof(studentInfo), 1, studentFile);

    //close file
    fclose(studentFile);

    //ask the user if he want to write again
    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tAdd another student?(y/n)?");
    scanf("%c", &ch);
    system("cls"); 
    if (ch == 'n') break;
    }
}

//read student data from the file
void readData () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");

    //ask the user to enter the student id which he is looking for
    int searchId;
    printf("\n\t\tEnter the ID: ");
    scanf("%d", &searchId);

    //open file
    read_write_create();

    //move the pointer to first element 
    rewind(studentFile);

    //to check if he find the student or not
    int flag = 1;

    //let's find our student !
    while (fread(&student, sizeof(studentInfo), 1, studentFile))
    {
        if (searchId == student.id) //if it match
        {
            flag = 0;
            printf("\n\n\t\t--> Student Name: %s" , student.name);
            printf("\n\t\t--> Id Number: %d" , student.id);
            printf("\n\t\t--> department Name: %s" , student.department);
            break;
        } 
    }
    //oops we cant find him !
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

//print all student with their data
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
    //in case of file is empty
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

//to edit data in particular student 
void modifyData () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");

    //same step for searching
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

            //ask the user which data he want to modify
            printf("\n\n\n\n\n\t\t\t\t\t\tModify: 1. Name");
            printf("\n\t\t\t\t\t\t\t2. Id");
            printf("\n\t\t\t\t\t\t\t3. department");
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t\tEnter Your Option --> ");
            scanf("%d", &option);
            system("cls");
                printf("\n\t\t\t\t\t\tStudent Management System \n\n");
                printf("\t\t\t\t\t---------------------------------------\n\n");

            //switch the option and modify the data in the file
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

            //print student after modifying his data
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

//remove student
void removeData () {
    while (1)
    {
    printf("\n\t\t\t\t\t\tStudent Management System \n\n");
    printf("\t\t\t\t\t---------------------------------------\n\n");

    //search for him first
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

            //make sure he want to remove
            char sure;
            fflush(stdin);
            printf("\n\n\n\n\n\t\t\t\t\t\tRemove Student?(y/n)?");
            scanf("%c", &sure);

            //in case he agree
            if (sure == 'y')
            {
                //create new file to copy all student
                FILE *copyFile;
                copyFile = fopen("./copy.bin", "wb+");

                //read all student from old file
                rewind(studentFile);
                while (fread(&student, sizeof(studentInfo), 1, studentFile)){

                    if (searchId == student.id) continue; //expect this one 
                    
                    //write the rest of student
                    fseek(copyFile, 0, SEEK_END);
                    fwrite(&student, sizeof(studentInfo), 1, copyFile);
                }
                fclose(studentFile);
                fclose(copyFile);

                //delete old file and rename the new file to tha same name of the old file
                remove("database.bin");
                rename("./copy.bin", "./database.bin");
                printf("\n\t\t\t\t\t\t\tDone !");
            }
        } 
    }

        if (flag) {
            printf("\n\n\t\tStudent Not Found");
        }
    fclose(studentFile);
    fflush(stdin);
    char ch;
    printf("\n\n\n\n\t\t\t\t\t\tRemove another student?(y/n)?");
    scanf("%c", &ch);
    system("cls"); 
    if (ch == 'n') break;
    }
    
}

























