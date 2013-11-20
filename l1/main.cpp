//Программа шифрования/дешифрования символов латиницы алгоритмом Цезаря

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int input (char *&text, char *filename)
{
	FILE *file=NULL;
	int n=0;
	if (!(file = fopen(filename, "r")))
	{
		printf("Can't open file \"%s\".", filename);
		exit (1);
	}	
	fseek(file,0,2);
	if(!(n=ftell(file))) 
	{
		printf("Error. File \"%s\" is empty.", filename);
		exit (1);
	}
	fseek(file,0,0);
	text=(char*)calloc(n-1, sizeof(char));
	fscanf(file, "%s", text);
	fclose(file);
	return n;
}

void output(char *text, char *filename)
{
	FILE *file = fopen(filename, "w");
	fprintf(file, "%s", text);
	fclose(file);
}

char *encryption (int k, char *source, int n)
{
	char *result=(char*)calloc(n-1, sizeof(char));
	for (int i = 0; i < n; i++)
		if ((source[i] < 'A')||(source[i] > 'z'))
			result[i] = source[i];
		else
		{
			if ((source[i] >= 'a') && (source[i] <= 'z'))
			{
				if (source[i] + k > 'z')
					result[i] = source[i] + k - 26;
				else
					result[i] = source[i] + k;
			}
			if ((source[i] >= 'A') && (source[i] <= 'Z'))
			{
				if (source[i] + k > 'Z')
					result[i] = source[i] + k - 26;
				else
					result[i] = source[i] + k;
			}
		}
	return result;
}

char *decryption (int k, char *source, int n)
{
	char *result=(char*)calloc(n-1, sizeof(char));
	for (int i = 0; i < n; i++)
		if ((source[i] < 'A')||(source[i] > 'z'))
			result[i] = source[i];
		else
		{
			if ((source[i] >= 'a') && (source[i] <= 'z'))
			{
				if (source[i] - k < 'a')
					result[i] = source[i] - k + 26;
				else
					result[i] = source[i] - k;
			}
			if ((source[i] >= 'A') && (source[i] <= 'Z'))
			{
				if (source[i] - k < 'A')
					result[i] = source[i] - k + 26;
				else
					result[i] = source[i] - k;
			}
		}
	return result;
}

int main(int argc, char *argv[])
{	
	if((argc==2) and (!strcmp(argv[1],"help")))
	{
		printf("The program reads a source text from the file, encrypts (or decrypts) by Caesar cipher and writes result in the file.");
		printf("\nHow to use:");
		printf("\nfirst [a] [b] [c] [d]");
		printf("\n[a]:\n    enc - for encryption\n    dec - for decryption");
		printf("\n[b]:\n    key - natural number for encryption or decryption");
		printf("\n[c]:\n    name of source file");
		printf("\n[d]:\n    file name for record of result\n");
		return 0;	
	}
	if (argc!=5)
	{
		printf("Invalid arguments.\nUse \"help\" to see instructions.\n");
		return 1;
	} 
	if(atoi(argv[2])<0)
	{
		printf("Negative key? No!\n");
		return 1;
	}
	char *text=NULL;
	if (!strcmp(argv[1], "enc"))
		output(encryption(atoi(argv[2]), text, input(text, argv[3])), argv[4]);
	else
			if(!strcmp(argv[1], "dec"))
				output(decryption(atoi(argv[2]), text, input(text, argv[3])), argv[4]);
			else
			{
				printf("Invalid arguments.\nUse \"help\" to see instructions.\n");
				return 1;
			}
	printf("Program has been successfully completed.\n");
	return 0;
}