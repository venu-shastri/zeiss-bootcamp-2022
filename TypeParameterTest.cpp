#pragma once

#include "pch.h"

class I {
public:
	virtual int getNumber() = 0;
};

class A:public I {
public:
	int getNumber() { return 100; }
};

class B :public I{

public:
	int getNumber() { return 200; }
};

template <class T>
I* CreateObject();

template <>
I* CreateObject<A>() {
	return new A();
}

template <>
I* CreateObject<B>() {
	return new B();
}

template <class T>
class ObjectTest : public testing::Test {
protected:
	// The ctor calls the factory function to create a prime table
	// implemented by T.
	ObjectTest() : basePtr_(CreateObject<T>()) {}

	~ObjectTest() override { delete basePtr_; }

	// Note that we test an implementation via the base interface
	// instead of the actual implementation class.  This is important
	// for keeping the tests close to the real world scenario, where the
	// implementation is invoked via the base interface.  It avoids
	// got-yas where the implementation class has a method that shadows
	// a method with the same name (but slightly different argument
	// types) in the base interface, for example.
	I* const basePtr_;
};

using testing::Types;
typedef Types<A, B> Implementations;

TYPED_TEST_CASE(ObjectTest, Implementations);

TYPED_TEST(ObjectTest,getNumberTest) {
	// Inside the test body, you can refer to the type parameter by
	// TypeParam, and refer to the fixture class by TestFixture.  We
	// don't need them in this example.

	// Since we are in the template world, C++ requires explicitly
	// writing 'this->' when referring to members of the fixture class.
	// This is something you have to learn to live with.
	EXPECT_EQ(this->basePtr_->getNumber(),100); // A,B
	
	
}
