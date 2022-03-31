 #include "std_lib_facilities.h"

template<typename T>
struct S {
private:

	T val;

public:

	S(T vv = 0) : val{vv} {}

	void operator = (const T&);
	T& get();
	const T& get() const;
	void set(T x){val=x;}
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& s){
	val=s;
}

template<typename T>
void read_val(T& v){
	cin>>v;
}

int main()
{
	S<int> int_array {10};
	S<double> double_array {0.1};
    S<char> char_array {'a'};
    S<string> string_array {"alma"};
    S<vector<int>> iv {vector<int>{10,20,30,40,50}};

	cout << int_array.get() << endl;
	cout << double_array.get() << endl;
	cout << char_array.get() << endl;
	cout << string_array.get() << endl;

	int_array.set(12);
	char_array.set('b');

	cout << int_array.get() << endl;
	cout << char_array.get() << endl;

	int ii;
	read_val(ii);
	S<int> int_array_2 {ii};

	cout << int_array_2.get() << endl;


	return 0;
}