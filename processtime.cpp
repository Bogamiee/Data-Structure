#include <iostream>
#include <chrono>

int main() {
    // 시작 시간 기록
    auto start = std::chrono::high_resolution_clock::now();

    // 수행할 코드 (여기에 실제 작업을 작성하세요)

    // 종료 시간 기록
    auto end = std::chrono::high_resolution_clock::now();

    // 소요 시간 계산
    std::chrono::duration<double> duration = end - start;

    // 소요 시간 출력
    std::cout << "소요 시간: " << duration.count() << "초" << std::endl;

    return 0;
}

