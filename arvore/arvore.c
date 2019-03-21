#include"arvore.h"

Arvore* constroiArvoreVazia(){

    return NULL;

}
Arvore* constroiArvore(char data, Arvore* esq, Arvore* dir){

    Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
    arv->esq = esq;
    arv->dir = dir;
    arv->data = data;

    return arv;

}

int verificaArvoreVazia(Arvore* arv){

    return (arv == NULL);

}
void liberaArvore(Arvore* arv){

    if(!verificaArvoreVazia(arv)){

        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);

    }

}

int pertenceArvore(char c, Arvore* arv){

    if(!verificaArvoreVazia(arv->esq)){

        if(pertenceArvore(c, arv->esq)){

            return 1;

        }

    }
    if(!verificaArvoreVazia(arv->dir)){

        if(pertenceArvore(c, arv->dir)){

            return 1;

        }

    }

    return arv->data == c;

}

void imprimeArvorePreOrdem(Arvore* arv){

    putchar(arv->data);

    if(!verificaArvoreVazia(arv->esq)){

        imprimeArvorePreOrdem(arv->esq);

    }

    if(!verificaArvoreVazia(arv->dir)){

        imprimeArvorePreOrdem(arv->dir);

    }

}
void imprimeArvoreInOrdem (Arvore* arv){

    if(!verificaArvoreVazia(arv->esq)){

        imprimeArvoreInOrdem(arv->esq);

    }

    putchar(arv->data);

    if(!verificaArvoreVazia(arv->dir)){

        imprimeArvoreInOrdem(arv->dir);

    }

}
void imprimeArvorePosOrdem(Arvore* arv){

    if(!verificaArvoreVazia(arv->esq)){

        imprimeArvorePosOrdem(arv->esq);

    }

    if(!verificaArvoreVazia(arv->dir)){

        imprimeArvorePosOrdem(arv->dir);

    }

    putchar(arv->data);

}

void imprimeArvoreMarcadores(Arvore* arv){

    printf("<%c",arv->data);

    if(!verificaArvoreVazia(arv->esq)){

        imprimeArvoreMarcadores(arv->esq);

    }
    else{

        printf("<>");

    }

    if(!verificaArvoreVazia(arv->dir)){

        imprimeArvoreMarcadores(arv->dir);

    }
    else{

        printf("<>");

    }

    putchar('>');

}

int contaNos(Arvore* arv){

    int cnt = 1;

    if(!verificaArvoreVazia(arv->esq)){

        cnt += contaNos(arv->esq);

    }

    if(!verificaArvoreVazia(arv->dir)){

        cnt += contaNos(arv->dir);

    }

    return cnt;

}

int calculaAltura(Arvore* arv){

    int e = 0, d = 0;

    if(verificaArvoreVazia(arv->esq) &&
       verificaArvoreVazia(arv->dir)){

       return 1;

    }
    if(!verificaArvoreVazia(arv->esq)){

        e += calculaAltura(arv->esq);

    }
    if(!verificaArvoreVazia(arv->dir)){

        d += calculaAltura(arv->dir);

    }
    return e >= d ? e + 1 : d + 1;

}

int contaNosFolha(Arvore* arv){

    int cnt = 0;

    if(verificaArvoreVazia(arv->esq) &&
       verificaArvoreVazia(arv->dir)){

        return 1;

       }
    if(!verificaArvoreVazia(arv->esq)){

        cnt += contaNosFolha(arv->esq);

    }
    if(!verificaArvoreVazia(arv->dir)){

        cnt += contaNosFolha(arv->dir);

    }

    return cnt;

}
