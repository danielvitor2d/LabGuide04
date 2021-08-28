#include <stdio.h>
#include <dirent.h>
#include <string.h>

/*
	Author: Daniel Vitor
	Created At: 24/08
*/

void print_files_on_this_path(char* current_path) {
	DIR *directory_stream;                        // Stream de diretório
	directory_stream = opendir(current_path);     // Abrindo diretório atual

	if (directory_stream == NULL) return;         // Em caso de erro, apenas para

	struct dirent* dir;                           // Ponteiro para estrutura dirent
	while (1) {
		dir = readdir(directory_stream);          // Lê a próxima entrada de diretório
		if (dir == NULL) break;                   // Para em caso de erro ou não ter mais entradas
			
		
		if (dir->d_type == DT_DIR && 
			strcmp(dir->d_name, ".") != 0 && 
			strcmp(dir->d_name, "..") != 0) {     // Primeiro caso: diretório (excluindo o atual "." e o pai "..")

			// Calcula o tamanho do novo caminho
			int new_size = strlen(current_path)+1+strlen(dir->d_name);
			// Cria buffer para salvar o novo caminho
			char new_directory[new_size];

			// Salva o novo caminho
			sprintf(new_directory, "%s/%s", current_path, dir->d_name);


			// Chamada recursiva para o diretório filho
			print_files_on_this_path(new_directory);

		} else if (dir->d_type == DT_REG) {       // Segundo caso: arquivo regular
			printf("%s\n", dir->d_name);          // Apenas imprime o nome do arquivo regular
		}

	}
	closedir(directory_stream);
}

int main() {
	/*
		Primeira chamada recursiva para o diretório atual
	*/
	print_files_on_this_path(".");
	return 0;
}
/*
References:
	man opendir
	man readdir
	man closedir
*/