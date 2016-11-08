#include <stdio.h>
int numbers[100]={0};
int count=0;
void first(int array[],char operate[], int times)
{
	//printf("chengchu ");
	if(times==0)	return;
	int i,j;
	for(i=0;i<count+1;i++)
	{
		if(operate[i]=='*')
		{
	//		printf("cheng ");
			array[i] *= array[i+1];break;
		}
		else if(operate[i]=='/')
		{
	//		printf("chu ");
			array[i] /= array[i+1];break;
		}
	}
	for(j=i+1;j<count+1;j++)
		array[j] = array[j+1];
	for(j=i;j<count;j++)
		operate[j] = operate[j+1];
//	printf("%d",numbers[0]);
	first(array,operate,times-1);
}

void second(int array[],char operate[], int times)
{
	//printf("jiajian ");
	if(times==0)	return;
	int i,j;
	for(i=0;i<count+1;i++)
	{
		if(operate[i]=='+')
		{
	//		printf("jia ");
			array[i] += array[i+1];break;
		}
		else if(operate[i]=='-')
		{
	//		printf("jian ");
			array[i] -= array[i+1];break;
		}
	}
	for(j=i+1;j<count+1;j++)
		array[j] = array[j+1];
	for(j=i;j<count;j++)
		operate[j] = operate[j+1];
	//printf("%d",numbers[0]);
	second(array,operate,times-1);
}

int main()
{

	char operators[100]={'\0'};
	char temp;
	int i=0;
	int j=0;
	while((temp=getchar())!='=')
	{
		if(temp==' ') continue;
		if(temp=='+'||temp=='-'||temp=='*'||temp=='/')
		{
			operators[j++] = temp;
			i++;
		}
		else
		{
			numbers[i] = numbers[i]*10+temp-'0';
		}
	}
	count = j;
	int times1 = 0;
	for(i=0;operators[i]!='0';i++)
		if (operators[i]=='*'||operators[i]=='/')	times1++;
	int times2 = j - times1;
	first(numbers,operators,times1);
	second(numbers,operators,times2);
	printf("%d",numbers[0]);
	return 0;
}
