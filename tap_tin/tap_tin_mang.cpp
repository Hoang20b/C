#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sinh_mang(FILE *f , int n) {
	f = fopen("test.txt", "w");
	if(f == NULL) {
		printf("khong mo file");
		return;
	}
	srand(time(NULL));
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++) {
		fprintf(f, "%d ", rand() % 100);
	}
	fclose(f);
}
void nhap_mang(FILE *f , int *a , int n) {
	f = fopen("test.txt", "r");
	if(f == NULL) {
		printf("khong mo file");
		return;
	}
	fscanf(f, "%d", &n);
	for(int i = 0; i < n; i++) {
		fscanf(f , "%d", a + i);
	}
}
void xuat_mang(int *a , int n) {
	for(int i = 0; i < n ; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a , n;
	FILE *f;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	sinh_mang(f,n);
	nhap_mang(f,a,n);
	xuat_mang(a,n);
	return 0;
}
