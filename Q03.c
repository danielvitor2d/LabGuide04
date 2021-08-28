#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

/*
	Author: Daniel Vitor
	Created At: 24/08
*/


/*
	Como não foi definido em enunciado, vou definir como 
	os arquivos passados por argumento na linha de comando
	Formato escolhido: ELF
*/

int main(int argc, char *argv[]) {
	assert(argc == 2);

	// Criando struct para armazenar os metadados
	struct stat st;

	// Lendo os metadados
	stat(argv[1], &st);

	// Imprimindo metadados
	printf("st_dev: %lu\n", st.st_dev);
	printf("st_ino: %lu\n", st.st_ino);
	printf("st_mode: %u\n", st.st_mode);
	printf("st_nlink: %lu\n", st.st_nlink);
	printf("st_uid: %u\n", st.st_uid);
	printf("st_gid: %u\n", st.st_gid);
	printf("st_rdev: %lu\n", st.st_rdev);
	printf("st_size: %lu\n", st.st_size);
	printf("st_blksize: %lu\n", st.st_blksize);
	printf("st_blocks: %lu\n", st.st_blocks);

	return 0;
}