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

typedef void* Pointer;

void exchange(Pointer* array,int pos1,int pos2);

/* Getters */
int getLeft(int i);
int getRight(int i);
int getParent(int i);

/* Heap main utility */
void buildMaxHeap(Pointer* array,int heapSize,int (*compare)(const void*,const void*));
void maxHeapify(Pointer* array,int heapSize,int i,int (*compare)(const void*,const void*));
void heapsort(Pointer* array,int heapSize,int (*compare)(const void*,const void*));