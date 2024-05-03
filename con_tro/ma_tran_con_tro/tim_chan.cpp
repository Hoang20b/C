#include<stdio.h>
#include<stdlib.h>
void nhap_matran(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", a + (i * m + j));
		}
	}
}
int chan_dau(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) % 2 == 0) {
				return *(a + (i * m + j));
			}
		}
	}
	return -1;
}
int chan_cuoi(int *a , int n , int m) {
	int chan;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) % 2 == 0) {
				chan = *(a + (i * m + j));
			}
		}
	}
	return chan;
}
int main() {
	int *a , n , m;
	scanf("%d%d", &n , &m);
	a = (int *) malloc((n * m) * sizeof(int));
	nhap_matran(a,n,m);
	if(chan_dau(a,n,m) == -1) {
		printf("Not Found");
	} else {
		printf("%d\n%d", chan_dau(a,n,m) , chan_cuoi(a,n,m));
	}
	return 0;
}
