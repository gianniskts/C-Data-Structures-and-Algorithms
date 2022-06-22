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

#include "./Comparators.h"		// we need Comparators
#include "./HashFunctions.h"		// we need HashFunctions


#define empty NULL

typedef void * keyType;
typedef const void* ConstPointer;
typedef void* Pointer;
typedef struct HashTableNode HashNode;
typedef void InfoType;
typedef struct Data DataNode;
typedef struct Key KeyNode;

typedef struct HashTable {
	unsigned int size;
	HashNode **Table;	
}HashTable;

typedef struct HashTableNode{
	KeyNode * keyList;
}HashNode;

typedef struct Key{
	keyType key;
	DataNode * dataList;		/*Pointer to list */
	KeyNode * next;				/*Next key ,if hash table collision */
}KeyNode;

typedef struct Data{
	InfoType * data;
	DataNode * next;
}DataNode;


/*---------Create_Functions-------------*/

HashTable * createHashTable(int size);
KeyNode * createKeyNode(keyType key);
DataNode * createDataNode(InfoType * newdata);


/*-------------Insert_Functions-----------------*/

void HashInsert(HashTable * ht,keyType key,InfoType * info,int (*compare)(ConstPointer,ConstPointer));
KeyNode * insertNewKey(HashNode * hn , keyType key);
void insertData(KeyNode * key,InfoType * newdata);


/*------------Getters-----------------*/

keyType getKey(KeyNode * keyList);
unsigned int hashCode(HashTable * ht,keyType key);

/*--------------Search_function-------------------*/

KeyNode * findKeyNode(HashTable * ht,keyType key,int (*compare)(ConstPointer,ConstPointer));

/*----------Remove_functions------------------*/

void RemoveDataFromHT(HashTable * ht,InfoType * rmData,keyType key,int (*compare)(ConstPointer,ConstPointer));
void RemoveKeyFromHT(HashTable * ht , keyType key,int (*compare)(ConstPointer,ConstPointer));


/*------------------Destructors----------------*/

void destroyDataList(DataNode * startOfList);
void destroyHashTable(HashTable * ht);
