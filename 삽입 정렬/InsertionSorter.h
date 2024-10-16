#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H

class InsertionSorter {
private:
    int* list;    // �迭 ������
    int size;     // �迭 ũ��

public:
    // �����ڿ� �Ҹ���
    InsertionSorter(int n);
    ~InsertionSorter();

    // ��� �Լ���
    void initRandom(int max = 100);       // �迭�� �������� �ʱ�ȭ
    void printArray(const char* str) const;   // �迭�� ���
    void insertionSort();                 // ���� ���� ����
};

#endif // INSERTIONSORTER_H
