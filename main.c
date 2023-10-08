#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nato.h"

#define EUSAGE 1
#define EDIRECTION 2

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: %s <--to | --from> <text>\n", argv[0]);
        exit(EUSAGE);
    }

    if (strcmp(argv[1], "--to") == 0)
    {
        to_nato(&argv[2], argc - 2);
    }
    else if (strcmp(argv[1], "--from") == 0)
    {
        from_nato(&argv[2], argc - 2);
    }
    else 
    {
        fprintf(stderr, "error: \"%s\" is not a valid translation direction. Use \"--to\" or \"--from\" <TEXT>\n", argv[1]);
        exit(EDIRECTION);
    }
    

    return 0;
}
