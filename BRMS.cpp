#include<iostream>
#include<iomanip>
#include<cctype>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

class bank{
    long long acno;
    char name[20];
    char actype;
    long long mno;
    int amt;

    public:
    void create_acc();
    int dep_amt(int a);
    int withdraw(int a);
    void modify();
    void show_acc();
    void showAll_acc();
    void del_acc();
    int retac();
    int retdep();
    int rettype();
};

void bank::create_acc(){
    cout<<"\n\n\tEnter the name: ";
    char name1[20];
    cin.ignore();
    cin.getline(name1,20);
    for(int i=0;i<20;i++)
        name[i]=' ';
    for(int i=0;name1[i]!='\0';i++)
        name[i]=name1[i];
    cout<<"\n\tEnter Account number: ";
    cin>>acno;
    cout<<"\n\tEnter account type(C/S): ";
    cin>>actype;
    actype=toupper(actype);
    cout<<"\n\tEnter Mobile number: ";
    cin>>mno;
    cout<<"\n\tEnter Initial Amount(>=500 for Savings and >=1000 for Current): ";
    cin>>amt;
    cout<<"\n\n\n\t\t********** Account created successfully **********"<<endl;
}

int bank::dep_amt(int a){
    amt+=a;
}

int bank::withdraw(int a){
    amt-=a;
}

void bank::modify(){
    cout<<"\n\n\tAccount number: "<<acno<<endl;
    cout<<"\n\tEnter new name: ";
    char name1[20];
    cin.ignore();
    cin.getline(name1,20);
    for(int i=0;i<20;i++)
        name[i]=' ';
    for(int i=0;name1[i]!='\0';i++)
        name[i]=name1[i];
    cout<<"\n\tEnter new Phone Number: ";
    cin>>mno;
    cout<<"\n\tEnter new Account Type: ";
    cin>>actype;
    actype=toupper(actype);
}

void bank::show_acc(){
    cout<<"\n\n\tAccount Number: "<<acno<<endl;
    cout<<"\n\tName: "<<name<<endl;
    cout<<"\n\tPhone Number: "<<mno<<endl;
    cout<<"\n\tAccount Type: "<<actype<<endl;
    cout<<"\n\tBalance: "<<amt<<endl;
}

void bank::showAll_acc(){
    cout<<acno<<setw(17)<<" "<<name<<setw(10)<<" "<<mno<<setw(10)<<" "<<amt<<endl;
}

int bank::retac(){
    return acno;
}

int bank::retdep(){
    return amt;
}

int bank::rettype(){
    return actype;
}

void write();
void dep_with(int , int);
void modify_acc(int);
void show(int);
void show_all();
void delete_acc(int);

int main(){
    int i;
    int num;
    cout<<"\t\t\t\t\t\t\t\t\t\t======================================================\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t             BANKING MANAGEMENT SYSTEM\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t======================================================\n\n";

    do{

        cout<<"\n\n\n\n\n\n\n\t\t******************** MAIN MENU ********************\n\n\n\n"<<endl;
        cout<<"\t\t1. Create Account"<<endl;
        cout<<"\t\t2. Deposit Amount"<<endl;
        cout<<"\t\t3. Withdraw Amount"<<endl;
        cout<<"\t\t4. Modify Account"<<endl;
        cout<<"\t\t5. Show Account"<<endl;
        cout<<"\t\t6. Show All Account"<<endl;
        cout<<"\t\t7. Delete Account"<<endl;
        cout<<"\t\t8. Exit"<<endl;
        cout<<"\n\t\tEnter your choice(1-8): ";
        cin>>i;
        switch(i){
            case 1: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Create Account ***************\n";
                    write();
                    break;
            case 2: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Deposit Amount ***************"<<endl;
                    cout<<"\n\tEnter the account number: ";
                    cin>>num;
                    dep_with(num,1);
                    break;
            case 3: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Withdraw Amount ***************"<<endl;
                    cout<<"\n\tEnter the account number: ";
                    cin>>num;
                    dep_with(num,2);
                    break;
            case 4: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Modify Account ***************"<<endl;
                    cout<<"\n\tEnter the account number: ";
                    cin>>num;
                    modify_acc(num);
                    break;
            case 5: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Showing Account***************"<<endl;
                    cout<<"\n\tEnter the account number: ";
                    cin>>num;
                    show(num);
                    break;
            case 6: system("cls");
                    show_all();
                    break;
            case 7: system("cls");
                    cout<<"\n\n\n\n\n\t*************** Delete Account ***************"<<endl;
                    cout<<"\n\tEnter the account number: ";
                    cin>>num;
                    delete_acc(num);
                    break;
            case 8: system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t****************************** THANK YOU ******************************\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    break;
            default: cout<<"Invalid Choice";
                     break;
        }
    }while(i!=8);
    return 0;
}

void write(){
    bank b;
    ofstream o;
    o.open("account.dat",ios::binary|ios::app);
    b.create_acc();
    o.write(reinterpret_cast<char *>(&b),sizeof(bank));
    o.close();
}

void dep_with(int num, int a){
    bank b;
    int n;
    bool found=false;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\n\tFile not found";
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char *> (&b),sizeof(bank));
        if(num==b.retac()){
            b.show_acc();
            if(a==1){
                cout<<"\n\n\tEnter the amount to be deposited: ";
                cin>>n;
                b.dep_amt(n);
            }
            if(a==2){
                cout<<"\n\n\tEnter the amount to be withdrawn: ";
                cin>>n;
                int left=b.retdep()-n;
                if((left<500 && b.rettype()=='S') || (left<1000 && b.rettype()=='C'))
                cout<<"\n\tNot enough balance";
                else b.withdraw(n);
            }
            int position=(-1)*static_cast<int>(sizeof(b));
            file.seekp(position,ios::cur);
            file.write(reinterpret_cast<char *>(&b),sizeof(bank));
            cout<<"\n\n\n\t\t********** Account Updated **********";
            found=true;
        }
    }
    file.close();
    if(found==false)
    cout<<"\n\tAccount not found";
}

void modify_acc(int num){
    bool found=false;
    bank b;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\n\t File could not be opened";
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char*> (&b),sizeof(bank));
        if(b.retac()==num){
            b.show_acc();
            cout<<"\n\n\t\tEnter new details of the account\n"<<endl;
            b.modify();
            int position=(-1)*static_cast<int>(sizeof(bank));
            file.seekp(position,ios::cur);
            file.write(reinterpret_cast<char *> (&b), sizeof(bank));
            cout<<"\n\n\n\t\t********** Account modified **********";
            found=true;
        }
    }
    file.close();
    if(found==false)
    cout<<"\n\tAccount not found";
}

void delete_acc(int num){
    bank b;
    ifstream infile;
    ofstream outfile;
    infile.open("account.dat",ios::binary);
    if(!infile){
        cout<<"\n\tFile could not be opened";
        return;
    }
    outfile.open("Temp.dat",ios::binary);
    infile.seekg(0,ios::beg);
    while(infile.read(reinterpret_cast<char *> (&b), sizeof(bank))){
        if(b.retac()!=num){
            outfile.write(reinterpret_cast<char *> (&b), sizeof(bank));
        }
    }
    infile.close();
    outfile.close();
    remove("account.dat");
    cout<<"\n\n\t********** Account deleted **********";
    rename("Temp.dat","account.dat");
}

void show(int num){
    bank b;
    bool found=false;
    ifstream infile;
    infile.open("account.dat",ios::binary);
    if(!infile){
        cout<<"\n\tFile could not be opened";
        return;
    }
    cout<<"\n\n\n\t\t--------------- Account Datails ---------------\n";
    while(infile.read(reinterpret_cast<char *> (&b), sizeof(bank))){
        if(b.retac()==num){
            b.show_acc();
            found=true;
        }
    }
    infile.close();
    if(found==false)
    cout<<"\n\n\t Account does not exist";
}

void show_all(){
    bank b;
    ifstream infile;
    infile.open("account.dat",ios::binary);
    if(!infile){
        cout<<"\n\tFile could not be open";
        return;
    }
    cout<<"\n\n\n\t\t\t\t\t*****[ACCOUNT LIST]*****\n\n";
    cout<<"================================================================================================\n";
    cout<<"A/c no.           Name               Type        Mobile              Balance\n";
    cout<<"================================================================================================\n";
    while(infile.read(reinterpret_cast<char *> (&b), sizeof(bank))){
        b.showAll_acc();
    }
    infile.close();
}
