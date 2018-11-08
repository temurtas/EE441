#include <iostream>
#include  <string>




using namespace std;

//template <class T>
class Date
{
private:
            int month, day, year;
public:
            Date (int m=1, int d=1, int y=1900);
            Date (char *dstr);
		     void PrintDate( );
		     int JumpYear(int j) const;
		     void SetDate(int m, int d, int y);

		};
/* Class implementation */
/* constructor */
Date::Date(int m, int d, int y )
{
   month=m ;
	day=d;
	year=y;
}

int Date::JumpYear (int j) const
{
     return  year+j;
}
void Date::PrintDate()
{
cout<<"Month:"<<month<<" Day:"<<day<<" Year:"<<year<<"\n";
}


