#pragma once

template <class T>
class Arvore{

private:

    template <class T2>
    class No{
    
    private:
        
        int key;
        T2 data;
        No* leftson;
        No* rightson;
        
    public:
    
        No(){
            key = 1;
            data = 0;
            leftson = NULL;
            rightson = NULL;
        }
        No(T2 d){
            key = 1;
            data = d;
            leftson = NULL;
            rightson = NULL;
        }
        ~No(){
            key = -1;
            data = 0;
            leftson = NULL;
            rightson = NULL;
        }
        
        void setKey(int k){
            key = k;
        }
        int getKey(){
            return key;
        }
        
        void setData(T2 d){
            data = d;
        }
        T2 getData(){
            return data;
        }
        
        void setLeftSon(No* n){
            leftson = n;
        }
        No* getLeftSon(){
            return leftson;
        }
        
        void setRightSon(No* n){
            rightson = n;
        }
        No* getRightSon(){
            return rightson;
        }
        
    }
    
    No* raiz;
    
public:

    Arvore(){
        raiz = NULL;
    }
    Arvore(T data){
        raiz = (No*) malloc(sizeof(No));
        raiz->setData(data);
    }
    ~Arvore(){
        raiz = NULL;
    }
    
    void insert(T data){}
    void remove(int id){}
    void present(){}
    
};
