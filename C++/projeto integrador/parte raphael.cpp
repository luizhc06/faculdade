int main()
{
	// Inicializando Variaveis
	int interacao1 = 1;
	int interacao2 = 0;
	int interacao3 = -1;
	int verificacao = 0;
	int pagamento = 0;

	// Armazenamento de Dados de Todos os Cartões
	string cartao_debito[4] = { "", "", "", "" };
	string cartao_credito[4] = { "", "", "", "" };
	string cartao_vr[4] = { "", "", "", "" };

	// Loop Confirmação Check - out
	while (interacao1 != 0)  // Mantem o Usuario em um Loop até ele Cancelar a Compra
	{
		// Porcentagem Retirada par Aplicativo
		double taxa_app = 0.05;
		// Itens no Carrinho e seus Preços
		string itens[3] = { "Combo Big Mac", "Coca-Cola Grande", "Batata frita Media" };
		double price[3] = { 36.99, 12.99, 10.99 };

		// Printando Primeiro Menu Check-out
		cout << "Seja bem vindo!\n" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "\nCarrinho Atual: " << endl;
		cout << "Item: " << itens[0] << "           Preco: " << price[0] << endl;
		cout << "Item: " << itens[1] << "        Preco: " << price[1] << endl;
		cout << "Item: " << itens[2] << "      Preco: " << price[2] << endl;
		cout << "Taxa Adicional Integracao aplicativo:   " << taxa_app * 100 << "%\n" << endl;
		taxa_app = (price[0] + price[1] + price[2]) * taxa_app; // Converte a Porcentagem Adicionada ao Carrinho do Cliente
		double total = (price[0] + price[1] + price[2]) + taxa_app; // Valor Total Check-out
		cout << "---------------------------------------------" << endl;
		cout << "Total: R$" << fixed << setprecision(2) << total << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Confirmar compra e prosseguir para pagamento?" << endl;
		cout << "[0] Nao     [1] Sim" << endl;
		cout << "---------------------------------------------" << endl;
		// Confirma Compra ou Cancela
		cout << "Sua escolha: ";
		cin >> interacao1;

		system("cls");

		// Inicia Bloco de Códigos ao Confirmar Continuar Compra
		if (interacao1 == 1)
		{
			// Mantem em um Loop Até o Usuário Cancelar a Compra
			while (interacao2 != 6)
			{	
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
				// Escolha Método de Pagamento
				cout << "Insira sua escolha: ";
				cin >> interacao2;
				system("cls");

				// Inicia Bloco de Código caso Já tenha um Cartao de Débito Cadastrado
				if (interacao2 == 1 && cartao_debito[0] != "")
				{			
					cout << "--------------- CARTAO DEBITO ---------------" << endl;
					cout << "Confirme os dados . . .\n" << endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					cout << "---------------------------------------------" << endl;
					cout << "Nome: " << cartao_debito[0] << endl; // Printa Dados Cartão
					cout << "Numero Cartao: " << cartao_debito[1] << endl; // Printa Dados Cartão
					cout << "Validade Cartao: " << cartao_debito[2] << endl; // Printa Dados Cartão
					cout << "CVV Cartao: " << cartao_debito[3] << endl; // Printa Dados Cartão
					cout << "---------------------------------------------\n" << endl;
					// Confirmação de Pagamento com Cartão de Débito Cadastrado
					cout << "Proceder com Pagamento: " << endl;
					cout << "[0] NAO     [1] SIM" << endl;
					cout << "Insira sua escolha: ";
					cin >> verificacao;
					system("cls");

					// Redireciona a Tela Final de Pagamento ao Confirmar a Compra
					if (verificacao == 1)
					{
						cout << "------------------------------" << endl;
						cout << "Processando Pagamento . . ." << endl;
						cout << "------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
						pagamento = 1; // Permite Chegar na Tela de Comprovante
						break; // Finaliza Loop Menu Formas de Pagamento
					}

					// Apaga os Dados do Cartão Cadastrado ao Negar o Pagamento com o Cartão
					else if (verificacao == 0)
					{
						cout << "---------------------------------------------" << endl;
						cout << "Deletando Dados do Cartao . . ." << endl;
						cout << "---------------------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(5));
						system("cls");
						cartao_debito[0] = { "" }; // Limpa Array
						cartao_debito[1] = { "" }; // Limpa Array
						cartao_debito[2] = { "" }; // Limpa Array
						cartao_debito[3] = { "" }; // Limpa Array
						cout << "---------------------------------------------" << endl;
						cout << "Nome: " << cartao_debito[0] << endl; // Printa Cartão Vazio
						cout << "Numero Cartao: " << cartao_debito[1] << endl; // Printa Cartão Vazio
						cout << "Validade Cartao: " << cartao_debito[2] << endl; // Printa Cartão Vazio
						cout << "CVV Cartao: " << cartao_debito[3] << endl; // Printa Cartão Vazio
						cout << "---------------------------------------------\n" << endl;
						system("pause");
						system("cls");
						interacao2 = 0; // Reinicia Variavel ao Retornar para o Loop do Menu de Pagamento

					}
				}

				// Inicia Bloco de Código caso NÃO exista um Cartão de Débito Cadastrado
				else if (interacao2 == 1 && cartao_debito[0] == "") {
					cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
					system("pause");
					system("cls");
					cout << "--------------- CARTAO DEBITO ---------------" << endl;
					cout << "Insira o nome registrado no cartao: ";
					cin.ignore();
					getline(cin, cartao_debito[0]); // Cadastra Dados Cartão de Débito
					cout << "Insira o numero registrado no cartao: ";
					getline(cin, cartao_debito[1]); // Cadastra Dados Cartão de Débito
					cout << "Insira a validade registrada no cartao: ";
					cin >> cartao_debito[2]; // Cadastra Dados Cartão de Débito
					cout << "Insira o CVV registrado no cartao: ";
					cin >> cartao_debito[3]; // Cadastra Dados Cartão de Débito
					cout << "---------------------------------------------\n" << endl;

					system("cls");
					cout << "Registrando Dados . . .";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("CLS");
				}

				// Inicia Bloco de Código caso Já tenha um Cartao de Crédito Cadastrado
				if (interacao2 == 2 && cartao_credito[0] != "")
				{
					cout << "--------------- CARTAO CREDITO ---------------" << endl;
					cout << "Confirme os dados . . .\n" << endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					cout << "----------------------------------------------" << endl;
					cout << "Nome: " << cartao_credito[0] << endl; // Printa Dados Cartão
					cout << "Numero Cartao: " << cartao_credito[1] << endl; // Printa Dados Cartão
					cout << "Validade Cartao: " << cartao_credito[2] << endl; // Printa Dados Cartão
					cout << "CVV Cartao: " << cartao_credito[3] << endl; // Printa Dados Cartão
					cout << "----------------------------------------------\n" << endl;
					cout << "Proceder com Pagamento: " << endl;
					cout << "[0] NAO     [1] SIM" << endl;
					cout << "----------------------------------------------\n" << endl;
					// Confirmação de Pagamento com Cartão de Crédito Cadastrado
					cout << "Insira sua escolha: ";
					cin >> verificacao;
					system("cls");

					// Redireciona a Tela Final de Pagamento ao Confirmar a Compra
					if (verificacao == 1)
					{
						cout << "------------------------------" << endl;
						cout << "Processando Pagamento . . ." << endl;
						cout << "------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
						pagamento = 1; // Permite Chegar na Tela de Comprovante
						break; // Finaliza Loop Menu Formas de Pagamento
					}

					// Apaga os Dados do Cartão Cadastrado ao Negar o Pagamento com o Cartão
					else if (verificacao == 0)
					{
						cout << "---------------------------------------------" << endl;
						cout << "Deletando Dados do Cartao . . ." << endl;
						cout << "---------------------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(5));
						system("cls");
						cartao_credito[0] = { "" }; // Limpa Array
						cartao_credito[1] = { "" }; // Limpa Array
						cartao_credito[2] = { "" }; // Limpa Array
						cartao_credito[3] = { "" }; // Limpa Array
						cout << "---------------------------------------------" << endl;
						cout << "Nome: " << cartao_credito[0] << endl; // Printa Cartão Vazio
						cout << "Numero Cartao: " << cartao_credito[1] << endl; // Printa Cartão Vazio
						cout << "Validade Cartao: " << cartao_credito[2] << endl; // Printa Cartão Vazio
						cout << "CVV Cartao: " << cartao_credito[3] << endl; // Printa Cartão Vazio
						cout << "---------------------------------------------\n" << endl;
						system("pause");
						system("cls");
						interacao2 = 0; // Reinicia Variavel ao Retornar para o Loop do Menu de Pagamento
					}
				}

				// Inicia Bloco de Código caso NÃO exista um Cartão de Credito Cadastrado
				else if (interacao2 == 2 && cartao_credito[0] == "")
				{
					cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
					system("pause");
					system("cls");
					cout << "--------------- CARTAO CREDITO ----------------" << endl;
					cout << "Insira o nome registrado no cartao: ";
					cin.ignore(); 
					getline(cin, cartao_credito[0]); // Cadastra Dados Cartão de Crédito
					cout << "Insira o numero registrado no cartao: "; 
					getline(cin, cartao_credito[1]); // Cadastra Dados Cartão de Crédito
					cout << "Insira a validade registrada no cartao: ";
					cin >> cartao_credito[2]; // Cadastra Dados Cartão de Crédito
					cout << "Insira o CVV registrado no cartao: ";
					cin >> cartao_credito[3]; // Cadastra Dados Cartão de Crédito
					cout << "----------------------------------------------\n" << endl;

					system("cls");
					cout << "Registrando Dados . . .";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("CLS");
				}

				// Inicia Bloco de Código caso Já tenha um Cartao de Vale Alimentação Cadastrado
				if (interacao2 == 3 && cartao_vr[0] != "")
				{
					cout << "--------------- CARTAO VALE ALIMENTACAO ---------------" << endl;
					cout << "Confirme os dados . . .\n" << endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					cout << "----------------------------------------------" << endl;
					cout << "Nome: " << cartao_vr[0] << endl; // Printa Dados Cartão
					cout << "Numero Cartao: " << cartao_vr[1] << endl; // Printa Dados Cartão
					cout << "Validade Cartao: " << cartao_vr[2] << endl; // Printa Dados Cartão
					cout << "CVV Cartao: " << cartao_vr[3] << endl; // Printa Dados Cartão
					cout << "----------------------------------------------\n" << endl;
					cout << "Proceder com Pagamento: " << endl;
					cout << "[0] NAO     [1] SIM" << endl;
					cout << "----------------------------------------------\n" << endl;
					// Confirmação de Pagamento com Cartão de Crédito Cadastrado
					cout << "Insira sua escolha: ";
					cin >> verificacao;
					system("cls");

					// Redireciona a Tela Final de Pagamento ao Confirmar a Compra
					if (verificacao == 1)
					{
						cout << "------------------------------" << endl;
						cout << "Processando Pagamento . . ." << endl;
						cout << "------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
						pagamento = 1; // Permite Chegar na Tela de Comprovante
						break; // Finaliza Loop Menu Formas de Pagamento
					}

					// Apaga os Dados do Cartão Cadastrado ao Negar o Pagamento com o Cartão
					else if (verificacao == 0)
					{
						cout << "---------------------------------------------" << endl;
						cout << "Deletando Dados do Cartao . . ." << endl;
						cout << "---------------------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(5));
						system("cls");
						cartao_vr[0] = { "" }; // Limpa Array
						cartao_vr[1] = { "" }; // Limpa Array
						cartao_vr[2] = { "" }; // Limpa Array
						cartao_vr[3] = { "" }; // Limpa Array
						cout << "---------------------------------------------" << endl;
						cout << "Nome: " << cartao_vr[0] << endl; // Printa Cartão Vazio
						cout << "Numero Cartao: " << cartao_vr[1] << endl; // Printa Cartão Vazio
						cout << "Validade Cartao: " << cartao_vr[2] << endl; // Printa Cartão Vazio
						cout << "CVV Cartao: " << cartao_vr[3] << endl; // Printa Cartão Vazio
						cout << "---------------------------------------------\n" << endl;
						system("pause");
						system("cls");
						interacao2 = 0; // Reinicia Variavel ao Retornar para o Loop do Menu de Pagamento
					}
				}

				// Inicia Bloco de Código caso NÃO exista um Cartão de Vale Alimentação Cadastrado
				else if (interacao2 == 3 && cartao_vr[0] == "")
				{
					cout << "Nenhum Cartao cadastrado, valide um agora mesmo!" << endl;
					system("pause");
					system("cls");
					cout << "--------------- CARTAO VALE ALIMENTACAO ----------------" << endl;
					cout << "Insira o nome registrado no cartao: ";
					cin.ignore();
					getline(cin, cartao_vr[0]); // Cadastra Dados Cartão de Vale Alimentação
					cout << "Insira o numero registrado no cartao: ";
					getline(cin, cartao_vr[1]); // Cadastra Dados Cartão de Vale Alimentação
					cout << "Insira a validade registrada no cartao: ";
					cin >> cartao_vr[2]; // Cadastra Dados Cartão de Vale Alimentação
					cout << "Insira o CVV registrado no cartao: ";
					cin >> cartao_vr[3]; // Cadastra Dados Cartão de Vale Alimentação
					cout << "-------------------------------------------------------\n" << endl;

					system("cls");
					cout << "Registrando Dados . . .";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("CLS");
				}

				// Inicia Bloco de Código ao Pagar com PIX
				if (interacao2 == 4)
				{
					cout << "--------------- PIX ---------------" << endl;
					cout << "Insira sua Preferencia: " << endl;
					cout << "[0] QR CODE    [1] CHAVE PIX" << endl;
					cout << "-----------------------------------" << endl;
					// Escolha Pagamento Entre QR CODE e CHAVE PIX
					cout << "Sua Escolha: ";
					cin >> interacao3;
					system("cls");

					// Inicia Bloco de Código ao Pagar com QR CODE
					if (interacao3 == 0)
					{
						cout << "-----------------------------------\n" << endl;
						cout << "Leia o QR Code apresentado a seguir\n" << endl;
						cout << "-----------------------------------" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
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

						std::this_thread::sleep_for(std::chrono::seconds(5));
						system("cls");

						// Contador de Verificação de Pagamento (5 Segundos)
						for (int i = 6; i > 0; i--)
						{
							cout << "-----------------------------------\n" << endl;
							cout << "Conferindo Pagamento . . .  " << "\nTempo Restantes: " << i << " Segundos\n" << endl;
							cout << "-----------------------------------\n" << endl;
							std::this_thread::sleep_for(std::chrono::seconds(1));
							pagamento = 1; // Permite Chegar na Tela de Comprovante
							system("cls");
						}
						break; // Finaliza Loop Menu Formas de Pagamento
					}

					// Inicia Bloco de Código ao Pagar por Chaves Pix
					if (interacao3 == 1)
					{
						// Chaves Pix Cadastradas
						string cnpj = "32.968.893/0001-50";
						string email = "macdonals@gmail.com";
						string telefone = "(42) 9 9999-9999";
						string chave_aleatoria = "NEu4g@PZzvx";
				
						cout << "-----------------------------------" << endl;
						cout << "Chaves Pix Cadastradas: " << endl;
						cout << "-----------------------------------" << endl;
						cout << "CNPJ: " << cnpj << endl; // Printa Chave Pix
						cout << "Telefone: " << telefone << endl;  // Printa Chave Pix
						cout << "E-mail: " << email << endl;  // Printa Chave Pix
						cout << "Chave Aleatoria: " << chave_aleatoria << endl;  // Printa Chave Pix
						cout << "-----------------------------------" << endl;
						system("pause");
						system("cls");

						// Contador de Verificação de Pagamento (5 Segundos)
						for (int i = 6; i > 0; i--)
						{
							cout << "-----------------------------------\n" << endl;
							cout << "Conferindo Pagamento . . .  " << "\nTempo Restantes: " << i << " Segundos\n" << endl;
							cout << "-----------------------------------\n" << endl;
							std::this_thread::sleep_for(std::chrono::seconds(1));
							pagamento = 1; // Permite Chegar na Tela de Comprovante
							system("cls");
						}
						break; // Finaliza Loop Menu Formas de Pagamento
						
					}

				}

				//  Inicia Bloco de Código ao Verificar Cartões Cadastrados
				if (interacao2 == 5)
				{
					cout << "Cartoes Registrados: \n" << endl;

					// Printa Cartão Débito caso NÃO esteja com a array Vazia
					if (cartao_debito[0] != "")
					{
						cout << "--------------- CARTAO DEBITO ---------------" << endl;
						cout << "Nome: " << cartao_debito[0] << endl; // Printa Dados Cartão
						cout << "Numero Cartao: " << cartao_debito[1] << endl; // Printa Dados Cartão
						cout << "Validade Cartao: " << cartao_debito[2] << endl; // Printa Dados Cartão
						cout << "CVV Cartao: " << cartao_debito[3] << endl; // Printa Dados Cartão
						cout << "---------------------------------------------\n" << endl;
						interacao2 = 0;
					}

					// Printa Cartão Crédito caso NÃO esteja com a array Vazia
					if (cartao_credito[0] != "")
					{
						cout << "--------------- CARTAO CREDITO ---------------" << endl;
						cout << "Nome: " << cartao_credito[0] << endl; // Printa Dados Cartão
						cout << "Numero Cartao: " << cartao_credito[1] << endl; // Printa Dados Cartão
						cout << "Validade Cartao: " << cartao_credito[2] << endl; // Printa Dados Cartão
						cout << "CVV Cartao: " << cartao_credito[3] << endl; // Printa Dados Cartão
						cout << "----------------------------------------------\n" << endl;
						interacao2 = 0;
					}

					// Printa Cartão Vale Alimentação caso NÃO esteja com a array Vazia
					if (cartao_vr[0] != "")
					{
						cout << "----------- CARTAO VALE ALIMENTACAO -----------" << endl;
						cout << "Nome: " << cartao_vr[0] << endl; // Printa Dados Cartão
						cout << "Numero Cartao: " << cartao_vr[1] << endl; // Printa Dados Cartão
						cout << "Validade Cartao: " << cartao_vr[2] << endl; // Printa Dados Cartão
						cout << "CVV Cartao: " << cartao_vr[3] << endl; // Printa Dados Cartão
						cout << "----------------------------------------------\n" << endl;
						interacao2 = 0;
					}

					// Printa Mensagem ao Nenhum Cartão Estar Cadastrado
					if (cartao_credito[0] == "" && cartao_debito[0] == "" && cartao_vr[0] == "")

					{
						cout << "Nenhum Cartao Registrado\n" << endl;
					}

					system("pause");
					system("cls");
				}

				// Mensagem ao selecionar alguma escolha fora das disponíveis no Menu
				if (interacao2 < 0 || interacao2 > 6)
				{
					cout << "Escolha Invalida! Insira Novamente" << endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			}
			break; // Quebra Primeiro Menu Para confirmar a iniciaçao do Pagamento
		}

		// // Mensagem ao selecionar alguma escolha fora das disponíveis no Menu
		if (interacao1 < 0 || interacao1 > 1) {
			cout << "Escolha Invalida! Insira Novamente" << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
	}

	// Inicia Bloco de Código ao Pagamento ser Confirmado de Alguma das Maneiras
	if (pagamento == 1)
	{
		// Redefinindo Variáveis do Início
		// Preço Itens nos Carrinhos
		double price[3] = { 36.99, 12.99, 10.99 };
		double taxa_app = 0.05;
		taxa_app = (price[0] + price[1] + price[2]) * taxa_app;
		double total = (price[0] + price[1] + price[2]) + taxa_app;
	
		// Inicia Bloco de Códigos do Comprovante de Pagamento
		cout << " --------------- COMPROVANTE ---------------\n" << endl;
		cout << "Pagamento Concluido        HORARIO: 18:23:55\n\n" << endl;
		cout << "Total: R$" << fixed << setprecision(2) << total << endl; // Printa Pagamento Total

		// Printa nome Caso o Pagamento seja feito por Cartão de Crédito
		if (cartao_credito[0] != "")
		{
			cout << "Nome: " << cartao_credito[0] << endl;
			cout << "Forma de Pagamento: Credito\n\n" << endl;
		}

		// Printa nome Caso o Pagamento seja feito por Cartão de Débito
		else if (cartao_debito[0] != "")
		{
			cout << "Nome: " << cartao_debito[0] << endl;
			cout << "Forma de Pagamento: Debito\n\n" << endl;
		}

		// Printa nome Caso o Pagamento seja feito por Cartão de Vale Alimentação
		else if (cartao_vr[0] != "")
		{
			cout << "Nome: " << cartao_vr[0] << endl;
			cout << "Forma de Pagamento: VR\n\n" << endl;
		}
		cout << "Apresente o Seguinte codigo para retirada: AhGR81Bc\n\n" << endl;
		cout << "Tempo para Retirada: 15:03 Minutos" << endl;
		cout << "Obrigado Pela Preferencia!!!!" << endl;
		cout << " -------------------------------------------\n" << endl;
		return 0; // Finaliza Código
	}

	cout << "Compra Cancelada!!" << endl;
	cout << "Ate a Proxima . . ." << endl;
	return 0; // Finaliza Código

}