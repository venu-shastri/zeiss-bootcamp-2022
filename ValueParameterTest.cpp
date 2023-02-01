#include "pch.h"
using ::testing::TestWithParam;
using ::testing::Values;

class Interface {
public:
	virtual int getNumber() = 0;
};

class C:public Interface {
public:
	int getNumber() { return 100; }
};

class D :public Interface {

public:
	int getNumber() { return 100; }
};

class E :public Interface {

public:
	int getNumber() { return 100; }
};

typedef Interface* CreatePrimeTableFunc();

Interface* CreateObjectC() { return new C(); }
Interface* CreateObjectD() { return new D(); }
Interface* CreateObjectE() { return new E(); }


class ObjectFixture : public TestWithParam<CreatePrimeTableFunc*> {
public:
	~ObjectFixture() override { delete basePtr_; }
	void SetUp() override { basePtr_ = (*GetParam())(); }
	void TearDown() override {
		delete basePtr_;
		basePtr_ = nullptr;
	}

protected:
	Interface* basePtr_;
};

INSTANTIATE_TEST_CASE_P(OnAAndB, ObjectFixture,Values(&CreateObjectC,&CreateObjectD,&CreateObjectE));

TEST_P(ObjectFixture, getNumberTest) {
	EXPECT_EQ(basePtr_->getNumber(), 100);
	
}
