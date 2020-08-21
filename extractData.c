#include "extractData.h"

#define LOGS 1
#define SPAN_LOGS LOGS

char author[] = "<author>";
char name[] = "<name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";

const char trackingPoints[] = "<trkpt";
const char *lat = "lat=\"";
const char *lon = "lon=\"";
const char *elevation = "<ele>";

const char *end_trackingPoints = "\">";
const char *end_lat = "\"";
const char *end_lon = "\"";

char end_name[] = "</name>";
char end_time[] = "</time>";
char end_type[] = "</type>";

static char *getString(char *start, size_t size, size_t offset, size_t span) {
  if (start != NULL && size != 0 && offset != 0 && span != 0) {
    char *author;
    author = malloc(size);
    strncpy(author, start + offset - 1, span);

    return author;
  }
  return NULL;
}

static unsigned int getSpan(const char *s, const char *start, const char *end) {
  if (s != NULL && start != NULL && end != NULL) {
    char *b = strstr(s, start);
    char *e = strstr(b + strlen(start), end);
#if SPAN_LOGS
    printf("\ninside getSpan addr: %p", (void *)b);
    printf("\ninside getSpan addr: %p", (void *)e);
    printf("\ninside getSpan b: %s", b);
    printf("\ninside getSpan e: %s", e);

#endif
    if (b != NULL && e != NULL) {
      size_t t = (sizeof(e));
      unsigned int span = ((e - b) - t);
#if SPAN_LOGS
      printf("Size of end: %u", t);
      printf("\n ----- Inside getSpan span: %u", span);
#endif
      return span;
    }
    return 0;
  }
  return 0;
}

char *getStringFrom(const char *s, const char *start, const char *end) {
  unsigned int span = getSpan(s, start, end);
  char *begin = strstr(s, start);
//  char *the_end = strstr(begin + strlen(start), end);
#if LOGS
  printf("\nInside getString ----- :Begin: %s", begin);
  printf("\nInside getString ----- :End: %s\nSpan: %u", end, span);
#endif
  char *str = malloc((span - strlen(start)) * sizeof(char));
  strncpy(str, begin + strlen(start), span - strlen(start));
#if LOGS
  printf("\nInside getString -----: %s",
         strncpy(str, begin + strlen(start), span - strlen(start)));
  printf("\nInside getString -----: %s: ", str);
#endif
  return str;
}

char *findAuthor(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, name);
  if (begin) {
    /*
    size_t span = getSpan(s, name, end_name);
    //printf("\n span: %lu\n", span);
    return getString(begin, size, sizeof(name), span);
    */
    return getStringFrom(s, name, end_name);
  }
  return NULL;
}

char *findTime(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, time);
  if (begin) { /*
                 size_t span = getSpan(s, time, end_time);
                 return getString(begin, size, sizeof(time), span);*/
    return getStringFrom(s, time, end_time);
  }
  return NULL;
}

char *findActivity(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, type);
  if (begin) { /*
                 size_t span = getSpan(s, type, end_type);
                 return getString(begin, size, sizeof(type), span);*/
    return getStringFrom(s, type, end_type);
  }

  return NULL;
}

char *findTrackPoints(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, trackingPoints);

  if (begin) {
    /*
    size_t span = getSpan(s, trackingPoints, end_trackingPoints);
    return getString(begin, size, sizeof(trackingPoints), span);
    */
    return getStringFrom(s, trackingPoints, end_trackingPoints);
  }

  return NULL;
}

char *extractLatitude(char *s, size_t size) {
  char *begin = NULL;
  begin = strstr(s, lat);
  if (begin) {
    /*  size_t span = getSpan(s, lat, end_lat);
    printf("\nspan: %lu", span);*/
    char *lattitude = getStringFrom(s, lat, end_lat);
    //            printf("\nExt string: %s", tmpChar);
    return lattitude;
  }

  return NULL;
}

char *extractLongitude(char *s, size_t size) {
  char *begin = NULL;
  begin = strstr(s, lon);
  if (begin) {
    char *longitude = getStringFrom(s, lon, end_lon);
    return longitude;
  }

  return NULL;
}