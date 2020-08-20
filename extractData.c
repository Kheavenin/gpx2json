#include "extractData.h"

char author[] = "<author>";
char name[] = "<name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";

char trackingPoints[] = "<trkpt";
const char *lat = "lat=\"";
const char *lon = "lon=\"";
char *elevation = "<ele>";

char *end_trackingPoints = "\">";
const char *end_lat = "\"";
const char *end_lon = "\"";

char end_name[] = "</name>";
char end_time[] = "</time>";
char end_type[] = "</type>";

/*
static size_t getSpan(size_t size, char *start, char *end)
{
    if (size > 0 && start != NULL && end != NULL)
        return (size - strlen(start) - strlen(end));
    else
        return 0;
}
*/

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

static unsigned int getSpan(const char *s, const char *start, const char *end)
{
    if (s != NULL && start != NULL && end != NULL)
    {
        char *b = strstr(s, start);
        char *e = strstr(b + strlen(start), end);
        //        printf("\ninside getSpan b: %s",b);
        //        printf("\ninside getSpan e: %s",e);
        if (b && e)
        {
            unsigned int span = (e - b);
            //    printf("\n ----- Inside getSpan span: %u", span);
            return span;
        }
        return 0;
    }
    return 0;
}

char *getStringFrom(const char *s, const char *start, const char *end)
{
    unsigned int span = getSpan(s, start, end);
    char *begin = strstr(s, start);
    char *the_end = strstr(begin + strlen(start), end);
    //    printf("\nInside getStrin ----- :Begin: %s", begin);
    //    printf("\nInside getStrin ----- :End: %s\nSpan: %u", end, span);

    char *str = malloc((span - strlen(start)) * sizeof(char));
    strncpy(str, begin + strlen(start), span - strlen(start));
    //    printf("\nInside getStrin -----%s", strncpy(str, begin + strlen(start), span - strlen(start)));
    //    printf("\nInside getStrin ----- st:%s", str);
    return str;
}

char *findAuthor(char *s, size_t size)
{
    if (s == NULL || size < 1)
        return NULL;

    char *begin = NULL;
    begin = strstr(s, name);
    if (begin)
    {
        /*
        size_t span = getSpan(s, name, end_name);
        //printf("\n span: %lu\n", span);
        return getString(begin, size, sizeof(name), span);
        */
        return getStringFrom(s, name, end_name);
    }
    return NULL;
}

char *findTime(char *s, size_t size)
{
    if (s == NULL || size < 1)
        return NULL;

    char *begin = NULL;
    begin = strstr(s, time);
    if (begin)
    { /*
        size_t span = getSpan(s, time, end_time);
        return getString(begin, size, sizeof(time), span);*/
        return getStringFrom(s, time, end_time);
    }
    return NULL;
}

char *findActivity(char *s, size_t size)
{
    if (s == NULL || size < 1)
        return NULL;

    char *begin = NULL;
    begin = strstr(s, type);
    if (begin)
    { /*
        size_t span = getSpan(s, type, end_type);
        return getString(begin, size, sizeof(type), span);*/
        return getStringFrom(s, type, end_type);
    }

    return NULL;
}

char *findTrackPoints(char *s, size_t size)
{
    char *begin = NULL;
    begin = strstr(s, trackingPoints);

    if (begin)
    {
        /*
        size_t span = getSpan(s, trackingPoints, end_trackingPoints);
        return getString(begin, size, sizeof(trackingPoints), span);
        */
        return getStringFrom(s, trackingPoints, end_trackingPoints);
    }

    return NULL;
}

char *extractLatitude(char *s, size_t size)
{
    char *begin = NULL;
    begin = strstr(s, lat);
    if (begin)
    {
        /*  size_t span = getSpan(s, lat, end_lat);
        printf("\nspan: %lu", span);*/
        char *tmpChar = getStringFrom(s, lat, end_lat);
        //            printf("\nExt string: %s", tmpChar);
        return tmpChar;
    }

    return NULL;
}
