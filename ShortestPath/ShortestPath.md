# Shortest Path 최단 경로 Alg.

✔️ 최단 경로 알고리즘이란?

: 가장 짧은 경로를 찾는 알고리즘, 보통 그래프 문제에서 사용되는 알고리즘이며 **간선의 가중치 합이 최소**가 되는 경로를 찾는 방법

* 주요 알고리즘으로 `다익스트라 알고리즘` `벨만-포드 알고리즘` `플로이드-워셜 알고리즘`이 있다.

___

## **✔️ 다익스트라 알고리즘 (Dijkstra Algorithm)**

- *음의 간선이 없는* 가중 그래프에서 사용되는 알고리즘
- 특정 정점에서 다른 정점으로 가는 각각의 최단경로를 구해주는 알고리즘
- **우선순위큐**를 활용하여 구현 (리스트로도 구현 가능)

**시간 복잡도**
- 힙에 기초한 우선순위큐 구현: O(ElogV)
  - 각 정점을 우선순위큐에 삽입, 삭제할 때 소요 O(logV)
  - 우선순위큐에 추가할 최대 원소 수 = 간선의 갯수
  => `O(ElogV)`
- 리스트에 기초한 구현: O(V^2)
  - 각 정점 V번, 삽입 시 O(V)소요
  => `O(V^2)`

**기본 알고리즘**
1. 출발 노드 설정
2. 최단 거리 테이블 초기화
3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드 선택
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블 갱신
5. `3`, `4`번 과정 반복

![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/4f5319af-eeff-41e9-97a5-f81ca644667f)
![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/0a69e0df-edcf-433b-97a9-446035e323b8)

**C++ 코드**
![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/18eaabec-aad7-4167-90c0-e9d21fc45e02)

___

## **✔️ 플로이드 워셜 알고리즘 (Floyd-Warshall Algorithm)**

- 모든 지점에서 다른 모든 지점까지의 최단 경로를 구할 때 사용하는 알고리즘
- 2차원 리스트에 '최단 거리' 정보를 저장 (인접 행렬)
- 노드의 갯수가 N개일 때, 매 단계마다 O(N^2) 연산을 통해 '현재 노드를 거쳐 가는' 모든 경로를 고려
- 시간 복잡도: `O(N^3)`
- 다익스트라 알고리즘과는 다르게 매 단계에서 방문하지 않은 노드 중 최단 거리를 갖는 노드를 찾을 필요가 없음

**주요 알고리즘**

i노드에서 j노드까지 이동하는 최소 비용을 구할 때, i노드에서 k노드를 거쳐 j노드를 가는 비용과 비교

`min(dist[i][j], dist[i][k] + dist[k][j]`

![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/5368e6b8-7ef8-48d0-aedb-f0bec5d6b8c7)

**C++ 코드**

![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/7c46768a-57cf-4700-9d0e-20b59bfde0b6)

___

## **✔️ 벨만-포드 알고리즘 (Bellman-Ford Algorithm)**

- *음의 간선이 있는* 가중 그래프에서 사용되는 알고리즘
- 노드 갯수가 n이라고 할 때, n-1회 반복하면서 매 단계마다 간선 완화 시도
- n-1회 후, 한번더 간선 완화가 된다면 `음의 무게를 가지는 싸이클`이 존재함을 알 수 있음
- 다익스트라 알고리즘과는 다르게 매 반복마다 모든 간선을 확인 함 <-> 다익스트라는 최단 거리가 가장 짧은 노드만 방문

**주요 알고리즘**
1. 출발 노드를 설정
2. 최단 거리 테이블 초기화
3. 다음 과정 (V-1)번 반복
   - 모든 간선 E개를 확인, 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
4. 마지막에 한번 더 반복했을 때 간선 완화가 이루어진다면 음의 무게를 가지는 싸이클이 존재

![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/4a200e41-1a3b-448b-be4a-edf45d552bdc)
![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/846e88a3-2e06-4de2-8c8c-776b44b739ce)

**C++ 코드**

![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/145194eb-fc2b-48c2-a777-ef6b7a72ce6f)

___

## 최단경로 알고리즘 문제 예시
* 미래 도시 [https://github.com/dannysmson/codingTestStudy/blob/main/ShortestPath/%EB%AF%B8%EB%9E%98%EB%8F%84%EC%8B%9C.cpp]
* 전보 [https://github.com/dannysmson/codingTestStudy/blob/main/ShortestPath/%EC%A0%84%EB%B3%B4.cpp]
