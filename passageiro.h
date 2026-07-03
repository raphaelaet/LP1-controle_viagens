#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include "cidade.h"

class Passageiro
{
private:
    string nome;
    Cidade *localAtual;

public:
    Passageiro(string nome, Cidade *localAtual);
    string getNome();
    Cidade *getLocalAtual();
    void setLocalAtual(Cidade *local);
};

#endif