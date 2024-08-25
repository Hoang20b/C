#include<stdio.h>
#include<hoang.h>
int len(char* kt) {
	//ham tra ra so ky tu cua 1 chuoi.
	int count = 0;
	while(*(kt + count) != '\0')
		count++;
	return count;
}

int ktDoiXung(char *kt) {
	//ham kiem tra chuoi co doi xung khong
	/*
	- input: abba -> output: 1
	- input: abab -> output: 0 
	*/
	int kichThuoc = len(kt);
	for(int i = 0; i < kichThuoc; i++)
		if(*(kt + i) != *(kt + kichThuoc - i - 1))
			return 0;
	return 1;
}

int ktChuoiCon(char *ktGoc, char *kt, int soKtCanKT) {
	//ham kiem tra chuoi con dua tren so ki tu can kiem tra.
	/*
	input: "Nguyen Huy Hoang" "Huy" 3
	output: 1 -> true
	
	input: "Nguyen Huy Hoang" "Huy" 4
	output: 0 -> false
	*/
	for(int i = 0; i < soKtCanKT; i++)
		if(*(kt + i) != *(ktGoc + i))
			return 0;
	return 1;
}

int demSoTu(char *kt) {
	//ham dem so tu trong 1 chuoi.
	/*
	input: "Nguyen Huy Hoang"
	output: 3
	*/
	int count = 0;
	while(*(kt++) != '\0')
		if(*(kt) == ' ')
			count++;
	return count + 1;
}

void upperCase(char *kt) {
	//ham viet hoa cac ky tu trong chuoi
	int kichThuoc = len(kt);
	for(int i = 0; i < kichThuoc; i++)
		if(*(kt + i) >= 97 && *(kt + i) <= 122)
			*(kt + i) -= 32;
			
}

void lowerCase(char *kt) {
	//ham viet thuong cac ky tu trong chuoi
	int kichThuoc = len(kt);
	for(int i = 0; i < kichThuoc; i++)
		if(*(kt + i) >= 65 && *(kt + i) <= 90)
			*(kt + i) += 32;
}

void reverseString(char *kt) {
	//ham dao nguoc chuoi ki tu.
	//input: abc -> output: cba.
	int kichThuoc = len(kt);
	char tmp;
	for(int i = 0; i < kichThuoc / 2; i++) {
		tmp = *(kt + i);
		*(kt + i) = *(kt + kichThuoc - i - 1);
		*(kt + kichThuoc - i - 1) = tmp;
	}
}

void copyString(char *ktGoc, char *kt, int soKtCopi) {
	//copy mot chuoi tu chuoi goc.
	if(soKtCopi > len(ktGoc)) {
		soKtCopi = len(ktGoc);
	}
	for(int i = 0; i < soKtCopi; i++)
		*(kt + i) = *(ktGoc + i);
}

void xoaKtTheoViTri(char *kt, int vtXoa) {
	//ham xoa ki tu o vi tri xoa khoi chuoi ki tu.
	int kichThuoc = len(kt);
	if(vtXoa < 0 || vtXoa >= kichThuoc) {
		printf("\nvi tri ban can xoa la %d khong nam trong pham vi cua chuoi\n", vtXoa);
		return;
	}
	for(int i = vtXoa; i < kichThuoc; i++)
		*(kt + i) = *(kt + i + 1);
}

void xoaKt(char *kt, char ktXoa, int soKTXoa) {
	//xoa ki tu ban mong muon
	int kichThuoc = len(kt);
	int count = 0;
	for(int i = 0; i < kichThuoc; i++) {
		if(count == soKTXoa)
			break;
		if(*(kt + i) == ktXoa) {
			xoaKtTheoViTri(kt,i);
			count++;
		}
	}
}

void xoaKhoangTrangKhongCanThiet(char *kt) {
	//ham xoa cac khoang trang khong can thiet trong 1 chuoi ki tu.
	/*
	input: "   Nguyen Huy    Hoang   "
	output: "Nguyen Huy Hoang"
	*/
	int kichThuoc = len(kt);
	int tmp;
	for(int i = 0; *(kt + i) == ' ';)
		for(int j = i; j < kichThuoc; j++)
			*(kt + j) = *(kt + j + 1);
	kichThuoc = len(kt);
	for(int i = kichThuoc - 1; *(kt + i) == ' '; i--)
		*(kt + i) = *(kt + i + 1);
	kichThuoc = len(kt);
	for(int i = 0; i < kichThuoc; i++) {
		if(*(kt + i) == ' ' && *(kt + i + 1) == ' ') {
			xoaKtTheoViTri(kt,i);
			i--;
		}
	}
}

void thayTheChuoiCon(char *kt, char *ktCon, char *chuoiConThayThe) {
	//ham thay the chuoi con trong chuoi lon.
	/*
	input: "Nguyen Huy Hoang" "Huy" "Hoa".
	output: "Nguyen Hoa Hoang" ! sau khi su ly va in *kt ra
	*/
	int kichThuocCon = len(ktCon);
	int kichThuoc = len(kt);
	int found;
	for(int i = 0; i < kichThuoc; i++) {
		found = 1;
		for(int j = 0; j < kichThuocCon;j++)
			if(*(kt + j + i) != *(ktCon + j)) {
				found = 0;
				break;
			}
		if(found) 
			for(int j = 0; j < kichThuocCon; j++)
				*(kt + j + i) = *(chuoiConThayThe + j);
	}
}

void noiChuoi(char *chuoiGoc, char *chuoiNoi) {
	//ham noi 2 chuoi voi chuoiGoc la chuoi duoc noi them chuoiNoi
	int kichThuoc = len(chuoiGoc);
	int kichThuocNoi = len(chuoiNoi);
	int j = 0;
	for(int i = kichThuoc; i < kichThuoc + kichThuocNoi; i++) {
		*(chuoiGoc + i) = *(chuoiNoi + j);
		j++;
	}
	xoaKtTheoViTri(chuoiGoc,len(chuoiGoc) - 1);
}
int main() {
	char name[] = "Nguyen Huy Hoang ";
	char friendName[] = "Nguyen Huynh Binh";
	noiChuoi(name,friendName); 
	printf("%s", name);
	return 0;
}
