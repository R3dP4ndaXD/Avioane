#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    int count = 1;
    void* idx = info;
    while (count <= nr_avioane) {
        printf("(%hu, ", *(unsigned short*)idx);
        idx += sizeof(unsigned short);
        printf("%hu)\n", *(unsigned short*)idx);
        idx += sizeof(unsigned short);
        printf("%c\n", *(unsigned char*)idx);
        idx += sizeof(unsigned char);
        printf("%c", *(unsigned char*)idx);
        idx += sizeof(unsigned char);
        printf("%c", *(unsigned char*)idx);
        idx += sizeof(unsigned char);
        printf("%c", *(unsigned char*)idx);
        idx += sizeof(unsigned char);
        printf("%c\n", *(unsigned char*)idx);
        idx += sizeof(unsigned char);
        printf("%i\n", *(unsigned int*)idx);
        idx += sizeof(unsigned int);
        printf("\n");
        count++;
    }
}
