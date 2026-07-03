#include "cidade.h"

using namespace std;

Cidade::Cidade(string nome) {
    this->nome = nome;
}

string Cidade::getNome() {
    return this->nome;
}