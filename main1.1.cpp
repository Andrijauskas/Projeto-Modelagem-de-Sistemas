/*
Data: 01/05/2017
Integrantes: Adriana Andrijauskas e Willian Utsumi
Disciplina: Modelagem de Sistemas
Professor: Destro.
Descri��o: Projeto de laborat�rio. Simula��o da bolsa de valores.
*/

#include <iostream>
#include <windows.h> //biblioteca para mudar o nome da janela de console
#include <fstream> //manipular arquivos
#include <string>
using namespace std;

//fazer
class Protocolo
{
	public:
		//definir todas as vari�veis
		int corretora; //identificador da corretora
		int cliente; //identificador do cliente da corretora acima
		int tipo; //O.C. ou O.V.
		int nome; //identificador da a��o
		int tempo; //quantidade de preg�es que a a��o ficar� ativa
		int qtd; //quantidade de a��es
		float valor; //valor unit�rio da a��o
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

//Login dos administradores e das corretoras; acho que Funcion�rio n�o precisa ser uma classe, poir ele � apenas o login (manipula��o do arquivo Usuarios.txt)
int cadastrarUsuario();
int validarUsuario();
//Menu do administrador da bolsa e op��es de a��es
void menuBolsa();
void manutencao();
void relatorios();
//Menu das corretoras e op��es de a��es
void menuCorretora();
void painel();
void gerenciarOrdem();
int cadastrarCliente();
int validarCliente();

//ok
int cadastrarUsuario(int verificadorLogin)
{
	SetConsoleTitle("Cadastro de usuario :)"); //nome da janela de console
	system ("cls");
	
	ofstream arquivo ("Usuarios.txt", ios_base::app); //habilita para escrita sem sobreposi��o no arquivo
	string nome;
	cout << "Nome: " << endl;
	cin >> nome;
	arquivo << nome << endl;
	verificadorLogin=1; //usu�rio autenticado
	arquivo.close();
	return verificadorLogin;
}

//ok
int validarUsuario()
{
	SetConsoleTitle("Login :)"); //nome da janela de console
	int verificadorLogin=0; //passo para o main, para permitir ou n�o o acesso ao menu
	ifstream arquivo("Usuarios.txt"); //habilita para leitura no arquivo
	string nome="";
	string senha="";
	int verificadorPalavra=0;
	cout << "Nome: ";
	cin >> nome;
	cout << "Senha: ";
	cin >> senha;
	string palavraAtual="";
	string palavraAnterior="";
	if(senha=="sucodebraco") //senha padr�o
	{
		while(!arquivo.eof()) //para no final do arquivo
		{
			getline(arquivo, palavraAtual);//salva a linha atual
			if(palavraAtual==nome)
			{
				verificadorPalavra=1; //usu�rio encontrado
			}
		}
		if (verificadorPalavra==1)
		{
			verificadorLogin=1; //usu�rio autenticado
		}
		else
		{
			cout << "Usuario nao encontrado..." << endl;
			string cadastro="";
			cout << "Realizar cadastro?(S/N)" << endl;
			cin >> cadastro;
			if(cadastro=="S" || cadastro=="s")
			{
				verificadorLogin=cadastrarUsuario(verificadorLogin); //cadastro de usu�rio
			}
			else
			{
				verificadorLogin=-2; //usu�rio n�o autenticado
				exit;
			}
		}
		arquivo.close();
		return verificadorLogin; //usu�rio autenticado ou usu�rio n�o autenticado
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
	
	cout <<"Opcao 1" << endl;
	system ("pause");
}

//fazer
void relatorios()
{
	SetConsoleTitle("Relatorios :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Opcao 2" << endl;
	system ("pause");
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
	cout << "2. Gerenciar Ordem de compra ou Ordem de venda" << endl;
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

//fazer
void painel()
{
	SetConsoleTitle("Painel de exibicao das acoes :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Opcao 1" << endl;
	system ("pause");
}

//fazer
void gerenciarOrdem()
{
	SetConsoleTitle("Gerenciar Ordem de compra ou Ordem de venda :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Opcao 2" << endl;
	system ("pause");
}

//fazer
int cadastrarCliente()
{
	SetConsoleTitle("Cadastrar clientes :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Opcao 3.1" << endl;
	system ("pause");
}

//fazer
int validarCliente()
{
	SetConsoleTitle("Validar clientes :)"); //nome da janela de console
	system ("cls");
	
	cout <<"Opcao 3" << endl;
	system ("pause");
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
