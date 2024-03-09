#include "./utils.h"

void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N) {
    char **mat = NULL;
    mat = init_mat(N);
    for (int i = 0; i < nr_pct_coord; i++) {
        mat[X[i]][Y[i]] = '@';
    }
    const int next = sizeof(unsigned int);
    for (int t = 0; t <= T; t++) {
        void *idx = info;
        int count = 1, dead = 0, search = 1;
        while (count <= nr_avioane) {
            int x = 0, y = 0, v = 0;
            unsigned char dir = 0, tip = 0;
            x = *((unsigned short *)idx);
            idx +=sizeof(unsigned short);
            y = *((unsigned short *)idx);
            idx +=sizeof(unsigned short);
            dir = *((unsigned char*)idx);
            idx +=sizeof(unsigned char);
            tip = *((unsigned char*)idx);
            idx +=4*sizeof(unsigned char);
            v =  *((int*)idx);
            if (dir == 'N') {
                x -= v * t;
            } else if (dir == 'S') {
                x += v * t;
            } else if (dir == 'E') {
                y += v * t;
            } else {
                y -= v * t;
            }
            int lin = x, col = y;
            search = 1;
            if (tip == '1') {
                if (dir == 'N') {
                    if ((lin >= 0) && mat[lin][y] == '@') {
                        search = 0;
                    }
                    lin++;
                    for (col = y -2; col <= y + 2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin++;
                    if ((lin >= 0 && lin < N && search) && mat[lin][y] == '@') {
                        search = 0;
                    }
                    lin++;
                    for (col = y -1; col<= y +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                         if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else if (dir == 'S') {
                    if ((lin < N) && mat[lin][y] == '@') {
                        search = 0;
                    }
                    lin--;
                    for (col = y -2; col<= y +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin--;
                    if ((lin >= 0 && lin < N && search) && mat[lin][y] == '@') {
                        search = 0;
                    }
                    lin--;
                    for (col = y -1; col<= y +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                       if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else if (dir == 'E') {
                    if ((col < N) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col--;
                    for (lin = x -2; lin <= x +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col--;
                    if ((col >= 0 && col <N && search) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col--;
                    for (lin = x -1; lin<= x +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else {
                    if ((col >= 0) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col++;
                    for (lin = x -2; lin <= x +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col++;
                    if ((col >= 0 && col < N && search) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col++;
                    for (lin = x -1; lin <= x +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            } else {
                if (dir == 'N') {
                    if ((lin >= 0) && mat[lin][y] == '@') {
                        search = 0;
                    }
                    lin++;
                    for (col = y -1; col<= y +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin++;
                    for (col = y -3; col<= y +3 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin++;
                    if ((lin >= 0 && lin < N && search) && mat[lin][y] =='@') {
                        search = 0;
                    }
                    lin++;
                    for (col = y -2; col<= y +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else if (dir == 'S') {
                    if ((lin < N) &&  mat[lin][y] == '@')  {
                        search = 0;
                    }
                    lin--;
                    for (col = y -1; col<= y +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin--;
                    for (col = y -3; col<= y +3 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    lin--;
                    if ((lin >= 0 && lin < N) &&  mat[lin][y] == '@')  {
                        search = 0;
                    }
                    lin--;
                    for (col = y -2; col<= y +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); col++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else if (dir == 'E') {
                    if ((col < N) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col--;
                    for (lin = x -1; lin <= x +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col--;
                    for (lin = x -3; lin <= x +3 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col--;
                     if ((col>= 0 && col < N) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col--;
                    for (lin = x -2; lin<= x +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                } else {
                    if ((col >= 0) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col++;
                    for (lin = x -1; lin <= x +1 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col++;
                    for (lin = x -3; lin <= x +3 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                    col++;
                    if ((col >= 0 && col < N) && mat[x][col] == '@') {
                        search = 0;
                    }
                    col++;
                    for (lin = x -2; lin<= x +2 && (lin >= 0 && lin < N && col >= 0 && col < N && search); lin++) {
                        if (mat[lin][col] == '@') {
                            search = 0;
                        }
                    }
                }
            }
            if (!search) {
                dead++;
            }
            // printf("%i dupa %i iteratii\n",dead, count);
            count++;
            idx += next;
        }
        /*for(int l = 0; l < N; l++) {
            for(int p = 0; p < N; p++) {
                printf("%c", mat[l][p]);
            }
            printf("\n");
        }*/
        printf("%i : %i\n", t, dead);
    }
    free_mat(mat, N);
}
