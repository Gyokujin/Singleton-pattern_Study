#include <iostream>
using namespace std;

// ��ü�� �Ѱ� �̻� �������� �ʴ� Ŭ����
class CSingleObject
{
private:
	static CSingleObject* m_pSingObject; // ���� �Ҵ� ��ü(�ν��Ͻ�)�� Ȱ���Ͽ� �����Ѵ�.
	int nData = 5;

	CSingleObject()
	{
		cout << "������ ���� " << endl;
	}

	~CSingleObject()
	{
		// delete(m_pSingObject); Ŭ������ �ٸ� �Լ����� �����ϵ��� �Ѵ�.
		cout << "�Ҹ��� ���� " << endl;
	}

public:
	static CSingleObject* GetInstance() // ���� 1ȸ ��ü�� �����Ͽ� return �Ѵ�.
	{
		if (!m_pSingObject) // �ϳ��� �����ؾ� �ϱ� ������ ������ �д�.
		{
			cout << "��ü ���� 1ȸ ����" << endl;
			m_pSingObject = new CSingleObject();
		}

		return m_pSingObject;
		// return new CSingleObject();//��ü�� ȣ��ɶ����� ���� �����Ǵ� ���� �̱����� �ƴϴ�.
	}

	void Release()
	{
		cout << "Release() ����" << endl;

		if (m_pSingObject) // ���� �ִ��� Ȯ���ϰ� �����Ѵ�.
		{
			delete(m_pSingObject); // delete�� �� ���Ŀ� ���� �Ҵ� ��ü�� ���쵵�� �Ѵ�. �ݴ�� �ϸ� �Ҹ��ڰ� ������� �ʴ´�.
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

CSingleObject* CSingleObject::m_pSingObject = NULL; // ���� ��� ���� : ���� ��� ������ ��ü�� �������� �Ҵ� �Ǿ�� �Ѵ�.

void main()
{
	CSingleObject* pSingleObject = NULL;
	CSingleObject* pArrSingleObject[2];

	pSingleObject = CSingleObject::GetInstance();
	cout << pSingleObject << endl;

	for (int i = 0; i < size(pArrSingleObject); i++)
	{
		pArrSingleObject[i] = CSingleObject::GetInstance(); // CSingleObject�� ��ü�� �� �ϳ��̱� ������ �ᱹ ���� �ּҸ� ������ �ִ�.

		cout << pArrSingleObject[i] << endl;
		cout << pSingleObject << endl;

		pSingleObject->UpdateData();
		pSingleObject->ShowData();
	}

	pArrSingleObject[0]->ShowData(); // ��� ���� �ּ��̱� ������ ���� �ᱹ ����.
	pArrSingleObject[1]->ShowData();
	pSingleObject->ShowData();

	pSingleObject->UpdateData();
	pSingleObject->ShowData();

	pSingleObject->Release();
	pArrSingleObject[0]->ShowData(); // ���� ��ü�� �Ҹ�Ǿ��� ������ �ش� ��ü�� �ּҸ� ������ �ִ� pArrSingleObject[0] ���� �������� �ȴ�.
}