#include <stdio.h>
#include <openssl/sha.h>
int main() {
    unsigned char hash[SHA_DIGEST_LENGTH];
    char str[] = "hello";
    SHA1((unsigned char*)str, strlen(str), hash);
    printf("SHA1: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}
