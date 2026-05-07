#include<iostream>
#include<stack>
using namespace std;
bool isMatch(char open,char close){
    return (open=='('&& close==')') || (open=='['&&close==']')||(open=='{'&&close=='}');
}
bool balanced(string exp){
    stack<int> s;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }
        else if(ch==')'||ch==']'||ch=='}'){
            if(s.empty()) return false;
            if(!isMatch(s.top(),ch)){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();

}
int main(){
    string expr;
    cout<<"Enter string of paranthesis: ";
    cin>>expr;
    if(balanced(expr)){
        cout<<"Balanced\n";
    }
    else
        cout<<"Not balanced\n";
}