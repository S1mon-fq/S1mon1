#include<stdio.h>
#include<stdlib.h>

#include <windows.h>
#include <direct.h>
#include <io.h>
#include <string.h>

 int cCount,wCount,lCount,aCount=0;
 int e=0;
 int c=0;
 int n=0;
int CharCount(char filename[])  //统计字符数 
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
		if (ch != ' '&&ch != '\n'&&ch != '\t'&&ch != ','&&ch != '.'&&ch != '!'&&ch != ';'&&ch != '=') 
		cCount++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return cCount;
}

int WordCount(char filename[])  //统计字词数 
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
		
			wCount++;
			ch = fgetc(fp);
	}
	fclose(fp);
	return wCount;
}

int LineCount(char filename[])  //统计行数 
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
			lCount++;
		ch = fgetc(fp);
	}
	lCount++;
	fclose(fp);
	return lCount;
}
int AllCount(char path[])  //统计代码行、空行、注释行 
{
    FILE *fp;
    char ch;
    char *path_1 = path;
    int k = strlen(path);
    *(path_1 + k) = '\0';
    int c = 0, e = 0, n = 0;
    if ((fp = fopen(path_1, "r")) == NULL)
    {
        printf("file read failure.");
        exit(0);
    }
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if (ch == '{' || ch == '}')
        {
            e++;
            ch = fgetc(fp);
        }
        else if (ch == '\n')
        {
            ch = fgetc(fp);
            while (ch == '\n')
            {
                e++;
                ch = fgetc(fp);
            }
        }
        else if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
            while (ch != '\n')
            {
                ch = fgetc(fp);
            }
            n++;
            ch = fgetc(fp);
        }
        else
        {
            c++;
            while (ch != '{'&&ch != '}'&&ch != '\n'&&ch != '/'&&ch != EOF)
            {
                ch = fgetc(fp);
            }
        }

    }
    printf("code line count is ：%d.\n", c);
    printf("empt line count is ：%d.\n", e);
    printf("note line count is ：%d.\n", n);
    fclose(fp);
    
}
int main(int argc, char *argv[])  //主函数 
{
   
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
        else if(strcmp(argv[i],"-a")==0)
        {
        	aCount=AllCount(argv[argc-1]);
		}
        else
        {
            printf("THE COMMAND IS WRONG\n");
            break;
        }
    }
    return 0;
}
