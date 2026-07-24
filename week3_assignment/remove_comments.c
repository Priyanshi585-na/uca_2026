#include <stdio.h>

void removeComments(FILE *in, FILE *out) {
    int c, next;

    enum {
        NORMAL,
        SINGLE_COMMENT,
        MULTI_COMMENT,
        STRING,
        CHARACTER
    } state = NORMAL;

    while ((c = fgetc(in)) != EOF) {

        switch (state) {

        case NORMAL:
            if (c == '/') {
                next = fgetc(in);

                if (next == '/')
                    state = SINGLE_COMMENT;
                else if (next == '*')
                    state = MULTI_COMMENT;
                else {
                    fputc(c, out);
                    if (next != EOF)
                        ungetc(next, in);
                }
            }
            else if (c == '"') {
                fputc(c, out);
                state = STRING;
            }
            else if (c == '\'') {
                fputc(c, out);
                state = CHARACTER;
            }
            else {
                fputc(c, out);
            }
            break;

        case SINGLE_COMMENT:
            if (c == '\n') {
                fputc('\n', out);
                state = NORMAL;
            }
            break;

        case MULTI_COMMENT:
            if (c == '*') {
                next = fgetc(in);
                if (next == '/')
                    state = NORMAL;
                else if (next != EOF)
                    ungetc(next, in);
            }
            break;

        case STRING:
            fputc(c, out);

            if (c == '\\') {
                c = fgetc(in);
                if (c != EOF)
                    fputc(c, out);
            }
            else if (c == '"') {
                state = NORMAL;
            }
            break;

        case CHARACTER:
            fputc(c, out);

            if (c == '\\') {
                c = fgetc(in);
                if (c != EOF)
                    fputc(c, out);
            }
            else if (c == '\'') {
                state = NORMAL;
            }
            break;
        }
    }
}

int main() {
    removeComments(stdin, stdout);
    return 0;
}
