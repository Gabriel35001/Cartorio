#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocaçôes de texto por regiao
#include <string.h> //biblioteca responsabel por cuidar das strings
int registro() // funçao responsavel por cadastrar os usuarios no sistema
{
	//inicio da criaçao de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçao de variavel/string
	
	
	printf("Digite o  CPF a ser cadastrado: "); //coletando informaçoes do usuario
	scanf("%s", cpf); //%s refere-se a string 
	
	
	strcpy(arquivo, cpf); // esse cara é responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados, o 'w' significa escrever
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	 file = fopen(arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado: ");
	 scanf("%s",nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s",sobrenome);
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,sobrenome);
     fclose(file);
     
     file = fopen(arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,cargo);
	 fclose(file);
	 
	 system("pause");
	 
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo,não localizado!. \n ");
		system("pause");
		return 0;
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n\n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	 
	 fclose(file);
	 
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	 
	 if(file ==NULL)
	 {
	 	printf("\n O usuário não se encontra no sistema!.\n");
	 	system("pause");
	 }


}


int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=10;)
	{
	
	    system("cls");
  	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
  	
    	printf("### Cartório da EBAC ###\n\n");  //inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");  // o \n é resonsavel por dar o espaço das linhas
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
  	    printf("\t3 - Deletar nomes\n\n");
    	printf("Opção: "); //fim do menu
  	
    	scanf("%d", &opcao); //armazenando a escolha do usuario
  	
    	system("cls"); //responsavel por limpar a tela
  	
        switch(opcao) //inicio da seleçao do menu
		{
			case 1:
			registro(); //chamada de funçoes
  		    break;
  		    
  		    case 2:
  		    consulta();
  	    	break;
  	    	
  	    	case 3:
  	    	deletar();
    		break;
    		
    		default:
    			printf("Essa opção não está disponivel!\n");
      		system("pause");
      		break;
    			
			 } 	
  	
 }

}
