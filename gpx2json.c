#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16

#ERROR_DATA 0
#ERROR_MEMORY ERROR_DATA	//code for memory allocation


typedef struct gpxParamtersStruct
{
	char gpxEncoding[GPX_PARAM_SIZE];
	char gpxVer[GPX_PARAM_SIZE];
	char gpxSource[GPX_SOURCE_SIZE];
	
	int readLines;
};

typedef struct gpxReadStruct
{
	char gpxLatitude[GPX_ARRAY_SIZE];
	char gpxLongitude[GPX_ARRAY_SIZE];
	char gpxElevation[GPX_ARRAY_SIZE];
	char gpxData[GPX_ARRAY_SIZE];
	char gpxTime[GPX_ARRAY_SIZE];

};






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
	if (psGpxParameters == NULL)
	{
		fprintf(stderr, "Error. Didn't allocate memory for parameters's structure\n");
		return ERROR_MEMORY;
	}
	else 
	{
		fprintf(stderr, "Created .gpx paramters's structure.\n" );
	}

	if (psGpxRead == NULL)
	{
		fprintf(stderr, "Error. Didn't allocate memory for read's structure\n");
		return ERROR_MEMORY;
	}
	else 
	{
		fprintf(stderr, "Created .gpx read's structure.\n" );
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