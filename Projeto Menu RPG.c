/* Cabe�alho
Institui��o: Faculdade dos Guararapes
Professor: Guibson Santana
Alunos: �ngelo Gon�alo da Silva
Turma: CCO 2-MA PIE
Data de Entrega: 30/11/2018 

Descri��o do Programa:
 
Desafio 04 � Cadastro de personagem

Resumo:	Funciona como uma estrutura de cadastro de um jogo de RPG, onde o usu�rio ir� informar um nome para o seu login, um nome para seu personagem, senha e 
seus atributos, como for�a, defesa, destreza e poder m�gico, ao final, imprime em um arquivo txt todas as informa��es.

	Mais detalhadamente o programa pede para o us�ario informar at� 10 jogadores que ir�o participar do jogo,  a partir desse ponto ser� iniciado o cadastro
de todos os jogadores, cada um ir� informar seu nome de login o programa ir� identificar e n�o deixar� que haja duplica��o, caso outro
jogador ja tenha escolhido esse nome, esse jogador ter� que informar outro nome que n�o esteja disponivel, o mesmo funciona para o nome do personagem, 
em seguida o jogador informar� sua senha e ter� que confirmar. 
	O pr�ximo passo ser� a distribui��o de pontos nos atributos de cada personagem, cada jogador tem direito a 15 pontos, que ir� distribuir nos atributos de
for�a, defesa, destreza e poder m�gico, para isso ter� algumas regras que ele ter� que seguir, que s�o:

1- A habilidade n�o pode ser de valor 0 ou menor;
2- Cada habilidade deve possuir ao menos 1 ponto;
3- N�o se pode inserir todos os pontos em apenas uma habilidade;
4- N�o deixe que falte pontos em seu personagem, utilize todos;

	Ap�s todos os passos terem sido realizados de forma correta, ir� imprimir na tela as informa��es de todos os jogadores cadastrados e ser� criado um arquivo 
de texto com todas essas informa��es.*/

//Bibliotecas 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Comando utilizado para que o struct Player seja utilizado de uma forma diferente, com o intuito de auxiliar as fun��es "compararNickUser" e "compararNickChar"
typedef struct{ 
    char nickUser[20];
    char nickChar[20];
    char senha[20];
    char confirmaSenha[20];
    int forca, destreza, poderMagico, defesa;
}Player;

/*Demonstra��o das fun��es com passagem de par�metro*/

int compararNickUser(Player verificador[], int tam) //Fun��o com passagem de par�metro, definidos por uma vari�vel int referente ao tamanho e Player da linha 44.
{
    int i; //Vari�vel que ser� usada como refer�ncia
    for(i = 0; i<tam; i++) //Ir� listar criar uma lista entre i at� o tamanho total at� o momento.
	{
	    if(strcmp(verificador[i].nickUser, verificador[tam].nickUser) == 0) //compara se nome do usu�rio digitado j� existe.
		{
            printf("\n\nUsu�rio: %s\nJ� est� em uso...\n", verificador[tam].nickUser); //Informa na tela que o nome digitado j� est� em uso
            printf("\nInforme outro usu�rio: ");
            fflush(stdin); //Limpa a entrada dos dados
            gets(verificador[tam].nickUser); //L� um novo nome de usu�rio
            return 0; //Retorna o valor 0
        }
	}
    system("cls"); //Limpa a tela
    return 1; //Retorna o valor 1
}

//Essa fun��o tem como objetivo verificar se o nome do personagem digitado ja existe
int compararNickChar(Player verificador[], int tam) //Fun��o com passagem de par�metro, definidos por uma vari�vel int referente ao tamanho e Player da linha 44.
{
	int i; //Vari�vel que ser� usada como refer�ncia
    for(i = 0; i<tam; i++) //Ir� listar criar uma lista entre i at� o tamanho total at� o momento.
	{
        if(strcmp(verificador[i].nickChar, verificador[tam].nickChar) == 0) //compara se nome do personagem digitado j� existe.
		{
	        printf("\n\nPersonagem: %s\nJ� est� em uso..\n", verificador[tam].nickChar); //Informa na tela que o nome digitado j� est� em uso
	        printf("\nInforme outro nome para o personagem: "); 
	        fflush(stdin); //Limpa a entrada dos dados
	        gets(verificador[tam].nickChar); //L� um novo nome para o personagem;
	        return 0; //Retorna o valor 0
   	 	}
	}
    system("cls"); //Limpa a tela
    return 1; //Retorna o valor 1
}

/*Foi dado a cada fun��o a responsabilidade de mostrar na tela quantos pontos foram utilizados em cada atributo.*/

void calculoPerksForca(int forca)
{
	printf("Pontos utilizados na for�a: %d\n", forca);
}
void calculoPerksDestreza(int destreza)
{
	printf("Pontos utilizados na destreza: %d\n", destreza);
}
void calculoPerksPoderMagico(int poderMagico)
{
	printf("Pontos utilizados na magia: %d\n", poderMagico);
}
void calculoPerksDefesa(int defesa)
{
	printf("Pontos utilizados na defesa: %d\n", defesa);
}
int main(void)
{
	//Fun��o utilizada para utilizada para reconhecer palavras do portugu�s, como palavras com acentua��o.
	setlocale (LC_ALL,"Portuguese");
	
	//Estrutura cadastro do Jogador
	struct Player 
	{
		char nickUser[20]; //Nome do Usu�rio, limite de 20 caracteres
		char nickChar[20]; //Nome do personagem, limite 20 caracteres
		char senha[20];    //Senha do Usuario, limite 20 caracteres
		char confirmaSenha[20]; //Confirma��o de Senha, limite 20 caracteres
		int forca, destreza, poderMagico, defesa; //Atributos do Jogador
	}; struct Player players[10]; //Define que se tem limite de at� 5 jogadores
	
	//Vari�veis
	int perks;  //Utilizada para distribui��o de pontos nos atributos
	int count; //Utilizada para criar uma refer�ncia
	int qntdPlayer; //Utilizada para identificar a quantidade de jogadores
	
	/*Arte ilustrativa do site: www.asciiarte.com 
	Menu do Jogo*/
		
	printf("                     /\\  \n");
	printf("                    / |\\ \n");
	printf("                   / /\\ \\\ \n");
	printf("                  / /  \\ \\\ \n");
	printf("                 / /    \\ \\\ \n");
	printf("                /_/      \\_\\ \n");
	printf("                \\    '`    / \n");
	printf("                 )   ||   ( \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("                 |   ||   | \n");
	printf("     /           |   ||   |           \\ \n");
	printf("    /(           |   ||   |           )\\ \n");
	printf("    |`\\_         |   ||   |         _/'| \n");
	printf("    |`. `-._     |   ||   |     _,-' ,'|                     BEM VINDO JOGADOR!\n");
	printf("    (   ` . `-._ |  _--_  | _,-' , '   )             Pressione qualquer tecla para Iniciar.\n");
	printf("     `.._   ` . `-./.__.\.-' , '   _,-' \n");
	printf("         `-._   ` | /  \\ | '   _,-' \n");
	printf("             `-._/ |_()_| \\_,-' \n");
	printf("           ___.-'   ______   `-, \n");
	printf("          '-----.  |______|   /  \n");
	printf("                 \\  ______   / \n");
	printf("                 |  \\>  </  / \n");
	printf("                  \\________/ \n");
	printf("                  _]______[_ \n");
	printf("                  |*      *| \n");
	printf("                  |________| \n");
	printf("                   ]______[# \n");
	printf("                  |        | \n");
	printf("                  |________| \n");
	printf("                  _]______[_ \n");
	printf("                  |*      *| \n");
	printf("                  |________| \n");
	printf("                  _]______[_ \n");
	printf("                  |        | \n");
	printf("                  |________| \n");
	printf("                    ]____[ \n");
	printf("                  .'      `. \n");
	printf("                  | <   >  |> \n");
	printf("                 <|   <   >| \n");
	printf("                   `.____.' \n");
	printf("                     V   V \n");
	printf("->");
	
	getch(); //L� uma tecla
	system("cls"); //Limpa a tela
	
	//Mensagens de intera��o com o usu�rio
	printf("\t\tOl� Jogador, Como vai?\n");
	printf("\t\tEst� pronto para come�ar uma nova jornada?\n");
	
	printf("\n\nPor favor, Informe quantos jogadores ser�o cadastrados(Limite de 10 jogadores): ");
	scanf("%d", &qntdPlayer); //L� a quantidade de jogadores que o usu�rio quer preencher, de 1 a 5
	if (qntdPlayer > 0 && qntdPlayer <= 10) //Express�o condicional para que identifique se o numero digitado est� entre os valores 1 e 5
	{
		//La�o de repeti��o, ir� repetir o trecho at� que todas as informa��es de todos os jogadores sejam preenchidas
		for (count = 0; count < qntdPlayer; count++)
		{
			system("cls"); //Comando limpa tela
			fflush(stdin); //Limpa a entrada dos dados
			
			//Mensagens interativas
			printf("\t\t!!ATEN��O!!\n");
			printf("Os nomes tem o limite de at� 20 caracteres, informe de maneira correta.\n\n");
			
			printf("Nome do Usu�rio:");
			gets(players[count].nickUser); //L� o nome digitado pelo us�ario e guarda na vari�vel count, que pode variar dependendo de qual jogador est� preenchendo no momento
			while(compararNickUser(players, count)!=1);	//Enquanto a compara��o realizada pela fun��o "compararNickUser" for diferente de 1, ele continuar� repetindo a fun��o at� que o usu�rio informe um nome de usu�rio que ainda n�o tenha sido cadastrado no sistema.		
			printf("\nMuito bem, voc� usar� esse nome para realizar o login no jogo!\nLogin: %s\n", players[count].nickUser); //Mostra na tela o nome digitado pelo usu�rio
			
			printf("Pressione qualquer tecla para continuar.");
			getch(); //Ir� ler a tecla digitada
			system("cls"); //Limpa a tela 
			fflush(stdin); //Limpa a entrada dos dados
			//Mensagens de intera��o
			printf("Por favor, agora insira o nome do personagem\nDica: Escolha um nome maneiro, esse ser� o nome que seus amigos o reconhecer�o no jogo!\n");
			printf("Nome do Personagem:");
			gets(players[count].nickChar); //Ir� ler o que o usu�rio escrever
			while(compararNickChar(players, count)!=1);	//Enquanto a compara��o realizada pela fun��o "compararNickChar" for diferente de 1, ele continuar� repetindo a fun��o at� que o usu�rio informe um nome de usu�rio que ainda n�o tenha sido cadastrado no sistema.
			printf("\nPerfeito, � assim que seus amigos o reconhecer�o!\nNick: %s\n", players[count].nickChar); //Retorna a tela o nome que o usu�rio digitou
			
			//Mensagens Informativas
			printf("Pressione qualquer tecla para continuar.");
			getch(); //L� uma tecla
			system("cls"); //Limpa a tela
			fflush(stdin); //Limpa a entrada dos dados
			
			//Mensagens de Informa��o
			printf("\t\tMuito bem, seguiremos para o pr�ximo passo!\n");
			printf("\t\tAgora vamos seguir com o registro da senha do seu Login!\n");
			printf("\t\tInforme uma senha de at� 20 caracteres!\n\n");
			printf("Dica: Utilize uma senha composta por caracteres especiais, n�meros e letras mai�sculas e min�sculas, ir� ajudar em sua seguran�a.\n\n");
			
			printf("Senha: ");
			gets(players[count].senha); //Ir� ler a senha digitada
			printf("Repita a senha para que ocorra a confirma��o.\n\nConfirma��o de Senha:");//Ir� pedir para que o usu�rio repita a senha
			gets(players[count].confirmaSenha); //IUsu�rio deve repetir a senha de forma correta
			
			do //Fun��o do, para que utilize-a ao menos uma vez
			{
				if (strcmp (players[count].senha, players[count].confirmaSenha)) //Express�o comdicional, ir� checar se as senhas s�o diferentes
				{
					//Mensagens informativas
					printf("Algo deu errado, as senhas n�o s�o iguais, por favor, tente mais uma vez\n");
					printf("Tome cuidado com a sua senha, ela � muito importante!\n\n");
					printf("Confirma��o de Senha:");
					gets(players[count].confirmaSenha); //Usu�rio deve repetir a senha de forma correta
				}
				else 
				{
					printf("\nMais uma etapa concluida com louvor!\n"); //Mensagem informativa
				}
			}while (strcmp (players[count].senha, players[count].confirmaSenha)); //Enquanto as senhas forem diferentes, ele repetir� tudo novamente, a partir do if
				
				//Mensagens Informativas
				printf("\nPressione qualquer tecla para continuar.");
				getch(); //L� uma tecla
				system("cls"); //Limpa tela
		}
			//Mensagens de intera��o com o usu�rio
			printf("\t\t\tAgora iremos distribuir juntos os pontos de habilidade do seu personagem.\n"); 
			printf("\t\t\tIsso ir� definir basicamente a sua fun��o no jogo, escolha com cuidado... XD\n");
			printf("\t\t\tSer�o esses pontos que lhe far�o ter mais facilidades para ser de determinada classe.\n");
			printf("\t\t\tS�o elas, Guerreiro, Guardi�o, Mago, Ladr�o e o Ningu�m.\n\n");
			
			printf("Leia atentamente as informa��es acima, caso as tenha entendido, clique qualquer tecla para continuar.");
			getch(); //L� uma tecla
			system("cls"); //Limoa tela
			
			//Aqui ser� exibido um pequeno resumo sobre as classes do jogo, para ajuda-lo a distribuir seus pontos de uma forma adequada
			printf("Informa��es sobre as classes:\n\n");
			printf("\nGuerreiro:  Seria a classe em que o seu foco � a for�a, um personagem bruto pronto para destro�ar seus inimigos sem medo algum. \n");
			printf("\nGuardi�o: Guardi�es s�o conhecidos pela sua grande resist�ncia, s�o extremamente �teis, sendo a linha de frente de seus aliados.\n");
			printf("\nMago: A arte da feinti�aria � uma das mais antigas em nossa hist�ria, os magos s�o seres de intelecto superior e grande controlador de magias, sendo utilizado tanto como dano bruto quanto para ser utilizado como defensor de seus aliados, � uma classe complexa e n�o recomendada se voc� � inexperiente em jogos estilo RPG.\n");
			printf("\nLadr�o: S�o peritos em atividades sil�nciosas, costumam entrar e sair de lugares sem serem vistos e deixam um grande estrago, s�o peritos em armas de curto alcance, como adagas, e com armas a dist�ncia, como arco e flecha e a besta.\n");
			printf("\nNingu�m: S�o pessoas cujo comuns, com balanceamento em todas as habilidades, n�o sendo forte em nenhuma delas, mas que mesmo assim ainda pode ser desenvolvida com bastante treinamento.\n");
			
			printf("Leia atentamente as informa��es acima, caso as tenha entendido, clique qualquer tecla para continuar");
			getch(); //L� uma tecla
			system("cls"); //Limpa tela
			
			for(count = 0; count < qntdPlayer; count++) //La�o de repeti��o que ir� repetir o n�mero de jogadores em jogo
			{
				//Mensagens Informativas
				printf("Ser� iniciada a distribui��o das habilidades do jogador: %s.\n\n", players[count].nickUser); //Ir� exibir na tela o nome do usu�rio da vez
				printf("Personagem: %s\n\n", players[count].nickChar); //Ir� exibir na tela o nome do personagem do usu�rio da vez
				
				//Cita��o das Regras de distribui�ao de pontos
				printf("Vale resaltar que voc� precisa seguir algumas regras na distribui��o de pontos, Fique atento!!\n");
				printf("1- A habilidade n�o pode ser de valor 0 ou menor\n");
				printf("2- Cada habilidade deve possuir ao menos 1 ponto\n");
				printf("3- N�o se pode inserir todos os pontos em apenas uma habilidade\n");
				printf("4- N�o deixe que falte pontos em seu personagem, utilize todos!");
				
				do //Fun��o do, para que utilize-a ao menos uma vez
				{
					perks = 15; //Atribui o valor de pontos a serem distribuidos como 15
					printf("\n\nPontos: %d\n", perks); //Exibir� na tela o valor de pontos disponiveis
					printf("For�a: "); //Mensagem informativa
					scanf("%d", &players[count].forca); // Ir� ler a quantidade de pontos insedira pelo usu�rio
					do //Fun��o do, para que utilize-a ao menos uma vez
					{
						if (players[count].forca <=0 || players[count].forca > 12) //Express�o comdicional, ir� checar se a quantidade informada n�o est� dentro das regras
						{
							//Mensagens informativas 
							printf("Aten��o cidad�o, voc� est� violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos: %d\n", perks); //Mostrar� na tela novamente o valor que se tem disponivel
							printf("For�a: ");
							scanf("%d", &players[count].forca);  //Ir� ler a quantidade de pontos digitada
						}
					}while  (players[count].forca <=0 || players[count].forca > 12); //Repetir� a fun��o at� que a quantidade correta seja digitada
					system("cls"); //Limpa a tela
					
					calculoPerksForca(players[count].forca); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de for�a
					perks = perks - players[count].forca; //C�lculo da diferen�a para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Destreza: ");
					scanf("%d", &players[count].destreza); // Ir� ler a quantidade de pontos inserira pelo usu�rio
					do //Fun��o do, para que utilize-a ao menos uma vez
					{
						if (players[count].destreza <=0 || players[count].destreza > perks - 2) //Express�o comdicional, ir� checar se a quantidade informada n�o est� dentro das regras
						{
							//Mensagens informativas 
							printf("Aten��o cidad�o, voc� est� violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mostrar� na tela novamente o valor que se tem disponivel
							printf("Destreza: ");
							scanf("%d", &players[count].destreza); //Ir� ler a quantidade de pontos digitada
						}
					}while (players[count].destreza <=0 || players[count].destreza > perks - 2); //Repetir� a fun��o at� que a quantidade correta seja digitada
				
					system("cls"); //Limpa tela
					
					calculoPerksForca(players[count].forca); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de for�a
					calculoPerksDestreza(players[count].destreza); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de destreza
					perks = perks - players[count].destreza; //C�lculo da diferen�a para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Poder M�gico: ");
					scanf("%d", &players[count].poderMagico); // Ir� ler a quantidade de pontos inserira pelo usu�rio
					
					do //Fun��o do, para que utilize-a ao menos uma vez
					{
						if(players[count].poderMagico <=0 || players[count].poderMagico > perks - 1) //Express�o comdicional, ir� checar se a quantidade informada n�o est� dentro das regras
						{
							//Mensagens informativas 
							printf("Aten��o cidad�o, voc� est� violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mostrar� na tela novamente o valor que se tem disponivel
							printf("Poder M�gico: ");
							scanf("%d", &players[count].poderMagico); //Ir� ler a quantidade de pontos digitada
						}
					} while(players[count].poderMagico <=0 || players[count].poderMagico > perks - 1); //Repetir� a fun��o at� que a quantidade correta seja digitada
					
					system("cls");
					
					calculoPerksForca(players[count].forca); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de for�a
					calculoPerksDestreza(players[count].destreza); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de destreza
					calculoPerksPoderMagico(players[count].poderMagico); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de poder m�gico
					perks = perks - players[count].poderMagico; //C�lculo da diferen�a para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Defesa: ");
					scanf("%d", &players[count].defesa); //Ir� ler a quantidade de pontos digitada
					
					do
					{
						if(players[count].defesa <=0 || players[count].defesa > perks) //Express�o comdicional, ir� checar se a quantidade informada n�o est� dentro das regras
						{
							//Mensagens informativas 
							printf("Aten��o cidad�o, voc� est� violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
							printf("Defesa: ");
							scanf("%d", &players[count].defesa); //Ir� ler a quantidade de pontos digitada
						}
					}while (players[count].defesa <=0 || players[count].defesa > perks); //Repetir� a fun��o at� que a quantidade correta seja digitada
					
					perks = perks - players[count].defesa; //C�lculo da diferen�a para continuar com a quantidade correta  de pontos
					system("cls"); //Limpa tela
					
				}while(perks != 0); //Repetir� todo o la�o caso o jogador n�o tenha utilizado todos os pontos disponiveis
				
				system("cls"); //limpa a tela
				calculoPerksForca(players[count].forca); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de for�a
				calculoPerksDestreza(players[count].destreza); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de destreza
				calculoPerksPoderMagico(players[count].poderMagico); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos de poder m�gico	 
				calculoPerksDefesa(players[count].defesa); //Ir� mostrar na tela as informa��es da utiliza��o dos pontos da defesa	 
			}		
			printf("Pressione qualquer tecla para finalizar.");
			getch(); //L� uma tecla
			system("cls"); //Limpa a tela
			printf("Dados dos Jogadores:\n");
			
		for (count = 0; count < qntdPlayer; count++) //Comando para listar todos os jogadores que foram preenchidos.
		{
			printf("\nUsu�rio: %s\n",players[count].nickUser); //Mostra na tela o nome do usu�rio
			printf("Personagem: %s\n",players[count].nickChar); //Mostra na tela o nome do personagem do usu�rio
			printf("Senha: %s\n\n",players[count].senha); //Mostra na tela a senha do usu�rio 
			printf("Atributos:\n");
			printf("For�a: %d\n",players[count].forca); //Mostra na tela a for�a
			printf("Destreza: %d\n",players[count].destreza); //Mostra na tela a destreza
			printf("Poder M�gico: %d\n",players[count].poderMagico); //Mostra na tela o poder magico
			printf("Defesa: %d\n",players[count].defesa); //Mostra na tela a defesa
		}	
		FILE *Pfile; //Declara��o do ponteiro do arquivo
		Pfile = fopen("dados.txt", "w"); //Abre o arquivo txt para grava��o
		if (Pfile == NULL) //Caso ocorra alguma complica��o ir� demonstrar a mensagem abaixo e encerrar� o programa
		{
			//Mensagem informativa
			printf("Erro na abertura do arquivo.");
			exit(0); //Encerra
		}
		for (count = 0; count < qntdPlayer; count++) //Lsita as informa��es de todos os jogadores no arquivo criado
		{
			fprintf(Pfile, "\nNome: %s\n",players[count].nickUser);
			fprintf(Pfile, "Personagem: %s\n",players[count].nickChar);
			fprintf(Pfile, "Senha: %s\n",players[count].senha);
			fprintf(Pfile, "For�a: %d\n",players[count].forca);
			fprintf(Pfile, "Destreza: %d\n",players[count].destreza);
			fprintf(Pfile, "Poder M�gico: %d\n",players[count].poderMagico);
			fprintf(Pfile, "Defesa: %d\n",players[count].defesa);
		}
		fclose(Pfile); //Fecha o arquivo 		
	}
	else
	{
		printf("\nErrou feio, errou rude\nAcho que voc� n�o devia estar aqui...\nInsira o n�mero de participantes corretamente");
		return 0; //Encerra o programa
	}
}
