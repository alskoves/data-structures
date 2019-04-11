#pragma once
//código do professor minetto

typedef struct node{

    char data;
    int altura;
    struct node* esq;
    struct node* dir;

} No, Arvore;

Arvore* Inserir(Arvore* a, char chave){

    if(a==NULL)

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
