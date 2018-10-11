#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H
#include <string>

using namespace std;

class ElectronicProduct
{
    public:
        ElectronicProduct();

        // Define all properties as a public variables
        // No need for get and set methods.
        string productName;
        int productID;
        string productType;
        float deviceCpu=0;
        int deviceRam=0;
        int deviceMemory=0;
        float screenSize=0;
        float batteryLife=0;
        bool has4g=0;
        bool hasBluetooth=0;
        bool hasWifi=0;
        bool hasHdmi=0;
        bool hasUsb=0;
        bool hasFrontCamera=0;
        string opticalDevice="cd";
        float price=0;
        float deviceBenefit=0;
        float priceOverPerformance=0;
        void findRelevantProperties(bool* arr);
        int findBenefitOfOpticalDevice();
        float  findDeviceBenefit();
        float   calcPriceOverPerformance();
    private:





};

#endif // ELECTRONICPRODUCT_H
