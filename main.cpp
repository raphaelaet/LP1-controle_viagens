#include <iostream>
#include <vector>
#include "cidade.h"
#include "controladordetransito.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"
#include "viagem.h"

using namespace std;

void pausar() {
    cout << "\n(Pressione Enter para voltar ao menu...)";
    cin.get();
}

int main() {
    ControladorDeTransito ctrl;
    int opcao;

    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1 - Cadastrar Cidade" << endl;
        cout << "2 - Cadastrar Trajeto" << endl;
        cout << "3 - Cadastrar Transporte" << endl;
        cout << "4 - Cadastrar Passageiro" << endl;
        cout << "5 - Iniciar Viagem" << endl;
        cout << "6 - Avancar Horas" << endl;
        cout << "7 - Relatorio de Viagens em Andamento" << endl;
        cout << "8 - Relatorio de Passageiros" << endl;
        cout << "9 - Relatorio de Transportes" << endl;
        cout << "0 - Sair" << endl;
        cout << "=========================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); 
        
        switch (opcao) {
            case 1: {
                string nome;
                cout << "Nome da cidade: ";
                getline(cin, nome);
                ctrl.cadastrarCidade(nome);
                cout << "Cidade cadastrada com sucesso!" << endl;
                pausar();
                break;
            }

            case 2: {
                string origem, destino;
                char tipo;
                int distancia;
                cout << "Cidade de origem: ";
                getline(cin, origem);
                cout << "Cidade de destino: ";
                getline(cin, destino);
                cout << "Tipo (A - Aquatico / T - Terrestre): ";
                cin >> tipo;
                cin.ignore();
                cout << "Distancia (km): ";
                cin >> distancia;
                cin.ignore();
                ctrl.cadastrarTrajeto(origem, destino, tipo, distancia);
                cout << "Trajeto cadastrado com sucesso!" << endl;
                pausar();
                break;
            }

            case 3: {
                string nome, localAtual;
                char tipo;
                int capacidade, velocidade, distanciaDescansos, tempoDescanso;
                cout << "Nome do transporte: ";
                getline(cin, nome);
                cout << "Tipo (A - Aquatico / T - Terrestre): ";
                cin >> tipo;
                cin.ignore();
                cout << "Capacidade de passageiros: ";
                cin >> capacidade;
                cin.ignore();
                cout << "Velocidade (km/h): ";
                cin >> velocidade;
                cin.ignore();
                cout << "Distancia entre descansos (km): ";
                cin >> distanciaDescansos;
                cin.ignore();
                cout << "Tempo de descanso (horas): ";
                cin >> tempoDescanso;
                cin.ignore();
                cout << "Cidade onde o transporte esta atualmente: ";
                getline(cin, localAtual);
                ctrl.cadastrarTransporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual);
                cout << "Transporte cadastrado com sucesso!" << endl;
                pausar();
                break;
            }

            case 4: {
                string nome, localAtual;
                cout << "Nome do passageiro: ";
                getline(cin, nome);
                cout << "Cidade onde o passageiro esta atualmente: ";
                getline(cin, localAtual);
                ctrl.cadastrarPassageiro(nome, localAtual);
                cout << "Passageiro cadastrado com sucesso!" << endl;
                pausar();
                break;
            }

            case 5: {
                string nomeTransporte, origem, destino;
                int qtdPassageiros;
                vector<string> nomesPassageiros;

                cout << "Nome do transporte: ";
                getline(cin, nomeTransporte);
                cout << "Cidade de origem: ";
                getline(cin, origem);
                cout << "Cidade de destino: ";
                getline(cin, destino);
                cout << "Quantidade de passageiros na viagem: ";
                cin >> qtdPassageiros;
                cin.ignore();

                for (int i = 0; i < qtdPassageiros; i++) {
                    string nomePassageiro;
                    cout << "Nome do passageiro " << i + 1 << ": ";
                    getline(cin, nomePassageiro);
                    nomesPassageiros.push_back(nomePassageiro);
                }

                ctrl.iniciarViagem(nomeTransporte, nomesPassageiros, origem, destino);
                pausar();
                break;
            }

            case 6: {
                int horas;
                cout << "Quantas horas deseja avancar? ";
                cin >> horas;
                cin.ignore();
                ctrl.avancarHoras(horas);
                cout << "Tempo avancado em " << horas << " hora(s)." << endl;
                pausar();
                break;
            }

            case 7:
                ctrl.relatarEstado();
                pausar();
                break;

            case 8:
                ctrl.relatarPassageiros();
                pausar();
                break;

            case 9:
                ctrl.relatarTransportes();
                pausar();
                break;

            case 0:
                cout << "Encerrando o sistema..." << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}
