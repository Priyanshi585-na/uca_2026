#include <stdio.h>

int my_strlen(char* str){
	int len = 0;
	int i = 0;
	while(str[i]){
		len++;
		i++;
	}
	return len;
}

int main(){
	char str[100];
	fgets(str, sizeof(str), stdin);
	int len = my_strlen(str);
	printf("%d\n", len);
}
