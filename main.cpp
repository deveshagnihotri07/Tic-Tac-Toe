#include <iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
using namespace std;

int PLAYER=1,p1won=0,p2won=0;
char arr[]={'1','2','3','4','5','6','7','8','9'};
string player1="Player 1",player2="Player 2";
char player,mark,Continue,choice;
int tie=0,yo=0;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void colourchange(int temp)
{
    if(arr[temp]=='X')
   {
	 SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
       cout<<arr[temp];
	SetConsoleTextAttribute(h,15|FOREGROUND_INTENSITY);
}
	else if(arr[temp]=='0')
	    {
	     SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			cout<<arr[temp];
        SetConsoleTextAttribute(h,15|FOREGROUND_INTENSITY);
		  }
	else
		 cout<<arr[temp];
}

void display()
{
    system("cls");
    cout<<"\t\t\t\t\t\t  WELCOME...\n\t\t\t\t\t\tTic Tac Toe\n\n\n";
    cout<<"\t\t\t                 |            |                                 =============================== \n";
    cout<<"\t\t\t            ";colourchange(0);cout<<"    |     ";colourchange(1);cout<<"      |     ";colourchange(2);cout<<"  \t\t\t\t|| "<<"\t   POINTS:  \t     ||\n";
    cout<<"\t\t\t        ---------|------------|------------\t\t\t||---------------------------||\n";
    cout<<"\t\t\t            ";colourchange(3);cout<<"    |     ";colourchange(4);cout<<"      |     ";colourchange(5);cout<<"  \t\t\t\t||";
    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);cout<<" '0' ";SetConsoleTextAttribute(h,15|FOREGROUND_INTENSITY);cout<<player1<<" :  "<<p1won<<"  \t     ||\n";
    cout<<"\t\t\t        ---------|------------|------------\t\t\t||     \t\t\t     ||\n";
    cout<<"\t\t\t            ";colourchange(6);cout<<"    |     ";colourchange(7);cout<<"      |     ";colourchange(8);cout<<"  \t\t\t\t||";
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);cout<<" 'X' ";SetConsoleTextAttribute(h,15|FOREGROUND_INTENSITY);cout<<player2<<" :  "<<p2won<<"  \t     || \n";
    cout<<"\t\t\t                 |            |                                 =============================== \n";
}


int check()
{
    if(arr[0]==arr[4]&&arr[4]==arr[8])
        return 0;
    else if(arr[2]==arr[4]&&arr[4]==arr[6])
        return 0;
    else if(arr[0]==arr[3]&&arr[3]==arr[6])
        return 0;
    else if(arr[1]==arr[4]&&arr[4]==arr[7])
        return 0;
    else if(arr[2]==arr[5]&&arr[5]==arr[8])
        return 0;
    else if(arr[0]==arr[1]&&arr[1]==arr[2])
        return 0;
    else if(arr[3]==arr[4]&&arr[4]==arr[5])
        return 0;
    else if(arr[6]==arr[7]&&arr[7]==arr[8])
        return 0;

    else if(arr[0]!='1'&&arr[1]!='2'&&arr[2]!='3'&&arr[3]!='4'&&arr[4]!='5'&&arr[5]!='6'&&arr[6]!='7'&&arr[7]!='8'&&arr[8]!='9')
        {
            system("cls");
            display();
            cout<<"\n\n";
            cout<<"\n\n\t\t\t\t\t"<<"Game Over \nGame Result Tie";
            Beep(1000,1000);
            tie=1;
            return 0;
        }

    else
       return 1;
}

void input()
{
    mark=((PLAYER%2==0)? 'X' : '0');

    if(choice=='1'||choice==1)
        arr[0]=mark;
    else if(choice=='2'||choice==2)
        arr[1]=mark;
    else if(choice=='3'||choice==3)
        arr[2]=mark;
    else if(choice=='4'||choice==4)
        arr[3]=mark;
    else if(choice=='5'||choice==5)
        arr[4]=mark;
    else if(choice=='6'||choice==6)
        arr[5]=mark;
    else if(choice=='7'||choice==7)
        arr[6]=mark;
    else if(choice=='8'||choice==8)
        arr[7]=mark;
    else if(choice=='9'||choice==9)
        arr[8]=mark;

     if(PLAYER==1)
            PLAYER=0;
     else
            PLAYER=1;
}
void start()
{
    cout<<"\n\n";
    cout<<"=======================================================================================================================";
    cout<<"\n\n\t\t\t\t\t"<<"Enter Name of 1st player:";
    cin>>player1;
    cout<<"\n\n\n \t\t\t\t\t"<<"Enter name of 2nd player:";
    cin>>player2;
    cout<<"\n";
}

void delay(unsigned int ms)
{
    clock_t goal=ms+clock();
    while(goal>clock())
    {
    }
}
int inputcheck(int temp)     // arg char type ki aai hai ab int mai catch kr rhe hai toh check() shi se nhi kr ra kaam -_- a=49
{
	temp=temp-48;
        if(arr[temp-1]=='X'||arr[temp-1]=='0')
        {
            display();
            cout<<"\t\tWRONG INPUT (-_-) ENTER AGAIN\n\n\t\tSelect one Option again \n";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"WAIT LOADING...";
            SetConsoleTextAttribute(h, 15|FOREGROUND_INTENSITY);
            Beep(500,900);
            delay(200);
            Beep(500,900);
            delay(200);
            Beep(500,900);
            return 1;
        }
        else
            return 0;
}

int random_player()
{
    srand(time(0));
    int t=rand()%2;
    return t;
}
int main()
{
    display();
    if(yo==0)                                                // taaki sirf pehi baaf chle ye....
    {
        start();
    }
    PLAYER=random_player();
    while(check())                                           //pehle check kreg //input leega // check krega ki same place p pehle se toh ni hai kuch //if not toh input
    {
        display();
        if(PLAYER==1)
        {
            cout<<"\n\n";
            cout<<"=======================================================================================================================";
            cout<<"\n\n \t\t\t\t\t\t"<<player1<<"'s"<<" turn\n SELECT ONE OPTION:\n";
        }
        else
        {
            cout<<"\n\n";
            cout<<"=======================================================================================================================";
            cout<<"\n\n\t\t\t\t\t\t"<<player2<<"'s"<<" turn\n SELECT ONE OPTION:\n";
        }
        //cin>>choice;
        choice=_getch();
        fflush(stdin);
        if(choice=='1'||choice=='2'||choice=='3'||choice=='4'||choice=='5'||choice=='6'||choice=='7'||choice=='8'||choice=='9')
        {

            int input_check_ret=inputcheck(choice);
            if(input_check_ret==1)
            {        }
            else
            {
                input();
            }
        }
        else
        {
            cout<<"\t\tWRONG INPUT (-_-) ENTER AGAIN\n\n\t\tSelect one Option again \n";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"WAIT LOADING...";
            SetConsoleTextAttribute(h, 15|FOREGROUND_INTENSITY);
            Beep(500,900);
            delay(200);
            Beep(500,900);
            delay(200);
            Beep(500,900);
        }
    }
    if(PLAYER==1)                              // input function me player change hoo gya hooga toh wapis usi player p laane k liye kyunki while ki cindition fail hoo gyi hai
            PLAYER=0;
     else
            PLAYER=1;

    if(tie==1)
    {
        // tie hoo gya;
    }
    else                                   // player ki value 1 toh pehla wala jita hai nhi toh doosre wala kyunki while fail hoo gya hai
    {
        if(PLAYER==1)
          {
              display();
                cout<<"\n\n";
                cout<<"\t\t\t\t\t"<<player1<<" WON\n";
              Beep(500,500);
              p1won++;

          }
        else
        {
            display();
              cout<<"\n\n";
              cout<<"\t\t\t\t\t"<<player2<<" WON\n";
              Beep(500,500);
            p2won++;
        }
    }
    cout<<"\n\n";
    cout<<"=======================================================================================================================";
    cout<<"\n\n\t\t\tDO you want to continue with this game ?....\n";
    cout<<"\n\t\t\tPRESS 'Y' for YES and 'N' for NO...";
    cin>>Continue;
    if(Continue=='y'||Continue=='Y')
    {
        char ch='1';
        for(int m=0;m<9;m++)
        {
            arr[m]=ch;
            ch++;
        }
        yo++;
        main();
    }
    else if(Continue=='n'||Continue=='N')
    {
        system("cls");
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\tTHANKS FOR PLAYING....\n";
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\tHAVE A NICE DAY...";
    }
    else
    {
        system("cls");
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t\tSORRY WRONG INPUT\n\n";
            Beep(500,900);
            delay(200);
            Beep(500,900);
            delay(200);
            Beep(500,900);
    }
}
