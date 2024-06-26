# Brute Force
> ✔️ 브루트 포스(완전탐색) 알고리즘 이란?
>
> 알고리즘에서 사용되는 기법 중 하나로 '모든 가능한 경우의 수를 탐색'하여 최적의 결과를 찾는 방법
>
> 경우의 수가 매우 큰 경우에는 실행 시간 및 메모리 사용이 비효율적일 수 있음
>
___________________________________________________________________________
## 완전 탐색 알고리즘 종류
* 단순 Brute-Force
  
  : 단순히 반복문과 조건문을 활용해 모든 경우의 수를 찾는 방법
* 비트마스크
  
  : 2진수 표현 기법을 활용하는 방법 (각각의 원소가 포함되거나, 포함되지 않는 두 가지 선택으로 구성되는 경우에 유용)
* 재귀함수
  
  : 함수 안에 자신의 함수를 다시 호출하는 함수 (**재귀 탈출 조건**, **로직**, **함수 호출**로 구성됨)
* 순열
  
  : 임의의 수열이 있을 때, 다른 순서로 연산하는 방법
* 너비 우선 탐색(BFS), 깊이 우선 탐색(DFS)
  
  : 그래프에서 모든 정점을 탐색하기 위한 방법
  * 너비 우선 탐색 (Breadth-First Search)는 하나의 요소를 방문하고 그 요소에 인접한 모든 요소를 우선 방문
  * 깊이 우선 탐색 (Depth-First Seach)는 시작 노드에서 자식 노드를 순서대로 탐색하면서 깊이를 우선으로 방문
___________________________________________________________________________
## 완전 탐색 알고리즘 문제 예시
* 왕실의 나이트 <https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/A.cpp>
* 게임 개발 <https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/B.cpp>
* 럭키 스트레이트 [https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/Q7.cpp]
* 문자열 재정렬 [https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/Q8.cpp]
* 문자열 압축 [https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/Q9.cpp]
* 자물쇠와 열쇠 [https://github.com/dannysmson/codingTestStudy/blob/main/BruteForce/Q10.cpp]
