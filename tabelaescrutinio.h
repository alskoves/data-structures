#pragma once
//dicionário ou mapa ou vetor associativo

template <class D, class K>
class Dictionary{

    private:
    
        template <class D2, class K2>
        class Entry{
          
            private:
                
                D2* _data;
                K2 _chave;
            
            public:
            
                Entry(D2 data, K2 chave){
                    
                    _data = &data;
                    _chave = chave;
                    
                }
                Entry(){
                    
                    _data = NULL;
                    _chave = 0;
                    
                }
                ~Entry(){
                    
                    _data = NULL;
                    _chave = 0;
                    
                }
            
                void resetData(D2 data){
                    
                    _data = &data;
                    
                }
                void resetKey(K2 chave){
                    
                    _chave = chave;
                    
                }
            
        };

};
