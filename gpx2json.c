#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ERROR_DATA 0


//Elevation 
//latitude
//longitude
//time

typedef struct gpxParamtersStruct
{
	char gpxEncoding[8];
	char gpxVer[8];
	char gpxSource[64];
	
	int readLines;
};


int int main(int argc, char const *argv[])
{

	if((argv == NULL) || argc == 0 ) {
		fprintf(stderr ,"\nInvalid arguments.\n");
		return ERROR_DATA ;
	}
		

	/* Create structure and pointer to its */
	gpxParamtersStruct sGpxParameters, *psGpxParameters = NULL;
	/* Allocation memmory for structures */
	psGpxParameters = malloc(sizeof(sGpxParameters)); 


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