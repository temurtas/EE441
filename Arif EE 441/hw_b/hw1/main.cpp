#include <iostream>
#include <ElectronicProduct.h>
#include <fstream>
#include <cstdlib>
using namespace std;

// The maximum product number that will be stored in the system.
const int maxCapacity=1000;

// The number of item that is in the system. Initially zero.
int itemNumber=0;

ElectronicProduct productList[maxCapacity];

/*
    Shows the product type list and return a string depending on selection
*/
string chooseType() {
    int dummy;
    string selection;
    cout<<"Choose a product type: \n 1> smartPhone \n 2> laptopComp \n 3> gameConsole \n 4> tv"<<endl;
    cin>>dummy;
    switch(dummy) {
        case 1:
            selection="smartPhone";
            break;
        case 2:
            selection="laptopComp";
            break;
        case 3:
            selection="gameConsole";
            break;
        case 4:
            selection="tv";
            break;
        default:
            selection="err";
    }
    return selection;
    }

/*
    This function shows the adding new product screen.
    Returns 1 if product is added.
    Returns 0 if there is error and shows the error.
*/

bool newProduct() {
    // Some input variables used to take data from user.
    string stringInput,productType;
    int intInput;
    float floatInput;
    bool boolInput;
    bool propertiesArr[17];

    ElectronicProduct product;
    productType=chooseType();
    if (productType=="err") {
        cout<<"ERROR: wrong selection."<<endl;
        return 0;
    }
    else {
        product.productType=productType;
        product.productID=itemNumber;
    }

    product.findRelevantProperties(propertiesArr);

    // for every property take values  from user
    if(*(propertiesArr+1)) {
        cout<<"Product name:"<<endl;
        cin>>stringInput;
        product.productName=stringInput;
    }

    if(*(propertiesArr+2)) {
        cout<<"Device CPU(in GHz):"<<endl;
        cin>>floatInput;
        product.deviceCpu=floatInput;
    }

    if(*(propertiesArr+3)) {
        cout<<"Device RAM(in GB):"<<endl;
        cin>>intInput;
        product.deviceRam=intInput;
    }

    if(*(propertiesArr+4)) {
        cout<<"Device Memory(in GB):"<<endl;
        cin>>intInput;
        product.deviceMemory=intInput;
    }

    if(*(propertiesArr+5)) {
        cout<<"Screen Size(in Inches):"<<endl;
        cin>>floatInput;
        product.screenSize=floatInput;
    }

    if(*(propertiesArr+6)) {
        cout<<"Battery life(in hours):"<<endl;
        cin>>floatInput;
        product.batteryLife=floatInput;
    }

    if(*(propertiesArr+7)) {
        cout<<"Has 4g:"<<endl;
        cin>>boolInput;
        product.has4g=boolInput;
    }

    if(*(propertiesArr+8)) {
        cout<<"Has Bluetooth:"<<endl;
        cin>>boolInput;
        product.hasBluetooth=boolInput;
    }

    if(*(propertiesArr+9)) {
        cout<<"Has Wifi:"<<endl;
        cin>>boolInput;
        product.hasWifi=boolInput;
    }

    if(*(propertiesArr+10)) {
        cout<<"Has HDMI:"<<endl;
        cin>>boolInput;
        product.hasHdmi=boolInput;
    }

    if(*(propertiesArr+11)) {
        cout<<"Has USB:"<<endl;
        cin>>boolInput;
        product.hasUsb=boolInput;
    }

    if(*(propertiesArr+12)) {
        cout<<"Has front camera:"<<endl;
        cin>>boolInput;
        product.hasFrontCamera=boolInput;
    }

    if(*(propertiesArr+13)) {
        cout<<"Optical Device (write from below items): \n -bluray \n -cd \n -dvd"<<endl;
        cin>>stringInput;
        if(stringInput=="bluray" || stringInput=="cd" || stringInput=="dvd") {
            product.opticalDevice=stringInput;
        }
        else {
            cout<<"ERROR: write a correct name."<<endl;
            return 0;
        }
    }

    if(*(propertiesArr+14)) {
        cout<<"Price (in TL):"<<endl;
        cin>>floatInput;
        product.price=floatInput;
    }
    // Check the capacity of list
    if(itemNumber< maxCapacity -1) {
            // if capacity not exceeded add new item to the list
            productList[itemNumber]=product;
            itemNumber++;
            return 1;
    }
    else {
            cout<<"ERROR: Item capacity is full. New item cannot be added."<<endl;
            return 0;
    }
}

/*
    Shows the product with given pid
*/
bool showProduct(int pid) {
    ElectronicProduct product;
    bool propertiesArr[17];
    product=productList[pid];
    // Get the properties of device
    product.findRelevantProperties(propertiesArr);

    // for every property take values  from user
    if(*(propertiesArr)) {
        cout<<"Product ID: "<<product.productID<<endl;
    }
    if(*(propertiesArr+1)) {
        cout<<"Product name: "<<product.productName<<endl;
    }

    if(*(propertiesArr+2)) {
        cout<<"Device CPU(in GHz): "<<product.deviceCpu<<endl;
    }

    if(*(propertiesArr+3)) {
        cout<<"Device RAM(in GB): "<<product.deviceRam<<endl;
    }

    if(*(propertiesArr+4)) {
        cout<<"Device Memory(in GB): "<<product.deviceMemory<<endl;
    }

    if(*(propertiesArr+5)) {
        cout<<"Screen Size(in Inches): "<<product.screenSize<<endl;
    }

    if(*(propertiesArr+6)) {
        cout<<"Battery life(in hours): "<<product.batteryLife<<endl;
    }

    if(*(propertiesArr+7)) {
        cout<<"Has 4g:"<<product.has4g<<endl;
    }

    if(*(propertiesArr+8)) {
        cout<<"Has Bluetooth: "<<product.hasBluetooth<<endl;
    }

    if(*(propertiesArr+9)) {
        cout<<"Has Wifi:"<<product.hasWifi<<endl;
    }

    if(*(propertiesArr+10)) {
        cout<<"Has HDMI:"<<product.hasHdmi<<endl;
    }

    if(*(propertiesArr+11)) {
        cout<<"Has USB:"<<product.hasUsb<<endl;
    }

    if(*(propertiesArr+12)) {
        cout<<"Has front camera:"<<product.hasFrontCamera<<endl;
    }

    if(*(propertiesArr+13)) {
        cout<<"Optical Device: "<<product.opticalDevice<<endl;
    }

    if(*(propertiesArr+14)) {
        cout<<"Price (in TL): "<<product.price<<endl;
    }
    return 1;
}

/*
    Shows all the product that are added to system.
*/
bool showAllProducts() {
        cout<<"PID       TYPE             NAME"<<endl;
        cout<<"==============================="<<endl;
    for(int i=0;i<itemNumber;i++) {
        ElectronicProduct product;
        product=productList[i];
        cout<<product.productID<<" - "<<product.productType<<" - "<<product.productName<<endl;
    }
    return 1;
}


bool convertToBool(string str){
    if(str=="True") return 1;
    else return 0;
}
/*
    creates product with read data
*/
bool createProductWithData(string arr[]) {
    bool propertiesArr[17];
    ElectronicProduct product;
    product.productName=arr[0];
    string type=arr[1];
    if(type=="GameConsole") {
        product.productType="gameConsole";
    }
    else if (type=="TV") {
        product.productType="tv";
    }
    else if (type=="Smartphone") {
        product.productType="smartPhone";
    }
    else {
        product.productType="laptopComp";
    }
    product.productID=itemNumber;
    product.findRelevantProperties(propertiesArr);

    // for every property take values  from user
    if(*(propertiesArr+2)) {
        product.deviceCpu=atof(arr[2].c_str());

    }

    if(*(propertiesArr+3)) {
        product.deviceRam=atoi(arr[3].c_str());

    }

    if(*(propertiesArr+4)) {
        product.deviceMemory=atoi(arr[4].c_str());

    }

    if(*(propertiesArr+5)) {
        product.screenSize=atof(arr[5].c_str());

    }

    if(*(propertiesArr+6)) {
        product.batteryLife=atof(arr[6].c_str());

    }

    if(*(propertiesArr+7)) {
        product.has4g=convertToBool(arr[7]);

    }

    if(*(propertiesArr+8)) {
        product.hasBluetooth=convertToBool(arr[8]);

    }

    if(*(propertiesArr+9)) {
        product.hasWifi=convertToBool(arr[9]);

    }

    if(*(propertiesArr+10)) {
        product.hasHdmi=convertToBool(arr[10]);

    }

    if(*(propertiesArr+11)) {
        product.hasUsb=convertToBool(arr[11]);

    }

    if(*(propertiesArr+12)) {
        product.hasFrontCamera=convertToBool(arr[12]);

    }

    if(*(propertiesArr+13)) {
        product.opticalDevice=arr[13];

    }
    if(*(propertiesArr+14)) {
        product.price=atof(arr[14].c_str());

    }
    // Check the capacity of list
    if(itemNumber< maxCapacity -1) {
            // if capacity not exceeded add new item to the list
            productList[itemNumber]=product;
            itemNumber++;
            return 1;
    }
    else {
            cout<<"ERROR: Item capacity is full. New item cannot be added."<<endl;
            return 0;
    }
    return 1;
}
/*
    Get the required vale from given string.
*/
void getValFromString(string &str,int &no) {
    int found;
    int stringSize;
    string val="";
    stringSize=str.size();
    found=str.find(':');
    string propertyName="";
    // Will parse the property name
    for(int i=0;i<found;i++) {
        propertyName+=str[i];
    }

    // Depending on property, point the related item in the array
    if(propertyName=="Name") {
        no=0;
    }
    if(propertyName=="Type") {
        no=1;
    }
    else if (propertyName=="CPU"){
        no=2;
    }
    else if (propertyName=="RAM"){
        no=3;
    }
    else if (propertyName=="Mem"){
        no=4;
    }
    else if (propertyName=="Screen"){
        no=5;
    }
    else if (propertyName=="battLife"){
        no=6;
    }
    else if (propertyName=="has4g"){
        no=7;
    }
    else if (propertyName=="hasBT"){
        no=8;
    }
    else if (propertyName=="hasWifi"){
        no=9;
    }
    else if (propertyName=="hasHdmi"){
        no=10;
    }
    else if (propertyName=="hasUsb"){
        no=11;
    }
    else if (propertyName=="hasFrCam"){
        no=12;
    }
    else if (propertyName=="opticDev"){
        no=13;
    }
    else if (propertyName=="Price"){
        no=14;
    }
    // get the value from given line
    for(int i=found+1;i<stringSize;i++) {
        if(isspace(str[i])) {
            // ignore the first empty characters, break when last character is empty
            if(val.size()) break;
            else continue;
        }
        else {
            // add all char to val string
            val+=str[i];
        }

    }
    str=val;
    return;
}
/*
    Read and parse the all the data from txt file.
*/
bool readData() {
    const char firstChar='=';
    ifstream txtFile ("allProductData.txt");
    if(txtFile.is_open()) {
            string line;
            string productValues[17];
            int i=0;
            int objectLine=0;
            int propertyNo=0;
            while ( getline (txtFile,line) )
            {
                // ignore the first two line
                if(i<2) {
                    i++;
                    continue;
                }
                else {
                    // not first line
                    if (line[0]==firstChar) {
                        // new item to be added system.
                        createProductWithData(productValues);
                        continue;
                    }
                    else {
                        getValFromString(line,propertyNo);
                        productValues[propertyNo]=line;
                    }
                }


            }
            txtFile.close();
            return 1;
    }
    else {
        cout<<"Error: allProductData.txt not found"<<endl;
        return 0;
    }
    return 1;
}

bool compareProducts() {
    showAllProducts();
    int pid1,pid2,pid3;
    cout<<"\n Choose three product ID to Compare"<<endl;
    cin >>pid1;
    cin >>pid2;
    cin >>pid3;
    ElectronicProduct product1=productList[pid1];
    ElectronicProduct product2=productList[pid2];
    ElectronicProduct product3=productList[pid3];
    string type=product1.productType;
    string type2=product2.productType;
    string type3=product3.productType;

    if(type==type2 && type==type3 && type3==type2) {
        bool propertiesArr[17];
        ElectronicProduct product=product1;
        // Get the properties of device
        product.findRelevantProperties(propertiesArr);
        cout<<"Property - "<<product1.productName<<" - "<<product2.productName<<" - "<<product3.productName<<endl;

        if(*(propertiesArr+2)) {
            cout<<"Device CPU(in GHz): "<<product1.deviceCpu<<" - "<<product2.deviceCpu<<" - "<<product3.deviceCpu<<endl;
        }

        if(*(propertiesArr+3)) {
            cout<<"Device RAM(in GB): "<<product1.deviceRam<<" - "<<product2.deviceRam<<" - "<<product3.deviceRam<<endl;
        }

        if(*(propertiesArr+4)) {
            cout<<"Device Memory(in GB): "<<product1.deviceMemory<<" - "<<product2.deviceMemory<<" - "<<product3.deviceMemory<<endl;
        }

        if(*(propertiesArr+5)) {
            cout<<"Screen Size(in Inches): "<<product1.screenSize<<" - "<<product2.screenSize<<" - "<<product3.screenSize<<endl;
        }

        if(*(propertiesArr+6)) {
            cout<<"Battery life(in hours): "<<product1.batteryLife<<" - "<<product2.batteryLife<<" - "<<product3.batteryLife<<endl;
        }

        if(*(propertiesArr+7)) {
            cout<<"Has 4g:"<<product1.has4g<<" - "<<product2.has4g<<" - "<<product3.has4g<<endl;
        }

        if(*(propertiesArr+8)) {
            cout<<"Has Bluetooth: "<<product1.hasBluetooth<<" - "<<product2.hasBluetooth<<" - "<<product3.hasBluetooth<<endl;
        }

        if(*(propertiesArr+9)) {
            cout<<"Has Wifi:"<<product1.hasWifi<<" - "<<product2.hasWifi<<" - "<<product3.hasWifi<<endl;
        }

        if(*(propertiesArr+10)) {
            cout<<"Has HDMI:"<<product1.hasHdmi<<" - "<<product2.hasHdmi<<" - "<<product3.hasHdmi<<endl;
        }

        if(*(propertiesArr+11)) {
            cout<<"Has USB:"<<product1.hasUsb<<" - "<<product2.hasUsb<<" - "<<product3.hasUsb<<endl;
        }

        if(*(propertiesArr+12)) {
            cout<<"Has front camera:"<<product1.hasFrontCamera<<" - "<<product2.hasFrontCamera<<" - "<<product3.hasFrontCamera<<endl;
        }

        if(*(propertiesArr+13)) {
            cout<<"Optical Device: "<<product1.opticalDevice<<" - "<<product2.opticalDevice<<" - "<<product3.opticalDevice<<endl;
        }

        if(*(propertiesArr+14)) {
            cout<<"Price (in TL): "<<product1.price<<" - "<<product2.price<<" - "<<product3.price<<endl;
        }
        cout<<"\n\nBenefit:"<<product1.findDeviceBenefit()<<" - "<<product2.findDeviceBenefit()<<" - "<<product3.findDeviceBenefit()<<endl;
        cout<<"Price / Bft:"<<product1.calcPriceOverPerformance()<<" - "<<product2.calcPriceOverPerformance()<<" - "<<product3.calcPriceOverPerformance()<<endl;
        if(product1.priceOverPerformance<product2.priceOverPerformance) {
            if(product1.priceOverPerformance<product3.priceOverPerformance) {
                cout<<" \n \n Best Choice is :"<<product1.productName<<endl;
            }
            else {
                cout<<" \n \n Best Choice is :"<<product3.productName<<endl;
                }
        }
        else {
            if(product2.priceOverPerformance<product3.priceOverPerformance) {
                cout<<" \n \n Best Choice is :"<<product2.productName<<endl;
            }
            else {
                cout<<" \n \n Best Choice is :"<<product3.productName<<endl;
                }
        }
        return 1;
    }
    else {
        cout<<" Error: choose product in same type"<<endl;
    }
}
int main()
{
    // Program Description
    cout<<"\t\tEE Tech Product Comparison"<<endl;
    cout<<"\t\tAhmet EROL - 1814094 \n\n\n"<<endl;

    // User Interface
    bool exit=true;
    while(exit){
            int selection;
            // Options screen
            cout<<"\n\n Choose option below\n 1 > Enter new product \n 2 > Import Data \n 3 > Display all products \n 4 > Choose 3 product to compare \n 0 > Exit Program \n"<<endl;

            // Get selection
            cin>>selection;
            switch(selection) {
            case 1:
                // New Product Screen
                int result;
                result=newProduct();
                    // new product succesfully added
                if(result) {
                    // show the last added product.
                    cout<<"Product is added with information below\n\n"<<endl;
                    showProduct(itemNumber-1);
                    cout<<"\n\n"<<endl;
                }
                break;
            case 2:
                 // Import Data
                readData();
                break;
            case 3:
                 // Display Products
                 showAllProducts();
                break;
            case 4:
                 // Comparison
                if(itemNumber>2) compareProducts();
                else cout<<"Not enough product"<<endl;
                break;
            case 0:
                 // Exit
                exit=false;
                break;
            default:
                cout << "Choose an option below \n" << endl;
                continue;
            }
    }
    return 0;
}
