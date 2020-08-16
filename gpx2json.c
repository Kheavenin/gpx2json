#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16

#define CORRECT_EXECUTE 1
#define ERROR_DATA 0
#define ERROR_MEMORY ERROR_DATA			//code for memory allocation
#define ERROR_NULL_POINTER ERROR_DATA	//code for null pointer detection


static unsigned int allocateMemCounter = 0;
static unsigned int deallocateMemCounter = 0;

void *allocateMemory(size_t size);
void deallocateMemory(void *pMemoryHandler);
int checkMemoryLeak(void);


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




	/* Deallocation */
	free(psGpxRead);
	free(psGpxParameters);

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


void *allocateMemory(size_t size) {
	if(size < 1) {
		fprintf(stderr, "ERROR_SIZE.\nSize passed to allocate: %ld\n", size );
		return NULL;
	}

	void *pMemoryHandler = NULL;
	pMemoryHandler = malloc(size);

	if (pMemoryHandler != NULL)
	{
		++allocateMemCounter;
		return (pMemoryHandler);
	}
	else 
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nDidn't allocate memory with %ld size.\n",size );
	}

}

void deallocateMemory(void *pMemoryHandler) {
	if (pMemoryHandler != NULL)
	{
		free(pMemoryHandler);
		++deallocateMemCounter;
	}
	else {
		fprintf(stderr, "ERROR_NULL_POINTER\nCannot deallocate memory.\n");
	}
}

int checkMemoryLeak(void) {
	if(allocateMemCounter != deallocateMemCounter ) {
		fprintf(stderr, "ERROR_MEMORY\nDetect memory leak.\nDiffrence between allocante and deallocate: %u", (allocateMemCounter - deallocateMemCounter));
		return ERROR_MEMORY;
	}
	else{
		/* No leak memory detected*/
		return CORRECT_EXECUTE;
	}
}