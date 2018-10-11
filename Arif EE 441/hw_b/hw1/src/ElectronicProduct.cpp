#include "ElectronicProduct.h"
#include <iostream>
// itemNumber declared externally
extern int itemNumber;

// Constructer
ElectronicProduct::ElectronicProduct()
{

}

// Device benefit for every type
float ElectronicProduct::findDeviceBenefit() {
    if(productType=="smartPhone") {
            deviceBenefit=(has4g+hasBluetooth+hasFrontCamera)*deviceCpu*deviceMemory*deviceRam*screenSize*batteryLife;
    }
    else if(productType=="laptopComp") {
            deviceBenefit=(hasBluetooth+hasHdmi+findBenefitOfOpticalDevice())*deviceCpu*deviceMemory*deviceRam*screenSize*batteryLife;
    }
    else if(productType=="gameConsole") {
            deviceBenefit=(hasBluetooth+hasWifi+hasUsb+findBenefitOfOpticalDevice())*deviceCpu*deviceMemory*deviceRam;
    }
    else {
            deviceBenefit=(hasWifi+hasHdmi+hasUsb)*screenSize;
    }
    return deviceBenefit;
}
//  Find the benefit of optical device
int ElectronicProduct::findBenefitOfOpticalDevice(){
    if(opticalDevice=="cd") return 1;
    else if(opticalDevice=="dvd") return 2;
    else return 3;
}

float ElectronicProduct::calcPriceOverPerformance() {
    return price/deviceBenefit;
}
/*
    Functions returns a array of bool, to show product properties
*/
void ElectronicProduct::findRelevantProperties(bool *arr) {
    if(productType=="smartPhone") {
        bool properties[]={1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1};
        for(int i=0;i<17;i++) {
            arr[i]=properties[i];
        }
    }
    else if(productType=="laptopComp") {
        bool properties[]={1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,1};
        for(int i=0;i<17;i++) {
            arr[i]=properties[i];

        }
    }
    else if(productType=="gameConsole") {
        bool properties[]={1,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1};
        for(int i=0;i<17;i++) {
            arr[i]=properties[i];
        }
    }
    else {
        bool properties[]={1,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1};
        for(int i=0;i<17;i++) {
            arr[i]=properties[i];
        }
    }
    return;
}
