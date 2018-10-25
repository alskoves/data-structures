#pragma once
//Listas duplas

#include<stdlib.h>
#include<stdio.h>

/******************************************************************************/

template <class NTYPE>
class LISTA{

private:

    template <class NTYPE2>
    class Node{

    protected:

        NTYPE data;   //Dado a ser armazenado
        Node<NTYPE>* ante; //Ponteiro para o anterior da lista
        Node<NTYPE>* prox; //Ponteiro para o próximo da lista

    public:

        Node(){     //Construtora
            data = 0;
            ante = NULL;
            prox = NULL;
        }
        ~Node(){    //Destrutora
          ante = NULL;
          prox = NULL;
        }

        void setDataValue(const NTYPE a){  //Recebe o dado
            data = a;
        }
        NTYPE getDataValue(){        //Retorna o dado
            return data;
        }

        void setAnteLista(Node<NTYPE>* no){//Define o elemento anterior da lista
            ante = no;
        }
        Node<NTYPE>* getAnteLista(){       //Retorna o ponteiro para o anterior da lista
            return ante;
        }

        void setProxLista(Node<NTYPE>* no){//Define o próximo elemento da lista
            prox = no;
        }
        Node<NTYPE>* getProxLista(){       //Retorna o ponteiro para o próximo da lista
            return prox;
        }

    };

protected:

    Node<NTYPE>* top;   //Topo da lista
    Node<NTYPE>* here;  //Posição atual da lista
    Node<NTYPE>* bottom;//Fundo da lista

public:

    DList(){    //Construtora
        top = NULL;
        here = NULL;
        bottom = NULL;
    }
    ~DList(){   //Destrutora
        mataLista();
        top = NULL;
        here = NULL;
        bottom = NULL;
    }

    void colaNoComeco(NTYPE a);
    void colaNoFinal (NTYPE a);
    int tiraDoComeco ();
    int tiraDoFinal ();

    int imprimeLista();
    void mataLista();

};
