#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{

    char data;
    struct arvore* esq;
    struct arvore* dir;

}Arvore;

Arvore* constroiArvoreVazia();
Arvore* constroiArvore(char data, Arvore* esq, Arvore* dir);

int verificaArvoreVazia(Arvore* arv);
void liberaArvore(Arvore* arv);

int pertenceArvore(char c, Arvore* arv);

void imprimeArvorePreOrdem(Arvore* arv);
void imprimeArvoreInOrdem (Arvore* arv);
void imprimeArvorePosOrdem(Arvore* arv);

void imprimeArvoreMarcadores(Arvore* arv);

int contaNos(Arvore* arv);

int calculaAltura(Arvore* arv);

int contaNosFolha(Arvore* arv);
