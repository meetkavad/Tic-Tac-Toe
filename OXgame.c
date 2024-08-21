#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>


char board[3][3];

char player1[20];
char player2[20];
char bin;

void playermove();
void player1move();
void player2move();
void compmove();
void printboard();
void resetboard();
char checkwinner();
int checkfreespaces();
void printwinner(char);
void printwinner2(char);
int players();


int main()
{
 int pl=players();
 if(pl==1)
 {

printf("you:'X'\ncomputer:'O'\n");
printf("how to fill matrix?\n");
printf(" 7 | 8 | 9 " );
printf("\n---|---|---\n");
printf(" 4 | 5 | 6 ");
printf("\n---|---|---\n");
printf(" 1 | 2 | 3 \n\n");

char fm;
printf("firstmove(O/X):\n");
for(int i =0; i<2; i++)
scanf("%c", &fm);


if(fm=='X' || fm=='x')
{
char winner =' ';
resetboard();

while(checkfreespaces()!=0 && winner==' ')
{
  printboard();

  playermove();
  winner = checkwinner();
  if(winner!= ' '|| checkfreespaces()==0)
  break;
  
  compmove();
  winner = checkwinner(); 
  if(winner!= ' '|| checkfreespaces()==0)
  break;

}
printboard();
printwinner(winner);

}

else if(fm=='O' || fm=='o')
{
char winner =' ';
resetboard();

while(checkfreespaces()!=0 && winner==' ')
{


compmove();
  winner = checkwinner();
  if(winner==' ')
  printboard();
  
  if(winner!= ' '|| checkfreespaces()==0)
  break;

  playermove();
  winner = checkwinner();
  if(winner!= ' '|| checkfreespaces()==0)
  break;
  
  

}
printboard();
printwinner(winner);

}

else 
printf("enter valid character:\n");
 }

 else if(pl==2)
 {
  
  printf("enter name (player 1):\n");
 scanf("%s", player1);
  printf("enter name(player 2):\n");
  scanf("%s",player2);

  printf("\n%s : O\n",player1);
  printf("%s : X\n",player2);
  printf("\nhow to fill matrix?\n");
printf(" 7 | 8 | 9 " );
printf("\n---|---|---\n");
printf(" 4 | 5 | 6 ");
printf("\n---|---|---\n");
printf(" 1 | 2 | 3 \n\n");

 printf("\n    TOSS TIME: ");
 printf("\n\n%s : heads",player1);
 printf("\n%s : tails \n\n",player2);
 
 printf("press enter to spin the coin : \n");
 for(int i =0 ;i<2;i++)
 scanf("%c", &bin);
 printf("Coin in the Air");
 for(int i=0 ;i<5;i++)
 {
   printf(".");
   Beep(0,400);
 }
 printf("\n\n");


 srand(time(0));
 int fm1 =rand()%2;
 
  if(fm1==0)
  {
    printf("Heads!!\n\n");
   char winner =' ';
   resetboard();

while(checkfreespaces()!=0 && winner==' ')
{
  printboard();

  player1move();
  printboard();
  winner = checkwinner();
  if(winner!= ' '|| checkfreespaces()==0)
  break;
  
  player2move();
  winner = checkwinner(); 
  if(winner!= ' '|| checkfreespaces()==0)
  break;

}
printboard();
printwinner2(winner);
}

else if(fm1=1)
  {
        printf("Tails!!\n\n");
   char winner =' ';
   resetboard();

while(checkfreespaces()!=0 && winner==' ')
{
  printboard();

  player2move();
  printboard();
  winner = checkwinner();
  if(winner!= ' '|| checkfreespaces()==0)
  break;
  
  player1move();
  winner = checkwinner(); 
  if(winner!= ' '|| checkfreespaces()==0)
  break;

}
printboard();
printwinner2(winner);
}

else 
printf("enter valid character:\n");
 
 
   


}

}

int players()

{
  int game;
  printf("\nselect game mode: \n\n1.Single player\n2.Two players\n");
  scanf("%d", &game);

  if(game==1)
  return 1;
  else if(game==2)
  return 2;
  else
  printf("select valid options.");
}

void playermove()
{ 
   int  x;
    int y;
    do{

    int n;
    printf("enter the spot:\n");
    scanf("%d",&n);
    
    switch(n){
     case 7: x=0;y=0;
              break;
     case 8: x=0;y=1;
               break;
     case 9: x=0;y=2;
              break;
     case 4: x=1;y=0;
             break;
     case 5: x=1;y=1;
               break;
     case 6: x=1;y=2;
              break;
     case 1: x=2;y=0;
              break;
     case 2: x=2;y=1;
                break;
     case 3: x=2;y=2; 
                break;      

    }

      if(  board[x][y]!=' ')
     printf("invalid move!!\n");
     else
     {
     board[x][y]='X';
     break;
     }
} while (board[x][y]!=' ');


    
}

void player1move()
{   int x;
    int y;
    do{

    int n;
    printf("%s:\n",player1);
    scanf("%d",&n);
    
    switch(n){
     case 7: x=0;y=0;
              break;
     case 8: x=0;y=1;
               break;
     case 9: x=0;y=2;
              break;
     case 4: x=1;y=0;
             break;
     case 5: x=1;y=1;
               break;
     case 6: x=1;y=2;
              break;
     case 1: x=2;y=0;
              break;
     case 2: x=2;y=1;
                break;
     case 3: x=2;y=2; 
                break;      

    }

      if(  board[x][y]!=' ')
     printf("invalid move!!\n");
     else
     {
     board[x][y]='O';
     break;
     }
} while (board[x][y]!=' ');
}

void player2move()
{   int x;
    int y;
    do{

    int n;
    printf("%s:\n",player2);
    scanf("%d",&n);
    
    switch(n){
     case 7: x=0;y=0;
              break;
     case 8: x=0;y=1;
               break;
     case 9: x=0;y=2;
              break;
     case 4: x=1;y=0;
             break;
     case 5: x=1;y=1;
               break;
     case 6: x=1;y=2;
              break;
     case 1: x=2;y=0;
              break;
     case 2: x=2;y=1;
                break;
     case 3: x=2;y=2; 
                break;      

    }

      if(  board[x][y]!=' ')
     printf("invalid move!!\n");
     else
     {
     board[x][y]='X';
     break;
     }
} while (board[x][y]!=' ');
}

void compmove()
{
  srand(time(0));
  int x;
  int y;

   if(checkfreespaces()>0)
  {
    do{
    x= rand()%3;
    y=rand()%3;
  }while(board[x][y]!=' ');

  board[x][y]='O';
  }


}

void printboard()
{



printf(" %c | %c | %c ", board[0][0], board[0][1],board[0][2] );
printf("\n---|---|---\n");
printf(" %c | %c | %c ", board[1][0], board[1][1],board[1][2] );
printf("\n---|---|---\n");
printf(" %c | %c | %c \n", board[2][0], board[2][1],board[2][2] );

}

void resetboard()
{
   for(int i =0;i<3;i++)
   {
    for(int j =0; j<3; j++)
    {
        board[i][j]=' ';
    }
   }
}

char checkwinner()
{
    for(int i =0; i<3;i++)
    {
    if(board[0][i] == board[1][i] && board[1][i]==board[2][i])
     return board[0][i];

      else if(board[i][0] == board[i][1] && board[i][1]==board[i][2])
     return board[i][0];

      else if(board[1][1] == board[2][2] && board[1][1]== board[0][0])
     return board[1][1];

      else if(board[0][2] == board[1][1] && board[1][1]== board[2][0])
     return board[0][2];

     
    }
    return ' ';
}

int checkfreespaces()
{
   int spaces =9;
   
    for(int i =0;i<3;i++)
   {
    for(int j =0; j<3; j++)
    {
        if(board[i][j]!=' ')
        spaces--;
    }
   }
   return spaces;
}

void printwinner(char a ){
    if(a=='X')
    printf("you won!\n");

     else if(a == 'O')
    printf("you lost!\n");

    else
     printf("game tied!\n");  
}

void printwinner2(char a )
{
   if(a=='X')
    printf("%s won!\n", player2);

     else if(a == 'O')
    printf("%s won!\n", player1);

    else
     printf("game tied!\n");

}