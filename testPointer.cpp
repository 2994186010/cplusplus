#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* MALLOC(int size) {
    void* pArr = malloc(size);
    if (pArr == NULL) {
        printf("unable to get enough memory");
        return 0;
    }
    memset(pArr, 0, size);
    return pArr;
}

void FREE(void* pArr) {
    free(pArr);
    pArr = NULL;
}

int main()
{
    const int nEntrySize = 8;
    const int nChunkSize = 9;

    void* pArr = MALLOC(sizeof(void) * nEntrySize * nChunkSize);
    void* pNext = pArr + 1;
    printf("%d \n", (unsigned long)pNext - (unsigned long)pArr);
    FREE(pArr);

    void** pArr1 = (void**)MALLOC(sizeof(void*) * nEntrySize * nChunkSize);
    void** pNext1 = pArr1 + 1;
    printf("%d \n", (unsigned long)pNext1 - (unsigned long)pArr1);
    FREE(pArr1);

    char* pCharArr = (char*)MALLOC(sizeof(char) * nEntrySize * nChunkSize);
    char* pCharNext = pCharArr + 1;
    printf("%d \n", (unsigned long)pCharNext - (unsigned long)pCharArr);
    FREE(pCharArr);

    char** pCharArr1 = (char**)MALLOC(sizeof(char*) * nEntrySize * nChunkSize);
    char** pCharNext1 = pCharArr1 + 1;
    printf("%d \n", (unsigned long)pCharNext1 - (unsigned long)pCharArr1);
    FREE(pCharArr1);

    int* pIntArr = (int*)MALLOC(sizeof(int) * nEntrySize * nChunkSize);
    int* pIntNext = pIntArr + 1;
    printf("%d \n", (unsigned long)pIntNext - (unsigned long)pIntArr);
    FREE(pIntArr);

    int** pIntArr1 = (int**)MALLOC(sizeof(int*) * nEntrySize * nChunkSize);
    int** pIntNext1 = pIntArr1 + 1;
    printf("%d \n", (unsigned long)pIntNext1 - (unsigned long)pIntArr1);
    FREE(pIntArr1);

    return 0;
}