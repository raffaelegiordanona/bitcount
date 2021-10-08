/**
 * C program to count total of zeros and ones in a binary number using bitwise operator
 */

#include <stdio.h>
#define BYTE_SIZE 8

int main(int argc, char *argv[])
{
    unsigned char num;
    int i, zeros = 0, ones = 0, bits = 0, bytes = 0, zbytes = 0, nzbytes = 0;
    FILE *fp;

    
    if (argc != 2) {
        printf("Wrong number of arguments.\n"); 
        printf("Usage: bitcount <input filename>\n"); 
        return -1;
    }

    fp = fopen(argv[1],"rb");  // r for read, b for binary
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]); 
        return -1;
    }

    // printf("%x\n",num); 
    while (fread(&num,1,1,fp)==1) { // read 1 byte 
      
        if (num==0) 
            zbytes++; 
        else 
            nzbytes++;
      // printf("%x\n",num);
      for(i=0; i<BYTE_SIZE; i++)
      {
        /* If LSB is set then increment ones otherwise zeros */
        if(num & 1)
            ones++;
        else
            zeros++;

        /* Right shift bits of num to one position */
        num >>= 1;
       }



       bits+=8;
       bytes++;
    
    }

    
    
    printf("Total bits %d\n", bits);
    printf("Total zeros are %d (%.2f %%)\n", zeros, (float) zeros * 100 / bits);
    printf("Total ones are %d (%.2f %%)\n", ones, (float) ones * 100 / bits);
    printf("\n");
    printf("Total bytes %d\n", bytes);
    printf("Total zeros bytes are %d (%.2f %%)\n", zbytes, (float) zbytes * 100 / bytes);
    printf("Total non-zero bytes are %d (%.2f %%)\n", nzbytes, (float) nzbytes * 100 / bytes);
    
    fclose(fp);

    return 0;
}


