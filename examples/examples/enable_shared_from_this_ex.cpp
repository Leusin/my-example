/// enable_shared_from_this 클래스 와
/// shared_from_this() 를 사용하는 예제
/// 
/// 2024-01-07

#include <memory>
#include <iostream>

struct C : public std::enable_shared_from_this<C>
{
	int val;
	std::shared_ptr<C> share_more()
	{
		return shared_from_this();
	}
};

int main()
{
	auto oneSPtr = std::make_shared<C>();

	std::cout << oneSPtr.use_count() << std::endl;

	auto anotherSPtr = oneSPtr->share_more();

	std::cout << oneSPtr.use_count() << std::endl;

	auto otherSPtr = oneSPtr->shared_from_this();

	std::cout << oneSPtr.use_count() << std::endl;

	otherSPtr->val = 3;
	std::cout << "anotherSPtr->val == " << anotherSPtr->val << std::endl;
	std::cout << "oneSPtr->val == " << oneSPtr->val << std::endl;
	return 0;
}