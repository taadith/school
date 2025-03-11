#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    EVP_MD_CTX *mdctx;
    
    const EVP_MD *md;
    
    char mess1[] = "Test Message";
    
    unsigned char md_value[EVP_MAX_MD_SIZE];
    
    unsigned int md_len, i;

    md = EVP_get_digestbyname("md5");

    mdctx = EVP_MD_CTX_new();

    if (!EVP_DigestInit_ex2(mdctx,md,NULL)) {
        printf("Message digest initialization failed.\n");
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestUpdate(mdctx,mess1,strlen(mess1))) {
        printf("Message 1 digest update failed.\n");
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestFinal_ex(mdctx, md_value, &md_len)) {
        printf("Message digest finalization failed.\n");
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    EVP_MD_CTX_free(mdctx);

    printf("First 6 characters of MD5(\"%s\") are \"", mess1);
    for (i = 0; i < 3 /* used to be md_len */; i++)
        printf("%02x", md_value[i]);
    printf("\"\n");

    //found to be "d1d418"

    EVP_MD_CTX *mdctx1;
    
    unsigned int mess = 0;
    char hex_string[3];
    while (1) {
        char buffer[11];
        sprintf(buffer, "%u", mess);

        unsigned char md_value1[EVP_MAX_MD_SIZE];

        mdctx1 = EVP_MD_CTX_new();

        if (!EVP_DigestInit_ex2(mdctx1,md,NULL)) {
            printf("Message digest initialization failed.\n");
            EVP_MD_CTX_free(mdctx);
            exit(1);
        }
        if (!EVP_DigestUpdate(mdctx1,buffer,strlen(buffer))) {
            printf("Message 1 digest update failed.\n");
            EVP_MD_CTX_free(mdctx);
            exit(1);
        }
        if (!EVP_DigestFinal_ex(mdctx1, md_value1, &md_len)) {
            printf("Message digest finalization failed.\n");
            EVP_MD_CTX_free(mdctx);
            exit(1);
        }
        EVP_MD_CTX_free(mdctx1);
        
        if (md_value1[0] == 0xd1 && md_value1[1] == 0xd4 && md_value1[2] == 0x18) {
            printf("First 6 characters of MD5(\"%s\") are \"", buffer);
            for (i = 0; i < 3 /* used to be md_len */; i++)
                printf("%02x", md_value1[i]);
            printf("\"\n");
            break;
        }
        
        ++mess;
    }
    printf("It took %u trial(s)\n",mess + 1);
    exit(0);
}