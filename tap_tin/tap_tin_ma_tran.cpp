#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void sinh_mang(int *a , int n, int m) {
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			*(a + (i * m + j)) = rand() % 100;
		}
	}
}
void ghifile(FILE *f , int *a , int n , int m) {
	f = fopen("test.txt", "w");
	if(f == NULL) {
		printf("khong mo file");
		return;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			fprintf(f, "%d ", *(a + (i * m + j)));
		}
		fprintf(f, "\n");
	}
	fclose(f);
}
void docfile(FILE *f, int *a , int n , int m) {
	f = fopen("test.txt", "r");
	if(f == NULL) {
		printf("khong mo file");
		return;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			fscanf(f, "%d", a + (i * m + j));
		}
	}
	fclose(f);
}
void xuat_mang(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			printf("%d ", *(a + (i * m + j)));
		}
		printf("\n");
	}
}
int main() {
	int *a , *b , n , m;
	FILE *f;
	scanf("%d%d", &n , &m);
	a = (int *) malloc(n * m * sizeof(int));
	b = (int *) malloc(n * m * sizeof(int));
	sinh_mang(a,n,m);
	ghifile(f,a,n,m);
	docfile(f,b,n,m);
	xuat_mang(b,n,m);
	return 0;
}
