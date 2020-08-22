#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getString(const char *s, const char *start, const char *end);
char *getLatitude(const char *s);
char *getLongitude(const char *s);

char *findAuthor(char *s, size_t size);
char *findTime(char *s, size_t size);
char *findActivity(char *s, size_t size);
char *findTrackPoints(char *s, size_t size);

char *extractLatitude(char *s, size_t size);
char *extractLongitude(char *s, size_t size);
