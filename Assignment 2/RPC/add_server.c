/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "add.h"
#include <unistd.h>
char **
getpath_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;
	result = getcwd(0, 0);
	printf("sending back the path \n");
	return &result;
}

sortList *
sort_1_svc(sortList *argp, struct svc_req *rqstp)
{
	static sortList result;
	
	int i,j;
	int temp1, temp2;
	int n = argp->listSize;
	// bubble sort to sort the list
	for(i=0;i<n;i++){
		for(j=i+1; j<n; j++){
			if(argp->list[i] > argp->list[j]) {
            temp1 = argp->list[i];
			temp2 = argp->list[j];
            argp->list[i] = temp2;
            argp->list[j] = temp1;
			}
		}
		// setting the sorted values to resultant list
		result.sortedList[i]=argp->list[i];
	}
	
	printf("sending back the sorted list \n");
	result.listSize = n;
	return &result;
}

char **
printecho_1_svc(serverEcho *argp, struct svc_req *rqstp)
{
	static char * result;
	// accessing the echo member from the struct argp
	result =argp->echo;
	printf("Echo from the client :%s \n",argp->echo);
	return &result;
}


char **
isfileexist_1_svc(checkFile *argp, struct svc_req *rqstp)
{
	static char * result;
	char fname[1000];
	// copying in passed string into fname
	strcpy(fname,argp->fname);
	// using file concept, if you can open then file then file exists, else it does not
	FILE * file;
	file = fopen(fname,"r");
	if(file){
			result = "file found";
	} else {
			result = "file not found";
	}
	
	printf("sending back file status \n");
	return &result;
}


matrixMultiplication *
mmultiply_1_svc(matrixMultiplication *argp, struct svc_req *rqstp)
{
	static matrixMultiplication  result;
	int row = argp->row;
	int col = argp->col;
	result.row = row;
	result.col = col;
	int i,j,k;
	//matrix multiplication
	
	for(i=0; i< row; i++){
		for(j=0; j<col; j++){
			int sum=0;
			for(k=0; k<row; k++){
				sum += argp->matrix1[i*col+k] * argp->matrix2[k*col+j];
				result.resultMatrix[i*col+j] = sum;
			}
		}
	}
	
	printf("sending back result matrix\n");
	return &result;
}