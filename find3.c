/* find3.c - Open file and count the number of '3' characters found 
   @MarquetteU  - F. Frigo - Modified by Emma Ludwig
   COEN 2610
   To compile: cc -g find3.c -o find3
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 80

int main(void)
{
    FILE *fd;
    char *filename[MAX_STRING_LEN];
    int i, file_size;
    int three_count = 0;
    unsigned char value;
   
   printf("Enter file name to check: ");
   scanf("%79s", filename);

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
       if( value == '3') three_count++; 
    }
    fclose(fd);
    printf("Number of '3' characters found in %s = %d\n", filename, three_count);
    exit(0);
}
