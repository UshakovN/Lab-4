//Вариант 2. Сформировать строку заменой в исходной строке заданной подстроки 
//На другую заданную подстроку (возможно разной длины).

/*

МОЙ КОД

#include <cstdio>
#include <locale.h>
#pragma warning(disable:4996)

bool check_ch(char a) {
	return (a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

bool check_end(char a) {
	return (a == '\0');
}

int input_rec(FILE* f, int i) {
	char ch;

	if ( !(feof(f)) ) {
		fscanf(f, "%c", &ch);
		i++;
		input_rec(f, i);
	}
	else return i;
}

void output_rec(char*& x, int i, FILE* f) {
	bool flag = check_end(x[i]);

	if (!flag) {
		printf("%c", x[i]);
		fprintf(f, "%c", x[i]);
		i++;
		output_rec(x, i, f);
	}
	return;
}

int copy_str(char*& x, char*& y, int i, int j)
{
	if ( check_ch(x[i]) )
	{
		y[j] = x[i];
		i++;
		j++;
		copy_str(x, y, i, j);
	}
	else return j;
}

int lenth_str(char* f_name) {
	FILE* f; int i;
	f = fopen(f_name, "rt");
	i = input_rec(f, 0);
	fclose(f);
	return i;
}


int main() {
	return 0;
}


*/
