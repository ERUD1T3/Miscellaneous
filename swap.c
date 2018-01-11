#include <stdio.h>
#define MASK 1000

void read_array(int len, int array[]);
void print_array(int len, int array[]);
void swap_single(int* x, int* y);
void swap_single_temp(int* x, int* y);
void swap_array(int len, int arr_x[], int arr_y[]);
void swap_array_temp(int len, int arr_x[], int arr_y[]); 
void copy_array(int len, int dest[], int src[]);

int main(void) {
    
    int cmd;
    printf("Please define the type of the inputs (0: integer, 1: arrays of integer): ");
    scanf("%d", &cmd);

    if(cmd) { //cmd == 1 so array
        unsigned int len;
        printf("Please enter the length of the arrays: ");
        scanf("%d", &len);
        int arr_x[len], arr_y[len], arr_x_tmp[len], arr_y_tmp[len];
        printf("Please enter the first array as array1: ");
        read_array(len, arr_x);
        printf("Please enter the second array as array2: ");
        read_array(len, arr_y);
        copy_array(len, arr_x_tmp, arr_x);
        copy_array(len, arr_y_tmp, arr_y);
        swap_array(len, arr_x, arr_y);
        swap_array_temp(len, arr_x_tmp, arr_y_tmp);

        printf("The output after the exchange is:\n");
        printf("array1 = "); print_array(len, arr_x);
        printf("array2 = "); print_array(len, arr_y);
        
        printf("Using temp:\n");
        printf("array1 = "); print_array(len, arr_x_tmp);
        printf("array2 = "); print_array(len, arr_y_tmp);

    }
    else { //cmd == 0 so integers
        int x, y;
        printf("Please enter the first variable as x: ");
        scanf("%d", &x);
        printf("Please enter the second variable as y: ");
        scanf("%d", &y);
        int x_tmp = x, y_tmp = y;
        swap_single(&x,&y);
        swap_single_temp(&x_tmp, &y_tmp);
        printf("The output after the exchange is:\nx = %d\ny = %d\nUsing Temp\nx = %d\ny = %d\n", x, y, x_tmp, y_tmp);
    }

    return 0;
}

void read_array(int len, int array[]) {
    for(unsigned short i = 0; i < len; ++i)
        scanf("%d", array + i);
}

void print_array(int len, int array[]) {
    for(unsigned short i = 0; i < len; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

void swap_single(int* x, int* y) {
    *x = *x * MASK + *y;
    *y = (int)(*x)/MASK;
    *x = (*x)%MASK;
}

void swap_single_temp(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_array(int len, int arr_x[], int arr_y[]) {
    for(unsigned short i = 0; i < len; ++i) 
        swap_single(arr_x + i, arr_y + i);
}

void swap_array_temp(int len, int arr_x[], int arr_y[]) {
    for(unsigned short i = 0; i < len; ++i)
        swap_single_temp(arr_x+i, arr_y+i);   
}

void copy_array(int len, int dest[], int src[]) {
    for(unsigned short i = 0; i < len; ++i)
        dest[i] = src[i];
}