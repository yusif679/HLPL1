#include "std_lib_facilities.h"

void print_vector(ostream& os,vector<int> v) {
    
for (int i=0;i<v.size();++i)
    os<<v[i]<<"\n";
}

ostream& print_array10(ostream& os,int* a) {            //4 exercise drill 17

for (int i=0;i<10;i++) {
	os<<a[i]<<"\n";
	}
os<<"\n";
return os;
}

ostream& print_array(ostream& os,int* a,int n) {
for(int i=0;i<n;i++) {
		os<<a[i]<<"\n";
	}
os<<"\n";
return os;
}

int main() try{            //1-10

int* arr = new int[10];                 //1 exercise drill 17
for(int i=0;i<10; ++i)  {
		cout<<arr[i]<<"\n";}         //2 exercise drill 17
delete[] arr;                           //3 exercise drill 17
    
cout<<"\n";   
int* arr2=new int[10];                
for (int i=0;i<10;++i) {
	arr2[i]=100+i; }                    //5 exercise drill 17

print_array10(cout,arr2);               //4 exercise drill 17
delete[] arr2;

int* arr3=new int[11];
for(int i=0;i<11;++i)                   //6 exercise drill 17
{
	arr3[i]=100+i;                     
}
print_array(cout,arr3,11);              //7 exercise drill 17
delete[] arr3;

int* arr4=new int[20];                  //8 exercise drill 17
for(int i=0;i<20;++i)
{
	arr4[i]=100+i;
}
print_array(cout,arr4,20);
delete[] arr4;



vector<int> vec;
for(int i=0;i<10;++i){                //10 exercise drill 17  (same as 5 ex but with vectors) 
    vec.push_back(100+i);
                          } 
print_vector(cout,vec);
cout<<"\n";
   
vector<int> vec2;                          //10 exercise drill 17  (same as 6 ex but with vectors) 
for(int i=0;i<11;++i){
    vec2.push_back(100+i);
                          }
print_vector(cout,vec2);
cout<<"\n";


vector<int> vec3;                         //10 exercise drill 17  (same as 8 ex but with vectors) 
for (int i=0;i<20;++i){
    vec3.push_back(100+i);
                          }
print_vector(cout,vec3);
cout<<"\n";
 
 
//10-20


int z=7;                           //11 exercise drill 17  
int* p1=&z;
 

cout<<"p1= "<<p1<<"\n";        //12 exercise drill 17  
cout<<"*p1= "<<*p1<<"\n";

cout<<"\n";
int* p2 =new int[7];
for(int i=0;i<7;++i)                 
{ p2[i]= pow(2,i);}                  //13,14 ex           pow(base,exponent) in std_lib facilities
cout<<"p2="<<p2<<"\n";
cout<<"quadratic progression with arrays"<<"\n";
print_array(cout,p2,7);

int* p3=p2;                     
p2=p1;                             //15,16,17 ex
p2=p3;

cout<<"p1= " <<p1<<"\n";
cout<<"*p1= "<<*p1<<"\n";      //18 ex
cout<<"p2= "<<p2<<"\n";
cout<<"*p2= "<<*p2<<"\n";

cout<<"\n";
delete[] p2;                  //19 ex
p3 = 0;

p1=new int[10];
for(int i=0;i<10; ++i)       //20 ex
    p1[i]=pow(2,i);             //pow(base,exponent) in std_lib facilities

p2=new int[10];           //21 ex


for(int i=0;i<10; ++i)
p2[i]=p1[i];                 //22 ex
cout<<"quadratic progression with array"<<"\n";
print_array(cout,p2,10);

vector<int> vec4;
for(int i=0;i<10;++i)
vec4.push_back(pow(2,i));
vector<int> vec5;
    
for(int i=0;i<vec4.size();++i)
vec5.push_back(vec4[i]);
cout<<"quadratic progression with vector"<<"\n";         //23 ex
print_vector(cout,vec5);
}
catch (exception& e){
cerr<<"exception: "<<e.what()<<endl;
}
catch (...){
cerr<<"exception\n"<<"\n";
}