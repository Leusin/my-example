/// ���� shared_ptr �� ���������� �������� ���ԵǾ� �߻��ϴ� 
/// ������ ��ȿ���� �ʴ� ������ �߻��ϴ� ���
/// 
/// 2024-01-07

#include <iostream>
#include <memory>

class A
{
public:
	A() { std::cout << "> A �ν��Ͻ� ���� --\n"; }
	~A() { std::cout << "> A �ν��Ͻ� �Ҹ� --\n"; }
	void problemFunction() 
	{
		// ���ο� shared_ptr�� ����� this�� ����
		std::shared_ptr<A> anotherPtr(this);

		std::cout << "\t>> A ���� �ɹ� ���� ��. ���� ī��Ʈ :" << anotherPtr.use_count() << std::endl;

		// �� ����� ����� anotherPtr ��
		// �� ������ A ��ü �ν��Ͻ��� ���� ī��Ʈ�� 0�� �ȴ�
		// �׷��� shared_ptr�� ��ü�� delete �Ѵ�. 
	}
};

int main() 
{
	std::shared_ptr<A> onePtr = std::make_shared<A>();
	//A* onePtr = new A();
	
	//std::cout << "\t>> A ���� ���� ī��Ʈ :" << onePtr.use_count() << std::endl;

	onePtr->problemFunction();
	// �� �Լ��� �����ϴ� ����
	// onePtr�� ���� ��ȿ���� �ʴ� ��ü�� ����Ų��.
	return 0;
} 

//
// HEAP[examples.exe]: Invalid address specified to RtlValidateHeap( 0000026F24260000, 0000026F2426A900 )
// �ߴ��� ���(__debugbreak() �� �Ǵ� ������ ȣ��)�� examples.exe���� ����Ǿ����ϴ�.
//

//
// std::shared_ptr�� ���� ī��Ʈ�� 0�� �Ǹ鼭 ��ü�� �����ϴ� 
// ��Ŀ������ ��� �ϴ� ���۰��� �ٸ��� �۵��Ѵ�.
// 
// std::shared_ptr�� ��ü�� �����ϴ� å���� ���� Ƚ���� 0�� �Ǹ鼭 
// ��ü�� �Ҹ�� �������� ���ε�, problemFunction()���� �̹� 
// ���� Ƚ���� ���ҵǰ� ���ܰ� �߻��� ���������� onePtr�� ������ 
// �� ��ü�� ����Ű�� �ֱ� �����̴�.
//
// ���� �����ϸ� ������ ����.
// 
// 1. main �Լ����� onePtr�� �����ϰ� �ش� ��ü�� ����ŵ�ϴ�.
// 2. problemFunction()�� ȣ��Ǹ鼭 onePtr�� ����Ű�� ��ü�� �Ҹ��ڰ� ȣ��˴ϴ�.
// 3. problemFunction()���� ���ܰ� �߻��ϰ� ���ܸ� ó������ �ʾ� �Լ��� �������� ��, onePtr�� �̹� ������ ��ü�� ����Ű�� �˴ϴ�.
// 4. ���� main �Լ����� onePtr�� ���� ������ ��ü�� �����Ϸ��� �� �� ���ܰ� �߻��մϴ�.
// 