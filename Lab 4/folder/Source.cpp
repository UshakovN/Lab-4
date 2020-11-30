/* 

Õ≈ –¿¡Œ“¿≈“

#include <cstdio>
#include <locale.h>

#include <string.h>

void ReadLine(FILE* f, char*& array, int& n) {
	char tmp = 'a';
	int size = 0;

	fscanf_s(f, "%c", &tmp, 1);
	while (!feof(f)) {
		//ResizeArray(array, size);
		array[size - 1] = tmp;
		fscanf_s(f, "%c", &tmp, 1);
	}
	n = size;
}

void PrintArray(FILE* f, int size, char* array, bool flag) {
	for (int i = 0; i < size; i++) {
		fprintf(f, "%c", array[i]);
	}
	fprintf(f, " ");

	if (flag) {
		fprintf(f, "\n");
	}
	return;
}

void ResizeArray(char*& array, int& size) {
	char* temparray;
	int currentsize = size;
	int  newsize = currentsize + 1;
	temparray = new char[newsize];

	for (int i = 0; i < newsize; i++) {
		temparray[i] = array[i];
	}

	size = newsize;
	delete[] array;
	array = new char[size];
	array = temparray;
	return;
}

void ReversWord(char* s, int i, int j) {
	char tmp;

	if (i < j) {
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		ReversWord(s, i + 1, j - 1);
	}
	return;
}

bool IsItInWord(char ch) {
	return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '\n');
}

int main() {
	int pos;
	return 0;
}

int subch(char* x, char ch, int n) {
	int pos, i = 0;
	bool flag = true;
	if (flag && i < n) {
		if (x[i] = ch) {
			flag = false;
			pos = i;
		}
		else {
			subch(x, i + 1, n);
		}
	}
}


*/