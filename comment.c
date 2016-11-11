#include <stdio.h>

int main()
{
	FILE* fp;
	fp = fopen("filein.c","r");
	char temp;
	int count=1;
	int commentcount = 0;
	while((temp=fgetc(fp))!=EOF)
	{
		count++;
	}
	fclose(fp);
	fp = fopen("filein.c","r");
	while((temp=fgetc(fp))!=EOF)
	{	
		if((temp=='/')&&((temp=fgetc(fp)))=='*')
		{	
			A:
			if((temp=fgetc(fp))=='*')
			{
				if((temp=fgetc(fp))=='/')
				{
					temp=fgetc(fp);
					continue;
				}
				else 
				{
					commentcount++;
					goto A;
				}
			}
			else 
			{
				commentcount++;
				goto A;
			}
		}
	}
	int percentage = 100*commentcount/count;
	printf("%d%%",percentage);
	return 0;
}
