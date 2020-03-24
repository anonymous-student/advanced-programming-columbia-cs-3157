#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "duper_upper.h"

DuperUpper::DuperUpper(int argc, char **argv) 
{
    // set current index to 1, where the first arg is
    idx = 1;

    // remember the end of the argv array, where NULL is
    end = argc;

    // The rest of this function is basically the old duplicateArgs().
    // Note that we chose to duplicate the original args too here.
    // We didn't have to.  We could have just held the original argv,
    // in which case of course you shouldn't free it in the destructor.

    normal = (char **)malloc((argc + 1) * sizeof(char *));
    upper  = (char **)malloc((argc + 1) * sizeof(char *));
    if (normal == NULL || upper == NULL) {
        perror("malloc failed");
        exit(1);
    }

    for (int i = 0; i < argc; i++) {

        // allocate space for each string
        normal[i] = new char[strlen(argv[i]) + 1];
        upper[i]  = new char[strlen(argv[i]) + 1];

        // make exact copies of argv in the normal array
        strcpy(normal[i], argv[i]);

        // strcpy(), but capitalize every char in upper
        char *t = upper[i];
        char *s = argv[i];
        while ((*t++ = toupper(*s++)) != 0)
            ;
    }

    // don't forget to put NULL at the end of the overall arrays
    normal[argc] = upper[argc] = NULL;
}

DuperUpper::~DuperUpper() 
{
    char **p = normal;
    char **p2 = upper;

    // free all the strings
    while (*p) {
        delete [] *p++;
        delete [] *p2++;
    }

    // free the overall arrays
    free(normal);
    free(upper);
}
