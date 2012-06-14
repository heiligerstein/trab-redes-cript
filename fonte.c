#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

FILE *infile;
FILE *outfile;

// criptografa os dados no arquivo
int encript(int key)
{
	char c;
	int i=0;
	while((c = fgetc(infile)) != EOF) {
		// logica da criptografia
		printf("%c", c+i+key); // anda na posicao na ASCII
		fprintf(outfile, "%c", c+i+key);
		i++;
	}
   	fclose(infile); 
}

// descriptografa os dados no arquivo
void decript(int key) 
{
	char c;
	int i=0;
	while((c = fgetc(infile)) != EOF) {
		// logica da criptografia
		printf("%c", c-i-key); // anda na posicao na ASCII
		fprintf(outfile, "%c", c-i-key);
		i++;
	}
   	fclose(infile); 
}

void UsageExit(char *exec) 
{ 
	printf("Usage: %s [-e|-d] input_file output_file password\n", exec); 
	exit(10); 
} 

int main(int argc, char ** argv) 
{ 
	// verifica se os argumentos estao corretos
	if (argc < 5 && strcmp(argv[1], "--help") != 0) UsageExit(argv[0]); 

	infile = fopen(argv[2], "r"); 
	outfile = fopen(argv[3], "w"); 

	if(strcmp(argv[1], "--help") == 0) {
		printf("Usage: %s [-c|-d] input_file output_file password\n", argv[0]); 
		printf("\n-e\t\tCriptografa os dados.");
		printf("\n-d\t\tDecriptografa os dados.");
		printf("\ninput_file\tArquivo de entrada. Quando usado com -e é um arquivo em \"texto claro\", com o -d é um arquivo \"criptografado.\"");
		printf("\noutput_file\tArquivo de saída onde os dados serão escritos, seja ou não os dados criptografados.");
		printf("\n--help\t\tExibe esta tela de ajuda.\n");
	}

	// seleciona a operacao a se realizar
	if(strcmp(argv[1], "-e") == 0) {
		encript(atoi(argv[4])); // encript
	} else {
		if(strcmp(argv[1], "-d") == 0) {
			decript(atoi(argv[4])); // decript
		} else {
			if(strcmp(argv[1], "--help") != 0) {
				UsageExit(argv[0]); // sai
			}
		}
	}

}
