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
  psGpxRead->readTime = malloc(sizeof(char) * DEFAULT_SIZE);
  if (psGpxRead->readTime == NULL) {
    free(psGpxRead->readLine);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->readLinesCounter = 0;
  return psGpxRead;
}

void gpxReadDeinit(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    realseGpxReadField(psGpxRead->readTime);
    realseGpxReadField(psGpxRead->readLine);
    psGpxRead->readLinesCounter = 0;
    free(psGpxRead);
  }
}

void setGpxReadLine(gpxReadStruct *psGpxRead, char *s) {
  if (psGpxRead != NULL && s != NULL) {
    size_t len = strlen(s);
    if (len > 0) {
      char *t = psGpxRead->readLine;
      psGpxRead->readLine = NULL;
      psGpxRead->readLine = realloc(t, (len + 1) * sizeof(char));
      if (psGpxRead->readLine) {
        strcpy(psGpxRead->readLine, s);
      }
    }
  }
}

char *getGpxReadLine(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL && (psGpxRead->readLine != NULL)) {

    return psGpxRead->readLine;
  }
  return NULL;
}