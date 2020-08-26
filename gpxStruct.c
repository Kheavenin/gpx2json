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

void setReadLatitudec(gpxReadStruct *psGpxRead, char *s) {
  if (psGpxRead != NULL && s != NULL) {
    size_t len = strlen(s);
    if (len > 0) {
      char *t = psGpxRead->readLatitude;
      psGpxRead->readLatitude = NULL;
      psGpxRead->readLatitude = realloc(t, (len + 1) * sizeof(char));
      if (psGpxRead->readLatitude) {
        strcpy(psGpxRead->readLatitude, s);
      }
    }
  }
}

void setReadLongitude(gpxReadStruct *psGpxRead, char *s) {
  if (psGpxRead != NULL && s != NULL) {
    size_t len = strlen(s);
    if (len > 0) {
      char *t = psGpxRead->readLongitude;
      psGpxRead->readLongitude = NULL;
      psGpxRead->readLongitude = realloc(t, (len + 1) * sizeof(char));
      if (psGpxRead->readLongitude) {
        strcpy(psGpxRead->readLongitude, s);
      }
    }
  }
}

void setReadElevation(gpxReadStruct *psGpxRead, char *s) {
  if (psGpxRead != NULL && s != NULL) {
    size_t len = strlen(s);
    if (len > 0) {
      char *t = psGpxRead->readElevation;
      psGpxRead->readElevation = NULL;
      psGpxRead->readElevation = realloc(t, (len + 1) * sizeof(char));
      if (psGpxRead->readElevation) {
        strcpy(psGpxRead->readElevation, s);
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

char *getReadLatitude(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL && (psGpxRead->readLatitude != NULL)) {

    return psGpxRead->readLatitude;
  }
  return NULL;
}

char *getReadLongitude(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL && (psGpxRead->readLongitude != NULL)) {

    return psGpxRead->readLongitude;
  }
  return NULL;
}

char *getReadElevation(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL && (psGpxRead->readElevation != NULL)) {

    return psGpxRead->readElevation;
  }
  return NULL;
}
