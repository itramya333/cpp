
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void tail( FILE *fp, int nlines)
{
	int count =0;
	unsigned long long pos =0;
	char str[200];
	if (fseek( fp, 0, SEEK_END))
	perror("fseek failed");
	else
	pos = ftell(fp);
	
	while(pos)
	{
		if (!(fseek(fp, pos--, SEEK_SET)))
		{
			if(fgetc(fp) == '\n'){
			
				if(count++ == nlines)
				break;
			}
		}
		else
		perror("fseek fail");
	}
	while (fgets(str, sizeof(str), fp))
	cout << str;
}
int main()
{
	FILE *filep = fopen("c:/Cpp/input.txt", "rb+");
	if(filep==NULL)
	{
		cout << "File not exists";
		exit(EXIT_FAILURE);
	}
	
		
	tail (filep, 10);
	fclose(filep);
}
