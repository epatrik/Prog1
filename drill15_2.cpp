#include "std_lib_facilities.h"

struct Person{
private:
	string first_name;
	string last_name;
	int a;
public:
	Person(){}
	Person(string ff,string ll, int aa);	
	
	string fname() const {return first_name;}
	string lname() const {return last_name;}
	int age() const {return a;}
	
};

Person::Person(string ff,string ll, int aa):first_name(ff),last_name(ll),a(aa){
	if(aa<0 || aa>150){error("Invalid Age.");}
	string nn=ff+ll;
	for(char c:nn){
		if(c==';' || c==':' || c=='"' || c=='[' || c==']' || c=='*' || c=='&' || c=='^' || c=='%' || c=='$' || c=='#' || c=='@' || c=='!'){
			error("Invalid name.");
		}
	}
}

ostream& operator<<(ostream& os, Person p){
	os<<"First name: "<<p.fname()<<" Last name: "<<p.lname()<<" Age: "<<p.age()<<endl;
	return os;
}

istream& operator>>(istream& is, Person& p){
	string f;
	string l;
	int a;
	is>>f>>l>>a;
	p=Person(f,l,a);
	return is;
}


int main(){

	Person p("Goofy","Something",63);
	cout<<p;
	
	vector<Person> v;
	for(Person p1; cin>>p1;){
		if(p1.fname()=="end"){break;}
		v.push_back(p1);
	}
	for(Person p1:v){
		cout<<p1;
	}

	return 0;
}