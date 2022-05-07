#include "std_lib_facilities.h"

class Date {
    int y, m, d;                    // year, month, day
public:
    Date(int yy,int mm,int dd);   // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
    int month() const{return m;}
    
    int day() const{return d;}
    
	int year() const{return y;}
};

Date::Date(int yy,int mm,int dd)
//date check
{
if(dd<1 || dd>31) error("init_day: Invalid day(negative)");
if(mm<1 || mm>12) error("init_day: Invalid month(negative)");

y = yy;       
m = mm;
d = dd;
}

void Date::add_day(int n)
// + - days
{
// we suppose that every month has 31 days
int n_d=n%31;          // days out of months, to increase
int n_m=(n/31)%12;     // months out of years, to increase
int n_y=n/(31*12);     // years to increase

y+=n_y;
m+=n_m;
d+=n_d;
     
//making sure that date is not out of range and not negative
if(d>31){++m;d-=31;}     

if(d<1){--m;d+=31;}     

if(m>12){++y;m-=12;}
     
if(m<1){--y;m+=12;}     
}

ostream& operator<<(ostream& os, const Date& d)
{
return os <<'('<<d.year()
          <<','<<d.month()
          <<','<<d.day() 
		  <<')';
}

int main()
try
{
Date today{1978, 6, 25};
Date tomorrow{today};
tomorrow.add_day(1);


cout<<"Today: "<<today <<'\n';


cout<<"Tomorrow: "<< tomorrow << '\n';

Date test{2015, 5, 6};


test.add_day(8);   // 2015.5.6 + 0.0.8=2015.5.14
cout<< "May 14 2015? " << test << '\n';
test.add_day(-19);  // 2015.5.14-0.0.19=2015.4.26
cout<< "April 26 2015? " << test << '\n';

test=Date{2022, 5, 7};            //yy,mm,dd

test.add_day(-7);   // 2022.4.31
cout<< "April 31 2022? " << test << '\n';

test.add_day(+29);  // 2022.5.29 
cout<<"May 29 2022? " << test << '\n';

test.add_day(+2400);   //increasing the years for experiment
cout<<"Nearly 6 years later? " << test << '\n';

test.add_day(-1825); 
cout << "Nearly 5 years before? " << test << '\n';

// Invalid date
Date today_e{2002, 06, -7};

return 0;
}
catch(exception& e)
{
cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
return 2;
}