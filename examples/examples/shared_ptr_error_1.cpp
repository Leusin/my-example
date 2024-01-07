/// 여러 shared_ptr 가 독립적으로 소유권을 갖게되어 발생하는 
/// 문제중 유효하지 않는 참조가 발생하는 경우
/// 
/// 2024-01-07

#include <iostream>
#include <memory>

class A
{
public:
	A() { std::cout << "> A 인스턴스 생성 --\n"; }
	~A() { std::cout << "> A 인스턴스 소멸 --\n"; }
	void problemFunction() 
	{
		// 새로운 shared_ptr를 만들고 this를 전달
		std::shared_ptr<A> anotherPtr(this);

		std::cout << "\t>> A 여긴 맴버 변수 안. 참조 카운트 :" << anotherPtr.use_count() << std::endl;

		// 이 블록을 벗어나면 anotherPtr 는
		// 본 예제의 A 객체 인스턴스의 참조 카운트는 0이 된다
		// 그러면 shared_ptr이 객체를 delete 한다. 
	}
};

int main() 
{
	std::shared_ptr<A> onePtr = std::make_shared<A>();
	//A* onePtr = new A();
	
	//std::cout << "\t>> A 현재 참조 카운트 :" << onePtr.use_count() << std::endl;

	onePtr->problemFunction();
	// 위 함수를 실행하는 순간
	// onePtr는 더는 유효하지 않는 객체를 가리킨다.
	return 0;
} 

//
// HEAP[examples.exe]: Invalid address specified to RtlValidateHeap( 0000026F24260000, 0000026F2426A900 )
// 중단점 명령(__debugbreak() 문 또는 유사한 호출)이 examples.exe에서 실행되었습니다.
//

//
// std::shared_ptr이 참조 카운트가 0이 되면서 객체를 해제하는 
// 메커니즘을 기대 하는 동작과는 다르게 작동한다.
// 
// std::shared_ptr이 객체를 해제하는 책임은 참조 횟수가 0이 되면서 
// 객체가 소멸될 때까지의 것인데, problemFunction()에서 이미 
// 참조 횟수가 감소되고 예외가 발생한 시점에서는 onePtr이 여전히 
// 그 객체를 가리키고 있기 때문이다.
//
// 따라서 정리하면 다음과 같다.
// 
// 1. main 함수에서 onePtr를 생성하고 해당 객체를 가리킵니다.
// 2. problemFunction()이 호출되면서 onePtr이 가리키는 객체의 소멸자가 호출됩니다.
// 3. problemFunction()에서 예외가 발생하고 예외를 처리하지 않아 함수를 빠져나올 때, onePtr은 이미 삭제된 객체를 가리키게 됩니다.
// 4. 따라서 main 함수에서 onePtr을 통해 삭제된 객체에 접근하려고 할 때 예외가 발생합니다.
// 