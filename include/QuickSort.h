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
typedef const void* ConstPointer;

void quicksort(Pointer* array,int p,int r,int (*compare)(ConstPointer,ConstPointer));
int partition(Pointer* array,int p,int r,int (*compare)(ConstPointer,ConstPointer));