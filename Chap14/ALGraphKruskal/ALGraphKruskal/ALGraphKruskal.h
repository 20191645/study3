// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ�, ũ�罺Į �˰��� ��� �ּ� ���� Ʈ��(MST) ����
// "LinkedList2.h, cpp" -- ���� ����Ʈ Ȱ���Ͽ� ���� ���� ����
// "PriorityQueue.h, cpp" -- ����ġ �������� ���� ������ ���� �켱���� ť
// "PQueueHeap.h, cpp" -- "PriorityQueue.h, cpp"�� ���ԵǾ� �Բ� ������
// "ArrayStack.h, cpp" -- DFS Ž���� ���� ����
#ifndef ALGRAPHKRUSKAL_H_
#define ALGRAPHKRUSKAL_H_

#include "ArrayStack.h"
#include "LinkedList2.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J };	// ���� �̸� ���ȭ

// ũ�罺Į �˰����� ���� ALGraph
class ALGraph {
private:
	int Vnum;				// ���� ����
	int Enum;				// ���� ����
	int* visit;				// �湮 ����
	LinkedList* adjList;	// ���� ���� -- ������ Ÿ��: int
	PQueue pqueue;			// ������ ����ġ ���� -- ������ Ÿ��: Edge

public:
	ALGraph(int v);
	~ALGraph();

	void AddEdge(int fromV, int toV, int weight);
	void ShowEdgeInfo() const;
	void ShowVertexInfo(int start) const;

	void KruskalMST();
	void ShowEdgeWeightInfo();

	// KruskalMST() �Լ����� �̿�
	friend bool IsConnect(ALGraph* graph, int fromV, int toV);
};

#endif