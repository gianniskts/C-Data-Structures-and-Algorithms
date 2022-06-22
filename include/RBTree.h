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

#include "./Comparators.h"

enum nodeColor { BLACK, RED };

typedef enum nodeColor nodeColor;
typedef struct Node RBTNode;
typedef const void * valueType;
typedef void* Pointer;
typedef char* String;

extern RBTNode * GUARD;				/* Global pointer for guard */

typedef struct Node {

	RBTNode * parent,*left,*right;
	enum nodeColor color;
	valueType key;

	Pointer data;

} RBTNode;

RBTNode * createGuard();
void destroyGuard();

RBTNode * RBTConstruct();
RBTNode * RBTnewNode(Pointer data,valueType key);
void RBTInitialiseKey(RBTNode * n,valueType key);

RBTNode * GetParent(RBTNode* n);
RBTNode * GetGrandParent(RBTNode * n);
valueType GetKey(RBTNode * n);
nodeColor GetColor(RBTNode * n);
Pointer get_RBTData(RBTNode * node);
int RBTempty(RBTNode * root);
void SetColor(RBTNode * n,nodeColor color);

void RotateLeft(RBTNode **treeRoot,RBTNode * x);
void RotateRight(RBTNode **treeRoot,RBTNode * x);

void RBTInsert(RBTNode **treeRoot,Pointer data,valueType key,int (*comparator)(valueType,valueType));
void RBTInsertFixUP(RBTNode **treeRoot,RBTNode * z);

void RBTReplaceNode(RBTNode **treeRoot,RBTNode * u,RBTNode * v);
void RBTRemoveNode(RBTNode **treeRoot,RBTNode * rmNode);
void RBTDeletionFixUP(RBTNode **treeRoot,RBTNode * n);

RBTNode * RBTFindNode(RBTNode * node,valueType key,int (*comparator)(valueType,valueType));
RBTNode * RBTFindNodeOnCondition(RBTNode * node,valueType key,int (*comparator)(valueType,valueType));

void RBTDestroyNode(RBTNode * root);
void RBTDestroyTree(RBTNode * treeRoot);
void RBTDestroyAllNodes(RBTNode * treeRoot);
void RBTDestroyTreeAndData(RBTNode * treeRoot,void (*destructor)(Pointer data));

void RBTPrintTree(RBTNode * treeRoot,void (*printData)(Pointer data));

void RBTFindNodesBetweenKeys(RBTNode * node,int * counter,valueType key1,valueType key2,char * funValue,int (*comparator)(valueType,valueType),int (*function)(Pointer,String));
void RBTPrintTreeOnCondition(RBTNode * node,void (*printData)(Pointer data),int (*condition)(Pointer,String));

void destroyDataStructures();
void initializeDataStructures();
