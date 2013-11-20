#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;
 
string key_conv (string key)
{
	string key_out;
	for(int i = 0; i < key.size(); ++i)
    {
		if(key[i] >= 'A' && key[i] <= 'Z')
			key_out += key[i];
		else 
			if(key[i] >= 'a' && key[i] <= 'z')
				key_out += key[i] + 'A' - 'a';
    }
	return key_out;
}
 
string encryption(string key, string text)
{
	string out;
	for(int i = 0, j = 0; i < text.length(); ++i)
	{
		char c = text[i];
		if(c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else 
			if(c < 'A' || c > 'Z')
				continue;
		out += (c + key[j] - 2*'A') % 26 + 'A'; 
		j = (j + 1) % key.length();
    }
	return out;
}
 
string decryption(string key, string text)
{
	string out;
	for(int i = 0, j = 0; i < text.length(); ++i)
	{
		char c = text[i];
		if(c >= 'a' && c <= 'z')
		c += 'A' - 'a';
		else 
			if(c < 'A' || c > 'Z')
				continue; 
		out += (c - key[j] + 26) % 26 + 'A'; 
		j = (j + 1) % key.length();
    }
    return out;
}

string input (char *filename)
{
	ifstream file;
	string text;
	file.open (filename);
	if(file)
		getline(file, text);
	else
	{
		printf("Can't open file \"%s\".\n", filename);
		exit (1);
	}	
	file.close();
	return text;
}

void output(string text, char *filename)
{
	ofstream file;
	file.open (filename);
	file << text;
	file.close();
}
 
int main (int argc, char *argv[])
{
	if((argc==2) and (!strcmp(argv[1],"help")))
	{
		printf("\nThe program reads a source text from the file, encrypts (or decrypts) by Vigenere cipher and writes result in the file.");
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