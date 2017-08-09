/**
 * coder: kodo no kami
 * brute force md5 em C
 * face: https://www.facebook.com/hacker.fts315
 * discord: kodo#0010
 * compilador: gcc kodo.c -o kodo.out -l crypto
 * sintaxe: ./programa 812187228720a0bee75d3895c6a11acc wordlist.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(int argc, char **argv){
	FILE *arq;
	unsigned char linha[1000], *dados, hash2[10], hash3[50];
	MD5_CTX *hash;
	int cont, cont2;
	
	printf(
		"==========================\n"
		"     kodo bruteMd5C\n"
		"==========================\n\n");
	
	if(argc != 3){
		printf("coder: kodo no kami\n"
		"face: fb/hacker.fts315\n"
		"discord: kodo#0010\n\n"
		"sintaxe:\n"
		"    ./programa 812187228720a0bee75d3895c6a11acc wordlist.txt\n\n");
		return 0;
	}
	
	
	if((arq = fopen(argv[2],"r")) == 0){
		printf("problema na wordlist\n\n");
		return 0;
	}
	if(strlen(argv[1]) != 32){
		printf("hash invalida\n\n");
		return 0;
	}
	
	while(fgets(linha,1000,arq)){
		hash =  malloc(sizeof(MD5_CTX));
		dados = malloc(sizeof(unsigned char) * 600);
		
		MD5_Init(hash);
		MD5_Update(hash,linha,strlen(linha)-1);
		MD5_Final(dados,hash);
		
		strcpy(hash3,"");
		for(cont = 0; cont < 16; cont++){
			if(dados[cont] < 0x10){
				sprintf(hash2,"0%x",dados[cont]);
			}
			else{
				sprintf(hash2,"%x",dados[cont]);
			}
			strcat(hash3,hash2);
		}

		if(!strcmp(hash3,argv[1])){
			printf("\n[+] cracked %s == %s \n",hash3,linha);
			break;
		}
		else{
			printf("[-] %s != %s",hash3,linha);
		}
		
		free(dados);
		free(hash);
	}
	
	return 0;
}
