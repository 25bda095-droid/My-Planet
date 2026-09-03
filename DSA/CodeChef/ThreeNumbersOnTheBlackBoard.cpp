#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==b && b==c){
            cout << 0 <<endl;
        }
        else if(a>=b && a>=c){
            if(a>=(b+c)){
                if(b>c) cout << b <<endl;
                else cout<< c <<endl;
            }
            else if(a<(b+c)){
                if(b<c) cout<< a-b <<endl;
                else cout<< a-c <<endl;
            }
        }
        else if(b>=a && b>=c){
            if(b>=(a+c)){
                if(a>c) cout << a <<endl;
                else cout << c <<endl;
            }
            else if(b<(a+c)){
                if(a<c) cout << b-a <<endl;
                else cout << b-c << endl;
            }
        }
        else{
            if(c>=(a+b)){
                if(a>b) cout << a <<endl;
                else cout << b << endl;
            }
            else if(c<(a+b)){
                if(a<b) cout << c-a << endl;
                else cout << c-b <<endl;
            }
        }
    }
}