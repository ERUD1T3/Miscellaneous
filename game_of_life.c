#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 6
#define TOKEN ';'
#define ALIVE 1
#define DEAD 0
typedef unsigned short ushort;

void getWorld(FILE *ifp, int world[SIZE][SIZE]);
void printWorld(int world[SIZE][SIZE]);
void cell_life(int world[SIZE][SIZE], ushort n_gen);
ushort check_neighbors(int world[SIZE][SIZE], const ushort row, const ushort col);

int main(int argc, char* argv[]) {
    FILE *ifp, *ofp;
    ifp = fopen(argv[1], "r");
    ofp = fopen("output.txt", "w");
    int world[SIZE][SIZE];

    getWorld(ifp,world);
    //printf("File name is %s\n", argv[1]);
    //printf("\n");
    printWorld(world);
    printf("\n");
    printf("check neighboor at 0 and 3 = %d\n",check_neighbors(world, 0, 3));
    cell_life(world, atoi(argv[2]));
    printWorld(world);

    fclose(ifp);
    fclose(ofp);
    return 0;
}

void getWorld(FILE *ifp, int world[SIZE][SIZE]) {
    int i = 0, j = 0;
    char cell_data;
    do {
        cell_data = fgetc(ifp);
       // printf("char = (%c) ", cell_data);
        if(cell_data != TOKEN) {
        world[i][j++ % 6] = (int)cell_data - 48;
        i = (!(j%6))?++i:i;
        }
    } while(fgetc(ifp) != EOF);
}

void printWorld(int world[SIZE][SIZE]) {
    for(ushort i = 0; i < SIZE; ++i) {
        for(ushort j = 0; j < SIZE; ++j) {
            printf("%d ", world[i][j]);
        }
    printf("\n");
    }
}

ushort check_neighbors(int world[SIZE][SIZE], const ushort row, const ushort col) {
    ushort n_live_neighbors = 0, n_dead_neighbors = 0;
    
    for(ushort i = row-1; i <= row+1; ++i){
        if(i < 0 || i > SIZE) continue;
        for(ushort j = col-1; j <= col+1; ++j) {
            if(j < 0 || j > SIZE) continue;

            if(world[i][j] == ALIVE)
            n_live_neighbors++;
            
            if(world[i][j] == DEAD)
            n_dead_neighbors++;
            //invalid cell
        }
    }

    if(world[row][col] == ALIVE)
        n_live_neighbors--;
    else 
        n_dead_neighbors--;

    return n_live_neighbors*10+n_dead_neighbors;
}

void cell_life(int world[SIZE][SIZE], ushort n_gen) {
    for(ushort k = 0; k < n_gen; ++k) {
        for(ushort i = 0; i < SIZE; ++i){
            for(ushort j = 0; j < SIZE; ++j) {
                if(world[i][j] == ALIVE) {
                    world[i][j] = (check_neighbors(world, i, j)/10 == 2 || check_neighbors(world, i, j)/10 == 3)?ALIVE:DEAD;
                } 
                else //cell is dead
                    world[i][j] = (check_neighbors(world, i, j)/10 == 3)?ALIVE:DEAD;  

            }
        }
    }
}