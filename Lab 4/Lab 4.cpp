//Вариант 2. Сформировать строку заменой в исходной строке заданной подстроки 
//На другую заданную подстроку (возможно разной длины).

#include <cstdio>
#include <locale.h>
#include "Fuction.h"
#pragma warning(disable:4996)
#pragma warning(disable:6387)
const int MAX = 100;

int main() {
	setlocale(LC_ALL, "Rus"); 
	int pos; FILE* input; FILE* log;
	char *str, *sub, *che, *che_str; char *changed_str = nullptr;
	int n_str = 0; int n_sub = 0; int n_che = 0;
	fopen_s(&input, "input.txt", "rt");
	fopen_s(&log, "log.txt", "wt");
	input_str(str, n_str, 0, input);
	input_str(sub, n_sub, 0, input);
	input_str(che, n_che, 0, input);
    pos = sub_str(str, sub, 0, 0, 0);
	fprintf(log, "Original string: ");
    output_str(str, 0, n_str, log);
	fprintf(log, "\n"); printf("\n");
    fprintf(log, "Substring position: %d \n", pos); 
	fprintf(log, "Changed string: ");
	changed_str = new char[n_str-n_sub+n_che];
	change_str(str, che, changed_str, pos, n_sub, n_che, 0, 0, (pos+n_sub));
	output_str(changed_str, 0, (n_str-n_sub+n_che), log);
	fprintf(log, "\n"); printf("\n");
	delete[] str; delete[] sub; delete[] che; delete[] changed_str;
	fclose(input); fclose(log);
	return 0;
}


/*

void change_print(FILE* f, char* x, char* y, int pos_sub, int n1, int n2, int i, int j) {
	int m1, m2;
	if (n1 >= n2) m1 = m2 = n2;
	else { m1 = n1; m2 = n2; }

	if (x[i] != '\0') {
		if (i < pos_sub || i >= pos_sub + m1) {
			printf("%c", x[i]); fprintf(f, "%c", x[i]); i++;
		}
		else if (j < m2) {
			printf("%c", y[j]); fprintf(f, "%c", y[j]); j++;
		}
		else { i = pos_sub + m1; }
		change_print(f, x, y, pos_sub, n1, n2, i, j);
	}
	return;
}

void change_str(char* x, char* y, char*& z, int pos_sub, int n_str, int n1, int n2, int i, int j) {
	int m1, m2;
	if (n1 >= n2) { m1 = m2 = n2; }
	else { m1 = n1; m2 = n2; }

	if (x[i] != '\0') {
		if (i < pos_sub || i >= pos_sub + m1) {
			z[i] = x[i];
		}
		else if (j < m2) {
			z[i] = y[j]; j++;
		}
		else { i = pos_sub + m1; }
		change_str(x, y, z, pos_sub, n_str, n1, n2, ++i, j);
	}
	return;
}

*/

/*
bool check_ch(char a) {
	return (a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

void copy_str(char*& x, char*& y, int i, int& j) {
	y[j] = x[i];
	i++; j++;
	copy_str(x, y, i, j);
	return;
}
*/


