#include <iostream>
using namespace std;

int main(){
    double y = 1 + 0.0171/12;
    double y_n = 1;
    double sum_y = y_n;
    double res;
    for(int ii=1;ii<48;ii++){
        y_n *= y;
        sum_y += y_n;
    }
    res = 1000*sum_y/y_n;
    cout<<"需要一次性存入"<<res<<"元"<<endl;
    return 0;
}
