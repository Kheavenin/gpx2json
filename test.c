#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Zaprojektuj CString. Ma być to tylko wrapper na char*.
Pobranie długości ma być w czasie O(1)
Pobranie dowolnego znaku ma być w czasie O(1)
Zmiana dowolnego znaku ma być w czasie O(1)
Pobranie całego ciągu znaków również ma być w czasie O(1). Ale mamy uniemożliwić zmianę znaków po pobraniu go. (zmieniamy tylko za pomocą funkcji z punktu powyżej)
 */
typedef struct CString
{
    unsigned int d;
    char *s;

} CString;

CString *cstring_new(const char *str)
{
    if (str = NULL)
    {
        printf("\nInput data error.");
    }

    CString *cStr = NULL;
    cStr = malloc(sizeof(CString));
    if (cStr == NULL)
    {
        printf("\nMalloc error.");
    }

    cStr->d = strlen(str);
    cStr->s = malloc((cStr->d) * sizeof(const char));
    strcpy(cStr->s, str);

    return cStr;
}

int main()
{

    const char *str = "Ala kota";

    CString *p = NULL;
    p = cstring_new(str);

    printf("%s", p->s);

    printf("Hello world!");
    free(p);
    return 0;
}