#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char aux_array[100] = {'*'};
	int flag = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	int number_attributes = 0;
	char numbers_attributes_posibilities[10] = {1};
	char dataset[100][100][100] = {'*'};
	int counter = 0;
	
	while(flag==1) {
		fgets(aux_array,100,stdin);
		if (aux_array[0]=='@' && aux_array[1]=='a') {
			for (i=0; i<strlen(aux_array); i++) {
				if (aux_array[i]==',') {
					numbers_attributes_posibilities[number_attributes]++;
				}
				number_attributes++;
				if (aux_array[i]==' ') {
					for (j=i; j<strlen(aux_array); j++) {
						if (aux_array[j]==' ') {
							break;
						}
						counter++;
					}
					for (k=0; k<counter; k++) {
						dataset[m][n][k] = aux_array[i+1+k];
					}
					counter = 0;
					m++;
				}
				if (aux_array[i]=='{') {
					for (j=i; j<strlen(aux_array); j++) {
						if (aux_array[j]==',') {
							break;
						}
						counter++;
					}
					for (k=0; k<counter; k++) {
						dataset[m][n][k] = aux_array[i+1+k];
					}
					counter = 0;
					m++;
				}
				if (aux_array[i]==',') {
					for (j=i; j<strlen(aux_array); j++) {
						if (aux_array[j]==',' || aux_array[j]=='}') {
							break;
						}
						counter++;
					}
					for (k=0; k<counter; k++) {
						dataset[m][n][k] = aux_array[i+2+k];
					}
					counter = 0;
					m++;
				}
			}
			n++;
		}
		for (i=0; i<100; i++) {
			if (aux_array[i]==EOF) {
				flag = 0;
			}
		}
	}
	
	return 0;
}
