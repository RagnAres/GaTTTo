#include <iostream>

using namespace std;

void printM(char list[9]);
bool checkWin(char list[9]);
char selectSymb();
char positions(char pos, char list[9], char mark);

int main()
{
  int tie = 0;
  char ans1, ans2;
  char symb1, symb2;
  char ticTactoe[9] = {'1','2','3','4','5','6','7','8','9'};
  int r = 0;
  char taken[9] = {};
  bool p1Win, p2Win;
  int winner = 0;
  
  cout << "----------------------------" << endl;
  cout << " *** TIC TAC TOE *** " << endl;
  cout << " This is a Tic Tac Toe game for 2 players" << endl;
  cout << " Player 1 will go first, then Player 2 " << endl;
  cout << " Player 1, select your symbol " << endl;
  cout << " 1 for 'X', 2 for 'O' " << endl;  
  cout << "----------------------------" << endl;

  // Here Player 1 selects symbol, and player 2 will be playing as the remaining symbol
  symb1 = selectSymb();
  if (symb1 == 'X')
     symb2 = 'O';
  else
    symb2 = 'X';
  
  cout << "Player 1 has chosen '" << symb1 << "' " << endl;
  cout << "Player 2 will be playing as '" << symb2 << "' " << endl;
  cout << "----------------------------" << endl;
  cout << "Game will start!" << endl;
  cout << " --Enter 1 to 9-- " << endl;
  printM(ticTactoe);

 

  while(!checkWin(ticTactoe)){
    
    cout << "Make your move Player 1: ";
    cin >> ans1;
    
    for(int i = 0; i < 8; i++){
      while(taken[i] == ans1){
          cout << "This position is already taken! Please choose an available position: ";
          cin >> ans1;
          i = 0;}}
    taken[r] = ans1;
    r++;
    tie++;
   
    positions(ans1, ticTactoe, symb1);
    cout << "----------------------------" << endl;
    printM(ticTactoe);
    cout << "----------------------------" << endl;
    if(checkWin(ticTactoe))
    {  
       winner = 1;
       p1Win = true;     
       break;
    }
    if(tie == 9)
      break;

    cout << "Make your move, Player 2: ";
    cin >> ans2;
    for(int i = 0; i <= 8; i++){
      while(taken[i] == ans2){
          cout << "This position is already taken! Please choose an available position: ";
          cin >> ans2;
          i = 0;}}
    taken[r] = ans2;
    r++;
    tie++;
    positions(ans2, ticTactoe, symb2);
    cout << "----------------------------" << endl;
    printM(ticTactoe);
    cout << "----------------------------" << endl;
    if(checkWin(ticTactoe))
    {  
       winner = 2;     
       p2Win = true;   
       break;
    }
    
  }
  cout << endl;
  cout << "----------------------------" << endl;
  printM(ticTactoe);    
  cout << "----------------------------" << endl;
  if(p1Win || p2Win)
    cout << "Player " << winner << " Wins!" << endl;
  if(tie == 9 && (!checkWin(ticTactoe)))
    cout << "It's a tie!" << endl;

  cout << "Moves" << endl;
  for(int i = 0; i < 9; i++)
    cout << taken[i];
  cout << endl;
  cout << " *** Thank You for Playing! ***" << endl;
  
  cout << endl;
  return 0;
}
// Prints the matrix, which is the "game board"
void printM(char list[9])
{ 
   cout << "     |     |    " << endl;
   cout << "  " << list[0] << "  |  " << list[1] << "  |  " << list[2] << "  " << endl;
   cout << "-----------------" << endl;
   cout << "  " << list[3] << "  |  " << list[4] << "  |  " << list[5] << "  " << endl;
   cout << "-----------------" << endl;
   cout << "  " << list[6] << "  |  " << list[7] << "  |  " << list[8] << "  " << endl;
   cout << "     |     |    " << endl;    
}
// Places the X or O mark in the selected position
char positions(char posL, char list[9], char mark)
{
  for (int i = 0; i < 9; i++)
    if(list[i] == posL)
       return list[i] = mark;
}
// Ensures Player 1 selects X or 0
char selectSymb()
{
    int num;
    char symb1;
    cin >> num;
    if (num == 1){
       return symb1 = 'X';}
    else if(num == 2){
       return symb1 = 'O';}
    else{
     cout << "Please enter 1 for 'X' or 2 for 'O' only" << endl;
     selectSymb();}
}
bool checkWin(char list[9])
{
  if(list[0] == list[1] && list[0] == list[2] || list[0] == list[3] && list[0] == list[6] || list[2] == list[5] && list[2] == list[8]
     || list[8] == list[7] && list[8] == list[6] || list[4] == list[0] && list[4] == list[8] || list[4] == list[2] && list[4] == list[6]
     || list[4] == list[3] && list[4] == list[5] || list[4] == list[1] && list[4] == list[7])
       return true;
  else
       return false;
}
