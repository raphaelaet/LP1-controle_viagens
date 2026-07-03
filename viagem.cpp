#include <iostream>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"
#include "viagem.h"

using namespace std;

Viagem::Viagem(Transporte *transporte, vector<Passageiro*> passageiros, Trajeto *trajeto) {
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->trajeto = trajeto;
    horasEmTransito = 0;
    distanciaPercorrida = 0;
    distanciaDesdeUltimaParada = 0;
    emAndamento = false;
}

bool Viagem::iniciarViagem() {
    if (this->transporte->getLocalAtual() == this->trajeto->getOrigem()) {
        emAndamento = true;
        this->transporte->setLocalAtual(nullptr);
        for (int i = 0; i < passageiros.size(); i++) {
            this->passageiros[i]->setLocalAtual(nullptr); 
        }
        return true;
    }
    return false;
}

void Viagem::avancarHoras(int horas) {
    for (int i = 0; i < horas; i++) {
        if (this->transporte->getTempoDescansoAtual() > 0) { // está no período de descanso?
            this->transporte->setTempoDescansoAtual(this->transporte->getTempoDescansoAtual() - 1);
        }
        else { // transporte anda
            distanciaPercorrida += this->transporte->getVelocidade();
            distanciaDesdeUltimaParada += this->transporte->getVelocidade();
            if (this->transporte->getDistanciaEntreDescansos() <= distanciaDesdeUltimaParada) {
                this->transporte->setTempoDescansoAtual(this->transporte->getTempoDescanso());
                distanciaDesdeUltimaParada = distanciaDesdeUltimaParada - this->transporte->getDistanciaEntreDescansos();
            }
            if (distanciaPercorrida >= this->trajeto->getDistancia()) { // transporte chegou ao destino
                emAndamento = false;
                this->transporte->setLocalAtual(this->trajeto->getDestino());
                for (int i = 0; i < passageiros.size(); i++) { // passageiros chegam ao destino
                    this->passageiros[i]->setLocalAtual(this->trajeto->getDestino()); 
                }
                break;
            }
        }

    }
}

void Viagem::relatarEstado() {
    cout << "== Estado da Viagem ==" << endl << endl;
    cout << "Viagem em andamento?";
    if (this->emAndamento) {
        cout << " Sim." << endl;
    }
    else {
        cout << " Não." << endl; 
    } 
    if (this->transporte->getTempoDescansoAtual() > 0) {
        cout << "Status: parado para descanso (" << this->transporte->getTempoDescansoAtual() << " hora(s) restante(s)." << endl;
    }
    else if (this->transporte->getLocalAtual() == nullptr) {
        cout << "Status: na estrada (em transito)" << endl;
    }
    else {
        cout << "Local atual: " << this->transporte->getLocalAtual()->getNome() << endl;
    }
    cout << "Foram percorridos " << distanciaPercorrida << " km. Faltam " 
         << this->trajeto->getDistancia() - distanciaPercorrida 
         << " km para chegar no destino." << endl;
}

bool Viagem::isEmAndamento() {
    return this->emAndamento;
}