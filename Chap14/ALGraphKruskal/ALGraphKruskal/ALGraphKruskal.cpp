// 인접 리스트 기반 그래프를 활용하여, 크루스칼 알고리즘 기반 최소 신장 트리(MST) 구현
#include "ALGraphKruskal.h"
#include <iostream>

// 우선순위 큐 비교 기준 함수 -- 가중치 내림차순 정렬
int PQWeight(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

// 리스트 정렬 기준 함수 -- 정점 오름차순 정렬
int SortFunction(int v1, int v2) {
	if (v1 < v2)	// v1의 정렬 순서가 앞이다
		return 0;
	else			// v2의 정렬 순서가 앞이다
		return 1;
}

// 생성자 -- 그래프 초기화
ALGraph::ALGraph(int v) 
	:Vnum(v), Enum(0), pqueue(PQWeight)
{
	adjList = new LinkedList[v];
	for (int i = 0; i < v; i++)
		adjList[i].SetSortRule(SortFunction);

	visit = new int[v];
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// 파괴자
ALGraph::~ALGraph() {
	delete[] adjList;
	delete[] visit;
}

// fromV - toV 연결하는 간선 추가
// 인접 리스트의 인덱스: fromV, 리스트의 데이터: toV
void ALGraph::AddEdge(int fromV, int toV, int weight) {
	// 간선 정보는 연결 리스트에 저장
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	Enum++;

	// 간선의 가중치 정보는 우선순위 큐에 저장
	Edge edge = { fromV,toV,weight };
	pqueue.Enqueue(edge);
}

// 그래프의 간선 정보 출력
void ALGraph::ShowEdgeInfo() const {
	using std::cout;
	using std::endl;

	LData data;
	for (int i = 0; i < Vnum; i++) {
		if (adjList[i].LFirst(&data)) {
			cout << char(i + 65) << "과 연결된 정점: ";
			cout << char(data + 65) << ' ';
			while (adjList[i].LNext(&data))
				cout << char(data + 65) << ' ';
		}
		std::cout << std::endl;
	}
}

// DFS 기반으로 그래프를 탐색하여 정점 정보 출력
void ALGraph::ShowVertexInfo(int start) const {
	ArrayStack path;	// 경로 추적을 위한 정점 정보 스택
	int cur = start;	// 현재 탐색 정점
	int next;			// 다음 탐색 정점
	int p;				// 1이면 방문 안한 정점 찾았다는 뜻

	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;

	path.Push(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		visit[cur] = 1;
		p = 0;

		// 연결된 정점 중 방문 안한 정점 찾기
		if (adjList[cur].LFirst(&next)) {
			if (visit[next] == 0)
				p = 1;
			while (p == 0 && adjList[cur].LNext(&next))
				if (visit[next] == 0)
					p = 1;
		}

		// 연결된 정점이 모두 방문한 정점인 경우 -- 백 트래킹
		if (p == 0) {
			next = path.Pop();
		}
		// 방문 안한 정점을 찾은 경우
		else {
			path.Push(cur);
			// 새로 방문할 정점 출력
			std::cout << char(next + 65) << ' ';
		}

		cur = next;
	}

}

// 그래프 가중치 정보 출력
void ALGraph::ShowEdgeWeightInfo() {
	using std::cout;
	using std::endl;

	// 출력용 우선순위 큐 복사
	PQueue temp = pqueue;
	Edge edge;

	while (!temp.isEmpty()) {
		edge = temp.Dequeue();
		cout << "(" << char(edge.v1 + 65) << "-" << char(edge.v2 + 65)
			<< "), w: " << edge.weight << endl;
	}
}



// 간선 정보 제거 함수 -- KruskalMST() 함수에서 이용
void RemoveEdge(LinkedList* adjList, Edge max) {
	int temp;

	if (adjList[max.v1].LFirst(&temp)) {
		if (temp == max.v2)
			adjList[max.v1].LRemove();
		while (adjList[max.v1].LNext(&temp)) {
			if (temp == max.v2) {
				adjList[max.v1].LRemove();
				break;
			}
		}
	}

	if (adjList[max.v2].LFirst(&temp)) {
		if (temp == max.v1)
			adjList[max.v2].LRemove();
		while (adjList[max.v2].LNext(&temp)) {
			if (temp == max.v1) {
				adjList[max.v2].LRemove();
				break;
			}
		}
	}
}

// 간선 정보 복구 함수 -- KruskalMST() 함수에서 이용
void RecoverEdge(LinkedList* adjList, Edge max) {
	adjList[max.v1].LInsert(max.v2);
	adjList[max.v2].LInsert(max.v1);
}


// DFS를 이용한 정점 2개 연결 확인 함수 -- KruskalMST() 함수에서 이용
bool IsConnect(ALGraph* graph, int fromV, int toV) {
	ArrayStack path;	// 경로 추적을 위한 정점 정보 스택
	int cur = fromV;	// 현재 탐색 정점
	int next;			// 다음 탐색 정점
	int p;				// 1이면 방문 안한 정점 찾았다는 뜻

	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < graph->Vnum; i++)
		graph->visit[i] = 0;

	path.Push(cur);
	while (!path.isEmpty() && graph->visit[toV] == 0) {
		graph->visit[cur] = 1;
		p = 0;

		// 연결된 정점 중 방문 안한 정점 찾기
		if (graph->adjList[cur].LFirst(&next)) {
			if (graph->visit[next] == 0)
				p = 1;
			while (p == 0 && graph->adjList[cur].LNext(&next))
				if (graph->visit[next] == 0)
					p = 1;
		}

		// 연결된 정점이 모두 방문한 정점인 경우 -- 백 트래킹
		if (p == 0) {
			next = path.Pop();
		}
		// 방문 안한 정점을 찾은 경우
		else {
			path.Push(cur);
		}

		cur = next;
	}

	return graph->visit[toV] == 1;
}


// 크루스칼 알고리즘을 통해 MST 구현
void ALGraph::KruskalMST() {
	Edge max;			// 높은 가중치의 간선
	Edge temp[30];		// 제거 후 복구한 간선의 정보
	int index = 0;			// temp의 인덱스

	// 간선 개수가 정점 개수보다 1개 적으면 MST 완성
	while (Enum != Vnum - 1) {
		max = pqueue.Dequeue();

		// 간선 제거
		RemoveEdge(adjList, max);

		// 간선 제거 가능 -- 정점 연결하는 경로 있음
		if (IsConnect(this, max.v1, max.v2)) {
			Enum--;
		}
		// 간선 제거 불가능
		else {
			RecoverEdge(adjList, max);
			temp[index++] = max;
		}
	}

	// 우선순위 큐에 간선 정보 복구
	for (int j = 0; j < index; j++)
		pqueue.Enqueue(temp[j]);
}