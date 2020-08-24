#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getString(const char *s, const char *start, const char *end);
char *getLatitude(const char *s);
char *getLongitude(const char *s);

char *getAuthor(char *s, size_t size);
char *getTime(char *s, size_t size);
char *getActivity(char *s, size_t size);
char *getTrackPoint(char *s, size_t size);
