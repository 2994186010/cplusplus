#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int** pTemp;
    const int nEntrySize = 8;
    const int nChunkSize = 9;

    int** pLinkList = (int**)malloc(sizeof(int*) * nEntrySize *nChunkSize);
    if(pLinkList==NULL) {
        printf("unable to apply for enough memory");
        return 0;
    }
    memset(pLinkList, 0, sizeof(int*) * nEntrySize *nChunkSize);

    pTemp = pLinkList;

    for(int i=1; i<nChunkSize; i++) {
        *(int**)pTemp = (int*)(pTemp + nEntrySize);
        pTemp += 8;
    }

    pTemp = NULL;

    pTemp = pLinkList;

    printf("%d\n", sizeof(long));

    for(int i=1; i<nChunkSize; i++) {
        for(int j=1; j<nEntrySize; j++) {
            printf("%lx %lx\n", pTemp++, *pTemp);
        }
    }

    free(pLinkList);
    pLinkList = NULL;

    return 0;
}