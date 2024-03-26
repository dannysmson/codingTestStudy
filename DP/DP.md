# Dynamic Programming

✔️ Dynamic Programming 동적 프로그래밍이란?

: 복잡한 문제를 더 작은 하위 문제로 나누어 해결하는 알고리즘 설계 기법

* `+` 중복 계산을 줄일 수 있어 효율적인 시간 복잡도를 가질 수 있음
* `-` 메모리 사용량이 큼

___

✔️ Dynamic Programming 조건

1. **중복되는 부분 문제 (Overlapping Subproblems)**

동일한 작은 문제들이 반복하여 나타나는 경우

2. **최적 부분 구조 (Optimal Substructure)**

부분 문제의 최적 결과 값을 사용해 전체 문제의 최적 결과를 낼 수 있는 경우

> ![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/317fe28f-aee3-40f1-9ce3-2701d70bbfbc)
>
> 서울에서 부산까지 최단 경로를 찾는 예시
>
> 서울-대전: B경로, 대전-부산: E경로 => 서울-부산: B+E경로
>
> *즉 부분 문제의 최적 결과가 전체 문제의 최적 결과를 낼 수 있다!*

___

✔️ Dynamic Programming 문제 풀이 방법

1. **메모이제이션 (Memoization)** (=`캐싱`)

한 번 구한 결과를 메모리 공간에 메모해두고 같은 식을 다시 호출하면 메모한 결과를 그대로 가져오는 기법

2. **관계식(점화식) 만들기**

Ex) 피보나치 수열 f(n) = f(n-1) + f(n-2)

<br />

- **Top-Down** 방식 - 메모이제이션, 재귀 사용

: 큰 문제를 작은 부분 문제로 나누어 해결하는 방식, 중복 계산을 피하기 위해 이전에 계산한 결과 값을 저장하는 `Memoization`을 활용

> 🔎 `Memoization` 재귀를 사용하므로 구현이 간단하지만, 재귀 호출의 오버헤드가 발생할 수 있음

- **Bottom-Up** 방식

: 작은 부분 문제부터 차례대로 해결하여 전체 문제를 해결하는 방식, 반복문을 사용하여 반복적으로 부분 문제를 해결

> 🔎 일반적으로 더 직관적이고 이해하기 쉬움

___

✔️ 분할 정복 방법과의 차이점?

큰 문제를 작은 문제로 나누어 해결하는 방식에서는 동일하지만, **DP는 `작은 부분문제들이 반복`되어야 함!!**

___

## DP 문제예시
* 1로 만들기 [https://github.com/dannysmson/codingTestStudy/blob/main/DP/1%EB%A1%9C%EB%A7%8C%EB%93%A4%EA%B8%B0.cpp]
* 개미 전사 [https://github.com/dannysmson/codingTestStudy/blob/main/DP/%EA%B0%9C%EB%AF%B8%EC%A0%84%EC%82%AC.cpp]
* 바닥 공사 [https://github.com/dannysmson/codingTestStudy/blob/main/DP/%EB%B0%94%EB%8B%A5%EA%B3%B5%EC%82%AC.cpp]
* 효율적인 화폐 구성 [https://github.com/dannysmson/codingTestStudy/blob/main/DP/%ED%9A%A8%EC%9C%A8%EC%A0%81%EC%9D%B8%ED%99%94%ED%8F%90%EA%B5%AC%EC%84%B1.cpp]
