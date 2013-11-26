//Функции чтения/записи из файлов

#include "iof.h"

using namespace std;

string input (char *filename)
{
	ifstream file;
	string text;
	char temp;
	file.open (filename);
	if(file)
		while(file)
		{
			file.get(temp);
			text+=temp;
		}
	else
	{
		printf("Can't open file \"%s\".\n", filename);
		exit (1);
	}	
	file.close();
	if(text.length()==0)
	{
		printf("File \"%s\" is empty.\n", filename);
		exit (1);
	}
	return text;
}

void output(string text, char *filename)
{
	ofstream file;
	file.open (filename);
	file << text.c_str();
	file.close();
}
