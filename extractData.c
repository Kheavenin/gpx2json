#include "extractData.h"

char author[] = "<author>";
char name[] = "<name>";
char end_name[] = "</name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";
char trackingPoints[] = "<trkpt";
char elevation[] = "<ele>";

static size_t getSpan(size_t size, char *start, char *end)
{
    if (size > 0 && start != NULL && end != NULL)
        return (size - strlen(start) - strlen(end));
    else
        return 0;
}

static char *getString(char *start, size_t size, size_t offset, size_t span)
{
    if (start != NULL && size != 0 && offset != 0 && span != 0)
    {
        char *author;
        author = malloc(size);
        strncpy(author, start + offset - 1, span);

        return author;
    }
    return NULL;
}

char *findAuthor(char *s, size_t size)
{
    char *begin = NULL, *end = NULL;
    begin = strstr(s, name);
    if (begin)
    {
        size_t span = getSpan(size, name, end_name);
        //printf("\n span: %lu\n", span);
        return getString(begin, size, sizeof(name), span);
    }
    return NULL;
}
