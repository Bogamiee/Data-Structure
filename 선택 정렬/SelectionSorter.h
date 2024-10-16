#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

class SelectionSorter
{
private:
    int* list;    // �迭 ������
    int size;     // �迭 ũ��

public:
    // �����ڿ� �Ҹ���
    SelectionSorter(int n);
    ~SelectionSorter();

    // ��� �Լ���
    void initRandom(int max = 100);       // �迭�� �������� �ʱ�ȭ
    void printArray(const char* str) const;   // �迭�� ���
    void selectionSort();                 // ���� ���� ����
};

#endif // SELECTIONSORTER_H
