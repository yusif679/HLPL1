#include "std_lib_facilities.h"


const char number = '8';   //we represent 8 as a number,it is not a value only a kind
const char quit   = 'q';    //exit the program 
const char print  = '=';    //to print out we use = after the expression
const char name   = 'a';   
const char let    = 'L'; 
const string declkey = "let";  //it is a decloration keyword
const string result  = "= ";  //mainly used to not repeat = in cout
const string prompt  = "> ";

constexpr char sqrttoken = 'S';  //it is a decloration of char for sqrt token          
const string sqrtkey = "sqrt";

constexpr char powtoken = 'P';   //it is a decloration of char for pow token   
const string powkey="pow";

const string quitkey = "exit";   //it is a decloration of exit 

double sqrt_calculation();     //functions declaration
double pow_calculation();
double expression();                    

class Variable {        //variable functions
	public:
	string name;
	double value;
};

vector<Variable>var_table;
double get_value(string s){                                       // returnes value of variable names s

	for (int i = 0; i<var_table.size(); ++i)
       if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);

}


void set_value(string s, double d)
{
	for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    error("set: undefined variable ", s);}


bool is_declared(string var)  //is var already in var table?
{
	for (int i = 0; i<var_table.size(); ++i)
      if (var_table[i].name == var) return true;
    return false;

} 

double define_name (string var, double val)   //adds (var,val) to var_table
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;

}
 //variable last line

class Token {                  //token function
    public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch):             kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n):   kind(ch), name(n) {}
};

class Token_stream {    //token stream function

public:
	Token_stream(); //make the Token stream that reads from cin
	void putback(Token t);//put a token back
	Token get();//get a token
    void ignore(char c); //delete tokens upto including  'c'
private:
	bool full; //is there a token in buffer?
	Token buffer;
};


Token_stream::Token_stream() :full(false), buffer(0){} //buffer is clear of tokens

void Token_stream::putback(Token t) //puts argument to token stream buffer
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true; //is buffer fool? yes=true
}

Token Token_stream::get() //read from cin and make a token
{
	if (full) 
	{
	full = false;
	return buffer;
	}
	char ch; 
	cin >> ch;// note that >> skips whitespace (space, newline, tab,)
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case name:
	case quit:
	case ',': //for pow
		return Token(ch); //let each character represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.putback(ch); //putback into input stream
	double val;
	cin >> val;  // read a floating-point number
	return Token(number, val);
	}
	default:
		{
		 if(isalpha(ch))
		 {
		 
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
            cin.putback(ch);
            if (s == declkey) return Token(let); 
            
            else if (s == sqrtkey) return Token(sqrttoken); //sqrtkey check
            
    		else if (s==powkey) return Token(powtoken);  //powkey check
    		
    		else if (s == quitkey) return Token(quit);   //quitkey chech  
    		
				else if (is_declared(s))
				return Token(number, get_value(s));
            return Token(name,s);
        }
		error("Bad token");
	}
	return 0;
}
}




void Token_stream::ignore(char c) //c is a kind of token
{
	if (full && c == buffer.kind) {    //looks at buffer
		full = false;
		return;
	}
	full = false;

	char ch=0;     //searches an input
	while (cin >> ch)
		if (ch == c) return;          
}



Token_stream ts;
//token stream last line



double expression(); //expression,term,primary functions
double sqrt_calculation()
{
    char ch;                                             
    if (cin.get(ch) && ch != '(') 
        error("'(' is required at starting of sqrt");          //check for ( )
    cin.putback(ch);                                    

    double d = expression();
    if(d < 0) error("negative value can not be under sqrt");
    return sqrt(d);                                             //sqrt is already in std_lib_facilities.h

}  
double pow_calculation()                                                //pow  function   
{
    Token t = ts.get();                                                 //getting input
    if (t.kind != '(') error("'(' is expected in starting of pow");     //error if no '('            

    double base = expression();                                         //getting base   

    t = ts.get();
    if (t.kind != ',') error("',' expected in after base in pow");      //error if no ','      

    double temp_exponent = expression();
    int exponent = narrow_cast<int>(temp_exponent);                     //floating number case            

    t = ts.get();
    if (t.kind != ')') error("')' is expected at the ending of power formula"); // error if no ')' 

    return pow(base, exponent);                                   //pow is already in std_lib_facilities.h
}

   double primary()
   {
   
	Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
	
	case '-':
		return -primary();
	case number:
		return t.value;        //return number value
	case name:
		return get_value(t.name); //return variable value
	case '+':
		return primary();
	case sqrttoken:
        return sqrt_calculation();
    case powtoken:
    	return pow_calculation();
    default:
		error("primarey expected");
	}
}
double term()           //* / % function
{
	double left = primary();
	Token t = ts.get();  
	
	while(true) {
        switch (t.kind) {            
		
		case '*':
		 { 
		left *= primary();
		t = ts.get();
		break;
	     }
		case '/':
		{	
		double d = primary();
		if (d == 0) error("division by zero");
		left /= d;
		t = ts.get();
		break;
		}
		case '%':
        {    
        double d = primary();
		if (d == 0) error("%: division by zero");
		left = fmod (left, d);
		t = ts.get();
		break;
        }
		
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()   //+ - function
{
	double left = term(); //read and evaluate Term
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		
		case '+':
			left += term();
			t = ts.get();
			break;
		
		case '-':
			left -= term();
			t = ts.get();
			break;
		
		default:
			ts.putback(t);
			return left;  //at the end if no more + or - then return the answer
		}
	}
}

double declaration() //i declared a variable called 'name' with the initial value 'expression'
{
	Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name,d);
    return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}
 
void clean_up_mess()
{
	ts.ignore(print);
}

void calculate()
{
	while (cin) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); //removes all prints
		if (t.kind == quit){                  //quits(end of program)
			keep_window_open();
			return ;}
		ts.putback(t);
		cout <<result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;    //error message
		clean_up_mess();
	}
}




int main()


try {
	cout << "Welcome to calculator\n";                                                                         //operators 
    cout << "There is a list of operators:\n";
    cout << "Addition is  '+'" << endl;
	cout << "Subtraction is  '-'" << endl;
	cout << "Multiplication is  '*'"<< endl;
	cout << "Division is  '/'" << endl;
	cout << "Modulo is  '%'" << endl;
	cout << "squareroot is 'sqrt()'" << endl;
	cout << "power is 'pow(base,exponent)'" << endl;
	cout << "result is '='" << endl;
	cout << "Use let to make the variables" << endl;
	cout << "Enter a 'q' to exit" << endl;
	cout << "Please write an expression:";
	define_name("k", 1000);
	calculate();
	keep_window_open();        //works on windows only
	return 0;
}
catch (runtime_error& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
} 
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}
/*
Grammar:
	
	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Print:
		=
	Quit:
		q
	Statement:
		Declaration
		Expression
	Declaration:
		"let" Name "=" Expression
	Name:
		string literal
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		( Expression )
		– Primary
		+ Primary
	Number:
		floating-point-literal
*/

