#include "pch.h"
#include "InteractionTesting.h"
#include <stdio.h>
/*
The objective of the code is to monitor battery temperature and prevent damage:

Classify the temperature measurement as being too high or too low. 
This classification depends on the type of cooling. 
With active cooling, the battery can reach higher temperatures before taking action.
Transmit the classification to take action: 
When the system has a controller, send the classification to it.
In the absence of a controller, 
send the classification via email. In this project, the transmission is 'simulated' by printing on the console.
*/



//testable,pure function
//CCN value =?
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) {
        return TOO_LOW;
    }
    if (value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

//testable 
// dependency -> test friendly
BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
    int lowerLimit = 0;
    int upperLimit = 0;
    switch (coolingType) {
    case PASSIVE_COOLING:
        lowerLimit = 0;
        upperLimit = 35;
        break;
    case HI_ACTIVE_COOLING:
        lowerLimit = 0;
        upperLimit = 45;
        break;
    case MED_ACTIVE_COOLING:
        lowerLimit = 0;
        upperLimit = 40;
        break;
    }
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

//void checkAndAlert(
//    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
//
//    BreachType breachType = classifyTemperatureBreach(
//        batteryChar.coolingType, temperatureInC
//    );
//
//    switch (alertTarget) {
//    case TO_CONTROLLER:
//        sendToController(breachType);
//        break;
//    case TO_EMAIL:
//        sendToEmail(breachType);
//        break;
//    }
//}

//
//void checkAndAlert(
//    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,
//    void (*fcontroller)(BreachType), void (*femail)(BreachType))
//{
//
//    BreachType breachType = classifyTemperatureBreach(
//        batteryChar.coolingType, temperatureInC
//    );
//
//    switch (alertTarget) {
//    case TO_CONTROLLER:
//        (*fcontroller)(breachType);
//        break;
//    case TO_EMAIL:
//        (*femail)(breachType);
//        break;
//    }
//}

class IEmailManager {
public: virtual void sendEmail(BreachType breachType) = 0;
};

class EmailManager :public IEmailManager {

public: virtual void sendEmail(BreachType breachType) {
    const char* recepient = "a.b@c.com";
    switch (breachType) {
    case TOO_LOW:
        printf("To: %s\n", recepient);
        printf("Hi, the temperature is too low\n");
        break;
    case TOO_HIGH:
        printf("To: %s\n", recepient);
        printf("Hi, the temperature is too high\n");
        break;
    case NORMAL:
        break;
    }
}
};

class IControllerManager {
public:
    virtual ~IControllerManager(){}
    virtual void updateController(BreachType breachType) = 0;
};

class ControllerManager :public ControllerManager {

public:virtual void updateController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}
};


void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,IControllerManager* ptrToController,IEmailManager* ptrEmailManager)
{

    BreachType breachType = classifyTemperatureBreach(
        batteryChar.coolingType, temperatureInC
    );

    switch (alertTarget) {
    case TO_CONTROLLER:
        ptrToController->updateController(breachType);
        break;
    case TO_EMAIL:
        ptrEmailManager->sendEmail(breachType);
        break;
    }
}

//// excluded from unit test
//void sendToController(BreachType breachType) {
//   
//}
//
////exculded from unit test
//void sendToEmail(BreachType breachType) {
//   
//}


//Test Environment

//using gmock to generate mock object
class MockController :public IControllerManager {
public:
    MOCK_METHOD(void, updateController, (BreachType), (override));
    
};

TEST(CheckAndAlertTestCase, InteractionTest) {


    MockController controller;                              // #2
    EXPECT_CALL(controller, updateController(BreachType::TOO_LOW))                  // #3
        .Times(AtLeast(1));
    BatteryCharacter bCharObj;
    checkAndAlert(AlertTarget::TO_CONTROLLER, bCharObj, 30, controller, nullptr);


}
