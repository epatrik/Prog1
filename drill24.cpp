#include "std_lib_facilities.h"
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

template<typename A> 
void size(const A& a)
{
    cout<<sizeof(a)<< endl;
}

int main(){

    char ch;
    short s;
    int i;
    long l;
    float f;
    double db;
    int* ip;
    double* dbp;
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout<<"1. feladat\n"<< endl;

    size(ch);
    size(s);
    size(i);
    size(l);
    size(f);
    size(db);
    size(ip);
    size(dbp);

    cout<<"\n2. feladat\n"<< endl;

    size(a);
    size(b);
    size(c);
    size(d);
    size(e);

    cout<<"\n3. feladat\n"<< endl;

    cout<< a.size()<<endl;
    cout<< b.size()<<endl;
    cout<< c.size()<<endl;
    cout<< d.size()<<endl;
    cout<< e.size()<<endl;

    cout<<"\n4. feladat\n"<< endl;
    
    
    int x;

    while (cin>>x)
    {
        cout<<"The square of "<< x << " is: " <<sqrt(x)<<endl;
    }
    
    cin.clear();
    cin.ignore();

    cout<<"\n5. feladat\n"<< endl;

    cout<<"Write 10 values:\n";

    float y;
    
    for (int i = 0; i < c.size(); i++)
    {
        cin>>y;
        c[i]=y;
    }

    cout << "\nValues:\n";

    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    cout<<"\n\n6. feladat\n"<< endl;

    int n;
    int m;
    cin >> n;
    cin >> m;
    Matrix<int,2> nm(n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nm(i,j)=i*j;
            cout  << nm(i,j)<< "\t";
        }
        cout<<endl;
    }

    cout<<"\n7. feladat\n"<< endl;

    Matrix<complex<double>> cm(10);
    complex<double> cd;
    complex<double> sum;

    for (int i = 0; i < cm.size(); i++)
    {
        cin>>cd;
        cm[i]=cd;
        sum=sum+cm[i];
    }
    cout << "Sum: " << sum << endl;

    cout<<"\n8. feladat\n"<< endl;

    int z;
    Matrix<int,2> mm(2,3);
    for (int i = 0; i < mm.dim1(); i++)
    {
        for (int j = 0; j < mm.dim2(); j++)
        {
            cin>>z;
            mm(i,j)=z;
        }
    }
    for (int i = 0; i < mm.dim1(); i++)
    {
        for (int j = 0; j < mm.dim2(); j++)
        {
            cout  << mm(i,j)<< "\t";
        }
        cout<<endl;
    }
    
    return 0;
}