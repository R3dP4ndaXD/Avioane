#include "./utils.h"

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *X, int *Y, int N) {
    char **mat = NULL;
    mat = init_mat(N);
    for (int i = 0; i < nr_obstacole; i++) {
        mat[X[i]][Y[i]] = '@';
    }
    void *idx = info;
    const int next = 4*sizeof(unsigned char) + sizeof(unsigned int);
    int count = 1, safe = 0, search = 1;
    while (count <= nr_avioane) {
        unsigned short x = 0, y = 0;
        unsigned char dir = 0, tip = 0;
        x = *((unsigned short*)idx);
        idx +=sizeof(unsigned short);
        y = *((unsigned short*)idx);
        idx +=sizeof(unsigned short);
        dir = *((unsigned char*)idx);
        idx +=sizeof(unsigned char);
        tip = *((unsigned char*)idx);
        int lin = x, col = y;
        search = 1;
        if (tip == '1') {
            if (dir == 'N') {
                for (lin = x+3; lin >= x+2 && search; lin--) {
                    for (col = y-1; col <= y+1 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (lin = x+1; lin >= 0 && search; lin--) {
                    for (col = y-2; col <= y+2 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else if (dir == 'S') {
                for (lin = x-3; lin <= x-2 && search; lin++) {
                    for (col = y-1; col <= y+1 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (lin = x-1; lin < N && search; lin++) {
                    for (col = y-2; col <= y+2 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else if (dir == 'E') {
                for (col = y-3; col <= y-2 && search; col++) {
                    for (lin = x-1; lin <= x+1 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (col = y-1; col < N && search; col++) {
                    for (lin = x-2; lin <= x+2 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else {
               for (col = y+3; col >= y+2 && search; col--) {
                    for (lin = x-1; lin <= x+1 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (col = y+1; col >= 0 && search; col--) {
                    for (lin = x-2; lin <= x+2 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            }
        } else {
            if (dir == 'N') {
                for (lin = x +4; lin >= x +3 && search; lin--) {
                    for (col = y-2; col <= y+2 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (lin = x +2; lin >= 0 && search; lin--) {
                    for (col = y-3; col <= y+3 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else if (dir == 'S') {
                for (lin = x -4; lin <= x-3 && search; lin++) {
                    for (col = y-2; col <= y+2 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (lin = x -2; lin < N && search; lin++) {
                    for (col = y-3; col <= y+3 && search; col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else if (dir == 'E') {
                for (col = y-4; col <= y-3 && search; col++) {
                    for (lin = x-2; lin <= x+2 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (col = y-2; col < N && search; col++) {
                    for (lin = x-3; lin <= x+3 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else {
                for (col = y+4; col >= y+3 && search; col--) {
                    for (lin = x-2; lin <= x+2 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
                for (col = y+2; col >= 0 && search; col--) {
                    for (lin = x-3; lin <= x+3 && search; lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            }
        }
        if (search) {
            safe++;
        }
        // printf("%i dupa %i iteratii\n",safe, count);
        count++;
        idx += next;
    }
    /*for(int l = 0; l < N; l++) {
        for(int p = 0; p < N; p++) {
            printf("%c", mat[l][p]);
        }
        printf("\n");
    }*/
    printf("%i\n", safe);
    free_mat(mat, N);
}
