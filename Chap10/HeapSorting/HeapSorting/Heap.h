// 배열 기반 힙(Heap) 구현 -- 우선순위가 높을수록 앞 부분에 위치
// 힙: 완전 이진 트리
#ifndef HEAP_H_
#define HEAP_H_

const int arrLen = 100;	// 힙 배열 크기
typedef int HData;		// 힙 원소 데이터 -- int형

// 값이 작을수록 높은 우선순위로 간주
typedef int (*PriorityComp)(HData d1, HData d2);

// Heap 클래스
class Heap {
private:
	PriorityComp comp;	// 우선순위 비교용 함수 포인터
	HData arr[arrLen];
	int num;	// 현재 힙에 들어있는 원소 개수

public:
	Heap(PriorityComp pc) :num(0), comp(pc) {}
	~Heap() {}

	bool isEmpty() const { return num == 0; }
	void Insert(HData data);
	int GetChildIndex(int index) const;
	HData Delete();
};

#endif