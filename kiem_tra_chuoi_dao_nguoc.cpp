#include<stdio.h>
#include<string.h>
int check(char ki_tu[]) {
	if(strlen(ki_tu) % 2 != 0) {
		return 0;
	}
	for(int i = 0; i < strlen(ki_tu) / 2; i++) {
		if(ki_tu[i] != ki_tu[strlen(ki_tu) - i - 1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	char ki_tu[100];
	scanf("%s", &ki_tu);
	if(check(ki_tu)) {
		printf("chuoi dao nguoc");
	} else {
		printf("khong phai chuoi dao nguoc");
	}
	return 0;
}
