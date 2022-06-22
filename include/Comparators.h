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

#define empty NULL

typedef void* Pointer;
typedef const void* ConstPointer;

int compare_ints(ConstPointer a, ConstPointer b);
int compare_str(ConstPointer str1,ConstPointer str2);
int compare_longs(ConstPointer long1,ConstPointer long2);
int compare_floats(ConstPointer float1,ConstPointer float2);
int compare_dates(ConstPointer date1,ConstPointer date2);  // dd-mm-yyyy
