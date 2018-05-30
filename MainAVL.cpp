#include <iostream>
#include <stdlib.h>
#include "RotinasAVL.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{   
    bool encerra = false;

    ArvoreAvl *T = new ArvoreAvl();
    int Elem;
    do
    {  
        system("clear");
        cout << "-------------ARVORES AVL-------------" << endl;
        cout << "1.Inserção" << endl;
        cout << "2.Remoção" << endl;
        cout << "3.Visualizar Regras de Balanceamento" << endl;
        cout << "4.Consultar Arvore em Ordem" << endl;
        cout << "5.Consultar Arvore em Pré-Ordem" << endl;
        cout << "6.Consultar Arvore em Pos-Ordem" << endl;
        cout << "7.Esvaziar Arvore" << endl;
        cout << "8.Encerrar" << endl << endl;
        cout << "Opção: ";
        
        char op;
        cin >> op;
        
        switch(op)
        {
            case '1': cout << "Elemento: ";cin >> Elem; T->Inserir(Elem);break;
            case '2':   break;
            case '3':   break;
            case '4':   break;
            case '5':   break;
            case '6':   break;
            case '7':   break;
            case '8': encerra = true; break;
            default:break;
        }


    }while(!encerra);

    return 0;
}