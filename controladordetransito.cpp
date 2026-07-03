#include <iostream>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"
#include "viagem.h"
#include "controladordetransito.h"

using namespace std;

void ControladorDeTransito::cadastrarCidade(string nome) {
    Cidade* c = new Cidade(nome);
    this->cidades.push_back(c);
}

void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia) {
    Cidade* origemEncontrada = nullptr;
    Cidade* destinoEncontrado = nullptr;
    for (int i = 0; i < this->cidades.size(); i++) {
        if (this->cidades[i]->getNome() == nomeOrigem) {
            origemEncontrada = this->cidades[i];
        }
    }
    for (int i = 0; i < this->cidades.size(); i++) {
        if (this->cidades[i]->getNome() == nomeDestino) {
            destinoEncontrado = this->cidades[i];
        }
    }
    Trajeto* t = new Trajeto(origemEncontrada, destinoEncontrado, tipo, distancia);
    this->trajetos.push_back(t);
}

void ControladorDeTransito::cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, string localAtual) {
    Cidade* localAtualEncontrado = nullptr;
    for (int i = 0; i < this->cidades.size(); i++) {
        if (this->cidades[i]->getNome() == localAtual) {
            localAtualEncontrado = this->cidades[i];
        }
    }
    Transporte* t = new Transporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, localAtualEncontrado);
    this->transportes.push_back(t);
}

void ControladorDeTransito::cadastrarPassageiro(string nome, string localAtual) {
    Cidade* localAtualEncontrado = nullptr;
    for (int i = 0; i < this->cidades.size(); i++) {
        if (this->cidades[i]->getNome() == localAtual) {
            localAtualEncontrado = this->cidades[i];
        }
    }
    Passageiro* p = new Passageiro(nome, localAtualEncontrado);
    this->passageiros.push_back(p);
}

void ControladorDeTransito::iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino) {
    Transporte* transporteEncontrado = nullptr;
    Trajeto* trajetoEncontrado = nullptr;
    vector<Passageiro*> passageirosNaViagem;
    for (int i = 0; i < this->transportes.size(); i++) {
        if (this->transportes[i]->getNome() == nomeTransporte) {
            transporteEncontrado = this->transportes[i];
        }
    }
    for (int i = 0; i < this->trajetos.size(); i++) {
        if (this->trajetos[i]->getOrigem()->getNome() == nomeOrigem && this->trajetos[i]->getDestino()->getNome() == nomeDestino) {
            trajetoEncontrado = this->trajetos[i];
        }
    }
    for (int i = 0; i < nomesPassageiros.size(); i++) {
        for (int j = 0; j < this->passageiros.size(); j++) {
            if (nomesPassageiros[i] == this->passageiros[j]->getNome()) {
                passageirosNaViagem.push_back(this->passageiros[j]);
            }
        }
    }

    if (transporteEncontrado == nullptr || trajetoEncontrado == nullptr) {
        cout << "Erro: transporte ou trajeto nao encontrado." << endl;
        return;
    }

    if ((int)passageirosNaViagem.size() > transporteEncontrado->getCapacidade()) {
        cout << "Erro: capacidade do transporte excedida." << endl;
        return;
    }

    Viagem* v = new Viagem(transporteEncontrado, passageirosNaViagem, trajetoEncontrado);
    if (v->iniciarViagem()) {
        this->viagens.push_back(v);
    } 
    else {
        cout << "Erro: transporte nao esta na cidade de origem." << endl;
        delete v;
    }
}

void ControladorDeTransito::avancarHoras(int horas) {
    for (int i = 0; i < this->viagens.size(); i++) {
        if (this->viagens[i]->isEmAndamento()) {
            this->viagens[i]->avancarHoras(horas);
        }
    }
}

void ControladorDeTransito::relatarEstado() {
    for (int i = 0; i < this->viagens.size(); i++) {
        if (this->viagens[i]->isEmAndamento()) {
            cout << "=== Viagem " << i + 1 << " ===" << endl;
            this->viagens[i]->relatarEstado();
        }
    }
}

void ControladorDeTransito::relatarPassageiros() {
    for (int i = 0; i < this->passageiros.size(); i++) {
        Passageiro* p = this->passageiros[i];
        cout << p->getNome() << ": ";
        if (p->getLocalAtual() != nullptr) {
            cout << "em " << p->getLocalAtual()->getNome() << endl;
        }
        else {
            cout << "em transito" << endl;
        }
    }
}

void ControladorDeTransito::relatarTransportes() {
    for (int i = 0; i < this->transportes.size(); i++) {
        Transporte* t = this->transportes[i];
        cout << t->getNome() << ": ";
        if (t->getLocalAtual() != nullptr) {
            cout << "em " << t->getLocalAtual()->getNome() << endl;
        }
        else {
            cout << "em transito" << endl;
        }
    }
}
