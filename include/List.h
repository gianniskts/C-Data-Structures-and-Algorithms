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

typedef struct listNode listNode;

typedef struct listNode{
	
	Pointer data;
	listNode * nextNode;
	listNode * prevNode;
		
}listNode;

typedef struct List{

	listNode * firstNode;
	listNode * lastNode;
	int numOfNodes;

}List;

/*----------- List utilities --------------*/

// constructors
List * createList();
listNode * create_listNode(Pointer data);

// insertion functions
int insert_toList(List * list,Pointer data);

// geters
Pointer getData_fromList(List * list,int index);
int get_numOfNodes(List * list);

// search functions
Pointer findValue(List * list,Pointer value,int (*comparator)(Pointer,Pointer));

// destructors
int deleteList(List * list);

// print function
void printList(List * list,void (*printData)(Pointer));

// list with one node
int oneNodeList(List * list);

// size
int get_listSize(List * list);

// merge lists
List * mergeLists(List * list1,List * list2);
