#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extractData.h"
#include "gpxStruct.h"

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16
#define GPX_MARKERS_SIZE 8

#define CORRECT_EXECUTE 1
#define ERROR_DATA 0
#define ERROR_MEMORY 0       // code for memory allocation
#define ERROR_NULL_POINTER 0 // code for null pointer detection

char line[128];

/** Function prototypes */
int valiateMemoryPointer(void *pointer);
int valiateFilePointer(FILE *pointer);

int main(int argc, char const *argv[]) {

  if ((argv == NULL) || (argc != 3)) {
    fprintf(stderr, "\nInvalid program arguments.\n");
    return ERROR_DATA;
  }

  /* Create structures and pointers to thier */
  /* Allocation memmory for structures */
  /* Check memory allocations */
  gpxReadStruct *psGpxRead = NULL;
  psGpxRead = gpxReadInit();
  if (!(valiateMemoryPointer((void *)psGpxRead))) {
    fprintf(stderr, "ERROR_NULL_POINTER: psGpxRead\n");
    return ERROR_NULL_POINTER;
  }

  FILE *inputFile = NULL;
  FILE *outputFile = NULL;
  inputFile = fopen(
      argv[1], "r"); // first argument - gpx file to read gps position and time
  outputFile = fopen(argv[2], "w");

  if (!valiateFilePointer(inputFile)) {
    fprintf(stderr, "\nCannot open input file");
  }

  if (!valiateFilePointer(outputFile)) {
    fprintf(stderr, "\nCannot create output file.");
  }
  /* Start write to file */
  fprintf(outputFile, "{\n\"Metadata\": {\n");
  /** Read file */
  while (fscanf(inputFile, "%127[^\n]\n", line) == 1) {
    setGpxReadLine(psGpxRead, line);
    if ((psGpxRead->readLinesCounter) < 21) {
      char *pAuthor = getAuthor(psGpxRead->readLine);
      if (pAuthor != NULL) {
        fprintf(outputFile, "\t\"Author\": \"%s\",\n", pAuthor);
      }
      free(pAuthor);

      char *pTime = getTime(psGpxRead->readLine);
      if (pTime != NULL) {
        fprintf(outputFile, "\t\"StartTime\": \"%s\",\n", pTime);
      }
      free(pTime);

      char *pType = getActivity(psGpxRead->readLine);
      if (pType != NULL) {
        fprintf(outputFile, "\t\"ActivityType\": \"%s\"\n", pType);
        fprintf(outputFile, "},"); // End of Metadeta
      }
      free(pType);
    }

    if ((psGpxRead->readLinesCounter) == 21) {
    }

    if ((psGpxRead->readLinesCounter) < 52 &&
        (psGpxRead->readLinesCounter) > 20) {

      /* Find line wich tracking points */
      char *trackPoints = getTrackPoint(psGpxRead->readLine);
      if (trackPoints != NULL) {
        /* Get get latitude, longitude and print coordinates */
        char *tmpLat = getLatitude(trackPoints);
        char *tmpLon = getLongitude(trackPoints);
        fprintf(outputFile, "\n{\n\t\"geometry\": {\n"); // Begin print tracking
        fprintf(outputFile, "\t\"type:\" \"Point\",\n  ");
        fprintf(outputFile, "\t\"coordinates\": [ %s, %s", tmpLat, tmpLon);

        free(tmpLon);
        free(tmpLat);
      }
      free(trackPoints);

      /* Get elevation and add to coordinates */
      char *pElevation = getElevation(psGpxRead->readLine);
      if (pElevation != NULL) {
        fprintf(outputFile, ", %s ]", pElevation);
        fprintf(outputFile, "\t\t\n},");
      }
      if (pElevation == NULL) {
        //  fprintf(outputFile, " ]");
        //  fprintf(outputFile, "\t\t\n},");
      }
      free(pElevation);

      /* Get time and print properties print */
      char *pTime = getTime(psGpxRead->readLine);
      if (pTime != NULL) {
        fprintf(outputFile, "\n\t\t\t\"properties:\" {\n");
        fprintf(outputFile, "\t\t\"time\": \"%s\" \n}\n},", pTime);
      }
      free(pTime);
    }
    psGpxRead->readLinesCounter += 1;
  }

  fprintf(outputFile, "\n\t}");
  /* Deallocation */
  unsigned int inputCloseStatus = fclose(inputFile);
  unsigned int outputCloseStatus = fclose(outputFile);

  gpxReadDeinit(psGpxRead);

  /* code */
  return 0;
}

int valiateMemoryPointer(void *pointer) {
  if (pointer == NULL) {
    fprintf(
        stderr,
        "ERROR_NULL_POINTER.\nDidn't allocate memory for read's structure\n");
    return ERROR_NULL_POINTER;
  }
  return CORRECT_EXECUTE;
}

int valiateFilePointer(FILE *pointer) {
  if (pointer == NULL) {
    fprintf(stderr, "ERROR_NULL_POINTER.\nCannot open file.\n");
    return ERROR_NULL_POINTER;
  }
  return CORRECT_EXECUTE;
}
