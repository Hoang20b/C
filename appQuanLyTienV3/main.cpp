#include<stdio.h>
#include<string.h>
/*
hoaDon.txt
hoaDonTienMat.txt
hoaDonNganHang.txt
hoaDonMomo.txt
wallet.txt
nganHangViettinBank.txt
nganHangVietcomBank.txt
momo.txt
tongChi.txt
*/
int len(char *kt) {
	int count = 0;
	while(*(kt + count) != 0)
		count++;
	return count;
}
void copyString(char *ktGoc, char *kt, int soKyTu) {
	for(int i = 0; i < soKyTu; i++) {
		*(kt + i) = *(ktGoc + i);
	}
	*(kt + soKyTu) = '\0';
}
void xuLyNgay(char *kt) {
	int kichThuoc = len(kt);
	for(int i = 0; i < kichThuoc; i++)	
		if(*(kt + i) == '-' || *(kt + i) == ' ')
			*(kt + i) = '/';
}
void updateSoDuNganHang(char *tenNganHang, int soDu) {
	FILE* f = fopen(tenNganHang, "w");
	fprintf(f, "%d", soDu);
	fclose(f);
}
void updateSoDuTienMat(int soDu) {
	FILE* f = fopen("wallet.txt", "w");
	fprintf(f, "%d", soDu);
	fclose(f);
}
void updateSoDuMomo(int soDu) {
	FILE* f = fopen("momo.txt", "w");
	fprintf(f, "%d", soDu);
	fclose(f);
}
void updateTongChi(int tongChi) {
	FILE* f = fopen("tongChi.txt", "w");
	fprintf(f, "%d", tongChi);
	fclose(f);
}
void ghiHoaDonChiTieu(char *ngayTieu, int soTien, char *noiDung, char *hinhThuc) {
	FILE* f = fopen("hoaDon.txt", "a");
	fprintf(f, "%s: %d | %s\n", ngayTieu, soTien, noiDung);
	fclose(f);
}
void ghiHoaDonTienMat(char *ngayTieu, int soTien, char *noiDung, char tinhTrang) {
	FILE* f = fopen("hoaDonTienMat.txt", "a");
	fprintf(f, "%s: %c%d | %s\n", ngayTieu, tinhTrang, soTien, noiDung);
	fclose(f);
}
void ghiHoaDonNganHang(char *ngayTieu, int soTien, char *noiDung, char *tenNganHang, char tinhTrang) {
	FILE* f = fopen("hoaDonNganHang.txt", "a");
	fprintf(f, "%s: %c%d | %s | %s\n", ngayTieu, tinhTrang, soTien, tenNganHang, noiDung);
	fclose(f);
}
void ghiHoaDonMomo(char *ngayTieu, int soTien, char *noiDung, char tinhTrang) {
	FILE* f = fopen("hoaDonMomo.txt", "a");
	fprintf(f, "%s: %c%d | %s\n", ngayTieu, tinhTrang, soTien, noiDung);
	fclose(f);
}
void menuTenNganHang() {
	printf("1. ViettinBank\n");
	printf("2. VietcomBank\n");
}
int getTienNganHang(char* tenNganHang) {
	FILE* f = fopen(tenNganHang, "r");
	int tien;
	fscanf(f, "%d", &tien);
	fclose(f);
	return tien;
}
//tienMat.
void guiTienNganHang() {
	FILE* wallet = fopen("wallet.txt", "r");
	int tienMat, tienNganHang, tienGui, chonNganHang;
	char ngayGui[11], tenNganHang[24], tenNH[12];
	char noiDung[] = "Gui ngan hang";
	printf("chon ngan hang ban muon gui tien:\n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		default:
			printf("chon mac dinh ViettinBank\n");
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	fscanf(wallet, "%d", &tienMat);
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban muon gui vao ngan hang: ");
	scanf("%d", &tienGui);
	if(tienGui > tienMat) {
		printf("so du tien mat cua ban khong du\n");
		return;
	}
	getchar();
	printf("nhap ngay gui tien vao ngan hang: ");
	gets(ngayGui);
	xuLyNgay(ngayGui);
	tienMat -= tienGui;
	updateSoDuTienMat(tienMat);
	ghiHoaDonTienMat(ngayGui, tienGui, noiDung,'-');
	tienNganHang += tienGui;
	updateSoDuNganHang(tenNganHang,tienNganHang);
	ghiHoaDonNganHang(ngayGui, tienGui, noiDung, tenNH, '+');
	printf("Gui tien ngan hang thanh cong\n");
	fclose(wallet);
}
void chiTieuTienMat() {
	FILE* wallet = fopen("wallet.txt", "r");
	FILE* tongChi = fopen("tongChi.txt", "r");
	int tienMat, tienTieu, tienTongChi;
	char hinhThuc[] = "Tien mat";
	char noiDungTieu[50], ngayTieu[12];
	fscanf(wallet, "%d", &tienMat);
	fscanf(tongChi, "%d", &tienTongChi);
	printf("nhap so tien da tieu: ");
	scanf("%d", &tienTieu);
	if(tienTieu > tienMat) {
		printf("khong du tien cho chi tieu nay\n");
		return;
	}
	tienTongChi += tienTieu;
	updateTongChi(tienTongChi);
	getchar();
	printf("nhap noi dung tieu: ");
	gets(noiDungTieu);
	printf("nhap ngay tieu: ");
	gets(ngayTieu);
	xuLyNgay(ngayTieu);
	tienMat -= tienTieu;
	updateSoDuTienMat(tienMat);
	ghiHoaDonTienMat(ngayTieu, tienTieu, noiDungTieu, '-');
	ghiHoaDonChiTieu(ngayTieu, tienTieu, noiDungTieu, hinhThuc);
	printf("ghi chi tieu thanh cong\n");
	fclose(wallet);
	fclose(tongChi);
}
//themTienMat.
void rutTienNganHang() {
	FILE* wallet = fopen("wallet.txt", "r");
	int tienMat, tienRut, tienNganHang, chonNganHang;
	char ngayRut[11];
	char tenNganHang[24], tenNH[12];
	char noiDung[] = "Rut tien ngan hang";
	fscanf(wallet, "%d", &tienMat);
	printf("chon ngan hang ban muon rut: \n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			printf("chon ngan hang ViettinBank mac dinh\n");
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp,tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban rut: ");
	scanf("%d", &tienRut);
	if(tienRut > tienNganHang) {
		printf("tai khoan ngan hang %s khong du tien");
		return;
	}
	getchar();
	printf("nhap ngay rut: ");
	gets(ngayRut);
	xuLyNgay(ngayRut);
	tienMat += tienRut;
	updateSoDuTienMat(tienMat);
	ghiHoaDonTienMat(ngayRut, tienRut, noiDung, '+');
	tienNganHang -= tienRut;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayRut, tienRut, noiDung, tenNH, '-');
	printf("Rut tien ngan hang %d VND thanh cong\n", tienRut);
	fclose(wallet);
}
void nhanLuong() {
	FILE* nganHangVietCom = fopen("nganHangVietcomBank.txt", "r");
	char tenNganHang[] = "nganHangVietcomBank.txt";
	int tienNganHang, tienLuong, chot;
	char ngayNhanLuong[11];
	char noiDung[] = "nhan luong";
	fscanf(nganHangVietCom, "%d", &tienNganHang);
	printf("nhap luong ban nhan: ");
	scanf("%d", &tienLuong);getchar();
	printf("nhap ngay nhan luong: ");
	gets(ngayNhanLuong);
	xuLyNgay(ngayNhanLuong);
	printf("ban co chac la chot ngay nhan la ngay %s khong? (1.Co || 0.Khong): ", ngayNhanLuong);
	scanf("%d", &chot);getchar();
	if(!chot) {
		printf("da huy giao dich nhan luong\n");
		return;
	}
	tienNganHang += tienLuong;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayNhanLuong, tienLuong, noiDung, tenNganHang,'+');
	printf("thuc hien giao dich nhan luong %d VND thanh cong vao ngan hang Vietcombank\n", tienLuong);
	fclose(nganHangVietCom);
}

void lyDoThemTienKhac() {
	FILE* wallet = fopen("wallet.txt", "r");
	int tienMat, tienThem;
	char ngay[11], noiDung[50];
	fscanf(wallet, "%d", &tienMat);
	printf("nhap so tien nhan them: ");
	scanf("%d", &tienThem);getchar();
	printf("nhap noi dung nhan tien: ");
	gets(noiDung);
	printf("nhap ngay nhan tien: ");
	gets(ngay);
	xuLyNgay(ngay);
	tienMat += tienThem;
	updateSoDuTienMat(tienMat);
	ghiHoaDonTienMat(ngay, tienThem, noiDung, '+');
	printf("them so tien %d VND thanh cong\n", tienThem);
	fclose(wallet);
}
void menuThemTienMat() {
	printf("1. Rut tien ngan hang\n");
	printf("2. khac\n");
	printf("0. Quay lai...\n");
}
void themTienMat(int chon) {
	do {
		menuThemTienMat();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				rutTienNganHang();
				break;
			case 2:
				lyDoThemTienKhac();
				break;
			default:
				chon = 0;
		}
	} while(chon);
}
void menuTienMat() {
	printf("1. Gui tien ngan hang\n");
	printf("2. Chi tieu\n");
	printf("3. Them tien mat\n");
	printf("0. Quay lai...\n");
}
void tienMat(int chon) {
	do {
		menuTienMat();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				guiTienNganHang();
				break;
			case 2:
				chiTieuTienMat();
				break;
			case 3:
				int chonCase3;
				themTienMat(chonCase3);
				break;
			default:
				chon = 0;
		}
	} while(chon);
}
void RutTienMomo() {
	FILE* momo = fopen("momo.txt", "r");
	int tienNganHang, tienMomo, tienRutTuMomo, chonNganHang;
	char tenNganHang[24], tenNH[12], ngayRut[12];
	char noiDung[] = "Rut tu momo ve ngan hang";
	printf("chon ngan hang:\n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	fscanf(momo, "%d", &tienMomo);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban muon chuyen vao ngan hang %s: ", tenNH);
	scanf("%d", &tienRutTuMomo);getchar();
	if(tienRutTuMomo > tienMomo) {
		printf("Momo cua ban khong du tien de chuyen ve ngan hang\n");
		return;
	}
	printf("nhap ngay thuc hien chuyen tien tu momo ve ngan hang %s: ", tenNH);
	gets(ngayRut);
	xuLyNgay(ngayRut);
	tienNganHang += tienRutTuMomo;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayRut, tienRutTuMomo, noiDung, tenNH, '+');
	tienMomo -= tienRutTuMomo;
	updateSoDuMomo(tienMomo);
	ghiHoaDonMomo(ngayRut, tienRutTuMomo, noiDung, '-');
	printf("thuc hien giao dich chuyen tien tu momo ve ngan hang %s thanh cong\n", tenNH);
	fclose(momo);
}
void nhanChuyenKhoan() {
	int tienNganHang, tienNhan, chonNganHang;
	char ngayNhan[12], tenNganHang[24], tenNH[12];
	char noiDung[] = "Nhan chuyen khoan";
	printf("chon ngan hang da nhan chuyen khoan\n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban da nhan: ");
	scanf("%d", &tienNhan);getchar();
	printf("nhap ngay ban da nhan: ");
	gets(ngayNhan);
	xuLyNgay(ngayNhan);
	tienNganHang += tienNhan;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayNhan, tienNhan, noiDung, tenNH, '+');
	printf("cap nhat giao dich nhan %d vao ngan hang %s thanh cong\n", tienNhan, tenNH);
}
void chuyenTienVaoViMomo() {
	FILE* momo = fopen("momo.txt", "r");
	int tienMomo, tienNganHang, tienVaoMomo, chonNganHang;
	char ngayNap[11], tenNganHang[24], tenNH[12];
	char noiDung[] = "Nap tien vao momo";
	fscanf(momo, "%d", &tienMomo);
	printf("chon ngan hang da nhan chuyen khoan\n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban nap tu ngan hang vao momo: ");
	scanf("%d", &tienVaoMomo);getchar();
	if(tienVaoMomo > tienNganHang) {
		printf("tai khoan ngan hang %s khong du\n", tenNH);
		return;
	}
	printf("nhap ngay nap tien vao momo: ");
	gets(ngayNap);
	xuLyNgay(ngayNap);
	tienNganHang -= tienVaoMomo;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayNap, tienVaoMomo, noiDung, tenNH, '-');
	tienMomo += tienVaoMomo;
	updateSoDuMomo(tienMomo);
	ghiHoaDonMomo(ngayNap, tienVaoMomo, noiDung, '+');
	printf("thuc hien giao dich nap tien tu ngan hang %s vao Momo thanh cong\n", tenNH);
	fclose(momo);
}
void chiTieuNganHang() {
	FILE* tongChi = fopen("tongChi.txt", "r");
	int tienNganHang, tienTieu, tongChiTieu, chonNganHang;
	char hinhThuc[] = "Ngan hang";
	char noiDung[50], ngayTieu[11], tenNganHang[24], tenNH[12];
	fscanf(tongChi, "%d", &tongChiTieu);
	printf("chon ngan hang ban da su dung:\n");
	menuTenNganHang();
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("nhap so tien ban da tieu: ");
	scanf("%d", &tienTieu);
	getchar();
	if(tienTieu > tienNganHang) {
		printf("so du ngan hang %s khong du cho chi tieu nay\n", tenNH);
		return;
	}
	tongChiTieu += tienTieu;
	updateTongChi(tongChiTieu);
	printf("nhap noi dung chi tieu: ");
	gets(noiDung);
	printf("nhap ngay da chi tieu: ");
	gets(ngayTieu);
	xuLyNgay(ngayTieu);
	tienNganHang -= tienTieu;
	updateSoDuNganHang(tenNganHang, tienNganHang);
	ghiHoaDonNganHang(ngayTieu, tienTieu, noiDung, tenNH, '-');
	ghiHoaDonChiTieu(ngayTieu, tienTieu, noiDung, hinhThuc);
	printf("Thuc hien giao dich chi tieu ngan hang thanh cong\n");
	fclose(tongChi);
}
void menuNganHang() {
	printf("1. Gui tien ngan hang\n");//da lam ham nay o phan tien mat.
	printf("2. Chuyen tien Momo vao ngan hang\n");
	printf("3. Nhan chuyen khoan\n");
	printf("4. Nhan luong\n");
	printf("5. Chuyen vao vi Momo\n");
	printf("6. Rut tien mat\n"); // da co ham.
	printf("7. Chi tieu bang ngan hang\n");
	printf("0. Quay lai...\n");
}
void nganHang(int chon) {
	do {
		menuNganHang();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				guiTienNganHang();
				break;
			case 2:
				RutTienMomo();
				break;
			case 3:
				nhanChuyenKhoan();
				break;
			case 4:
				nhanLuong();
				break;
			case 5:
				chuyenTienVaoViMomo();
				break;
			case 6:
				rutTienNganHang();
				break;
			case 7:
				chiTieuNganHang();
				break;
			default:
				chon = 0;
		}
	} while(chon);
}
void nhanTienMomo() {
	FILE* momo = fopen("momo.txt", "r");
	int tienMomo, tienNhan;
	char noiDung[50], ngayNhan[11];
	fscanf(momo, "%d", &tienMomo);
	printf("nhap so tien nhan duoc: ");
	scanf("%d", &tienNhan);
	getchar();
	printf("nhap noi dung: ");
	gets(noiDung);
	printf("nhap ngay nhan: ");
	gets(ngayNhan);
	xuLyNgay(ngayNhan);
	ghiHoaDonMomo(ngayNhan, tienNhan, noiDung, '+');
	printf("thuc hien giao dich nhan tien MOMO thanh cong\n");
	fclose(momo);
}
void chiTieuMomo() {
	FILE* momo = fopen("momo.txt", "r");
	FILE* tongChi = fopen("tongChi.txt", "r");
	int tienMomo, tienChiTieu, tongTienChi;
	char noiDung[50], ngayTieu[11];
	char hinhThuc[] = "MOMO";
	fscanf(momo, "%d", &tienMomo);
	fscanf(tongChi, "%d", &tongTienChi);
	printf("nhap so tien ban da tieu: ");
	scanf("%d", &tienChiTieu);
	getchar();
	if(tienChiTieu > tienMomo) {
		printf("tai khoan momo cua ban khong du cho chi tieu\n");
		return;
	}
	printf("nhap noi dung tieu: ");
	gets(noiDung);
	printf("nhap ngay chi tieu: ");
	gets(ngayTieu);
	xuLyNgay(ngayTieu);
	tienMomo -= tienChiTieu;
	updateSoDuMomo(tienMomo);
	ghiHoaDonMomo(ngayTieu, tienChiTieu, noiDung, '-');
	tongTienChi += tienChiTieu;
	updateTongChi(tongTienChi);
	ghiHoaDonChiTieu(ngayTieu, tienChiTieu, noiDung, hinhThuc);
	fclose(momo);
	fclose(tongChi);
}
void menuViDienTuMomo() {
	printf("1. Chuyen tien vao ngan hang\n");
	printf("2. Nap tien tu ngan hang vao momo\n");
	printf("3. Nhan tien\n");
	printf("4. Chi tieu momo\n");
}
void viDienTuMomo(int chon) {
	do {
		menuViDienTuMomo();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				RutTienMomo();
				break;
			case 2:
				chuyenTienVaoViMomo();
				break;
			case 3:
				nhanTienMomo();
				break;
			case 4:
				chiTieuMomo();
				break;
			default:
				chon = 0;
		}
	} while(chon);
}
void xemTongChi() {
	FILE* f = fopen("tongChi.txt", "r");
	int tongChi;
	fscanf(f, "%d", &tongChi);
	printf("tong chi hien tai la: %d\n", tongChi);
	fclose(f);
}
int kiemTraTrungKyTu(char *ktGoc, char *kt, char soKyTu) {
	for(int i = 0; i < soKyTu; i++)
		if(*(ktGoc + i) != *(kt + i))
			return 0;
	return 1;
}
void searchChiTieu() {
	FILE* f = fopen("hoaDon.txt", "r");
	char ngayTieu[11], line[250];
	int found = 1;
	getchar();
	printf("nhap ngay ban da chi tieu (ngay/thang/nam): ");
	gets(ngayTieu);
	xuLyNgay(ngayTieu);
	while(fgets(line, sizeof(line), f))
		if(kiemTraTrungKyTu(line, ngayTieu, len(ngayTieu))) {
			printf("%s\n", line);
			found = 0;
		}
	if(found)
		printf("khong tim thay du lieu trong ngay %s\n", ngayTieu);
	fclose(f);
}
void chotChiTieu() {
	FILE* f = fopen("hoaDon.txt", "r");
	FILE* tongChi = fopen("tongChi.txt", "r");
	int tongTienChi;
	fscanf(tongChi, "%d", &tongTienChi);
	fprintf(f, "\n\t tong chi tieu chot ngay %s la: %d VND\n", tongTienChi);
	fprintf(f, "========================================================================================");
	fclose(f);
	fclose(tongChi);
}
void xemSoDuTienMat() {
	FILE* f = fopen("wallet.txt", "r");
	int soDu;
	fscanf(f, "%d", &soDu);
	printf("so du tien mat cua ban la: %d VND\n", soDu);
	fclose(f);
}
void xemSoDuNganHang() {
	int chonNganHang, tienNganHang;
	char tenNganHang[24], tenNH[12];
	printf("chon ngan hang ban muon xem so du:\n");
	menuTenNganHang();
	scanf("%d", &chonNganHang);
	switch(chonNganHang) {
		case 1: {
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
			break;
		}
		case 2: {
			char tmp[] = "nganHangVietcomBank.txt";
			char tmp2[] = "VietcomBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2,tenNH,len(tmp2));
			break;
		}
		default:
			char tmp[] = "nganHangViettinBank.txt";
			char tmp2[] = "ViettinBank";
			copyString(tmp, tenNganHang, len(tmp));
			copyString(tmp2, tenNH, len(tmp2));
	}
	tienNganHang = getTienNganHang(tenNganHang);
	printf("so du ngan hang %s cua ban la: %d VND\n", tenNH, tienNganHang);
}
void xemSoDuMomo() {
	FILE* f = fopen("momo.txt", "r");
	int tienMomo;
	fscanf(f, "%d", &tienMomo);
	printf("so tien MOMO cua ban la: %d VND\n", tienMomo);
	fclose(f);
}
void menuSoDu() {
	printf("1. Tien mat\n");
	printf("2. Ngan hang\n");
	printf("3. Momo\n");
	printf("0. Quay lai...\n");
}
void xemSoDu(int chon) {
	do {
		menuSoDu();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				xemSoDuTienMat();
				break;
			case 2:
				xemSoDuNganHang();
				break;
			case 3:
				xemSoDuMomo();
			default:
				chon = 0;
		} 
	} while(chon);
}
void menu() {
	printf("1. Tien mat\n");
	printf("2. Ngan hang\n");
	printf("3. Vi dien tu\n");
	printf("4. Xem tong chi\n");
	printf("5. Search chi tieu\n");
	printf("6. Chot chi tieu\n");
	printf("7. Xem so du\n");
	printf("0. Thoat...\n");
}
int main() {
	int chon;
	do {
		menu();
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				int chonCase1;
				tienMat(chonCase1);
				break;
			case 2:
				int chonCase2;
				nganHang(chonCase2);
				break;
			case 3:
				int chonCase3;
				viDienTuMomo(chonCase3);
				break;
			case 4:
				xemTongChi();
				break;
			case 5:
				searchChiTieu();
				break;
			case 6:
				chotChiTieu();
				break;
			case 7:
				int chonCase7;
				xemSoDu(chonCase7);
				break;
			default:
				chon = 0;
		}
	} while(chon);
	printf("Ket thuc chuong trinh");
	return 0;
}
