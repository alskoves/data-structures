#pragma once
//Listas simples e duplas

#include<stdlib.h>
#include<stdio.h>

/******************************************************************************/

template <class NTYPE>
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

/******************************************************************************/
/******************************************************************************/

namespace ListaDupla{///Classe e Funções-Método de Listas Duplas

template <class NTYPE>
class DList{

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

    void colaNoComeco(NTYPE a){

        Node<NTYPE>* no = (Node<NTYPE>*) malloc(sizeof(Node<NTYPE>));  //Cria um nó novo

        if(top == NULL && bottom == NULL){    //Se a lista estiver vazia

            no->setProxLista(NULL);//Como só tem ele, não aponta para frente
            no->setAnteLista(NULL);//Nem para trás
            no->setDataValue(a);   //Recebe o dado
            top = no;              //O novo nó se torna o topo da lista
            bottom = no;           //O novo nó também se torna o fundo da lista

        }
        else{

            here = top;             //Atual recebe o topo da lista
            no->setProxLista(here); //O antigo topo se torna o próximo do novo topo
            no->setAnteLista(NULL); //Como é o topo, anterior aponta para NULL
            no->setDataValue(a);    //Recebe o dado
            here->setAnteLista(no); //Antigo topo aponta para trás para o novo topo
            top = no;               //Substitui o topo da lista pelo nó novo
            here = NULL;            //Aterra o atual

        }


    }
    void colaNoFinal (NTYPE a){

        Node<NTYPE>* no = (Node<NTYPE>*) malloc(sizeof(Node<NTYPE>));  //Cria um nó novo

        if(top == NULL && bottom == NULL){     //Se a lista estiver vazia

            no->setProxLista(NULL);//Como só tem ele, não aponta para frente
            no->setAnteLista(NULL);//Nem para trás
            no->setDataValue(a);   //Recebe o dado
            top = no;              //O novo nó se torna o topo da lista
            bottom = no;           //O novo nó também se torna o fundo da lista

        }
        else{

            here = bottom;         //Atual recebe o fundo da lista
            no->setAnteLista(here);//O antigo fundo se torna o anterior do nó novo
            no->setProxLista(NULL);//Como é o fundo, próximo aponta para NULL
            no->setDataValue(a);   //Recebe o dado
            here->setProxLista(no);//Antigo fundo aponta para frente para o novo fundo
            bottom = no;           //Substitui o fundo da lista pelo nó novo
            here = NULL;           //Aterra o atual

        }

    }
    int tiraDoComeco(){ //Retorna 1 se a lista estiver vazia

        if(top == NULL){
            return 1;
        }
        else{

            here = top;                 //Recebe o primeiro elemento da lista
            top = top->getProxLista();  //O segundo elemento se torna o novo primeiro
            top->setAnteLista(NULL);    //O primeiro aponta para NULL
            free(here);                 //Destroi o antigo primeiro
            here = NULL;                //Aterra o atual
            return 0;

        }

    }
    int tiraDoFinal (){ //Retorna 1 se a lista estiver vazia

        if(top == NULL){
            return 1;
        }
        else{

            here = bottom;                  //Recebe o último elemento da lista
            bottom = bottom->getAnteLista();//O penúltimo elemento se torna o novo último
            bottom->setProxLista(NULL);     //O último elemento aponta pra NULL
            free(here);                     //Destroi o antigo último
            here = NULL;                    //Aterra o atual
            return 0;

        }

    }

    int imprimeLista(){ //Imprime a lista ; retorna 1 se a lista estiver vazia

        here = top;
        if(top == NULL){
            return 1;
        }
        else{

            int i = 2;
            printf("Topo: Endereço %p; Valor %d\n",top,top->getDataValue());
            while(here->getProxLista() != NULL){

                here = here->getProxLista();
                printf("%d: Endereço %p; Valor %d\n",i,here,here->getDataValue());
                i++;

            }

        }
        here = NULL;
        fflush(stdin);
        getchar();
        return 0;

    }
    void mataLista(){   //Destroi a lista

        here = top->getProxLista();     //Define o atual como o segundo elemento
        while(here != NULL){            //Enquanto não estiver no final da lista

            free(top);                  //Libera o topo
            top = here;                 //Desloca o topo uma posição para frente
            here = top->getProxLista(); //Desloca o atual uma posição para frente

        }//Enquanto não estiver no final da lista, vai destruindo ela
        free(top);      //Quando chegar no final, destroi o final
        here = NULL;    //Aterra o atual

    }

};
}
/******************************************************************************/
/******************************************************************************/

namespace ListaSimples{///Classe e Funções-método de Listas Simples

template <class NTYPE>
class SList{

protected:

    Node<NTYPE>* top; //Topo da lista
    Node<NTYPE>* here;//Elemento atual da lista

public:

    SList(){    //Construtora
        top = NULL;
        here = NULL;
    }
    ~SList(){   //Destrutora
        mataLista();
        top = NULL;
        here = NULL;
    }

    void colaNoComeco(NTYPE a){

        Node<NTYPE>* no = (Node<NTYPE>*) malloc(sizeof(Node<NTYPE>)); //Cria um novo nó

        if(top == NULL){ //Se a lista estiver vazia

            no->setProxLista(NULL); //Define o nó como o último da lista
            no->setDataValue(a);    //Define o valor do nó
            top = no;               //Define o nó como o topo da lista

        }
        else{

            here = top;             //Desloca o antigo topo uma posição para frente
            top = no;               //Coloca o novo elemento no topo
            top->setProxLista(here);//Faz o novo topo apontar para o antigo topo
            top->setDataValue(a);   //Define o valor do elemento no topo
            here = NULL;            //Aterra o ponteiro

        }

    }
    void colaNoFinal (NTYPE a){

        Node<NTYPE>* no = (Node<NTYPE>*) malloc(sizeof(Node<NTYPE>)); //Cria um novo nó

        if(top == NULL){ //Se a lista estiver vazia

            no->setProxLista(NULL); //Define o nó como o último da lista
            no->setDataValue(a);    //Define o valor do nó
            top = no;               //Define o nó como o topo da lista

        }
        else{

            for(here = top ; here->getProxLista() != NULL;
                here = here->getProxLista());
                                    //Move o ponteiro até o final da lista
            here->setProxLista(no); //Coloca o novo nó na frente do antigo último
            no->setDataValue(a);    //Define o valor do nó
            no->setProxLista(NULL); //Define o nó como último da lista
            here = NULL;            //Aterra o ponteiro

        }

    }
    int tiraDoComeco(){

        if(top == NULL){
            return 1;
        }
        else{

            here = top->getProxLista(); //Recebe o segundo elemento da lista
            free(top);                  //Destroi o topo
            top = here;                 //Antigo segundo elemento se torna o topo
            here = NULL;                //Aterra o ponteiro
            return 0;

        }

    }
    int tiraDoFinal (){

        if(top == NULL){
            return 1;
        }
        else{

            Node<NTYPE>* aux; //Ponteiro auxiliar
            aux = top;  //Auxiliar recebe o topo
            here = aux;

            while(aux->getProxLista()!= NULL){
                            //Enquanto não estiver no último elemento da lista
                here = aux;               //Segue o auxiliar
                aux = aux->getProxLista();//Auxiliar caminha um elemento para frente

            }
            free(aux);
            here->setProxLista(NULL);
            here = NULL;
            return 0;

        }

    }

    int imprimeLista(){//Imprime a lista

        here = top; //Aponta para o topo
        if(top == NULL){
            return 1;
        }
        else{

            int i = 2;  //O primeiro nó é o topo, então
            printf("Topo: Endereço %p; Valor %d\n",top,top->getDataValue());
                //Imprime o endereço e o valor do topo da lista
            while(here->getProxLista() != NULL){
                    //Enquanto não estiver no final da lista
                here = here->getProxLista();    //Se desloca para frente na lista
                printf("%d: Endereço %p; Valor %d\n",i,here,here->getDataValue());
                    //Imprime o endereço e o valor do nó atual
                i++;

            }

        }
        here = NULL;    //Aterra o ponteiro
        fflush(stdin);  //Limpa o buffer
        getchar();      //Para o programa enquanto o usuário não entrar algo
        return 0;

    }
    void mataLista(){   //Destroi a lista

        while(top->getProxLista() != NULL){
                                        //Enquanto não estiver no final da lista
            here = top;                 //Recebe o topo da lista
            top = top->getProxLista();  //Deslica o topo uma posição para frente
            free(here);                 //Destroi o antigo topo

        }
        free(top);  //Destroi o topo
        top = NULL; //Aterra o topo
        here = NULL;//Aterra o ponteiro

    }
};
}
/*****************************************************************************/
