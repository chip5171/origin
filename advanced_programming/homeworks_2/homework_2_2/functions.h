#pragma once
#include <iostream>
#include <fstream>

// ������ �������� - ��� ���������� ���������� � ������������ ����� ���������� �� ���� � ����� ����������
int* create_array(double size);
int* writing_array(std::ifstream& file, int* arr, int size);
void print_array(int* arr, int size);
void delete_array(int* arr, int size);