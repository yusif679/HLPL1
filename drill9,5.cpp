#include "std_lib_facilities.h"

namespace Chrono {
enum class Month {
jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator+(const Month& m, int n)
{
int r =int(m)+ n;
r %=int(Month::dec);

if (r==0) return Month::dec;  
return Month(r);
}

// Define other operators based on +
Month operator-(const Month& m, int n) 
                       { return (m+(-n)); }

Month& operator+=(Month& m,int n) 
                       { m=m+n;return m;
					    }

bool operator<(const Month& m,int n)
                       { return int(m)< n; 
					   }

bool operator>(const Month& m, int n) 
                       { return int(m) >n;
					}

class Date {
public:
class Invalid {};
Date(int yy, Month mm, int dd);

Month month() const
 { return m; }
int day() const
 { return d; }
int year() const 
{ return y; }

void add_day(int n);            //date++ by n days
void add_month(int n);          //date++ by n month         
void add_year(int n);           //date++ by n years 
private:
int y;          // year
Month m;
int d;          // day
bool is_valid();
};

Date::Date(int yy, Month mm, int dd)
:y{yy}, m{mm}, d{dd}
{
if (!is_valid()) throw Invalid{};
}

bool Date::is_valid()
//if data object is valid
{
if (d<1 || d>31) return false;
if (m<Month::jan || m>Month::dec) return false;
return true;
}

void Date::add_day(int n)
// + - days
{
// we suppose that every month has 31 days
int n_d =n%31;        
int n_m = (n/31)%12;   
int n_y = n/(31*12);     
d += n_d;

//making sure that date is not out of range and not negative
if (d>31){++n_m;d-=31; }     
if (d<1) {--n_m;d+= 1; }  
 
    
if (Month::dec<(int(m)+n_m)) ++n_y;
if (Month::jan>(int(m)+n_m)) --n_y;
m += n_m;   
y += n_y;
}

void Date::add_month(int n)
// + - month
{
int n_m= n% 12;   // months out of years, to increase
int n_y= n/ 12;   // years to increase

if (Month::dec < (int(m)+n_m)) ++n_y;
if (Month::jan > (int(m)+n_m)) --n_y;
m+= n_m;   // m is of Month type
y+= n_y;
}

void Date::add_year(int n)
//+ - years
{
y += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os <<'('<< d.year()
              <<','<< int(d.month())
              <<','<< d.day() 
			  <<')';
}

}; // namespace Chrono

int main()
try
{
    using Chrono::Date;
using Chrono::Month;

Date today{1978, Month::jun, 25};

Date tomorrow{today};
tomorrow.add_day(1);


cout << "Today: " << today << '\n';
cout << "Tomorrow: " << tomorrow << '\n';

    
Date test{2015, Month::may, 6};

test.add_day(8);   // 2015.5.6 + 0.0.8=2015.5.14
cout<< "May 14 2015? "<<test << '\n';

test.add_day(-11);  
cout<< "May 3 2015? "<<test << '\n';

test= Date{2022, Month::may, 7};
test.add_day(29);   
cout<< "June 5 2022? "<<test<< '\n';

test.add_day(+29);  
cout<< "Jule 3 2022? "<<test<<'\n';

test.add_day(+2400);   //increasing the years for experiment
cout<< "Nearly 6 years later? "<<test << '\n';

test.add_day(-1814); 
cout<< "Nearly 4 years before? " <<test << '\n';
    
// Test add_month() and add_year()
test.add_month(25); //(2026,1,15)
cout << "January 2 2026? " << test << '\n';
test.add_month(-25); //(2023,12,15)
test.add_year(8); 
cout << "January 1 2032? " << test << '\n';
test.add_year(-8);
cout << "january 1 2024? " << test << '\n';

// Invalid date
Date today_e{2002, Month::jun, -7};

return 0;
}
catch(exception& e)
{
cerr << e.what() << '\n';
return 1;
}
catch(Chrono::Date::Invalid)
{
cerr << "Invalid date!(negative)\n";
return 2;
}
catch(...)
{
cerr << "Unknown exception!!\n";
return 3;
}