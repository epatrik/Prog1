#include "std_lib_facilities.h"

template<typename C> 
void print(const C& c)
{
    for (auto& v : c)
        std::cout << v << " ";
    cout<<endl;
}

template<typename C> 
void increase(C& c,int e)
{
    for (auto& v : c)
        v=v+e;
}

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 i=f1; i!=e1; i++){
		*f2++ = *i;
	}
	return f2;
}

int main(){

    array<int,10> a1 {0,1,2,3,4,5,6,7,8,9};
    vector<int> v1 {0,1,2,3,4,5,6,7,8,9};
    list<int> l1 {0,1,2,3,4,5,6,7,8,9};

    array<int,10> a2 = a1;
    vector<int> v2 = v1;
    list<int> l2 = l1;

    print(a1);
    print(v1);
    print(l1);
    cout<<endl;

    increase(a2,2);
    increase(v2,3);
    increase(l2,5);
    
    print(a2);
    print(v2);
    print(l2);
    cout<<endl;

    copy2(a2.begin(),a2.end(),v2.begin());
    copy2(l2.begin(),l2.end(),a2.begin());

    print(a2);
    print(v2);
    print(l2);
    cout<<endl;

    if (find(v2.begin(),v2.end(),3)!=v2.end())
    {
        cout<< "The number is in the "<<distance(v2.begin(),find(v2.begin(),v2.end(),3))+1<< ". position" << endl;
    }
    else{
        cout<<"Not found\n";
    }
    
    if (find(l2.begin(),l2.end(),3)!=l2.end())
    {
        cout<< "The number is in the "<<distance(l2.begin(),find(l2.begin(),l2.end(),3))+1<<". position" << endl;
        
    }
    else{
        cout<<"Not found\n";
    }

    return 0;
}