#include"stringcustom.h"

StringC::StringC(const char* s){

    setString(s);
    setTamanho(strlen(s));

}

StringC::StringC(){

    setString("\0");
    setTamanho(1);

}
StringC::~StringC(){

    free(str);

}

void StringC::setString(const char* s){



}

void StringC::setTamanho(const int t){



}

const char* StringC::getString(){

    return str;

}
const int   StringC::getTamanho(){

    return tamanho;

}

void StringC::operator=(const char* s){

    setString(s);
    setTamanho(strlen(s));

}

void StringC::operator=(StringC& s){

    setString(s.getString());
    setTamanho(s.getTamanho());

}

void StringC::operator+(StringC& s){

    strcat(str,s.getString());
    setTamanho(tamanho+s.getTamanho()-1);

}

