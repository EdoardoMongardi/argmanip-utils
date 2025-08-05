#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "argmanip.h"

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int)) {
    char **result = malloc((argc + 1) * sizeof(char *)); 
    if (!result) return NULL;

    for (int i = 0; i < argc; ++i) {
        result[i] = malloc((strlen(argv[i]) + 1) * sizeof(char));
        if (!result[i]) {
            for (int j = 0; j < i; ++j) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }

        for (int j = 0; argv[i][j] != '\0'; ++j) {
            result[i][j] = manip(argv[i][j]);
        }
        result[i][strlen(argv[i])] = '\0';
    }

    result[argc] = NULL;
    return result;
}

void free_copied_args(char **args, ...) {
    va_list ap;
    va_start(ap, args);

    while (args) {
        for (int i = 0; args[i] != NULL; ++i) {
            free(args[i]);
        }
        free(args);

        args = va_arg(ap, char **);
    }

    va_end(ap);
}