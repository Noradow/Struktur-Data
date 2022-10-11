/*
VARREL PRAYOGA
A11.2021.13822
*/

#include <iostream>
#include <string>
#define MAX 20
using namespace std;

int top = -1;
int stk [MAX];
int priority(char alpho);
bool isFull();
bool isEmpty();
void push(char oper);
char pop();
string in2postfix(string infix);
string in2prefix(string infix);
void reverseStr(string& str);



int main(){
    string infix,postfix,prefix;
    string con;

    cout << "insert infix : ";cin>>con;
    cout << endl;

    postfix = in2postfix(con);
    cout<<endl;
    prefix = in2prefix(con);
    cout << endl;


    return 0;
}

int priority(char alpha){
    if(alpha == '+' || alpha == '-'){
        return 1;
    }

    if(alpha == '*' || alpha == '/'){
        return 2;
    }

    if(alpha == '$'){
        return 3;
    }
    return 0;
}

bool isFull(){
    if(top == MAX - 1 ){
        return true;
    }else {
        return false;
    }
}

bool isEmpty(){
    if(top == -1 ){
        return true;
    }else {
        return false;
    }
}

void push(char oper){
    if(isFull()){
        cout<<"sudah penuh";
    }
    else{
        top++;
        stk[top] = oper;
    }
}

char pop(){
    char ch;
    if(isEmpty()==true){
        cout<< "stack Kosong";
    }else{
        ch = stk[top];
        stk[top]= NULL;
        top--;
        return ch;
    }
    return 0;
}

//Konversi ke Postfix
string in2postfix(string infix){
    int i = 0;
    string pst = "";

    while(infix[i]!='\0'){
        if(infix[i]>='a' && infix[i] <= 'z'){
            pst.insert(pst.end(),infix[i]);
            i++;
        }
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='['){
            push(infix[i]);
            i++;
        }
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']'){
            if(infix[i] == ')'){
                while(stk[top]!= '('){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '}'){
                while(stk[top]!= '{'){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == ']'){
                while(stk[top]!= '['){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
        }
        else{
            if(top == -1){
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.end(),pop());

                while(priority(infix[i]) == priority(stk[top])){
                    pst.insert(pst.end(),pop());
                    if(top<0){
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])){
                push(infix[i]);
                i++;
            }
        }
    }
    while(top != -1){
        pst.insert(pst.end(),pop());
    }
    cout<<"konversi ke postfix: "<<pst;
    return pst;
}

//reverse
void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }

}

//Konversi ke prefix
string in2prefix(string infix){
    int i = 0;
    reverseStr(infix);
    string pst = "";

    while(infix[i]!='\0'){

        if(infix[i]>='a' && infix[i] <= 'z'){
            pst.insert(pst.begin(),infix[i]);
            i++;
        }
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']'){
            push(infix[i]);
            i++;
        }
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='['){
            if(infix[i] == '('){
                while(stk[top]!= ')'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '{'){
                while(stk[top]!= '}'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '['){
                while(stk[top]!= ']'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
        }
        else{
            if(top== -1){
                push(infix[i]);
                i++;
            }

            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.begin(),pop());

                while(priority(infix[i]) == priority(stk[top])){
                    pst.insert(pst.begin(),pop());
                    if(top<0){
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])){
                push(infix[i]);
                i++;
            }
        }
    }
    while(top != -1){
        pst.insert(pst.begin(),pop());
    }
    cout<<"konversi ke prefix: "<<pst;
    return pst;
}

