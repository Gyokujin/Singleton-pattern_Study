#include <iostream>
using namespace std;

// 객체가 한개 이상 생성되지 않는 클래스
class CSingleObject
{
private:
	static CSingleObject* m_pSingObject; // 동적 할당 객체(인스턴스)를 활용하여 관리한다.
	int nData = 5;

	CSingleObject()
	{
		cout << "생성자 실행 " << endl;
	}

	~CSingleObject()
	{
		// delete(m_pSingObject); 클래스의 다른 함수에서 삭제하도록 한다.
		cout << "소멸자 실행 " << endl;
	}

public:
	static CSingleObject* GetInstance() // 최초 1회 객체를 생성하여 return 한다.
	{
		if (!m_pSingObject) // 하나만 존재해야 하기 때문에 조건을 둔다.
		{
			cout << "객체 최초 1회 생성" << endl;
			m_pSingObject = new CSingleObject();
		}

		return m_pSingObject;
		// return new CSingleObject();//객체가 호출될때마다 새로 생성되는 것은 싱글톤이 아니다.
	}

	void Release()
	{
		cout << "Release() 실행" << endl;

		if (m_pSingObject) // 값이 있는지 확인하고 삭제한다.
		{
			delete(m_pSingObject); // delete를 한 이후에 동적 할당 객체를 지우도록 한다. 반대로 하면 소멸자가 실행되지 않는다.
			m_pSingObject = NULL;
		}
	}

	void ShowData()
	{
		cout << "Data : " << nData << endl;
	}

	void UpdateData()
	{
		nData++;
	}
};

CSingleObject* CSingleObject::m_pSingObject = NULL; // 정적 멤버 변수 : 정적 멤버 변수는 객체가 생성전에 할당 되어야 한다.

void main()
{
	CSingleObject* pSingleObject = NULL;
	CSingleObject* pArrSingleObject[2];

	pSingleObject = CSingleObject::GetInstance();
	cout << pSingleObject << endl;

	for (int i = 0; i < size(pArrSingleObject); i++)
	{
		pArrSingleObject[i] = CSingleObject::GetInstance(); // CSingleObject의 객체는 단 하나이기 때문에 결국 같은 주소를 가지고 있다.

		cout << pArrSingleObject[i] << endl;
		cout << pSingleObject << endl;

		pSingleObject->UpdateData();
		pSingleObject->ShowData();
	}

	pArrSingleObject[0]->ShowData(); // 모두 같은 주소이기 때문에 값도 결국 같다.
	pArrSingleObject[1]->ShowData();
	pSingleObject->ShowData();

	pSingleObject->UpdateData();
	pSingleObject->ShowData();

	pSingleObject->Release();
	pArrSingleObject[0]->ShowData(); // 원본 객체는 소멸되었기 때문에 해당 객체의 주소를 가지고 있는 pArrSingleObject[0] 또한 없어지게 된다.
}