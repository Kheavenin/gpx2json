#include "gpxStruct.h"

static int realseGpxReadField(char *s) {
  if (s != NULL) {
    free(s);
    return true;
  }
  return false;
}

gpxReadStruct *gpxReadInit(void) {
  gpxReadStruct *psGpxRead = NULL;
  psGpxRead = malloc(sizeof(gpxReadStruct));

  if (psGpxRead == NULL) {
    // stderr log
    return NULL;
  }
  psGpxRead->readLine = malloc(sizeof(char) * DEFAULT_SIZE);
  if (psGpxRead->readLine == NULL) {
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->readLinesCounter = 0;
  return psGpxRead;
}

void gpxReadDeinit(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    realseGpxReadField(psGpxRead->readLine);
    psGpxRead->readLinesCounter = 0;
    free(psGpxRead);
  }
}
