#include "pch.h"
#include<string>
using namespace std;
//Abstraction Using Runtime Polymorphism
class ILogger {

public: virtual void writeLogContent(string content) = 0;

};

class ConsoleLogger :public ILogger {
public:
    virtual void writeLogContent(string content) {
        cout << content;
    }
};


char getSizeNameForCms(int cms,ILogger *loggerRef) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
        loggerRef->writeLogContent("Small Size");
      
    }
    else if (cms >= 38 && cms < 42) {
        sizeName = 'M';
        loggerRef->writeLogContent("Medium Size");
    }
    else if (cms >= 42) {
        sizeName = 'L';
        loggerRef->writeLogContent("Large Size");
    }
    return sizeName;
}

void mainProgram() {
    ILogger* baseRef = new ConsoleLogger();
    getSizeNameForCms(30, baseRef);
}

//Test Env

class FakeLogger :public ILogger {
public:
    virtual void writeLogContent(string content) {
        //
    }
};

TEST(AssignmentTestSuite, TestName) {
    ILogger* baseRef = new FakeLogger();
    char actualSizeName = getSizeNameForCms(30,baseRef);
    EXPECT_EQ(actualSizeName, 'S');
}
