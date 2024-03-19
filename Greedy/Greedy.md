# Greedy Algorithm
> ✔️ 그리디 알고리즘(탐욕법) 이란?
>
> 각 단계에서 **최적**이라고 생각되는 것을 선택해 나가는 방식으로 진행하여 최종적인 해답에 도달하는 알고리즘
>
> But. 최종적인 결과 도출에 대한 최적해를 보장해주지는 않음!

<img width="697" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/d04b7c95-63ad-4a7d-8939-ffd61ea96625">

[시작 지점에서 시작하여 가장 큰 수를 구하는 문제]
  
직관: "시작 - 6 - 128"

그리디: "시작 - 17 - 23"

_이처럼 그리디 알고리즘은 현재 상황에서 가장 좋은 결과를 선택하는 방식이며 결과 도출에 항상 최적해를 보장하지 않는다_
________________________________________________________________________________________
## 그리디 알고리즘 조건
1. 탐욕 선택 속성(Greedy Choice Property)

>: 각 단게에서 '**최선의 선택**'을 했을 때 전체 문제의 최적해를 반드시 도출할 수 있어야 함


2. 최적 부분 구조(Optimal Substructure)

>: **전체 문제의 최적해가 '부분 문제의 최적해로 구성'될 수 있는 경우**
>
> 즉, 전체 문제를 작은 부분 문제로 나누어 각각의 부분 문제에서 최적의 해를 구한 후 이를 조합하여 전체 문제의 최적해를 구하는 것
>
_________________________________________________________________________________________
## 그리디 알고리즘 문제 예시
* 거스름돈
* 큰 수의 법칙 <https://github.com/dannysmson/codingTestStudy/blob/main/Greedy/A.cpp>
* 숫자 카드 게임 <https://github.com/dannysmson/codingTestStudy/blob/main/Greedy/B.cpp>
* 1이 될 때까지 <https://github.com/dannysmson/codingTestStudy/blob/main/Greedy/C.cpp>
  
