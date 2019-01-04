#include "sht_functions.h"

/* SHT_CreateSecondaryIndex */
int SHT_CreateSecondaryIndex(char *sfileName, char *attrName, int attrLength, int buckets) {
    // Create a hash file named 'sfileName'
    if (BF_CreateFile(sfileName) < 0) {
        BF_PrintError("Error creating file");
		return -1;
    } else {
        // Initialization of empty hash file
        printf("File with name %s just created!\n", sfileName);
        // Open hash file
		int fileDesc;
		if ((fileDesc = BF_OpenFile(sfileName)) < 0) {
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
					// Create SHT_info
					printf("Just read the first block!\n");
					SHT_info *sht_info = (SHT_info*)malloc(sizeof(SHT_info));
					// Initialization of SHT_info
					sht_info->fileDesc = fileDesc;
					strcpy(sht_info->attrName,attrName);
					sht_info->attrLength = attrLength;
					sht_info->numBuckets = buckets;
					strcpy(sht_info->fileName,FILENAME);
					printf("Just created SHT_info!\n");
					// Allocate one block for every bucket
					for (int i = 0; i < buckets; i++) {
						if (BF_AllocateBlock(fileDesc) < 0) {
							BF_PrintError("Error allocating block");
							return -1;					
						}
						printf("A block for the %d bucket just allocated!\n", i+1);
					}
					// Convert HT_info struct to bytearray block
					memcpy(block, sht_info, sizeof(SHT_info));
					printf("memcpy success!\n");
					// Write this block again into the HD
					if (BF_WriteBlock(fileDesc, 0) < 0) {
						BF_PrintError("Error writing block back");
						return -1;
					} else {
						printf("Just wrote the first block back to disk!\n");
						free(sht_info);
						/* NO NEED TO CLOSE FILE IN EVERY SIGNLE FUNCTION BECAUSE I WILL HAVE TO OPENFILE IN EACH FUNCTION THEN */
						// Store changes
						if (BF_CloseFile(fileDesc) < 0) {
							BF_PrintError("Error closing file");
							return -1;
						}
						printf("Just store block changes into file!\n");
						
					}
				}
			}
		}
        return 0;
    }
}

/* SHT_OpenSecondaryIndex */
SHT_info* SHT_OpenSecondaryIndex(char *sfileName) {
	// Open hash file
	int fileDesc;
	if ((fileDesc = BF_OpenFile(sfileName)) < 0) {
		BF_PrintError("Error opening file");
		return NULL;
	} else {
		void *block;
		if (BF_ReadBlock(fileDesc, 0, &block) < 0) {
			BF_PrintError("Error getting block");
			return NULL;
		} else {
			SHT_info *header_info = (SHT_info*) malloc(sizeof(SHT_info));
			header_info->fileDesc = ((SHT_info*)block)->fileDesc;
			strcpy(header_info->attrName,((SHT_info*)block)->attrName);
			header_info->attrLength = ((SHT_info*)block)->attrLength;
			header_info->numBuckets = ((SHT_info*)block)->numBuckets;
			strcpy(header_info->fileName,((SHT_info*)block)->fileName);
			return header_info;
		}
	}
}

/* SHT_CloseSecondaryIndex */
int SHT_CloseSecondaryIndex(SHT_info *header_info) {
	// Close file described in header_info
	if (BF_CloseFile(header_info->fileDesc) < 0) {
		BF_PrintError("Error closing file");
		return -1;
	} else {
		free(header_info);
		return 0;
	}
}

/* SHT_SecondaryInsertEntry */
int SHT_SecondaryInsertEntry(SHT_info header_info, SecondaryRecord record) {

}

/* SHT_SecondaryGetAllEntries */
int SHT_SecondaryGetAllEntries(SHT_info header_info_sht, HT_info header_info_ht, void *value) {

}