#include <cstdio>
#include <cstdint>
#include "changetext.h"

void test(char16_t * str)
{
    uint16_t * out_str = ChangeText((uint16_t *)str);
    puts("ChangeText() returned:");
    if(!out_str)
        puts("NULL");
    else {
        printf("%p\n", out_str);
        for(int i = 0; out_str[i]; i++) {
            printf("%04x %c\n", out_str[i], out_str[i]);
        }
    }
}

int main()
{
    char16_t str1[] = u"hello";
    char16_t str2[] = u"HELLO";
    int is_initialized = Init();
    
    printf("Init returned: %d\n", is_initialized);
    if(!is_initialized) return 1;
    
    test(str1);
    test(str2);
    
    return 0;
}
