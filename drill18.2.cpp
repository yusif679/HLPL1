#include "std_lib_facilities.h"
//vector drill

void print_vector(const vector<int>& v) {
for(int i=0;i<v.size();++i)
    cout << v[i]<<"\n";
}
vector<int> gv;

void f(const vector<int>& v)    //takes vector argument
{
vector<int> lv(v.size());
lv=gv;
print_vector(lv);
cout<<"\n";
vector<int> lv2(v);             //copying vector arguments
print_vector(lv2);
cout<<"\n";
}

void power_gv(vector<int>& v)
{
for(int i=0;i<10;++i)
v.push_back(pow(2,i));        //first 10 quadratic forms 
}

int main() try
{
power_gv(gv);
f(gv);
vector<int> v1;
v1.push_back(1);
for(int i=1;i<10;++i)
{
v1.push_back(v1[i-1]*(i+1));
}
f(v1);       //f has argument of v1 now
}
catch(exception& e){
cerr<<"exception: "<<e.what()<<endl;
}
catch(...) {
cerr<<"exception\n";
}
