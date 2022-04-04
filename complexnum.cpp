#include "std_lib_facilities.h"

using namespace std;

class Complexnum {
public:
    double first = 0;
    double second = 0;

     
     void value(){
        cin>>first;
        cin>>second;}


void display(){
        cout<<first<<"+"<<second<<"i"<<endl;}

void sum(Complexnum c1, Complexnum c2){

        first=c1.first+c2.first;
        second=c1.second+c2.second;}
};

int main(){

    Complexnum c1,c2,c3;
    cout<<"enter two values: for first and second part of complex number"<<endl;
        c1.value();
    cout<<"enter two values: for first and second part of second complex number"<<endl;
        c2.value();
    cout<<"result of addition is"<<endl;
        c3.sum(c1,c2);
        c3.display();

    return 0;}