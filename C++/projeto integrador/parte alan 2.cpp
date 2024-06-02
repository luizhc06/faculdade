#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

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
    vector<dadosProduto> produtos; // Vetor para armazenar os produtos da venda
    string feedback;
};

int main() {
    vector<Empresa> empresas;
    vector<venda> vendas;

    int escolha_usuario;
    int tamanho_vector, tamanho_vector_produtos;
    int indice_empresa;
    bool continuarLoop = 1;
    bool voltarMenuInicial = true;
    bool relatorios = false;

    cout << boolalpha;

    do {
        system("cls");

        cout << "------------------------ | FURA-FILA EXPRESS | -------------------------" << endl;
        cout << endl;
        cout << "| 1 | CADASTRO EMPRESAS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 2 | CADASTRO PRODUTOS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 3 | CONSULTA EMPRESAS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 4 | SIMULADOR DE VENDAS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 5 | FLUXO DE CAIXA" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 6 | FEEDBACKS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 7 | EXCLUIR VENDAS" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "| 8 | SAIR" << endl;
        cout << "_________________________________________________\n" << endl;
        cout << "ESCOLHA: ";
        cin >> escolha_usuario;

        switch (escolha_usuario) {
        case 1: // Cadastro de empresas
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
                cin.ignore();
                getline(cin, empresa.cnpj);
                cout << "___________________________________________________\n" << endl;
                cout << "BAIRRO: ";
                cin.ignore();
                getline(cin, empresa.endereco);
                cout << "___________________________________________________\n" << endl;
                cout << "TELEFONE: ";
                cin.ignore();
                getline(cin, empresa.telefone);
                cout << "___________________________________________________\n" << endl;
                cout << "E-MAIL: ";
                cin.ignore();
                getline(cin, empresa.email);
                cout << "___________________________________________________\n" << endl;

                empresas.push_back(empresa);

                system("cls");

                cout << "___________________ | EMPRESA CADASTRADA COM SUCESSO! | ________________________" << endl;

                cout << endl;

                cout << "NOVO CADASTRO?" << endl;
                cout << "[1]" << " SIM " << " " << "[0]" << " NAO " << endl;
                cin >> continuarLoop;

                system("cls");

            } while (continuarLoop);
            break;

        case 2: // Cadastro de produtos
            do {
                if (empresas.empty()) {
                    system("cls");

                    cout << "______________________________ | NENHUMA EMPRESA CADASTRADA! | ____________________________" << endl;

                    system("pause");
                    system("cls");
                } else {
                    system("cls");

                    tamanho_vector = empresas.size();

                    continuarLoop = 1;

                    cout << "________________________________ | ESCOLHA EMPRESA | _______________________________\n" << endl;

                    for (int i = 0; i < tamanho_vector; i++) {
                        cout << "| " << i + 1 << " | " << empresas[i].nome << endl;
                        cout << "_________________________________________________\n" << endl;
                    }

                    cout << "| 0 | SAIR" << endl;

                    cout << "_________________________________________________\n" << endl;

                    cout << "INDICE EMPRESA: ";
                    cin >> indice_empresa;

                    int decrementa_indice = indice_empresa - 1;

                    if (decrementa_indice >= 0 && decrementa_indice < tamanho_vector) {
                        dadosProduto novoProduto;

                        system("cls");

                        cout << "___________________________ | CADASTRO PRODUTO | __________________________\n" << endl;

                        cout << "NOME PRODUTO: ";
                        cin.ignore();
                        getline(cin, novoProduto.nome);
                        cout << "____________________________________________________________________\n" << endl;
                        cout << "VALOR PRODUTO: " << "R$ ";
                        cin >> novoProduto.valor;
                        cout << "________________________________________________________________\n" << endl;
                        cout << "QUANTIDADE PRODUTO: ";
                        cin >> novoProduto.quantidadeProduto;

                        empresas[decrementa_indice].produto.push_back(novoProduto);

                        system("cls");

                        cout << "______________________ | PRODUTO ADICIONADO COM SUCESSO! | _______________________________\n" << endl;

                        cout << "DESEJA ADICIONAR NOVO PRODUTO?" << endl;
                        cout << "[1] SIM " << " " << "[0] NAO" << endl;
                        cin >> continuarLoop;
                    } else if (indice_empresa == 0) {
                        continuarLoop = 0;
                    } else {
                        system("cls");

                        cout << "EMPRESA NAO ENCONTRADA!" << endl;

                        system("pause");
                        system("cls");
                    }
                }
            } while (continuarLoop);

            break;

        case 3:
            do {
                if (empresas.empty()) {
                    system("cls");
                    cout << "\nNENHUMA EMPRESA CADASTRADA!" << endl;
                    system("pause");
                    system("cls");
                } else {
                    system("cls");

                    tamanho_vector = empresas.size();

                    continuarLoop = 1;

                    cout << "______________________________ | EMPRESAS CADASTRADAS | _______________________________________\n" << endl;

                    for (int i = 0; i < tamanho_vector; i++) {
                        cout << "| " << i + 1 << " | " << empresas[i].nome << endl;
                        cout << "________________________________________________________________\n" << endl;
                    }

                    cout << "| 0 | SAIR" << endl;

                    cout << "__________________________________________________________________________\n" << endl;

                    cout << endl;

                    cout << " INDICE EMPRESA: ";
                    cin >> indice_empresa;

                    int decrementa_indice = indice_empresa - 1;

                    if (decrementa_indice >= 0 && decrementa_indice <= tamanho_vector) {
                        system("cls");

                        cout << "_______________________________ | DADOS DA EMPRESA | ______________________________\n" << endl;

                        cout << "NOME: " << empresas[indice_empresa - 1].nome << endl;
                        cout << "________________________________________________________________\n" << endl;
                        cout << "CNPJ: " << empresas[indice_empresa - 1].cnpj << endl;
                        cout << "________________________________________________________________\n" << endl;
                        cout << "BAIRRO: " << empresas[indice_empresa - 1].endereco << endl;
                        cout << "________________________________________________________________\n" << endl;
                        cout << "TEL: " << empresas[indice_empresa - 1].telefone << endl;
                        cout << "________________________________________________________________\n" << endl;
                        cout << "E-MAIL: " << empresas[indice_empresa - 1].email << endl;
                        cout << "________________________________________________________________\n" << endl;

                        system("pause");
                    } else if (indice_empresa == 0) {
                        continuarLoop = 0;
                    } else {
                        system("cls");

                        cout << "EMPRESA NAO ENCONTRADA COM ESSE INDICE. TENTE NOVAMENTE!" << endl;

                        system("pause");
                        system("cls");
                    }
                }
            } while (continuarLoop);
            break;

        case 4: // Simulador de Vendas
            do {
                if (empresas.empty()) {
                    system("cls");
                    cout << "NENHUMA EMPRESA CADASTRADA!" << endl;
                    system("pause");
                    system("cls");
                } else {
                    Empresa empresa;
                    system("cls");

                    tamanho_vector = empresas.size();
                    tamanho_vector_produtos = empresa.produto.size();

                    continuarLoop = 1;

                    cout << "___________________________________ | LISTA DE EMPRESAS | _______________________________ \n" << endl;

                    for (int i = 0; i < tamanho_vector; i++) {
                        cout << " | " << i + 1 << " | " << empresas[i].nome << endl;
                        cout << "________________________________________________________________\n" << endl;
                    }

                    cout << "| 0 | SAIR" << endl;
                    cout << "\n________________________________________________________________" << endl;

                    cout << "\nINDICE EMPRESA : ";
                    cin >> indice_empresa;

                    int decrementa_indice = indice_empresa - 1;

                    system("cls");

                    if (decrementa_indice >= 0 && decrementa_indice < tamanho_vector) {
                        tamanho_vector_produtos = empresas[indice_empresa - 1].produto.size();

                        cout << "_________________________________ | LISTA DE PRODUTOS | _______________________________________\n" << endl;

                        for (int i = 0; i < tamanho_vector_produtos; i++) {
                            cout << " | " << i + 1 << " | " << empresas[indice_empresa - 1].produto[i].nome << endl;
                            cout << "________________________________________________________________\n" << endl;
                        }

                        cout << " | 0 | SAIR" << endl;
                        cout << "________________________________________________________________\n" << endl;

                        cout << "INDICE DO PRODUTO: ";
                        int indice_produto;
                        cin >> indice_produto;

                        indice_produto = indice_produto - 1;

                        if (indice_produto >= 0 && indice_produto <= tamanho_vector_produtos) {
                            bool ir_para_carrinho = true;

                            system("cls");

                            cout << "IR PARA CARRINHO DE COMPRAS?" << endl;
                            cout << "[1] SIM " << " " << "[0] NAO" << endl;
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
                                    cout << "______________________ | CARRINHO DE COMPRAS | _________________________\n" << endl;
                                    int tamanho_vector_novaVenda_produtos = novaVenda.produtos.size();

                                    for (int i = 0; i < tamanho_vector_novaVenda_produtos; i++) {
                                        cout << "ITEM " << i + 1 << endl;
                                        cout << "NOME PRODUTO: " << novaVenda.produtos[i].nome << endl;
                                        cout << "VALOR PRODUTO: R$ " << novaVenda.produtos[i].valor << endl;
                                        cout << "QUANTIDADE: " << novaVenda.produtos[i].quantidadeProduto << endl;
                                        cout << "------------------------------------------------" << endl;
                                    }

                                    cout << "ADICIONAR MAIS PRODUTOS?" << endl;
                                    cout << "[1] SIM " << " " << "[0] NAO" << endl;
                                    int adicionarProduto;
                                    cin >> adicionarProduto;

                                    if (adicionarProduto == 1) {

                                        cout << "INDICE DO PRODUTO: ";
                                        int indice_produto;
                                        cin >> indice_produto;

                                        indice_produto = indice_produto - 1;

                                        if (indice_produto >= 0 && indice_produto <= tamanho_vector_produtos) {
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

                                cout << "FEEDBACK: ";
                                cin.ignore();
                                getline(cin, novaVenda.feedback);

                                cout << endl;

                                cout << "SIMULAR VENDA?" << endl;
                                cout << "[1] Sim " << " [0] Nao" << endl;
                                cin >> simular;

                                if (simular) {
                                    random_device rd;
                                    mt19937 mt(rd());
                                    uniform_int_distribution <int> dist(0, 99);

                                    int numGerados[10];
                                    int numeros = 0;

                                    for (int i = 0; i < 10; i++) {
                                        int num_aleatorio = dist(mt);
                                        numGerados[i] = num_aleatorio;
                                        numeros += numGerados[i];
                                    }

                                    system("pause");

                                    novaVenda.id_venda = numeros;

                                    vendas.push_back(novaVenda); // Pucha os valores digitados pelo usuário para dentro do vetor vendas como uma nova venda

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

                                    voltarMenuInicial = false;
                                } else {
                                    system("cls");
                                    cout << "VENDA NAO EXECUTADA!" << endl;
                                    system("pause");
                                    system("cls");
                                }
                            } else {
                                break;
                            }
                        }
                    } else if (indice_empresa == 0) {
                        continuarLoop = false;
                        voltarMenuInicial = true;
                    } else {
                        system("cls");
                        cout << "ESSA EMPRESA NAO ESTA CADASTRADA. TENTE NOVAMENTE!" << endl;
                        system("pause");
                        system("cls");
                    }
                }
            } while (!voltarMenuInicial);

            break;

        case 5:
            do {
                if (vendas.empty()) {
                    system("cls");
                    cout << "NENHUMA VENDA REALIZADA!" << endl;
                    system("pause");
                } else {
                    system("cls");

                    int numVendas = vendas.size();
                    double custoProgJr = 20 * 8 * 24 * 3;
                    double receitaTotal = 0;

                    for (int i = 0; i < numVendas; i++) {
                        for (const auto& produto : vendas[i].produtos) {
                            receitaTotal += produto.valor * produto.quantidadeProduto;
                        }
                    }

                    cout << "----------------- FLUXO DE CAIXA --------------------\n" << endl;
                    cout << "RECEITA TOTAL: R$ " << receitaTotal << endl;
                    cout << "-------------------------------------------------------" << endl;
                    cout << "CUSTO TOTAL: R$ " << custoProgJr << endl;
                    cout << "======================================================" << endl;
                    cout << "SALDO: R$ " << receitaTotal - custoProgJr << endl;

                    cout << "\n[1] CONFERIR RELATORIO" << endl;
                    cout << "[0] VOLTAR" << endl;
                    cin >> relatorios;

                    if (relatorios) {
                        system("cls");

                        double valorVendas = 0;
                        int numEmpresas = empresas.size();
                        int numProdutos = 0;

                        for (const auto& venda : vendas) {
                            for (const auto& produto : venda.produtos) {
                                valorVendas += produto.valor * produto.quantidadeProduto;
                            }
                        }
                        for (const auto& empresa : empresas) {
                            numProdutos += empresa.produto.size();
                        }

                        cout << "----------- RELATÓRIO -----------\n" << endl;

                        cout << "----------- DESPESAS ----------\n" << endl;
                        cout << "NUMERO FUNCIONARIOS: 1" << endl;
                        cout << "SALARIO HORA FUNCIONARIO: R$ 20" << endl;
                        cout << "DIAS TRABALHADOS MES: 24" << endl;
                        cout << "MESES TRABALHADOS: 3" << endl;
                        cout << "DESPESAS TOTAL: R$ " << custoProgJr << endl;

                        cout << "----------------- RECEITAS ----------------\n" << endl;
                        cout << "NUMERO DE VENDAS: " << numVendas << endl;
                        cout << "TOTAL DE VENDAS: R$ " << valorVendas << endl;
                        double ticketVendas = valorVendas / numVendas;
                        cout << "TICKET MEDIO: R$ " << ticketVendas << endl;

                        cout << "------------------ DADOS DO APP ---------------" << endl;
                        cout << "EMPRESAS CADASTRADAS: " << numEmpresas << endl;
                        cout << "PRODUTOS CADASTRADOS: " << numProdutos << endl;

                        system("pause");
                        system("cls");
                        voltarMenuInicial = true;
                    } else {
                        system("cls");
                        voltarMenuInicial = true;
                        break;
                    }
                }
            } while (!voltarMenuInicial);

            break;

        case 6:
            if (vendas.empty()) {
                system("cls");
                cout << "NENHUMA VENDA REALIZADA!" << endl;
                system("pause");
                system("cls");
            } else {
                system("cls");

                cout << "--------------- FEEDBACKS ---------------" << endl;

                int tamanho_vector_vendas = vendas.size();

                for (int i = 0; i < tamanho_vector_vendas; i++) {
                    cout << vendas[i].id_venda << " | " << vendas[i].feedback << endl;
                    cout << "--------------------------------------------------" << endl;
                }

                system("pause");
                system("cls");
            }

            break;

        case 7:
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
                    cout << "| " << i + 1 << " |" << vendas[i].id_venda << endl;
                }

                cout << "[1] EXCLUIR VENDA" << endl;
                cout << "[0] VOLTAR" << endl;
                cin >> excluirVenda;

                if (excluirVenda) {
                    cout << "DIGITE O INDICE DA VENDA: ";
                    cin >> indiceExcluir;

                    if (indiceExcluir - 1 < tamanho_vector_vendas) {
                        vendas.erase(vendas.begin() + (indiceExcluir - 1)); // Corrigido: usar 
                        system("pause");
                        cout << "ITEM EXCLUIDO COM SUCESSO!" << endl;
                        system("pause");
                        system("cls");
                    } else {
                        system("cls");
                        cout << "INDICE INVALIDO!" << endl;
                        system("pause");
                        system("cls");
                    }
                } else {
                    break;
                }

                system("pause");
            }

            break;

        default:
            system("cls");
            cout << "NENHUMA ESCOLHA CONDIZ COM A ESCOLHA DESEJADA!" << endl;
            cout << "\nSAINDO..." << endl;
            break;
        }
    } while (escolha_usuario <= 7);

    return 0;
}