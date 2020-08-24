#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 128
/** Structers definitons */
typedef struct {
  char *readLine;
  unsigned int readLinesCounter;
} gpxReadStruct;

gpxReadStruct *gpxReadInit(void);
void gpxReadDeinit(gpxReadStruct *psGpxRead);