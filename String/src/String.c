/*
 ============================================================================
 Name        : String.c
 Author      : AdamChen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0


typedef char *String;

int StrLength(String pStr)
{
    int size = 0;

    if(pStr)
    {
        while(*pStr != '\0')
        {
            pStr++;
            ++size;
        }
    }

    return size;
}

int SubString(String *pSubStr, String pMainStr, int pos, int length)
{
    int i = 0;
    String tempStr =  NULL;

    tempStr = (String)malloc(sizeof(char));

    if(!pMainStr)
    {
        printf("no main string\n");
        return ERROR;
    }

    tempStr[0] = pMainStr[pos-1];

    while(i < length)
    {
        i++;
        tempStr[i] = pMainStr[pos-1+i];
    }

    tempStr[length] = '\0';

    *pSubStr = tempStr;


//    *pSubStr = (*pSubStr)-i;


    return OK;
}

int StrCompare(String str1, String str2)
{
    int i = 0;
    int Lstr1 = 0, Lstr2 = 0;
    int ret = -1;

    Lstr1 = StrLength(str1);
    Lstr2 = StrLength(str2);

    if(Lstr1 == Lstr2)
    {
        while(i < Lstr1)
        {
            if(*(str1) > *(str2))
            {
                ret = 1;
                break;
            }
            else if(*(str1) < *(str2))
            {
                ret = -1;
                break;
            }

            str1++;
            str2++;

            i++;
        }
        if(i == Lstr1)
            ret = 0;
    }
    else if(Lstr1 > Lstr2)
    {
        ret = 1 ;
    }

    return ret;
}

int IndexSubStr(String mainStr, String subStr, int pos)
{
    int i = 0, str1L = 0, str2L = 0;
    String sub;

    if(pos > 0)
    {
        str1L = StrLength(mainStr);
        str2L = StrLength(subStr);
        i = pos;
        while(i < (str1L - str2L +1))
        {
            SubString(&sub, mainStr, i, str2L);
            if(StrCompare(sub, subStr) != 0)
            {
                if(sub)
                    free(sub);
                ++i;
            }
            else
            {
                if(sub)
                    free(sub);
                return i;
            }

        }

    }

    return 0;
}

int main(void) {

//    String str1 = "abc";
//    String str2 = "aac";
//    int ret = 0;
//
//    ret = StrCompare(str1, str2);
//
//    printf("%d\n", ret);

//    String pstr = "12345678";
//    String pSubStr = NULL;
//
//    SubString(&pSubStr, pstr, 4, 3);
//
//    printf("%s\n", pSubStr);

//    printf("size: %d\n", StrLength(pstr));


//    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    return EXIT_SUCCESS;
}
