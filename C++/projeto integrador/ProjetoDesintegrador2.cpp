#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <random>

using namespace std;

// estruturas 
struct Pedido {
    int id;
    string descricao;
    bool finalizado;
    double valor;
    string feedback;
};

struct dadosProduto {
    string nome;
    double valor;
    int quantidadeProduto;
};

struct Empresa {
    string nome;
    string cnpj;
    string endereco;
    string telefone;
    string email;
    vector<dadosProduto> produto;
};

struct venda {
    int id_venda;
    string nomeEmpresa;
    string cnpjEmpresa;
    string emailEmpresa;
    string enderecoEmpresa;
    string telefoneEmpresa;
    vector<dadosProduto> produtos;
    string feedback;
};

// gerador de codigo aleatorio de produto.
string generateRandomCode(int length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, characters.size() - 1);

    std::string random_code;
    for (int i = 0; i < length; ++i) {
        random_code += characters[distrib(gen)];
    }

    return random_code;
}

vector<Pedido> pedidos;
vector<Empresa> empresas;
vector<venda> vendas;
int proximoId = 1;

void loginCliente() {
    cout << "===== Interface de Login para Cliente =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "LoginCliente1" && password == "102024") {
            cout << "Login bem-sucedido para Cliente!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Cliente. Por favor, tente novamente mais tarde." << endl;
}

void loginEmpresa() {
    cout << "===== Interface de Login para Empresa =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "StartupFilaexpress" && password == "062024") {
            cout << "Login bem-sucedido para Empresa!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Empresa. Por favor, tente novamente mais tarde." << endl;
}

void loginOwner() {
    cout << "===== Interface de Login para Owner =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "OwnerFfe" && password == "FE2024") {
            cout << "Login bem-sucedido para Owner!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Owner. Por favor, tente novamente mais tarde." << endl;
}

// pedidos
void adicionarPedido(const string& descricao, double valor) {
    Pedido novoPedido = { proximoId++, descricao, false, valor, "" };
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

// CheckOut e pagamento
int processoCheckout() {

    int interacao1 = 1;
    int interacao2 = 0;
    int interacao3 = -1;
    int verificacao = 0;
    int pagamento = 0;

    string cartao_debito[4] = { "", "", "", "" };
    string cartao_credito[4] = { "", "", "", "" };
    string cartao_vr[4] = { "", "", "", "" };

    while (interacao1 != 0) {

        double taxa_app = 0.05;
        string itens[3] = { "Combo Big Mac", "Coca-Cola Grande", "Batata frita Media" };
        double price[3] = { 36.99, 12.99, 10.99 };

        cout << "Seja bem vindo!\n" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "\nCarrinho Atual: " << endl;
        cout << "Item: " << itens[0] << "           Preco: " << price[0] << endl;
        cout << "Item: " << itens[1] << "        Preco: " << price[1] << endl;
        cout << "Item: " << itens[2] << "      Preco: " << price[2] << endl;
        cout << "Taxa Adicional Integracao aplicativo:   " << taxa_app * 100 << "%\n" << endl;
        taxa_app = (price[0] + price[1] + price[2]) * taxa_app;
        double total = (price[0] + price[1] + price[2]) + taxa_app;
        cout << "---------------------------------------------" << endl;
        cout << "Total: R$" << fixed << setprecision(2) << total << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Confirmar compra e prosseguir para pagamento?" << endl;
        cout << "[0] Nao     [1] Sim" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> interacao1;

        system("cls");

        if (interacao1 == 1) {
            while (interacao2 != 6) {
                cout << "---------------------------------------------" << endl;
                cout << "Insira a forma de Pagamento:" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "[1] Cartao Debito" << endl;
                cout << "[2] Cartao de Credito" << endl;
                cout << "[3] Cartao VR" << endl;
                cout << "[4] PIX" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "[5] Conferir Cartoes" << endl;
                cout << "[6] Cancelar Compra" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "Insira sua escolha: ";
                cin >> interacao2;
                system("cls");

                if (interacao2 == 1 && cartao_debito[0] != "") {
                    cout << "--------------- CARTAO DEBITO ---------------" << endl;
                    cout << "Confirme os dados . . .\n" << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    cout << "---------------------------------------------" << endl;
                    cout << "Nome: " << cartao_debito[0] << endl;
                    cout << "Numero Cartao: " << cartao_debito[1] << endl;
                    cout << "Validade Cartao: " << cartao_debito[2] << endl;
                    cout << "CVV Cartao: " << cartao_debito[3] << endl;
                    cout << "---------------------------------------------\n" << endl;
                    cout << "Proceder com Pagamento: " << endl;
                    cout << "[0] NAO     [1] SIM" << endl;
                    cout << "Insira sua escolha: ";
                    cin >> verificacao;
                    system("cls");

                    if (verificacao == 1) {
                        cout << "------------------------------" << endl;
                        cout << "Processando Pagamento . . ." << endl;
                        cout << "------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(3));
                        system("cls");
                        pagamento = 1;
                        break;
                    } else if (verificacao == 0) {
                        cout << "---------------------------------------------" << endl;
                        cout << "Deletando Dados do Cartao . . ." << endl;
                        cout << "---------------------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(5));
                        system("cls");
                        cartao_debito[0] = { "" };
                        cartao_debito[1] = { "" };
                        cartao_debito[2] = { "" };
                        cartao_debito[3] = { "" };
                        cout << "---------------------------------------------" << endl;
                        cout << "Nome: " << cartao_debito[0] << endl;
                        cout << "Numero Cartao: " << cartao_debito[1] << endl;
                        cout << "Validade Cartao: " << cartao_debito[2] << endl;
                        cout << "CVV Cartao: " << cartao_debito[3] << endl;
                        cout << "---------------------------------------------\n" << endl;
                        system("pause");
                        system("cls");
                        interacao2 = 0;
                    }
                } else if (interacao2 == 1 && cartao_debito[0] == "") {
                    cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
                    system("pause");
                    system("cls");
                    cout << "--------------- CARTAO DEBITO ---------------" << endl;
                    cout << "Insira o nome registrado no cartao: ";
                    cin.ignore();
                    getline(cin, cartao_debito[0]);
                    cout << "Insira o numero registrado no cartao: ";
                    getline(cin, cartao_debito[1]);
                    cout << "Insira a validade registrada no cartao: ";
                    cin >> cartao_debito[2];
                    cout << "Insira o CVV registrado no cartao: ";
                    cin >> cartao_debito[3];
                    cout << "---------------------------------------------\n" << endl;

                    system("cls");
                    cout << "Registrando Dados . . .";
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                }

                if (interacao2 == 2 && cartao_credito[0] != "") {
                    cout << "--------------- CARTAO CREDITO ---------------" << endl;
                    cout << "Confirme os dados . . .\n" << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    cout << "----------------------------------------------" << endl;
                    cout << "Nome: " << cartao_credito[0] << endl;
                    cout << "Numero Cartao: " << cartao_credito[1] << endl;
                    cout << "Validade Cartao: " << cartao_credito[2] << endl;
                    cout << "CVV Cartao: " << cartao_credito[3] << endl;
                    cout << "----------------------------------------------\n" << endl;
                    cout << "Proceder com Pagamento: " << endl;
                    cout << "[0] NAO     [1] SIM" << endl;
                    cout << "----------------------------------------------\n" << endl;
                    cout << "Insira sua escolha: ";
                    cin >> verificacao;
                    system("cls");

                    if (verificacao == 1) {
                        cout << "------------------------------" << endl;
                        cout << "Processando Pagamento . . ." << endl;
                        cout << "------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(3));
                        system("cls");
                        pagamento = 1;
                        break;
                    } else if (verificacao == 0) {
                        cout << "---------------------------------------------" << endl;
                        cout << "Deletando Dados do Cartao . . ." << endl;
                        cout << "---------------------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(5));
                        system("cls");
                        cartao_credito[0] = { "" };
                        cartao_credito[1] = { "" };
                        cartao_credito[2] = { "" };
                        cartao_credito[3] = { "" };
                        cout << "---------------------------------------------" << endl;
                        cout << "Nome: " << cartao_credito[0] << endl;
                        cout << "Numero Cartao: " << cartao_credito[1] << endl;
                        cout << "Validade Cartao: " << cartao_credito[2] << endl;
                        cout << "CVV Cartao: " << cartao_credito[3] << endl;
                        cout << "---------------------------------------------\n" << endl;
                        system("pause");
                        system("cls");
                        interacao2 = 0;
                    }
                } else if (interacao2 == 2 && cartao_credito[0] == "") {
                    cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
                    system("pause");
                    system("cls");
                    cout << "--------------- CARTAO CREDITO ----------------" << endl;
                    cout << "Insira o nome registrado no cartao: ";
                    cin.ignore();
                    getline(cin, cartao_credito[0]);
                    cout << "Insira o numero registrado no cartao: ";
                    getline(cin, cartao_credito[1]);
                    cout << "Insira a validade registrada no cartao: ";
                    cin >> cartao_credito[2];
                    cout << "Insira o CVV registrado no cartao: ";
                    cin >> cartao_credito[3];
                    cout << "----------------------------------------------\n" << endl;

                    system("cls");
                    cout << "Registrando Dados . . .";
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                }

                if (interacao2 == 3 && cartao_vr[0] != "") {
                    cout << "--------------- CARTAO VALE ALIMENTACAO ---------------" << endl;
                    cout << "Confirme os dados . . .\n" << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    cout << "----------------------------------------------" << endl;
                    cout << "Nome: " << cartao_vr[0] << endl;
                    cout << "Numero Cartao: " << cartao_vr[1] << endl;
                    cout << "Validade Cartao: " << cartao_vr[2] << endl;
                    cout << "CVV Cartao: " << cartao_vr[3] << endl;
                    cout << "----------------------------------------------\n" << endl;
                    cout << "Proceder com Pagamento: " << endl;
                    cout << "[0] NAO     [1] SIM" << endl;
                    cout << "----------------------------------------------\n" << endl;
                    cout << "Insira sua escolha: ";
                    cin >> verificacao;
                    system("cls");

                    if (verificacao == 1) {
                        cout << "------------------------------" << endl;
                        cout << "Processando Pagamento . . ." << endl;
                        cout << "------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(3));
                        system("cls");
                        pagamento = 1;
                        break;
                    } else if (verificacao == 0) {
                        cout << "---------------------------------------------" << endl;
                        cout << "Deletando Dados do Cartao . . ." << endl;
                        cout << "---------------------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(5));
                        system("cls");
                        cartao_vr[0] = { "" };
                        cartao_vr[1] = { "" };
                        cartao_vr[2] = { "" };
                        cartao_vr[3] = { "" };
                        cout << "---------------------------------------------" << endl;
                        cout << "Nome: " << cartao_vr[0] << endl;
                        cout << "Numero Cartao: " << cartao_vr[1] << endl;
                        cout << "Validade Cartao: " << cartao_vr[2] << endl;
                        cout << "CVV Cartao: " << cartao_vr[3] << endl;
                        cout << "---------------------------------------------\n" << endl;
                        system("pause");
                        system("cls");
                        interacao2 = 0;
                    }
                } else if (interacao2 == 3 && cartao_vr[0] == "") {
                    cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
                    system("pause");
                    system("cls");
                    cout << "--------------- CARTAO VALE ALIMENTACAO ----------------" << endl;
                    cout << "Insira o nome registrado no cartao: ";
                    cin.ignore();
                    getline(cin, cartao_vr[0]);
                    cout << "Insira o numero registrado no cartao: ";
                    getline(cin, cartao_vr[1]);
                    cout << "Insira a validade registrada no cartao: ";
                    cin >> cartao_vr[2];
                    cout << "Insira o CVV registrado no cartao: ";
                    cin >> cartao_vr[3];
                    cout << "-------------------------------------------------------\n" << endl;

                    system("cls");
                    cout << "Registrando Dados . . .";
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                }

                if (interacao2 == 4) {
                    cout << "--------------- PIX ---------------" << endl;
                    cout << "Insira sua Preferencia: " << endl;
                    cout << "[0] QR CODE    [1] CHAVE PIX" << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "Sua Escolha: ";
                    cin >> interacao3;
                    system("cls");

                    if (interacao3 == 0) {
                        cout << "-----------------------------------\n" << endl;
                        cout << "Leia o QR Code apresentado a seguir\n" << endl;
                        cout << "-----------------------------------" << endl;
                        this_thread::sleep_for(chrono::seconds(3));
                        system("cls");

                        cout << "----------------------------------------------------" << endl;
                        cout << "------@@@@@@@@@@@@@--@@@@@@@@@@-=@@@@@@@@@@@@@=-----" << endl;
                        cout << "------@@---------@@--@@@@-=@@@@-=@@---------@@=-----" << endl;
                        cout << "------@@-*@@@@@%-@@----@@@@@@---=@@-%@@@@@+-@@=-----" << endl;
                        cout << "------@@-*@@@@@%-@@----@@=+@@@@-=@@-%@@@@@+-@@=-----" << endl;
                        cout << "------@@-*@@@@@%-@@--@@=----=@@-=@@-%@@@@@+-@@=-----" << endl;
                        cout << "------@@--=====--@@--@@=-@@--==-=@@--=====--@@=-----" << endl;
                        cout << "------@@@@@@@@@@@@@--@@=-@@-=@@-=@@@@@@@@@@@@@=-----" << endl;
                        cout << "---------------------@@@@@@@@-----------------------" << endl;
                        cout << "------@@@@@#---*@@@--@@@@@@@@@@@@@@@@@*---%@@@------" << endl;
                        cout << "------@@###%@@@%###--@@@@@@#####%@@#@@@@+-*#@@=-----" << endl;
                        cout << "------##---#@@@@@@@--@@%###-----=@@@@@@#%@=-@@=-----" << endl;
                        cout << "------##---#@@@@@@@--@@=-----##-=@@@@@@#%@=-@@------" << endl;
                        cout << "------@@###@@@-+#####@@%#---=@@#####%@@@#-*#--------" << endl;
                        cout << "------@@@@@@@#-*@@@@@@@@@--**-=@@@@@@*@@@*@@--------" << endl;
                        cout << "------=============--@@+==+@@=+@@@@@@@@@@@+-==------" << endl;
                        cout << "------@@@@@@@@@@@@@--++@@@@@@@@@@+#@@@@@@@+-@@------" << endl;
                        cout << "------@@--=====--@@--@@+=@@@@=+@@@@===@@#--=--------" << endl;
                        cout << "------@@-*@@@@@%-@@----@@@@@@@@@@@@@@@@@#-@@--------" << endl;
                        cout << "------@@-*@@@@@%-@@--==@@@@------===@@@@@@*===------" << endl;
                        cout << "------@@-*@@@@@%-@@--@@=--------=@@@@@@@@@@@@@=-----" << endl;
                        cout << "------@@---------@@--@@@@---=@@---#@@@@@#-----------" << endl;
                        cout << "------@@@@@@@@@@@@@--@@@@@@-----=@@---%@#---@@=-----" << endl;
                        cout << "----------------------------------------------------" << endl;

                        this_thread::sleep_for(chrono::seconds(5));
                        system("cls");

                        for (int i = 6; i > 0; i--) {
                            cout << "-----------------------------------\n" << endl;
                            cout << "Conferindo Pagamento . . .  " << "\nTempo Restantes: " << i << " Segundos\n" << endl;
                            cout << "-----------------------------------\n" << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                            pagamento = 1;
                            system("cls");
                        }
                        break;
                    }
                    if (interacao3 == 1) {
                        string cnpj = "32.968.893/0001-50";
                        string email = "mcdonals@gmail.com";
                        string telefone = "(42) 9 9999-9999";

                        cout << "-----------------------------------" << endl;
                        cout << "Chaves Pix Cadastradas: dcta478j-196l-03fm-t6gh-4298er7845m2" << endl;
                        cout << "-----------------------------------" << endl;
                        cout << "CNPJ: " << cnpj << endl;
                        cout << "Telefone: " << telefone << endl;
                        cout << "E-mail: " << email << endl;
                        cout << "-----------------------------------" << endl;
                        system("pause");
                        system("cls");

                        for (int i = 6; i > 0; i--) {
                            cout << "-----------------------------------\n" << endl;
                            cout << "Conferindo Pagamento . . .  " << "\nTempo Restantes: " << i << " Segundos\n" << endl;
                            cout << "-----------------------------------\n" << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                            pagamento = 1;
                            system("cls");
                        }
                        break;
                    }
                }

                if (interacao2 == 5) {
                    cout << "Cartoes Registrados: \n" << endl;

                    if (cartao_debito[0] != "") {
                        cout << "--------------- CARTAO DEBITO ---------------" << endl;
                        cout << "Nome: " << cartao_debito[0] << endl;
                        cout << "Numero Cartao: " << cartao_debito[1] << endl;
                        cout << "Validade Cartao: " << cartao_debito[2] << endl;
                        cout << "CVV Cartao: " << cartao_debito[3] << endl;
                        cout << "---------------------------------------------\n" << endl;
                        interacao2 = 0;
                    }
                    if (cartao_credito[0] != "") {
                        cout << "--------------- CARTAO CREDITO ---------------" << endl;
                        cout << "Nome: " << cartao_credito[0] << endl;
                        cout << "Numero Cartao: " << cartao_credito[1] << endl;
                        cout << "Validade Cartao: " << cartao_credito[2] << endl;
                        cout << "CVV Cartao: " << cartao_credito[3] << endl;
                        cout << "----------------------------------------------\n" << endl;
                        interacao2 = 0;
                    }
                    if (cartao_vr[0] != "") {
                        cout << "----------- CARTAO VALE ALIMENTACAO -----------" << endl;
                        cout << "Nome: " << cartao_vr[0] << endl;
                        cout << "Numero Cartao: " << cartao_vr[1] << endl;
                        cout << "Validade Cartao: " << cartao_vr[2] << endl;
                        cout << "CVV Cartao: " << cartao_vr[3] << endl;
                        cout << "----------------------------------------------\n" << endl;
                        interacao2 = 0;
                    }

                    if (cartao_credito[0] == "" && cartao_debito[0] == "" && cartao_vr[0] == "") {
                        cout << "Nenhum Cartao Registrado\n" << endl;
                    }
                    system("pause");
                    system("cls");
                }
                if (interacao2 < 0 || interacao2 > 6) {
                    cout << "Escolha Invalida! Insira Novamente" << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    system("cls");
                }
            }
            break;
        }
        if (interacao1 < 0 || interacao1 > 1) {
            cout << "Escolha Invalida! Insira Novamente" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            system("cls");
        }
    }

    if (pagamento == 1) {
        double price[3] = { 36.99, 12.99, 10.99 };
        double taxa_app = 0.05;
        taxa_app = (price[0] + price[1] + price[2]) * taxa_app;
        double total = (price[0] + price[1] + price[2]) + taxa_app;

        cout << " --------------- COMPROVANTE ---------------\n" << endl;
        cout << "Pagamento Concluido        HORARIO: 18:23:55\n\n" << endl;
        cout << "Total: R$" << fixed << setprecision(2) << total << endl;

        if (cartao_credito[0] != "") {
            cout << "Nome: " << cartao_credito[0] << endl;
            cout << "Forma de Pagamento: Credito\n\n" << endl;
        } else if (cartao_debito[0] != "") {
            cout << "Nome: " << cartao_debito[0] << endl;
            cout << "Forma de Pagamento: Debito\n\n" << endl;
        } else if (cartao_vr[0] != "") {
            cout << "Nome: " << cartao_vr[0] << endl;
            cout << "Forma de Pagamento: VR\n\n" << endl;
        }
        // codigo de retirada
        int code_length = 6;
        string random_code = generateRandomCode(code_length);
        cout << "Apresente o seguinte codigo para retirada: " << random_code << endl;
        cout << "Tempo para Retirada: 15:00 Minutos" << endl;
        cout << "Obrigado Pela Preferencia!!!!" << endl;
        cout << " -------------------------------------------\n" << endl;
        return 0;

    }

    cout << "Compra Cancelada!!" << endl;
    cout << "Ate a Proxima . . ." << endl;
    return 0;
}


int main() {
    int escolha;

    do {
        cout << "\nSelecione o tipo de usuario:\n";
        cout << "[1] Cliente\n";
        cout << "[2] Empresa\n";
        cout << "[3] Owner\n";
        cout << "[0] Sair\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
        case 1:
            loginCliente();
            processoCheckout();
            break;
        case 2:
            loginEmpresa();
            // Funcionalidades da empresa
            break;
        case 3: {
            loginOwner();
            int opcao;
            do {
                cout << "------------------------ | FURA-FILA EXPRESS | -------------------------\n";
                cout << "| 01 | - Pedidos em Andamento\n";
                cout << "__________________________________________________\n";
                cout << "| 02 | - Pedidos Antigos\n";
                cout << "__________________________________________________\n";
                cout << "| 03 | - Caixa de Entrada/Saída Produtos\n";
                cout << "__________________________________________________\n";
                cout << "| 04 | - Caixa de Entrada/Saída Capital por pedido\n";
                cout << "__________________________________________________\n";
                cout << "| 05 | - FeedBack Pedidos\n";
                cout << "__________________________________________________\n";
                cout << "| 06 | - Adicionar Pedido\n";
                cout << "__________________________________________________\n";
                cout << "| 07 | - Finalizar Pedido\n";
                cout << "__________________________________________________\n";
                cout << "| 08 | - Adicionar Feedback\n";
                cout << "__________________________________________________\n";
                cout << "| 09 | - Cadastro de Empresas\n";
                cout << "__________________________________________________\n";
                cout << "| 10 | - Cadastro de Produtos\n";
                cout << "__________________________________________________\n";
                cout << "| 11 | - Consulta de Empresas\n";
                cout << "__________________________________________________\n";
                cout << "| 12 | - Simulador de Vendas\n";
                cout << "__________________________________________________\n";
                cout << "| 13 | - Fluxo de Caixa\n";
                cout << "__________________________________________________\n";
                cout << "| 14 | - Excluir Venda\n"; // Nova opção
                cout << "__________________________________________________\n";
                cout << "| 15 | - Sair\n";
                cout << "__________________________________________________\n";
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
                case 9: {
                    bool continuarLoop = true;
                    do {
                        Empresa empresa;
                        system("cls");
                        cout << "_______________________ | CADASTRO EMPRESA | ____________________________" << endl;
                        cout << endl;
                        cout << "NOME EMPRESA: ";
                        cin.ignore();
                        getline(cin, empresa.nome);
                        cout << "___________________________________________________\n" << endl;
                        cout << "CNPJ: ";
                        getline(cin, empresa.cnpj);
                        cout << "___________________________________________________\n" << endl;
                        cout << "BAIRRO: ";
                        getline(cin, empresa.endereco);
                        cout << "___________________________________________________\n" << endl;
                        cout << "TELEFONE: ";
                        getline(cin, empresa.telefone);
                        cout << "___________________________________________________\n" << endl;
                        cout << "E-MAIL: ";
                        getline(cin, empresa.email);
                        cout << "___________________________________________________\n" << endl;

                        empresas.push_back(empresa);

                        system("cls");

                        cout << "___________________ | EMPRESA CADASTRADA COM SUCESSO! | ________________________" << endl;
                        cout << endl;
                        cout << "NOVO CADASTRO?" << endl;
                        cout << "[1]" << " SIM " << " " << "[0]" << "NAO " << endl;
                        cin >> continuarLoop;

                        system("cls");

                    } while (continuarLoop);
                    break;
                }
                case 10: {
                    bool continuarLoop = true;
                    do {
                        if (empresas.empty()) {
                            system("cls");
                            cout << "______________________________ | NENHUMA EMPRESA CADASTRADA! | ____________________________" << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        system("cls");
                        int tamanho_vector = empresas.size();
                        continuarLoop = true;

                        cout << "________________________________ | ESCOLHA EMPRESA | _______________________________\n"
                             << endl;
                        for (int i = 0; i < tamanho_vector; i++) {
                            cout << "| " << i + 1 << " | " << empresas[i].nome << endl;
                            cout << "_________________________________________________\n"
                                 << endl;
                        }
                        cout << "| 0 | SAIR" << endl;
                        cout << "_________________________________________________\n"
                             << endl;

                        cout << "INDICE EMPRESA: ";
                        int indice_empresa;
                        cin >> indice_empresa;

                        int decrementa_indice = indice_empresa - 1;

                        if (decrementa_indice >= 0 && decrementa_indice < tamanho_vector) {
                            dadosProduto novoProduto;
                            system("cls");
                            cout << "___________________________ | CADASTRO PRODUTO | __________________________\n"
                                 << endl;
                            cout << "NOME PRODUTO: ";
                            cin.ignore();
                            getline(cin, novoProduto.nome);
                            cout << "____________________________________________________________________\n"
                                 << endl;
                            cout << "VALOR PRODUTO: "
                                 << "R$ ";
                            cin >> novoProduto.valor;
                            cout << "________________________________________________________________\n"
                                 << endl;
                            cout << "QUANTIDADE PRODUTO: ";
                            cin >> novoProduto.quantidadeProduto;

                            empresas[decrementa_indice].produto.push_back(novoProduto);

                            system("cls");

                            cout << "______________________ | PRODUTO ADICIONADO COM SUCESSO! | _______________________________\n"
                                 << endl;
                            cout << "DESEJA ADICIONAR NOVO PRODUTO?" << endl;
                            cout << "[1] SIM "
                                 << " "
                                 << "[0] NAO" << endl;
                            cin >> continuarLoop;

                        } else if (indice_empresa == 0) {
                            continuarLoop = false;

                        } else {
                            system("cls");
                            cout << "EMPRESA NAO ENCONTRADA!" << endl;
                            system("pause");
                            system("cls");
                        }
                    } while (continuarLoop);
                    break;
                }

                case 11: {
                    bool continuarLoop = true;
                    do {
                        if (empresas.empty()) {
                            system("cls");
                            cout << "\nNENHUMA EMPRESA CADASTRADA!" << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        system("cls");
                        int tamanho_vector = empresas.size();
                        continuarLoop = true;

                        cout << "______________________________ | EMPRESAS CADASTRADAS | _______________________________________\n"
                             << endl;
                        for (int i = 0; i < tamanho_vector; i++) {
                            cout << "| " << i + 1 << " | " << empresas[i].nome << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                        }

                        cout << "| 0 | SAIR" << endl;

                        cout << "__________________________________________________________________________\n"
                             << endl;
                        cout << endl;

                        cout << " INDICE EMPRESA: ";
                        int indice_empresa;
                        cin >> indice_empresa;

                        int decrementa_indice = indice_empresa - 1;

                        if (decrementa_indice >= 0 && decrementa_indice < tamanho_vector) {
                            system("cls");
                            cout << "_______________________________ | DADOS DA EMPRESA | ______________________________\n"
                                 << endl;
                            cout << "NOME: " << empresas[decrementa_indice].nome << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                            cout << "CNPJ: " << empresas[decrementa_indice].cnpj << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                            cout << "BAIRRO: " << empresas[decrementa_indice].endereco << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                            cout << "TEL: " << empresas[decrementa_indice].telefone << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                            cout << "E-MAIL: " << empresas[decrementa_indice].email << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;

                            cout << "_______________________________ | PRODUTOS | ______________________________\n"
                                 << endl;
                            if (empresas[decrementa_indice].produto.empty()) {
                                cout << "Nenhum produto cadastrado para esta empresa.\n";
                            } else {
                                for (const auto& p : empresas[decrementa_indice].produto) {
                                    cout << "Nome: " << p.nome << ", Valor: R$" << p.valor << ", Quantidade: " << p.quantidadeProduto << endl;
                                }
                            }
                            cout << "________________________________________________________________\n"
                                 << endl;

                            system("pause");

                        } else if (indice_empresa == 0) {
                            continuarLoop = false;

                        } else {
                            system("cls");
                            cout << "EMPRESA NAO ENCONTRADA COM ESSE INDICE. TENTE NOVAMENTE!" << endl;
                            system("pause");
                            system("cls");
                        }
                    } while (continuarLoop);
                    break;
                }

                case 12: { // Simulador de Vendas
                    bool voltarMenuInicial = true; // Declaração movida para o escopo do case

                    do {
                        if (empresas.empty()) {
                            system("cls");
                            cout << "NENHUMA EMPRESA CADASTRADA!" << endl;
                            system("pause");
                            system("cls");
                            break; // Sai do loop do simulador se não houver empresas
                        }

                        system("cls");
                        int tamanho_vector = empresas.size();

                        cout << "___________________________________ | LISTA DE EMPRESAS | _______________________________ \n"
                             << endl;
                        for (int i = 0; i < tamanho_vector; i++) {
                            cout << " | " << i + 1 << " | " << empresas[i].nome << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;
                        }
                        cout << "| 0 | SAIR" << endl;
                        cout << "\n________________________________________________________________" << endl;

                        cout << "\nINDICE EMPRESA : ";
                        int indice_empresa;
                        cin >> indice_empresa;

                        int decrementa_indice = indice_empresa - 1;

                        if (decrementa_indice >= 0 && decrementa_indice < tamanho_vector) {
                            int tamanho_vector_produtos = empresas[decrementa_indice].produto.size();
                            if (tamanho_vector_produtos == 0) {
                                system("cls");
                                cout << "ESTA EMPRESA NÃO POSSUI PRODUTOS CADASTRADOS" << endl;
                                system("pause");
                                system("cls");
                                break; // Sai do loop do simulador se não houver produtos
                            }

                            cout << "_________________________________ | LISTA DE PRODUTOS | _______________________________________\n"
                                 << endl;
                            for (int i = 0; i < tamanho_vector_produtos; i++) {
                                cout << " | " << i + 1 << " | " << empresas[decrementa_indice].produto[i].nome << endl;
                                cout << "________________________________________________________________\n"
                                     << endl;
                            }
                            cout << " | 0 | SAIR" << endl;
                            cout << "________________________________________________________________\n"
                                 << endl;

                            cout << "INDICE DO PRODUTO: ";
                            int indice_produto;
                            cin >> indice_produto;

                            indice_produto = indice_produto - 1;

                            if (indice_produto >= 0 && indice_produto < tamanho_vector_produtos) {
                                bool ir_para_carrinho = true;

                                system("cls");

                                cout << "IR PARA CARRINHO DE COMPRAS?" << endl;
                                cout << "[1] SIM "
                                     << " "
                                     << "[0] NAO" << endl;
                                cin >> ir_para_carrinho;

                                if (ir_para_carrinho) {
                                    venda novaVenda;
                                    bool simular = true;

                                    // Adicionar dados da empresa à venda
                                    novaVenda.nomeEmpresa = empresas[indice_empresa - 1].nome;
                                    novaVenda.cnpjEmpresa = empresas[indice_empresa - 1].cnpj;
                                    novaVenda.emailEmpresa = empresas[indice_empresa - 1].email;
                                    novaVenda.enderecoEmpresa = empresas[indice_empresa - 1].endereco;
                                    novaVenda.telefoneEmpresa = empresas[indice_empresa - 1].telefone;

                                    // Adicionar o primeiro produto ao carrinho
                                    novaVenda.produtos.push_back(empresas[indice_empresa - 1].produto[indice_produto]);

                                    // Loop para adicionar mais produtos à venda
                                    while (true) {
                                        system("cls");
                                        cout << "______________________ | CARRINHO DE COMPRAS | _________________________\n"
                                             << endl;
                                        int tamanho_vector_novaVenda_produtos = novaVenda.produtos.size();

                                        for (int i = 0; i < tamanho_vector_novaVenda_produtos; i++) {
                                            cout << "ITEM " << i + 1 << endl;
                                            cout << "NOME PRODUTO: " << novaVenda.produtos[i].nome << endl;
                                            cout << "VALOR PRODUTO: R$ " << novaVenda.produtos[i].valor << endl;
                                            cout << "QUANTIDADE: " << novaVenda.produtos[i].quantidadeProduto << endl;
                                            cout << "------------------------------------------------" << endl;
                                        }

                                        cout << "ADICIONAR MAIS PRODUTOS?" << endl;
                                        cout << "[1] SIM "
                                             << " "
                                             << "[0] NAO" << endl;
                                        int adicionarProduto;
                                        cin >> adicionarProduto;

                                        if (adicionarProduto == 1) {

                                            cout << "INDICE DO PRODUTO: ";
                                            int indice_produto;
                                            cin >> indice_produto;

                                            indice_produto = indice_produto - 1;

                                            if (indice_produto >= 0 && indice_produto < tamanho_vector_produtos) {
                                                novaVenda.produtos.push_back(empresas[indice_empresa - 1].produto[indice_produto]);
                                            } else {
                                                system("cls");
                                                cout << "INDICE INVALIDO!" << endl;
                                                system("pause");
                                                system("cls");
                                            }
                                        } else {
                                            break; // Sai do loop de adição de produtos
                                        }
                                    }

                                    // Obter feedback após adicionar produtos
                                    cout << "FEEDBACK: ";
                                    cin.ignore();
                                    getline(cin, novaVenda.feedback);

                                    cout << endl;

                                    cout << "SIMULAR VENDA?" << endl;
                                    cout << "[1] Sim "
                                         << " [0] Nao" << endl;
                                    cin >> simular;

                                    if (simular) {
                                        random_device rd;
                                        mt19937 mt(rd());
                                        uniform_int_distribution<int> dist(0, 99);

                                        int numGerados[10];
                                        int numeros = 0;

                                        for (int i = 0; i < 10; i++) {
                                            int num_aleatorio = dist(mt);
                                            numGerados[i] = num_aleatorio;
                                            numeros += numGerados[i];
                                        }

                                        system("pause");

                                        novaVenda.id_venda = numeros;

                                        vendas.push_back(novaVenda); // Adiciona a venda ao vetor

                                        system("cls");

                                        double valor_total_venda = 0;
                                        for (const auto& produto : novaVenda.produtos) {
                                            valor_total_venda += produto.valor * produto.quantidadeProduto;
                                        }

                                        cout << "--------------------- COMPROVANTE DA VENDA -------------------------" << endl;
                                        cout << "NOME EMPRESA: " << empresas[decrementa_indice].nome << "        " << "CNPJ: " << empresas[decrementa_indice].cnpj << endl;
                                        cout << "PRODUTOS:" << endl;
                                        for (const auto& produto : novaVenda.produtos) {
                                            cout << "  - " << produto.nome << " (QUANTIDADE: " << produto.quantidadeProduto << ", VALOR: R$ " << produto.valor << ")" << endl;
                                        }
                                        cout << "VALOR TOTAL: R$ " << valor_total_venda << endl;
                                        cout << "ID DA VENDA: " << novaVenda.id_venda << endl;

                                        system("pause");

                                        voltarMenuInicial = false; // Sair do loop do simulador
                                    } else {
                                        system("cls");
                                        cout << "VENDA NAO EXECUTADA!" << endl;
                                        system("pause");
                                        system("cls");
                                    }
                                } else {
                                    break; // Sair do loop do carrinho
                                }
                            } else if (indice_produto == -1) {
                                // Fazer algo se o usuário escolher sair da lista de produtos
                            } else {
                                system("cls");
                                cout << "PRODUTO NÃO ENCONTRADO, TENTE NOVAMENTE!" << endl;
                                system("pause");
                                system("cls");
                            }
                        } else if (indice_empresa == 0) {
                            voltarMenuInicial = false; // Sair do loop do simulador
                        } else {
                            system("cls");
                            cout << "ESSA EMPRESA NAO ESTA CADASTRADA. TENTE NOVAMENTE!" << endl;
                            system("pause");
                            system("cls");
                        }
                    } while (voltarMenuInicial); // Loop do simulador
                    break;
                }

                case 13: {
                    bool continuarLoop = true;
                    do {
                        if (vendas.empty()) {
                            system("cls");
                            cout << "NENHUMA VENDA REALIZADA!" << endl;
                            system("pause");
                            break;
                        }

                        system("cls");
                        cout << "__________________________ | FLUXO DE CAIXA | ______________________________\n"
                             << endl;

                        int tamanho_vendas = vendas.size();
                        double valor_total_vendas = 0;
                        for (int i = 0; i < tamanho_vendas; i++) {
                            for (const auto& produto : vendas[i].produtos) {
                                valor_total_vendas += produto.valor * produto.quantidadeProduto;
                            }
                        }

                        double taxa_fura = 0.15;
                        double custo_vendas = 0.05;
                        double lucro_final = (valor_total_vendas * taxa_fura) - (valor_total_vendas * taxa_fura * custo_vendas);
                        double valor_total = valor_total_vendas * taxa_fura;
                        double ticket_medio = valor_total / tamanho_vendas;

                        cout << "NUMERO DE VENDAS: " << tamanho_vendas << endl;
                        cout << "_________________________________________________\n"
                             << endl;
                        cout << "VALOR TOTAL FURA-FILA: "
                             << "R$ " << valor_total << endl;
                        cout << "_________________________________________________\n"
                             << endl;
                        cout << "CUSTO TOTAL: "
                             << "R$ " << valor_total_vendas * taxa_fura * custo_vendas << endl;
                        cout << "_________________________________________________\n"
                             << endl;
                        cout << "LUCRO LIQUIDO TOTAL: "
                             << "R$ " << lucro_final << endl;
                        cout << "_________________________________________________\n"
                             << endl;
                        cout << "TICKET MEDIO: "
                             << "R$ " << ticket_medio << endl;
                        cout << "_________________________________________________\n"
                             << endl;

                        cout << "[0] VOLTAR MENU INICIAL" << endl;
                        cin >> continuarLoop;

                    } while (continuarLoop);
                    break;
                }

                case 14: // Excluir Venda
                    if (vendas.empty()) {
                        system("cls");
                        cout << "NENHUMA VENDA REALIZADA!" << endl;
                        system("pause");
                        system("cls");
                    } else {
                        system("cls");

                        int tamanho_vector_vendas = vendas.size();
                        bool excluirVenda;
                        int indiceExcluir;

                        cout << "---------- VENDAS REALIZADAS ------------" << endl;

                        for (int i = 0; i < tamanho_vector_vendas; i++) {
                            cout << "| " << i + 1 << " | ID: " << vendas[i].id_venda << endl;
                        }

                        cout << "[1] EXCLUIR VENDA" << endl;
                        cout << "[0] VOLTAR" << endl;
                        cin >> excluirVenda;

                        if (excluirVenda) {
                            cout << "DIGITE O INDICE DA VENDA: ";
                            cin >> indiceExcluir;

                            if (indiceExcluir > 0 && indiceExcluir <= tamanho_vector_vendas) {
                                vendas.erase(vendas.begin() + (indiceExcluir - 1));
                                cout << "ITEM EXCLUIDO COM SUCESSO!" << endl;
                                system("pause");
                                system("cls");
                            } else {
                                system("cls");
                                cout << "INDICE INVALIDO!" << endl;
                                system("pause");
                                system("cls");
                            }
                        }
                    }
                    break;

                case 15:
                    cout << "Saindo...\n";
                    break;
                default:
                    cout << "Opção inválida. Tente novamente.\n";
                    break;
                }
            } while (opcao != 15);
            break;
        }
        case 0:
            cout << "Encerrando o programa." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}