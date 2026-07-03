#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"
#include "viagem.h"

using namespace std;

class ControladorDeTransito
{
private:
    vector<Cidade *> cidades;
    vector<Trajeto *> trajetos;
    vector<Transporte *> transportes;
    vector<Passageiro *> passageiros;
    vector<Viagem *> viagens;

public:
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);
    void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros,
                       string nomeOrigem, string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado();
    void relatarPassageiros();
    void relatarTransportes();
};

#endif