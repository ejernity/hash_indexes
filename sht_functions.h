#ifndef _SHT_FUNCTIONS_H_
#define _SHT_FUNCTIONS_H_

#include "ht_functions.h"
#define MYFILENAME "hile"

typedef struct {
    int fileDesc;
    char attrName[10];
    int attrLength;
    long int numBuckets;
    char fileName[10];
} SHT_info;

typedef struct {
    Record record;
    int blockId;
} SecondaryRecord;

int SHT_CreateSecondaryIndex(char *sfileName, char *attrName, int attrLength, int buckets);

SHT_info* SHT_OpenSecondaryIndex(char *sfileName);

int SHT_CloseSecondaryIndex(SHT_info *header_info);

int SHT_SecondaryInsertEntry(SHT_info header_info, SecondaryRecord record);

int SHT_SecondaryGetAllEntries(SHT_info header_info_sht, HT_info header_info_ht, void *value);

#endif