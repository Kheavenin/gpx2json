#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 128
#define DEFAULT_DATA_SIZE 5
/** Structers definitons */
typedef struct {
  char *readLatitude;
  char *readLongitude;
  char *readElevation;
  char *readTime;
  char *readLine;
  char *readData[DEFAULT_DATA_SIZE];
  unsigned int readLinesCounter;
} gpxReadStruct;

gpxReadStruct *gpxReadInit(void);
void gpxReadDeinit(gpxReadStruct *psGpxRead);
void setGpxReadLine(gpxReadStruct *psGpxRead, char *s);
char *getGpxReadLine(gpxReadStruct *psGpxRead);

void setReadLatitudec(gpxReadStruct *psGpxRead, char *s);
void setReadLongitude(gpxReadStruct *psGpxRead, char *s);
void setReadElevation(gpxReadStruct *psGpxRead, char *s);
void setReadTime(gpxReadStruct *psGpxRead, char *s);

char *getReadLatitude(gpxReadStruct *psGpxRead);
char *getReadLongitude(gpxReadStruct *psGpxRead);
char *getReadElevation(gpxReadStruct *psGpxRead);
char *getReadTime(gpxReadStruct *psGpxRead);