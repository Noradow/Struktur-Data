/*
VARREL PRAYOGA
A11.2021.13822
*/
#include <iostream>
#define MAX 8

using namespace std;
struct Antrian{
               int data[MAX];
               int head;
               int tail;
   };
   Antrian antre;

void Create(){
   antre.head=antre.tail=-1;
   }

bool IsEmpty(){
   if(antre.tail==-1)
       return 1;
   else
       return 0;
   }

bool IsFull(){
    if(antre.tail==MAX-1)
        return 1;
    else
        return 0;
}

Enqueue(int data){
        if(IsEmpty()==1){
            antre.head=antre.tail=0;
            antre.data[antre.tail]=data;
            cout << "sudah dimasukan "  << "(" << antre.data << ")";
            cout << endl;
        } else
        if(IsFull()==0)
        {
            antre.tail++;
            antre.data[antre.tail]=data;
            cout << "sudah dimasukan "  << "(" << antre.data[antre.tail] << ")";
            cout << endl;
        }
}
int Dequeue(){
        int i;
        int e = antre.data[antre.head];
        for(i=antre.head; i<=antre.tail-1;i++){
            antre.data[i]=antre.data[i+1];
        }
        antre.tail--;
        cout << "mengeluarkan data " << e;
        cout << endl;
        return e;
}

void Tampil(){
    if(IsEmpty()==0){
        for(int i=antre.head;i<=antre.tail;i++){
            cout << " " << antre.data[i] << endl;
        }
    }else cout << "data kosong!\n";
}
main()
{
    int menu;
    int data;
    Create();
    do{
        cout << endl;
        cout << "MENU"<<endl;
        cout << "1. ENQUEUE " << endl;
        cout << "2. DEQUEUE " << endl;
        cout << "3. TAMPIL" << endl;
        cout << "4. EXIT" << endl;
        cout << "Masukan Pilihan : ";cin >> menu;
        switch(menu)
        {
                case 1:
                cout<<"Insert Data : ";cin>>data;
                Enqueue(data);
                break;

                case 2:
                Dequeue();
                break;

                case 3:
                Tampil();
                break;

                case 4:     //end program

                break;
        }

    }
   while(menu!=4);
    return 0;
}
