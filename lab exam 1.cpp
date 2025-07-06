#include<stdio.h>
#include<string.h>
int main()
{
	char plain_text[100];
	char cipher_text[100];
	int key,i;
	printf("enter the plain text:\n");
	scanf("%s",&plain_text);
	int len=strlen(plain_text);
	printf("enter the key:\n");
	scanf("%d",&key);
	for(i=0;i<=len;i++){
		char c=plain_text[i];
		if(c>='a' && c<='z'){
		cipher_text[i]=((c-'a'+key)%26)+'a';
	}
}
	printf("cipher text=%s",cipher_text);
	return 0;
}
