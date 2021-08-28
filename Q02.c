#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
	Author: Daniel Vitor
	Created At: 24/08
*/


/*
	Como não foi definido em enunciado, vou definir como 
	os arquivos passados por argumento na linha de comando
*/

int main(int argc, char *argv[]) {
	assert(argc == 3);

	// Cria ponteiro para stream de arquivo
	FILE *file_01, *file_02, *file_03;
	file_01 = fopen(argv[1], "r");       // Abre primeiro arquivo (leitura)
	file_02 = fopen(argv[2], "r");       // Abre segundo arquivo (leitura)
	file_03 = fopen("diff.txt", "w");    // Abre/Cria terceiro arquivo (escrita)

	while (1) {
		char linha1[100], linha2[100];       // Buffer de leitura dos arquivos
		memset(linha1, 0, sizeof(linha1));   // Limpando buffer
		memset(linha2, 0, sizeof(linha2));
		fgets(linha1, 100, file_01);         // Lendo próxima linha
 		fgets(linha2, 100, file_02);
		while (strlen(linha1) == 1) fgets(linha1, 100, file_01); // Enquanto estiver lendo linha com quebra de linha
		while (strlen(linha2) == 1) fgets(linha2, 100, file_02);
		if (strlen(linha1) == 0 && strlen(linha2) == 0) {        // Termina se os dois arquivos acabarem
			break;
		}
		if (strcmp(linha1, linha2) == 0) { // Caso das linhas iguais
			fprintf(file_03, "%s", linha1);
		} else {                           // Linhas diferentes
			linha1[strlen(linha1)-1] = 0;  // Retira a quebra de linha do final
			linha2[strlen(linha2)-1] = 0;  // Retira a quebra de linha do final
			fprintf(file_03, "[%s]\n", linha1); // Escreve no arquivo de saída
			fprintf(file_03, "[%s]\n", linha2); // Escreve no arquivo de saída
		}
	}

	// Fecha os arquivos abertos
	fclose(file_01);
	fclose(file_02);
	fclose(file_03);

	return 0;
}
/*
References:
	man fopen
	man fgets
	man fprintf
	man fclose
*/
