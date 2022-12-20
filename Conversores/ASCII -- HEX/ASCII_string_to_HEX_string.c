#include <stdio.h>
#include <string.h>

//function to convert ascii char[] to hex-string (char[])
void string2hexString(char* input, char* output)
{
    int loop = 0;
    int i = 0; 
    
    while(input[loop] != NULL)
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }

    output[i++] = NULL;
}

void main()
{
    char ACII_string[] = "Hello world!";
    int len = strlen(ACII_string);
    char HEX_string[(len*2)+1];    
    string2hexString(ACII_string, HEX_string);    
    printf("ascii_str: %s\n", ACII_string);
    printf("hex_str: %s\n", HEX_string);
}