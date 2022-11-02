#include <iostream>
#include <fstream>

// Функция создания одномерного динамического массива
int* create_array(int size) {
    int* arr = new int[size]();
    return arr;
}
// Функция заполнения массива из файла
int* writing_array(std::ifstream& file, int size, int* arr) {
    for (int i = 0; i < size; ++i) {
        file >> arr[i];
    }
    return arr;
}
// Функция записи массива в файл
void fprint_array(std::ofstream& file, int size, int* arr, int k) {
    for (k; k < (size); k++) {
        file << arr[k] << " ";
    }
}
// Функция удаления динамического массива
void delete_array(int* arr, int size) {
    delete[] arr;
}
//______________________________________________________________________

int main(int argc, char** argv) {
    int N, M;
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (!fin.is_open()) {
        std::cout << "File in.txt not opened\n";
        return 1;
    }
    if (!fout.is_open()) {
        std::cout << "File out.txt not opened\n";
        return 1;
    }

    fin >> N;
    int* arrN = create_array(N);
    writing_array(fin, N, arrN);

    fin >> M;
    int* arrM = create_array(M);
    writing_array(fin, M, arrM);

    fin.close();

    fout << M << std::endl;
    fout << arrM[M - 1] << " ";
    int m = 0;
    fprint_array(fout, (M - 1), arrM, m);
    fout << std::endl;

    fout << N << std::endl;
    int n = 1;
    fprint_array(fout, N, arrN, n);
    fout << arrN[0] << " " << std::endl;

    fout.close();

    delete_array(arrN, N);
    delete_array(arrM, M);

    return 0;
}
