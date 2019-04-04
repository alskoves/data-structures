#pragma once
//árvores de busca binária

template<class T>
class Arvore{

protected:

    T data;
    Arvore<T>* esq;
    Arvore<T>* dir;
    
protected:
    
    mataArvore(Arvore<T>* arv){
     
        if(arv->esq != NULL){
            
            mataArvore(esq);
            
        }
        if(arv->dir != NULL){
            
            mataArvore(dir);
            
        }
        if(arv->esq == NULL && arv->esq == NULL){
            
            
        
    }
    
public:
    
    Arvore(T1 d){
        
        data = d;
        esq = NULL;
        dir = NULL;
    
    }
    
    Arvore(){
        
        esq = NULL;
        dir = NULL;
           
    }
    
    ~Arvore(){
        
        mataArvore(this);   
        
    }
    

};
