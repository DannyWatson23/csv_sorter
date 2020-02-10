#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "grab_type.h"

char read_file[8] = "data.csv";

int main(){
 FILE * f1;
 int buflen = 255;
 char buff[buflen];
 f1 = fopen(read_file, "r");
 while(fgets(buff, buflen,  f1)){
   // write_to_file asks for a pointer BECAUSE fgets assigns a pointer to buff
   graba(buff);
   // return;
   // write_to_file(buff, f1);
 }
 fclose(f1);
 f1 = NULL;
 printf("Completed successfully\n");
 return 0;
}
