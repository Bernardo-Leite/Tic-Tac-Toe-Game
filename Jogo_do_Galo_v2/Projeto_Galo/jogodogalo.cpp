#include <cstdlib>
#include <iostream>
#include <iomanip>
#include<time.h>
#include <windows.h>
#include "jogodogalo.h"
#include <string>

#define DIM 3
#define ESPACO ' '
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

//============================================================================================



//============================================================================================




CTabuleiro::~CTabuleiro(){}
//============================================================================================
void CTabuleiro :: mostraMatriz(char matriz[DIM][DIM]){
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            cout<<" "<<matriz[i][j]<<" "<<((j==DIM-1)? ESPACO : '\xBA');
        }
        if(i!=DIM-1)cout<<"\n\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCE\xCD\xCD\xCD";
        cout<<"\n";
    }
}
//============================================================================================

 CTabuleiro:: CTabuleiro (char matriz[DIM][DIM]){

    for(int i = 0;i<DIM;i++){
        for(int j=0;j<DIM;j++)
            matriz[i][j]=ESPACO;

    }

}
//============================================================================================
 void CTabuleiro :: resetMatriz(char matriz[DIM][DIM]){
                cout<<"\n";
     for(int i = 0;i<DIM;i++){
        for(int j=0;j<DIM;j++)
             matriz[i][j]=ESPACO;
     }
 }
//============================================================================================


void CTabuleiro :: NivelElementar(char matriz[DIM][DIM], int linha, int coluna, bool jogador){

    cout <<endl;

    if(jogador == true){
        SetConsoleTextAttribute(h,10);
        matriz[linha][coluna] ='X';

    }else{
        SetConsoleTextAttribute(h,12);
        matriz[linha][coluna] = 'O';
    }
         //SetConsoleTextAttribute(h,15);
}
//============================================================================================
void CTabuleiro :: NivelBasico(char matriz[DIM][DIM], int linha, int coluna, bool jogador){

    cout <<endl;
    int l,c;

    if(jogador == true){
        SetConsoleTextAttribute(h,10);
        matriz[linha][coluna] ='X';

    }else{
         SetConsoleTextAttribute(h,12);
        if(matriz[1][0]=='O' && matriz[1][1]=='O'&& matriz[1][2]==ESPACO){
            matriz[1][2]='O';
        }else  if(matriz[2][0]=='O' && matriz[2][1]=='O'&& matriz[2][2]==ESPACO){
            matriz[2][2]='O';
        }else if(matriz[0][1]=='O' && matriz[0][2]=='O'&& matriz[0][0]==ESPACO){
            matriz[0][0]='O';
        }else	if(matriz[1][1]=='O' && matriz[1][2]=='O'&& matriz[1][0]==ESPACO){
            matriz[1][0]='O';
        }else if(matriz[2][1]=='O' && matriz[2][2]=='O'&& matriz[2][0]==ESPACO){
            matriz[2][0]='O';

        }else	if(matriz[0][0]=='O' && matriz[1][0]=='O'&& matriz[2][0]==ESPACO){
            matriz[2][0]='O';
        }else	if(matriz[0][1]=='O' && matriz[1][1]=='O'&& matriz[2][1]==ESPACO){
            matriz[2][1]='O';
        }else	if(matriz[0][2]=='O' && matriz[1][2]=='O'&& matriz[2][2]==ESPACO){
            matriz[2][2]='O';

        }else	if(matriz[0][0]=='O' && matriz[0][2]=='O'&& matriz[0][1]==ESPACO){
            matriz[0][1]='O';
        }else	if(matriz[1][0]=='O' && matriz[1][2]=='O'&& matriz[1][1]==ESPACO){
            matriz[1][1]='O';
        }else	if(matriz[2][0]=='O' && matriz[2][2]=='O'&& matriz[2][1]==ESPACO){
            matriz[2][1]='O';

        }else	if(matriz[0][0]=='O' && matriz[1][1]=='O'&& matriz[2][2]==ESPACO){
            matriz[2][2]='O';
        }else	if(matriz[2][0]=='O' && matriz[1][1]=='O'&& matriz[0][2]==ESPACO){
            matriz[0][2]='O';

        }else	if(matriz[0][2]=='O' && matriz[1][1]=='O'&& matriz[2][0]==ESPACO){
            matriz[2][0]='O';
        }else	if(matriz[2][2]=='O' && matriz[1][1]=='O'&& matriz[0][0]==ESPACO){
            matriz[0][0]='O';

        }else	if(matriz[2][0]=='O' && matriz[1][0]=='O'&& matriz[0][0]==ESPACO){
            matriz[0][0]='O';
        }else	if(matriz[2][1]=='O' && matriz[1][1]=='O'&& matriz[0][1]==ESPACO){
            matriz[0][1]='O';
        }else	if(matriz[2][2]=='O' && matriz[1][2]=='O'&& matriz[0][2]==ESPACO){
            matriz[0][2]='O';

        }else	if(matriz[0][0]=='O' && matriz[2][2]=='O'&& matriz[1][1]==ESPACO){
            matriz[1][1]='O';
        }else	if(matriz[0][2]=='O' && matriz[2][0]=='O'&& matriz[1][1]==ESPACO){
            matriz[1][1]='O';

        }else	if(matriz[0][0]=='O' && matriz[2][0]=='O'&& matriz[1][0]==ESPACO){
            matriz[1][0]='O';
        }else	if(matriz[0][1]=='O' && matriz[2][1]=='O'&& matriz[1][1]==ESPACO){
            matriz[1][1]='O';
        }else	if(matriz[0][2]=='O' && matriz[2][2]=='O'&& matriz[1][2]==ESPACO){
            matriz[1][2]='O';
        }else if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]==ESPACO){
            matriz[0][2]='O';
        }
        else {
               do{

       l = (rand()% DIM);
       c = (rand()% DIM);
   }while(matriz[l][c] != ESPACO);
   matriz[l][c] = 'O';
        }
           // SetConsoleTextAttribute(h,15);
    }
}
//============================================================================================
void CTabuleiro :: NivelMedio(char matriz[DIM][DIM], int linha, int coluna, bool jogador){

    int n,l,c;

    bool X=false;
    srand((time(NULL)));
    cout <<endl;

    if(jogador == true){
        SetConsoleTextAttribute(h,10);
        matriz[linha][coluna] ='X';


              }
             else {

                SetConsoleTextAttribute(h,12);

                if(matriz[1][0]=='O' && matriz[1][1]=='O'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';
                }else  if(matriz[2][0]=='O' && matriz[2][1]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else if(matriz[0][1]=='O' && matriz[0][2]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[1][1]=='O' && matriz[1][2]=='O'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else if(matriz[2][1]=='O' && matriz[2][2]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';

                }else	if(matriz[0][0]=='O' && matriz[1][0]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[0][1]=='O' && matriz[1][1]=='O'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[1][2]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';

                }else	if(matriz[0][0]=='O' && matriz[0][2]=='O'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[1][0]=='O' && matriz[1][2]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[2][0]=='O' && matriz[2][2]=='O'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';

                }else	if(matriz[0][0]=='O' && matriz[1][1]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else	if(matriz[2][0]=='O' && matriz[1][1]=='O'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][2]=='O' && matriz[1][1]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[2][2]=='O' && matriz[1][1]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';

                }else	if(matriz[2][0]=='O' && matriz[1][0]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[2][1]=='O' && matriz[1][1]=='O'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[2][2]=='O' && matriz[1][2]=='O'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][0]=='O' && matriz[2][2]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[2][0]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';

                }else	if(matriz[0][0]=='O' && matriz[2][0]=='O'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else	if(matriz[0][1]=='O' && matriz[2][1]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[2][2]=='O'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }

               else if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';}

                else if(matriz[1][0]=='X' && matriz[1][1]=='X'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else  if(matriz[2][0]=='X' && matriz[2][1]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else if(matriz[0][1]=='X' && matriz[0][2]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[1][1]=='X' && matriz[1][2]=='X'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else if(matriz[2][1]=='X' && matriz[2][2]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';

                }else	if(matriz[0][0]=='X' && matriz[1][0]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[0][1]=='X' && matriz[1][1]=='X'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[1][2]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';

                }else	if(matriz[0][0]=='X' && matriz[0][2]=='X'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[1][0]=='X' && matriz[1][2]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[2][0]=='X' && matriz[2][2]=='X'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';

                }else	if(matriz[0][0]=='X' && matriz[1][1]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else	if(matriz[2][0]=='X' && matriz[1][1]=='X'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][2]=='X' && matriz[1][1]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[2][2]=='X' && matriz[1][1]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';

                }else	if(matriz[2][0]=='X' && matriz[1][0]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[2][1]=='X' && matriz[1][1]=='X'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[2][2]=='X' && matriz[1][2]=='X'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][0]=='X' && matriz[2][2]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[2][0]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';

                }else	if(matriz[0][0]=='X' && matriz[2][0]=='X'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else	if(matriz[0][1]=='X' && matriz[2][1]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[2][2]=='X'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]==ESPACO){
                                matriz[0][2]='O';
                 }else {
                    do{
                            l = (rand()% DIM);
                            c = (rand()% DIM);
                        }while(matriz[linha][coluna] != ESPACO);
                        matriz[linha][coluna] = 'O';
        }
    }
           //  SetConsoleTextAttribute(h,15);
}


//============================================================================================
void CTabuleiro :: NivelDestruidor(char matriz[DIM][DIM], int linha, int coluna, bool jogador,int jogada){

    int n;

    bool X=false,P=false;
    srand((time(NULL)));
    cout <<endl;

    if(jogador == true){
        SetConsoleTextAttribute(h,10);
        matriz[linha][coluna] ='X';


    }
    else {
        SetConsoleTextAttribute(h,12);
        if(matriz[1][1]==ESPACO){
            matriz[1][1]='O';
        }else{
            if(jogada == 2){

                while(X==false)
                {
                    n=rand()%4;

                    if(n==0){
                        if(matriz[0][0]=='X')
                        {
                            X=false;
                        }
                        else{
                            matriz[0][0]='O';
                            X=true;
                        }
                    }
                    if(n==1){
                        if(matriz[0][2]=='X')
                        {
                            X=false;
                        }
                        else
                        {
                            matriz[0][2]='O';
                            X=true;
                        }
                    }
                    if(n==2){
                        if(matriz[2][0]=='X')
                        {
                            X=false;
                        }else
                        {
                            matriz[2][0]='O';
                            X=true;
                        }
                    }
                    if(n==3)
                    {
                        if(matriz[2][2]=='X')
                            X=false;
                        else
                        {
                            matriz[2][2]='O';
                            X=true;
                        }
                    }
                }
            }

            else  if(jogada == 3)
            {
                while(P==false)
                {
                    n=rand()%4;

                    if(n==0){
                        if(matriz[0][0]=='X')
                        {
                            P=false;
                        }
                        else{
                            matriz[0][0]='O';
                            P=true;
                        }
                    }
                    if(n==1){
                        if(matriz[0][2]=='X')
                        {
                            P=false;
                        }
                        else
                        {
                            matriz[0][2]='O';
                            P=true;
                        }
                    }
                    if(n==2){
                        if(matriz[2][0]=='X')
                        {
                            P=false;
                        }else
                        {
                            matriz[2][0]='O';
                            P=true;
                        }
                    }
                    if(n==3)
                    {
                        if(matriz[2][2]=='X')
                            P=false;
                        else
                        {
                            matriz[2][2]='O';
                            P=true;
                        }
                    }
                }
            }
            else if(jogada>3 && jogada<9){

                if(matriz[1][0]=='O' && matriz[1][1]=='O'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else  if(matriz[2][0]=='O' && matriz[2][1]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else if(matriz[0][1]=='O' && matriz[0][2]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[1][1]=='O' && matriz[1][2]=='O'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else if(matriz[2][1]=='O' && matriz[2][2]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';

                }else	if(matriz[0][0]=='O' && matriz[1][0]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[0][1]=='O' && matriz[1][1]=='O'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[1][2]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';

                }else	if(matriz[0][0]=='O' && matriz[0][2]=='O'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[1][0]=='O' && matriz[1][2]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[2][0]=='O' && matriz[2][2]=='O'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';

                }else	if(matriz[0][0]=='O' && matriz[1][1]=='O'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else	if(matriz[2][0]=='O' && matriz[1][1]=='O'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][2]=='O' && matriz[1][1]=='O'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[2][2]=='O' && matriz[1][1]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';

                }else	if(matriz[2][0]=='O' && matriz[1][0]=='O'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[2][1]=='O' && matriz[1][1]=='O'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[2][2]=='O' && matriz[1][2]=='O'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][0]=='O' && matriz[2][2]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[2][0]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';

                }else	if(matriz[0][0]=='O' && matriz[2][0]=='O'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else	if(matriz[0][1]=='O' && matriz[2][1]=='O'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='O' && matriz[2][2]=='O'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                    //---- defender
                }else if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else if(matriz[1][0]=='X' && matriz[1][1]=='X'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }else  if(matriz[2][0]=='X' && matriz[2][1]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else if(matriz[0][1]=='X' && matriz[0][2]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[1][1]=='X' && matriz[1][2]=='X'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else if(matriz[2][1]=='X' && matriz[2][2]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';

                }else	if(matriz[0][0]=='X' && matriz[1][0]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[0][1]=='X' && matriz[1][1]=='X'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[1][2]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';

                }else	if(matriz[0][0]=='X' && matriz[0][2]=='X'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[1][0]=='X' && matriz[1][2]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[2][0]=='X' && matriz[2][2]=='X'&& matriz[2][1]==ESPACO){
                    matriz[2][1]='O';

                }else	if(matriz[0][0]=='X' && matriz[1][1]=='X'&& matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else	if(matriz[2][0]=='X' && matriz[1][1]=='X'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][2]=='X' && matriz[1][1]=='X'&& matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else	if(matriz[2][2]=='X' && matriz[1][1]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';

                }else	if(matriz[2][0]=='X' && matriz[1][0]=='X'&& matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else	if(matriz[2][1]=='X' && matriz[1][1]=='X'&& matriz[0][1]==ESPACO){
                    matriz[0][1]='O';
                }else	if(matriz[2][2]=='X' && matriz[1][2]=='X'&& matriz[0][2]==ESPACO){
                    matriz[0][2]='O';

                }else	if(matriz[0][0]=='X' && matriz[2][2]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[2][0]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';

                }else	if(matriz[0][0]=='X' && matriz[2][0]=='X'&& matriz[1][0]==ESPACO){
                    matriz[1][0]='O';
                }else	if(matriz[0][1]=='X' && matriz[2][1]=='X'&& matriz[1][1]==ESPACO){
                    matriz[1][1]='O';
                }else	if(matriz[0][2]=='X' && matriz[2][2]=='X'&& matriz[1][2]==ESPACO){
                    matriz[1][2]='O';
                }
                else if (matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='O' && jogada<8) {
                    if(matriz[0][2]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }
                }
                else if(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='O' && jogada<8){
                    if(matriz[2][2]!=ESPACO && matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }else if(matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }
                }
                else if(matriz[2][0]=='X'&& matriz[1][1]=='X'&& matriz[0][2]=='O' && jogada<8){
                    if(matriz[2][2]!=ESPACO && matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                     }else if(matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }
                }
                else if(matriz[0][0]=='O' && matriz[1][1]=='X' && matriz[2][2]=='X' && jogada<8){
                    if(matriz[0][2]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                     }else if(matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }
                }
                else if(matriz[0][0]=='X' && matriz[1][1]=='O' && matriz[2][2]=='X'){
                    if(matriz[0][1]!=ESPACO && matriz[1][2]!=ESPACO && matriz[2][1]!=ESPACO && matriz[1][0]==ESPACO){
                        matriz[1][0]='O';
                    }else if(matriz[0][1]!= ESPACO && matriz[1][0]!=ESPACO && matriz[2][1]!=ESPACO && matriz[1][2]==ESPACO){
                        matriz[1][2]='O';
                    }else if(matriz[1][0]!= ESPACO && matriz[2][1]!=ESPACO && matriz[1][2]!=ESPACO && matriz[0][1]==ESPACO){
                        matriz[0][1]='O';
                    }else if(matriz[1][0]!= ESPACO && matriz[1][0]!=ESPACO && matriz[1][2]!=ESPACO && matriz[2][1]==ESPACO){
                        matriz[2][1]='O';
                    }else if(matriz[1][2]==ESPACO){
                        matriz[1][2]='O';
                    }
                }
                else if(matriz[2][0]=='X' && matriz[1][1]=='O' && matriz[0][2]=='X'){
                    if(matriz[0][1]!=ESPACO && matriz[1][2]!=ESPACO && matriz[2][1]!=ESPACO && matriz[1][0]==ESPACO){
                        matriz[1][0]='O';
                    }else if(matriz[0][1]!= ESPACO && matriz[1][0]!=ESPACO && matriz[2][1]!=ESPACO && matriz[1][2]==ESPACO){
                        matriz[1][2]='O';
                    }else if(matriz[1][0]!= ESPACO && matriz[2][1]!=ESPACO && matriz[1][2]!=ESPACO && matriz[0][1]==ESPACO){
                        matriz[0][1]='O';
                    }else if(matriz[1][0]!= ESPACO && matriz[1][0]!=ESPACO && matriz[1][2]!=ESPACO && matriz[2][1]==ESPACO){
                        matriz[2][1]='O';
                    }else if(matriz[0][1]==ESPACO){
                        matriz[0][1]='O';
                    }
                }
                else if(matriz[1][0]=='X' && matriz[1][1]=='O' && matriz[2][1]=='X'){
                    if(matriz[0][0]!=ESPACO && matriz[2][2]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[0][0]!= ESPACO && matriz[2][0]!=ESPACO && matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }else if(matriz[2][0]!=ESPACO && matriz[2][2]!=ESPACO && matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }else if(matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }
                }
                else if(matriz[0][1]=='X' && matriz[1][1]=='O' && matriz[1][0]=='X'){
                    if(matriz[0][0]!=ESPACO && matriz[0][2]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[0][2]!= ESPACO && matriz[2][0]!=ESPACO && matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }else if(matriz[0][0]!=ESPACO && matriz[2][0]!=ESPACO && matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }else if(matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }

                }
                else if(matriz[1][1]=='O'&&matriz[2][1]=='X'&&matriz[1][2]=='X'){
                    if(matriz[0][2]!=ESPACO && matriz[2][2]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[2][0]!= ESPACO && matriz[2][2]!=ESPACO && matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }else if(matriz[2][0]!=ESPACO && matriz[0][2]!=ESPACO && matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }else if(matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }
                }
                else  if(matriz[0][1]=='X' && matriz[1][1]=='O' && matriz[1][2]=='X'){
                    if(matriz[0][2]!=ESPACO && matriz[2][2]!=ESPACO && matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }else if(matriz[0][0]!= ESPACO && matriz[2][2]!=ESPACO && matriz[1][1]==ESPACO){
                        matriz[1][1]='O';
                    }else if(matriz[0][0]!=ESPACO && matriz[1][1]!=ESPACO && matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }else if(matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }
                }

                //------ ataca

            else if(matriz[0][0]=='X' && matriz[1][1]=='O' && matriz[2][2]=='O' && jogada == 5){
                if(matriz[2][1]!=ESPACO && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';
                }else if(matriz[1][2]!=ESPACO && matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }

            }else if(matriz[0][2]=='X' && matriz[1][1]=='O' && matriz[2][0]=='O' && jogada == 5){
                if(matriz[2][1]!=ESPACO && matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }else if(matriz[1][0]!=ESPACO && matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }
            }else if(matriz[2][2]=='X' && matriz[1][1]=='O' && matriz[0][0]=='O' && jogada == 5){
                if(matriz[0][1]!=ESPACO && matriz[2][0]==ESPACO){
                    matriz[2][0]='O';
                }else if(matriz[1][0]!=ESPACO && matriz[0][2]==ESPACO){
                    matriz[0][2]='O';
                }
            }else if(matriz[2][0]=='X' && matriz[1][1]=='O' && matriz[0][2]=='O' && jogada == 5){
                if(matriz[0][1]!=ESPACO && matriz[2][2]==ESPACO){
                    matriz[2][2]='O';
                }else if(matriz[1][2]!=ESPACO && matriz[0][0]==ESPACO){
                    matriz[0][0]='O';
                }}

                //-----------defende

                else if(matriz[0][1]=='X' && matriz[1][1]=='O' && matriz[2][0]=='X'){
                    if(matriz[0][0]!=ESPACO && matriz[1][0]==ESPACO){
                        matriz[1][0]='O';
                    }else if(matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }
                }
                else if(matriz[0][1]=='X' && matriz[1][1]=='O' && matriz[2][2]=='X'){
                    if(matriz[0][2]!=ESPACO && matriz[1][2]==ESPACO){
                        matriz[1][2]='O';
                    }else if(matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }
                }
                else if(matriz[0][0]=='X' && matriz[1][1]=='O' && matriz[1][2]=='X'){
                    if(matriz[0][1]!=ESPACO && matriz[0][2]==ESPACO){
                        matriz[0][2]='O';
                    }else if(matriz[0][1]==ESPACO){
                        matriz[0][1]='O';
                    }
                }
                else if(matriz[2][0]=='X' && matriz[1][1]=='O' && matriz[1][2]=='X'){
                    if(matriz[2][1]!=ESPACO && matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }else if(matriz[2][1]==ESPACO){
                        matriz[2][1]='O';
                    }
                }
                else if(matriz[0][0]=='X' && matriz[1][1]=='O' && matriz[2][1]=='X'){
                    if(matriz[1][0]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[1][0]==ESPACO){
                        matriz[1][0]='O';
                    }
                }
                else if(matriz[0][2]=='X' && matriz[1][1]=='O' && matriz[2][1]=='X'){
                    if(matriz[1][2]!=ESPACO && matriz[2][2]==ESPACO){
                        matriz[2][2]='O';
                    }else if(matriz[1][2]==ESPACO){
                        matriz[1][2]='O';
                    }
                }else if(matriz[1][0]=='X' && matriz[1][1]=='O' && matriz[2][2]=='X'){
                    if(matriz[2][1]!=ESPACO && matriz[2][0]==ESPACO){
                        matriz[2][0]='O';
                    }else if(matriz[2][1]==ESPACO){
                        matriz[2][1]='O';
                  }
                }else if(matriz[1][0]=='X' && matriz[1][1]=='O' && matriz[0][2]=='X'){
                    if(matriz[0][0]!=ESPACO && matriz[0][1]==ESPACO){
                        matriz[0][1]='O';
                    }else if(matriz[0][0]==ESPACO){
                        matriz[0][0]='O';
                    }
                }

                //-----------
                else {
                    do{

                        linha = (rand()% DIM);
                        coluna = (rand()% DIM);
                    }while(matriz[linha][coluna] != ESPACO);
                    matriz[linha][coluna] = 'O';
                }
            }


            else  if(jogada == 9){
                for (int i=0; i< DIM;i++) {
                    for (int j=0; j< DIM;j++) {
                        linha=i;
                        coluna=j;
                        if(matriz[linha][coluna]==ESPACO)matriz[linha][coluna] = 'O';
                    }
                }
            }
        }
    }
                   // SetConsoleTextAttribute(h,15);
}


//============================================================================================
int CTabuleiro :: verificaResultado(char matriz[DIM][DIM]){

    if(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X')return 1;
    if(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X')return 1;
    if(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X')return 1;
    if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X')return 1;
    if(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X')return 1;
    if(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X')return 1;
    if(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X')return 1;
    if(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X')return 1;
    if(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O') return -1;
    if(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O') return -1;
    if(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O') return -1;
    if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O') return -1;
    if(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O') return -1;
    if(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O') return -1;
    if(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O') return -1;
    if(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O') return -1;

}
//============================================================================================

void CTabuleiro:: mostraResultado(int &n){
    if (n == 1){ SetConsoleTextAttribute(h,10); cout << "\n========VITORIA========"<<endl;SetConsoleTextAttribute(h,15);}
    else if (n == -1){SetConsoleTextAttribute(h,12);cout << "\n========DERROTA========"<<endl;SetConsoleTextAttribute(h,15);
   }else{ SetConsoleTextAttribute(h,14); cout << "\n========EMPATE========"<<endl;SetConsoleTextAttribute(h,15);}
}
//============================================================================================
int CTabuleiro :: retornaCasas(char matriz[DIM][DIM]){
    int casas=1;
    for (int i=0;i<DIM;i++) {
        for (int j=0;j<DIM;j++) {
            if(matriz[i][j]!=ESPACO) casas++;
        }
    }
    return casas;
}

//==========================================Menus=============================================



void menuPrincipal(){

   SetConsoleTextAttribute(h,15);
    cout<<"\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCDJODO DO GALO\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB" << endl;
    cout<<"\xBA                                   \xBA \n";
    cout<<"\xBA Escolha uma das seguintes op\x87\xe4";
    cout<<"es: \xBA \n";
    cout<<"\xBA 1-> Iniciar um novo jogo          \xBA\n";
    cout<<"\xBA 2-> Continuar um jogo             \xBA"<< endl;
    cout<<"\xBA 3-> Mostrar top 10                \xBA"<< endl;
    cout<<"\xBA 4-> Sair                          \xBA \n";
    cout<<"\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n" << endl;
    SetConsoleTextAttribute(h,15);
}

void menuSecundario(){
    SetConsoleTextAttribute(h,15);
    cout<<"\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB" << endl;
    cout<<"\xBA Escolha a dificuldade:       \xBA \n";
    cout<<"\xBA                              \xBA \n";
    cout<<"\xBA 0-> Voltar ao menu principal \xBA\n";
    cout<<"\xBA 1-> Elementar                \xBA \n";
    cout<<"\xBA 2-> B\xa0sico                   \xBA"<< endl;
    cout<<"\xBA 3-> M\x82";
    cout <<"dio                    \xBA \n";
    cout<<"\xBA 4-> Avan\x87";
    cout<<"ado                 \xBA \n";
    cout<<"\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n" << endl;
    cout<<"Escolha:";
    SetConsoleTextAttribute(h,15);

}

void menuCaixa (int cont_jogo, int cont_win, int cont_lose, int cont_draw,  int contaJogadas, string nivel){

    string b;
    int e,r,t,y,u;
    b=to_string(cont_jogo);
    e=b.length();
    int parte1=10;
    parte1+=e;

    b=to_string(cont_win);
    r=b.length();
    int parte2=4;
    parte2+=r;

    b=to_string(cont_lose);
    t=b.length();
    int parte3=4;
    parte3+=t;

    b=to_string(cont_draw);
    y=b.length();
    int parte4=4;
    parte4+=y;


   // SetConsoleTextAttribute(h,11);
    cout<<"\n\n";
    cout<<"\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\t\t\t\t\xDA";

    for (int i=0;i<parte1;i++) {
        cout<<"\xC4";
    }
    cout<<"\xc2";

    for (int i=0;i<parte2;i++) {
        cout<<"\xC4";
    }
    cout<<"\xc2";

    for (int i=0;i<parte3;i++) {
        cout<<"\xC4";
    }
    cout<<"\xc2";

    for (int i=0;i<parte4;i++) {
        cout<<"\xC4";
    }
    cout<<"\xBF"<<endl; //até aqui linha 1

    cout<<"\xB3"<<setw(2)<<contaJogadas<<"\xf8Jogada! "<<"\xB3\t\t\t\t\xB3";
   //SetConsoleTextAttribute(h,11);
    cout << " N\xf8Jogos:"<<cont_jogo; //daqui linha 2
    cout<<" \xb3 V:"<<cont_win;
    cout<<" \xb3 D:"<<cont_lose;
    cout<<" \xb3 E:"<<cont_draw;

    cout<<" \xB3\n";            //até aqui linha 2

    cout<<"\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\t\t\t\t\xc3";
    // SetConsoleTextAttribute(h,11);
    for (int i=0;i<parte1;i++) { //daqui linha 3
        cout<<"\xC4";
    }
    cout<<"\xc1";

    for (int i=0;i<parte2;i++) {
        cout<<"\xC4";
    }
    cout<<"\xc1";

    for (int i=0;i<parte3;i++) {
        cout<<"\xC4";
    }
    cout<<"\xc1";

    for (int i=0;i<parte4;i++) {
        cout<<"\xC4";
    }
    cout<<"\xb4";
     //SetConsoleTextAttribute(h,15);
    cout<<"\nSua jogada: \t\t\t\t";
   // SetConsoleTextAttribute(h,11);
    cout<< "\xB3 Dificuldade: "<<nivel;




    int meio=parte1+parte2+parte3+parte4+3;
    u=nivel.length()+ 14;
    int meio2= meio - u;
    for (int i=0; i<meio2; i++) {
        cout<<" ";
    }

    cout<<"\xB3\n";
    cout<<"\t\t\t\t\t\xC0";

    for (int i=0; i < meio;i++) {
        cout<<"\xC4";
    }
    cout<<"\xD9";
    //SetConsoleTextAttribute(h,15);
}
void mostraPosicao(){
    SetConsoleTextAttribute(h,15);
    cout<<"Posi\x87\xe4";
    cout<<"es do tablueiro:\n\n";
    cout<<" 7 \xBA 8 \xBA 9 "<<endl;
    cout<<"\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCE\xCD\xCD\xCD"<<endl;
    cout<<" 4 \xBA 5 \xBA 6 "<<endl;
    cout<<"\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCE\xCD\xCD\xCD"<<endl;
    cout<<" 1 \xBA 2 \xBA 3 "<<endl;
    SetConsoleTextAttribute(h,15);
}

