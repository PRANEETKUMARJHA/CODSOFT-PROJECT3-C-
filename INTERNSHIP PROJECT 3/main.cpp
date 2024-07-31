#include <iostream>

using namespace std;

const int SIZE=3;
char board[SIZE][SIZE]={{'1','2','3'},{'4','5','6'},{'7','8','9'} };
char currentPlayer='X';

void printBoard()
{
    cout<<"---------\n";
    for(int i=0;i<SIZE;++i)
    {
        cout<<"|";
    for(int j=0;j<SIZE;++j)
    {
        cout<<board[i][j]<<"|";
    }
    cout<<"\n---------\n";
}
}

bool checkwin()
{
    // check row and columns
    for(int i=0;i<SIZE;++i)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])return true;
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])return true;
    }
    //check diagonals
     if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])return true;
     if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])return true;
     return false;
}


bool checkdraw()
{
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j)
        if(board[i][j]!='X'&& board[i][j]!='0')return false;
    return true;
}

void switchplayer()
{
    currentPlayer=(currentPlayer=='X')?'0':'X';
}

void playgame()
{
    int choice;
    while(true)
    {
        printBoard();
        cout<<"Player"<<currentPlayer<<",enter your move(1-9):";
        cin>>choice;
        if(choice<1||choice>9)
        {
            cout<<"invalid move! try again . \n";
            continue;
        }
        int row=(choice-1)/SIZE;
        int col=(choice-1)%SIZE;

        if(board[row][col]=='X'||board[row][col]=='0')
        {
            cout<<"cell already taken !try again.  \n";
            continue;
        }

        board[row][col]=currentPlayer;
        if(checkwin())
        {
            printBoard();
            cout<<"player"<<currentPlayer<<"wins !\n";
            break;
        }
        if(checkdraw())
        {
            printBoard();
            cout<<"the game is a draw!\n";
            break;
        }
        switchplayer();
    }
}

int main()
{
    char playagain;
    do
    {
        //reset the board for a new game
        char newboard[SIZE][SIZE]={{'1','2','3'},{'4','5','6'},{'7','8','9'} };
        memcpy(board,newboard,SIZE*SIZE*sizeof(char));
        currentPlayer='X';

        playgame();

        cout<<"do you want to play again ?(y/n):";
        cin>>playagain;
    }while(playagain=='y'||playagain=='Y');

    return 0;

    }
