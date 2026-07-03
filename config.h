#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe Cidade
class Cidade
{
private:
    string nome;

public:
    Cidade(string nome);
    string getNome();
};
// Classe Trajeto
class Trajeto
{
private:
    Cidade *origem;
    Cidade *destino;
    char tipo; // 'A' para Aquático, 'T' para Terrestre
    int distancia;

public:
    Trajeto(Cidade *origem, Cidade *destino, char tipo, int distancia);
    Cidade *getOrigem();
    Cidade *getDestino();
    char getTipo();
    int getDistancia();
};
// Classe Transporte
class Transporte
{
private:
    string nome;
    char tipo;                     // 'A' para Aquático, 'T' para Terrestre
    int capacidade;                // número de passageiros
    int velocidade;                // km/h
    int distancia_entre_descansos; // em km
    int tempo_de_descanso;         // em horas
    int tempo_de_descanso_atual;   // em horas
    Cidade *localAtual;

public:
    Transporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade *localAtual);
    string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade *getLocalAtual();
    void setLocalAtual(Cidade *local);
};
// Classe Passageiro
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
// Classe Viagem
class Viagem
{
private:
    Transporte *transporte;
    vector<Passageiro *> passageiros;
    Cidade *origem;
    Cidade *destino;
    Viagem *proxima;
    int horasEmTransito;
    bool emAndamento;

public:
    Viagem(Transporte *transporte, vector<Passageiro *> passageiros, Cidade *origem, Cidade *destino);
    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
};
// Classe ControladorDeTransito
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
};

#endif