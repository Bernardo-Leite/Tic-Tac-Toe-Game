//=============================================================================
// Estrutura de Dados e Algorítmos 2018/2019
//=============================================================================
// Bernardo Alexandre dos Santos Costa Leite, 2017268958
// Roberto Luís Dias Pereira, 2017270581
//=============================================================================
// Mini-projeto: Jogo do galo.
//=============================================================================

#include <cstdlib>
#include <iostream>
#include "jogodogalo.h"
#include <iomanip>
#include <time.h>
#include<string>
#include"clistajogador.h"
#include "cjogadores.h"
#include <windows.h>
#define DIM 3


HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;



int main(){

    CListaJogador p;
    CJogador pessoa,computador;


    int linha, coluna,posicao,contaJogadas=1;
    char matriz[DIM][DIM];
    bool primeiroJogador,jogar_novamente = false;

    int x,opcao,escolha,continua,aux;
    string nome;
    CTabuleiro tabuleiro(matriz);
    int k;
    do{
start:
        system("CLS");
        menuPrincipal();
        cout<<"Op\x87\xc6o:";
        cin>>opcao;
        if(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
        }
        cout<<"\n";

        switch (opcao) {

        case 1:system("CLS");
            do{
                menuSecundario();
                cin>>escolha;
            }while(escolha<0||escolha>4);
            if(escolha==0)break;

            else if(escolha==1){
                pessoa.escerveNome(nome);
                primeiroJogador=pessoa.quemJogaPrimeiro();
                tabuleiro.resetMatriz(matriz);
                contaJogadas=tabuleiro.retornaCasas(matriz);
aqui1:
                int cont_jogo=1,cont_win=0,cont_lose=0,cont_draw=0;

                do
                {  system("CLS");
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    srand((time(NULL)));
                    mostraPosicao();
                    cout<<"\n\n";
                    tabuleiro.mostraMatriz(matriz);
                    do{
                        if (primeiroJogador){

                            SetConsoleTextAttribute(color,18);
                            k= pessoa.posicaoJogador(matriz,posicao, linha, coluna,nome);
                            if(k==2){

                                goto start;
                            }

                            menuCaixa(cont_jogo,cont_win,cont_lose,cont_draw,contaJogadas,"Elementar");
                            contaJogadas++;
                        }else{
                            SetConsoleTextAttribute(color,18);
                            computador.posicaoComputador(matriz, linha, coluna);
                            cout<<"\n";
                            cout<<"\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF"<<endl;
                            cout<<"\xB3"<<setw(2)<<contaJogadas++<<"\xf8Jogada! "<<"\xB3"<<endl;
                            cout<<"\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9";
                            cout<<"\nJogada do computador: \n";

                        }
                        tabuleiro.NivelElementar(matriz, linha, coluna, primeiroJogador);
                        cout<<"\n";
                        tabuleiro.mostraMatriz(matriz);
                        primeiroJogador = !primeiroJogador;

                        x =tabuleiro.verificaResultado(matriz);
                        if(x == 1 || x == -1){
                            tabuleiro.resetMatriz(matriz);
                            break;
                        }
                        pessoa.continua(matriz, nome, 1);

                    }while(contaJogadas <= 9);
                    if(x==1){
                        cont_jogo++;
                        cont_win++;
                    } else if(x == -1) {
                        cont_jogo++;
                        cont_lose++;
                    }else {
                        cont_jogo++;
                        cont_draw++;
                    }
                    tabuleiro.mostraResultado(x);
                    contaJogadas=1;
                    tabuleiro.resetMatriz(matriz);
                    pessoa.continua(matriz, nome, 1);
                    pessoa.guardado(matriz, nome);
                    do{
                        cout<<"\nJogar novamente(1)  Voltar ao menu pincipal(0):";
                        cin>>continua;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(100,'\n');}
                    }while(continua<0||continua>1);
                    if(continua == 1){
                        jogar_novamente = true;
                        primeiroJogador=pessoa.quemJogaPrimeiro();
                    }else jogar_novamente = false;
                }while(jogar_novamente==true);
                cont_jogo--;
                p.criaFich(nome,cont_jogo,cont_win,cont_lose,cont_draw);
                pessoa.continua(matriz, nome, 1);
                system("PAUSE");
                break;
            }

            else if(escolha==2){
                pessoa.escerveNome(nome);
                primeiroJogador=pessoa.quemJogaPrimeiro();
                tabuleiro.resetMatriz(matriz);
                contaJogadas=tabuleiro.retornaCasas(matriz);
aqui2:
                int cont_jogo=1,cont_win=0,cont_lose=0,cont_draw=0;
                do
                {   system("CLS");
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    srand((time(NULL)));
                    mostraPosicao();
                    cout<<"\n\n";
                    tabuleiro.mostraMatriz(matriz);
                    do{
                        if (primeiroJogador){
                            SetConsoleTextAttribute(color,15);
                            k= pessoa.posicaoJogador(matriz,posicao, linha, coluna,nome);
                            if(k==2){
                                pessoa.continua(matriz, nome, escolha);
                                goto start;
                            }

                            menuCaixa(cont_jogo,cont_win,cont_lose,cont_draw,contaJogadas,"Basico");
                            contaJogadas++;
                        }else{
                            SetConsoleTextAttribute(color,15);
                            computador.posicaoComputador(matriz, linha, coluna);
                            cout<<"\n";
                            cout<<"\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF"<<endl;
                            cout<<"\xB3"<<setw(2)<<contaJogadas++<<"\xf8Jogada! "<<"\xB3"<<endl;
                            cout<<"\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9";
                            cout<<"\nJogada do computador: \n";

                        }
                        tabuleiro.NivelBasico(matriz, linha, coluna, primeiroJogador);
                        cout<<"\n";
                        tabuleiro.mostraMatriz(matriz);
                        primeiroJogador = !primeiroJogador;

                        x =tabuleiro.verificaResultado(matriz);
                        if(x == 1 || x == -1){
                            tabuleiro.resetMatriz(matriz);
                            break;
                        }
                        pessoa.continua(matriz, nome, 2);
                        pessoa.guardado(matriz, nome);

                    }while(contaJogadas <= 9);
                    if(x==1){
                        cont_jogo++;
                        cont_win++;
                    } else if(x == -1) {
                        cont_jogo++;
                        cont_lose++;
                    }else {
                        cont_jogo++;
                        cont_draw++;
                    }
                    tabuleiro.mostraResultado(x);
                    contaJogadas=1;
                    tabuleiro.resetMatriz(matriz);
                    do{
                        cout<<"\nJogar novamente(1)  Voltar ao menu pincipal(0):";
                        cin>>continua;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(100,'\n');}
                    }while(continua<0||continua>1);

                    if(continua == 1){
                        jogar_novamente = true;
                        primeiroJogador=pessoa.quemJogaPrimeiro();
                    }else jogar_novamente = false;
                }while(jogar_novamente==true);
                cont_jogo--;
                p.criaFich(nome,cont_jogo,cont_win,cont_lose,cont_draw);
                pessoa.continua(matriz, nome, 2);
                system("PAUSE");
                break;
            }

            else if(escolha==3){
                pessoa.escerveNome(nome);
                primeiroJogador=pessoa.quemJogaPrimeiro();
                tabuleiro.resetMatriz(matriz);
                contaJogadas=tabuleiro.retornaCasas(matriz);

aqui3:
                int cont_jogo=1,cont_win=0,cont_lose=0,cont_draw=0;
                do
                {   system("CLS");
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    srand((time(NULL)));
                    mostraPosicao();
                    cout<<"\n\n";
                    tabuleiro.mostraMatriz(matriz);
                    do{
                        if (primeiroJogador){
                            SetConsoleTextAttribute(color,15);
                            k= pessoa.posicaoJogador(matriz,posicao, linha, coluna,nome);
                            if(k==2){
                                pessoa.continua(matriz, nome, escolha);
                                goto start;
                            }

                            menuCaixa(cont_jogo,cont_win,cont_lose,cont_draw,contaJogadas,"Medio");
                            contaJogadas++;
                        }else{
                            SetConsoleTextAttribute(color,15);
                            computador.posicaoComputador(matriz, linha, coluna);
                            cout<<"\n\n";
                            cout<<"\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF"<<endl;
                            cout<<"\xB3"<<setw(2)<<contaJogadas++<<"\xf8Jogada! "<<"\xB3"<<endl;
                            cout<<"\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9";
                            cout<<"\nJogada do computador: \n";

                        }
                        tabuleiro.NivelMedio(matriz, linha, coluna, primeiroJogador);

                        cout<<"\n";
                        tabuleiro.mostraMatriz(matriz);
                        primeiroJogador = !primeiroJogador;

                        x =tabuleiro.verificaResultado(matriz);
                        if(x == 1 || x == -1){
                            tabuleiro.resetMatriz(matriz);
                            break;
                        }
                        pessoa.continua(matriz, nome, 3);
                        pessoa.guardado(matriz, nome);
                    }while(contaJogadas <= 9);
                    if(x==1){
                        cont_jogo++;
                        cont_win++;
                    } else if(x == -1) {
                        cont_jogo++;
                        cont_lose++;
                    }else {
                        cont_jogo++;
                        cont_draw++;
                    }
                    tabuleiro.mostraResultado(x);
                    contaJogadas=1;
                    tabuleiro.resetMatriz(matriz);
                    do{
                        cout<<"\nJogar novamente(1)  Voltar ao menu pincipal(0):";
                        cin>>continua;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(100,'\n');}
                    }while(continua<0||continua>1);
                    if(continua == 1){
                        jogar_novamente = true;
                        primeiroJogador=pessoa.quemJogaPrimeiro();
                    }else jogar_novamente = false;
                }while(jogar_novamente==true);
                cont_jogo--;
                p.criaFich(nome,cont_jogo,cont_win,cont_lose,cont_draw);
                pessoa.continua(matriz, nome, 3);
                system("PAUSE");
                 break;
            }



            else if(escolha==4) {
                pessoa.escerveNome(nome);
                primeiroJogador=pessoa.quemJogaPrimeiro();
                tabuleiro.resetMatriz(matriz);
                contaJogadas=tabuleiro.retornaCasas(matriz);
aqui4:
                int cont_jogo=1,cont_win=0,cont_lose=0,cont_draw=0;
                contaJogadas=tabuleiro.retornaCasas(matriz);
                do
                {   system("CLS");
                    mostraPosicao();
                    aux=1;
                    cout<<"\n\n";
                    tabuleiro.mostraMatriz(matriz);
                    do {
                        if (primeiroJogador) {
                            SetConsoleTextAttribute(color,15);
                            k= pessoa.posicaoJogador(matriz,posicao, linha, coluna,nome);
                            if(k==2){
                                pessoa.continua(matriz, nome, escolha);
                                goto start;
                            }

                            menuCaixa(cont_jogo,cont_win,cont_lose,cont_draw,contaJogadas,"Avancado");
                            contaJogadas++;
                        }else{
                            SetConsoleTextAttribute(color,15);
                            computador.posicaoComputador(matriz, linha, coluna);
                            cout<<"\n\n";
                            cout<<"\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF"<<endl;
                            cout<<"\xB3"<<setw(2)<<contaJogadas++<<"\xf8Jogada! "<<"\xB3"<<endl;
                            cout<<"\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9";
                            //SetConsoleTextAttribute(color,15);
                            cout<<"\nJogada do computador: \n";

                        }

                        tabuleiro.NivelDestruidor(matriz, linha, coluna, primeiroJogador,aux);
                        aux++;
                        cout<<"\n";
                        tabuleiro.mostraMatriz(matriz);
                        primeiroJogador = !primeiroJogador;

                        x =tabuleiro.verificaResultado(matriz);
                        if(x == 1 || x == -1) {
                            tabuleiro.resetMatriz(matriz);
                            break;
                        }
                        pessoa.continua(matriz, nome, 4);
                        pessoa.guardado(matriz, nome);
                    } while(contaJogadas <= 9);
                    if(x==1) {
                        cont_jogo++;
                        cont_win++;
                    } else if(x == -1) {
                        cont_jogo++;
                        cont_lose++;
                    }else {
                        cont_jogo++;
                        cont_draw++;
                    }
                    tabuleiro.mostraResultado(x);
                    contaJogadas=1;
                    tabuleiro.resetMatriz(matriz);
                    do {
                        cout<<"\nJogar novamente(1)  Voltar ao menu pincipal(0):";
                        cin>>continua;
                        if(cin.fail()) {
                            cin.clear();
                            cin.ignore(100,'\n');
                        }
                    } while(continua<0||continua>1);
                    if(continua == 1) {
                        jogar_novamente = true;
                        primeiroJogador=pessoa.quemJogaPrimeiro();
                    }else jogar_novamente = false; } while(jogar_novamente==true);

                cont_jogo--;
                p.criaFich(nome,cont_jogo,cont_win,cont_lose,cont_draw);
                pessoa.continua(matriz, nome, 4);
                system("PAUSE");
                break;

            }
        case 2:
        {

                system("CLS");
                int l=pessoa.guardado(matriz, nome);
                if(l>0 && l < 5){
                cout<<"O jogo que se encontra suspenso\n\n";
                tabuleiro.mostraMatriz(matriz);

                cout<<"\n";
                int o;
                do{
                    cout<<"\nPretende continuar este jogo? \n1-Sim | 2-Nao:";
                    cin >> o;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                }while(o<1 || o>2);
                if(o==2) goto start;

                if(l==1){
                    //escolha=1;
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    primeiroJogador=true;
                    goto aqui1;
                }

                else if(l==2){
                    //escolha=2;
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    primeiroJogador=true;
                    goto aqui2;
                }

                else if(l==3) {
                    //escolha=3;
                    contaJogadas=tabuleiro.retornaCasas(matriz);
                    primeiroJogador=true;
                    goto aqui3;
                }

                else if(l==4){
                    //escolha=4;
                    aux=tabuleiro.retornaCasas(matriz);
                    primeiroJogador=true;
                    goto aqui4;
                }
            }
                else cout << "Nao se encontra nenhum jogo suspendido.\n\n";
                system("PAUSE");
                break;
        }

        case 3:{
            system("CLS");
            CListaJogador aux;

            cout<<"\t\t\t\t|Top 10 das melhores jogadas!|\n\n\n";

            aux.readFicheiro();
            //p.mostraLista();

            system("PAUSE");
            break;
        }
        case 4:
            system("CLS");
            cout<<"\t\tADEUS!\n";
            cout<<"\n\n\n\n\nDEVELOPERS:Bernardo Leite\n";
            cout<<"           Roberto Pereira\n\n\n";

            break;
        }

    }while(opcao!=4);

    return EXIT_SUCCESS;
}
