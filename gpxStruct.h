#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEAFULT_SIZE 64
#define DEAFULT_SIZE_SHORT 16

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