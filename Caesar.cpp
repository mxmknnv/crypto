//Программа шифрования/дешифрования символов латиницы алгоритмом Цезаря

#include <string.h>
#include "iof.h"

using namespace std;

string encryption (int key, string source)
{
	string result;
	char ch;
	for (unsigned long int i = 0; i < source.length(); i++)
	{
		ch=source[i];		
		if ((ch >= 'a') && (ch <= 'z'))
		{
			ch = ch + key;
			if(ch > 'z')
				ch = ch - 26;
			if(ch < 'a')
				ch = ch + 26;
		}	
		else				
			if ((ch >= 'A') && (ch <= 'Z'))
			{
				ch = ch + key;
				if(ch > 'Z')
					ch = ch - 26;
				if(ch < 'A')
					ch = ch + 26;
			}
		result += ch;
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
	if (!strcmp(argv[1], "enc"))
		output(encryption((atoi(argv[2]) % 26), input(argv[3])), argv[4]);
	else
		if(!strcmp(argv[1], "dec"))
			output(encryption(((atoi(argv[2])*(-1)) % 26), input(argv[3])), argv[4]); //Функция encryption вызывается с ключом * (-1)
		else
		{
			printf("Invalid arguments.\nUse \"help\" to see instructions.\n");
			return 1;
		}
	printf("Program has been successfully completed.\n");
	return 0;
}
