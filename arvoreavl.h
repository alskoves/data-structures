#pragma once
//código do professor minetto

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    char data;
    int altura;
    struct node* esq;
    struct node* dir;

} No, Arvore;

Arvore* Inserir(Arvore* a, char data){

    if(a==NULL){
        
        a = (No*) malloc(sizeof(No));
        a->data = data;
        a->altura = 0;
        a->esq = NULL;
        a->dir = NULL;
        
    }
    
    else if(data < a->data){
        
        a->esq = Inserir(a->esq, data);
        a->altura = Atualizar_fb_esq(a);
        
    }
    
    else{
        
        a->dir = Inserir(a->dir, data);
        a->altura = Atualizar_fb_dir(a);
        
    }

}

Arvore* Atualizar_fb_esq(Arovre* a){

  a-> altura = Atualizar(a);
  if(Balanceamento(a)== -2){
  
    if(Balanceamento(a->esq) >= 0){
    
        a = Rotacao_simples_dir(a);
    
    }
    else{
    
        a = Rotacao_dupla_dir(a);
    }
  
  }
  return a;

}

Arvore* Atualizar_fb_dir(Arovre* a){

  a-> altura = Atualizar(a);
  if(Balanceamento(a)== 2){
  
    if(Balanceamento(a->dir) >= 0){
    
        a = Rotacao_simples_esq(a);
    
    }
    else{
    
        a = Rotacao_dupla_esq(a);
    }
  
  }
  return a;

}

int Altura(Arvore* a){
    
    return (a==NULL ? -1 : a->altura);
    
}

int Balanceamento(Arvore* a){
    
    return(Altura(a->dir) - Altura(a->esq));
    
}

int Atualizar(Arvore* a){
    
    return(maior( Altura(a->esq), Altura(a->dir)) + 1);
    
}

int maior(int a, int b);

    return(a>=b ? a : b);
        
}        
        
Arvore* Rotacao_simples_esq(Arvore* a){
        
    No* t = a->dir;
    a->dir = t->esq;
    t->esq = a;
    a->altura = Atualizar(a);
    t->altura = Atualizar(t);
    return t;
        
}

Arvore* Rotacao_simples_dir(Arvore* a){
        
    No* t = a->esq;
    a->esq = t->dir;
    t->dir = a;
    a->altura = Atualizar(a);
    t->altura = Atualizar(t);
    return t;
        
}

Arvore* Rotacao_dupla_esq(Arvore* a){
    
    a->dir = Rotacao_simples_dir(a->dir);
    return Rotacao_simples_esq(a);
    
}

Arvore* Rotacao_dupla_dir(Arvore* a){
    
    a->esq = Rotacao_simples_esq(a->esq);
    return Rotacao_simples_dir(a);
    
}

Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No *tmp = a;
            a = a->dir;
            free (tmp);
         }
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq;
            free (tmp);
         }
         else {
            No *tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave; 
            tmp->chave = chave;
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}

int main () {

   Arvore *AVL = NULL;

   AVL = inserir (AVL, 'Q');
   /*Complete!!!*/

   //AVL = remover (AVL, 'A');
   //AVL = remover (AVL, 'H');
   //AVL = remover (AVL, 'E');
   //AVL = remover (AVL, 'W');
   //AVL = remover (AVL, 'G');
   //AVL = remover (AVL, 'N');
   //AVL = remover (AVL, 'P');
   //AVL = remover (AVL, 'O');

   imprimir_in_order (AVL, 0);

   return 0;
}
