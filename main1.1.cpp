/*
Data: 01/05/2017
Integrantes: Adriana Andrijauskas e Willian Utsumi
Disciplina: Modelagem de Sistemas
Professor: Destro.
Descrição: Projeto de laboratório. Simulação da bolsa de valores.
*/

#include <iostream>
#include <windows.h> //biblioteca para mudar o nome da janela de console
#include <fstream> //manipular arquivos
#include <string>
using namespace std;

//variáveis globais
string sd="dealbroker"; //senha padrão dos administradores da bolsa de valores
string sb="broker"; //senha padrão das corretoras

//Protótipos de funções
//Login dos administradores e das corretoras; acho que Funcionário não precisa ser uma classe, poir ele é apenas o login (manipulação do arquivo Usuarios.txt)
int cadastrarUsuario();
int validarUsuario();
//Menu do administrador da bolsa e opções de ações
void menuBolsa();
void manutencao();
void relatorios();
//Menu das corretoras e opções de ações
void menuCorretora();
void painel();
void gerenciarOrdem();
int validarCliente();

//fazer
class Protocolo
{
	public:
		//definir todas as variáveis
		int corretora; //identificador da corretora
		int cliente; //identificador do cliente da corretora acima
		int tipo; //O.C. ou O.V.
		int nome; //identificador da ação
		int tempo; //quantidade de pregões que a ação ficará ativa
		int qtd; //quantidade de ações
		float valor; //valor unitário da ação
		void gerarProtocolo();
};

//fazer
class Acao
{
	public:
		string nome;
		int id;
		float valor;
};

//ok
int cadastrarUsuario(int verificadorLogin, string senha)
{
	SetConsoleTitle("Cadastro de usuario :)"); //nome da janela de console
	system ("cls");
	
	ofstream arquivo ("Usuarios.txt", ios_base::app); //habilita para escrita sem sobreposição no arquivo
	string nome;
	cout << "Nome: " << endl;
	cin >> nome;
	arquivo << nome << endl;
	if (senha==sd)
		verificadorLogin=1; //administrador da bolsa autenticado
	else if (senha==sb)
		verificadorLogin=2; //funcionário da corretora autenticado
	arquivo.close();
	return verificadorLogin;
}

//ok
int validarUsuario()
{
	SetConsoleTitle("Login :)"); //nome da janela de console

	int verificadorLogin=0; //passo para o main, para permitir ou não o acesso ao menu
	string nome="";
	string senha="";
	int verificadorPalavra=0;
	cout << "Nome: ";
	cin >> nome;
	cout << "Senha: ";
	cin >> senha;
	string palavraAtual="";
	string palavraAnterior="";
	if(senha==sd || senha==sb) //senhas padrões
	{
		ifstream arquivo("Usuarios.txt"); //habilita para leitura no arquivo; para melhorar podemos diferenciar dealbroker e broker	
		while(!arquivo.eof()) //para no final do arquivo
		{
			getline(arquivo, palavraAtual);//salva a linha atual
			if(palavraAtual==nome)
				verificadorPalavra=7; //usuário encontrado
		}
		if (verificadorPalavra==7)
		{
			if(senha==sd)
				verificadorLogin=1; //administrador da bolsa autenticado
			else if (senha==sb)
				verificadorLogin=2; //funcionário da corretora autenticado
		}
		else
		{
			cout << "Usuario nao encontrado..." << endl;
			string cadastro="";
			cout << "Realizar cadastro?(S/N)" << endl;
			cin >> cadastro;
			if(cadastro=="S" || cadastro=="s")
				verificadorLogin=cadastrarUsuario(verificadorLogin, senha); //cadastro de usuário
			else
			{
				verificadorLogin=-2; //usuário não autenticado
				exit;
			}
		}
		arquivo.close();
		return verificadorLogin; //usuário autenticado ou usuário não autenticado
	}
	verificadorLogin=-1; //senha incorreta
	return verificadorLogin;
}

//ok
void menuBolsa()
{
	SetConsoleTitle("Menu da Bolsa de Valores :)"); //nome da janela de console
	system ("cls");
	
	int op=0;
	cout << "MENU\n" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Manutencao" << endl;
	cout << "2. Geracao de relatorios" << endl;
	cin >> op;
	
	switch(op)
	{
		case 0:
			break;
		case 1:
			manutencao();
			menuBolsa();			
			break;
		case 2:
			relatorios();
			menuBolsa();
			break;
	}
}

//fazer
void manutencao()
{
	SetConsoleTitle("Manutencao :)"); //nome da janela de console
	system ("cls");
	
	int op=0;
	cout << "MENU DE MANUTENCAO\n" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Definir da hora de abertura e fechamento dos pregoes" << endl;
	cout << "2. Definir o preco de abertura" << endl;
	cout << "3. Painel de exibicao das acoes" << endl;
	cin >> op;
	
	switch(op)
	{
		case 0:
			break;
		case 1:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "opcao 1 de manutencao" << endl;
			system("pause");
			manutencao();
			break;
		case 2:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "opcao 2 de manutencao" << endl;
			system("pause");
			manutencao();
			break;
		case 3:
			painel();
			manutencao();
			break;
	}
}

//fazer
void relatorios()
{
	SetConsoleTitle("Relatorios :)"); //nome da janela de console
	system ("cls");
	
	int op=0;
	cout << "MENU DE RELATORIOS\n" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Consolidar relatorios do dia" << endl;
	cout << "2. Gerar relatorio para auditoria" << endl;
	cin >> op;
	
	switch(op)
	{
		case 0:
			break;
		case 1:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "Implementar opcao 1 de relatorios..." << endl;
			system("pause");
			relatorios();
			break;
		case 2:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "Implementar opcao 2 de relatorios..." << endl;
			system("pause");
			relatorios();
			break;
	}
}

//ok
void menuCorretora()
{
	SetConsoleTitle("Menu das Corretoras :)"); //nome da janela de console
	system ("cls");
	
	int op=0;
	cout << "MENU\n" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Painel de exibicao das acoes" << endl;
	cout << "2. Gerenciar ordem de compra ou ordem de venda" << endl;
	cout << "3. Validacao de clientes" << endl;
	cin >> op;
	
	switch(op)
	{
		case 0:
			break;
		case 1:
			painel();
			menuCorretora();		
			break;
		case 2:
			gerenciarOrdem();
			menuCorretora();
			break;
		case 3:
			validarCliente();
			menuCorretora();
			break;
	} 
}

//fazer MUITO
void painel()
{
	SetConsoleTitle("Painel de exibicao das acoes :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Implementar o painel..." << endl; //apenas imprimir o arquivo onde as ações estão salvas
	system ("pause");
}

//fazer
void gerenciarOrdem()
{
	SetConsoleTitle("Gerenciar ordem de compra ou ordem de venda :)"); //nome da janela de console
	system ("cls");
	
	int op=0;
	cout << "MENU DAS ORDENS\n" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Cadastrar" << endl;
	cout << "2. Cancelar" << endl;	
	cin >> op;
	
	switch(op)
	{
		case 0:
			break;
		case 1:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "opcao 1 de gerenciar ordem" << endl;
			system("pause");
			gerenciarOrdem();		
			break;
		case 2:
			//redirecionar para alguma função, ou codificar aqui mesmo
			cout << "opcao 2 de gerenciar ordem" << endl;
			system("pause");
			gerenciarOrdem();
			break;
	} 
}

//fazer em conjunto com os brokers
int validarCliente()
{
	SetConsoleTitle("Validacao de clientes :)"); //nome da janela de console
	system ("cls");
	
	int cpf=0;
	cout << "Digite o cpf do cliente: " << endl;
	cin >> cpf;
	
	
	//mandar o cpf para todos os broker fazerem a verificação, se retornar -1 é pq existe (não pode cadastrar), se retornar 1 é pa não existe (pode cadastrar)
	int verificador=0;
	cout << "*******Implementar a chamada de função em todos os brokers. Passar o resultado para o broker que solicitou.*******" << endl;

	system("pause");
	return 0;
}

//ok
int main()
{
	int v=validarUsuario();
	if(v==1)
		menuBolsa();
	else if(v==2)
		menuCorretora();
	else if(v==-1)
		cout << "Senha incorreta..." << endl;
	else if(v==-2)
		cout << "Usuario nao possui login..." << endl;
	
	return 0;
}
