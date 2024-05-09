#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
long long int myWallet = 2000000;
void menu(int &chon) {
	printf("chon danh muc: \n");
	printf("1.Mua hang\n2.Gio hang\n3.Thanh toan\n4.Kiem tra so du\n5.Nap tien\n6.Bo hang ra khoi gio\n0.Thoat...\n");
	scanf("%d", &chon);
}
void danhMucMuaHang(int &butChi , int &thuocKe , int &hopBut) {
	int chon;
	int sl;
	do {
		printf("1. But chi - 10000 VND\n2. Thuoc ke - 20000 VND\n3.Hop but - 30000 VND\n0.Tro lai\n");
		scanf("%d", &chon);
		switch(chon) {
			case 1:				
				printf("Nhap so but ban muon them: ");scanf("%d", &sl);
				butChi += sl;
				printf("!!!Da them thanh cong %d but chi!!!\n", sl);
				break;
			case 2:
				printf("Nhap so thuoc ke ban muon them: ");scanf("%d", &sl);
				thuocKe += sl;
				printf("!!!Da them thanh cong %d thuoc ke!!!\n", sl);
				break;
			case 3:
				printf("Nhap so hop but ban muon them: ");scanf("%d", &sl);
				hopBut += sl;
				printf("!!!Da them thanh cong %d hop but!!!\n", sl);
				break;
			case 0:
				break;
			default:
				chon = 0;break;
		}
	} while(chon);
}
void gio_hang(int butChi , int thuocKe , int hopBut) {
	printf("======Gio hang cua ban======\n");
	printf("%d but chi: %lld VND\n%d thuoc ke: %lld VND\n%d hop but: %lld VND\n", butChi ,butChi * 10000LL , thuocKe , thuocKe * 20000LL,hopBut, hopBut * 30000LL);
	printf("Tong thanh toan: %lld VND\n", (butChi * 10000) + (thuocKe * 20000) + (hopBut * 30000));
	printf("============================\n");
}
void thanhToan(int &butChi , int &thuocKe , int &hopBut) {
	long long int tong = (butChi * 10000) + (thuocKe * 20000) + (hopBut * 30000);
	if(tong == 0) {
		printf("Ban chua mua!!\n");return;
	}
	if(tong > myWallet) {
		printf("Thanh toan that bai!! So du khong du hay bo bot do\n");
	} else {
		printf("!!Thanh toan Thanh Cong!!\n");
		myWallet -= tong;
		butChi = 0; thuocKe = 0; hopBut = 0;
	}
}
void checkWallet() {
	printf("############So du############\nSo du cua ban la: %lld VND\n##############################\n", myWallet);
}
void deposite() {
	printf("ngan hang ViettinBank\nSTK: 123456789\nChu TK: NGUYEN HUY HOANG\n");
	int chon;
	long long int tienNap;
	char maXn[100];
	printf("Ban da nap chua: \n1. Xac nhan\n0. Huy\n");scanf("%d", &chon);
	if(chon) {
		printf("nhap so tien can nap: ");scanf("%lld", &tienNap);
		getchar();
		printf("nhap ma giao dich: "); //quy dinh la "abc123"
		gets(maXn); //O duoi se co thuat toan doi chieu!!!CHUA BIET LAM.
		/*
		if(maXN.....) {
			printf("Ban da nap thanh cong");
			myWallet += tienNap;
		}
		*/
		if(strcmp(maXn,"abc123") == 0) {
			myWallet += tienNap;
			printf("Nap tien thanh cong!!!\n\n");
		} else {
			printf("Nap tien that bai\n\n");
		}
	} else {
		printf("Ban chon khong thanh toan\n");
		return; //de cho dep !! lenh khong can thiet
	}
}
void removeFromCart(int &butChi , int &thuocKe , int &hopBut) {
	int chon;
	printf("Hay chon mon hang muon bo ra\n");
	do {
		printf("1.But chi\n2.Thuoc ke\n3.Hop but\n0.Tro lai...\n\n");
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				if(butChi) {
					butChi = 0;
					printf("Da bo but chi ra khoi gio hang cua ban\n");
				} else {
					printf("Ban chua them but chi\n");
				}
				break;
			case 2:
				if(thuocKe) {
					thuocKe = 0;
					printf("Da bo thuoc ke ra khoi gio hang cua ban\n");
				} else {
					printf("Ban chua them thuoc ke\n");
				}
				break;
			case 3:
				if(hopBut) {
					hopBut = 0;
					printf("Da bo hop but ra khoi gio hang cua ban\n");
				} else {
					printf("Ban chua them hop but\n");
				}
				break;
			default:
				printf("khong nhap linh tinh\n");
				chon = 0;
		}
	} while(chon);
}
int main() {
	int chon;
	int butChi = 0;
	int thuocKe = 0;
	int hopBut = 0;
	do {
		menu(chon);
		switch(chon) {
			case 1: 
				danhMucMuaHang(butChi,thuocKe,hopBut);
				break;
			case 2:
				gio_hang(butChi,thuocKe,hopBut);
				break;
			case 3:
				thanhToan(butChi,thuocKe,hopBut);
				break;
			case 4:
				checkWallet();
				break;
			case 5:
				deposite();
				break;
			case 6:
				removeFromCart(butChi , thuocKe , hopBut);
				break;
			case 0:
				break;
			default:
				printf("khong duoc chon cac so khac trong danh sach!!Chuong trinh se duoc dung lai\n");
				chon = 0;
		}
	} while(chon);
	printf("chuong trinh ket thuc");
	return 0;
}
//CODE CHUA HOAN THIEN

