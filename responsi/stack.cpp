/*
  VARREL PRAYOGA
  A11.2021.13822
 */
#include <iostream>
#include <string>
#define MAX 30
using namespace std;

int top = 0;
string stk[MAX];

bool isFull(){
    if(top == MAX){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if(top == 0){
        return true;
    }else{
        return false;
    }
}

void push(char data){
    if(isFull()){
        cout<<"sudah penuh";
    }else{
        stk[top] = data;
        top++;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Data kosong" << endl;
    }else{
        stk[top]='\0';
    }
}

void tampil(){
    if(isEmpty()){
        cout<<"Data kosong" << endl;
    }else{
        cout << "sesudah konversi : ";
        for(int i = 0; i<=top; i++){
            cout<<stk[i];
        }
    }
}


int main(){
    char text[]= "HA***L*OAP***A*KAB*A***R";
    int panjang = sizeof(text)/sizeof(text[0]);

    for(int i=0; i<panjang; i++){
        if(text[i] == '*'){
            pop();
        }else{
            push(text[i]);
        }
    }
    //cetak teks asli
    cout << "Sebelum konversi : ";
    for(int i=0; i<panjang; i++){
        cout << text[i] << "";
    }
    cout << endl;

    tampil();
    cout << endl;

    return 0;
}
