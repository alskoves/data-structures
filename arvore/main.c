#include"arvore.h"

int main(){

    Arvore *arv = constroiArvore ('a',constroiArvore('b',constroiArvoreVazia(),
                            constroiArvore('d',constroiArvoreVazia(),constroiArvoreVazia())),
                            constroiArvore('c',constroiArvore('e',constroiArvoreVazia(),
                            constroiArvoreVazia()),constroiArvore('f',constroiArvoreVazia(),
                            constroiArvoreVazia())));


    char choose, c;
    printf("Imprimir arvore em pre ordem:             1\n");
    printf("Imprimir arvore em in ordem:              2\n");
    printf("Imprimir arvore em pos ordem:             3\n");
    printf("Imprimir arvore em marcadores:            4\n");
    printf("Verificar se caractere pertence a arvore: 5\n");
    printf("Contar quantos nos tem a arvore:          6\n");
    printf("Calcular a altura da arvore:              7\n");
    printf("Contar quantos nos folha tem a arvore:    8\n");
    choose = getchar();
    fflush(stdin);

    switch(choose){

    case '1':

        imprimeArvorePreOrdem(arv);
        break;

    case '2':

        imprimeArvoreInOrdem(arv);
        break;

    case '3':

        imprimeArvorePosOrdem(arv);
        break;

    case '4':

        imprimeArvoreMarcadores(arv);
        break;

    case '5':

        c = getchar();
        pertenceArvore(c, arv) ?
            printf("PERTENCE"):
            printf("NAO PERTENCE");
        break;

    case '6':

        printf("%d nos\n", contaNos(arv));
        break;

    case '7':

        printf("a altura e %d\n", calculaAltura(arv));
        break;

    case '8':

        printf("a arvore tem %d nos folha\n", contaNosFolha(arv));
        break;

    default: break;
    }

    liberaArvore(arv);
}
