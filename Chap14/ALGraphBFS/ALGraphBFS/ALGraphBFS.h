// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ� BFS ����
// "ALGraph.h, cpp" -- ���� ����Ʈ ��� �׷��� Ȱ���ϱ� ���� �Բ� ������
// "LinkedList2.h, cpp" -- "ALGraph.h, cpp"���� ���ԵǾ� �Բ� ������
// "ArrayQueue.h, cpp" -- ��� ������ ���� ť�� �̿��ϱ� ���� �Բ� ������
// LinkedList�� LData Ÿ�԰� ArrayStack�� Data Ÿ�԰� ���� Ÿ���� �����ؾ� �Ѵ� -- int��
#ifndef ALGRAPHBFS_H_
#define ALGRAPHBFS_H_

#include "ALGraph.h"
#include "LinkedList2.h"
#include "ArrayQueue.h"

// ALGraph�� ����Ͽ� DFS ������ ���� ��������� �Լ��� �߰�
class ALGraphBFS : public ALGraph {
private:
	int* visit;	// �湮 ���� �迭 -- �ε���: ����

public:
	ALGraphBFS(int v);
	~ALGraphBFS();

	void ShowVertexInfo(int start) const;
};

#endif