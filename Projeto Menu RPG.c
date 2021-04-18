/* Cabeçalho
Instituição: Faculdade dos Guararapes
Professor: Guibson Santana
Alunos: Ângelo Gonçalo da Silva
Turma: CCO 2-MA PIE
Data de Entrega: 30/11/2018 

Descrição do Programa:
 
Desafio 04 – Cadastro de personagem

Resumo:	Funciona como uma estrutura de cadastro de um jogo de RPG, onde o usuário irá informar um nome para o seu login, um nome para seu personagem, senha e 
seus atributos, como força, defesa, destreza e poder mágico, ao final, imprime em um arquivo txt todas as informações.

	Mais detalhadamente o programa pede para o usúario informar até 10 jogadores que irão participar do jogo,  a partir desse ponto será iniciado o cadastro
de todos os jogadores, cada um irá informar seu nome de login o programa irá identificar e não deixará que haja duplicação, caso outro
jogador ja tenha escolhido esse nome, esse jogador terá que informar outro nome que não esteja disponivel, o mesmo funciona para o nome do personagem, 
em seguida o jogador informará sua senha e terá que confirmar. 
	O próximo passo será a distribuição de pontos nos atributos de cada personagem, cada jogador tem direito a 15 pontos, que irá distribuir nos atributos de
força, defesa, destreza e poder mágico, para isso terá algumas regras que ele terá que seguir, que são:

1- A habilidade não pode ser de valor 0 ou menor;
2- Cada habilidade deve possuir ao menos 1 ponto;
3- Não se pode inserir todos os pontos em apenas uma habilidade;
4- Não deixe que falte pontos em seu personagem, utilize todos;

	Após todos os passos terem sido realizados de forma correta, irá imprimir na tela as informações de todos os jogadores cadastrados e será criado um arquivo 
de texto com todas essas informações.*/

//Bibliotecas 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Comando utilizado para que o struct Player seja utilizado de uma forma diferente, com o intuito de auxiliar as funções "compararNickUser" e "compararNickChar"
typedef struct{ 
    char nickUser[20];
    char nickChar[20];
    char senha[20];
    char confirmaSenha[20];
    int forca, destreza, poderMagico, defesa;
}Player;

/*Demonstração das funções com passagem de parâmetro*/

int compararNickUser(Player verificador[], int tam) //Função com passagem de parâmetro, definidos por uma variável int referente ao tamanho e Player da linha 44.
{
    int i; //Variável que será usada como referência
    for(i = 0; i<tam; i++) //Irá listar criar uma lista entre i até o tamanho total até o momento.
	{
	    if(strcmp(verificador[i].nickUser, verificador[tam].nickUser) == 0) //compara se nome do usuário digitado já existe.
		{
            printf("\n\nUsuário: %s\nJá está em uso...\n", verificador[tam].nickUser); //Informa na tela que o nome digitado já está em uso
            printf("\nInforme outro usuário: ");
            fflush(stdin); //Limpa a entrada dos dados
            gets(verificador[tam].nickUser); //Lê um novo nome de usuário
            return 0; //Retorna o valor 0
        }
	}
    system("cls"); //Limpa a tela
    return 1; //Retorna o valor 1
}

//Essa função tem como objetivo verificar se o nome do personagem digitado ja existe
int compararNickChar(Player verificador[], int tam) //Função com passagem de parâmetro, definidos por uma variável int referente ao tamanho e Player da linha 44.
{
	int i; //Variável que será usada como referência
    for(i = 0; i<tam; i++) //Irá listar criar uma lista entre i até o tamanho total até o momento.
	{
        if(strcmp(verificador[i].nickChar, verificador[tam].nickChar) == 0) //compara se nome do personagem digitado já existe.
		{
	        printf("\n\nPersonagem: %s\nJá está em uso..\n", verificador[tam].nickChar); //Informa na tela que o nome digitado já está em uso
	        printf("\nInforme outro nome para o personagem: "); 
	        fflush(stdin); //Limpa a entrada dos dados
	        gets(verificador[tam].nickChar); //Lê um novo nome para o personagem;
	        return 0; //Retorna o valor 0
   	 	}
	}
    system("cls"); //Limpa a tela
    return 1; //Retorna o valor 1
}

/*Foi dado a cada função a responsabilidade de mostrar na tela quantos pontos foram utilizados em cada atributo.*/

void calculoPerksForca(int forca)
{
	printf("Pontos utilizados na força: %d\n", forca);
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
	//Função utilizada para utilizada para reconhecer palavras do português, como palavras com acentuação.
	setlocale (LC_ALL,"Portuguese");
	
	//Estrutura cadastro do Jogador
	struct Player 
	{
		char nickUser[20]; //Nome do Usuário, limite de 20 caracteres
		char nickChar[20]; //Nome do personagem, limite 20 caracteres
		char senha[20];    //Senha do Usuario, limite 20 caracteres
		char confirmaSenha[20]; //Confirmação de Senha, limite 20 caracteres
		int forca, destreza, poderMagico, defesa; //Atributos do Jogador
	}; struct Player players[10]; //Define que se tem limite de até 5 jogadores
	
	//Variáveis
	int perks;  //Utilizada para distribuição de pontos nos atributos
	int count; //Utilizada para criar uma referência
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
	
	getch(); //Lê uma tecla
	system("cls"); //Limpa a tela
	
	//Mensagens de interação com o usuário
	printf("\t\tOlá Jogador, Como vai?\n");
	printf("\t\tEstá pronto para começar uma nova jornada?\n");
	
	printf("\n\nPor favor, Informe quantos jogadores serão cadastrados(Limite de 10 jogadores): ");
	scanf("%d", &qntdPlayer); //Lê a quantidade de jogadores que o usuário quer preencher, de 1 a 5
	if (qntdPlayer > 0 && qntdPlayer <= 10) //Expressão condicional para que identifique se o numero digitado está entre os valores 1 e 5
	{
		//Laço de repetição, irá repetir o trecho até que todas as informações de todos os jogadores sejam preenchidas
		for (count = 0; count < qntdPlayer; count++)
		{
			system("cls"); //Comando limpa tela
			fflush(stdin); //Limpa a entrada dos dados
			
			//Mensagens interativas
			printf("\t\t!!ATENÇÃO!!\n");
			printf("Os nomes tem o limite de até 20 caracteres, informe de maneira correta.\n\n");
			
			printf("Nome do Usuário:");
			gets(players[count].nickUser); //Lê o nome digitado pelo usúario e guarda na variável count, que pode variar dependendo de qual jogador está preenchendo no momento
			while(compararNickUser(players, count)!=1);	//Enquanto a comparação realizada pela função "compararNickUser" for diferente de 1, ele continuará repetindo a função até que o usuário informe um nome de usuário que ainda não tenha sido cadastrado no sistema.		
			printf("\nMuito bem, você usará esse nome para realizar o login no jogo!\nLogin: %s\n", players[count].nickUser); //Mostra na tela o nome digitado pelo usuário
			
			printf("Pressione qualquer tecla para continuar.");
			getch(); //Irá ler a tecla digitada
			system("cls"); //Limpa a tela 
			fflush(stdin); //Limpa a entrada dos dados
			//Mensagens de interação
			printf("Por favor, agora insira o nome do personagem\nDica: Escolha um nome maneiro, esse será o nome que seus amigos o reconhecerão no jogo!\n");
			printf("Nome do Personagem:");
			gets(players[count].nickChar); //Irá ler o que o usuário escrever
			while(compararNickChar(players, count)!=1);	//Enquanto a comparação realizada pela função "compararNickChar" for diferente de 1, ele continuará repetindo a função até que o usuário informe um nome de usuário que ainda não tenha sido cadastrado no sistema.
			printf("\nPerfeito, é assim que seus amigos o reconhecerão!\nNick: %s\n", players[count].nickChar); //Retorna a tela o nome que o usuário digitou
			
			//Mensagens Informativas
			printf("Pressione qualquer tecla para continuar.");
			getch(); //Lê uma tecla
			system("cls"); //Limpa a tela
			fflush(stdin); //Limpa a entrada dos dados
			
			//Mensagens de Informação
			printf("\t\tMuito bem, seguiremos para o próximo passo!\n");
			printf("\t\tAgora vamos seguir com o registro da senha do seu Login!\n");
			printf("\t\tInforme uma senha de até 20 caracteres!\n\n");
			printf("Dica: Utilize uma senha composta por caracteres especiais, números e letras maiúsculas e minúsculas, irá ajudar em sua segurança.\n\n");
			
			printf("Senha: ");
			gets(players[count].senha); //Irá ler a senha digitada
			printf("Repita a senha para que ocorra a confirmação.\n\nConfirmação de Senha:");//Irá pedir para que o usuário repita a senha
			gets(players[count].confirmaSenha); //IUsuário deve repetir a senha de forma correta
			
			do //Função do, para que utilize-a ao menos uma vez
			{
				if (strcmp (players[count].senha, players[count].confirmaSenha)) //Expressão comdicional, irá checar se as senhas são diferentes
				{
					//Mensagens informativas
					printf("Algo deu errado, as senhas não são iguais, por favor, tente mais uma vez\n");
					printf("Tome cuidado com a sua senha, ela é muito importante!\n\n");
					printf("Confirmação de Senha:");
					gets(players[count].confirmaSenha); //Usuário deve repetir a senha de forma correta
				}
				else 
				{
					printf("\nMais uma etapa concluida com louvor!\n"); //Mensagem informativa
				}
			}while (strcmp (players[count].senha, players[count].confirmaSenha)); //Enquanto as senhas forem diferentes, ele repetirá tudo novamente, a partir do if
				
				//Mensagens Informativas
				printf("\nPressione qualquer tecla para continuar.");
				getch(); //Lê uma tecla
				system("cls"); //Limpa tela
		}
			//Mensagens de interação com o usuário
			printf("\t\t\tAgora iremos distribuir juntos os pontos de habilidade do seu personagem.\n"); 
			printf("\t\t\tIsso irá definir basicamente a sua função no jogo, escolha com cuidado... XD\n");
			printf("\t\t\tSerão esses pontos que lhe farão ter mais facilidades para ser de determinada classe.\n");
			printf("\t\t\tSão elas, Guerreiro, Guardião, Mago, Ladrão e o Ninguém.\n\n");
			
			printf("Leia atentamente as informações acima, caso as tenha entendido, clique qualquer tecla para continuar.");
			getch(); //Lê uma tecla
			system("cls"); //Limoa tela
			
			//Aqui será exibido um pequeno resumo sobre as classes do jogo, para ajuda-lo a distribuir seus pontos de uma forma adequada
			printf("Informações sobre as classes:\n\n");
			printf("\nGuerreiro:  Seria a classe em que o seu foco é a força, um personagem bruto pronto para destroçar seus inimigos sem medo algum. \n");
			printf("\nGuardião: Guardiões são conhecidos pela sua grande resistência, são extremamente úteis, sendo a linha de frente de seus aliados.\n");
			printf("\nMago: A arte da feintiçaria é uma das mais antigas em nossa história, os magos são seres de intelecto superior e grande controlador de magias, sendo utilizado tanto como dano bruto quanto para ser utilizado como defensor de seus aliados, é uma classe complexa e não recomendada se você é inexperiente em jogos estilo RPG.\n");
			printf("\nLadrão: São peritos em atividades silênciosas, costumam entrar e sair de lugares sem serem vistos e deixam um grande estrago, são peritos em armas de curto alcance, como adagas, e com armas a distância, como arco e flecha e a besta.\n");
			printf("\nNinguém: São pessoas cujo comuns, com balanceamento em todas as habilidades, não sendo forte em nenhuma delas, mas que mesmo assim ainda pode ser desenvolvida com bastante treinamento.\n");
			
			printf("Leia atentamente as informações acima, caso as tenha entendido, clique qualquer tecla para continuar");
			getch(); //Lê uma tecla
			system("cls"); //Limpa tela
			
			for(count = 0; count < qntdPlayer; count++) //Laço de repetição que irá repetir o número de jogadores em jogo
			{
				//Mensagens Informativas
				printf("Será iniciada a distribuição das habilidades do jogador: %s.\n\n", players[count].nickUser); //Irá exibir na tela o nome do usuário da vez
				printf("Personagem: %s\n\n", players[count].nickChar); //Irá exibir na tela o nome do personagem do usuário da vez
				
				//Citação das Regras de distribuiçao de pontos
				printf("Vale resaltar que você precisa seguir algumas regras na distribuição de pontos, Fique atento!!\n");
				printf("1- A habilidade não pode ser de valor 0 ou menor\n");
				printf("2- Cada habilidade deve possuir ao menos 1 ponto\n");
				printf("3- Não se pode inserir todos os pontos em apenas uma habilidade\n");
				printf("4- Não deixe que falte pontos em seu personagem, utilize todos!");
				
				do //Função do, para que utilize-a ao menos uma vez
				{
					perks = 15; //Atribui o valor de pontos a serem distribuidos como 15
					printf("\n\nPontos: %d\n", perks); //Exibirá na tela o valor de pontos disponiveis
					printf("Força: "); //Mensagem informativa
					scanf("%d", &players[count].forca); // Irá ler a quantidade de pontos insedira pelo usuário
					do //Função do, para que utilize-a ao menos uma vez
					{
						if (players[count].forca <=0 || players[count].forca > 12) //Expressão comdicional, irá checar se a quantidade informada não está dentro das regras
						{
							//Mensagens informativas 
							printf("Atenção cidadão, você está violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos: %d\n", perks); //Mostrará na tela novamente o valor que se tem disponivel
							printf("Força: ");
							scanf("%d", &players[count].forca);  //Irá ler a quantidade de pontos digitada
						}
					}while  (players[count].forca <=0 || players[count].forca > 12); //Repetirá a função até que a quantidade correta seja digitada
					system("cls"); //Limpa a tela
					
					calculoPerksForca(players[count].forca); //Irá mostrar na tela as informações da utilização dos pontos de força
					perks = perks - players[count].forca; //Cálculo da diferença para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Destreza: ");
					scanf("%d", &players[count].destreza); // Irá ler a quantidade de pontos inserira pelo usuário
					do //Função do, para que utilize-a ao menos uma vez
					{
						if (players[count].destreza <=0 || players[count].destreza > perks - 2) //Expressão comdicional, irá checar se a quantidade informada não está dentro das regras
						{
							//Mensagens informativas 
							printf("Atenção cidadão, você está violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mostrará na tela novamente o valor que se tem disponivel
							printf("Destreza: ");
							scanf("%d", &players[count].destreza); //Irá ler a quantidade de pontos digitada
						}
					}while (players[count].destreza <=0 || players[count].destreza > perks - 2); //Repetirá a função até que a quantidade correta seja digitada
				
					system("cls"); //Limpa tela
					
					calculoPerksForca(players[count].forca); //Irá mostrar na tela as informações da utilização dos pontos de força
					calculoPerksDestreza(players[count].destreza); //Irá mostrar na tela as informações da utilização dos pontos de destreza
					perks = perks - players[count].destreza; //Cálculo da diferença para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Poder Mágico: ");
					scanf("%d", &players[count].poderMagico); // Irá ler a quantidade de pontos inserira pelo usuário
					
					do //Função do, para que utilize-a ao menos uma vez
					{
						if(players[count].poderMagico <=0 || players[count].poderMagico > perks - 1) //Expressão comdicional, irá checar se a quantidade informada não está dentro das regras
						{
							//Mensagens informativas 
							printf("Atenção cidadão, você está violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mostrará na tela novamente o valor que se tem disponivel
							printf("Poder Mágico: ");
							scanf("%d", &players[count].poderMagico); //Irá ler a quantidade de pontos digitada
						}
					} while(players[count].poderMagico <=0 || players[count].poderMagico > perks - 1); //Repetirá a função até que a quantidade correta seja digitada
					
					system("cls");
					
					calculoPerksForca(players[count].forca); //Irá mostrar na tela as informações da utilização dos pontos de força
					calculoPerksDestreza(players[count].destreza); //Irá mostrar na tela as informações da utilização dos pontos de destreza
					calculoPerksPoderMagico(players[count].poderMagico); //Irá mostrar na tela as informações da utilização dos pontos de poder mágico
					perks = perks - players[count].poderMagico; //Cálculo da diferença para continuar com a quantidade correta  de pontos
					printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
					printf("Defesa: ");
					scanf("%d", &players[count].defesa); //Irá ler a quantidade de pontos digitada
					
					do
					{
						if(players[count].defesa <=0 || players[count].defesa > perks) //Expressão comdicional, irá checar se a quantidade informada não está dentro das regras
						{
							//Mensagens informativas 
							printf("Atenção cidadão, você está violando as regras!\n\n");
							printf("Informe mais uma vez!\n");
							printf("Pontos Restantes: %d\n", perks); //Mensagem que mostra quantos pontos ainda tem disponivel
							printf("Defesa: ");
							scanf("%d", &players[count].defesa); //Irá ler a quantidade de pontos digitada
						}
					}while (players[count].defesa <=0 || players[count].defesa > perks); //Repetirá a função até que a quantidade correta seja digitada
					
					perks = perks - players[count].defesa; //Cálculo da diferença para continuar com a quantidade correta  de pontos
					system("cls"); //Limpa tela
					
				}while(perks != 0); //Repetirá todo o laço caso o jogador não tenha utilizado todos os pontos disponiveis
				
				system("cls"); //limpa a tela
				calculoPerksForca(players[count].forca); //Irá mostrar na tela as informações da utilização dos pontos de força
				calculoPerksDestreza(players[count].destreza); //Irá mostrar na tela as informações da utilização dos pontos de destreza
				calculoPerksPoderMagico(players[count].poderMagico); //Irá mostrar na tela as informações da utilização dos pontos de poder mágico	 
				calculoPerksDefesa(players[count].defesa); //Irá mostrar na tela as informações da utilização dos pontos da defesa	 
			}		
			printf("Pressione qualquer tecla para finalizar.");
			getch(); //Lê uma tecla
			system("cls"); //Limpa a tela
			printf("Dados dos Jogadores:\n");
			
		for (count = 0; count < qntdPlayer; count++) //Comando para listar todos os jogadores que foram preenchidos.
		{
			printf("\nUsuário: %s\n",players[count].nickUser); //Mostra na tela o nome do usuário
			printf("Personagem: %s\n",players[count].nickChar); //Mostra na tela o nome do personagem do usuário
			printf("Senha: %s\n\n",players[count].senha); //Mostra na tela a senha do usuário 
			printf("Atributos:\n");
			printf("Força: %d\n",players[count].forca); //Mostra na tela a força
			printf("Destreza: %d\n",players[count].destreza); //Mostra na tela a destreza
			printf("Poder Mágico: %d\n",players[count].poderMagico); //Mostra na tela o poder magico
			printf("Defesa: %d\n",players[count].defesa); //Mostra na tela a defesa
		}	
		FILE *Pfile; //Declaração do ponteiro do arquivo
		Pfile = fopen("dados.txt", "w"); //Abre o arquivo txt para gravação
		if (Pfile == NULL) //Caso ocorra alguma complicação irá demonstrar a mensagem abaixo e encerrará o programa
		{
			//Mensagem informativa
			printf("Erro na abertura do arquivo.");
			exit(0); //Encerra
		}
		for (count = 0; count < qntdPlayer; count++) //Lsita as informações de todos os jogadores no arquivo criado
		{
			fprintf(Pfile, "\nNome: %s\n",players[count].nickUser);
			fprintf(Pfile, "Personagem: %s\n",players[count].nickChar);
			fprintf(Pfile, "Senha: %s\n",players[count].senha);
			fprintf(Pfile, "Força: %d\n",players[count].forca);
			fprintf(Pfile, "Destreza: %d\n",players[count].destreza);
			fprintf(Pfile, "Poder Mágico: %d\n",players[count].poderMagico);
			fprintf(Pfile, "Defesa: %d\n",players[count].defesa);
		}
		fclose(Pfile); //Fecha o arquivo 		
	}
	else
	{
		printf("\nErrou feio, errou rude\nAcho que você não devia estar aqui...\nInsira o número de participantes corretamente");
		return 0; //Encerra o programa
	}
}
