#include "./utils.h"

int my_cmp(const void *a, const void *b) {
    const unsigned int pos_tip = 2*sizeof(unsigned short)+ sizeof(unsigned char);
    const unsigned int pos_coo = 2*sizeof(unsigned short)+ 2*sizeof(unsigned char);
    const unsigned int pos_v = 2*sizeof(unsigned short)+ 5*sizeof(unsigned char);
    unsigned char *tip1 = (unsigned char *)a + pos_tip;
    unsigned char *tip2 = (unsigned char *)b + pos_tip;
    unsigned char *coo1 = (unsigned char *)a + pos_coo;
    unsigned char *coo2 = (unsigned char *)b + pos_coo;
    unsigned int *v1 = (unsigned int *)((unsigned char *)a + pos_v);
    unsigned int *v2 = (unsigned int *)((unsigned char *)b + pos_v);
    if (strncmp(tip1, tip2, 1)) {
        return strncmp(tip1, tip2, 1);
    } else if (strncmp(coo2, coo1, 3)) {
        return strncmp(coo2, coo1, 3);
    } else if (*v1 < *v2) {
        return -1;
    } else if (*v1 > *v2) {
        return 1;
    } else {
        return 0;
    }
}
void SolveTask3(void *info, int nr_avioane) {
    const unsigned int len = 2*sizeof(unsigned short)+ 5*sizeof(unsigned char) +sizeof(unsigned int);
    qsort(info, nr_avioane, len, my_cmp);
    SolveTask1(info, nr_avioane);
}
