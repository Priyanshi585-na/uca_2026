#include <stdio.h>

void url_encoder(char *str, int true_length){
	int spaces = 0;

	int i = 0;
	while(i < true_length){
		if(str[i] == ' ') spaces++;
		i++;
	}

	i = true_length - 1;
	int j = true_length + spaces*2 -1;

	str[j + 1] = '\0';

	while(i >= 0){
		if(str[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else str[j--] = str[i];

		i--;
	}
}

int main(){
     char str[100] = "Hello World";
     url_encoder(str, 11);
     printf("%s\n", str);
     return 0;
}
