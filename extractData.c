#include "extractData.h"

char author[] = "<author>";
char name[] = "<name>";
char end_name[] = "</name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";
char trackingPoints[] = "<trkpt";
char elevation[] = "<ele>";

char *findAuthor(char *s, size_t size)
{
    char *begin = NULL, *end = NULL;
    begin = strstr(s, name);
    if (begin)
    {
        end = strstr(s, end_name);
        size_t span = strlen(s) - strlen(name) - strlen(end_name);
        //   printf("\n span: %lu\n", span);
        if (end)
        {
            char *author;
            author = malloc(size);
            strncpy(author, begin + sizeof(name) - 1, span);
            //    printf("Author: %s", author);
            return author;
        }
        return NULL;
    }
    return NULL;
}
