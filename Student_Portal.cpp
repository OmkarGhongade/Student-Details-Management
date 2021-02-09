#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


//structure for storing the details


struct details{
    char name[100];
    char uname[100];
    char pass[100];
    int age;
    long long int pnumber;
    char branch[100];
    char div[100];
    char dob[100];
    int sem;
};

//Array of structure named student with maximum limit of 20.

struct details student[20];

//an integer named size of maintaining the number of students being admited in the class.

int size=0;




///All functions used in program.


void captcha();//for verifying captcha
void choicee();//for 1st menu
void login();//for loggin in to account
void newacc();//for creating new acccount
void list();//for printing list of students in classs
void exitt();//for exiting the program
void main_menu(int);//for printing the 2nd menu
void pdetails(int);//for printing the details og logged in students
void tt(int);//for printing time table
void sf(int);//for printing subject and faculty details
void change_uname(int );//for changing username
void change_pass(int);//for changing pasword








int main()
{
    captcha();
}

//Captcha Function For Human Verification.

void captcha()
{
    system("cls");
    int num,num1;
    srand(time(0));
    num = rand();
    printf("%d\n",num);
    printf("Enter The Captcha : ");
    scanf("%d",&num1);
    if(num==num1)
    {
        choicee();
    }
    else
    {
        printf("Enter Correct Captcha \n");
        captcha();
    }
}

//choicee function for letting the user what he want's to do.

void choicee()
{
    system("cls");
    int choice;
    printf("\n\t\t----------------------------MENU-------------------------\n\n\t\t1.Login\n\t\t2.New Account\n\t\t3.All Class Student List\n\t\t4.Exit\n\n\t\tNote : If Running Program For First Time Please Creat Multiple Accounts And Then Try Out\n\n\t\tEnter Your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        login();
        break;
        case 2:
        newacc();
        break;
        case 3:
        list();
        break;
        case 4:
        exitt();
        default:
        system("cls");
        printf("\t\tEnter The Correct Choice\n");
        choicee();
    }
}

//login function for loggin in to the created account.

void login()
{
    system("cls");
    int i;
    char username[100],password[100];
    int num,num1,flag=0;
    if(size==0)
    {
        printf("\n\t\tPlease Create An Account First.");
        printf("\n\t\tPress 1 to go Back To Menu : ");
        scanf("%d",&num);
        choicee();
    }
    printf("\n--------------------------------LOGIN-------------------------------\n");
    printf("\n\n\t\tEnter The User-Name : ");
    scanf("%s",username);
    printf("\n\t\tEnter The Password : ");
    scanf("%s",password);
    srand(time(0));
    num = rand();
    printf("\n\n\t\tCaptcha : %d",num);
    printf("\n\t\tEnter The Captcha : ");
    scanf("%d",&num1);
    for(i=0;i<size;i++)
    {
        if(strcmp(username,student[i].uname)==0  &&  strcmp(password,student[i].pass)==0  && num==num1)
        {
            main_menu(i);
        }
        else
        {
            flag=1;
        }
    }
    if(flag==1 || size==0)
    {
        printf("\n\t\tPlease Create An Account First.");
        printf("\n\t\tPress 1 to go Back To Menu : ");
        scanf("%d",&num);
        choicee();
    }
}

//newacc function for creating a new account and I personally suggest that if you really want the feel of the project then create minimum 10 accounts and the try out.It will be a Fun.

void newacc()
{
    int num;
    system("cls");
    if(size==20)
    {
        printf("\n\t\tClass is Full.\n\t\tYou Cannot Admit More Students To the Class.\n\t\tPlease Try With Other Features");
        system("cls");
        choicee();
    }
    else
    {
        printf("\n--------------------------------NEW LOGIN-------------------------------\n");
        printf("\n\n\t\tEnter The Name : ");
        scanf("%s",student[size].name);
        printf("\n\t\tEnter The User-Name : ");
        scanf("%s",student[size].uname);
        printf("\n\t\tEnter The Password : ");
        scanf("%s",student[size].pass);
        printf("\n\t\tEnter The Age : ");
        scanf("%d",&student[size].age);
        printf("\n\t\tEnter The Phone Number : ");
        scanf("%lld",&student[size].pnumber);
        printf("\n\t\tEnter The Branch : ");
        scanf("%s",student[size].branch);
        printf("\n\t\tEnter The Division : ");
        scanf("%s",student[size].div);
        printf("\n\t\tEnter The Date Of Birth : ");
        scanf("%s",student[size].dob);
        printf("\n\t\tEnter The Semester In Which You Are Studying : ");
        scanf("%d",&student[size].sem);
        size++;
        printf("\n\n\t\tStudent Is Registered Sucessfuly.....");
        printf("\n\t\tPress 1 to go Back To Menu : ");
        scanf("%d",&num);
        choicee();
    }
}

//list function for printing the list of al the students admited in the class.

void list()
{
    system("cls");
    int i,num;
    printf("-------------------All Students List--------------------");
    for(i=0;i<size;i++)
    {
        printf("\n\t\t%d.%s",i+1,student[i].name);
    }
    printf("\n\t\tPress 1 to go Back To Menu : ");
    scanf("%d",&num);
    choicee();
}

//exitt funtion for quiting the program. It will display the name of the contributers and the terminate the program.

void exitt()
{
    system("cls");
    printf("-----------Project Created By-----------");
    printf("\n\t1.Omkar Ghongade.");
    printf("\n\t2.Himaja Sree.\n");
    printf("----------------------------------------\n\n\n\n\n\n\n\n\n\n\n");
    exit(0);
}

//main_menu function is the function which is displayed after login.

void main_menu(int num)
{
    system("cls");
    int choices,a=num;
    system("cls");
    printf("\n\t\t----------------------------MAIN-MENU-------------------------");
    printf("\n\t\t1.Personal Details\n\t\t2.Time-Table\n\t\t3.Semester-Subjects And Faculties\n\t\t4.Change Username\n\t\t5.Change Password\n\t\t6.Log-Out");
    printf("\n\t\tEnter You Choice : ");
    scanf("%d",&choices);
    switch(choices)
    {
        case 1:
        pdetails(a);
        break;
        case 2:
        tt(a);
        break;
        case 3:
        sf(a);
        break;
        case 4:
        system("cls");
        change_uname(a);
        break;
        case 5:
        system("cls");
        change_pass(a);
        break;
        case 6:
        choicee();
        break;
        default :
        printf("\n\t\tEnter Correct Choice........");
        main_menu(a);
    }
}

void pdetails(int i)
{
    int num;
    system("cls");
    printf("\n--------------------------------Personal Details-------------------------------\n");
    printf("\n\n\t\tStudent Name : ");
    printf("%s",student[i].name);
    printf("\n\n\t\tStudent User-Name : ");
    printf("%s",student[i].uname);
    printf("\n\n\t\tStudent Password : ");
    printf("%s",student[i].pass);
    printf("\n\n\t\tStudent Age : ");
    printf("%d",student[i].age);
    printf("\n\n\t\tStudent Phone-Number : ");
    printf("%lld",student[i].pnumber);
    printf("\n\n\t\tStudent Studying Branch : ");
    printf("%s",student[i].branch);
    printf("\n\n\t\tStudent Studying Division : ");
    printf("%s",student[i].div);
    printf("\n\n\t\tStudent Date Of Birth : ");
    printf("%s",student[i].dob);
    printf("\n\n\t\tCurrent Semster : ");
    printf("%d",student[i].sem);
    printf("\n\n\t\tPress 1 to go Back To Menu : ");
    scanf("%d",&num);
    main_menu(i);
}

void tt(int i)
{
    system("cls");
    int num;
    printf("\n------------------------------ Time Table -------------------------------");
    printf("\n\n\t\t1. English - ");
    printf("\n\t\t\tWednesday 11:20 am to 12:10 pm.");
    printf("\n\t\t\tThursday 11:20 am to 12:10 pm.");
    printf("\n\n\t\t2.Chemistry - ");
    printf("\n\t\t\tMonday 09:00 am to 09:50 am.");
    printf("\n\t\t\tWednesday 02:00 pm to 02:50 pm.");
    printf("\n\n\t\t3. Maths - ");
    printf("\n\t\t\tMonday 02:00 pm to 03:30 pm.");
    printf("\n\t\t\tWednesday 09:00 am to 09:50 am.");
    printf("\n\n\t\t4. Biology - ");
    printf("\n\t\t\tMonday 11:20 am to 12:10 pm.");
    printf("\n\t\t\tTuesday 11:20 am to 12:10 pm.");
    printf("\n\n\t\t5. C Language - ");
    printf("\n\t\t\tTuesday 09:90 am to 09:50 am.");
    printf("\n\t\t\tThursday 02:20 pm to 03:50 pm.");
    printf("\n\n\t\t6. ISES - ");
    printf("\n\t\t\tWednesday 12:50 pm to 01:40 pm.");
    printf("\n\t\t\tFriday 11:20 am to 12:50 pm.");
    printf("\n\n\t\tPress 1 to go Back To Menu : ");
    scanf("%d",&num);
    main_menu(i);
}

void sf(int i)
{
    system("cls");
    int num;
    int a=i;
    printf("\n------------------------------ Subject & Faculty -------------------------------");
    printf("\n\t\t1.English     Prof. Srabani Basu.");
    printf("\n\t\t2.Maths       Prof. Saswata Adhikari.");
    printf("\n\t\t3.Chemistry   Pardha Saradi Maram.");
    printf("\n\t\t4.Bilology    Prof. Jayaseelan Murugaiyan.");
    printf("\n\t\t5.C Language  Prof. Riyaz");
    printf("\n\t\t6.CDC         Prof. Naresh Addapa.");
    printf("\n\n\t\tPress 1 to go Back To Menu : ");
    scanf("%d",&num);
    main_menu(i);
}

void change_uname(int i)
{
    char use1[100],use2[100],use3[100];
    int num;
    printf("\n------------------------------ Change Username -------------------------------");
    printf("\n\t\tEnter The Old Username : ");
    scanf("%s",use1);
    printf("\n\t\tEnter The New Username : ");
    scanf("%s",use2);
    printf("\n\t\tConfirm The Username : ");
    scanf("%s",use3);
    if(strcmp(use1,student[i].uname)==0 && strcmp(use2,use3)==0)
    {
        strcpy(student[i].uname,use3);
        printf("\n\n\t\tUsername Changed Sucessfully......");
        printf("\n\n\t\tPress 1 to go Back To Menu : ");
        scanf("%d",&num);
        main_menu(i);

    }
    else
    {
        system("cls");
        printf("\n\t\tThe Deatils Dosen't Match.....");
        change_uname(i);
    }
}

void change_pass(int i)
{
    
    char use1[100],use2[100],use3[100];
    int num;
    printf("\n------------------------------ Change Password -------------------------------");
    printf("\n\t\tEnter The Old Password : ");
    scanf("%s",use1);
    printf("\n\t\tEnter The New Password : ");
    scanf("%s",use2);
    printf("\n\t\tConfirm The Password : ");
    scanf("%s",use3);
    if(strcmp(use1,student[i].pass)==0 && strcmp(use2,use3)==0)
    {
        strcpy(student[i].pass,use3);
        printf("\n\n\t\tPassword Changed Sucessfully......");
        printf("\n\n\t\tPress 1 to go Back To Menu : ");
        scanf("%d",&num);
        main_menu(i);

    }
    else
    {
        system("cls");
        printf("\n\t\tThe Deatils Dosen't Match.....");
        change_pass(i);
    }
}