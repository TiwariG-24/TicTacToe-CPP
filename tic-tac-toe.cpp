// library files
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class TicTacToe
{
   private:
 //two-dimensional arrays
    public:
   char board[3][3];
   int scorecounterX =0;
   int scorecounterO =0;
   int xlost = 0;
   int olost = 0;
   int drawcount=0;
   TicTacToe() {}

   //Organizing our board for the game
   void SetBoard()
   {
      int n = 1;
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ )
      {
         for ( j = 0; j < 3; j++ )
         {
            board[i][j] = '0' + n; //Cast the n to a character
            n++;
         }
      }
   } //End SetBoard

   //here we attempt to print (output) our board
   void PrintBoard()
   {
   		system("cls");
   		cout<<endl<<endl<<endl<<endl<<endl;
      int i = 0;
      int j = 0;
	cout<<"\t\t\t\t----------------"<<endl;
      for ( i = 0; i < 3; i++ )
      {
      	cout<<"\t\t\t\t";
         for ( j = 0; j < 3; j++ )
         {
            if ( j < 2 )                                      
            {
               cout <<" "<< board[i][j] << "  |  ";
            }
               else
               {
                  cout << board[i][j] << endl;
               }
         }
         cout<<"\t\t\t\t----------------"<<endl;
      }
      
   } //End Print Table

   //Control Player moves
   bool PlayerTurn(char num, char Player)
   {
      int i = 0;
      int j = 0;
      int k;
      bool WrongMove = true; //If true, the player has made a wrong move
      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         { //Mark square with X or O if WrongMove is not true
            if(board[i][j] == num) 
            { 
               board[i][j] = Player; //Assigns the space with the X or O, 
               WrongMove = false;    //depending on the board. 
            }
            
         }
      }
     return WrongMove;
   } //End Player Move


//checking for the winner, if any, finish the game. If not, cotinue or a draw
//in the next function (CheckDraw)
   bool CheckResult(char Player, bool GameOver)
   {
      for(int i = 0; i < 3; i++) //Increment i to check rows
      {
         if(board[i][0] == board[i][1] && board[i][1] == 
         board[i][2]) GameOver = true;
      }
      for(int i = 0; i < 3; i++) //Increment i to check column
      {
         if(board[0][i] == board[1][i] && board[1][i] == 
         board[2][i]) GameOver = true;
      }
      //Checking the Diagonals
      if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
      {
         GameOver = true;
      }
      if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
      {
         GameOver = true;
      }
       
      if(GameOver == true) 
      {
      	PrintBoard();
      	cout<<endl<<endl<<endl;
         cout << "\t\t\t"<<"Player " << Player << " wins!\n\n";
         cout <<"\t\t\t"<< "-----------------------" << endl;
         cout <<"\t\t\t"<< "|   CONGRATULATIONS " << Player << " |\n";
         cout << "\t\t\t"<<"-----------------------" << endl << endl;
         if(Player == 'X')
         {
             scorecounterX++;
             olost++;
         }
         else if(Player== 'O'){
             scorecounterO++;
             xlost++;
         }
         
         
      }
         return GameOver;
   } //End Check Winner
//Check the board to see if the match has come to a draw
   bool CheckDraw(bool GameOver)
   {
      int n = 1;
      int i = 0;
      int j = 0;
      int counter = 0;

      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         {
            //Check to see if the board is full
            if(board[i][j] == '0' + n) 
            { 
               counter++; 
            }
            n++;
         }
      }
      if( counter < 1 ) 
      {
      	PrintBoard();
         cout <<"\t\t\t"<< "No one won :(, keep playing :)!\n\n"; 
         GameOver = true;
             drawcount++;
      }
      
      return GameOver;
   }
   int scoredisplay(){
   	cout<<"\t\t\t Scoreboard:"<<endl;
   	cout<<"\t\t\t"<<"|-------------------------|"<<endl;
    cout<< "\t\t\t"<<"| player" << "  |  "<< "won" << "  |  " << "lost |"<<endl;
    cout<<"\t\t\t"<< "|   X   " << "  |  "<<" "<<scorecounterX<<" "<< "  |  " <<"  "<< xlost<<"  |"<<endl;
    cout<< "\t\t\t"<<"|   O   " << "  |  "<<" "<<scorecounterO<<" "<< "  |  " <<"  "<< olost<<"  |"<<endl;
    cout<<"\t\t\t"<<"|-------------------------|"<<endl;
    cout<<"\t\t\t"<<"| draw  " << "  |  "<<drawcount<<"            |"<<endl;
    cout<<"\t\t\t"<<"|-------------------------|"<<endl;
    }
};
class computer : public TicTacToe
{
    public:
 bool PlayerCompTurn(char num, char comp, char Player)
   {
      int i = 0;
      int j = 0;
      int k;
      bool WrongMove = true; //If true, the player has made a wrong move
      if(Player == 'X')
      {
         cout <<"\t\t\t"<< "\nPlayer \"" << Player << "\", it's your turn "<<endl;
          cout <<"Enter a tile number to mark "<< Player<<":";
		 cin >> num; 
         cout << "\n"; 
          for( i = 0; i < 3; i++ )
         {
            for( j = 0; j < 3; j++ )
            { //Mark square with X or O if WrongMove is not true
            if(board[i][j] == num) 
            { 
               board[i][j] = Player; //Assigns the space with the X or O, 
               WrongMove = false;    //depending on the board. 
            }
            
            }
         }
      }
      else{
          cout<<"computer is playing"<<endl;
          for( i = 0; i < 3; i++ )
         {
            for( j = 0; j < 3; j++ )
            { //Mark square with X or O if WrongMove is not true
            if(board[i][j] == comp) 
            { 
               board[i][j] = Player; //Assigns the space with the X or O, 
               WrongMove = false;    //depending on the board. 
            }
            
            }
         }
          
      }
     return WrongMove;
   } //End Player Move
};
int main()
{
    srand ( time(NULL) ); 
    bool done = false, GameOver  = false, done2=false;
    char Player   = 'O', num;
    int mode;
    char quit;
    char comp;
    bool invlidMove;
    cout<< "\t\t\t***********************************************************************"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
	cout<< "\t\t\t*                            WELCOME TO                                *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
	cout<< "\t\t\t*                            Tic-Tac-Toe                               *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
    cout<< "\t\t\t*                                                                      *"<<endl;
    cout<< "\t\t\t***********************************************************************"<<endl;
    cout<<endl<<endl;
    cout<< "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<< "\t\t\t~ Rules:                                                              ~"<<endl;
    cout<< "\t\t\t~     1. The game is played on a grid that's 3 squares by 3 squares.  ~"<<endl;
    cout<< "\t\t\t~     2. You are X, your friend (or the computer in this case) is O.  ~"<<endl;
    cout<< "\t\t\t~     3. Players take turns putting their marks in empty squares.     ~"<<endl;
    cout<< "\t\t\t~     4. The first player to get 3 of her marks in a row              ~"<<endl;
    cout<< "\t\t\t~        (up, down, across, or diagonally) is the winner.             ~"<<endl;
    cout<< "\t\t\t~     5. When all 9 squares are full, the game is over.               ~"<<endl;
    cout<< "\t\t\t~        If no player has 3 marks in a row, the game ends in a tie.   ~"<<endl;
    cout<< "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	cout<< "\t\t\t\t\t***************************"<<endl;
    cout<< "\t\t\t\t\t*                         *"<<endl;
	cout<< "\t\t\t\t\t*        1.Player         *"<<endl;
    cout<< "\t\t\t\t\t*                         *"<<endl;
    cout<< "\t\t\t\t\t*        2.Computer       *"<<endl;
    cout<< "\t\t\t\t\t*                         *"<<endl;
    cout<< "\t\t\t\t\t***************************"<<endl<<endl ;
    got:
    cout<< "\t\t\tChoose  your opponent:- ";
     cin>>mode;
	cout<<endl<<endl;    

if(mode == 1)
{
    cout <<"\t\t\t\t"<< "----------------"<< endl;
    TicTacToe myGame;
    myGame.SetBoard();

    do
    {
        
       if (invlidMove  == false){
        if( Player == 'X' ) 
        {
           Player = 'O';
        }
           else
           {
              Player = 'X';
           } 
       }
       else{
           cout<< "\t\t\t invlid input please play again"<<endl;
       }
    
		myGame.PrintBoard();
        cout << "\nPlayer \"" << Player << "\", it's your turn: "<<endl;
        cout <<"Enter a tile number to mark "<< Player<<":";
		cin >> num; 
        cout << "\n";

        invlidMove = myGame.PlayerTurn(num, Player);

        GameOver = myGame.CheckResult(Player, GameOver);
        if(GameOver == false)
        {
         GameOver = myGame.CheckDraw(GameOver);
        }
        //if game over, starting over
        
        if(GameOver == true) 
        {   
            cout<< "\t\t if you want to quit press 'Q' or if you don't then press 'N':  ";
            cin>>quit;
             cout<< endl <<endl;
            if(quit == 'n'|| quit == 'N')
            {
            myGame.SetBoard(); 
            GameOver = false;
            }
            else {
                
                myGame.scoredisplay();
            done = true;
            break;
            }
            
        }
        //system("CLS");
    } while(!done);
}   // ----------------copVSplayer-------
else if(mode == 2)
{
    
    computer myGame1;
    myGame1.SetBoard();
     do
    {
       comp= '1' + rand()%9;
       if (invlidMove  == false){
        if( Player == 'X' ) 
        {
           Player = 'O';
        }
           else
           {
              Player = 'X';
           } 
       }
       else{
           cout<< "\t\t\t invlid input please play again"<<endl;
       }
        
        myGame1.PrintBoard();
        

        invlidMove = myGame1.PlayerCompTurn(num,comp, Player);

        GameOver = myGame1.CheckResult(Player, GameOver);
 
        GameOver = myGame1.CheckDraw(GameOver);
        //if game over, starting over
        
        if(GameOver == true) 
        {   
       
	
            cout<< "\t\t if you want to quit press 'q' or if you don't press 'n'";
            cin>>quit;
            if(quit == 'n' || quit == 'N' ) {
            myGame1.SetBoard(); 
            GameOver = false;
            
            }
            else {
           	myGame1.scoredisplay();
            done2 = true;
            
            break;
            }
            
        }
    } while(!done2);
}
else{
    cout<<"\t\t\t invalid input Enter number 1 or 2"<<endl;
    goto got;
}
    return 0;
}




