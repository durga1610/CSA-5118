#include <stdio.h>
#include <openssl/md5.h>
int main() {
    unsigned char digest[MD5_DIGEST_LENGTH];
    char str[] = "hello";
    MD5((unsigned char*)str, strlen(str), digest);
    printf("MD5: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");
    return 0;
}
