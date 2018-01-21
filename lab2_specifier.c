#include <stdio.h>

void read_file(FILE* ifp, char* to_format);  //read the file in a variable
void reformat_and_save_file(FILE *ofp, char *formated); //reformart the variables as each line ask how and save in a new file adding a new column


int main(int argc, char* argv[]) {
    char *input_file = argv[1], *output_file = argv[2];
    FILE *ifp, *ofp;
    ifp = fopen(input_file,"r");
    ofp = fopen(output_file, "w");

    char* data;
    read_file(ifp, data);
    reformat_and_save_file(ofp, data);

    fclose(ifp);
    fclose(ofp);
  return 0;
}

void read_file(FILE* ifp, char* to_format) {
    fscanf(ifp, " %d", to_format);
}

void reformat_and_save_file(FILE *ofp, char *formated){
    fprintf(ofp, " %d", formated);
}
