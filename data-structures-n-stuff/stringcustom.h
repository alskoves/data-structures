#pragma once
/// String bonita feita da magia do amor e da amizade

#include<string.h>
#include<stdlib.h>

class StringC{

private:

    char* str;
    int tamanho;

protected:

    void setString(const char* s);
    void setTamanho(const int t);

public:

    StringC(const char* s);
    StringC();
    ~StringC();

    const char* getString();
    const int getTamanho();

    void operator=(const char* s);
    void operator=(StringC& s);
    void operator+(StringC& s);

};
