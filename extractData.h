#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char author[];
extern char name[];
extern char source[];
extern char type[];
extern char time[];

extern char trackingPoints[];
extern char elevation[];

extern char end_name[];
extern char end_time[];

char *findAuthor(char *s, size_t size);
char *findTime(char *s, size_t size);
char *findActivity(char *s, size_t size);