/*
 **************************************************************************
 * Author: Giannis Kotsias		                                          *
 * URL: http://github.com/gianniskts                                      *
 *                                                                        *
 * Copyright notice:   							  						  *
 * Free use this code is permitted under the guidelines 		  		  *
 * and in accordance with the MIT License. 				  				  * 
 *                                                                        *
 **************************************************************************
*/
#pragma once
/* hashtable consists of buckets and buckets point to a memory that are stored HTrecords */
#include <unistd.h>
#include "./RBTree.h"
#include "./HashFunctions.h"


#define ERROR -1
#define NO_ERROR 1

typedef const void * comparatorValue;
typedef struct Bucket Bucket;
typedef void* Pointer;
typedef const void* ConstPointer;
typedef char* String;

typedef struct HTRecord{
		
	Pointer value;
	String key;
	int counter;

}HTRecord;

typedef struct Bucket{

	int records;		// counter of records saved in bucketMemory
	Pointer bucketMemory;	// bucket storage
	Bucket * next;

}Bucket;

typedef struct HashTable{
	
	size_t hashtableSize;
	size_t bucketSize;
	int records_perBucket;
	int numOfRecords;
	Bucket **buckets; 

}HashTable;


/*----------- HashTable functions ------------------*/ 

// constructors
HashTable * create_HashTable(size_t hashtableSize,size_t bucketSize);
Bucket * createBucket(size_t bucketSize);
HTRecord * createHTRecord(String key);

// insertion functions
int insert_toHashTable(Pointer value,String HTkey,String treeKey,HashTable * ht,int (*comparator)(comparatorValue,comparatorValue));
int insertRecord(Pointer htRecord,Bucket * bucket);
void increaseCounter(HTRecord * record);

// geters
void * getValue(HTRecord * record);
int getCounter(HTRecord * record);
int getNumOfRecords(HashTable * ht);

// search functions
void numOfRecordsBetweenKeys(HashTable * hashtable,String date1,String date2,int (*comparator)(comparatorValue,comparatorValue));
int findKeyData(HashTable * hashtable,String wantedKey,String date1,String date2,int (*comparator)(comparatorValue,comparatorValue),String funValue,int (*function)(Pointer,String));

// destructors
void destroyHashTable(HashTable * hashtable);

