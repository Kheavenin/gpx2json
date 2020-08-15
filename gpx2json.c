#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16

#define CORRECT_EXECUTE 1
#define ERROR_DATA 0
#define ERROR_MEMORY ERROR_DATA			//code for memory allocation
#define ERROR_NULL_POINTER ERROR_DATA	//code for null pointer detection



/** Structers definitons */
typedef struct 
{
	char gpxEncoding[GPX_PARAM_SIZE];
	char gpxVer[GPX_PARAM_SIZE];
	char gpxSource[GPX_SOURCE_SIZE];
	
	int readLines;
} gpxParamtersStruct;

typedef struct 
{
	char gpxLatitude[GPX_ARRAY_SIZE];
	char gpxLongitude[GPX_ARRAY_SIZE];
	char gpxElevation[GPX_ARRAY_SIZE];
	char gpxData[GPX_ARRAY_SIZE];
	char gpxTime[GPX_ARRAY_SIZE];

} gpxReadStruct;

/** Function prototypes */
int valiateMemoryPointer(void *pointer);





int int main(int argc, char const *argv[])
{

	if((argv == NULL) || argc == 0 ) {
		fprintf(stderr ,"\nInvalid arguments.\n");
		return ERROR_DATA ;
	}
		

	/* Create structures and pointers to thier */
	gpxParamtersStruct sGpxParameters, *psGpxParameters = NULL;
	gpxReadStruct sGpxRead, *psGpxRead = NULL;

	/* Allocation memmory for structures */
	psGpxParameters = malloc(sizeof(sGpxParameters));
	psGpxRead = malloc(sizeof(sGpxRead));

	/* Check memory allocations */
	if (!((valiateMemoryPointer((void *) psGpxParameters))))
	{
		fprintf(stderr, "ERROR_NULL_POINTER: psGpxParameters\n");
		return ERROR_NULL_POINTER;
	}
	if(!(valiateMemoryPointer((void *)psGpxRead)))
		{
		fprintf(stderr, "ERROR_NULL_POINTER: psGpxRead\n");
		return ERROR_NULL_POINTER;
	}



	FILE *inputFile;
	inputFile = fopen(argv[1], "r"); //first argument - gpx file to read gps position and time
	if (inputFile == NULL)
	{
		fprintf(stderr, "Cannot open inputFile\n");
	}







	/* code */
	return 0;
	}
}


int valiateMemoryPointer(void *pointer) {
	if (pointer == NULL)
	{
		fprintf(stderr, "Error: NULL_POINTER.\nDidn't allocate memory for read's structure\n");
		return ERROR_NULL_POINTER;
	}
	else 
	{
		fprintf(stderr, "Allocate structure memory.\n" );
		return CORRECT_EXECUTE;
	}
}