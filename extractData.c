#include "extractData.h"

#define LOGS 0
#define SPAN_LOGS LOGS

char author[] = "<author>";
const char *name = "<name>";
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

const char *end_name = "</name>";
char end_time[] = "</time>";
char end_type[] = "</type>";

unsigned int getSpan(const char *s, const char *start, const char *end) {
  if (s != NULL && start != NULL && end != NULL) {
    char *b = strstr(s, start);
    char *e = strstr(b + strlen(start), end);
#if SPAN_LOGS
    printf("\ninside getSpan addr: %p", (void *)b);
    printf("\ninside getSpan addr: %p", (void *)e);
    //    printf("\ninside getSpan b: %s", b);
    //    printf("\ninside getSpan e: %s", e);

#endif
    if (b != NULL && e != NULL) {
      unsigned int span = ((e - b) - (strlen(e) - 1));
#if SPAN_LOGS
      printf("\nInside getSpan span: %u", span);
#endif
      return span;
    }
    return 0;
  }
  return 0;
}

char *getStringFrom(const char *s, const char *start, const char *end) {
  unsigned int span = getSpan(s, start, end);
  if (span > 127) {
    return NULL;
  }
  char *begin = strstr(s, start);
//  char *the_end = strstr(begin + strlen(start), end);
#if LOGS
  printf("\nInside getString Begin: %s", begin);
  printf("\nInside getString End: %s\nSpan: %u", end, span);
#endif
  char *str = malloc((span + 1) * sizeof(char));
  strncpy_s(str, ((span + 1) * sizeof(char)), begin + strlen(start), span);
#if LOGS
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