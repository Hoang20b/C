#include<stdio.h>
//Bai toan tinh so to tien trong 1 khoan tien.
/*
- Nhung to tien co menh gia cao = hoac < khoan tien se duoc tinh dau tien.
- vd: 7k = 1 to 5k , 1 to 2k cong lai.
*/
int main() {
	long n;
	int to1 = 0 , to2 = 0 , to3 = 0 , to5 = 0 , to10 = 0 , to20 = 0 , to50 = 0 , to100 = 0 , to200 = 0 , to500 = 0;
	printf("nhap so tien (bo 3 so 0): ");scanf("%ld", &n);
	while(n) {
		if(n >= 500) {
			to500++;
			n -= 500;
		} else if(n >= 200) {
			to200++;
			n -= 200;
		} else if(n >= 100) {
			to100++;
			n -= 100;
		} else if(n >= 50) {
			to50++;
			n -= 50;
		} else if(n >= 20) {
			to20++;
			n -= 20;
		} else if(n >= 10) {
			to10++;
			n -= 10;
		} else if(n >= 5) {
			to5++;
			n -= 5;
		} else if(n >= 2) {
			to2++;
			n -= 2;
		} else if(n >= 1) {
			to1++;
			n--;
		}
	}
	printf("So to tien can la: \n");
	if(to1) {
		printf("%d to 1k\n", to1);
	} 
	if(to2) {
		printf("%d to 2k\n", to2);
	} 
	if(to5) {
		printf("%d to 5k\n", to5);
	} 
	if(to10) {
		printf("%d to 10k\n", to10);
	}
	if(to20) {
		printf("%d to 20k\n", to20);
	}
	if(to50) {
		printf("%d to 50k\n", to50);
	}
	if(to100) {
		printf("%d to 100k\n", to100);
	}
	if(to200) {
		printf("%d to 200k\n", to200);
	}
	if(to500) {
		printf("%d to 500k\n", to500);
	}
	return 0;
}
