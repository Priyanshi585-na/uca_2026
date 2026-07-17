#include <stdio.h>

char* my_strtok(char* str, char delim){
	
	static char* next;

	if(str != NULL) next = str;

	if(next == NULL) return NULL;

	char *start = next;

	while(*next != '\0' && *next != delim){
		next++;
	}

	if(*next == delim){
		*next = '\0';
		next++;
	}
	else{
		next = NULL;
	}

	return start;
}

int main(){
	char s[] = "C,C++,Java,Python,Rust";
	char *token = my_strtok(s, ',');
	
	while(token != NULL){
		printf("%s\n",token);
		token = my_strtok(NULL, ',');
	}
}
