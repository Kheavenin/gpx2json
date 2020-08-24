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
  psGpxRead->gpxTime = malloc(sizeof(char) * DEAFULT_SIZE);
  if (psGpxRead->gpxTime == NULL) {
    // stderr logs
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxData = malloc(sizeof(char) * DEAFULT_SIZE);
  if (psGpxRead->gpxData == NULL) {
    // stderr logs
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxElevation = malloc(sizeof(char) * DEAFULT_SIZE_SHORT);
  if (psGpxRead->gpxElevation == NULL) {
    // stderr logs
    free(psGpxRead->gpxData);
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxLatitude = malloc(sizeof(char) * DEAFULT_SIZE_SHORT);
  if (psGpxRead->gpxLatitude == NULL) {
    // stderr logs
    free(psGpxRead->gpxElevation);
    free(psGpxRead->gpxData);
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxLongitude = malloc(sizeof(char) * DEAFULT_SIZE_SHORT);
  if (psGpxRead->gpxLongitude == NULL) {
    // stderr logs
    free(psGpxRead->gpxLatitude);
    free(psGpxRead->gpxElevation);
    free(psGpxRead->gpxData);
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  return psGpxRead;
}

void gpxReadDeinit(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    realseGpxReadField(psGpxRead->gpxData);
    realseGpxReadField(psGpxRead->gpxTime);
    realseGpxReadField(psGpxRead->gpxElevation);
    realseGpxReadField(psGpxRead->gpxLatitude);
    realseGpxReadField(psGpxRead->gpxLongitude);
  }
}

void setGpxData(gpxReadStruct *psGpxRead, char *s) {
  if (psGpxRead != NULL && s != NULL) {
    size_t len = strlen(s);
    if (len > 0) {
      psGpxRead->gpxData = realloc(psGpxRead->gpxData, len * sizeof(char));
      strcpy(psGpxRead->gpxData, s);
    }
  }
}

char *getGpxData(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    if (psGpxRead->gpxData != NULL) {
      // printf("%s", psGpxRead->gpxData);
      return (psGpxRead->gpxData);
    }
    return NULL;
  }
  return NULL;
}