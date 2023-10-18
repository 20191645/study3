// 가중치가 포함된 간선을 표현하는 구조체
#ifndef ALEDGE_H_
#define ALEDGE_H_

struct Edge {
	int v1;		// 첫번째 정점
	int v2;		// 두번째 정점
	int weight;	// 가중치
};

#endif