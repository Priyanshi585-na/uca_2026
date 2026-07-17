#include <stdio.h>

int sumofevens(int n){
	if(n < 2) return 0;

	int even1 = 2;
	int even2 = 8;
	int sum = even1;

	while (even2 <= n){
		sum = sum + even2;

		int temp = even2;
		even2 = 4*even2 + even1;
		even1 = temp;
	}	

	return sum;
}

int main(){
	int n;
 	scanf("%d", &n);

	int sum = sumofevens(n);
	printf("Sum of evens: %d", sum);
	return 0;
}
