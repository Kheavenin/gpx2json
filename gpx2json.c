#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GPX_PARAM_SIZE 8
#define GPX_SOURCE_SIZE 64
#define GPX_ARRAY_SIZE 16

#define CORRECT_EXECUTE 1
#define ERROR_DATA 0
#define ERROR_MEMORY ERROR_DATA		  //code for memory allocation
#define ERROR_NULL_POINTER ERROR_DATA //code for null pointer detection

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

typedef struct
{
	unsigned int allocateMemoryCounter;
	unsigned int deallocateMemoryCounter;

} memoryGuardCountersStruct;

typedef struct
{
	void *(*pAllocteMemory)(memoryGuardCountersStruct *s, size_t);
	void (*pDeallocateMemory)(memoryGuardCountersStruct *s, void *);
	int (*pMemoryLeak)(memoryGuardCountersStruct *s);
} memoryGuardFunctionsStruct;

typedef struct
{
	memoryGuardCountersStruct *pMemoryGuardCounter;
	memoryGuardFunctionsStruct *pMemoryGuardFunctions;

} memoryGuardStruct;

/** Function prototypes */

int valiateMemoryPointer(void *pointer);

memoryGuardCountersStruct *initMemoryGuardCounters(void);
memoryGuardFunctionsStruct *initMemoryGuardFunction(void *(*a)(memoryGuardCountersStruct *, size_t),
													void (*d)(memoryGuardCountersStruct *, void *),
													int (*l)(memoryGuardCountersStruct *));
memoryGuardStruct *initMemoryGuard(void *(*a)(memoryGuardCountersStruct *, size_t),
								   void (*d)(memoryGuardCountersStruct *, void *),
								   int (*l)(memoryGuardCountersStruct *));

void *allocateMemory(memoryGuardCountersStruct *s, size_t size);
void deallocateMemory(memoryGuardCountersStruct *s, void *pMemoryHandler);
int memoryLeak(memoryGuardCountersStruct *s);

int main(int argc, char const *argv[])
{

	if ((argv == NULL) || argc == 0)
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

int valiateMemoryPointer(void *pointer)
{
	if (pointer == NULL)
	{
		fprintf(stderr, "Error: NULL_POINTER.\nDidn't allocate memory for read's structure\n");
		return ERROR_NULL_POINTER;
	}
	else
	{
		fprintf(stderr, "Allocate structure memory.\n");
		return CORRECT_EXECUTE;
	}
}

void *allocateMemory(memoryGuardCountersStruct *s, size_t size)
{
	if (size < 1)
	{
		fprintf(stderr, "ERROR_SIZE.\nSize passed to allocate: %ld\n", size);
		return NULL;
	}

	void *pMemoryHandler = NULL;
	pMemoryHandler = malloc(size);

	if (pMemoryHandler != NULL)
	{
		++(s->allocateMemoryCounter);
		return (pMemoryHandler);
	}
	else
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nDidn't allocate memory with %ld size.\n", size);
	}
}

void deallocateMemory(memoryGuardCountersStruct *s, void *pMemoryHandler)
{
	if (pMemoryHandler != NULL)
	{
		free(pMemoryHandler);
		++(s->deallocateMemoryCounter);
	}
	else
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nCannot deallocate memory.\n");
	}
}

int memoryLeak(memoryGuardCountersStruct *s)
{
	if ((s->allocateMemoryCounter) != (s->deallocateMemoryCounter))
	{
		fprintf(stderr, "ERROR_MEMORY\nDetect memory leak.\nDiffrence between allocante and deallocate: %u", ((s->allocateMemoryCounter) - (s->deallocateMemoryCounter)));
		return ERROR_MEMORY;
	}
	else
	{
		/* No leak memory detected*/
		return CORRECT_EXECUTE;
	}
}

memoryGuardCountersStruct *initMemoryGuardCounters(void)
{
	memoryGuardCountersStruct memoryCountersGuard, *pMemoryCountersGuard = NULL;
	pMemoryCountersGuard = &memoryCountersGuard;

	if (pMemoryCountersGuard == NULL)
	{
		fprintf(stderr, "ERROR_MEMORY\nMemory Guard Counters have not been initalized.");
		return ERROR_NULL_POINTER;
	}

	pMemoryCountersGuard->allocateMemoryCounter = 0;
	pMemoryCountersGuard->deallocateMemoryCounter = 0;

	return pMemoryCountersGuard;
}

memoryGuardFunctionsStruct *initMemoryGuardFunction(void *(*a)(memoryGuardCountersStruct *, size_t),
													void (*d)(memoryGuardCountersStruct *, void *),
													int (*l)(memoryGuardCountersStruct *))
{
	if (a == NULL || d == NULL || l == NULL)
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nFuntions's pointers have no reference.");
		return ERROR_NULL_POINTER;
	}

	memoryGuardFunctionsStruct memoryGuardFunctions, *pMemoryGuardFunctions = NULL;
	pMemoryGuardFunctions = &memoryGuardFunctions;

	if (pMemoryGuardFunctions == NULL)
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nMemory Guard Functions have not been initalized.");
		return ERROR_NULL_POINTER;
	}

	pMemoryGuardFunctions->pAllocteMemory = a;
	pMemoryGuardFunctions->pDeallocateMemory = d;
	pMemoryGuardFunctions->pMemoryLeak = l;

	return pMemoryGuardFunctions;
}

memoryGuardStruct *initMemoryGuard(void *(*a)(memoryGuardCountersStruct *, size_t),
								   void (*d)(memoryGuardCountersStruct *, void *),
								   int (*l)(memoryGuardCountersStruct *))
{
	memoryGuardCountersStruct *pMemCount = initMemoryGuardCounters();
	if (pMemCount == NULL)
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nMemory Counters struct didn't create.");
		return ERROR_NULL_POINTER;
	}

	memoryGuardFunctionsStruct *pMemFunc = initMemoryGuardFunction(a, d, l);
	if (pMemFunc == NULL)
	{
		fprintf(stderr, "ERROR_NULL_POINTER\nMemory Functions struct didn't create.");
		return ERROR_NULL_POINTER;
	}

	memoryGuardStruct sMemoryGuard, *psMemoryGuard;
	psMemoryGuard = &sMemoryGuard;
	psMemoryGuard->pMemoryGuardCounter = pMemCount;
	psMemoryGuard->pMemoryGuardFunctions = pMemFunc;

	return psMemoryGuard;
}
