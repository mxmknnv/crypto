//Программа шифрования/дешифрования символов латиницы алгоритмом Виженера

#include <string.h>
#include "iof.h"

using namespace std;
 
string key_conv (string key)
{
	string key_out;
	for(unsigned long int i = 0; i < key.length(); i++)
    	{
		if(key[i] >= 'A' && key[i] <= 'Z')
			key_out += key[i];
		else 
			if(key[i] >= 'a' && key[i] <= 'z')
				key_out += key[i] + 'A' - 'a';
    	}
	if(key_out.length()==0)
	{
		printf("Key file doesn't contain letters of Latin alphabet.\n");
		exit (1);
	}
	return key_out;
}
 
string encryption(string key, string text)
{
	string out;
	for(unsigned long int i = 0, j = 0; i < text.length(); i++)
	{
		if(text[i] >= 'a' && text[i] <= 'z')
			text[i] += 'A' - 'a';
		
		if(text[i] >= 'A' && text[i] <= 'Z')
		{
			out += (text[i] + key[j] - 2*'A') % 26 + 'A'; 
			j = (j + 1) % key.length();
		}
		else
			out += text[i];
    	}
	return out;
}
 
string decryption(string key, string text)
{
	string out;
	for(unsigned long int i = 0, j = 0; i < text.length(); i++)
	{
		if(text[i] >= 'a' && text[i] <= 'z')
			text[i] += 'A' - 'a';
		
		if(text[i] >= 'A' && text[i] <= 'Z')
		{
			out += (text[i] - key[j] + 26) % 26 + 'A'; 
			j = (j + 1) % key.length();
		}
		else
			out += text[i];
    	}
    return out;
}

 
int main (int argc, char *argv[])
{
	if((argc==2) and (!strcmp(argv[1],"help")))
	{
		printf("The program reads a source text from the file, encrypts (or decrypts) by Vigenere cipher and writes result in the file.");
		printf("\nHow to use:");
		printf("\nsecond [a] [b] [c] [d]");
		printf("\n[a]:\n    enc - for encryption\n    dec - for decryption");
		printf("\n[b]:\n    name of key file");
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
		output(encryption(key_conv(input(argv[2])), input(argv[3])), argv[4]);
	else
			if(!strcmp(argv[1], "dec"))
				output(decryption(key_conv(input(argv[2])), input(argv[3])), argv[4]);
			else
			{
				printf("Invalid arguments.\nUse \"help\" to see instructions.\n");
				return 1;
			}
	printf("Program has been successfully completed.\n");
	return 0;
}
