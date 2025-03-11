#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    unsigned char hashes[1000000+1][3];

    const EVP_MD *md;
    
    unsigned int i,j;
    unsigned int md_len1, md_len2;

    md = EVP_get_digestbyname("md5");

    EVP_MD_CTX *mdctx1;
    EVP_MD_CTX *mdctx2;
    
    unsigned long counter = 0;
    for(i = 0; i < 1000000; i++) {
        char mess1[11];
        sprintf(mess1, "%u", i);

        unsigned char md_value1[EVP_MAX_MD_SIZE];

        mdctx1 = EVP_MD_CTX_new();

        if (!EVP_DigestInit_ex2(mdctx1,md,NULL)) {
            printf("Message 1 digest initialization failed.\n");
            EVP_MD_CTX_free(mdctx1);
            exit(1);
        }
        if (!EVP_DigestUpdate(mdctx1,mess1,strlen(mess1))) {
            printf("Message 1 digest update failed.\n");
            EVP_MD_CTX_free(mdctx1);
            exit(1);
        }
        if (!EVP_DigestFinal_ex(mdctx1, md_value1, &md_len1)) {
            printf("Message 1 digest finalization failed.\n");
            EVP_MD_CTX_free(mdctx1);
            exit(1);
        }
        EVP_MD_CTX_free(mdctx1);

        if (i == 0) {
            hashes[i][0] = md_value1[0];
            hashes[i][1] = md_value1[1];
            hashes[i][2] = md_value1[2];
        }
        
        for(j = i + 1; j <= 1000000; j++) {
            char mess2[11];
            sprintf(mess2,"%u",j);

            unsigned char md_value2[EVP_MAX_MD_SIZE];

            mdctx2 = EVP_MD_CTX_new();

            if (!EVP_DigestInit_ex2(mdctx2,md,NULL)) {
                printf("Message 2 digest initialization failed.\n");
                EVP_MD_CTX_free(mdctx2);
                exit(1);
            }
            if (!EVP_DigestUpdate(mdctx2,mess2,strlen(mess2))) {
                printf("Message 2 digest update failed.\n");
                EVP_MD_CTX_free(mdctx2);
                exit(1);
            }
            if (!EVP_DigestFinal_ex(mdctx2, md_value2, &md_len2)) {
                printf("Message 2 digest finalization failed.\n");
                EVP_MD_CTX_free(mdctx2);
                exit(1);
            }
            EVP_MD_CTX_free(mdctx2);
            counter++;

            hashes[j][0] = md_value2[0];
            hashes[j][1] = md_value2[1];
            hashes[j][2] = md_value2[2];

            for(unsigned long k = 0; k < j; k++) {
                if (hashes[k][0] == hashes[j][0] && hashes[k][1] == hashes[j][1] && hashes[k][2] == hashes[j][2]) {
                    printf("took %lu trials\n",counter);
                    exit(0);
                }
            }
        }
    }
}