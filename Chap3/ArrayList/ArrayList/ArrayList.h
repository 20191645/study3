// 순차 리스트(ArrayList) 구현
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

const int arrLen = 100;

// ArrayList에 담기는 데이터 타입에 따라 typedef 선언을 수정한다
typedef int LData;

class ArrayList {
private:
	LData arr[arrLen];
	int index;	// 현재 리스트가 가리키는 인덱스
	int num;	// 현재 리스트에 담긴 데이터 개수

public:
	ArrayList();
	~ArrayList() {}

	void insert(LData data);
	bool first(LData* pdata);
	bool next(LData* pdata);
	LData remove();
	int count() const;
};

#endif