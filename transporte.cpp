#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"

using namespace std;

Transporte::Transporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade *localAtual) {
    this->nome = nome;
    this->tipo = tipo;
    this->capacidade = capacidade;
    this->velocidade = velocidade;
    this->distancia_entre_descansos = distancia_entre_descansos;
    this->tempo_de_descanso = tempo_de_descanso;
    this->localAtual = localAtual;
    this->tempo_de_descanso_atual = 0;
}

string Transporte::getNome() {
    return this->nome;
}

char Transporte::getTipo() {
    return this->tipo;
}

int Transporte::getCapacidade() {
    return this->capacidade;
}

int Transporte::getVelocidade() {
    return this->velocidade;
}

int Transporte::getDistanciaEntreDescansos() {
    return this->distancia_entre_descansos;
}

int Transporte::getTempoDescanso() {
    return this->tempo_de_descanso;
}

void Transporte::setTempoDescansoAtual(int tempo_de_descanso_atual) {
    this->tempo_de_descanso_atual = tempo_de_descanso_atual;
}

int Transporte::getTempoDescansoAtual() {
    return this->tempo_de_descanso_atual;
}

Cidade *Transporte::getLocalAtual() {
    return this->localAtual;
}

void Transporte::setLocalAtual(Cidade *local) {
    this->localAtual = local;
}