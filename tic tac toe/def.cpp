#include<iostream>
#include "dec.h"
using namespace std;

//globally defined
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;   //0-9
string playerName[2];
string choice[1];

void introduction()
{
    cout<<"Press [Enter] to begin: ";
    getchar();  //haults the screen until pressing key
    cout<<"\n\n";

    cout<<"Enter Player 1 name:"<<endl;
    cin>>playerName[0];

    cout<<"Enter choice: X or O"<<endl;
    cin>>choice[0];

    while(choice[0] != "X" && choice[0] != "O")
    {
        cout<<"Please enter a valid choice between: X or O"<<endl;
        cin>>choice[0];
    }

    cout<<"Enter Player 2 name:"<<endl;
    cin>>playerName[1];

    cout<<"***************\n";
    cout<<"Tic-Tac-Toe\n";
    cout<<"***************\n";

    if(choice[0]=="X")
    {
        cout<<playerName[0]<<" - X\n";
        cout<<playerName[1]<<" - O\n";
    }
    else
    {
        cout<<playerName[0]<<" - O\n";
        cout<<playerName[1]<<" - X\n";
    }

    cout<<"\nThe  3x3 grid is shown below:\n\n";

    cout<<"       |       |       \n";
    cout<<"   1   |   2   |   3   \n";
    cout<<"_______|_______|_______\n";
    cout<<"       |       |       \n";
    cout<<"   4   |   5   |   6   \n";
    cout<<"_______|_______|_______\n";
    cout<<"       |       |       \n";
    cout<<"   7   |   8   |   9   \n";
    cout<<"       |       |       \n\n";

}

bool is_Winner_Util(string a, string b, string c)
{
    if(a==b && b==c && a != " ")
    {
        return true;
    }
    return false;
}

bool is_Winner()
{
    bool winner=false;

    //checking the rows
    if(is_Winner_Util(board[0], board[1], board[2]))
    {
        winner=true;
    }
    else if(is_Winner_Util(board[3], board[4], board[5]))
    {
        winner=true;
    }
    else if(is_Winner_Util(board[6], board[7], board[8]))
    {
        winner=true;
    }

    //checking the column
    else if(is_Winner_Util(board[0], board[3], board[6]))
    {
        winner=true;
    }
    else if(is_Winner_Util(board[1], board[4], board[7]))
    {
        winner=true;
    }
    else if(is_Winner_Util(board[2], board[5], board[8]))
    {
        winner=true;
    }

    //checking the diagonals
    else if(is_Winner_Util(board[0], board[4], board[8]))
    {
        winner=true;
    }
    else if(is_Winner_Util(board[2], board[4], board[6]))
    {
        winner=true;
    }

    return winner;
}

bool filled_up()
{
    bool filled=true;

    for(int i=0; i<9; i++)
    {
        if(board[i]==" ")
        {
            filled=false;
        }
    }

    return filled;
}

void draw()
{
    cout<<"       |       |       \n";
    cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<"   \n";
    cout<<"_______|_______|_______\n";
    cout<<"       |       |       \n";
    cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<"   \n";
    cout<<"_______|_______|_______\n";
    cout<<"       |       |       \n";
    cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<"   \n";
    cout<<"       |       |       \n\n";
}

void set_position()
{
    if(player==1){
        cout<<playerName[0]<<"'s turn (Enter: 1-9): ";
    }
    else
    {
        cout<<playerName[1]<<"'s turn (Enter: 1-9): ";
    }
    while(!(cin>>position))
    {
        cout<<"Please enter a valid number between 1-9"<<endl;
        cin.clear();    //flushing the buffer
        cin.ignore();
    }

    while(board[position-1]!=" ")
    {
        cout<<"Oops, that position is already filed\nTry again\n";
        cout<<"Player "<<player<<"'s turn (Enter: 1-9): ";
        cin>>position;
        cout<<"\n";
    }
}

void update_board()
{   
    if(choice[0]=="X")
    {
        if(player%2==1)     //switching between player 1 and 2
        {
            board[position-1]="X";
        }
        else
        {
            board[position-1]="O";
        }
    }
    else
    {
        if(player%2==1)     //switching between player 1 and 2
        {
            board[position-1]="O";
        }
        else
        {
            board[position-1]="X";
        }
    }
}

void change_player()
{
    if(player==1)
    {
        player++;
    }
    else{
        player--;
    }
}

void take_turn()
{
    while(!is_Winner() && !filled_up())
    {
        set_position();
        update_board();
        change_player();
        draw();
    }
}

void end_game()
{
    if(is_Winner() && player==1)
    {
        cout<<playerName[1]<<" is the winner!!"<<endl;
    }
    else if(is_Winner() && player==2)
    {
        cout<<playerName[0]<<" is the winner!!"<<endl;
    }
    else if(filled_up())
    {
        cout<<"It's a tie!!\n"<<endl;
    }
}