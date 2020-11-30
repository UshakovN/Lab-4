#include <cstdio>
#pragma warning (disable:4473)
#pragma warning (disable:6064)
const int MAX = 100;

void resize_str(char*& x, char*& y, int& i, int n, int k) {
	if (k < i) { y[k] = x[k]; resize_str(x, y, i, n, ++k); }
	return;
}

void input_str(char*& x, int& i, int n, FILE* f) {
	if (n == 0) {
		char* y = new char[i * 2 + 2];
		resize_str(x, y, i, n, 0);
		n = i + 2; x = y;
		/*
		for (int k = 0; k < i; k++) {
			y[k] = x[k];
		}
		n = i + 2; x = y;
		*/
	}
	if (fscanf_s(f, "%c", &x[i]) == 1 && x[i] != '\n') {
		input_str(x, ++i, --n, f);
	}
	else x[i] = '\0';
	return;
}

void output_str(char* x, int i, int n, FILE* f) {
	if (i < n) {
		printf("%c", x[i]); fprintf(f, "%c", x[i]);
		output_str(x, ++i, n, f);
	}
	return;
}

void change_str(char* x, char* y, char *&z, int pos_sub, int n_sub, int n_che, int i, int j, int k) {
	if (i < pos_sub) {
		z[i] = x[i]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, j, k);
	}
	else if (j < n_che) {
		z[i] = y[j]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, ++j, k);
	}
	else if (x[k] != '\0') {
		z[i] = x[k]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, j, ++k);
	}
	return;
	}

int sub_str(char* x, char* y, int i, int j, int k) {
	int pos = -1;
	if (x[i] != '\0') {
		if (y[k] != '\0') {
			if (x[j] == y[k]) {
				j++; k++;
				pos = sub_str(x, y, i, j, k);
			} else {
				k = 0; i++; j = i;
				pos = sub_str(x, y, i, j, k);
			}
		}
		else pos = i;
	}
	return pos;
}

