#include <stdio.h>
#include <stdint.h>
#include "changetext.h"

int main()
{
    uint16_t str[] = {'h', 'e', 'l', 'l', 'o', 0};
    uint16_t * out_str;
    printf("Init returned: %d\n", Init());
    out_str = ChangeText(str);
    puts("ChangeText() returned:\n");
    printf("%08x\n", out_str);
    if(!out_str)
        puts("NULL\n");
    else
        for(int i = 0; out_str[i]; i++)
            printf("%04x %c\n", out_str[i], out_str[i]);
    return 0;
}
