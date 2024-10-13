// 2차원 행렬을 생성하고 랜덤으로 값을 채워넣는 프로그램

#include <iostream>
#include <vector>
using namespace std;

struct SparseMatrix {
    int row; // 행
    int col; // 열
    int value; // 값
};

void fillMatrix(int *A, int row, int col); // 2차원 행렬을 랜덤으로 채워넣는 함수
void printMatrix(int *A, int row, int col); // 2차원 행렬을 출력하는 함수
void denseToSparse(int *A, int row, int col); // 1차원 배열로 표현한 행렬을 희소 행렬로 변환

int main() {
    int row, col; // 행, 열

    do {
        cout << "행: ";
        cin >> row;
    } while (row <= 0);
    do {
        cout << "열: ";
        cin >> col;
    } while (col <= 0);
    cout << endl;

    int *A = new int[row * col]; // 1차원 배열로 2차원 행렬을 표현
    
    fillMatrix(A, row, col);
    printMatrix(A, row, col);

    denseToSparse(A, row, col);

    delete[] A; // 동적 할당한 메모리 해제

    return 0;
}

void fillMatrix(int *A, int row, int col) {
    for (int i = 0; i < row * col; i++) {
        if (rand() % 100 < 80) 
            A[i] = 0;
        else
            A[i] = rand() % 9 + 1;
    }
}

void printMatrix(int *A, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << A[i * col + j] << " ";
        }
        cout << endl;
    }
}

// 1차원 배열로 표현한 행렬을 희소 행렬로 변환. 0이 아닌 원소의 개수를 센다.
void denseToSparse(int *A, int row, int col) {
    int count = 0; // 0이 아닌 원소의 개수
    
    for (int i = 0; i < row * col; i++) {
        if (A[i] != 0) {
            count++;
        }
    }

    vector<SparseMatrix> sA(count); // 희소 행렬    
}
