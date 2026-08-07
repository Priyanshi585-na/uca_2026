#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const char* input)
{
    int len = strlen(input);
    int output_len = 4 * ((len + 2) / 3);
    char* output = (char*)malloc(output_len + 1);

    int i = 0, j = 0;

    while(i < len)
    {
        int remaining = len - i;

        int a = input[i++];
        int b = (remaining > 1) ? input[i++] : 0;
        int c = (remaining > 2) ? input[i++] : 0;

        int index1 = (a >> 2);
        int index2 = ((a & 0x03) << 4) | (b >> 4);
        int index3 = ((b & 0x0F) << 2) | (c >> 6);
        int index4 = (c & 0x3F);

        
        output[j++] = base64_table[index1];
        output[j++] = base64_table[index2];

        if(remaining > 1)
            output[j++] = base64_table[index3];
        else
            output[j++] = '=';

        if(remaining > 2)
            output[j++] = base64_table[index4];
        else
            output[j++] = '=';
    }

    output[j] = '\0';
    return output;
}

int main()
{
    char input[] = "Hello World";

    char* encoded = base64_encode(input);

    printf("%s\n", encoded);

    free(encoded);
    return 0;
}
