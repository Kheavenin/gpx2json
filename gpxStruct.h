#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 128
#define DEFAULT_DATA_SIZE 4
/** Structers definitons */
typedef struct {
  char *readLatitude;
  char *readLongitude;
  char *readElevation;
  char *readLine;
  char *readData[DEFAULT_DATA_SIZE];
  unsigned int readLinesCounter;
} gpxReadStruct;

gpxReadStruct *gpxReadInit(void);
void gpxReadDeinit(gpxReadStruct *psGpxRead);
void setGpxReadLine(gpxReadStruct *psGpxRead, char *s);
char *getGpxReadLine(gpxReadStruct *psGpxRead);