#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pedido {
    int id;
    string descricao;
    bool finalizado;
    double valor;
    string feedback;
};

vector<Pedido> pedidos;
int proximoId = 1;

void adicionarPedido(const string& descricao, double valor) {
    Pedido novoPedido = {proximoId++, descricao, false, valor, ""};
    pedidos.push_back(novoPedido);
    cout << "Pedido adicionado com sucesso!\n";
}

void finalizarPedido(int id) {
    for (auto& pedido : pedidos) {
        if (pedido.id == id && !pedido.finalizado) {
            pedido.finalizado = true;
            cout << "Pedido finalizado com sucesso!\n";
            return;
        }
    }
    cout << "Pedido não encontrado ou já finalizado.\n";
}

void visualizarPedidos(bool finalizados) {
    cout << (finalizados ? "Pedidos Antigos:\n" : "Pedidos em Andamento:\n");
    for (const auto& pedido : pedidos) {
        if (pedido.finalizado == finalizados) {
            cout << "ID: " << pedido.id << ", Descrição: " << pedido.descricao << ", Valor: " << pedido.valor << "\n";
        }
    }
}

void gerenciarEstoque() {
    // Implementar funcionalidade de gerenciamento de estoque
    cout << "Funcionalidade de gerenciamento de estoque ainda não implementada.\n";
}

void visualizarCapitalPorPedido() {
    for (const auto& pedido : pedidos) {
        cout << "ID: " << pedido.id << ", Valor: " << pedido.valor << "\n";
    }
}

void visualizarFeedback() {
    for (const auto& pedido : pedidos) {
        if (!pedido.feedback.empty()) {
            cout << "ID: " << pedido.id << ", Feedback: " << pedido.feedback << "\n";
        }
    }
}

void adicionarFeedback(int id, const string& feedback) {
    for (auto& pedido : pedidos) {
        if (pedido.id == id) {
            pedido.feedback = feedback;
            cout << "Feedback adicionado com sucesso!\n";
            return;
        }
    }
    cout << "Pedido não encontrado.\n";
}

int main() {
    int opcao;
    do {
        cout << "Menu:\n";
        cout << "01 - Pedidos em Andamento\n";
        cout << "02 - Pedidos Antigos\n";
        cout << "03 - Caixa de Entrada/Saída Produtos\n";
        cout << "04 - Caixa de Entrada/Saída Capital por pedido\n";
        cout << "05 - FeedBack Pedidos\n";
        cout << "06 - Adicionar Pedido\n";
        cout << "07 - Finalizar Pedido\n";
        cout << "08 - Adicionar Feedback\n";
        cout << "09 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                visualizarPedidos(false);
                break;
            case 2:
                visualizarPedidos(true);
                break;
            case 3:
                gerenciarEstoque();
                break;
            case 4:
                visualizarCapitalPorPedido();
                break;
            case 5:
                visualizarFeedback();
                break;
            case 6: {
                string descricao;
                double valor;
                cout << "Descrição do pedido: ";
                cin.ignore();
                getline(cin, descricao);
                cout << "Valor do pedido: ";
                cin >> valor;
                adicionarPedido(descricao, valor);
                break;
            }
            case 7: {
                int id;
                cout << "ID do pedido a ser finalizado: ";
                cin >> id;
                finalizarPedido(id);
                break;
            }
            case 8: {
                int id;
                string feedback;
                cout << "ID do pedido: ";
                cin >> id;
                cout << "Feedback: ";
                cin.ignore();
                getline(cin, feedback);
                adicionarFeedback(id, feedback);
                break;
            }
            case 9:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 9);

    return 0;
}
