#include "std_lib_facilities.h"

struct Date {
int y, m, d;                    // year, month, day
Date(int yy, int mm, int dd);   // check for valid date and initialize
void add_day(int n);            // increase the Date by n days
};

Date::Date(int yy, int mm, int dd)
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
d += n;           // increase dd by n days
     
//making sure that date is not out of range and not negative
if(d>31){++m;d-=31;}
     
if(d<1){--m;d+=31;}    
    
if(m>12){++y;m-=12;}
    
if(m<1){--y;m+= 12;}     
}

ostream& operator<<(ostream& os, const Date& d)
{
return os <<'('<<d.y
          <<','<<d.m
          <<','<<d.d 
		  <<')';
}

int main()
try
{
Date today{1978, 6, 25};

Date tomorrow{today};
tomorrow.add_day(1);


cout << "Today: " << today << '\n';
cout << "Tomorrow: " << tomorrow << '\n';

Date test{2015, 5, 6};


test.add_day(8);   // 2015.5.6 + 0.0.8=2015.5.14
cout<< "May 14 2015? " <<test<<'\n';
test.add_day(-19);  // 2015.5.14-0.0.19=2015.4.26
cout<< "April 26 2015? " <<test<<'\n';

test=Date{2022, 5, 7};            //yy,mm,dd
test.add_day(-7);   // 2022.4.31
cout<<"April 31 2022? " <<test<<'\n';
test.add_day(+29);  // 2022.5.29 
cout<<"May 29 2022? " <<test<<'\n';

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