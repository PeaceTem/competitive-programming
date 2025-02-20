#include <bits/stdc++.h>

using namespace std;

int main(){
    for(int a=1;a<999;a++){
        for(int b=1;b<999;b++){
            for(int c=1;c<999;c++){
                if(a*a + b*b == c*c && a+b+c==1000){
                    cout << "A: " << a << " B: " << b << " C: " << c << " " << a*b*c << " " << '\n'; break;
                }
            }
        }
    }
}