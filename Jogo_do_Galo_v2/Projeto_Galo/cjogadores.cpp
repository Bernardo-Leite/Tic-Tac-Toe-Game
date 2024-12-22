#include "cjogadores.h"
#include <time.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#define ESPACO ' '
#define DIM 3

using namespace std;
//============================================================================================

//============================================================================================
void CJogador::escerveNome(string &nome){
   do{ cout<<"Insira o nome do jogador:";
    cin.ignore();
    getline(cin,nome);
    }while(nome=="");
}
//============================================================================================

CJogador::~CJogador(){}

//============================================================================================

bool CJogador :: quemJogaPrimeiro(){
               int opcao;

                       do{
                           cout<<"Escolha quem joga primeiro-> Jogador(1)  Computador(2)  Aleat\xa2rio(3):";
                            cin>>opcao;
                         //  if(cin.fail()){
                            cin.clear();
                            cin.ignore(100,'\n');
                        //}

                }while(opcao<1||opcao>3);
                       switch (opcao) {
                                case 1:return true;
                                case 2:return false;
                                case 3:srand(time(NULL));
                               int i = 1+(rand()%2);
                               if(i==1) return true;
                               else return false;
                       }



}
//============================================================================================

int CJogador :: posicaoJogador(char matriz[DIM][DIM],int &posicao,int &linha,int &coluna, string &nome){

        bool repetir = true;


             cout<<endl<<endl<<"\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4> "<<nome<<" \x82 a sua vez de jogar <\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n";
        do{
                 cout<<"\nIntroduza a Posi\x87\xC6o de Jogo[De 1 a 9] ou 0 para suspender:";

                    do{
                        cin>>posicao;
                        //if(cin.fail()){
                            cin.clear();
                            cin.ignore(100,'\n');
                        //}
                            if (posicao==0)return 2;
                 }while(posicao<0 || posicao>9);
                 if(posicao==1){linha=2;coluna=0;}
                 else if(posicao==2){linha=2;coluna=1;}
                 else if(posicao==3){linha=2;coluna=2;}
                 else if(posicao==4){linha=1;coluna=0;}
                  else if(posicao==5){linha=1;coluna=1;}
                  else if(posicao==6){linha=1;coluna=2;}
                  else if(posicao==7){linha=0;coluna=0;}
                  else if(posicao==8){linha=0;coluna=1;}
                  else if(posicao==9){linha=0;coluna=2;}

                 if(matriz[linha][coluna] !=ESPACO){
                  cout<<"\n!Posi\x87\xC6o ja ocupada!\n";
                }else{
                        repetir = false;
                }
         }while(repetir == true);

}

//============================================================================================

void CJogador :: posicaoComputador(char matriz[DIM][DIM], int &linha, int &coluna){

                do{

                        linha = (rand()% DIM);
                        coluna = (rand()% DIM);
                }while(matriz[linha][coluna] != ESPACO);
}

//============================================================================================

void CJogador :: continua(char matriz[DIM][DIM], string nome, int dificuldade)
{
        ofstream fich;
        fich.open("JogoSuspenso.txt");
        fich << nome << ";";
        for(int i=0; i<DIM; i++)
        {
                for(int j = 0; j < DIM; j++)
                {
                        if(matriz[i][j] == ' ')
                                fich << "0;";
                        if(matriz[i][j] == 'X')
                                fich << "1;";
                        if(matriz[i][j] == 'O')
                                fich << "2;";
                }
        }
        if(dificuldade==1) fich << "0;";
        else if(dificuldade==2) fich << "1;";
        else if(dificuldade==3) fich << "2;";
        else if(dificuldade==4) fich << "3;";
        fich.close();
}
//============================================================================================

int CJogador :: guardado(char matriz[DIM][DIM],string nome)
{
        string a;
        string b, c, d, e, f, g, h, j, i, x;
        ifstream fich;

        fich.open("JogoSuspenso.txt");
        if(fich.is_open())
        {
                getline(fich, a, ';');
                getline(fich, b, ';');
                getline(fich, c, ';');
                getline(fich, d, ';');
                getline(fich, e, ';');
                getline(fich, f, ';');
                getline(fich, g, ';');
                getline(fich, h, ';');
                getline(fich, i, ';');
                getline(fich, j, ';');
                getline(fich, x, ';');
                if(a=="")return 0;

                else
                {
                        if(stoi(b)==0)
                        {
                                matriz[0][0] = ' ';
                        }
                        else if(stoi(b)==1)
                        {
                                matriz[0][0] = 'X';
                        }
                        else if(stoi(b)==2)
                        {
                                matriz[0][0] = 'O';
                        }
                        if(stoi(c)==0)
                        {
                                matriz[0][1] = ' ';
                        }
                        else if(stoi(c)==1)
                        {
                                matriz[0][1] = 'X';
                        }
                        else if(stoi(c)==2)
                        {
                                matriz[0][1] = 'O';
                        }
                        if(stoi(d)==0)
                        {
                                matriz[0][2] = ' ';
                        }
                        else if(stoi(d)==1)
                        {
                                matriz[0][2] = 'X';
                        }
                        else if(stoi(d)==2)
                        {
                                matriz[0][2] = 'O';
                        }
                        if(stoi(e)==0)
                        {
                                matriz[1][0] = ' ';
                        }
                        else if(stoi(e)==1)
                        {
                                matriz[1][0] = 'X';
                        }
                        else if(stoi(e)==2)
                        {
                                matriz[1][0] = 'O';
                        }
                        if(stoi(f)==0)
                        {
                                matriz[1][1] = ' ';
                        }
                        else if(stoi(f)==1)
                        {
                                matriz[1][1] = 'X';
                        }
                        else if(stoi(f)==2)
                        {
                                matriz[1][1] = 'O';
                        }
                        if(stoi(g)==0)
                        {
                                matriz[1][2] = ' ';
                        }
                        else if(stoi(g)==1)
                        {
                                matriz[1][2] = 'X';
                        }
                        else if(stoi(g)==2)
                        {
                                matriz[1][2] = 'O';
                        }
                        if(stoi(h)==0)
                        {
                                matriz[2][0] = ' ';
                        }
                        else if(stoi(h)==1)
                        {
                                matriz[2][0] = 'X';
                        }
                        else if(stoi(h)==2)
                        {
                                matriz[2][0] = 'O';
                        }
                        if(stoi(i)==0)
                        {
                                matriz[2][1] = ' ';
                        }
                        else if(stoi(i)==1)
                        {
                                matriz[2][1] = 'X';
                        }
                        else if(stoi(i)==2)
                        {
                                matriz[2][1] = 'O';
                        }
                        if(stoi(j)==0)
                        {
                                matriz[2][2] = ' ';
                        }
                        else if(stoi(j)==1)
                        {
                                matriz[2][2] = 'X';
                        }
                        else if(stoi(j)==2)
                        {
                                matriz[2][2] = 'O';
                        }
                }

                if(stoi(x)==0)return 1;
                else if(stoi(x)==1)return 2;
                else if(stoi(x)==2)return 3;
                else if(stoi(x)==3)return 4;

        }
}

