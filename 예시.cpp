#include <iostream>
using namespace std;

#define endl "\n"; // for�������� endl�� ������ �ͺ��� "\n" ���°� �� ����

struct SparseMatrix {
    int row;   // ��
    int col;   // ��
    int value; // ��
};

void fillMatrix(int *A, int row, int col); // 2���� ����� �������� ä���ִ� �Լ�
void printMatrix(int *A, int row, int col); // 2���� ����� ����ϴ� �Լ�
void denseToSparse(int *A, int row, int col); // 1���� �迭�� ǥ���� ����� ��� ��ķ� ��ȯ

int main() {
    int row, col; // ��, ��

    do {
        cout << "��: ";
        cin >> row;
    } while (row <= 0);
    do {
        cout << "��: ";
        cin >> col;
    } while (col <= 0);
    cout << endl;

    int *A = new int[row * col]; // 1���� �迭�� 2���� ����� ǥ��
    
    fillMatrix(A, row, col);
    printMatrix(A, row, col);

    denseToSparse(A, row, col);

    delete[] A; // ���� �Ҵ��� �޸� ����

    return 0;
}

void fillMatrix(int *A, int row, int col) {
    for (int i = 0; i < row * col; i++) {
        if (rand() % 100 < 80) 
            A[i] = 0;  // 80% Ȯ���� 0
        else
            A[i] = rand() % 9 + 1;  // 1���� 9������ ������ ��
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
    int count = 0; // 0�� �ƴ� ������ ����
    
    // 0�� �ƴ� ������ ������ ���� ��
    for (int i = 0; i < row * col; i++) {
        if (A[i] != 0) {
            count++;
        }
    }

    // ��Ȯ�� ũ���� ��� ��� ����ü �迭 �Ҵ�
    SparseMatrix *sA = new SparseMatrix[count];
    
    // 0�� �ƴ� ���Ҹ� ��� ��ķ� ��ȯ
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

    // ��� ��� ���
    cout << "��� ��� (row, col, value):\n";
    for (int i = 0; i < count; i++) {
        cout << "(" << sA[i].row << ", " << sA[i].col << ", " << sA[i].value << ")" << endl;
    }

    delete[] sA;
}
