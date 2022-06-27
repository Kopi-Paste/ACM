#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LENGTH 200001
 
 
int * prepareArray(){
	int * retValue = (int *)malloc(sizeof(int) * MAX_LENGTH);
	memset(retValue, 0, sizeof(int) * MAX_LENGTH);
	return retValue;
}
 
void setIntervals(int * arr, int intervals){
	int start, end;
	for (int i = 0; i < intervals; i++){
		scanf(" %d %d ", &start, &end);
		arr[start] += 1;
		arr[end + 1] += -1;
	}
}
 
void setCorrectTempratures(int * arr, int required){
	int counter = 0;
	int correctCounter = 0;
	for (int i = 0; i < MAX_LENGTH; i++){
		counter += arr[i];
		if (counter >= required)
			correctCounter++; 
		arr[i] = correctCounter;
	}
}
 
void acceptQueries(int * arr, int queries){
	int start, end;
	for (int i = 0; i < queries; i++){
		scanf(" %d %d ", &start, &end);
		printf("%d\n", arr[end] - arr[start - 1]);
	}
}
 
int main(){
	int * tempratures = prepareArray();
	int intervals, required, queries;
	scanf(" %d %d %d ", &intervals, &required, &queries);
	setIntervals(tempratures, intervals);
	setCorrectTempratures(tempratures, required);
	acceptQueries(tempratures, queries);
	free(tempratures);
	return 0;
}