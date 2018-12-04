#pragma once

template <class D, class K>
class Dictionary{

    private:

        template <class K2>
        class Key{

            private:

                K2 _chave;

            public:

                Key(){}
                ~Key(){}

                void setKey(K2 c){
                    _chave = c;
                }
                K2 getKey(){
                    return _chave;
                }

                void operator = (K2 c){
                    setKey(c);
                }
                void operator = (Key k){
                    setKey(k.getKey());
                }

        };

        template <class E>
        class Entry{

            private:

                E* _data;
                long _key;

            public:

                Entry(){

                    _data = NULL;
                    _key = 0;

                }

        };

};
