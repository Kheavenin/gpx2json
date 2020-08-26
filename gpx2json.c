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
  bool printFlag = false;
  bool oneUseFlag = true;
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

    if ((psGpxRead->readLinesCounter) < 52 &&
        (psGpxRead->readLinesCounter) > 21) {

      /* Find line which has tracking points */
      char *trackPoints = getTrackPoint(psGpxRead->readLine);
      if (trackPoints != NULL) {
        /* Get get latitude, longitude and print coordinates */
        char *tmpLat = getLatitude(trackPoints);
        char *tmpLon = getLongitude(trackPoints);
        setReadLatitudec(psGpxRead, tmpLat);
        setReadLongitude(psGpxRead, tmpLon);
        free(tmpLon);
        free(tmpLat);
      }
      free(trackPoints);

      /* Get elevation  */
      char *pElevation = getElevation(psGpxRead->readLine);
      if (pElevation != NULL) {
        setReadElevation(psGpxRead, pElevation);
      }
      free(pElevation);
      /* Get time */
      char *pTime = getTime(psGpxRead->readLine);
      if (pTime != NULL) {
        setReadTime(psGpxRead, pTime);
        printFlag = true;
      }
      free(pTime);

      if (printFlag) {
        if (strlen(getReadLatitude(psGpxRead)) < 2)
          setReadLatitudec(psGpxRead, "null");
        if (strlen(getReadLongitude(psGpxRead)) < 2)
          setReadLongitude(psGpxRead, "null");
        if (strlen(getReadElevation(psGpxRead)) < 2)
          setReadElevation(psGpxRead, "null");
        if (strlen(getReadTime(psGpxRead)) < 2)
          setReadTime(psGpxRead, "null");

        /* Printig feature */
        if (oneUseFlag) {
          fprintf(outputFile, "\n\t\"feature\": [");
          oneUseFlag = false;
        }
        /* Printing coordinates */
        fprintf(outputFile, "\n\t{\n\t\t\"geometry\": {");
        fprintf(outputFile, "\n\t\t\"type\": \"Point\",");
        fprintf(outputFile, "\n\t\t\"coordinates\": ");
        fprintf(outputFile, "[ %s, %s, %s ]", getReadLatitude(psGpxRead),
                getReadLongitude(psGpxRead), getReadElevation(psGpxRead));
        fprintf(outputFile, "\n\t\t},");
        /* printing properties */
        fprintf(outputFile, "\n\t\t\"properties:\" {\n");
        fprintf(outputFile, "\t\t\"time\": \"%s\", \n\t\t\"elevation\": %s",
                getReadTime(psGpxRead), getReadElevation(psGpxRead));
        fprintf(outputFile, "\n\t\t}"); // End of propertie
        fprintf(outputFile, "\n\t},");  // end of block

        for (size_t i = 0; i < DEFAULT_DATA_SIZE; i++) {
          memset(psGpxRead->readData[i], '\0', strlen(psGpxRead->readData[i]));
        }

        printFlag = false;
      }
    }
    psGpxRead->readLinesCounter += 1;
  }
  fprintf(outputFile, "\n\t]"); // End of feature
  fprintf(outputFile, "\n\t}"); // End of JSON
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
