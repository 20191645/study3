// 인접 리스트 기반 그래프를 활용하여 BFS 구현
// "ALGraph.h, cpp" -- 인접 리스트 기반 그래프 활용하기 위해 함께 컴파일
// "LinkedList2.h, cpp" -- "ALGraph.h, cpp"에서 포함되어 함께 컴파일
// "ArrayQueue.h, cpp" -- 경로 추적을 위한 큐를 이용하기 위해 함께 컴파일
// LinkedList의 LData 타입과 ArrayStack의 Data 타입과 정점 타입이 동일해야 한다 -- int형
#ifndef ALGRAPHBFS_H_
#define ALGRAPHBFS_H_

#include "ALGraph.h"
#include "LinkedList2.h"
#include "ArrayQueue.h"

// ALGraph를 상속하여 DFS 구현을 위한 멤버변수와 함수를 추가
class ALGraphBFS : public ALGraph {
private:
	int* visit;	// 방문 정보 배열 -- 인덱스: 정점

public:
	ALGraphBFS(int v);
	~ALGraphBFS();

	void ShowVertexInfo(int start) const;
};

#endif