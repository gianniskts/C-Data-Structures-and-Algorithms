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

#define LEFT 0
#define RIGHT 1

typedef void* Pointer;

typedef struct  heapNode heapNode;

typedef struct  heapNode{

	heapNode * parent;
	heapNode * leftChild;
	heapNode * rightChild;
	Pointer value;

}heapNode;

typedef struct Heap{

	int size;
	heapNode * root;
	
}Heap;

// constructors
Heap * heapConstruct();
heapNode * create_heapNode(Pointer value);

// geters
void swap(heapNode * hn1,heapNode * hn2);
heapNode * getParent(heapNode * hn);

// fixViolations
void heapifyUp(Heap * heap,heapNode * hn,int (*comparator)(const void *,const void *));
void heapifyDown(Heap * heap,heapNode * hn,int depth,int (*comparator)(const void *,const void *));

// insertion-extraction functions
void insert_toHeap(Heap * heap,Pointer value,int (*comparator)(const void *,const void *));
Pointer extractMax_fromHeap(Heap * heap,int (*comparator)(const void *,const void *));

// destructors
void destroyNode(heapNode * rmNode,int leftORright,Heap * heap);
void destroyHeap(Heap * heap);