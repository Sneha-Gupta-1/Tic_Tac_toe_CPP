#include<iostream>
using namespace std;

char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int choice;
char turn = 'X';
int row,column;
bool draw=false;


void Display_board()
{
    system("cls");

    cout<<"       <------ T i c - T a c - T o e ------>";
    cout<<endl<<endl;
    
    cout<<"                 Player 01: [X]"<<endl;
    cout<<"                 Player 02: [Y]"<<endl;
    cout<<endl<<endl;
    cout<<"     Enter the no where you want to enter your choice:\n";

    cout<<"        _________________________________\n";
    cout<<"       | _________  _________  _________ |\n";
    cout<<"       ||1        ||2        ||3        ||\n";
    cout<<"       ||    "<<board[0][0]<<"    ||    "<<board[0][1]<<"    ||    "<<board[0][2]<<"    ||\n";
    cout<<"       ||_________||_________||_________||\n";
    cout<<"       ||_________  _________  _________||\n";
    cout<<"       ||4        ||5        ||6        ||\n";
    cout<<"       ||    "<<board[1][0]<<"    ||    "<<board[1][1]<<"    ||    "<<board[1][2]<<"    ||\n";
    cout<<"       ||_________||_________||_________||\n";
    cout<<"       ||_________  _________  _________||\n";
    cout<<"       ||7        ||8        ||9        ||\n";
    cout<<"       ||    "<<board[2][0]<<"    ||    "<<board[2][1]<<"    ||    "<<board[2][2]<<"    ||\n";
    cout<<"       ||_________||_________||_________||\n";
    cout<<"       |_________________________________|\n";
    cout<<endl;

}

void Player_Turn()
{
    if(turn=='X')
    cout<<"              Player--1--[X] turn :";

    if(turn=='O')
    cout<<"              Player--2--[O] turn :";

    cin>>choice;
    switch(choice)
    {
        case 1:
            row=0;
            column=0;
            break;
        case 2:
            row=0;
            column=1;
            break;
        case 3:
            row=0;
            column=2;
            break;
        case 4:
            row=1;
            column=0;
            break;
        case 5:
            row=1;
            column=1;
            break;
        case 6:
            row=1;
            column=2;
            break;
        case 7:
            row=2;
            column=0;
            break;
        case 8:
            row=2;
            column=1;
            break;
        case 9:
            row=2;
            column=2;
            break;
        default:
            cout<<"              Invalid Choice!!!"; 
            cout<<endl;
            break;
    }

    if(turn =='X' && board[row][column]!='X' && board[row][column]!='O' )
    {
        board[row][column]='X';
        turn = 'O';
    }
    else if(turn =='O' && board[row][column]!='O' && board[row][column]!='X' )
    {
        board[row][column]='O';
        turn = 'X';
    }
    else
    {
        cout<<"              Box already filled!!!"<<endl<<"              Please try again\n";
        Player_Turn();
    }
    
    Display_board();


}

bool Game_Over()
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]&& board[i][0] !=' ')||
           (board[0][i] == board[1][i] && board[0][i] == board[2][i]&& board[0][i] !=' '))
           {
             return true;
           }
    }

    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] !=' ') || 
       (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] !=' '))
       {
        return true;
       }

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(board[i][j] !='X'&& board[i][j]!='O')
    return false;

    draw =true;
    return false;


}

int main()
{
    
    // Display_board();
    while(!Game_Over())
    {
        Display_board();
        Player_Turn();
    }
    
    
    if(turn == 'X' && draw == false)
    cout<<"              Player--2--[O] Wins!!" <<endl<< "              congratulations";

    else if(turn == 'O' && draw == false)
    cout<<"              Player--1--[X] Wins!!" <<endl<< "              congratulations";
        
    else
    cout<<"              Game Draw!! \n";

    return 0;

}