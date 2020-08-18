#include "extractData.h"

char author[] = "<author>";
char name[] = "<name>";
char end_name[] = "</name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";
char trackingPoints[] = "<trkpt";
char elevation[] = "<ele>";

static size_t getSpan(char *s, char *start, char *end)
{
    return (strlen(s) - strlen(start) - strlen(end));
}

static char *getString(char *start, size_t size, size_t span, char *m)
{
    char *author;
    author = malloc(size);
    strncpy(author, start + sizeof(m) - 1, span);

    return author;
}

char *findAuthor(char *s, size_t size)
{
    char *begin = NULL, *end = NULL;
    begin = strstr(s, name);
    if (begin)
    {
        end = strstr(s, end_name);
        if (end)
        {
            size_t span = getSpan(s, name, end_name);
            return getString(s, size, span, name);
            //  strncpy(author, begin + sizeof(name) - 1, span);
            //    printf("Author: %s", author);
            //   printf("\n span: %lu\n", span);
        }
        return NULL;
    }
    return NULL;
}
