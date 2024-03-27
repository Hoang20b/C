#include<stdio.h>
#include<math.h>
// dua so vao 1 mang va vi tri cua mang se la so de sang
int so[1000001];
void sang() {
	// cho tat ca cac gia tri deu la so nguyen so
	for(int i = 0; i <= 1000000;i++) {
		so[i] = 1;
	}
	// 2 truong hop dac biet can loc thu cong
	so[0] = so[1] = 0;
	for(int i = 2; i <= 1000; i++) {
		//xac dinh i la so nguyen to va nhung so chia het cho i khong phai so nguyen to;
		for(int j = i * i; j <= 1000000; j += i) {
			if(so[j]) {
				so[j] = 0;
			}
		}
	}
}
int main() {
	//goi ham sang
	sang();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		//thuc hien in ra
		if(so[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}
