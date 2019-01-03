#ifndef _HT_FUNCTIONS_H_
#define _HT_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BF.h"

typedef struct {
    int fileDesc;
    char attrType;
    char *attrName;
    int attrLength;
    long int numBuckets;
} HT_info;

typedef struct {
    int id;
    char name[15];
    char surname[20];
    char address[40];
} Record;

int HT_CreateIndex(char *fileName, char attrType, char *attrName, int attrLength, int buckets);

HT_info* HT_OpenIndex(char *fileName);

int HT_CloseIndex(HT_info *header_info);

int HT_InsertEntry(HT_info header_info, Record record);

int HT_DeleteEntry(HT_info header_info, void *value);

int HT_GetAllEntries(HT_info header_info, void *value);

#endif