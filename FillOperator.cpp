#include <iostream>
#include <array>
#include <sstream>
#include <regex>

using namespace std;

bool getResult(string eval,double *result){
    stringstream ss;
    double dbl;
    smatch resm;
    regex rep("[+-]?\\d+(\\.\\d+)?");
    regex_search(eval,resm,rep);
    ss<<resm.str();
    ss>>*result;
    ss.clear();
    eval = resm.suffix().str();

    while(regex_search(eval,resm,rep)){
        ss<<resm.str();
        ss>>dbl;
        ss.clear();

        if(resm.prefix().str() == "*")
            *result *= dbl;
        else{
            if(!dbl)
                return false;
            *result /= dbl;
        }
        eval = resm.suffix().str();
    }
    return true;
}

int main() {
    array<double,6> arrDataIn;
    array<string,4> arrOperator={"+","-","*","/"};

    cout << "请输入6个数字：";
    for(double &data:arrDataIn){
        cin>>data;
    }

    string strData,strTmp;
    stringstream ss;
    regex rep("[+-]\\d+(\\.\\d+)?([*/]\\d+(\\.\\d+)?)*");
    smatch resm;
    double dblTmp,dblRes;
    bool isSucceed;
    for(string operator1:arrOperator){
        for(string operator2:arrOperator){
            for(string operator3:arrOperator){
                for(string operator4:arrOperator){
                    dblRes = 0;
                    isSucceed = true;

                    ss<<"+"<<arrDataIn[0]<<operator1<<arrDataIn[1]<<operator2
                      <<arrDataIn[2]<<operator3<<arrDataIn[3]<<operator4<<arrDataIn[4];
                    ss>>strData;
                    ss.clear();

                    strTmp = strData;
                    while(regex_search(strTmp,resm,rep)){
                        isSucceed = getResult(resm.str(),&dblTmp);
                        if(isSucceed)
                            dblRes += dblTmp;
                        else
                            break;
                        strTmp = resm.suffix().str();
                    }

                    if(isSucceed && (dblRes>arrDataIn[5]?(dblRes-arrDataIn[5]):(arrDataIn[5]-dblRes)) < 1e-5){
                        cout<<strData.substr(1)<<"="<<arrDataIn[5]<<endl;
                    }
                }
            }
        }
    }

//    cin.get();
    return 0;
}