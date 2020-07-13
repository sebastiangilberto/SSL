/* wl-1-enum-switch.c
 * Sebastian Gilberto
 * 20200713
 */

#include <stdio.h>

typedef enum {
    In, Out
} State;

int main(void){
    
    State s = Out;
    int c;

    while ((c = getchar()) != EOF) {            
        switch(c) {
            case ' ':
            case '\t':
            case '\n':
            case '.':
            case ',':
            case ';':
                if(s == In) {
                    s = Out;
                    putchar('\n');
                }
                break;
            default:
                s = In;
                putchar(c);
                break;
        }
    }
    
    return 0;
}