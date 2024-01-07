/// ���� shared_ptr �� ���������� �������� ���ԵǾ� �߻��ϴ� 
/// ������ ��ü�� �ι� �̻� �Ҵ� ���� �Ǵ� ���
/// 
/// 2024-01-07

#include <iostream>
#include <memory>

class B
{
public:
	B() { std::cout << "> B() -\n"; }
	~B() { std::cout << "> ~B() -\n"; }

	// �Լ� ������ this�� ���� shared_ptr�� �����ϰ� ��ȯ
	std::shared_ptr<B> createSharedPtr() 
	{
		std::cout << "   > B createSharedPtr() --\n";
		return std::shared_ptr<B>(this);
	}
};

int main() {
	B* obj = new B();
	// shared_ptr�� ���� ��ü�� ����
	std::shared_ptr<B> onePtr = obj->createSharedPtr();

	// ���ο� shared_ptr�� �����Ͽ� ���� ��ü�� ����
	std::shared_ptr<B> antherPtr(obj);
	return 0;
}