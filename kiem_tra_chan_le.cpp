#include<stdio.h>
int chan_le(int n) {
	if(n % 2 == 0) {
		return 1;
	} 
	return 0;
}
int main() {
	int n;
	printf("nhap so n can kiem tra tinh chan le: ");
	scanf("%d", &n);
	if(chan_le(n)) {
		printf("chan");
	} else {
		printf("le");
	}
}
