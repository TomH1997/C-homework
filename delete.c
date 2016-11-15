#include<stdio.h>  
#include<string.h>  
  
  
int main()  
{  
    int t = 0 ;  
    int i = 0 ;  
    int j = 0 ;  
    int n = 0 ;  
    int length = 0;  
    int num = 0;  
    char istr[240];  
    int k = 0 ;  
  
    gets(istr);

    scanf("%d",&num) ;  
    getchar() ;  
	length = strlen(istr) ;  
  	for(i = 0 ; i < num ; i++)  
    {  
            for(j = 0 ; j < length ; j++)  
            {  
                if(istr[j] > istr[j+1])  
                {  
                    for(k = j ; k < length ; k++)  
                    {  
                        istr[k] = istr[k+1] ;  
                    }  
                    break ;  
                }    
            }         
  
            if(j == length)  
            {  
                istr[j-1] = '/0' ;  
            }  
          
           length-- ;  
    }
    puts(istr) ;  
    return 0 ; 
}  
