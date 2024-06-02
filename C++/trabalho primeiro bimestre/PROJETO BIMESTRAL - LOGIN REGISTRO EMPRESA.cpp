#include <iostream>
#include <string> // usado para fazer strings, class(private e public)
#include <random> // geração de números aleatórios

using namespace std;

// Parte do Luiz

class Registro { // Representa registros de usuários e informações de funcionários
private:  // São acessiveis apenas dentro da propria classe em que estão declarados
    string nome;
    int idade;
    string dataNascimento;
    string gmail;
    string id;
    string senha;

public: // São acessiveis fora da classe em que estão declarados
    Registro() {} 

    Registro(string nome, int idade, string dataNascimento, string gmail, string senha) {
        this->nome = nome;
        this->idade = idade;
        this->dataNascimento = dataNascimento;
        this->gmail = gmail;
        this->id = gerarIdAleatoria();
        this->senha = senha;
    }
    
    // Recuperar o email e a senha armazenados no objeto Registro
    // Getter para o Gmail
    string getGmail() const {
        return gmail;
    }

    // Getter para senha
    string getSenha() const {
        return senha;
    }

    // Verificar gmail
    bool verificarCredenciaisG(string gmail) const {
        return this->gmail == gmail;
    }

    // Verificar senha
    bool verificarCredenciaisS(string senha) const {
        return this->senha == senha;
    }

    string toString() {
        return "Nome: " + nome +
               "\nIdade: " + to_string(idade) +
               "\nData de Nascimento: " + dataNascimento +
               "\nGmail: " + gmail +
               "\nID: " + id;
    }

    string getNome() const {
        return nome;
    }

private:
    string gerarIdAleatoria() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 9999);
        return to_string(dis(gen));
    }
};

// Parte da Gab
// Estrutura para definir o funcionario
struct Funcionario {
    string nome;
    string endereco;
    string cpf;
    string dataAdmissao;
    string tipo; // efetivo, temporário ou estagiário
    double salarioBase;
    int horasExtras;
    int diasTrabalhados; // Apenas para temporários
};

// Função para calcular o salário de um funcionário
double calcularSalario(Funcionario &funcionario) {
    double salario = funcionario.salarioBase;

    // Calcula o salário com base no tipo de funcionário
    if (funcionario.tipo == "efetivo") {
        // Calcula o valor das horas extras
        salario += funcionario.horasExtras * (funcionario.salarioBase / 220); // Considerando 220 horas mensais de trabalho
    } else if (funcionario.tipo == "temporario") {
        // Calcula o salário com base nos dias trabalhados
        salario = (funcionario.salarioBase / 30) * funcionario.diasTrabalhados;
    } else if (funcionario.tipo == "estagiario") {
        // Salário fixo para estagiários
        salario = 800.0;
    }

    // Aplica os descontos (INSS e imposto de renda)
    double descontoINSS = salario * 0.08;
    double descontoIR = salario * 0.12;
    salario -= descontoINSS;
    salario -= descontoIR;

    return salario;
}

int main() {
    int escolha;
    bool login = false;
    Registro registros[2] = {}; // Array para armazenar os registros dos usuários
    string nomeUsuario; // Variável para armazenar o nome do usuário registrado

    while (!login) { // Loop
        cout << "\n----- Bem-vindo a pagina inicial da empresa de Cadastro e Login -----\n";
        cout << "Selecione uma das opcoes:\n";
        cout << "[1] para REGISTRAR-SE\n";
        cout << "[2] para LOGAR em sua respectiva conta criada\n";
        cout << "[0] para SAIR\n";
        cout << "Opcao: ";
        cin >> escolha;

        switch(escolha) {
            case 1: {
                int idade;

                cout << "\nBoas-vindas a parte de Sign-in da nossa empresa:\n";
                string nome, dataNascimento, gmail, senha;
                cout << "\nDigite o nome: ";
                cin.ignore();
                getline(cin, nome);
                // usamos o getline ao invez do cin pq so funciona em strings e cin da pra usar em geral

                cout << "\nDigite a idade: ";
                cin >> idade;
                cin.ignore(); // limpar o buffer antes de ler a próxima linha

                cout << "\nDigite a data de nascimento (dd/mm/aaaa): ";
                getline(cin, dataNascimento);

                cout << "\nDigite o Gmail: ";
                getline(cin, gmail);

                cout << "-- Criacao de senha --";
                cout << "\n(Recomenda-se usar no minimo 8 caracteres com numeros e caracteres especiais)";
                cout << "\nDigite sua senha: ";
                getline(cin, senha);

                nomeUsuario = nome; // armazena o nome do usuário registrado

                for (int i = 0; i < 2; ++i) {
                    if (registros[i].getGmail().empty()) {
                        registros[i] = Registro(nome, idade, dataNascimento, gmail, senha);
                        cout << "\nRegistro criado:\n" << registros[i].toString() << endl;
                        break;
                    }
                }

                break;
            }

            case 2: {
                cout << "\nBoas-vindas a parte de LOGIN da nossa empresa:\n";
                string gmail, senha;
                cout << "\nDigite o seu Gmail: ";
                cin.ignore();
                getline(cin, gmail);
                cout << "\nDigite sua senha: ";
                getline(cin, senha);

                // Verificar credenciais
                bool credenciaisValidas = false;
                for (int i = 0; i < 2; ++i) {
                    if (registros[i].verificarCredenciaisG(gmail) && registros[i].verificarCredenciaisS(senha)) {
                        credenciaisValidas = true;
                        break;
                    }
                }

                if (credenciaisValidas) {
                    cout << "Login bem-sucedido!\n";

                    // Parte da Gab

                    Funcionario funcionario;
                    cout << "\n----- Cadastro de Funcionario -----\n";
                    cout << "Digite o endereco do funcionario: ";
                    getline(cin, funcionario.endereco);
                    cout << "Digite o CPF do funcionario: ";
                    getline(cin, funcionario.cpf);
                    cout << "Digite a data de admissao do funcionário (dd/mm/aaaa): ";
                    getline(cin, funcionario.dataAdmissao);
                    cout << "Digite o tipo de funcionario (efetivo, temporario, estagiario): ";
                    getline(cin, funcionario.tipo);
                    cout << "Digite o salario base do funcionario: ";
                    cin >> funcionario.salarioBase;

                    // Se for funcionário efetivo, perguntar as horas extras
                    if (funcionario.tipo == "efetivo") {
                        cout << "Digite a quantidade de horas extras trabalhadas: ";
                        cin >> funcionario.horasExtras;
                    }
                    
                    // Calcular e exibir o salário do funcionário
                    double salario = calcularSalario(funcionario);
                    cout << "\n----- Holerite -----\n";
                    cout << "Nome: " << nomeUsuario << endl;  //para nao ter que digitar o nome novamente
                    cout << "Salario liquido: R$ " << salario << endl;

                    login = true;
                } else {
                    cout << "Credenciais invalidas!\n";
                }

                break;
            }
            case 0: {
                cout << "Saindo...\n";
                return 0;
            }
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }

    // O usuário está logado aqui e foi para a página inicial
    return 0;
}