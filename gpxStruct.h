#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEAFULT_SIZE 64

/** Structers definitons */
typedef struct {
  char *gpxEncoding;
  char *gpxVer;
  char *gpxSource;
  char *gpxActivityType;
  unsigned int readLines;
} gpxParamtersStruct;

typedef struct {
  char *gpxLatitude;
  char *gpxLongitude;
  char *gpxElevation;
  char *gpxData;
  char *gpxTime;
} gpxReadStruct;

gpxReadStruct *gpxReadInit(void);