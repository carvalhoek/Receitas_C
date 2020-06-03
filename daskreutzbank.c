#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "daskreutzbank.h"

#define ext ".kr"
char* stringZuweisung(int tam);

FILE* neueDatenbank(char *name){
	FILE *arq;
	char nam[30];
	strcpy(nam,name);
	strcat(nam,ext);
	arq = fopen(nam,"wb+");
	return arq;
}

FILE* datebankOffnen(char*name){
	int a;
	FILE *arq;	
	char nam[30];
	strcpy(nam,name);
	strcat(nam,ext);
	arq = fopen(nam,"rb+");
	rewind(arq);
	return arq;
}
void datenbankSchreiben(FILE*arq,int type, void*data){
	int len;
	char *str;
	//char m[5]="olha";
	switch (type)
	{
	case 7:
		fwrite(&type,sizeof(int),1,arq);
		fwrite(data,sizeof(int),1,arq);
		break;
	case 13:
		fwrite(&type,sizeof(int),1,arq);
		fwrite(data,sizeof(float),1,arq);
		break;
	case 3:
		fwrite(&type,sizeof(int),1,arq);
		fwrite(data,sizeof(char),1,arq);
		break;
	case 16:
		str = malloc(sizeof(data)/**sizeof(char)*/);
		str = (char*)data;
		len = strlen(str);
		fwrite(&type,sizeof(int),1,arq);
		fwrite(&len,sizeof(int),1,arq);
		fwrite(str,sizeof(char),len,arq);
		break;
	default:
		printf("erro na escrita, codigo de tipo errado");
		return;
	}
}
void* datebankLesen(FILE *arq){
	int a;
	//rewind(arq);
	int id;
	int len;
	char* dataS;
	int dataI;
	float dataF;
	char dataC;
	fread(&id,sizeof(int),1,arq);
	switch (id){
	case 7:
		fread(&dataI,sizeof(int),1,arq);
		return &dataI;
	case 13:
		fread(&dataF,sizeof(float),1,arq);
		return &dataF;
	case 3:
		fread(&dataC,sizeof(char),1,arq);
		return &dataC;
	case 16:
		fread(&len,sizeof(int),1,arq);
		dataS = stringZuweisung(len);
		fread(dataS,sizeof(char),len,arq);
		return dataS;
	default:
		printf("erro na leitura, codigo de tipo errado");
		return;
		break;
	}
}
char* stringZuweisung(int tam){
	char* obj = malloc(sizeof(char)*tam);
	return obj;
}

