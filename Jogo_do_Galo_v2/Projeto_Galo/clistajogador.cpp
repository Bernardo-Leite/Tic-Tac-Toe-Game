#include "clistajogador.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int maiorNome=0;


void CListaJogador  :: criaFich(string name,int jogos, int win, int loses, int draw){

        fstream fich;
        fich.open("Ranking.txt", ios::app);

        if(fich.fail()) {
                cout << "Erro a criar ficheiro da classificacao.";
                return;
        }

        fich << name << endl;
        fich << jogos << endl;
        fich << win << endl;
        fich << loses<< endl;
        fich << draw << endl;

        fich.close();
}

void CListaJogador :: readFicheiro()
{

        string name;
        int jogos;
        int win;
        int loses;
        int draw;

        ifstream fich;
        fich.open("Ranking.txt", ios::in);
        if(fich.fail())
        {
            cout <<"Erro a abrir ficheiro!" <<endl;
            return;
        }

        fich.peek();


        while(!fich.eof())
        {

                fich>>name;
                fich>>jogos;
                fich>>win;
                fich>>loses;
                fich>>draw;

                fich.peek();
                int k = name.length();
                if(k > maiorNome) maiorNome=k;
                ordenaClassificacao(name, jogos, win, loses, draw);
        }
        fich.close();
        mostraLista();
}
void CListaJogador::ordenaClassificacao(string name, int jogos, int win, int loses, int draw){
        CNoListaJogador *novo= new CNoListaJogador;
        CNoListaJogador *atual, *anterior;

        novo->name = name;
        novo->jogos = jogos;
        novo->win = win;
        novo->loses = loses;
        novo->draw = draw;
        novo->proximo=NULL;

        if(cabeca==NULL) {
                cabeca=novo;
                return;
        }
        else
        {
                if (win > cabeca-> win)
                {
                        novo->proximo = cabeca;
                        cabeca = novo;
                        return;
                }
                else
                {
                        CNoListaJogador *atual = cabeca;
                        CNoListaJogador *anterior = cabeca;
                        while (win <= atual->win && atual->proximo != NULL)
                        {
                                anterior = atual;
                                atual = atual->proximo;
                        }
                        if (win <= atual->win)
                        {
                                atual->proximo = novo;
                                return;
                        }
                        else
                        {
                                novo->proximo = atual;
                                anterior->proximo = novo;
                                return;
                        }
                }
        }

}


void CListaJogador:: mostraLista()
{
        int n = 1;
        CNoListaJogador *atual = cabeca;
        CNoListaJogador *anterior;

        while(atual != NULL)
        {
                if(n >= 2 && atual->name == anterior->name  && anterior->jogos == atual->jogos && anterior->win == atual->win && anterior->draw == atual->draw &&anterior->loses == atual->loses)
                {
                    n--;
                }
                else
                {

                string aux1;
                int nt, jt, vt, dt, et, aux2;

                aux1=atual->name;
                nt=aux1.length();

                aux2 = atual->jogos;
                aux1=to_string(aux2);
                jt=aux1.length();

                aux2 = atual->win;
                aux1=to_string(aux2);
                vt=aux1.length();

                aux2 = atual->loses;
                aux1=to_string(aux2);
                dt=aux1.length();

                aux2 = atual->draw;
                aux1=to_string(aux2);
                et=aux1.length();


                cout <<"\t\xdB\xdF";
                for (int i=0;i<23+maiorNome;i++) {
                    cout <<"\xdF";
                }
                cout <<"\xdB\n";

                cout <<" \t\xdB "<< n <<"\xf8 - Nome:\t\t"<<atual->name;
                for (int i=nt;i<maiorNome+1;i++) {
                    cout << " ";
                }
                cout << "\xdB"<<endl;

                cout <<" \t\xdB Jogos:\t\t"<<atual->jogos;
                for (int i=jt;i<maiorNome+1;i++) {
                    cout << " ";
                }
                cout << "\xdB"<<endl;

                cout <<" \t\xdB Vitorias:\t\t"<<atual->win;
                for (int i=vt;i<maiorNome+1;i++) {
                    cout << " ";
                }
                cout << "\xdB"<<endl;

                cout <<" \t\xdB Derrotas:\t\t"<<atual->loses;
                for (int i=dt;i<maiorNome+1;i++) {
                    cout << " ";
                }
                cout << "\xdB"<<endl;

                cout <<" \t\xdB Empates:\t\t"<<atual->draw;
                for (int i=et;i<maiorNome+1;i++) {
                    cout << " ";
                }
                cout << "\xdB"<<endl;

                cout <<"\t\xdB\xdC";
                for (int i=0;i<23+maiorNome;i++) {
                    cout <<"\xdC";
                }
                cout<<"\xdB\n\n";

               }
                if(n == 10) break;

                                anterior = atual;
                                atual = atual->proximo;
                                n++;
        }
}
