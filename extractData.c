#include "extractData.h"

#define LOGS 0
#define SPAN_LOGS LOGS

const char *author = "<author>";
const char *name = "<name>";
const char *time = "<time>";
const char *source = "<scr>";
const char *type = "<type>";

const char *trackingPoints = "<trkpt ";
const char *lat = "lat=\"";
const char *lon = "lon=\"";
const char *elevation = "<ele>";

const char *end_trackingPoints = ">";
const char *end_lat = "\"";
const char *end_lon = "\"";
const char *end_elevation = "</ele>";

const char *end_name = "</name>";
const char *end_time = "</time>";
const char *end_type = "</type>";

char *getString(const char *s, const char *start, const char *end) {
  if (s != NULL && start != NULL && end != NULL) {
    char *begin = strstr(s, start);
    char *ended = strstr(begin, end);

    if (begin != NULL && ended != NULL) {
      //   printf("\nBegin of tracking section:%s\nEnd of tracking section:%s",
      //   begin, ended); printf("\nBegin length: %lu, End length: %lu",
      //   strlen(begin),strlen(ended));
      unsigned int span =
          strlen(s) - strlen(start) - strlen(end); //- strlen(start) +1;

      char *str = malloc(sizeof(char) * span);
      if (str != NULL) {
        memset(str, 0, strlen(str));
        //  printf("\nPointer before copy: %p\nIts size: %lu", str,strlen(str));
        strncpy(str, begin + strlen(start), span);
        str[span] = '\0';
        //  printf("\nPointer after copy : %s\nIts size: %lu", str,strlen(str));
        return str;
      } else {
        return NULL;
      }
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

char *getLatitude(const char *s) {
  if (s != NULL) {
    char *begin = strstr(s, lat);
    char *ended = strstr(strlen(lat) + begin, end_lat);

    if (begin != NULL && ended != NULL) {
      unsigned int span = ended - begin - strlen(lat); //- strlen(start) +1;
      //  printf("\nlatitude span: %u", span);

      char *latitude = malloc(sizeof(char) * span);
      if (latitude != NULL) {
        strncpy(latitude, begin + strlen(lat), span);
        latitude[span] = '\0';
        //  printf("\nPointer after copy : %s\nLat size: %lu",
        //  latitude,strlen(latitude));
        return latitude;
      } else {
        return NULL;
      }

    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

char *getLongitude(const char *s) {
  if (s != NULL) {
    char *begin = strstr(s, lon);
    char *ended = strstr(strlen(lon) + begin, end_lon);

    if (begin != NULL && ended != NULL) {
      unsigned int span = ended - begin - strlen(lon); //- strlen(start) +1;
      // printf("\nlongitude span: %u", span);

      char *longitude = malloc(sizeof(char) * span);
      if (longitude != NULL) {
        strncpy(longitude, begin + strlen(lon), span);
        longitude[span] = '\0';
        //  printf("\nPointer after copy : %s\nLon size: %lu",
        //  longitude,strlen(longitude));
        return longitude;
      } else {
        return NULL;
      }
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

char *getAuthor(char *s, size_t size) {
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

char *getTime(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, time);
  if (begin) {
    char *tmp = getString(s, time, end_time);
    return tmp;
  }
  return NULL;
}

char *getActivity(char *s, size_t size) {
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

char *getTrackPoint(char *s, size_t size) {
  if (s == NULL || size < 1)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, trackingPoints);

  if (begin) {
    return getString(s, trackingPoints, end_trackingPoints);
  }
  return NULL;
}

char *getElevation(char *s) {
  if (s == NULL)
    return NULL;

  char *begin = NULL;
  begin = strstr(s, elevation);
  if (begin) {
    return getString(s, elevation, end_elevation);
  }
  return NULL;
}