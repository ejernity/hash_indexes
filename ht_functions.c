#include "ht_functions.h"

/* HT_CreateIndex */
int HT_CreateIndex(char *fileName, char attrType, char *attrName, int attrLength, int buckets) {
    // Create a hash file named 'fileName'
    if (BF_CreateFile(fileName) < 0) {
        BF_PrintError("Error creating file");
		return -1;
    } else {
        // Initialization of empty hash file
        printf("File with name %s just created!\n", fileName);
        // Open hash file
		int fileDesc;
		if ((fileDesc = BF_OpenFile(fileName)) < 0) {
			BF_PrintError("Error opening file");
			return -1;
		} else {
			// Get block (HD to RAM)
			void *block;
			if (BF_AllocateBlock(fileDesc) < 0) {
				BF_PrintError("Error allocating block");
				return -1;
			} else {
				if (BF_ReadBlock(fileDesc, 0, &block) < 0) {
					BF_PrintError("Error getting block");
					return -1;
				} else {
					// Create HT_info
					printf("Just read the first block!\n");
					HT_info *ht_info = (HT_info*)malloc(sizeof(HT_info));
					// Initialization of HT_info
					ht_info->fileDesc = fileDesc;
					ht_info->attrType = attrType;
					strcpy(ht_info->attrName,attrName);
					ht_info->attrLength = attrLength;
					ht_info->numBuckets = buckets;
					printf("Just created HT_info!\n");
					// Allocate one block for every bucket
					for (int i = 0; i < buckets; i++) {
						if (BF_AllocateBlock(fileDesc) < 0) {
							BF_PrintError("Error allocating block");
							return -1;					
						}
						printf("A block for the %d bucket just allocated!\n", i+1);
					}
					// Convert HT_info struct to bytearray block
					memcpy(block, ht_info, sizeof(HT_info));
					printf("memcpy success!\n");
					// Write this block again into the HD
					if (BF_WriteBlock(fileDesc, 0) < 0) {
						BF_PrintError("Error writing block back");
						return -1;
					} else {
						printf("Just wrote the first block back to disk!\n");
						free(ht_info);
						/* NO NEED TO CLOSE FILE IN EVERY SIGNLE FUNCTION BECAUSE I WILL HAVE TO OPENFILE IN EACH FUNCTION THEN
						// Store changes
						if (BF_CloseFile(fileDesc) < 0) {
							BF_PrintError("Error closing file");
							return -1;
						}
						printf("Just store block changes into file!\n");
						*/
					}
				}
			}
		}
        return 0;
    }
}

/* HT_OpenIndex */
HT_info* HT_OpenIndex(char *fileName) {
	// Open hash file
	int fileDesc;
	if ((fileDesc = BF_OpenFile(fileName)) < 0) {
		BF_PrintError("Error opening file");
		return NULL;
	} else {
		void *block;
		if (BF_ReadBlock(fileDesc, 0, &block) < 0) {
			BF_PrintError("Error getting block");
			return NULL;
		} else {
			HT_info *header_info = (HT_info*) malloc(sizeof(HT_info));
			return header_info;
		}
	}
}

/* HT_CloseIndex */
int HT_CloseIndex(HT_info *header_info) {
	// Close file described in header_info
	if (BF_CloseFile(header_info->fileDesc) < 0) {
		BF_PrintError("Error closing file");
		return -1;
	} else {
		free(header_info);
		return 0;
	}
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