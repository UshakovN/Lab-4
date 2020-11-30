#pragma once
#include <cstdio>

void input_str(char*& x, int& i, int n, FILE* f);
void output_str(char* x, int i, int n, FILE* f);
int sub_str(char* x, char* y, int i, int j, int k);
void change_str(char* x, char* y, char*& z, int pos_sub, int n_sub, int n_che, int i, int j, int k);

void resize_str(char*& x, char*& y, int& i, int n, int k);
