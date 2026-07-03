#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>
#include <vector>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"

class Viagem
{
private:
    Transporte *transporte;
    vector<Passageiro *> passageiros;
    Trajeto *trajeto;
    Viagem *proxima;
    int horasEmTransito;
    int distanciaPercorrida;
    int distanciaDesdeUltimaParada;
    bool emAndamento;

public:
    Viagem(Transporte *transporte, vector<Passageiro *> passageiros, Trajeto *trajeto);
    bool iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
};

#endif