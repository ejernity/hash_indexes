#include "ht_functions.h"

/* HT_CreateIndex */
int HT_CreateIndex(char *fileName, char attrType, char *attrName, int attrLength, int buckets) {
    // Create a hash file named 'fileName'
    if (BF_CreateFile(fileName) < 0) {
        BF_PrintError("Error creating file");
		exit(EXIT_FAILURE);
    } else {
        // initialization of empty hash file
        printf("File with name %s just created!", fileName);
    }
}

/* HT_OpenIndex */
HT_info* HT_OpenIndex(char *fileName) {

}

/* HT_CloseIndex */
int HT_CloseIndex(HT_info *header_info) {

}

/* HT_InsertEntry */
int HT_InsertEntry(HT_info header_info, Record record) {

}

/* HT_DeleteEntry */
int HT_DeleteEntry(HT_info header_info, void *value) {

}

/* HT_GetAllEntries */
int HT_GetAllEntries(HT_info header_info, void *value) {

}