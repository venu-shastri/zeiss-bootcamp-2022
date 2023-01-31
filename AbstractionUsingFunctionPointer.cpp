#include "pch.h"
#include<string>
using namespace std;
//CCN value ?

void writeToConsole(string content) {
    cout << content;
}


char getSizeNameForCms(int cms,void(*logger)(string)) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
       // writeToConsole("Small Size");
        (*logger)("Small Size");
    }
    else if (cms >= 38 && cms < 42) {
        sizeName = 'M';
        (*logger)("Medium Size");
    }
    else if (cms >= 42) {
        sizeName = 'L';
        (*logger)("Large Size");
    }
    return sizeName;
}

//Test Environment

void fakeWriteToConsole(string content) {
    //
}
TEST(AssignmentTestSuite, SmallSizeTest) {

   char actualSizeName= getSizeNameForCms(30,&fakeWriteToConsole);
   EXPECT_EQ(actualSizeName,'S');


}
