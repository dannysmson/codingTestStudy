#include <bits/stdc++.h>
using namespace std;

// 2020 카카오 신입 공채
// 자물쇠와 열쇠 (Brute Force Alg.)
// https://programmers.co.kr/learn/courses/30/lessons/60059
// (문제는 기본 코드가 제공되므로 상기 링크를 통해서 문제를 풀어야 함)
int K, L;
// 2차원 배열 회전
void rotate_key(vector<vector<int>> &key) {
    vector<vector<int>> tmp(K, vector<int>(K, 0));
    for(int i=0; i<K; i++) {
        for(int j=0; j<K; j++) {
            tmp[i][j] = key[K-j-1][i];
        }
    }
    key = tmp;
    return;
}
bool check(vector<vector<int>> &board, vector<vector<int>> &key, int y, int x) {
    bool answer = true;
    for(int i=0; i<K; i++) {
        for(int j=0; j<K; j++) {
            board[i+y][j+x] += key[i][j];
        }
    }
    
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            if(!board[i+L-1][j+L-1]) {
                answer = false;
                break;
            }
        }
    }
    
    for(int i=0; i<K; i++) {
        for(int j=0; j<K; j++) {
            board[i+y][j+x] -= key[i][j];
        }
    }
    return answer;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    K = key.size();
    L = lock.size();
    // 자물쇠 부분의 3배 크기인 2차원 벡터 생성
    vector<vector<int>> board(3*L, vector<int>(3*L, 0));

    // 가운데 부분에 기존 자물쇠 배열 넣기
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            board[i+L-1][j+L-1] = lock[i][j];
        }
    }
    
    // 4번 회전하며 완전 탐색
    for(int cnt=0; cnt<4; cnt++) {
        for(int i=0; i<=3*L-K; i++) {
            for(int j=0; j<=3*L-K; j++) {
                if(check(board, key, i, j)) return true;
            }
        }
        rotate_key(key);
    }
    return false;
}