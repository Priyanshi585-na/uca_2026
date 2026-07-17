#include <stdio.h>

void reverse_string(char* str){
	int len = 0;
	while(str[len]){
		len++;
	}

	int left = 0;
	int right = len-1;

	while(left <= right){
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;

		left++;
		right--;
	}
}

int main(){
	char str[100];
	fgets(str, sizeof(str), stdin);
	reverse_string(str);
	printf("%s\n", str);
}
