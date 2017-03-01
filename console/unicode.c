#include <stdint.h>

typedef union unichr
{
    uint8_t  c[2];

    uint16_t u;
    
    struct
    {
        uint16_t uni_l : 5;
        uint16_t multibyte_mark : 3;
     
        uint16_t uni_r : 6;
        uint16_t multibyte_continue : 2;
    };
} unichr;


void utf8_to_cp1251(char *str)
{
    for (char *ptr = str; *ptr; ptr++)
    {
        if ((*ptr & 0xE0) == 0xC0)          // utf-8 multibyte seq flag
        {
            char c = *ptr;
            unichr u = { { c, *++ptr } };
            
            u.u = u.uni_l << 6 | u.uni_r;   // letter in 11-bit unicode

            if (u.u == 0x0451)              // latin letter YO
            {
                u.u = 0xE5;                 // make it YE
            }
            else
            {
                u.u -= 0x0410;              // A in unicode
                u.u += 0xC0;                // A in cp1251
            }

            *ptr = u.c[0];
        }
        *str++ = *ptr;
    }
    *str = 0;
}

