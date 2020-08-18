#include "extractData.h"

char author[] = "<author>";
char name[] = "<name>";
char end_name[] = "</name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";
char trackingPoints[] = "<trkpt";
char elevation[] = "<ele>";

int findAuthor(char *s, size_t size)
{
    char *author;
    author = malloc(size);
    if (author)
    {
        char *begin = NULL, *end = NULL;
        begin = strstr(s, name);
        if (begin)
        {
            end = strstr(s, end_name);
            size_t span = strlen(s) - strlen(name) - strlen(end_name);
            printf("\n span: %lu\n", span);
            if (end)
            {
                strncpy(author, begin + sizeof(name) - 1, span);
                printf("Author: %s", author);
            }
        }
        free(author);
        return 1;
    }
    free(author);
    return 0;
}
