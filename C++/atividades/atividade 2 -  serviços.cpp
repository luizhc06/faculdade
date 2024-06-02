#include <iostream>
using namespace std;

// Constantes para os preços dos quartos e taxa de imposto
const double preco_quarto_pequeno = 100.0;
const double preco_quarto_grande = 150.0;
const double taxa_imposto = 0.06;
const int dias_validade_orcamento = 30;

int main() {
    cout << "\n------Serviço de Limpeza de Carpetes Frank------";
    cout << "\nOpções: ";
    cout << "\nR$100,00 o quarto pequeno";
    cout << "\nR$150,00 o quarto grande";

    int quartos_pequenos, quartos_grandes;

    cout << "\nDigite o número de quartos pequenos: ";
    cin >> quartos_pequenos;

    cout << "\nDigite o número de quartos grandes: ";
    cin >> quartos_grandes;

    // Calculo do custo total antes dos impostos
    double custo_total = (quartos_pequenos * preco_quarto_pequeno) + (quartos_grandes * preco_quarto_grande);

    // Calculo do valor do imposto
    double imposto = custo_total * taxa_imposto;

    // Calculo do orçamento total
    double orcamento_total = custo_total + imposto;

    // Orçamento
    cout << "\nOrçamento para serviço de limpeza de carpetes:\n";
    cout << "Número de quartos pequenos: " << quartos_pequenos << endl;
    cout << "Número de quartos grandes: " << quartos_grandes << endl;
    cout << "Preço por quarto pequeno: R$" << preco_quarto_pequeno << endl;
    cout << "Preço por quarto grande: R$" << preco_quarto_grande << endl;
    cout << "Custo: R$" << custo_total << endl;
    cout << "Imposto: R$" << imposto << endl;
    cout << "==========================================" << endl;
    cout << "Orçamento Total: R$" << orcamento_total << endl;
    cout << "Orçamento válido por " << dias_validade_orcamento << " dias" << endl;

    return 0;
}