#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getString(const char *s, const char *start, const char *end);
char *getLatitude(const char *s);
char *getLongitude(const char *s);

char *getAuthor(char *s);
char *getTime(char *s);
char *getActivity(char *s);
char *getTrackPoint(char *s);

char *getElevation(char *s);
