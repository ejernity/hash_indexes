#include "sht_functions.h"

/* SHT_CreateSecondaryIndex */
int SHT_CreateSecondaryIndex(char *sfileName, char *attrName, int attrLength, int buckets) {

}

/* SHT_OpenSecondaryIndex */
SHT_info* SHT_OpenSecondaryIndex(char *sfileName) {

}

/* SHT_CloseSecondaryIndex */
int SHT_CloseSecondaryIndex(SHT_info *header_info) {

}

/* SHT_SecondaryInsertEntry */
int SHT_SecondaryInsertEntry(SHT_info header_info, SecondaryRecord record) {

}

/* SHT_SecondaryGetAllEntries */
int SHT_SecondaryGetAllEntries(SHT_info header_info_sht, HT_info header_info_ht, void *value) {

}