#include "gpxStruct.h"

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