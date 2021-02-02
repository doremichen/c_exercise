/*
 ============================================================================
 Name        : RingBuffer.c
 Author      : AdamChen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct
{
    const char *pStr[BUFFER_SIZE];
    int read;
    int write;
} BUFFER;

static int isInit = 0;
static BUFFER buffer;

void initBuffer(BUFFER *pBuf)
{
    int id;

    for(id = 0; id < BUFFER_SIZE; ++id)
    {
        pBuf->pStr[id] =  NULL;
    }

    pBuf->read = pBuf->write = 0;
}

int isEmpty(BUFFER *pBuf)
{
    return (pBuf && (pBuf->read == pBuf->write));
}

int isFull(BUFFER *pBuf)
{
    return (pBuf && ((pBuf->write+1)%BUFFER_SIZE == pBuf->read));
}


void cbWrite(BUFFER *pBuf, const char* pstring)
{

    pBuf->pStr[pBuf->write++] = pstring;
    pBuf->write %= BUFFER_SIZE;
    
}

void cbRead(BUFFER *pBuf, const char **pTemp)
{

    *pTemp = pBuf->pStr[pBuf->read++];
    pBuf->read %= BUFFER_SIZE;
}

void Dmsg_Write(const char *pStr)
{
    if(!isInit)
    {
        initBuffer(&buffer);
        isInit = 1;
    }

    cbWrite(&buffer, pStr);
}

void Dmsg_Dump(void)
{
    const char *getStr =  NULL;
    int id;

    if(!isInit)
    {
        initBuffer(&buffer);
        isInit = 1;
    }

    for(id = 0; id < BUFFER_SIZE; ++id)
    {
        cbRead(&buffer, &getStr);
        printf("%s--------------\n", getStr);
    }


}



void printData(BUFFER *pBuf)
{
    int i;

    for(i = 0; i < BUFFER_SIZE; ++i)
    {
        printf("%d: %s\n", i, pBuf->pStr[i]);
    }
}

int main(void) {
    
    Dmsg_Write("1: aaa");
    Dmsg_Write("2: aaa");
    Dmsg_Write("3: aaa");
    Dmsg_Write("4: aaa");
    Dmsg_Write("5: aaa");
    Dmsg_Write("6: aaa");
    Dmsg_Write("7: aaa");
    Dmsg_Write("8: aaa");
    Dmsg_Write("9: aaa");
    Dmsg_Write("10: aaa");


    Dmsg_Dump();

    return EXIT_SUCCESS;
}
