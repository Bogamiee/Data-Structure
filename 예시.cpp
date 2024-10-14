#include <iostream>
using namespace std;

#define endl "\n"; // for문에서는 endl을 돌리는 것보다 "\n" 쓰는게 더 빠름

struct SparseMatrix {
    int row;   // 행
    int col;   // 열
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
            A[i] = 0;  // 80% 확률로 0
        else
            A[i] = rand() % 9 + 1;  // 1에서 9까지의 랜덤한 수
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

void denseToSparse(int *A, int row, int col) {
    int count = 0; // 0이 아닌 원소의 개수
    
    // 0이 아닌 원소의 개수를 먼저 셈
    for (int i = 0; i < row * col; i++) {
        if (A[i] != 0) {
            count++;
        }
    }

    // 정확한 크기의 희소 행렬 구조체 배열 할당
    SparseMatrix *sA = new SparseMatrix[count];
    
    // 0이 아닌 원소를 희소 행렬로 변환
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i * col + j] != 0) {
                sA[index].row = i;
                sA[index].col = j;
                sA[index].value = A[i * col + j];
                index++;
            }
        }
    }

    // 희소 행렬 출력
    cout << "희소 행렬 (row, col, value):\n";
    for (int i = 0; i < count; i++) {
        cout << "(" << sA[i].row << ", " << sA[i].col << ", " << sA[i].value << ")" << endl;
    }

    delete[] sA;
}
