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

#include <stdio.h>

#define NO_ERROR 1
#define ERROR -1

typedef void* Pointer;
typedef const void* ConstPointer;

typedef struct queueNode queueNode;

typedef struct queueNode{
	
	Pointer data;
	queueNode * nextNode;
	queueNode * prevNode;
		
}queueNode;

typedef struct Queue{

	queueNode * firstNode;
	queueNode * lastNode;
	int numOfNodes;

} Queue;

/*----------- List utilities --------------*/

// constructors
Queue * createQueue();
queueNode * create_queueNode(Pointer data);

// insertion functions
int QueuePush(Queue * queue,Pointer data);

// geters
Pointer QueuePop(Queue * queue);

int emptyQueue(Queue * queue);

// destructors
int deleteQueue(Queue * queue);

