#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 64
#define DEFAULT_SIZE_SHORT 16

/** Structers definitons */
typedef struct {

} gpxParamtersStruct;

typedef struct {
  char *gpxEncoding;
  char *gpxVer;
  char *gpxSource;
  char *gpxActivityType;

  char *gpxLatitude;
  char *gpxLongitude;
  char *gpxElevation;
  char *gpxData;
  char *gpxTime;
  unsigned int readLines;
} gpxReadStruct;

gpxReadStruct *gpxReadInit(void);
void gpxReadDeinit(gpxReadStruct *psGpxRead);
void setGpxData(gpxReadStruct *psGpxRead, char *data);
char *getGpxData(gpxReadStruct *psGpxRead);
void setGpxTime(gpxReadStruct *psGpxRead, char *time);
char *getGpxTime(gpxReadStruct *psGpxRead);
void setGpxLatitude(gpxReadStruct *psGpxRead, char *lat);
char *getGpxLatitude(gpxReadStruct *psGpxRead);