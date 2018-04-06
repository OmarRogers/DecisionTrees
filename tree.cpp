//Juan Carlos Gama
//Omar Martinez

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;

struct Data{
	Data *pntr;
	char type[50];
	char value[50][50];
};

int main(int argc, char const *argv[])
{
	Data * head = new Data;
	Data * pointer = head;
	//counts number of nodes
	int types=1;
	char parser[1024] = {'*'};
	//ignore comments
	fgets(parser,1024, stdin);
	while(parser[0]=='%'){
		//fill nodes
		char node_names[1024] = {'*'};
		fgets(parser, 1024, stdin);
	}
	if(parser[0]=='@' && parser[1]=='r'){
		fgets(parser,1024, stdin);
		while(parser[0]!='@'){
			fgets(parser,1024, stdin);
		}
	}
	int flag=0;
	bool mark=false;
	//save data type
	while(parser[0]!=' '||(parser[0]!='@'&& parser[1]!='d')){
		for(int i=0;i<1024;i++){
			if(parser[i]==' '){
				if(mark){
					pointer->type[flag]=parser[i];
					flag++;
				}
				mark=true;
				if(parser[i+1]==' '){
					Data * aux = new Data;
					types++;
					pointer->pntr = aux;
					pointer = aux;
					aux=NULL;
					fgets(parser,1024,stdin);
					i=1025;
				}
			}
		}
		flag=0;
		mark=false;
	}
	
	while(parser[0]!='@' && parser[1]!='d'){
		fgets(parser,1024,stdin);
	}
	int x=0;
	bool kek=true;
	while(kek){

		if(fgets(parser,1024,stdin)==NULL){
			kek=false;
		}else{
			int y=0;
			Data * node = head;
			for(int z=0; z<types;z++){

				while(parser[y]!=','||parser[y]!='\n'){
					node->value[y][x] = parser[y];
					y++;
				}
				node = node->pntr;
			}
		}
		x++;
	}

	return 0;
}