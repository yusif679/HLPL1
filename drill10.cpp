#include "std_lib_facilities.h"
//each comment is a exercise in 10th drill
//please dont rename the file "mydata" for some reason it does not work with suffix .txt
//y defining the data type Point that has two coordinate members x and y
struct Point {
int x;
int y;
};

//Input of point
istream& operator>>(istream& is, Point& p)
{
char ch1;
if (is >> ch1 && ch1 != '(') {
is.unget();
is.clear(ios_base::failbit);
return is;
}

char ch2;
char ch3;
int x1;
int y1;
is >> x1 >> ch2 >> y1 >> ch3;
if (!is || ch3 != ')') {
    if (is.eof()) return is;
    error("bad point");
                       }
p.x = x1;
p.y = y1;
return is;
}

//output of point
ostream& operator<<(ostream& os, Point& p)
{
return os << '(' << p.x << ',' << p.y << ')';
}

//Read points back in from file
void fill_from_file(vector<Point>& points, string& name)
{
ifstream ist {name};
ist.exceptions(ist.exceptions()|ios_base::badbit);

if (!ist) error("Can't open input file ", name);
for (Point p; ist >> p; )
    points.push_back(p);
}

int main()
try {
    //prompt the user to input seven (x,y) pairs ,store it in a vector of Points called original_points.

cout << " Enter 7 sets of x, y points:\n";
vector<Point> original_points;

while (original_points.size() < 7) {
   
Point p;
cin >> p;
original_points.push_back(p);
                                   } 

// Print the data in original_points
for (Point p : original_points)
    cout << p;
        cout <<"<- are original points"<< '\n';

//Output the points to file
string fname = "mydata";

ofstream ost { fname };

if (!ost) error("Couldn't open file ", fname);

for (Point p : original_points)
    ost << p;
        ost.close();


//Read the file back into a vector
vector<Point> processed_points;
fill_from_file(processed_points, fname);

for (Point p : processed_points)
    cout<<p;
        cout<<"<- are written points to the file"<<'\n';


if (original_points.size() != processed_points.size())
cout<<"Something's wrong!\n";
}
catch (exception& e) {
cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch (...) {
cerr<<"Something terrible has happened!\n";
    return 2;
}