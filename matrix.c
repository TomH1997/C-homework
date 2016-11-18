#include <stdio.h>

int main()
{
	int rank;
	scanf("%d",&rank);
	int matrix[rank][rank];
	char temp;
	int num;
	int i,j=0;
	for(i=0;i<rank;i++)
			for(j=0;j<rank;j++)
				scanf("%d ",&matrix[i][j]);
	while((temp=getchar())!='#')
	{
		switch(temp)
		{
			case '+':
			for(i=0;i<rank;i++)	
			{
				for(j=0;j<rank;j++)
					{
						scanf("%d",&num);
						matrix[i][j] += num;
					}
			}break;
			case '-':
			for(i=0;i<rank;i++)
			{
				for(j=0;j<rank;j++)
					{
						scanf("%d",&num);
						matrix[i][j] -= num;
					}
			}break;
		}
	}
	int tempnum;
	int space[rank][rank];
	for(i=0;i<rank;i++)
	{
		for(j=0;j<rank;j++)
		{
			space[i][j]=5;
			tempnum=matrix[i][j];
			while(tempnum)
			{
				tempnum /=10;	
				space[i][j]--;
			}
			if(matrix[i][j]<0) space[i][j]--;
		}
	}

	for(i=0;i<rank;i++)
	{
		for(j=0;j<rank;j++)
		{
			while(space[i][j]-->0){printf(" ");}
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
