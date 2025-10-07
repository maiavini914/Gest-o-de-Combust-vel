#include <iostream>
#include <cmath> // para arredondamento

using namespace std;

class Veiculo {
private:
    string modelo = "Golf Sapão";
    double tanqueMaximo = 50.0;     // capacidade total do tanque (litros)
    double combustivelAtual = 50.0; // começa cheio
    double consumo = 12.0;          // consumo médio (km/L)
    double kmRodados = 0.0;         // total de km percorridos

public:
    void abastecer(double litros) {
        combustivelAtual += litros;
        if (combustivelAtual > tanqueMaximo) {
            combustivelAtual = tanqueMaximo;
        }
        cout << "Tanque atualizado: " << combustivelAtual << " L\n";
    }

    void viajar(double km) {
        double necessario = km / consumo;

        if (necessario > combustivelAtual) {
            cout << "Combustível insuficiente para percorrer " << km << " km.\n";
            cout << "Você só pode percorrer até " << combustivelAtual * consumo << " km.\n";
        } else {
            combustivelAtual -= necessario;
            kmRodados += km;
            cout << "Viagem concluída!\n";
            cout << "Km percorridos: " << km << " km\n";
            cout << "Combustível gasto: " << round(necessario * 100) / 100 << " L\n";
            cout << "Combustível restante: " << round(combustivelAtual * 100) / 100 << " L\n";
        }
    }

    void desempenho() {
        double autonomia = combustivelAtual * consumo;
        cout << "\n=== Desempenho do Veículo ===\n";
        cout << "Modelo: " << modelo << endl;
        cout << "Km rodados: " << kmRodados << " km\n";
        cout << "Combustível atual: " << combustivelAtual << " L\n";
        cout << "Autonomia restante: " << autonomia << " km\n";
        cout << "Consumo médio: " << consumo << " km/L\n";
    }
};

int main() {
    Veiculo carro;

    int opcao;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Abastecer\n";
        cout << "2. Viajar\n";
        cout << "3. Mostrar desempenho\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            double litros;
            cout << "Quantos litros deseja abastecer? ";
            cin >> litros;
            carro.abastecer(litros); 
        } 
        else if (opcao == 2) {
            double km;
            cout << "Quantos km deseja percorrer? ";
            cin >> km;
            carro.viajar(km);
        } 
        else if (opcao == 3) {
            carro.desempenho();
        }
    } while (opcao != 0);

    cout << "Encerrando o sistema.\n";
    return 0;
}

