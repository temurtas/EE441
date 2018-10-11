//===============================================================
// File: main.cpp
// Function: Main
// Description: EETech Company Product Comparison Helper Program
// Author: H. Semih GENÇ
//===============================================================

//----- Header Files ------
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//----- Class Definition -----
class ElectronicProduct
{
private:
    float priceOverPerformance = 0;
    float deviceBenefit = 0;
    string ProductName;
    string ProductType;
    float deviceCPU;
    int deviceRAM;
    int deviceMemory;
    float screenSize;
    float batteryLife;
    bool has4G;
    bool hasBluetooth;
    bool hasWIFI;
    bool hasHDMI;
    bool hasUSB;
    bool hasFrontCamera;
    string opticalDevice;
    float Price = 0;
public:


// Constructor
    ElectronicProduct(string Name = "", string Type = "", float dCPU = 0, int dRAM = 0, int dMem = 0, float sSize = 0, float bLife = 0,
                      bool _4g = 0, bool bl = 0, bool wifi = 0, bool hdmi = 0, bool usb = 0, bool fCam = 0, string opDevice = "", float price = 0);

// Member functions
    float findDeviceBenefit();
    static vector<string> findRelevantProperties(string);
    static string getTypePropertiesInBit(string);
    int findBenefitOfOpticalDevice();
    float calcPricePerformance();
    void setProperty(pair<string, string>);
    static string getProductTypeStr(int);
    string getTypeStr(int);
    static vector<ElectronicProduct> ParseFile(string);
    string getName();
    string getType();

    float getFloatType(string);
    int getIntType(string);
    bool getBoolType(string);
};

// Constructor
ElectronicProduct::ElectronicProduct(string Name, string Type, float dCPU, int dRAM, int dMem, float sSize, float bLife,
                                     bool _4g, bool bl, bool wifi, bool hdmi, bool usb, bool fCam, string opDevice, float price)
{

    ProductName = Name;
    ProductType = Type;
    deviceCPU = dCPU;
    deviceRAM = dRAM;
    deviceMemory = dMem;
    screenSize = sSize;
    batteryLife = bLife;
    has4G = _4g;
    hasBluetooth = bl;
    hasWIFI = wifi;
    hasHDMI = hdmi;
    hasUSB = usb;
    hasFrontCamera = fCam;
    opticalDevice = opDevice;
    Price = price;
    findDeviceBenefit();
}



// ----------------------------- MEMBER FUNCTIONS -------------------------------------
float ElectronicProduct::findDeviceBenefit()
{
    // These are assumed as "other variables" in the calculation of deviceBenefit (if exist): deviceCPU, deviceRam, deviceMemory, screenSize, batteryLife
    float dFactor = deviceCPU*deviceRAM*deviceMemory;
    deviceBenefit = (has4G + hasBluetooth + hasFrontCamera + hasHDMI + hasUSB + hasWIFI + findBenefitOfOpticalDevice())*(ProductType != "TV" ? (ProductType == "GameConsole" ? dFactor : dFactor*batteryLife*screenSize) : screenSize);
    return deviceBenefit;
}

int ElectronicProduct::findBenefitOfOpticalDevice()
{
    if (opticalDevice == "CD" || opticalDevice == "1")
        return 1;
    else if (opticalDevice == "DVD" || opticalDevice == "2")
        return 2;
    else if (opticalDevice == "Bluray" || opticalDevice == "3")
        return 3;
    return 0;
}

float ElectronicProduct::calcPricePerformance()
{
    priceOverPerformance = Price / findDeviceBenefit();
    return priceOverPerformance;
}

// Set Property method. As an argument, it takes a pair whose first key is property name and second key is value of the property.
void ElectronicProduct::setProperty(pair<string, string> p)
{
    string key = p.first;
    string val = p.second;

    if (key == "Name")
        ProductName = val;
    else if (key == "Type")
        ProductType = val;
    else if (key == "CPU")
        deviceCPU = atof(val.c_str());  // Conversion from string to float
    else if (key == "RAM")
        deviceRAM = atoi(val.c_str());  // Conversion from string to int
    else if (key == "Mem")
        deviceMemory = atoi(val.c_str());
    else if (key == "Screen")
        screenSize = atof(val.c_str());
    else if (key == "battLife")
        batteryLife = atof(val.c_str());
    else if (key == "has4g")
        has4G = (val == "True" ? true : false); // Conversion from string to boolean/int. This line can be written in more compact way.
    else if (key == "hasBT")
        hasBluetooth = (val == "True" ? true : false);
    else if (key == "hasWifi")
        hasWIFI = (val == "True" ? true : false);
    else if (key == "hasHdmi")
        hasHDMI = (val == "True" ? true : false);
    else if (key == "hasUsb")
        hasUSB = (val == "True" ? true : false);
    else if (key == "hasFrCam")
        hasFrontCamera = (val == "True" ? true : false);
    else if (key == "opticDev")
        opticalDevice = val;
    else if (key == "Price")
    {
        Price = atof(val.c_str());
        findDeviceBenefit();
        calcPricePerformance();
    }

}

vector<string> ElectronicProduct::findRelevantProperties(string s)
{
    static string properties[14] = { "Name", "CPU", "RAM", "Mem", "Screen", "battLife", "has4g", "hasBT", "hasWifi", "hasHdmi", "hasUsb", "hasFrCam", "opticDev", "Price" };
    vector<string> PropertyList;
    for (int i = 0; i <= 13; i++)
    {
        if (s[i] == '1')
            PropertyList.push_back(properties[i]);  // Relevant properties from the array "properties" are added to PropertyList.
    }

    return PropertyList;
}

// Returned strings carrying 14-bit data represent the properties of a product of certain type.
// The bit being zero means the product does not have the corresponding property.
string ElectronicProduct::getTypePropertiesInBit(string ProductType)
{
    if (ProductType == "Smartphone")
        return "11111111000101";
    else if (ProductType == "LaptopComputer")
        return "11111101010011";
    else if (ProductType == "GameConsole")
        return "11110001101011";
    else if (ProductType == "TV")
        return "10001000111001";
    else return "00000000000000";
}
string ElectronicProduct::getProductTypeStr(int Type)
{
    switch (Type)
    {
    case 1:
        return "Smartphone";
    case 2:
        return "LaptopComputer";
    case 3:
        return "GameConsole";
    case 4:
        return "TV";
    }
}
string ElectronicProduct::getTypeStr(int i)
{
    switch (i)
    {
    case 1:
        return "Smartphone";
    case 2:
        return "LaptopComputer";
    case 3:
        return "GameConsole";
    case 4:
        return "TV";
    }

}

// ----- Some Getters -----
string ElectronicProduct::getName(void)
{
    return ProductName;
}

string ElectronicProduct::getType(void)
{
    return ProductType;
}

float ElectronicProduct::getFloatType(string key)
{
    if (key == "CPU")
        return deviceCPU;
    else if (key == "Screen")
        return screenSize;
    else if (key == "battLife")
        return batteryLife;
    else if (key == "Price")
        return Price;
}

int ElectronicProduct::getIntType(string key)
{
    if (key == "RAM")
        return deviceRAM;
    else if (key == "Mem")
        return deviceMemory;
}

bool ElectronicProduct::getBoolType(string key)
{

    if (key == "4g")
        return has4G ;
    else if (key == "bt")
        return hasBluetooth;
    else if (key == "wifi")
        return hasWIFI ;
    else if (key == "hdmi")
        return hasHDMI;
    else if (key == "usb")
        return hasUSB;
    else if (key == "frcam")
        return hasFrontCamera;
    return false;
}
// ----- Global Variables -----
vector<ElectronicProduct>productList;

// ----- Main Function -----
int main()
{

// ----- User Interface ------
// There are 6 options in the menu.
    string filePath= "d:\\allProductData.txt";  // File path for the data to be imported.
    int f = 1, level = 0;           //  "level" means menu level. "f" means chosen option.
    while (f != 0)
    {
        // Welcome menu and the options
        if (level == 0)
        {
            system("CLS");
            cout << "\n   EE Tech Product Comparison\n   1949866 - H. Semih GENC" << endl << endl;
            cout << "===============================" << endl;
            cout << " Total number of products: " << productList.size() << endl;
            cout << "===============================";
            cout << endl<< endl
                 <<"(1) Enter new product"<<endl
                 <<"(2) Import Data" << endl<< "    File path is set to \""<< filePath <<"\""<<endl<< endl
                 <<"(3) Display all products"<<endl
                 <<"(4) Choose 3 products and compare"<<endl
                 <<"(5) Remove a product"<<endl
                 <<"(6) Clear product list"<<endl
                 <<"(0) Exit program\n\n\n";

            cout << "Enter your choice: ";
            cin >> f;
            level = 1;
            system("CLS");
        }

        // New product option
        if (f == 1 && level == 1)
        {

            int type;
            string input;
            ElectronicProduct newProd;
            cout << "\n[1] Smartphone\n[2] Laptop Computer\n[3] Game Console\n[4] TV\n";
            cout << "Enter the type of new product: ";
            cin >> input;
            type = atoi(input.c_str());
            if (!(type >= 1 && type <= 4))
            {
                cout << endl << "You entered an invalid type. Exiting..." << endl;
                system("PAUSE");
            }
            else
            {
                vector<string> vs = ElectronicProduct::findRelevantProperties(ElectronicProduct::getTypePropertiesInBit(ElectronicProduct::getProductTypeStr(type)));   // Relevant properties for the entered type
                newProd.setProperty(pair<string,string>("Type",newProd.getTypeStr(type)));         // Set the type

                for (int a = 0; a <= vs.size() - 1; a++)
                {
                    cout << "Enter this property -> " << vs[a];        // Ask for the next property
                    cout << ((vs[a].substr(0, 3) == "opt") ? " ( [1] CD, [2] DVD, [3] Bluray )" : "");      // Modifying output for different option types.
                    cout << ((vs[a].substr(0, 3) == "has") ? " (y or n)" : "") << ": ";
                    string val;
                    cin >> val;
                    pair <string, string> paramArg;
                    paramArg.first = vs[a];
                    paramArg.second = ((val == "y" || val == "Y") ? "True" : val);
                    newProd.setProperty(paramArg);          // Set the related property of the new product

                }
                productList.push_back(newProd);             // Put the new product to global product list
                level=0;
            }
        }

        // Import Data Option
        if (f == 2 && level == 1)
        {
            vector<ElectronicProduct> parsedProd =ElectronicProduct::ParseFile(filePath);
            // Put each product from parsing to product list.
            for (int e = 0; e <= parsedProd.size() - 1; e++)
            {
                productList.push_back(parsedProd[e]);
                system("CLS");
            }

        }

        //  Display All the Products Option
        if (f == 3 && level == 1)
        {
            cout << left
                 << setw(5)<<"#"
                 << setw(16) << "Type"
                 << setw(16) << "Name"
                 << setw(8) << "Price TL"
                 << setw(16) << "Dev. Benefit"
                 << setw(12) << "Price/Perf" << endl;

            cout << "-----------------------------------------------------------------\n";
            int best;
            float benefit=0;
            for (int p = 0; p <= productList.size() - 1; p++)
            {
                cout << setw(5)<<p<< setw(16) << productList[p].getType() << setw(16) << productList[p].getName()<<
                     setw(8) << productList[p].getFloatType("Price")<< setw(16) << productList[p].findDeviceBenefit() <<
                     setw(12) << productList[p].calcPricePerformance() << endl;

                if(productList[p].findDeviceBenefit()>benefit)
                {
                    benefit=productList[p].findDeviceBenefit();
                    best=p;
                }


            }
            cout<< endl << "The best product is "<< productList[best].getName()<< endl;
            cout << endl;
            system("PAUSE");
        }

        // Comparison Option (3 products)
        if (f == 4 && level == 1 && productList.size()>2)
        {
            int i, j, k;
            cout << "First Product (Index):";
            cin >> i;
            cout << "Second Product (Index):";
            cin >> j;
            cout << "Third Product (Index):";
            cin >> k;
            system("CLS");
            int cap = productList.size();
            if (i != j && j != k && i != k && i <= cap && j <= cap && k <= cap)
            {
                ElectronicProduct pi=productList[i],pj=productList[j],pk=productList[k];

                if (pi.getType() == pj.getType() && pj.getType() == pk.getType())
                {
                    // For comparison criteria
                    float Di = pi.findDeviceBenefit();
                    float Dj = pj.findDeviceBenefit();
                    float Dk = pk.findDeviceBenefit();

                    // Tabulating products info.
                    cout << endl;
                    cout << left << setw(16) << "Name"
                         << setw(16) << "Benefit"
                         << setw(5)<<"CPU"
                         << setw(5)<<"RAM"
                         << setw(5)<<"Mem"
                         << setw(7)<<"Screen"
                         << setw(3)<<"4G"
                         << setw(3)<<"BT"
                         << setw(5)<<"Wifi"
                         << setw(5)<<"HDMI"
                         << setw(4)<< "USB"
                         << setw(4)<<"FrC";
                    cout << endl<<"-----------------------------------------------------------------------------" << endl;
                    cout << setw(16) << pi.getName() << setw(16) << Di<< setw(5)<<pi.getFloatType("CPU")<< setw(5)<<pi.getIntType("RAM") << setw(5)<<pi.getIntType("Mem")
                         << setw(7)<<(pi.getFloatType("Screen")==0?NULL:pi.getFloatType("Screen"))  << setw(3)<<(pi.getBoolType("4g")? " +": "") << setw(3)<<(pi.getBoolType("bt")? " +": "") << setw(5)<<(pi.getBoolType("wifi")? " +": "")
                         << setw(5)<<(pi.getBoolType("hdmi")? " +": "") << setw(4)<< (pi.getBoolType("usb")? " +": "")  << setw(4)<<(pi.getBoolType("frcam")? " +": "")  << endl;
                    cout << setw(16) << pj.getName() << setw(16) << Dj<< setw(5)<<pj.getFloatType("CPU")<< setw(5)<<pj.getIntType("RAM") << setw(5)<<pj.getIntType("Mem")
                         << setw(7)<<(pj.getFloatType("Screen")==0?NULL:pj.getFloatType("Screen")) << setw(3)<<(pj.getBoolType("4g")? " +": "") << setw(3)<<(pj.getBoolType("bt")? " +": "") << setw(5)<<(pj.getBoolType("wifi")? " +": "")
                         << setw(5)<<(pj.getBoolType("hdmi")? " +": "") << setw(4)<< (pj.getBoolType("usb")? " +": "")  << setw(4)<<(pj.getBoolType("frcam")? " +": "")  << endl;
                    cout << setw(16) << pk.getName() << setw(16) << Dk<< setw(5)<<pk.getFloatType("CPU")<< setw(5)<<pk.getIntType("RAM") << setw(5)<<pk.getIntType("Mem")
                         << setw(7)<<(pk.getFloatType("Screen")==0?NULL:pk.getFloatType("Screen"))  << setw(3)<<(pk.getBoolType("4g")? " +": "") << setw(3)<<(pk.getBoolType("bt")? " +": "") << setw(5)<<(pk.getBoolType("wifi")? " +": "")
                         << setw(5)<<(pk.getBoolType("hdmi")? " +": "") << setw(4)<< (pk.getBoolType("usb")? " +": "")  << setw(4)<<(pk.getBoolType("frcam")? " +": "")  << endl;
                    // Finding the best product among the chosen.
                    int theBest;
                    if (Di > Dj)
                    {
                        if (Di > Dk)
                            theBest = i;
                        else
                            theBest = k;
                    }
                    else
                    {
                        if (Dj > Dk)
                            theBest = j;
                        else
                            theBest = k;
                    }

                    cout << endl << "The best product is " << productList[theBest].getName() << endl << endl;
                    level = 0;
                }
// Some other logical checks below
                else
                {
                    cout << endl << "The products you entered are of different types" << endl << endl;
                    level = 0;
                }
                system("PAUSE");
            }
            else
            {
                if (cap > 0)
                    cout << "You entered an invalid set of index\n\n";
                else
                {
                    cout << "There is no product in the list\n\n";
                }
                level = 0;
                system("PAUSE");
            }
        }
        else
        {
            if(f == 4 && level == 1 && !(productList.size()>2))
            {
                cout <<endl <<"There are less than 3 products in the database." <<
                     endl<<"Use option 1 or 2 to add products..." <<endl <<endl;
                system("PAUSE");
                level = 0;
            }

        }

        if (f == 5 && level == 1)
        {
            int rm;
            string r;
            cout<<"Enter the index number of the product you would like to remove:";
            cin>>r;
            rm = atoi(r.c_str());

            if(rm<productList.size() && rm >=0)
            {
                productList.erase(productList.begin()+ rm);
                cout << "INFO: The entry is removed..." << endl<<endl;
            }
            else
                cout<<"You entered an invalid index."<<endl;
            system("PAUSE");

        }

        if (f == 6 && level == 1)
        {
            int rm;
            string r;
            cout<<"Are you sure you would like to delete all the products? (y or n):"<<endl;
            cin>>r;
            if(r=="y")
            {
                productList.clear();
                cout << endl<<"INFO: All entries in the product list are removed..." << endl<<endl;
                system("PAUSE");
            }


        }
        level=0;
    }
    return 0;
}

// This method helps us to parse a file, collect products and return them in a vector.
vector<ElectronicProduct> ElectronicProduct::ParseFile(string filepath)
{

    string str;												// Each line is stored in a temp storage
    size_t pos = 0;											// Delimiter position in current line (str) will be stored
    vector<ElectronicProduct> pList;                        // Product List (array)
    ElectronicProduct newOne;                               // Object definiton for the new product

    std::ifstream f(filepath.c_str());                      // Define a file stream to read a file
    while (f)
    {
        getline(f, str);                                    // Get lines one by one
        if (str.find(':') != string::npos)                  // If there is a delimiter -->
        {
            pos = str.find(':');                            // --> find its position
            string key = str.substr(0, pos);
            string value = str.substr(pos + 2, str.length());   // Split string into key and value.

            if (key != "Name")
                value = value.substr(0, value.find(' '));

            newOne.setProperty(pair<string, string>(key, value));   // Parsed property is collected
        }
        else if (str.find('===') != string::npos && str.length() == 3)
        {
            pos = str.find('===');                          //  End of product info lines
            pList.push_back(newOne);                        //  Put new product from parsing to product list
            newOne = ElectronicProduct();                   //  Initialize a blank product for the next.
        }
    }
    return pList;                                           // Return all the products
}
