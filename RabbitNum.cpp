#include <iostream>
using namespace std;

int getRabbitNum(unsigned int month){
    if(month <= 1){
        return 1;
    } else{
        int num[2]={1,1};
        for(int ii=2;ii<=month;ii++){
            num[ii%2] = num[0] + num[1];
        }
        return num[month%2];
    }
}

int main(){
    unsigned int month;
    cout<<"�����������ӵ�������";
    cin>>month;
    cout<<"��"<<month<<"������������Ϊ��"<<getRabbitNum(month)<<endl;
    return 0;
}

