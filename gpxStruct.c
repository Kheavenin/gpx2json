#include "gpxStruct.h"

gpxReadStruct *gpxReadInit(void) {
  gpxReadStruct *psGpxRead = NULL;
  psGpxRead = malloc(sizeof(gpxReadStruct));

  if (psGpxRead == NULL) {
    // stderr log
    return NULL;
  }

  /* memory allocate */
  psGpxRead->readData[0] = psGpxRead->readLine =
      malloc(sizeof(char) * DEFAULT_SIZE);
  psGpxRead->readData[1] = psGpxRead->readLatitude =
      malloc(sizeof(char) * DEFAULT_SIZE);
  psGpxRead->readData[2] = psGpxRead->readLongitude =
      malloc(sizeof(char) * DEFAULT_SIZE);
  psGpxRead->readData[3] = psGpxRead->readElevation =
      malloc(sizeof(char) * DEFAULT_SIZE);

  unsigned int i;
  bool nullFlag = false;
  for (i = 0; i < DEFAULT_DATA_SIZE; i++) {
    bool nullFlag = false;
    if (psGpxRead->readData[i] == NULL) {
      nullFlag = true;
    }
  }
  if (nullFlag) {
    for (i = 0; i < DEFAULT_DATA_SIZE - 1; i++) {
      free(psGpxRead->readData[i]);
    }
    free(psGpxRead);
  }

  psGpxRead->readLinesCounter = 0;
  return psGpxRead;
}

void gpxReadDeinit(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    unsigned int i;
    for (i = 0; i < DEFAULT_DATA_SIZE - 1; i++) {
      free(psGpxRead->readData[i]);
    }
    free(psGpxRead);
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
