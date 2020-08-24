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

  psGpxRead->gpxEncoding = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
  psGpxRead->gpxVer = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
  psGpxRead->gpxSource = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
  psGpxRead->gpxActivityType = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);

  psGpxRead->gpxTime = malloc(sizeof(char) * DEFAULT_SIZE);
  if (psGpxRead->gpxTime == NULL) {
    // stderr logs
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxData = malloc(sizeof(char) * DEFAULT_SIZE);
  if (psGpxRead->gpxData == NULL) {
    // stderr logs
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxElevation = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
  if (psGpxRead->gpxElevation == NULL) {
    // stderr logs
    free(psGpxRead->gpxData);
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxLatitude = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
  if (psGpxRead->gpxLatitude == NULL) {
    // stderr logs
    free(psGpxRead->gpxElevation);
    free(psGpxRead->gpxData);
    free(psGpxRead->gpxTime);
    free(psGpxRead);
    return NULL;
  }

  psGpxRead->gpxLongitude = malloc(sizeof(char) * DEFAULT_SIZE_SHORT);
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

    realseGpxReadField(psGpxRead->gpxLatitude);
    realseGpxReadField(psGpxRead->gpxLongitude);
    realseGpxReadField(psGpxRead->gpxElevation);
    realseGpxReadField(psGpxRead->gpxData);
    realseGpxReadField(psGpxRead->gpxTime);
    psGpxRead->readLines = 0;
  }
}

void setGpxData(gpxReadStruct *psGpxRead, char *data) {
  if (psGpxRead != NULL && data != NULL) {
    size_t len = strlen(data);
    if (len > 0) {
      psGpxRead->gpxData = realloc(psGpxRead->gpxData, len * sizeof(char));
      strcpy(psGpxRead->gpxData, data);
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

void setGpxTime(gpxReadStruct *psGpxRead, char *time) {
  if (psGpxRead != NULL && time != NULL) {
    size_t len = strlen(time);
    if (len > 0) {
      psGpxRead->gpxTime = realloc(psGpxRead->gpxTime, len * sizeof(char));
      strcpy(psGpxRead->gpxTime, time);
    }
  }
}

char *getGpxTime(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    if (psGpxRead->gpxTime != NULL) {
      // printf("%s", psGpxRead->gpxData);
      return (psGpxRead->gpxTime);
    }
    return NULL;
  }
  return NULL;
}

void setGpxLatitude(gpxReadStruct *psGpxRead, char *lat) {
  if (psGpxRead != NULL && lat != NULL) {
    size_t len = strlen(lat);
    if (len > 0) {
      psGpxRead->gpxLatitude =
          realloc(psGpxRead->gpxLatitude, len * sizeof(char));
      strcpy(psGpxRead->gpxLatitude, lat);
    }
  }
}

char *getGpxLatitude(gpxReadStruct *psGpxRead) {
  if (psGpxRead != NULL) {
    if (psGpxRead->gpxLatitude != NULL) {
      // printf("%s", psGpxRead->gpxData);
      return (psGpxRead->gpxLatitude);
    }
    return NULL;
  }
  return NULL;
}