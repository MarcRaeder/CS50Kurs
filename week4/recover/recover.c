#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");

        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == 0)
    {
        printf("Could not open file\n");
        
        return 2;
    }

    char *filename = malloc(8 * sizeof(char));
    int count_image = 0;
    unsigned char buffer[512];

    FILE *output_file = NULL;

    while (fread(buffer, sizeof(char), 512, input_file))
    {
        bool checkBytesIndicateStartOfJPEG = (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xff) == 0xe0);
        if (checkBytesIndicateStartOfJPEG)
        {
            sprintf(filename, "%03i.jpg", count_image);
            output_file = fopen(filename, "w");
            count_image++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}
