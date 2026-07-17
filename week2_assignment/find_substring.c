#include<stdio.h>

int find_substring(char* haystack, char* needle){
	int i = 0;
	while(haystack[i]){
		int k = i;
		int j = 0;
		while(needle[j] && haystack[k] && haystack[k] == needle[j]){
			j++;
			k++;
		}	

		if(!needle[j]) return i;
		i++;
	}

	return -1;
}

int main(){
	char haystack[100];
	char needle[100];

	fgets(haystack, sizeof(haystack), stdin);

	int len = 0;
	while(haystack[len])len++;
	if(len > 0 && haystack[len-1] == '\n') haystack[len - 1] = '\0';


	fgets(needle, sizeof(needle), stdin);

	len = 0;
	while(needle[len]) len++;
	if(len > 0 && needle[len-1] == '\n') needle[len - 1] = '\0';
	
	int idx = find_substring(haystack, needle);
	printf("%d\n", idx);
}
