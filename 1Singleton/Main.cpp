#include <iostream>
using namespace std;

// 객체가 한개 이상 생성되지 않는 클래스
class CSingleObject
{
private:
	int nData = 5;

public:
	CSingleObject()
	{
		cout << "생성자" << endl;
		ShowData();
	};

	void ShowData()
	{
		cout << "Data : " << nData << endl;
	}
};

void main()
{
	CSingleObject instanceObj; // 객체를 정적 할당한다.(컴파일 전에 메모리 할당)
	// csing

	//	CSingleObject* pSingleObject; // 객체의 포인터만 선언했으므로 객체가 생성되지 않았다.
	/*cout << &pSingleObject << endl;

	CSingleObject* pSingleObject = NULL;
	pSingleObject->*/
}