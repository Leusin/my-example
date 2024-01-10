/// 여러 shared_ptr 가 독립적으로 소유권을 갖게되어 발생하는 
/// 문제중 객체가 두번 이상 할당 해제 되는 경우
/// 
/// 2024-01-07

#include <iostream>
#include <memory>

class B
{
public:
	B() { std::cout << "> B() -\n"; }
	~B() { std::cout << "> ~B() -\n"; }

	// 함수 내에서 this를 통해 shared_ptr를 생성하고 반환
	std::shared_ptr<B> createSharedPtr() 
	{
		std::cout << "   > B createSharedPtr() --\n";
		return std::shared_ptr<B>(this);
	}
};

int main() {
	B* obj = new B();
	// shared_ptr를 통해 객체를 참조
	std::shared_ptr<B> onePtr = obj->createSharedPtr();

	// 새로운 shared_ptr를 생성하여 같은 객체를 참조
	std::shared_ptr<B> antherPtr(obj);
	return 0;
}