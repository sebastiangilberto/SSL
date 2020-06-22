#include "String.h"
#include <string.h>
#include <assert.h>

void testGetLength()
{
    size_t string1 = GetLength("");
    assert(string1 == 0);

    size_t string2 = GetLength("abcd");
    assert(string2 == 4);

    char string3[25] = "Hello World";
    size_t string3_length = GetLength(string3);
    assert(string3_length == 11);

    char string4[30] = "";
    size_t length4 = GetLength(string4);
    assert(length4 == 0);
}

void testIsEmpty()
{
    bool result1 = IsEmpty("hola");
    assert(result1 == false);

    bool result2 = IsEmpty("");
    assert(result2 == true);
    
    char staticString1[20] = "Hello world";
    bool result3 = IsEmpty(staticString1);
    assert(result3 == false);

    char staticString2[20] = "";
    bool result4 = IsEmpty(staticString2);
    assert(result4 == true);
}

void testPowerStatic()
{
    char result1[20];
    PowerStatic("abc", 3, result1);
    assert(strcmp(result1, "abcabcabc") == 0);

    char result2[20];
    PowerStatic("", 3, result2);
    assert(Compare(result2, "", 0) == 0);
    
    char result3[20];
    char string1[20] = "hola";
    PowerStatic(string1, 3, result3);
    assert(Compare(result2, "", 0) == 0);
    
    char result4[20];
    char string2[20] = "";
    PowerStatic(string2, 3, result4);
    assert(strcmp(result4, "") == 0);

    char result5[20];
    char string3[20] = "hola";
    PowerStatic(string3, 0, result5);
    assert(strcmp(result5, "") == 0);
}

void testPowerDynamic()
{
    char * result1 = PowerDynamic("abc", 3);
    assert(strcmp(result1, "abcabcabc") == 0);

    char * result2 = PowerDynamic("", 3);
    assert(strcmp(result2, "") == 0);
    
    char string1[20] = "hola";
    char * result3 = PowerDynamic(string1, 3);
    assert(strcmp(result3, "holaholahola") == 0);
    
    char string2[20] = "";
    char * result4 = PowerDynamic(string2, 3);
    assert(strcmp(result4, "") == 0);

    char string3[20] = "hola";
    char * result5 = PowerDynamic(string3, 0);
    assert(strcmp(result5, "") == 0);

    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
}

void testCompare()
{
    int result1 = Compare("abc", "abc", 0);
    assert(result1 == 0);
    
    result1 = strcmp("abc", "abc");
    assert(result1 == 0);
    
    int result2 = Compare("", "abc", 0);
    assert(result2 < 0);
    
    result2 = strcmp("", "abc");
    assert(result2 < 0);
    
    int result3 = Compare("", "", 0);
    assert(result3 == 0);
    
    result3 = strcmp("", "");
    assert(result3 == 0);

    char string1[5] = "abc";
    char string2[5] = "abc";
    int result4 = Compare(string1, string2, 0);
    assert(result4 == 0);

    result4 = strcmp(string1, string2);
    assert(result4 == 0);

    char string3[5] = "abc";
    char string4[5] = "";
    int result5 = Compare(string3, string4, 0);
    assert(result5 > 0);
    
    result5 = strcmp(string3, string4);
    assert(result5 > 0);
}

int main(void){
    testGetLength();
    testIsEmpty();
    testPowerStatic();
    testPowerDynamic();
    testCompare();
    return 0;
}
