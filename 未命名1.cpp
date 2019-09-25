#include<stdio.h>
#include<stdlib.h>

#include <windows.h>
#include <direct.h>
#include <io.h>
#include <string.h>

int a=0;
int b=0;
int c=0;
int CharCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch != ' '&&ch != '\n'&&ch != '\t'&&ch != ','&&ch != '.'&&ch != '!'&&ch != ';'&&ch != '=');
		a++;
		ch = fgetc(fp);
	}
	a--;
	fclose(fp);
}

int WordCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch==' '||ch=='\n'||ch==','||ch=='.'||ch=='!'||ch=='='||ch==';')
		
			b++;
			ch = fgetc(fp);
	}
	fclose(fp);
}

int LineCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n' || ch == '\t')
			c++;
		ch = fgetc(fp);
	}
	c++;
	fclose(fp);
}
int main(int argc, char *argv[])
{
    int cCount,wCount,lCount;
    int i;
    for(i=1;i<argc-1;i++)
    {
        if(strcmp(argv[i],"-c")==0)
        {
            cCount=CharCount(argv[argc-1]);
            printf("The character has %d\n",cCount);
        }
        else if(strcmp(argv[i],"-w")==0)
        {
            wCount=WordCount(argv[argc-1]);
            printf("The word has %d\n",wCount);
        }
        else if(strcmp(argv[i],"-l")==0)
        {
            lCount=LineCount(argv[argc-1]);
            printf("The line has %d\n",lCount);
        }
        else
        {
            printf("THE COMMAND IS WRONG\n");
            break;
        }
    }
    return 0;
}
