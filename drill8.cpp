//chapter 8, drill 2
#include "std_lib_facilities.h"
void swap_v(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"swap_v a="<<a<<", swap_v b="<<b<<endl;
	
}

void swap_r(int& a,int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"swap_r a="<<a<<", swap_r b="<<b<<endl;
	
}

//void swap_cr(const int& a, const int& b)
//{
//	int temp;
//	temp=a;
//	a=b;                                          error,assingment of read-only reference 'a',const can not be swapped
//	b=temp;                                       error,assingment of read-only reference 'b',const can not be swapped
//	cout<<"x= "<<a<<" y="<<b<<endl;
//}

int main()
{  //swap_v
	int x=7;
	int y=9;
	swap_v(x,y);    // replace ? by v, r, or cr
	cout << "main   x="<< x << ", main   y=" << y << endl;
	
	swap_v(7,9);
	cout<<endl;
   //swap_v worked well
   
   //swap_r
    x=7;
    y=9;
    swap_r(x,y);   // replace ? by v, r, or cr
    cout << "main   x="<< x << ", main   y=" << y << endl;
    cout<<"\n";
    //swap_r(7,9);   //[Error] cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
	               //[Note] initializing argument 1 of 'void swap_r(int&, int&)'
   //swap_r(x,y) worked well
	
	
   //swap_cr
//   x=7;
//   y=9;
//   swap_cr(x,y);   // replace ? by v, r, or cr
//   cout << "main   x="<< x << ", main   y=" << y << endl;
//swap_cr does not work because of constant value which can not be swapped
   
   //swap_v cx, cy 
   const int cx = 7;
   const int cy = 9;
   swap_v(cx,cy);
   cout << "main  cx="<< cx << ", main  cy=" << cy << endl;
   swap_v(7.7,9.9);
   //swap_v(cx,cy) worked well
   cout<<"\n"; 
 /*  swap_r cx, cy
   cx = 7;          
   cy = 9;
   swap_r(cx,cy);                          //[Error] cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
   cout << "main  cx="<< cx << ", main  cy=" << cy << endl;
   swap_r(7.7,9.9);                        //[Note] initializing argument 1 of 'void swap_r(int&, int&)'
   swap_r did not work
*/

//swap_cr cx cy
//    cx = 7;
//    cy = 9;
//    swap_cr(cx,cy);
//    cout << "main  cx="<< cx << ", main  cy=" << cy << endl;
//    swap_cr(7.7,9.9);
//    [Error] assignment of read-only variables 'cx' 'cy'
//    swap_cr did not work


  
    //swap_v dx, dy
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);           
    cout << "main dx="<< dx << ", main dy=" << dy << endl;      
    swap_v(7.7,9.9);    //worked but only with integer part,fraction part did not appear
    
    //swap_r dx, dy
    //dx = 7.7;
    //dy = 9.9;
    //swap_r(dx,dy);                      //[Error] cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //cout << "main  dx="<< dx << ", main  dy=" << dy << endl;
    //swap_r(7.7,9.9);                    //[Error] cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //swap_r did not work
    
	
	//swap_cr dx, dy
    //dx = 7.7;
    //dy = 9.9;
    //swap_cr(dx,dy);
    //cout << "main  dx="<< dx << ", main  dy=" << dy << endl;
    //swap_cr(7.7,9.9);
    //swap cr did not work

return 0;
}