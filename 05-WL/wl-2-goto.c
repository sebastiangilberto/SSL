/* wl-2-goto.c
 * Sebastian Gilberto
 * 20200713
 */

#include <stdio.h>

int main(void) {
    int c;

    Read:
        if ((c = getchar()) != EOF) {            
            switch(c) {
                case ' ':
                case '\t':
                case '\n':
                case '.':
                case ',':
                case ';':
                    goto Out;
                    break;
                default:
                    goto In;
                    break;
            }
        }
        
        return 0;

    In:
        putchar(c);
        goto Read;

    Out:
        putchar('\n');
        goto Read;
}