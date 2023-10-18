// ���� ����Ʈ(AdjacentList) ��� �׷��� ����
// ���� ����Ʈ�� Ȱ���ϱ� ������ "LinkedList2.h, cpp"�� �Բ� ������
// LinkedList�� LData Ÿ�԰� ���� Ÿ���� �����ؾ� �Ѵ� -- int��
#ifndef ALGRAPH_H_
#define ALGRAPH_H_

#include "LinkedList2.h"

enum { A, B, C, D, E, F, G, H, I, J };	// ���� �̸� ���ȭ -- adjList�� �ε���

class ALGraph {
// protected�� ������ �����Ͽ� ��ӹ޴� DFS, BFS Ŭ�������� ����� �� �ְ�
protected:
	LinkedList* adjList;	// ������ ������ ���� ����Ʈ
	int Vnum;				// ���� ����
	int Enum;				// ���� ����

public:
	ALGraph(int v);
	~ALGraph();

	void AddEdge(int fromV, int toV);
	void ShowEdgeInfo() const;
};

#endif