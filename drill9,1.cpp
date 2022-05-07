#include "std_lib_facilities.h"

struct Date {
    int y;      // year
    int m;      // month in year
    int d;      // day of month
};

void init_day(Date& dd, int y, int m, int d)
//date check
{
if (d < 1 || d > 31) error("init_day: Invalid day(negative)");
if (m < 1 || m > 12) error("init_day: Invalid month(negative)");

dd.y = y;       
dd.m = m;
dd.d = d;
}

void add_day(Date& dd, int n)
// + - days
{
dd.d += n;    // increase dd by n days
     
//making sure that date is not out of range and not negative
if (dd.d>31){++dd.m;dd.d-=31;}     

if (dd.d<1){--dd.m;dd.d+=31;}     
    
if (dd.m>12){++dd.y;dd.m-=12;}  
   
if (dd.m<1) {--dd.y;dd.m+=12;}     
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
Date today;
init_day(today,1978,6,25);

Date tomorrow{today};
add_day(tomorrow,1);

cout << "Today: "<<today<<'\n';
cout << "Tomorrow: " <<tomorrow << '\n';

    
Date test;

init_day(test, 2015, 5, 6);           //yy,mm,dd
add_day(test, 8);   // 2015.5.6 + 0.0.8=2015.5.14
cout << "May 14 2015? " << test << '\n';
add_day(test, -19);  // 2015.5.14-0.0.19=2015.4.26
cout<< "April 26 2015? "<<test<<'\n';

init_day(test, 2022, 5, 7);            //yy,mm,dd
add_day(test, -7);   // 2022.4.31
cout<< "April 31 2022? "<<test<<'\n';
add_day(test, +29);  // 2022.5.29 
cout<< "May 29 2022? "<<test<<'\n';

// Invalid date
Date today_e;
init_day(today_e, 2002, 06, -7);

return 0;
}
catch(exception& e)
{
cerr<<e.what()<<'\n';
return 1;
}
catch(...)
{
cerr<<"Unknown exception!!\n";
return 2;
}