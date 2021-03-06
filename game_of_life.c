#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define SIZE 6
#define TOKEN ';'
#define ALIVE 1
#define DEAD 0
typedef unsigned short ushort;

ushort get_array_size(char *file_name);
void getWorld(FILE *ifp, int *world, ushort size);
void printWorld(int *world, ushort size, FILE* ofp);
void cell_life(int *world, ushort size, ushort n_gen, FILE* ofp);
ushort check_neighbors(int *world, ushort size, const ushort row, const ushort col);
int num_cell_alive(int *world, ushort size);

int main(int argc, char* argv[]) {
    clock_t start = clock();
    FILE *ifp, *ofp;
    ifp = fopen(argv[1], "r");
    ofp = fopen("output.csv", "w");

    const ushort size = get_array_size(argv[1]);
    //int world[size][size];
    printf("array size is %hu\n", size);
    int *world = malloc(size*size*sizeof(int));

    getWorld(ifp,world, size);
    //printf("File name is %s\n", argv[1]);
    //printf("\n");
    printWorld(world, size, ofp);
    printf("\n");
    //printf("check neighboor at 2 and 5 = %d\n\n",check_neighbors(world,size, 2, 5));
    cell_life(world, size, atoi(argv[2]), ofp);
    //printWorld(world, size);

    fclose(ifp);
    fclose(ofp);
    free(world);
    clock_t end = clock();
    double time_p = (double)(end - start)/CLOCKS_PER_SEC;
    printf("time: %lf\n", time_p);
    return 0;
}

ushort get_array_size(char* file_name) {
    FILE *sizep = fopen(file_name, "r");
    ushort size;
    char token;
    do {
        token = fgetc(sizep);
        if(token == '0') size++;
    } while(fgetc(sizep) != '\n');
    fclose(sizep);
    return size;
}

void getWorld(FILE *ifp, int *world, ushort size) {
    int i = 0, j = 0;
    char cell_data;
    do {
        cell_data = fgetc(ifp);
       // printf("char = (%c) ", cell_data);
        if(cell_data != TOKEN) {
        *(world + i*size + (j++ % size)) = (int)cell_data - 48;
        i = (!(j%size))?++i:i;
        }
    } while(fgetc(ifp) != EOF);
}

void printWorld(int *world, ushort size, FILE* ofp) {
    for(ushort i = 0; i < size; ++i) {
        for(ushort j = 0; j < size; ++j) {
            //printf("%d ", *(world + i*size + j));
            (*(world + i*size + j))?printf("|O"):printf("| ");
            (*(world + i*size + j))?fprintf(ofp,"|O"):fprintf(ofp,"| ");
        }
    printf("|\n");
    fprintf(ofp,"|\n");
    }
}

ushort check_neighbors(int *world, ushort size, const ushort row, const ushort col) {
    ushort n_live_neighbors = 0, n_dead_neighbors = 0;
    
    for(short i = row-1; i <= row+1; ++i){
        if(i < 0 || i >= size) continue;

        for(short j = col-1; j <= col+1; ++j) {
            if(j < 0 || j >= size) continue;

            if(*(world + i*size + j) == ALIVE)
                n_live_neighbors++;
            else 
                n_dead_neighbors++;
                /*
            if(world[i][j] == DEAD)
                n_dead_neighbors++;
                */
            
        }
    }

    if(*(world + row*size + col) == ALIVE)
        n_live_neighbors--;
    else 
        n_dead_neighbors--;

    return n_live_neighbors*10+n_dead_neighbors; //num live neigh/num dead neighbor
}

void cell_life(int *world, ushort size, ushort n_gen, FILE* ofp) {
    for(ushort k = 0; k < n_gen; ++k) {
        for(ushort i = 0; i < size; ++i) {
            for(ushort j = 0; j < size; ++j) {
                ushort neighb = check_neighbors(world,size, i, j);
                if(*(world + i*size + j) == ALIVE) 
                    *(world + i*size + j) = (((int)neighb/10) == 2 || ((int)neighb/10) == 3)?ALIVE:DEAD;
                else //cell is dead
                    *(world + i*size + j) = ((int)neighb/10 == 3)?ALIVE:DEAD;  

            }
        }
        printWorld(world, size, ofp);
        printf("gen: %hu | #alive: %d\n\n", k + 1, num_cell_alive(world, size));
        fprintf(ofp, "gen: %hu | #alive: %d\n\n", k + 1, num_cell_alive(world, size));
        for(short i = 0; i < 9999; ++i);
        system("clear");
    }
}

int num_cell_alive(int *world, ushort size) {
    int n_alive = 0;
    for(ushort i = 0; i < size; ++i) {
        for(ushort j = 0; j < size; j++) {
        if(*(world + i*size + j) == ALIVE)
            n_alive++;
        }
    }
    return n_alive;
}

//Coded by Josias
