#include<stdio.h>
#include<string.h>
int main()
{
	char plaintext[100];
	int i,j,frequency=1;
	printf("enter the plian text:\n");
	scanf("%s",&plaintext);
	int len=strlen(plaintext);
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(plaintext[i]==plaintext[j]){
				frequency++;
			}
		}
		printf("frequency of %c = %d",plaintext[i],frequency);
		printf("\n");
	}
	return 0;
}
