//Программа шифрования/дешифрования символов латиницы алгоритмом Цезаря

#include <string.h>
#include "../iof.h"

using namespace std;

string encryption (int k, string source)
{
	string result;
	for (unsigned int i = 0; i < source.length(); i++)
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

string decryption (int k, string source)
{
	string result;
	for (unsigned int i = 0; i < source.length(); i++)
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
	if (!strcmp(argv[1], "enc"))
		output(encryption(atoi(argv[2]), input(argv[3])), argv[4]);
	else
			if(!strcmp(argv[1], "dec"))
				output(decryption(atoi(argv[2]), input(argv[3])), argv[4]);
			else
			{
				printf("Invalid arguments.\nUse \"help\" to see instructions.\n");
				return 1;
			}
	printf("Program has been successfully completed.\n");
	return 0;
}
