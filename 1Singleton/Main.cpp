#include <iostream>
using namespace std;

// ��ü�� �Ѱ� �̻� �������� �ʴ� Ŭ����
class CSingleObject
{
private:
	int nData = 5;

public:
	CSingleObject()
	{
		cout << "������" << endl;
		ShowData();
	};

	void ShowData()
	{
		cout << "Data : " << nData << endl;
	}
};

void main()
{
	CSingleObject instanceObj; // ��ü�� ���� �Ҵ��Ѵ�.(������ ���� �޸� �Ҵ�)
	// csing

	//	CSingleObject* pSingleObject; // ��ü�� �����͸� ���������Ƿ� ��ü�� �������� �ʾҴ�.
	/*cout << &pSingleObject << endl;

	CSingleObject* pSingleObject = NULL;
	pSingleObject->*/
}