// dupla: Luiz Henrique de Castro Almeida e Gabriela da Cruz

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int opcao, prova, trab1, trab2, rec;
bool saida = true;

struct Aluno {
    string nome;
    int prova;
    int trab1;
    int trab2;
    int rec;
    int notaFinal;
};

vector<Aluno> turmaBAlunos;

void turmaA() {
    cout << "--------------------------------------------------- " << endl;
    cout << "| aluno | prova | trab. 1 | trab. 2 | rec | nota final bim. |" << endl;
    cout << "| joao  |   50  |    10   |    10   |  0  |       70        |" << endl;
    cout << "| pedro |   30  |    0    |    0.8  |  70 |       100       |" << endl;
    cout << "| maria |   40  |   0.7   |    10   |  0  |       50.7      |" << endl;
    cout << "--------------------------------------------------- " << endl;
}

void adicionarNotaTurmaB() {
    Aluno aluno;
    cout << "Digite o nome do aluno: ";
    cin >> aluno.nome;
    cout << "Digite a nota da prova: ";
    cin >> aluno.prova;
    cout << "Digite a nota do trabalho 1: ";
    cin >> aluno.trab1;
    cout << "Digite a nota do trabalho 2: ";
    cin >> aluno.trab2;
    cout << "Digite a nota do rec: ";
    cin >> aluno.rec;

    aluno.notaFinal = aluno.prova + aluno.trab1 + aluno.trab2 + aluno.rec;
    turmaBAlunos.push_back(aluno);
    cout << "O aluno " << aluno.nome << " ficou com a nota: " << aluno.notaFinal << endl;
    if (aluno.rec >= 60 && aluno.rec < 70) {
        cout << "Aluno " << aluno.nome << " esta em recuperacao." << endl;
    } else {
        cout << "Aluno " << aluno.nome << " nao esta em recuperacao." << endl;
    }
}

void turmaB() {
    int escolha;
    do {
        adicionarNotaTurmaB();
        cout << "Deseja adicionar mais notas? (1 - Sim, 2 - Nao): ";
        cin >> escolha;
    } while (escolha == 1);
}

void mostrarNotasTurmaB() {
    cout << "--------------------------------------------------- " << endl;
    cout << "| aluno | prova | trab. 1 | trab. 2 | rec | nota final bim. |" << endl;
    for (const auto& aluno : turmaBAlunos) {
        cout << "| " << aluno.nome << " | " << aluno.prova << " | " << aluno.trab1 << " | " << aluno.trab2 << " | " << aluno.rec << " | " << aluno.notaFinal << " |" << endl;
    }
    cout << "--------------------------------------------------- " << endl;
}

int main() {
    while (saida) {
        cout << "Ola, o que voce gostaria de fazer?" << endl;
        cout << "1 - ver notas" << endl;
        cout << "2 - adicionar notas" << endl;
        cout << "3 - sair do sistema" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                char turma;
                cout << "Qual turma voce ira ver as notas? (A ou B) ";
                cout << "\n";
                cin >> turma;
                if (turma == 'A' || turma == 'a') {
                    turmaA();
                } else if (turma == 'B' || turma == 'b') {
                    mostrarNotasTurmaB();
                } else {
                    cout << "Turma invalida." << endl;
                }
                break;
            }

            case 2: {
                char turma;
                cout << "Qual turma voce ira adicionar notas? (A ou B) ";
                cout << "\nTurma A eh exemplo, turma B eh a que esta funcionando.";
                cout << "\n";
                cin >> turma;
                if (turma == 'A' || turma == 'a') {
                    turmaA();
                } else if (turma == 'B' || turma == 'b') {
                    turmaB();
                } else {
                    cout << "Turma invalida." << endl;
                }
                break;
            }

            case 3:
                cout << "Ok! Até logo..." << endl;
                saida = false;
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }

    return 0;
}
