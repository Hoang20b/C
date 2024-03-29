#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham kiem tra so chinh phuong
int scp(int n) {
	if(sqrt(n) == (int) sqrt(n)) {
		return 1;
	}
	return 0;
}
//ham liet ke so chinh phuong o vi tri le
void scp_vt_le(int a[], int n) {
	//bien check = 0 khi chua tim thay ket qua
	int check = 0;
	for(int i = 0; i < n; i++) {
		if(scp(a[i]) && i % 2 != 0) {
			printf("%d ", a[i]);
			check = 1;
		}
	}
	//kiem tra neu khong co thi in ra None
	if(!check) {
		printf("None");
	}
}
int main() {
	int a[100], n;
	scanf("%d", &n);
	nhap_mang(a,n);
	scp_vt_le(a,n);
	return 0;
}
