// 인접 리스트(AdjacentList) 기반 그래프 확인
// -- 다른 메인 함수(~Main.cpp)와 함께 컴파일하지 않기
#include "ALGraph.h"
#include <iostream>

int main() {
	// 그래프 생성 및 초기화
	ALGraph graph(5);

	// 그래프 간선 추가
	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(C, D);
	graph.AddEdge(D, E);
	graph.AddEdge(E, A);

	// 그래프 간선 정보 출력
	graph.ShowEdgeInfo();

	return 0;
}
