#include <stdio.h>
int main()
{
    char str[15];
    int num;
    while(scanf("%s", str), str[0] != '-') {
        if(str[1] == 'x') {
            sscanf(str, "%x", &num);
            printf("in decimal: %d\n", num);
        }
        else {
            sscanf(str, "%d", &num);
            printf("in hexadecimal: 0x%X\n", num);
            printf("in octal: %o\n",num);
        }
    }
    return 0;
}

/*
Input
*/

/*
0x7FFFFFFF
2147483647
43438943
0xFACE
0xBEEF
-1234
*/