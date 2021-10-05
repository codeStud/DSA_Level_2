#include<iostream>
using namespace std;

void printLexographically(int i, int n)
{
    if(i > n){
        return;
    }
    
    // expectation - below code will print all the families of 'i' lexographically
    // eg - if i == 1 then expectation is 
    // (1, 10( + lexographically-100, 1000, 101, 102...109), 11( + lexographically-110, 110, 111, 112...119), 12( + lexographically-120, 121, 122, 123...129), 
    //   .... 19 ( + lexographically-190, 191, 192... 199))
    cout<<i<<endl;
    for(int j = 0; j < 10; j++){
        printLexographically(10*i + j, n);
    }
}

int main()
{
    int n;
    cin>>n;
    
    // faith - below code will print all the families of 1, 2, 3.. 9 lexographically
    for(int i = 1; i < 10; i++){
        printLexographically(i, n);
    }
    
    return 0;
}