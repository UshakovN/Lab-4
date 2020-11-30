#include <cstdio>
#include <locale.h>
#pragma warning(disable:4996)
const int MAX = 100;

void input_str(char*& x, int& i, int n, FILE* f) {
	if (n == 0) { char* y = new char[i * 2 + 2];
		for (int k = 0; k < i; k++) { y[k] = x[k]; }
		n = i + 2; x = y; }
	if (fscanf_s(f, "%c", &x[i]) == 1 && x[i] != '\n') { input_str(x, ++i, --n, f); }
	else x[i] = '\0';
	return; }

void output_str(char* x, int i, int n, FILE* f) {
	if (i < n) { printf("%c", x[i]); fprintf(f, "%c", x[i]); output_str(x, ++i, n, f); }
	return; }

void change_str(char* x, char* y, char*& z, int pos_sub, int n_sub, int n_che, int i, int j, int k) {
	if (i < pos_sub) { z[i] = x[i]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, j, k); }
	else if (j < n_che) { z[i] = y[j]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, ++j, k); }
	else if (x[k] != '\0') { z[i] = x[k]; change_str(x, y, z, pos_sub, n_sub, n_che, ++i, j, ++k); }
	return; }

int sub_str(char* x, char* y, int i, int j, int k) {
	int pos = -1;
	if (x[i] != '\0') {
		if (y[k] != '\0') {
			if (x[j] == y[k]) { j++; k++; pos = sub_str(x, y, i, j, k); }
			else { k = 0; i++; j = i; pos = sub_str(x, y, i, j, k); }
		} else pos = i; }
	return pos; }

int main() {
	setlocale(LC_ALL, "Rus");
	int pos; FILE* input; FILE* log;
	char* str, * sub, * che, * che_str; char* changed_str = nullptr;
	int n_str = 0; int n_sub = 0; int n_che = 0;
	fopen_s(&input, "input.txt", "rt"); fopen_s(&log, "log.txt", "wt");
	input_str(str, n_str, 0, input); input_str(sub, n_sub, 0, input); input_str(che, n_che, 0, input);
	pos = sub_str(str, sub, 0, 0, 0);
	fprintf(log, "Original string: "); output_str(str, 0, n_str, log);
	fprintf(log, "\n"); printf("\n"); fprintf(log, "Substring position: %d \n", pos);
	fprintf(log, "Changed string: "); changed_str = new char[n_str - n_sub + n_che];
	change_str(str, che, changed_str, pos, n_sub, n_che, 0, 0, (pos + n_sub));
	output_str(changed_str, 0, (n_str - n_sub + n_che), log);
	fprintf(log, "\n"); printf("\n");
	delete[] str; delete[] sub; delete[] che; delete[] changed_str;
	fclose(input); fclose(log);
	return 0;
}
