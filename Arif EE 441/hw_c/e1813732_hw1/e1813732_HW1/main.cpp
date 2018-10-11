#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
int globalid ;

using namespace std;
   enum productType
{
    smartPhone,
    laptopComp,
    gameConsole,
    tv,
    erol
};
enum opticalDevice
{
    nooptical,
    CD,
    DVD,
    Bluray

};

class ElectronicProduct
{
private:

    int productID;
    string productName;
    productType product;
    float deviceCpu;
    int deviceRam;
    int deviceMemory; //(in GB)
    float screenSize; //(in inches)
    float batteryLife; //(in hours)
    bool has4g;
    bool hasBluetooth;
    bool hasWifi;
    bool hasHdmi;
    bool hasUsb;
    bool hasFrontCamera;
    opticalDevice device;
    float price;
    float deviceBenefit;
    float priceOverPerformance;
public:

    ElectronicProduct();
    void setname(string name);
    void settype (string product_1="tv");
    void setcpu(float cpu=0);
    void setram(int ram=0);
    void setmemory(int memory=0);
    void setscreen(float screen=0);
    void setbattery(float life=0);
    void set4g(bool g_4=false);
    void setbluetooth(bool blue=false);                             // set functions
    void setwifi(bool wifi=false);
    void sethdmi(bool hdmi=false);
    void setusb(bool usb=false);
    void setfrontcam(bool cam=false);
    void setopticaldevice(string optic="");
    void setprize(float prize=0);
    int findBenefitOfOpticalDevice();
    float findDeviceBenefit();
    float calcPriceOverPerformance();
    int getid();
    string getname();
    productType gettype();                                          //type is held as enum
    string gettypeasstr();                                          //for printing operations i wrote getting it as a string
    float getcpu();
    float getram();
    float getmemory();
    float getscreen();
    float getbattery();
    bool get4g();
    bool getbluetooth();
    bool getwifi();
    bool gethdmi();
    bool getusb();
    bool getfrontcam();
    opticalDevice getopticaldevice();                               // read command above
    string getopticaldeviceasstr();
    float getprize();
};

ElectronicProduct::ElectronicProduct():productID(globalid)
{
    settype();
    setcpu();
    setram();
    setmemory();
    setscreen();
    setbattery();
    set4g();
    setbluetooth();
    setwifi();
    sethdmi();
    setusb();
    setfrontcam();
    setopticaldevice();
    setprize();
    globalid++;

}
void ElectronicProduct::setname (string name)
{productName=name;}

void ElectronicProduct::settype(string product_1)
{   int sz=product_1.size();
        for(int i=0;i<sz;i++)
        {
            product_1[i]=tolower(product_1[i]);
        }

    if(product_1=="smartphone") {product=smartPhone;}
    else if(product_1=="laptopcomputer") {product=laptopComp;}
    else if(product_1=="gameconsole") {product=gameConsole;}
    else if(product_1=="tv") {product=tv;}
    else {product=erol;}
}

void ElectronicProduct::setcpu(float cpu)
{deviceCpu=cpu;}

void ElectronicProduct::setram(int ram)
{deviceRam=ram;}

void ElectronicProduct::setmemory(int memory)
{deviceMemory=memory;}

void ElectronicProduct::setscreen(float screen)
{screenSize=screen;}

void ElectronicProduct::setbattery(float life)
{batteryLife=life;}

void ElectronicProduct::set4g(bool g_4)
{has4g=g_4;}

void ElectronicProduct::setbluetooth(bool blue)
{hasBluetooth=blue;}

void ElectronicProduct::setwifi(bool wifi)
{hasWifi=wifi;}

void ElectronicProduct::sethdmi(bool hdmi)
{hasHdmi=hdmi;}

void ElectronicProduct::setusb(bool usb)
{hasUsb=usb;}

void ElectronicProduct::setfrontcam(bool cam)
{hasFrontCamera=cam;}

void ElectronicProduct::setopticaldevice(string optic)
{int se=optic.size();
        for(int i=0;i<se;i++)
        {
            optic[i]=tolower(optic[i]);
        }

    if(optic=="cd") {device=CD;}
    else if(optic=="dvd") {device=DVD;}
    else if(optic=="bluray") {device=Bluray;}
    else {device=nooptical;}

}

void ElectronicProduct::setprize(float prize)
{price=prize;}

int ElectronicProduct::findBenefitOfOpticalDevice()
{
  return device;
}
float ElectronicProduct::findDeviceBenefit()
{
  switch (product)
  {
    case smartPhone:
        {deviceBenefit=getcpu()*getram()*getmemory()*getscreen()*getbattery()*(get4g()+getbluetooth()+getfrontcam()); break; }
    case laptopComp:
        {deviceBenefit=getcpu()*getram()*getmemory()*getscreen()*getbattery()*(getbluetooth()+gethdmi()+findBenefitOfOpticalDevice()); break;}
    case gameConsole:
        {deviceBenefit=getcpu()*getram()*getmemory()*(getbluetooth()+getwifi()+getusb()+findBenefitOfOpticalDevice()); break;}
    case tv:
        {deviceBenefit=getscreen()*(getwifi()+gethdmi()+getusb()); break;}
  }
  return deviceBenefit;
}

float ElectronicProduct::calcPriceOverPerformance()
{
  priceOverPerformance=price/deviceBenefit;
  return priceOverPerformance;
}
int ElectronicProduct::getid()
{ return productID;}
string ElectronicProduct::getname()
{return productName;}
productType ElectronicProduct::gettype()
{ return product;}
string ElectronicProduct::gettypeasstr() //in electronic product class type of product is held as enumarator. simply convert it to string
{
    switch (product)
    {
    case smartPhone:
        {
            return "SmartPhone";
        }
    case laptopComp:
        {
            return "LaptopComputer";
        }
    case gameConsole:
        {
            return "GameConsole";
        }
    case tv:
        {
            return "TV";
        }
    }
}
float ElectronicProduct::getcpu()
{ return deviceCpu;}
float ElectronicProduct::getram()
{ return deviceRam;}
float ElectronicProduct::getmemory()
{ return deviceMemory;}
float ElectronicProduct::getscreen()
{ return screenSize;}
float ElectronicProduct::getbattery()
{ return batteryLife;}
bool ElectronicProduct::get4g()
{ return has4g;}
bool ElectronicProduct::getbluetooth()
{ return hasBluetooth;}
bool ElectronicProduct::getwifi()
{ return hasWifi;}
bool ElectronicProduct::gethdmi()
{ return hasHdmi;}
bool ElectronicProduct::getusb()
{ return hasUsb;}
bool ElectronicProduct::getfrontcam()
{ return hasFrontCamera;}
opticalDevice ElectronicProduct::getopticaldevice()
{ return device;}
string ElectronicProduct::getopticaldeviceasstr()
{
     switch (device)
    {
    case nooptical:
        {
            return "No optical device";
        }
    case CD:
        {
            return "CD";
        }
    case DVD:
        {
            return "DVD";
        }
    case Bluray:
        {
            return "Bluray";
        }
    }
}
float ElectronicProduct::getprize()
{ return price;}

void enternewproduct(ElectronicProduct &k)
{   string my_name,my_type,optic;
    float cpu,ram,memory,screen,battery,price;
    bool g4,bluetooth,wifi,hdmi,usb,frontcam;
    cout<<"Enter product name:"<<"\n";
    cin>>my_name;
    k.setname(my_name);
    cout<<"Enter product type:"<<"\n";
    cin>>my_type;
    k.settype(my_type);
    while(k.gettype()==erol)
    {
        cout<<"Enter product type correctly:"<<"\n";
        cin>>my_type;
        k.settype(my_type);
    }
            switch(k.gettype())
            {
            case smartPhone:
                {
                    cout<<"Enter product CPU:"<<"\n";
                    cin>>cpu;
                    k.setcpu(cpu);
                    cout<<"Enter product RAM:"<<"\n";
                    cin>>ram;
                    k.setram(ram);
                    cout<<"Enter product memory (in GB):"<<"\n";
                    cin>>memory;
                    k.setmemory(memory);
                    cout<<"Enter product screen size:"<<"\n";
                    cin>>screen;
                    k.setscreen(screen);
                    cout<<"Enter product battery life:"<<"\n";
                    cin>>battery;
                    k.setbattery(battery);
                    cout<<"Does product have 4G? Yes(1) No(0):"<<"\n";
                    cin>>g4;
                    k.set4g(g4);
                    cout<<"Does product have bluetooth? Yes(1) No(0)"<<"\n";
                    cin>>bluetooth;
                    k.setbluetooth(bluetooth);
                    cout<<"Does product have front camera? Yes(1) No(0)"<<"\n";
                    cin>>frontcam;
                    k.setfrontcam(frontcam);
                    cout<<"Enter product price:"<<"\n";
                    cin>>price;
                    k.setprize(price);
                    break;

                }
            case laptopComp:
                {
                    cout<<"Enter product CPU:"<<"\n";
                    cin>>cpu;
                    k.setcpu(cpu);
                    cout<<"Enter product RAM:"<<"\n";
                    cin>>ram;
                    k.setram(ram);

                    cout<<"Enter product memory (in GB):"<<"\n";
                    cin>>memory;
                    k.setmemory(memory);

                    cout<<"Enter product screen size:"<<"\n";
                    cin>>screen;
                    k.setscreen(screen);

                    cout<<"Enter product battery life:"<<"\n";
                    cin>>battery;
                    k.setbattery(battery);

                    cout<<"Does product have bluetooth? Yes(1) No(0)"<<"\n";
                    cin>>bluetooth;
                    k.setbluetooth(bluetooth);

                    cout<<"Does product have Hdmi? Yes(1) No(0):"<<"\n";
                    cin>>hdmi;
                    k.sethdmi(hdmi);

                    cout<<"What is the optical device of product?"<<"\n";
                    cin>>optic;
                    k.setopticaldevice(optic);

                    cout<<"Enter product price:"<<"\n";
                    cin>>price;
                    k.setprize(price);

                    break;

                }
            case gameConsole:
                {
                    cout<<"Enter product CPU:"<<"\n";
                    cin>>cpu;
                    k.setcpu(cpu);

                    cout<<"Enter product RAM:"<<"\n";
                    cin>>ram;
                    k.setram(ram);

                    cout<<"Enter product memory (in GB):"<<"\n";
                    cin>>memory;
                    k.setmemory(memory);

                    cout<<"Does product have bluetooth? Yes(1) No(0)"<<"\n";
                    cin>>bluetooth;
                    k.setbluetooth(bluetooth);

                    cout<<"Does product have Wifi? Yes(1) No(0):"<<"\n";
                    cin>>wifi;
                    k.setwifi(wifi);

                    cout<<"Does product have Usb? Yes(1) No(0)"<<"\n";
                    cin>>usb;
                    k.setusb(usb);

                    cout<<"What is the optical device of product?"<<"\n";
                    cin>>optic;
                    k.setopticaldevice(optic);

                    cout<<"Enter product price:"<<"\n";
                    cin>>price;
                    k.setprize(price);

                    break;

                }
            case tv:
                {
                    cout<<"Enter product screen size:"<<"\n";
                    cin>>screen;
                    k.setscreen(screen);

                    cout<<"Does product have Wifi? Yes(1) No(0):"<<"\n";
                    cin>>wifi;
                    k.setwifi(wifi);

                    cout<<"Does product have Hdmi? Yes(1) No(0)"<<"\n";
                    cin>>hdmi;
                    k.sethdmi(hdmi);

                    cout<<"Does product have Usb? Yes(1) No(0)"<<"\n";
                    cin>>usb;
                    k.setusb(usb);

                    cout<<"Enter product price:"<<"\n";
                    cin>>price;
                    k.setprize(price);

                    break;
                }
            }

}


void displayObject(ElectronicProduct &b)//display an object of a class electronic product
{   switch (b.gettype())
    {

    case smartPhone:
    {
    cout<<"product ID: " <<b.getid()<<"\n"<<"product name: " <<b.getname()<<"\n"<<"product type: "<<b.gettypeasstr()<<"\n";
    cout<<"product CPU: "<<b.getcpu()<<"\n"<<"product Ram:"<<b.getram()<<"\n";
    cout<<"product Memory: "<<b.getmemory()<<"\n"<<"Screen size of product:"<<b.getscreen()<<"\n";
    cout<<"battery life of product: "<<b.getbattery()<<"\n"<<"has 4g:"<<b.get4g()<<"\n";
    cout<<"has Bluetooth: "<<b.getbluetooth()<<"\n"<<"has Front Camera:"<<b.getfrontcam()<<"\n";
    cout<<"Price: "<<b.getprize()<<"\n"<<"Device Benefit:"<<b.findDeviceBenefit()<<"\n";
    cout<<"Price over Performance: "<<b.calcPriceOverPerformance()<<"\n";
    break;
    }
    case laptopComp:
    {
    cout<<"product ID: " <<b.getid()<<"\n"<<"product name: "<<"\n"<<b.getname()<<"\n"<<"product type: "<<b.gettypeasstr()<<"\n";
    cout<<"product CPU: "<<b.getcpu()<<"\n"<<"product Ram:"<<b.getram()<<"\n";
    cout<<"product Memory: "<<b.getmemory()<<"\n"<<"Screen size of product:"<<b.getscreen()<<"\n";
    cout<<"battery life of product: "<<b.getbattery()<<"\n"<<"has Bluetooth: "<<b.getbluetooth()<<"\n";
    cout<<"has Hdmi:"<<b.gethdmi()<<"\n"<<"optical Device:"<<b.getopticaldeviceasstr()<<"\n";
    cout<<"Price: "<<b.getprize()<<"\n"<<"Device Benefit:"<<b.findDeviceBenefit()<<"\n";
    cout<<"Price over Performance: "<<b.calcPriceOverPerformance()<<"\n";
    break;
    }
    case gameConsole:
    {
    cout<<"product ID: " <<b.getid()<<"\n"<<"product name: "<<b.getname()<<"\n"<<"product type: "<<b.gettypeasstr()<<"\n";
    cout<<"product CPU: "<<b.getcpu()<<"\n"<<"product Ram:"<<b.getram()<<"\n";
    cout<<"product Memory: "<<b.getmemory()<<"\n"<<"has Bluetooth: "<<b.getbluetooth()<<"\n";
    cout<<"has Wi-fi:"<<b.getwifi()<<"\n"<<"has Usb:"<<b.getusb()<<"\n";
    cout<<"optical Device:"<<b.getopticaldeviceasstr()<<"\n";
    cout<<"Price: "<<b.getprize()<<"\n"<<"Device Benefit:"<<b.findDeviceBenefit()<<"\n";
    cout<<"Price over Performance: "<<b.calcPriceOverPerformance()<<"\n";
    break;
    }
    case tv:
    {
    cout<<"product ID: " <<b.getid()<<"\n"<<"product name: "<<b.getname()<<"\n"<<"product type: "<<b.gettypeasstr()<<"\n";
    cout<<"Screen Size:"<<b.getscreen()<<"\n"<<"has Wi-fi:"<<b.getwifi()<<"\n";
    cout<<"has Hdmi:"<<b.gethdmi()<<"\n"<<"has Usb:"<<b.getusb()<<"\n";
    cout<<"Price: "<<b.getprize()<<"\n"<<"Device Benefit:"<<b.findDeviceBenefit()<<"\n";
    cout<<"Price over Performance: "<<b.calcPriceOverPerformance()<<"\n";
    break;
    }
    }
}
void compare3products(ElectronicProduct &a,ElectronicProduct &b,ElectronicProduct &c)
{   float my_array[3],temp;
    switch (a.gettype())
    {
    case smartPhone:
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"\t\t\t"<<a.getname()<<"\t\t"<<b.getname()<<"\t\t"<<c.getname()<<endl;
            cout<<"CPU:"<<"\t\t\t"<<a.getcpu()<<"\t\t"<<b.getcpu()<<"\t\t"<<c.getcpu()<<endl;
            cout<<"RAM:"<<"\t\t\t"<<a.getram()<<"\t\t"<<b.getram()<<"\t\t"<<c.getram()<<endl;
            cout<<"Memory:"<<"\t\t\t"<<a.getmemory()<<"\t\t"<<b.getmemory()<<"\t\t"<<c.getmemory()<<endl;
            cout<<"Screen Size:"<<"\t\t"<<a.getscreen()<<"\t\t"<<b.getscreen()<<"\t\t"<<c.getscreen()<<endl;
            cout<<"Battery Life:"<<"\t\t"<<a.getbattery()<<"\t\t"<<b.getbattery()<<"\t\t"<<c.getbattery()<<endl;
            cout<<"has4g:"<<"\t\t\t"<<a.get4g()<<"\t\t"<<b.get4g()<<"\t\t"<<c.get4g()<<endl;
            cout<<"has Bluetooth:"<<"\t\t"<<a.getbluetooth()<<"\t\t"<<b.getbluetooth()<<"\t\t"<<c.getbluetooth()<<endl;
            cout<<"has frontcam:"<<"\t\t"<<a.getfrontcam()<<"\t\t"<<b.getfrontcam()<<"\t\t"<<c.getfrontcam()<<endl;
            cout<<"Price:"<<"\t\t\t"<<a.getprize()<<"\t\t"<<b.getprize()<<"\t\t"<<c.getprize()<<endl;
            cout<<"Device Benefit:"<<"\t\t"<<setprecision(4)<<a.findDeviceBenefit()<<"\t\t"<<setprecision(4)<<b.findDeviceBenefit()<<"\t\t"<<setprecision(4)<<c.findDeviceBenefit()<<endl;
            cout<<"Price/Performance:"<<"\t"<<setprecision(3)<<a.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<b.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<c.calcPriceOverPerformance()<<endl;
            break;
        }
    case laptopComp:
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"\t\t\t"<<a.getname()<<"\t\t"<<b.getname()<<"\t\t"<<c.getname()<<endl;
            cout<<"CPU:"<<"\t\t\t"<<a.getcpu()<<"\t\t"<<b.getcpu()<<"\t\t"<<c.getcpu()<<endl;
            cout<<"RAM:"<<"\t\t\t"<<a.getram()<<"\t\t"<<b.getram()<<"\t\t"<<c.getram()<<endl;
            cout<<"Memory:"<<"\t\t\t"<<setprecision(4)<<a.getmemory()<<"\t\t"<<setprecision(4)<<b.getmemory()<<"\t\t"<<setprecision(4)<<c.getmemory()<<endl;
            cout<<"Screen Size:"<<"\t\t"<<a.getscreen()<<"\t\t"<<b.getscreen()<<"\t\t"<<c.getscreen()<<endl;
            cout<<"Battery Life:"<<"\t\t"<<a.getbattery()<<"\t\t"<<b.getbattery()<<"\t\t"<<c.getbattery()<<endl;
            cout<<"has Bluetooth:"<<"\t\t"<<a.getbluetooth()<<"\t\t"<<b.getbluetooth()<<"\t\t"<<c.getbluetooth()<<endl;
            cout<<"has Hdmi:"<<"\t\t"<<a.gethdmi()<<"\t\t"<<b.gethdmi()<<"\t\t"<<c.gethdmi()<<endl;
            cout<<"Optical device:"<<"\t\t"<<a.getopticaldeviceasstr()<<"\t\t"<<b.getopticaldeviceasstr()<<"\t\t"<<c.getopticaldeviceasstr()<<endl;
            cout<<"Price:"<<"\t\t\t"<<setprecision(4)<<a.getprize()<<"\t\t"<<setprecision(4)<<b.getprize()<<"\t\t"<<setprecision(4)<<c.getprize()<<endl;
            cout<<"Device Benefit:"<<"\t\t"<<setprecision(8)<<a.findDeviceBenefit()<<"\t\t"<<setprecision(8)<<b.findDeviceBenefit()<<"\t\t"<<setprecision(8)<<c.findDeviceBenefit()<<endl;
            cout<<"Price/Performance:"<<"\t"<<setprecision(3)<<a.calcPriceOverPerformance()<<"\t"<<setprecision(3)<<b.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<c.calcPriceOverPerformance()<<endl;
            break;
        }
     case gameConsole:
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"\t\t\t"<<a.getname()<<"\t"<<b.getname()<<"\t"<<c.getname()<<endl;
            cout<<"CPU:"<<"\t\t\t"<<a.getcpu()<<"\t\t"<<b.getcpu()<<"\t\t"<<c.getcpu()<<endl;
            cout<<"RAM:"<<"\t\t\t"<<a.getram()<<"\t\t"<<b.getram()<<"\t\t"<<c.getram()<<endl;
            cout<<"Memory:"<<"\t\t\t"<<a.getmemory()<<"\t\t"<<b.getmemory()<<"\t\t"<<c.getmemory()<<endl;
            cout<<"has Bluetooth:"<<"\t\t"<<a.getbluetooth()<<"\t\t"<<b.getbluetooth()<<"\t\t"<<c.getbluetooth()<<endl;
            cout<<"has Wifi:"<<"\t\t"<<a.getwifi()<<"\t\t"<<b.getwifi()<<"\t\t"<<c.getwifi()<<endl;
            cout<<"has Usb:"<<"\t\t"<<a.getusb()<<"\t\t"<<b.getusb()<<"\t\t"<<c.getusb()<<endl;
            cout<<"Optical device:"<<"\t\t"<<a.getopticaldeviceasstr()<<"\t\t"<<b.getopticaldeviceasstr()<<"\t\t"<<c.getopticaldeviceasstr()<<endl;
            cout<<"Price:"<<"\t\t\t"<<setprecision(3)<<a.getprize()<<"\t\t"<<setprecision(3)<<b.getprize()<<"\t\t"<<setprecision(3)<<c.getprize()<<endl;
            cout<<"Device Benefit:"<<"\t\t"<<setprecision(6)<<a.findDeviceBenefit()<<"\t\t"<<setprecision(6)<<b.findDeviceBenefit()<<"\t\t"<<setprecision(6)<<c.findDeviceBenefit()<<endl;
            cout<<"Price/Performance:"<<"\t"<<setprecision(3)<<a.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<b.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<c.calcPriceOverPerformance()<<endl;
            break;
        }
     case tv:
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"\t\t\t"<<a.getname()<<"\t"<<b.getname()<<"\t"<<c.getname()<<endl;
            cout<<"Screensize:"<<"\t\t"<<a.getscreen()<<"\t\t"<<b.getscreen()<<"\t\t"<<c.getscreen()<<endl;
            cout<<"has Wifi:"<<"\t\t"<<a.getwifi()<<"\t\t"<<b.getwifi()<<"\t\t"<<c.getwifi()<<endl;
            cout<<"has Hdmi:"<<"\t\t"<<a.gethdmi()<<"\t\t"<<b.gethdmi()<<"\t\t"<<c.gethdmi()<<endl;
            cout<<"has Usb:"<<"\t\t"<<a.getusb()<<"\t\t"<<b.getusb()<<"\t\t"<<c.getusb()<<endl;
            cout<<"Price:"<<"\t\t\t"<<setprecision(3)<<a.getprize()<<"\t\t"<<setprecision(3)<<b.getprize()<<"\t\t"<<setprecision(3)<<c.getprize()<<endl;
            cout<<"Device Benefit:"<<"\t\t"<<setprecision(3)<<a.findDeviceBenefit()<<"\t\t"<<setprecision(3)<<b.findDeviceBenefit()<<"\t\t"<<setprecision(3)<<c.findDeviceBenefit()<<endl;
            cout<<"Price/Performance:"<<"\t"<<setprecision(3)<<a.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<b.calcPriceOverPerformance()<<"\t\t"<<setprecision(3)<<c.calcPriceOverPerformance()<<endl;
            break;
        }
    }
     my_array[0]=a.calcPriceOverPerformance();
     my_array[1]=b.calcPriceOverPerformance();
     my_array[2]=c.calcPriceOverPerformance();
        if(my_array[0]>my_array[1]&&my_array[0]>my_array[2])
        {
            if(my_array[2]>my_array[1])
            {
               temp=my_array[2];
               my_array[2]=my_array[1];
               my_array[1]=temp;
            }


        }
        else if(my_array[1]>my_array[0]&&my_array[1]>my_array[2])
        {      temp=my_array[0];
               my_array[0]=my_array[1];
               my_array[1]=temp;

            if(my_array[2]>my_array[1])
            {
               temp=my_array[2];
               my_array[2]=my_array[1];
               my_array[1]=temp;
            }


        }
        else if(my_array[2]>my_array[0]&&my_array[2]>my_array[1])
        {      temp=my_array[0];
               my_array[0]=my_array[2];
               my_array[2]=temp;

            if(my_array[2]>my_array[1])
            {
               temp=my_array[2];
               my_array[2]=my_array[1];
               my_array[1]=temp;
            }


        }
if(my_array[2]==a.calcPriceOverPerformance()){cout<<"Best choice is "<<a.getname()<<endl;}
else if(my_array[2]==b.calcPriceOverPerformance()){cout<<"Best choice is "<<b.getname()<<endl;}
else if(my_array[2]==c.calcPriceOverPerformance()){cout<<"Best choice is "<<c.getname()<<endl;}



}

void displayObject2(ElectronicProduct &z)
{
    cout<<z.getid()<<"\t\t"<<z.getname()<<"\t\t"<<z.gettypeasstr()<<endl;
}


int main()
{
    int k;
    globalid = 1;
    ElectronicProduct b[50], *c=b;
    bool mybool=0,runforestrun=1;
    while(runforestrun)
    {
            cout<<"EE Tech Product Comparison\n";
            cout<<"-- Efe Balo -- 1813732 --\n";
            cout<<"Enter your choice:\n";
            cout<<"\t1- Enter new product\n";
            cout<<"\t2- Import all product data from TXT\n";
            cout<<"\t3- Display all products\n";
            cout<<"\t4- Choose 3 products to compare\n";
            cout<<"\t0- Exit program\n";
            cin>>k;
            switch(k)
                {   case 0:
                    {       runforestrun=0;
                            cout<<"Thank you for choosing EE Tech."<<endl;
                            cout<<"Program is closing in"<<endl;
                            cout<<"3"<<endl;
                            Sleep(1000);
                            cout<<"2"<<endl;
                            Sleep(1000);
                            cout<<"1"<<endl;
                            Sleep(1000);
                            break;
                    }

                    case 1:
                    {
                        enternewproduct(*c);
                        displayObject(*c);
                        c++;
                        break;
                    }
                    case 2:
                        {   if(mybool==0)
                            {c--;
                            ifstream filereader;
                            filereader.open ("allProductData.txt");

                            while(!filereader.eof()){
                            string s ;
                            float f;
                            filereader >> s;

                            if(s == "Name:")
                            {   char l;
                                filereader >> s;
                                filereader.get(l);
                                if(l==' ')
                                {
                                    string r;
                                    filereader>>r;
                                    c->setname(s+" "+r);
                                }
                                else
                                {
                                    c->setname(s);
                                    //filereader.putback(l);
                                }
                                //cout<<c->getname()<<endl;

                            }
                            else if(s == "Type:")
                            { filereader>>s;
                                    c->settype(s);
                                    //cout<<c->gettypeasstr()<<endl;
                            }
                            else if(s == "CPU:"){
                            filereader >> f;
                                c->setcpu(f);
                                //cout<<c->getcpu()<<endl;
                            }
                            else if(s == "RAM:"){
                            filereader >> f;
                                c->setram(f);
                                //cout<<c->getram()<<endl;
                            }
                            else if(s == "Mem:"){
                            filereader >> f;
                                c->setmemory(f);
                                //cout<<c->getmemory()<<endl;
                            }
                            else if(s == "Screen:"){
                            filereader >> f;
                                c->setscreen(f);
                                //cout<<c->getscreen()<<endl;
                            }
                            else if(s == "battLife:"){
                            filereader >> f;
                                c->setbattery(f);
                                //cout<<c->getbattery()<<endl;
                            }
                            else if(s == "has4g:"){
                            filereader >>s;
                                if(s=="True")c->set4g(1);
                                //cout<<c->get4g()<<endl;

                            }
                            else if(s == "hasBT:"){
                            filereader >>s;
                                if(s=="True")c->setbluetooth(1);
                                //cout<<c->getbluetooth()<<endl;
                            }
                            else if(s == "hasWifi:"){
                            filereader >>s;
                                if(s=="True")c->setwifi(1);
                                //cout<<c->getwifi()<<endl;
                            }
                            else if(s == "hasHdmi:"){
                            filereader >>s;
                                if(s=="True")c->sethdmi(1);
                                //cout<<c->gethdmi()<<endl;
                            }
                            else if(s == "hasUsb:"){
                            filereader >>s;
                                if(s=="True")c->setusb(1);
                                //cout<<c->getusb()<<endl;
                            }
                            else if(s == "hasFrCam:"){
                            filereader >>s;
                                if(s=="True")c->setfrontcam(1);
                                //cout<<c->getfrontcam()<<endl;
                            }
                            else if(s == "opticDev:"){
                            filereader >>s;
                                c->setopticaldevice(s);
                                //cout<<c->getopticaldeviceasstr()<<endl;
                            }
                            else if(s == "Price:"){
                            filereader >>f;
                                c->setprize(f);
                                //cout<<c->getprize()<<endl;
                            }
                            else if(s.substr(0,3) == "==="){
                                c++;
                                //cout<<c->getid()<<endl;
                            }
}

                            cout<<"Parsing data has finished."<<endl;
                            mybool=1;
                            }
                            else
                                cout<<"Parsing of 'allProductData.txt' is done and cannot be done again."<<endl;
                            break;
                        }
                    case 3:
                    {   cout<<"Product ID\tProduct Name\t\tProduct Type"<<endl;
                        if(b!=c)
                        {
                            ElectronicProduct *d;
                            d=c;
                            while (b!=c)
                            {
                            c--;
                            displayObject2(*c);
                            }
                            c=d;
                            break;
                        }
                    }
                    case 4:
                        {   int id1,id2,id3;
                            string str_1,str_2,str_3;
                            cout<<"Please enter product id's:"<<endl;
                            cin>>id1;
                            cin>>id2;
                            cin>>id3;
                            id1--;
                            id2--;
                            id3--;
                            str_1=b[id1].gettypeasstr();
                            str_2=b[id2].gettypeasstr();
                            str_3=b[id3].gettypeasstr();

                            if(str_1==str_2 && str_1==str_3 && str_2==str_3)

                            {
                                compare3products(b[id1],b[id2],b[id3]);

                            }
                            else
                            {
                                cout<<"3 objects that you want to compare are not same type."<<"\n"<<" Please choose same type products."<<endl;
                            }

                        }
                }
    }

return 0;
}
