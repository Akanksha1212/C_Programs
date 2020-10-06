#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p printf
void codify(FILE* arq, int k, int n, int m)
{
    char senha[m];
    int count;
    FILE* arq_2;
    arq_2 = fopen("data.hash", "w");
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
    p("Digite o número de caracteres das senhas!");
    scanf("%d", &m);
    p("Digite o número de senhas!");
    scanf("%d", &n);
    p("Digite o número de criptografia!");
    scanf("%d", &k);
    char senha[m];
    arq = fopen("data.sql", "w");
    while (n > 0) {
        p("Digite a senha!");
        scanf("%s", &senha);
        fprintf(arq, "%s\n", senha);
        n--;
    }
    fclose(arq);
    arq = fopen("data.sql", "r");
    codify(arq, k, n, m);
    fclose(arq);
}
