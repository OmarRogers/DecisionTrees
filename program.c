#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	char aux_array[100] = {'*'};
	int flag = 1;
	int flag2 = 1;
	int flag3 = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	int comas = 0;
	int option = 0;
	int number_attributes = 0;
	char numbers_attributes_posibilities[10] = {1};
	char dataset[100][100][100] = {'*'};
	int counter = 0;
	char tree[100][100] = {'*'};
	char splitted[100][100] = {'*'};
	char options[100][100][100] = {'*'};
	float entropy = 0;
	int repeated = 0;
	
	while(flag==1) {
		fgets(aux_array,100,stdin);
		if (aux_array[0]=='@' && aux_array[1]=='a') {
			flag2 = 1;
			for (i=0; i<strlen(aux_array); i++) {
				if (aux_array[i]==',') {
					numbers_attributes_posibilities[number_attributes]++;
				}
				if (aux_array[i]==' ' && flag2==1) {
					for (j=i; j<strlen(aux_array); j++) {
						if (aux_array[j]==' ') {
							flag2 = 0;
							break;
						}
						counter++;
					}
					for (k=0; k<counter-1; k++) {
						dataset[m][n][k] = aux_array[i+1+k];
					}
					counter = 0;
					n++;
				}
			}
			number_attributes++;
		}
		if ((aux_array[0]>='A' && aux_array[0]<='Z') || (aux_array[0]>='a' && aux_array[0]<='z')) {
			n = 0;
			comas = 0;
			for (i=0; i<strlen(aux_array); i++) {
				if (aux_array[i]==',') {
					comas++;
					for (j=i-counter, k=0; j<i; j++, k++) {
						dataset[m][n][k] = aux_array[j];
						n++;
					}
					counter = -1;
				}
				counter++;
			}
			for (i=0; i<strlen(aux_array); i++) {
				if (aux_array[i]==',') {
					comas--;
					if (comas==0) {
						for (j=i+1, k=0; j<strlen(aux_array); j++, k++) {
							dataset[m][n][k] = aux_array[j];
						}
					}
				}
			}
			m++;
		}
		for (i=0; i<n; i++) {
			option = 0;
			for (j=1; j<m; j++) {
				flag3 = 0;
				for (k=0; k<100; k++) {
					if (strcmp(options[k][i],dataset[j][i])==0) {
						flag3 = 1;
					}
				}
				if (flag3==0) {
					strcpy(options[option][i],dataset[j][i]);
					option++;
				}
			}
		}
		for (i=0; i<n-1; i++) {
			for (j=0; j<numbers_attributes_posibilities[i]; j++) {
				for (k=1; k<m; k++) {
					if (strcmp(options[j][i],dataset[k][i])==0) {
						repeated++;
					}
				}
				entropy = -(repeated/((float)(m-1)))*log2(repeated/((float)(m-1)));
			}
			
		}
		for (i=0; i<100; i++) {
			if (aux_array[i]==EOF) {
				flag = 0;
			}
		}
	}
	
	return 0;
}
