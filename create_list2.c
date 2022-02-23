/* create_list.c - create file 100 lines long  with numbers from 00-99 
   @MarquetteU  - F. Frigo
   COEN 2610
   To compile: cc -g create_list.c -o create_list
   To check the number of lines in file use: `wc -l list.txt`
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fd;
    int i;
    const char *filename = {"list.txt"};

    /* Create file */
    fd = fopen(filename, "w");
    if(fd == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    /* Loop to write 1000 numbers to the file */
    for( i = 0; i< 1000; i++)
    {
        fprintf(fd, "%3.3d\n", i);
    }
    fclose(fd);

    printf("File created: %s\n", filename);
    exit(0);
}
