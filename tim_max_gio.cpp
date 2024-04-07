#include<stdio.h>
#include<math.h>
void tim_time(int a[]) {
	int gio_dau = 0;
	int gio_sau = 0;
	int phut_dau = 0;
	int phut_sau = 0;
	int check = 0;
	//kiem tra xem co so be hon bang 2 de lam gio dau tien khong
	for(int i = 0; i < 4; i++) {
		if(a[i] <= 2) {
			check = 1;
		}
	}
	//kiem tra neu khong co so nao dat yeu cau cho gio dau thi in -1 va ket thuc ham
	if(!check) {
		printf("%d", -1);return;
	}
	//tim gia tri gio dau
	for(int i = 0; i < 4; i++) {
		if(gio_dau < a[i] && a[i] <= 2) {
			gio_dau = a[i];
		}
	}
	//xoa gia tri gio dau nam trong mang
	for(int i = 0;i < 4; i++) {
		if(a[i] == gio_dau) {
			for(int j = i; j < 4; j++) {
				a[j] = a[j + 1];
			}
			break;
		}
	}
	check = 0;
	//neu gio dau == 2 thi cac gio sau chi chay toi 4. Neu khong no se chay tu 0-9
	if(gio_dau == 2) {
		for(int i = 0; i < 3; i++) {
			if(a[i] <= 4) {
				check = 1;
			}
		}
	} else {
		check = 1;
	}
	if(!check) {
		printf("%d", -1);return;
	}
	//neu gio dau == 2 thi gio sau max se la 3 . Boi vi 23h la thoi diem lon nhat trong ngay
	if(gio_dau == 2) {
		for(int i = 0; i < 3; i++) {
			if(a[i] > gio_sau && a[i] <= 3) {
				gio_sau = a[i];
			}
		}
	} else { //neu gio dau be hon 2 thi gio sau max se la 9
		for(int i = 0; i < 3; i++) {
			if(a[i] > gio_sau) {
				gio_sau = a[i];
			}
		}
	}
	//sau khi thuc hien tim gio sau se xoa gio sau khoi mang
	for(int i = 0; i < 3; i++) {
		if(a[i] == gio_sau) {
			for(int j = i; j < 3; j++) {
				a[j] = a[j + 1];
			}
			break;
		}
	}
	//kiem tra xem phut dau co giao dong tu 0 - 5 khong 
	check = 0;
	for(int i = 0; i < 2; i++) {
		if(a[i] <= 5) {
			check = 1;
		}
	}
	if(!check) {
		printf("%d", -1);return;
	}
	//tim so phut dau lon nhat giao dong tu 0 - 5
	for(int i = 0; i < 2; i++) {
		if(a[i] > phut_dau && a[i] <= 5) {
			phut_dau = a[i];
		}
	}
	//thuc hien xoa phut dau sau khi tim thay khoi mang
	for(int i = 0; i < 2; i++) {
		if(a[i] == phut_dau) {
			for(int j = i; j < 2; j++) {
				a[j] = a[j + 1];
			}
			break;
		}
	}
	//so cuoi cung se la phut sau
	phut_sau = a[0];
	printf("%d%d:%d%d", gio_dau , gio_sau , phut_dau , phut_sau);
}
int main() {
	int a , b , c , d;
	scanf("%d%d%d%d", &a , &b , &c , &d);
	int arr[4] = {a,b,c,d};
	tim_time(arr);
	return 0;
}
