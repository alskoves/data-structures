/*Famigerado Desocultatron 3000*/

#include<stdio.h>

int main(){

    fflush(stdin); /*Limpa o buffer do teclado*/

    char c,l[31];

    *l="attrib ?:\*.* /d /s +a -h -r -s\0"; /*Copia o comando de cmd para uma string l*/

    printf("Insira a unidade de disco do seu dispositivo (ex: D, E)\n\n"); /*Recebe do usuário a unidade de disco*/

    c=getchar();

    if(c>='a' && c<='z'){ /*Caso o caractere seja minúsculo*/

        c -= 32; /*Tornamos ele maiúsculo*/

        l[7]=c; /*Substitui o oitavo caractere da string pela unidade de disco entrada pelo usuário*/

        system(l); /*Envia o comando para o cmd*/

    }
    else if(c>'z' || (c<'a' && c>'Z') || c<'A'){ /*Caso não seja uma letra, ou seja uma letra acentuada*/

        printf("Unidade de disco invalida\n\n");

    }
    else{ /*Caso seja maiúsculo*/

        l[7]=c; /*Substitui o oitavo caractere da string pela unidade de disco entrada pelo usuário*/

        system(l); /*Envia o comando para o cmd*/

    }

    return 0;
}

