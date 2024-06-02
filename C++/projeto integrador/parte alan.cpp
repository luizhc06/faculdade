#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

struct produto 
{
        string nome;
        double valor;

};

struct Empresa 
{
       string nome;
       string cnpj;
       string endereco;
       string telefone;
       string email;
       vector<produto> produto;
};

struct venda
{

        string nomeEmpresa;
        string cnpjEmpresa;
        string emailEmpresa;
        string enderecoEmpresa;
        string telefoneEmpresa;
        string nomeProduto;
        double valorProduto;
        int quantidadeProduto;

};



int main(){
        
        vector<Empresa> empresas; // Vetor que armazena as empresas cadastradas
        vector<venda> vendas; // Vetor que armazena as venas feitas

        int escolha_usuario; // armazena a escolha do usuario no menu inicial
        int tamanho_vector, tamanho_vector_produtos;
        int indice_empresa;
        bool continuarLoop = 1;
        bool voltarMenuInicial = true;

        cout << boolalpha;

        do
        {

                system("cls"); // limpa o terminal

                cout << "------------------ | FURA-FILA EXPRESS | -------------------------" <<endl; // Menu principal de owner
                cout <<endl;
                cout << "| 1 | CADASTRO EMPRESAS" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "| 2 | CADASTRO PRODUTOS" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "| 3 | CONSULTA EMPRESAS" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "| 4 | SIMULADOR DE VENDAS" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "| 5 | FLUXO DE CAIXA" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "| 6 | SAIR SISTEMA" <<endl;
                cout << "_________________________________________________\n" <<endl;
                cout << "ESCOLHA: ";
                cin >> escolha_usuario;// input para o usuario digitar sua escolha

                switch (escolha_usuario) // Escolha do usuário 
                {

                case 1: // Cadastro de empresas
                        
                        do
                        {

                                Empresa empresa;

                                system("cls"); // Apaga o conteúdo do terminal

                                cout << "_______________________ | CADASTRO EMPRESA | ____________________________" <<endl; // Inicia o cadastro da nova empresa

                                cout << endl;

                                cout << "NOME EMPRESA: ";
                                cin.ignore();
                                getline(cin, empresa.nome); // Armazena o nome da empresa na struct chamada empresa
                                cout << "___________________________________________________\n" <<endl;
                                cout << "CNPJ: ";
                                cin.ignore();
                                getline(cin, empresa.cnpj); // Armazena o cnpj da empresa na struct chamada empresa
                                cout << "___________________________________________________\n" <<endl;
                                cout << "BAIRRO: ";
                                cin.ignore();
                                getline(cin, empresa.endereco); // Armazena o endereco da empresa na struct chamada empresa
                                cout << "___________________________________________________\n" <<endl;
                                cout << "TELEFONE: ";
                                cin.ignore();
                                getline(cin, empresa.telefone); // Armazena o telefone da empresa na struct chamada empresa
                                cout << "___________________________________________________\n" <<endl;
                                cout << "E-MAIL: ";
                                cin.ignore();
                                getline(cin, empresa.email);// Armazena o email da empresa na struct chamada empresa
                                cout << "___________________________________________________\n" <<endl;

                                empresas.push_back(empresa); // Insere a struct empresa dentro de um vetor, sempre colocando a nova empresa no final do vetor

                                system("cls");

                                cout << "___________________ | EMPRESA CADASTRADA COM SUCESSO! | ________________________" <<endl; // Se ocorrer tudo certo essa menssagem será mostrada ao usuário

                                cout << endl;

                                cout << "NOVO CADASTRO?" <<endl;
                                cout << "[1]" << " SIM " << " " << "[0]" << " NAO " <<endl;
                                cin >> continuarLoop; // Armazena a resposta a variável booleana, onde se for sim irá repetir o código acima

                                system("cls");

                        } while (continuarLoop);// Verifica se a resposta é true ou false
                        break;// Sai da caso 1

                case 2: // Cadastro de produtos


                        do
                        {
                                // Verifica se o vetor está vazio ou não
                                if(empresas.empty()){
                                        system("cls");

                                        cout << "______________________________ | NENHUMA EMPRESA CADASTRADA! | ____________________________" << endl;// Caso esteja vazio exibe essa menssagem

                                        system("pause");
                                        system("cls");
                                }else{

                                        system("cls");

                                        tamanho_vector = empresas.size(); // Serve para contarmos o tamanho do vetor 

                                        continuarLoop = 1; // Reinicia a variável booleana para seu valor original

                                        cout << "________________________________ | ESCOLHA EMPRESA | _______________________________\n" <<endl;

                                        for(int i = 0; i < tamanho_vector; i++){
                                                cout << "| " << i + 1 << " | " << empresas[i].nome << endl;// Vetor imprime os nomes das empresas que estão dentro do meu vetor chamado empresas
                                                cout << "_________________________________________________\n" <<endl;
                                        }


                                        cout << "| 0 | SAIR" <<endl;// Opção para sair do sistema

                                        cout << "_________________________________________________\n" <<endl;
                                        
                                        cout << "INDICE EMPRESA: ";
                                        cin >> indice_empresa; // Pede para o usuário escolher a empresa que ele deseja 

                                        int decrementa_indice = indice_empresa - 1; // Decrementa um do índice para ele começar da posição 0, e não da posição 1

                                        

                                        if(decrementa_indice >= 0 && decrementa_indice < tamanho_vector){

                                                produto novoProduto; // Refere-se a strutura produto

                                                system("cls");

                                                cout << "___________________________ | CADASTRO PRODUTO | __________________________\n" <<endl;

                                                cout << "NOME PRODUTO: ";
                                                cin.ignore(); // Serve para limpar o buffer de entrada de dados, para que consigamos rodar o getline
                                                getline(cin, novoProduto.nome); // Grava o nome do novo produto até que uma quebra de linha seja encontrada, ou seja quando pressionarmos um enter                                           
                                                cout << "____________________________________________________________________\n" <<endl;
                                                cout << "VALOR PRODUTO: " << "R$ ";
                                                cin >> novoProduto.valor; // Recebe o valor do produto
                                                cout << "________________________________________________________________" <<endl;

                                                empresas[decrementa_indice].produto.push_back(novoProduto); // Salva os dados do novoProduto dentro de um vetor produtos que estaá dentro de um vetor empresas

                                                system("cls");

                                                cout << "______________________ | PRODUTO ADICIONADO COM SUCESSO! | _______________________________\n" <<endl;

                                                cout << "DESEJA ADICIONAR NOVO PRODUTO?" <<endl;
                                                cout << "[1] SIM " << " " << "[0] NAO" <<endl;
                                                cin >> continuarLoop; // Recebe a informação se deseja ou não adionar novo produto

                                        }else if( indice_empresa == 0){

                                                continuarLoop = 0; // Alternativa para sairmos do loop e voltarmos para o menu inicial

                                        }else{
                                                system("cls");

                                                cout << "EMPRESA NAO ENCONTRADA!" <<endl; // Código para quando o índice da empresa não for encontrado

                                                system("pause");
                                                system("cls");
                                        }
                                }

                        } while (continuarLoop); // Verifica se volta ou não para menu inicial
                       
                        break;
                
                case 3:

                        do
                        {


                                if(empresas.empty()){

                                        system("cls");
                                        cout << "\nNENHUMA EMPRESA CADASTRADA!" <<endl; // Caso nenhuma empresa seja encontrada pela function empty esse código será retornado
                                        system("pause");
                                        system("cls");

                                }else{

                                        system("cls");

                                        tamanho_vector = empresas.size(); // tamanho do vetor empresas declarado novamente 

                                        continuarLoop = 1; // ContinuarLoop reinicia para seu valor original

                                        cout << "______________________________ | EMPRESAS CADASTRADAS | _______________________________________\n" <<endl;

                                        for(int i = 0; i < tamanho_vector; i++){
                                                cout << "| " << i + 1 << " | " << empresas[i].nome <<endl; // Exibi as empresas cadastradas no sistema
                                                cout << "________________________________________________________________\n" <<endl;
                                        }

                                        cout << "| 0 | SAIR" <<endl; // Alternativa para sair do sistema

                                        cout << "__________________________________________________________________________\n" <<endl;
                                
                                        cout << endl;

                                        cout << " INDICE EMPRESA: ";
                                        cin >> indice_empresa; // Armazena o indice escolhido pelo usuário

                                        int decrementa_indice = indice_empresa - 1;// Decrementa 1 do índice escolhido pelo usuário


                                        if(decrementa_indice >= 0 && decrementa_indice <= tamanho_vector){ // Verifica se o indice é maior ou igual a 0 e se é menor ou igual ao tamanho do vetor empresas

                                                system("cls"); // limpa o terminal

                                                cout << "_______________________________ | DADOS DA EMPRESA | ______________________________\n" <<endl;

                                                cout << "NOME: " << empresas[indice_empresa - 1].nome << endl; // Acha a empresa dentro do vetor pelo numero do indice que voce digitou - 1, pq os espaços de memórias em vetor começa da posição 0
                                                cout << "________________________________________________________________\n" <<endl;
                                                cout << "CNPJ: " << empresas[indice_empresa - 1].cnpj << endl;
                                                cout << "________________________________________________________________\n" <<endl;
                                                cout << "BAIRRO: " << empresas[indice_empresa - 1].endereco << endl;
                                                cout << "________________________________________________________________\n" <<endl;
                                                cout << "TEL: " << empresas[indice_empresa - 1].telefone << endl;
                                                cout << "________________________________________________________________\n" <<endl;
                                                cout << "E-MAIL: " << empresas[indice_empresa - 1].email << endl;
                                                cout << "________________________________________________________________\n" <<endl;

                                                system("pause");

                                        }else if(indice_empresa == 0){

                                                continuarLoop = 0; // continuar_loop igual a 0, para quando quisermos voltar ao menu incial e sair do while

                                        }else{

                                                system("cls");

                                                cout << "EMPRESA NAO ENCONTRADA COM ESSE INDICE. TENTE NOVAMENTE!" <<endl; // texto caso o índice da empresa não seja encontrado

                                                system("pause");
                                                system("cls");

                                        }
                                }

                        } while (continuarLoop); // Verifica se continua ou não o loop, por meio de uma varável booleana

                        break;

                case 4:

                        if(empresas.empty()){ // verifica se o vetor de empresas não está vazio

                                system("cls");
                                cout << "NENHUMA EMPRESA CADASTRADA!" <<endl; // Se estiver essa menssagem será exibida
                                system("pause");
                                system("cls");

                        }else{

                                Empresa empresa; // declaração da struct de empresa novamente

                                system("cls"); // Limpeza do terminal

                                tamanho_vector = empresas.size(); // Calcula o tamanho do vetor empresas
                                tamanho_vector_produtos = empresa.produto.size(); // Calcula o tamanho do vetor produtos dentro de empresa

                                continuarLoop = 1; // Reinicializa a variável continuarLoop, usada para sair e entrar nos loop

                                cout << "___________________________________ | LISTA DE EMPRESAS | _______________________________ \n" <<endl;

                                for(int i = 0; i < tamanho_vector; i++){
                                        cout << " | " << i + 1 << " | " << empresas[i].nome <<endl; // Imprime as empresas cadstradas no loop
                                        cout << "________________________________________________________________\n" <<endl;
                                }

                                cout << "| 0 | SAIR" <<endl; // Condição de saida do para o menu inicial

                                cout << "\n________________________________________________________________" <<endl;
                        
                                cout << "\nINDICE EMPRESA : ";
                                cin >> indice_empresa; //  Indice da empresa

                                int decrementa_indice = indice_empresa - 1; // Diminui um para ele acessar o indice 0 do vetor

                                system("cls");

                                if(decrementa_indice >= 0 && decrementa_indice < tamanho_vector){ // verifica se indice está dentro do tamanho do vetor empresasa

                                        tamanho_vector_produtos = empresas[indice_empresa - 1].produto.size(); // tamanho do vetor produtos


                                        cout << "_________________________________ | LISTA DE PRODUTOS | _______________________________________\n" <<endl;

                                        for(int i = 0; i < tamanho_vector_produtos; i++){
                                                cout << " | " << i + 1 << " | " << empresas[indice_empresa - 1].produto[i].nome <<endl; // Imprime os produtos do vetor produtos
                                                cout << "________________________________________________________________\n" <<endl;
                                        }

                                        cout << " | 0 | SAIR" << endl; // Condição de saida para o menu inicial
                                        cout << "________________________________________________________________\n" <<endl;

                                        cout << "INDICE DO PRODUTO: "; 
                                        int indice_produto;

                                        cin >> indice_produto;// Indice do prduto, usuário escolhe
                                        

                                        indice_produto = indice_produto - 1; // Diminui um do indice de produtos

                                        if(indice_produto >= 0 && indice_produto <= tamanho_vector_produtos){ // verifica se o indice está entre os parãmetros do vetor produtos

                                                bool simular = false; // Variável para saber se simula ou não a venda
                                                int quantidade_produto = 0; // Para saber a quantidade de produto da venda

                                                system("cls");

                                                cout << "SIMULAR VENDA?" <<endl;
                                                cout << "[1] SIM " << " " << "[0] NAO" << endl;
                                                cin >> simular; // recebe o o valor booleano

                                                if(simular){ // Se simular for true

                                                        venda novaVenda;

                                                        novaVenda.nomeEmpresa = empresas[indice_empresa - 1].nome; // Novavenda sempre será o indice da empresa - 1
                                                        novaVenda.cnpjEmpresa = empresas[indice_empresa - 1].cnpj;
                                                        novaVenda.emailEmpresa = empresas[indice_empresa - 1].email;
                                                        novaVenda.nomeProduto = empresas[indice_empresa - 1].produto[indice_produto].nome;
                                                        novaVenda.valorProduto = empresas[indice_empresa - 1].produto[indice_produto].valor;
                                                        
                                                        system("cls");

                                                        cout << "______________________ | CONFIRMACAO DOS DADOS DO PEDIDO | _________________________" <<endl;

                                                        cout << "\nNOME EMPRESA: " << novaVenda.nomeEmpresa << endl; // imprime o que está armazenado na posição escolhida pelo usuário dentro do vetor
                                                        cout << "_________________________________________________\n" <<endl;
                                                        cout << "CNPJ EMPRESA: " << novaVenda.cnpjEmpresa << endl;
                                                        cout << "_________________________________________________\n" <<endl;
                                                        cout << "E-MAIL: " << novaVenda.emailEmpresa <<endl;
                                                        cout << "_________________________________________________\n" <<endl;
                                                        cout << "NOME PRODUTO: " << novaVenda.nomeProduto <<endl;
                                                        cout << "_________________________________________________\n" <<endl;
                                                        cout << "VALOR PRODUTO: " << novaVenda.valorProduto << endl;
                                                        cout << "_________________________________________________\n" <<endl;
                                                        cout << "DIGITE A QUANTIDADE: ";
                                                        cin >> quantidade_produto;

                                                        novaVenda.quantidadeProduto = quantidade_produto; // defini que a quantidade de produto dentro da struct é quantidade de produto digitdada pelo usuário na variável

                                                        vendas.push_back(novaVenda); // Pucha os valores digitados pelo usuário para dentro do vetor vendas como uma nova venda

                                                        system("cls");

                                                        cout << "_______________________________ | PEDIDO CONFIRMADO COM SUCESSO! | ___________________________________" <<endl;

                                                        system("pause");
                                                        system("cls");

                                                        double valor_total_venda = novaVenda.valorProduto * novaVenda.quantidadeProduto;
                                                        double taxa_fura = 0.15;

                                                        cout << "\n_______________________ | DETALHES DA VENDA | _____________________________\n" <<endl;
                                                        cout << "________________________________________________________________\n" <<endl; // Exibi o que está aramazenado dentro da posição que o usuário escolheu do vetor vendas
                                                        cout << "NOME PRODUTO: " << novaVenda.nomeEmpresa << endl;
                                                        cout << "\n________________________________________________________________\n" <<endl;
                                                        cout << "VALOR PRODUTO (1 UNIDADE): " << novaVenda.valorProduto << endl;
                                                        cout << "\n________________________________________________________________\n" <<endl;
                                                        cout << "QUANTIDADE PRODUTO: " << novaVenda.quantidadeProduto <<endl;
                                                        cout << "\n________________________________________________________________\n" <<endl;
                                                        cout << "TAXA FURA-FILA: " <<  valor_total_venda * taxa_fura <<endl;
                                                        cout << "\n________________________________________________________________\n" <<endl;
                                                        cout << "VALOR TOTAL: " << valor_total_venda <<endl;
                                                        cout << "\n________________________________________________________________\n" <<endl;

                                                        system("pause");

                                                        system("cls");

                                                        bool repetir_venda;

                                                        cout << "DESEJA REPETIR A VENDA?" << endl;
                                                        cout << "[1] SIM" << "  " << "[0] NAO" <<endl;
                                                        cin >> repetir_venda; // pergunta para o usuário se ele deseja repetir a venda, variável booleana

                                                        if(repetir_venda){// Se for verdadeira a variável booleana

                                                                int vezes_repetir; // Variável para guaradar quantas vezes o usuário quer repetir a venda

                                                                cout << "\nDIGITE QUANTAS VEZES DESEJA REPETIR: ";
                                                                cin >> vezes_repetir; // Usuário digita numero de vezes que quer repetir

                                                                for(int i = 0; i < vezes_repetir - 1; i++){
                                                                        vendas.push_back(novaVenda); // Loop criar as vendas repetidas
                                                                }

                                                                system("cls");

                                                                int tamanho_vendas = vendas.size(); // Calcula o tamanho do vetor vendas
                                                                int total_vendas = 0; // Inicializa o vetor total de vendas

                                                                for(int i = 0; i < tamanho_vendas; i++){
                                                                        total_vendas += vendas[i].valorProduto * vendas[i].quantidadeProduto; // Valor do produto * quatidade de produtos na venda
                                                                }

                                                                double valor_produtos = total_vendas - (total_vendas * taxa_fura);

                                                                system("cls");

                                                                cout << "VENDAS CONCLUIDAS COM SUCESSO!" <<endl;

                                                                system("cls");
                                                                system("cls");

                                                                cout << "____________________________ | COMPROVANTE DA VENDA | ______________________________\n" <<endl;
                                                                cout << "NUMERO DE VENDAS: " << vezes_repetir <<endl; // imprime os dados de quantas vendas foram feitas
                                                                cout << "________________________________________________________________\n" <<endl;
                                                                cout << "VALOR PRODUTO: " << "R$ " << valor_produtos <<endl;// Imprime o valor 
                                                                cout << "________________________________________________________________\n" <<endl;
                                                                cout << "TAXA FURA-FILA: " << "R$ " << total_vendas - valor_produtos <<endl; // imrpime a taxa do fura fila
                                                                cout << "________________________________________________________________\n" <<endl;
                                                                cout << "VALOR TOTAL: " << "R$ " << total_vendas <<endl; // Valor total do fura fila
                                                                cout << "________________________________________________________________\n" <<endl;

                                                                system("pause");
                                                                
                                                                system("cls");


                                                        }


                                                }else{
                                                        cout << "VENDA NAO EXECUTADA!" <<endl;
                                                        system("pause");
                                                        break;
                                                }
                                        }

                                }else if(indice_empresa == 0){

                                        continuarLoop = false;

                                }else{
                                        system("cls");
                                        cout << "ESSA EMPRESA NAO ESTA CADASTRADA. TENTE NOVAMENTE!" <<endl;
                                        system("pause");
                                        system("cls");
                                }
                        }

                        break;

                case 5:

                        do
                        {

                                if (vendas.empty()) {
                                        system("cls");
                                        cout << "NENHUMA VENDA REALIZADA!" << endl;
                                        system("pause");
                                }else{

                                        system("cls");

                                        cout << "__________________________ | FLUXO DE CAIXA | ______________________________\n" << endl;

                                        venda novaVenda;

                                        int tamanho_vendas = vendas.size();
                                        double valor_total_vendas = 0;       

                                        for(int i = 0; i < tamanho_vendas; i++){
                                                valor_total_vendas += vendas[i].valorProduto * tamanho_vendas;
                                        }
                                        
                                        double taxa_fura = 0.15;
                                        double custo_vendas =  0.05;
                                        double lucro_final = (valor_total_vendas * taxa_fura) - (valor_total_vendas * taxa_fura * custo_vendas);
                                        double valor_total = valor_total_vendas * taxa_fura;
                                        double ticket_medio = valor_total / tamanho_vendas;

                                        cout << "NUMERO DE VENDAS: " << tamanho_vendas <<endl;
                                        cout << "_________________________________________________\n" <<endl;
                                        cout << "VALOR TOTAL FURA-FILA: " << "R$ " << valor_total << endl;
                                        cout << "_________________________________________________\n" <<endl;
                                        cout << "CUSTO TOTAL: " << "R$ " << valor_total_vendas * taxa_fura * custo_vendas <<endl;
                                        cout << "_________________________________________________\n" <<endl;
                                        cout << "LUCRO LIQUIDO TOTAL: " << "R$ " << lucro_final << endl;
                                        cout << "_________________________________________________\n" <<endl;
                                        cout << "TICKET MEDIO: " << "R$ " << ticket_medio <<endl;
                                        cout << "_________________________________________________\n" <<endl;

                                        cout << "[1] VOLTAR MENU INICIAL" <<endl;
                                        cin >> voltarMenuInicial;
                                        

                                }
                        } while (!voltarMenuInicial);
                        
                        break; 

                        default:
                                system("cls");
                               cout << "NENHUMA ESCOLHA CONDIZ COM A ESCOLHA DESEJADA!" <<endl;
                               cout << "\nSAINDO..." <<endl;
                        break;

                }

        } while (escolha_usuario != 6);


        return 0;
}