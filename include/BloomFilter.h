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

#include "./HashFunctions.h"

typedef char* String;

typedef struct BloomFilter{

	String bitArray;
	unsigned int size;

}BF;

// Get size
unsigned int size_of_bitArray(unsigned int numOfVoters);

// BloomFilter functions
BF * createBF(unsigned int size);
void insertBF(BF * bf, String identity);
int checkBF(BF * bf, String identity);
void destroyBF(BF * bf);

// Bit-Array functions
void setBit(BF * bf,int hash);
int checkBit(BF * bf,unsigned int hash);
