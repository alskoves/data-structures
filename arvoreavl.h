#pragma once
//código do professor minetto

typedef struct node{

    char data;
    int altura;
    struct node* esq;
    struct node* dir;

} No, Arvore;

Arvore* Inserir(Arvore* a, char chave){



}

Arvore* Atualizar_fb_esq(Arovre* a){

  a-> altura = Atualizar(a);
  if(Balanceamento(a)==-2){
  
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
  if(Balanceamento(a)==-2){
  
    if(Balanceamento(a->dir) >= 0){
    
        a = Rotacao_simples_esq(a);
    
    }
    else{
    
        a = Rotacao_dupla_esq(a);
    }
  
  }
  return a;

}
