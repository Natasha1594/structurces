#include <iostream>
using namespace std;

int main(){

    int num1, num2, num3, num4, num5, avg, sum;

    cout<<"Enter 5 number: \n";

    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    cin >> num5;

    sum=num1+num2+num3+num4+num5;
    avg=sum/5;

    cout<<"Average is: "<<avg<<endl;

    if(avg>num1){
        cout<<"The first number" "is less than the average. Difference is:"<<avg-num1<<endl;
    }
    if(avg>num2){
        cout<<"The first number is less than the average. Difference is:"<<avg-num2<<endl;
    }
    if(avg>num3){
        cout<<"The first number is less than the average. Difference is:"<<avg-num3<<endl;
    }
    if(avg>num4){
        cout<<"The first number is less than the average. Difference is:"<<avg-num4<<endl;
    }
    if(avg>num5){
        cout<<"The first number is less than the average. Difference is:"<<avg-num5<<endl;
    }
    
    








    return 0;
}

