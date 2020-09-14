/* wl-2-goto.c
 * Sebastian Gilberto
 * 20200713
 */

#include <stdio.h>

int main(void) {
    int c;

    Out:           
        switch(c = getchar()) {
            case ' ':
            case '\t':
            case '\n':
            case '.':
            case ',':
            case ';':
                putchar('\n');
                goto Out;
            case EOF: return;
            default:
                putchar(c);
                goto Out;
        }

    return 0;
}