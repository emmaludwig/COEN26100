/* find7.c - Open file and count the number of '7' characters found 
   @MarquetteU  - F. Frigo
   COEN 2610
   To compile: cc -g find7.c -o find7
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fd;
    const char *filename = {"list.txt"};
    int i, file_size;
    int seven_count = 0;
    unsigned char value;

    /* Open file in binary mode for reading */
    fd = fopen(filename, "rb");
    if(fd == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    /* Get size in bytes */
    fseek(fd, 0, SEEK_END);
    file_size = ftell(fd);

    /* Start at the begining of the file */ 
    fseek(fd, 0, SEEK_SET);
    /* Test each byte to count 7's */
    for( i = 0; i< file_size; i++)
    {
       fread(&value, 1, 1, fd);
       if( value == '7') seven_count++; 
    }
    fclose(fd);
    printf("Number of '7' characters found in %s = %d\n", filename, seven_count);
    exit(0);
}
