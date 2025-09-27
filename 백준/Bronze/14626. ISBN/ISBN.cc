#include <iostream>
#include <string>
#include <vector>

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 13자리 번호 입력
    std::string isbn;
    std::cin >> isbn;

    int sum = 0;
    int star_index = -1;

    // 1. '*'의 위치를 찾고, 나머지 숫자들의 가중치 합을 계산
    for (int i = 0; i < 13; ++i) {
        if (isbn[i] == '*') {
            star_index = i; // '*'의 인덱스 저장
        } else {
            // 문자를 숫자로 변환
            int digit = isbn[i] - '0';

            // 위치(인덱스)에 따른 가중치 결정
            // 인덱스가 0, 2, 4, ... (홀수 번째) -> 가중치 1
            // 인덱스가 1, 3, 5, ... (짝수 번째) -> 가중치 3
            if (i % 2 == 0) {
                sum += digit * 1;
            } else {
                sum += digit * 3;
            }
        }
    }

    // 2. '*' 자리에 0부터 9까지 대입하여 정답 찾기
    for (int missing_digit = 0; missing_digit <= 9; ++missing_digit) {
        int temp_sum = sum;
        
        // '*' 위치의 가중치를 판별
        if (star_index % 2 == 0) {
            temp_sum += missing_digit * 1;
        } else {
            temp_sum += missing_digit * 3;
        }

        // 3. 가중치 총합이 10의 배수인지 확인
        if (temp_sum % 10 == 0) {
            std::cout << missing_digit << std::endl;
            break; // 정답을 찾았으므로 반복문 종료
        }
    }

    return 0;
}