#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

class BubbleSorter {
private:
    int* list;    // �迭 ������
    int size;     // �迭 ũ��

public:
    // �����ڿ� �Ҹ���
    BubbleSorter(int n);
    ~BubbleSorter();

    // ��� �Լ���
    void initRandom(int max = 100);       // �迭�� �������� �ʱ�ȭ
    void printArray(const char* str) const;   // �迭�� ���
    void BubbleSort();                 // ���� ���� ����
};

#endif // BubbleSORTER_H
