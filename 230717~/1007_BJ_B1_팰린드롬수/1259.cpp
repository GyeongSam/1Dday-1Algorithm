#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        string word;
        cin >> word;
        if (word=="0") break;
        string answer = "yes";
        int l =0,r =word.size()-1;
        while(l<r){
            if (word[l]!=word[r]){
                answer="no";
                break;
            }
            l++;r--;
        }
        cout<< answer <<"\n";
    }
}