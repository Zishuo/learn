#include <stdio.h>


//doesn't work
void swap_1(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

//doesn't work
void swap_2(int *a, int *b){
	int *temp = a;
	a = b;
	b = temp;
}

//work
void swap_3(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(int argc, char * argv[]){
	int a,b;
	scanf("%d %d", &a,&b);
	printf("before swap : %d %d\n", a,b);

	swap_1(a,b);
	printf("swap_1 : %d %d\n", a,b);
	swap_2(&a,&b);
	printf("swap_2 : %d %d\n", a,b);
	swap_3(&a,&b);
	printf("swap_3 : %d %d\n", a,b);

	return 0;
}
