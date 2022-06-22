#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../include/Comparators.h"

int compare_ints(ConstPointer a, ConstPointer b) {
	return *(int*)a - *(int*)b;
}

int compare_str(ConstPointer str1,ConstPointer str2){
    return strcmp((String) str1,(String) str2);
}

int compare_longs(ConstPointer long1,ConstPointer long2){
	return (*(long *) long1 - *(long *) long2);
}

int compare_floats(ConstPointer float1,ConstPointer float2){
	return (*(float *) float1 - *(float *) float2);
}


// Date format: dd-mm-yyyy
int compare_dates(ConstPointer date1,ConstPointer date2){

	String d1 = (String) date1;
	String d2 = (String) date2;

	if(!strcmp(date2,"--"))
		return 0;

	String token;
	int d[2],m[2],y[2];

	for(int i=0;i<2;i++){
		int t=0;
		char buffer[20];
		if(i==0) strcpy(buffer,d1);
		else     strcpy(buffer,d2);

		token = strtok(buffer,"-");
		while(token!=NULL){
			if(t==0)		d[i] = atoi(token);
			else if(t==1)	m[i] = atoi(token);
			else if(t==2)	y[i] = atoi(token);
			token = strtok(NULL,"-");
			t++;
		}
	}

	if(y[0]>y[1])
		return 1;
	else if(y[0]<y[1])
		return -1;
	else{
		if(m[0]>m[1])
			return 1;
		else if(m[0]<m[1])
			return -1;
		else{
			if(d[0]>d[1])
				return 1;
			else if(d[0]<d[1])
				return -1;
			else
				return 0;
		}
	}
}
