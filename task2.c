#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    void *idx = info;
    int next = 4 * sizeof(unsigned char) + sizeof(unsigned int);
    int count = 1;
    while (count <= nr_avioane) {
        unsigned short x = 0, y = 0;
        unsigned char dir = 0, tip = 0;
        x = *((unsigned short*)idx);
        idx += sizeof(unsigned short);
        y = *((unsigned short*)idx);
        idx += sizeof(unsigned short);
        dir = *((unsigned char*)idx);
        idx += sizeof(unsigned char);
        tip = *((unsigned char*)idx);
        unsigned short lin = x, col = y;
        if (tip == '1') {
            if (dir == 'N') {
                mat[lin][y] = '*';
                lin++;
                for (col = y -2; col<= y +2; col++) {
                    mat[lin][col] = '*';
                }
                lin++;
                mat[lin][y] = '*';
                lin++;
                for (col = y -1; col<= y +1; col++) {
                    mat[lin][col] = '*';
                }
            } else if (dir == 'S') {
                mat[lin][y] = '*';
                lin--;
                for (col = y -2; col<= y +2; col++) {
                    mat[lin][col] = '*';
                }
                lin--;
                mat[lin][y] = '*';
                lin--;
                for (col = y -1; col<= y +1; col++) {
                    mat[lin][col] = '*';
                }
            } else if (dir == 'E') {
                mat[x][col] = '*';
                col--;
                for (lin = x -2; lin <= x +2; lin++) {
                    mat[lin][col] = '*';
                }
                col--;
                mat[x][col] = '*';
                col--;
                for (lin = x -1; lin<= x +1; lin++) {
                    mat[lin][col] = '*';
                }
            } else {
                mat[x][col] = '*';
                col++;
                for (lin = x -2; lin <= x +2; lin++) {
                    mat[lin][col] = '*';
                }
                col++;
                mat[x][col] = '*';
                col++;
                for (lin = x -1; lin<= x +1; lin++) {
                    mat[lin][col] = '*';
                }
            }
        } else {
            if (dir == 'N') {
                mat[lin][y] = '*';
                lin++;
                for (col = y -1; col<= y +1; col++) {
                    mat[lin][col] = '*';
                }
                lin++;
                for (col = y -3; col<= y +3; col++) {
                    mat[lin][col] = '*';
                }
                lin++;
                mat[lin][y] = '*';
                lin++;
                for (col = y -2; col<= y +2; col++) {
                    mat[lin][col] = '*';
                }
            } else if (dir == 'S') {
                mat[lin][y] = '*';
                lin--;
                for (col = y -1; col<= y +1; col++) {
                    mat[lin][col] = '*';
                }
                lin--;
                for (col = y -3; col<= y +3; col++) {
                    mat[lin][col] = '*';
                }
                lin--;
                mat[lin][y] = '*';
                lin--;
                for (col = y -2; col<= y +2; col++) {
                    mat[lin][col] = '*';
                }
            } else if (dir == 'E') {
                mat[x][col] = '*';
                col--;
                for (lin = x -1; lin <= x +1; lin++) {
                    mat[lin][col] = '*';
                }
                col--;
                for (lin = x -3; lin <= x +3; lin++) {
                    mat[lin][col] = '*';
                }
                col--;
                mat[x][col] = '*';
                col--;
                for (lin = x -2; lin<= x +2; lin++) {
                    mat[lin][col] = '*';
                }
            } else {
                mat[x][col] = '*';
                col++;
                for (lin = x -1; lin <= x +1; lin++) {
                    mat[lin][col] = '*';
                }
                col++;
                for (lin = x -3; lin <= x +3; lin++) {
                    mat[lin][col] = '*';
                }
                col++;
                mat[x][col] = '*';
                col++;
                for (lin = x -2; lin<= x +2; lin++) {
                    mat[lin][col] = '*';
                }
            }
        }
        idx += next;
        count++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}
