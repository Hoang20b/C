#include<stdio.h>
//chuong trinh duoc xay dung nham tinh ty gia gia tri cac tien ngoai te pho bien cua Viet Nam 14/4/2024
//ham chuyen doi usd qua vnd
void usdtovnd() {
	float sl_usd;
	int tygia = 25000;
	printf("nhap so tien usd muon doi qua vnd: ");scanf("%f", &sl_usd);
	long long int ket_qua = (int) (sl_usd * tygia);
	printf("%lld vnd\n", ket_qua);
}
void ndttovnd() {
	float sl_ndt;
	int tygia = 3500;
	printf("nhap so tien ndt muon doi sang vnd: ");scanf("%f", &sl_ndt);
	long long int ket_qua = (int) sl_ndt * tygia;
	printf("%lld vnd\n", ket_qua);
}
void yentovnd() {
	float sl_yen;
	int tygia = 165;
	printf("nhap so yen muon doi sang vnd: ");scanf("%f", &sl_yen);
	long long int ket_qua = (int) sl_yen * tygia;
	printf("%lld vnd\n", ket_qua);
}
void wontovnd() {
	float sl_won;
	int tygia = 18;
	printf("nhap so won muon doi sang vnd: ");scanf("%f", &sl_won);
	long long int ket_qua = (int) sl_won * tygia;
	printf("%lld vnd\n", ket_qua);
}
void eurotovnd() {
	float sl_euro;
	int tygia = 27000;
	printf("nhap so euro muon doi sang vnd: ");scanf("%f", &sl_euro);
	long long int ket_qua = (int) sl_euro * tygia;
	printf("%lld vnd\n", ket_qua);
}
void menu(int &chon) {
	printf("1.doi USD qua VND\n");
	printf("2.doi NDT qua VND\n");
	printf("3.doi YEN qua VND\n");
	printf("4.doi WON qua VND\n");
	printf("5.DOI EURO qua VND\n");
	printf("0.Thoat...\n");
	scanf("%d", &chon);
}
int main() {
	int chon;
	printf("hay nhap so tien ban muon tim:\n");
	do {
		menu(chon);
		switch(chon) {
			case 1:
				usdtovnd();
				break;
			case 2:
				ndttovnd();
				break;
			case 3:
				yentovnd();
				break;
			case 4:
				wontovnd();
				break;
			case 5:
				eurotovnd();
				break;
			default:
				chon = 0;
		}
	} while(chon != 0);
	return 0;
}
