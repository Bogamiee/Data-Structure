#include "Huffman.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1024]; // 최대 1024문자를 수용할 버퍼 크기. 필요 시 조정 가능.

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // `fgets`로 입력받은 문자열 끝에 개행 문자가 포함될 수 있으므로 제거.
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Huffman Coding 실행
    if (!huffmanCoding(str)) {
        fprintf(stderr, "Huffman coding failed.\n");
        return 1;
    }

    return 0;
}
