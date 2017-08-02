#include <iostream>

using namespace std;

void printM(char matX[7][11]);
bool checkWin(char matX[7][11]);
char selectSymb();
char positions(char pos, char matX[7][11], char mark);
int  takenList(int num);

int main()
{
  int tie = 0;
  char ans1, ans2;
  char symb1, symb2;
  char newmatrix[7][11] = {' ', ' ',' ', '|', ' ', ' ',' ','|',' ', ' ',' ',
                           ' ', '1',' ', '|', ' ', '2',' ','|',' ', '3',' ',
                           '-', '-','-', '|', '-', '-','-','|','-', '-','-',
                           ' ', '4',' ', '|', ' ', '5',' ','|',' ', '6',' ',
                           '-', '-','-', '|', '-', '-','-','|','-', '-','-',
                           ' ', '7',' ', '|', ' ', '8',' ','|',' ', '9',' ',
                           ' ', ' ',' ', '|', ' ', ' ',' ','|',' ', ' ',' '};
   

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
  printM(newmatrix);

  int r = 0;
  bool isTaken;
  char taken[9] = {};
  char nans1;

  while(!checkWin(newmatrix)){
    
    cout << "Make your move Player, 1" << endl;
    cin >> ans1;
    
    for(int i = 0; i < 8; i++){
      while(taken[i] == ans1){
          cout << "This position is already taken! Please choose an available position: ";
          cin >> ans1;
          i = 0;}}
    taken[r] = ans1;
    r++;
    tie++;
   
    positions(ans1, newmatrix, symb1);
    cout << "----------------------------" << endl;
    printM(newmatrix);
    cout << "----------------------------" << endl;
    if(checkWin(newmatrix))
    {       
       cout << "----------------------------" << endl;
       printM(newmatrix);
       cout << "----------------------------" << endl;
       cout << " *** Player 1 Wins! ***" << endl;
       break;
    }
    if(tie == 9)
      break;

    cout << "Make your move, Player 2" << endl;
    cin >> ans2;
    for(int i = 0; i <= 8; i++){
      while(taken[i] == ans2){
          cout << "This position is already taken! Please choose an available position: ";
          cin >> ans2;
          i = 0;}}
    taken[r] = ans2;
    r++;
    tie++;
    positions(ans2, newmatrix, symb2);
    cout << "----------------------------" << endl;
    printM(newmatrix);
    cout << "----------------------------" << endl;
    if(checkWin(newmatrix))
    {       
       cout << "----------------------------" << endl;
       printM(newmatrix);
       cout << "----------------------------" << endl;
       cout << " *** Player 2 Wins! ***" << endl;      
       break;
    }
    
  }
  if(tie == 9 && (!checkWin(newmatrix)))
   cout << "It's a tie!" << endl;
  cout << "Moves" << endl;
  for(int i = 0; i < 9; i++)
    cout << taken[i];
    

  
  cout << endl;
  cout << "----------------------------" << endl;
  printM(newmatrix);    
  cout << "----------------------------" << endl;
  cout << " *** Thank You for Playing! ***" << endl;
  
  cout << endl;
  return 0;

}
// Prints the matrix, which is the "game board"
void printM(char matX[7][11])
{ 
   for(int i = 0; i < 7; i++)
    {
     for(int u = 0; u < 11; u++)
     {
        cout << matX[i][u];
     }
     cout << endl;
    }
}
// Places the X or O mark in the selected position
char positions(char posM, char matX[7][11], char mark)
{ 
    char posN;
    for(int i = 0; i < 7; i++)
     for(int u = 0; u < 11; u++){
        if(matX[i][u] == posM)
        return matX[i][u] = mark;}
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
bool checkWin(char matX[7][11])
{
   if((matX[1][1] == matX[1][5] && matX[1][1] == matX[1][9]) || (matX[1][1] == matX[3][1] && matX[1][1] == matX[5][1])
       || (matX[3][5] == matX[1][1] && matX[3][5] == matX[5][9]) || (matX[3][5] == matX[1][9] && matX[3][5] == matX[5][1])
       || (matX[5][9] == matX[5][5] && matX[5][9] == matX[5][1]) || (matX[5][9] == matX[3][9] && matX[5][9] == matX[1][9])
       || (matX[3][5] == matX[1][5] && matX[3][5] == matX[5][5]) || (matX[3][5] == matX[3][1] && matX[3][5] == matX[3][9]))
       return true;
   else
       return false;
}
