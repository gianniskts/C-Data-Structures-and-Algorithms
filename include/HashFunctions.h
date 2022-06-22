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

typedef char* String;
typedef void* Pointer;
typedef const void* ConstPointer;


/* Function for finding the first prime number inside [min,max] */
unsigned int firstPrime(unsigned int min,unsigned int max);

/* String hashing */
unsigned int StringHashFunction_RS(String str);
unsigned int StringHashFunction_BKDR(String str);
unsigned int StringHashFunction_DEK(String str);

