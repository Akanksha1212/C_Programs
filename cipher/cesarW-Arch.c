#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p printf
void codify(FILE* arq, int k, int n, int m)
{
    char senha[m];
    int count;
    FILE* arq_2;
    arq_2 = fopen("data.txt", "w");
    while (1) {
        int c = fgetc(arq);
        if (c == EOF || c == '\n') {
            fprintf(arq_2, "\n");
            if (c == EOF)
                break;
        }
        else {
            if (c >= 'A' && c <= 'Z') {
                if (c + k > 'Z') {
                    c = (k % 25 + c - !(!(k % 25)));
                    fprintf(arq_2, "%c", c);
                }
                if (c + k < 'A') {
                    c = (k % 25 + c + !(!(k % 25)));
                    fprintf(arq_2, "%c", c);
                }
                if (c + k >= 'A' && c + k <= 'Z') {
                    c = k % 25 + c;
                    fprintf(arq_2, "%c", c);
                }
            }
            if (c >= 'a' and c <= 'z') {
                if (c + k > 'z') {
                    c = (k % 25 + c - !(!(k % 25)));
                    printf("%d\n", c);
                    fprintf(arq_2, "%c", c);
                }
                if (c + k < 'a') {
                    c = (k % 25 + c + !(!(k % 25)));
                    fprintf(arq_2, "%c", c);
                }
                if (c + k >= 'a' && c + k <= 'z') {
                    c = k % 25 + c;
                    fprintf(arq_2, "%c", c);
                }
            }
            if (!(c >= 65 && c <= 90) && !(c >= 97 and c <= 122)) {
                fprintf(arq_2, "%c", c);
            }
        }
    }
    fclose(arq_2);
}
int main()
{
    FILE* arq;
    int n;
    int m;
    int k;
    p("Type the maximum character length for passwords!");
    scanf("%d", &m);
    p("Type passwords quantity!");
    scanf("%d", &n);
    p("Type encrypt number!");
    scanf("%d", &k);
    char passw[m];
    arq = fopen("data.txt", "w");
    while (n > 0) {
        p("Type you password!");
        scanf("%s", &passw);
        fprintf(arq, "%s\n", passw);
        n--;
    }
    fclose(arq);
    arq = fopen("data.txt", "r");
    codify(arq, k, n, m);
    fclose(arq);
}
