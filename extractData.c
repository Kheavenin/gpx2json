#include "extractData.h"

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
            size_t span = strspn(begin, end);
            if (end)
            {
                strncpy(author, begin, span);
            }
        }

        free(author);
        return 1;
    }
    free(author);
    return 0;
}