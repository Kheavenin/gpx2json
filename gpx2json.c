#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extractData.h"

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16
#define GPX_MARKERS_SIZE 8

#define CORRECT_EXECUTE 1
#define ERROR_DATA 0
#define ERROR_MEMORY 0       //code for memory allocation
#define ERROR_NULL_POINTER 0 //code for null pointer detection

/** Structers definitons */
typedef struct
{
    char gpxEncoding[GPX_PARAM_SIZE];
    char gpxVer[GPX_PARAM_SIZE];
    char gpxSource[GPX_SOURCE_SIZE];
    char gpxActivityType[GPX_PARAM_SIZE];

    unsigned int readLines;
} gpxParamtersStruct;

typedef struct
{
    char gpxLatitude[GPX_ARRAY_SIZE];
    char gpxLongitude[GPX_ARRAY_SIZE];
    char gpxElevation[GPX_ARRAY_SIZE];
    char gpxData[GPX_ARRAY_SIZE];
    char gpxTime[GPX_ARRAY_SIZE];

} gpxReadStruct;

char line[128];

/** Function prototypes */
int valiateMemoryPointer(void *pointer);
int valiateFilePointer(FILE *pointer);

int main(int argc, char const *argv[])
{

    if ((argv == NULL) || (argc != 3))
    {
        fprintf(stderr, "\nInvalid arguments.\n");
        return ERROR_DATA;
    }

    /* Create structures and pointers to thier */
    gpxParamtersStruct sGpxParameters, *psGpxParameters = NULL;
    gpxReadStruct sGpxRead, *psGpxRead = NULL;

    /* Allocation memmory for structures */
    psGpxParameters = malloc(sizeof(sGpxParameters));
    psGpxRead = malloc(sizeof(sGpxRead));

    /* Check memory allocations */
    if (!((valiateMemoryPointer((void *)psGpxParameters))))
    {
        fprintf(stderr, "ERROR_NULL_POINTER: psGpxParameters\n");
        return ERROR_NULL_POINTER;
    }
    if (!(valiateMemoryPointer((void *)psGpxRead)))
    {
        fprintf(stderr, "ERROR_NULL_POINTER: psGpxRead\n");
        return ERROR_NULL_POINTER;
    }

    psGpxParameters->readLines = 0;

    FILE *inputFile = NULL;
    FILE *outputFile = NULL;
    inputFile = fopen(argv[1], "r"); //first argument - gpx file to read gps position and time
    outputFile = fopen(argv[2], "w");

    if (!valiateFilePointer(inputFile))
    {
        fprintf(stderr, "\nCannot open input file");
    }

    if (!valiateFilePointer(outputFile))
    {
        fprintf(stderr, "\nCannot create output file.");
    }

    /** Read file */
    while (fscanf(inputFile, "%127[^\n]\n", line) == 1)
    {
        if (strstr(line, name))
        {
            printf("\nRead author name: %s\n", line);
            printf("In line: %lu", (psGpxParameters->readLines));
        }

        psGpxParameters->readLines += 1;
        printf("Read lines: %lu", (psGpxParameters->readLines));
    }

    /* Deallocation */
    unsigned int inputCloseStatus = fclose(inputFile);
    unsigned int outputCloseStatus = fclose(outputFile);

    free(psGpxRead);
    free(psGpxParameters);

    /* code */
    return 0;
}

int valiateMemoryPointer(void *pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "ERROR_NULL_POINTER.\nDidn't allocate memory for read's structure\n");
        return ERROR_NULL_POINTER;
    }
    return CORRECT_EXECUTE;
}

int valiateFilePointer(FILE *pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "ERROR_NULL_POINTER.\nCannot open file.\n");
        return ERROR_NULL_POINTER;
    }
    return CORRECT_EXECUTE;
}
