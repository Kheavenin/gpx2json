#include "extractData.h"

#define LOGS 0
#define SPAN_LOGS LOGS

char author[] = "<author>";
const char *name = "<name>";
char time[] = "<time>";
char source[] = "<scr>";
char type[] = "<type>";

const char *trackingPoints = "<trkpt ";
const char *lat = "lat=\"";
const char *lon = "lon=\"";
const char *elevation = "<ele>";

const char *end_trackingPoints = ">";
const char *end_lat = "\"";
const char *end_lon = "\"";

const char *end_name = "</name>";
char end_time[] = "</time>";
char end_type[] = "</type>";

char *getString(const char *s, const char *start, const char *end) {
  if (s != NULL && start != NULL && end != NULL) {
    char *begin = strstr(s, start);
    char *ended = strstr(begin, end);

    if (begin != NULL && ended != NULL) {
      printf("\nBegin of tracking section:%s\nEnd of tracking section:%s",
             begin, ended);
      printf("\nBegin length: %lu, End length: %lu", strlen(begin),
             strlen(ended));
      unsigned int span =
          strlen(s) - strlen(start) - strlen(end); //- strlen(start) +1;

      char *trkp = malloc(sizeof(char) * span);
      memset(trkp, 0, strlen(trkp));
      printf("\nPointer before copy: %p\nIts size: %lu", trkp, strlen(trkp));
      strncpy(trkp, begin + strlen(start), span);
      printf("\nPointer after copy : %s\nIts size: %lu", trkp, strlen(trkp));
      return trkp;
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
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
    return getString(s, name, end_name);
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
    return getString(s, time, end_time);
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
    return getString(s, type, end_type);
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
    return getString(s, trackingPoints, end_trackingPoints);
  }

  return NULL;
}

char *extractLatitude(char *s, size_t size) {
  char *begin = NULL;
  begin = strstr(s, lat);
  if (begin != NULL) {
    char *latitude = getString(s, lat, end_lat);
    return latitude;
  }

  return NULL;
}

char *extractLongitude(char *s, size_t size) {
  char *begin = NULL;
  begin = strstr(s, lon);
  if (begin != NULL) {
    char *longitude = getString(s, lon, end_lon);
    return longitude;
  }

  return NULL;
}