#include<iostream>
using namespace std;

// Class for account related work
class account{
    private:
    int balance=100000;   // starting balance
    public:
    int getBalance(){
        return balance;
    }
    bool deposit(int amount){
        if (amount>0){ 
            balance+=amount;
            return true;
        }
        else{
            return false;
        }
    }
    bool withdraw(int amount){
        if(amount>0 && amount <=balance){
            balance-=amount;
            return true;
        }
        else{
            return false;
        }
    }
};

// ATM controller class (handles menu and operations)
class ATMController{
    private:
    account User;     
    int choice;       
    int amount;       
    bool iscomplete;  
    public:
    bool running = true; // loop control

    void showMenu(){
        bool Invalid=true;
        do{
         cout<<" 1) Deposit\n 2) Withdraw\n 3) Check Balance\n 4) Exit."<<endl;
         cin>>choice;
         if(cin.fail()){ // if user enters non-number
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid Input, Please Enter a Choice Given in the Menu."<<endl;
         }
         else if(choice<1 || choice>4){ 
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid Input, Please Enter a Choice Given in the Menu."<<endl;
         }
         else{
            Invalid=false; 
         }
         }while(Invalid);
    }

    void handleDeposit(){
        iscomplete=true;
        do{
            cout<<"Please enter an amount to deposit."<<endl;
            cin>>amount;   
            bool result = User.deposit(amount); 
            if(result) {
              cout<<"The deposit of amount "<<amount<<" PKR is successfull."<<endl;  
              cout<<"Your New Account balance is: "<<User.getBalance()<<" PKR"<<endl; 
              iscomplete=false; 
            }
            else{
               cout<<"Invalid amount, please enter a valid amount to proceed."<<endl;
            }
        }while(iscomplete);
    }

    void handleWithdraw(){
        iscomplete=true;
        do{
            cout<<"Please enter an amount to withdraw."<<endl;
            cin>>amount;
            bool result= User.withdraw(amount); 
            if(result){
              cout<<"The withdraw of amount "<<amount<<" PKR is successfull."<<endl;
              cout<<"Your New Account balance is: "<<User.getBalance()<< " PKR"<<endl;
              iscomplete=false;  
            }
            else{
                if(amount<=0){
                    cout<<"Invalid Amount.\n";
                }
                else{
                   cout<<"Insufficient funds, please enter a valid amount."<<endl;
                }
            }
        }while(iscomplete);
    }
    
    void operations(){
       switch(choice){
            case 1:
                handleDeposit();  
                break;
            case 2:
                handleWithdraw(); 
                break;
            case 3:
                cout<<"Your available balance is "<<User.getBalance()<< " PKR."<<endl;
                break;
            case 4:
                cout<<"Thank you For using our ATM Service.\n";
                 running = false; 
                break;
        }
    }
};

int main(){
   ATMController obj; 
   cout<<"---WELCOME TO OUR ATM SIMULATION---"<<endl;
   do{
      cout<<"What would you like to do?\n";
      obj.showMenu();    
      obj.operations();   
   }while(obj.running);   
   return 0;
}
