#include <iostream>

#include<fstream>



using namespace std;

class shopping{

private:

    int pcode;
    float price;
    float dis;
    string pname;


    public:

        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void remove();
        void list();
        void receipt();

        void rem();




};




void shopping :: menu(){
m:
int choice;
string  email;
string password;


cout<<"\t\t\t\t______________________________________________\n";
cout<<"\t\t\t\t                                               \n";
cout<<"\t\t\t\t                    supermarket                 \n";
cout<<"\t\t\t\t                                                \n";
cout<<"\t\t\t\t_______________________________________________ \n";
cout<<"\t\t\t\t                                                \n";




cout<<"\t\t\t\t | 1)Administrator    |\n";
cout<<"\t\t\t\t |                    |\n";
cout<<"\t\t\t\t | 2)buyer            |\n";
cout<<"\t\t\t\t |                    |\n";
cout<<"\t\t\t\t | 3)Exit             |\n";
cout<<"\t\t\t\t |                    |\n";
cout<<"\t\t\t\t | 4)please select!   |\n";
cout<<"\t\t\t\t |                    |\n";


cin>>choice;
switch(choice){

case 1:

    cout<<"\t\t\t please login \n";
     cout<<"\t\t\t enter email  \n";
     cin>>email;
      cout<<"\t\t\t please enter password \n";
      cin>>password;

      if(email=="nitin@email.com" && password =="nitin@123"){



        administrator();

      }
      else{

        cout<<"Invalid userName and password:";

      }
      break;







case 2:
    {

        buyer();


    }


    case 3:

    {


        exit(0);

    }

    default:{

        cout<<"please selected from given options \n";

    }

}
goto m;




}

void shopping:: administrator(){
    m:

int choice;
cout<<"\n\n\n\\t\t\t Administrator menu";

cout<<"\n\t\t\t|____ 1) add the product____|";
cout<<"\n\t\t\t|                           |";
cout<<"\n\t\t\t|_____2) modify the product_|";
cout<<"\n\t\t\t|                           |";
cout<<"\n\t\t\t|_____3) delete the product_|";
cout<<"\n\t\t\t|                           |";
cout<<"\n\t\t\t|_____4) back the product____|";

cout<<"\n\n\t please enter the choice ";

cin>>choice;


 switch(choice){

 case 1:
     add();
     break;


 case 2:
    edit();
    break;

 case 3:
    rem();
    break;

    case 4:
    menu();
    break;

    default:

        cout<<"invalid choice!";






 }

 goto m;




}


void shopping:: buyer(){

    m:
int choice;

cout<<"\t\t\t 1) buyer\n";
cout<<"                \n";
cout<<"\t\t\t 2) buy product\n";
cout<<"                \n";
cout<<"\t\t\t 3) go back\n";
cout<<"                \n";
cout<<"\t\t\t  enter the choice \n";

cin>>choice;

switch(choice)
{

case 1 :
    receipt();
    break;

case 2:

    menu();
    break;

default:

    cout<<"invalid choice ";




}
goto m;


}

void shopping:: add(){

m:
fstream data;
int c;
int token=0;
float p;
float d;
string n;
cout<<"\n\n\t\t Add new product";
cout<<"n\n\n\t product code of product  ";
cin>>pcode;

cout<<"n\n\n name of product";
cin>>pname;
cout<<"\n\n\t  Price of the product";
cin>>price;
cout<<"\n\n\t discount on product ";
cin>>dis;





data.open("database.txt", ios::in);
if(!data){


    data.open("database.txt",ios::app|ios::out);

    data<<" "<<pcode<<" "<< pname<<" "<< price<<" "<<dis<<"\n";
     data.close();



}

else{



    data>>c>>n>>p>>d;

    while(!data.eof()){


        if(c==pcode){

            token++;

        }

        data>>c>>n>>p>>d;

    }

    data.close();




if(token==1){

    goto m;
}

else{


   data.open("database.txt",ios::app|ios::out);

    data<<" "<<pcode<<" "<< pname<<" "<< price<<" "<<dis<<"\n";
     data.close();
}
}
cout<<"\n\n\t\t record inserted..";

}




void shopping:: edit(){
fstream data,data1;
int pkey;
int token=0;
int c;
float p;
float d;

string n;

cout<<"\n\n\t\t modify the record :";
cout<<"\n\\t\t\t  product code: ";
cin>>pkey;

data.open("database.txt",ios:: in);

if(!data){


    cout<<"\n\n file doesnot exist!";

}

else{


    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){


        if(pkey==pcode){


            cout<<"\n\t\t product of new code: ";
            cin>>c;
            cout<<"\n\t\t enter the name of product:";
            cin>>n;
            cout<<" \n\t\t price of product: ";
            cin>>p;


            cout<<"\n\t\t discont: ";
            cin>>d;
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\n\t\t record edited: ";
            token++;



    }

    else{

        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";



    }


    data>>pcode>>pname>>price>>dis;

    }

    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");


    if(token==0){



        cout<<"\n\n record not found";

    }



}





}





void shopping::rem(){

fstream data,data1;
int pkey;
int token=0;
cout<<"\n\n\t delete product";
cout<<"\n\n\t product code";
cin>>pkey;
data.open("database.txt", ios::in);
if(!data){


    cout<<"file not exists";


}

else{


    data1.open("database.txt",ios::app | ios:: out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){


        if(pcode==pkey){


            cout<<"\n\n\t\t  product deleted successfully";
            token++;
        }

        else{

            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";


        }

         data>>pcode>>pname>>price>>dis;
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0){



        cout<<"\n\n record not found";

    }


}



}


void shopping:: list(){






fstream data;

data.open("database.txt",ios::in);
cout<<"\n\n|___________________________\n";
cout<<"proNo\t\tname\t\tprice\n";
cout<<"\n\n|___________________________\n";

data>>pcode>>pname>>price>>dis;

while(!data.eof()){


    cout<<pcode<<"\t\t" <<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;



}

data.close();




}


void shopping::receipt(){


fstream data;
int arrc[100];
int arrq[100];
char choice;
int c=0;
float amount=0;
float dis=0;

float total=0;

count<<"\n\n\t\t\t receipt";

data.open("database.txt",ios::in);
if(!data){


    cout<<"\n\n empty database";


}

else{
    data.close();
    list();




    do{

m:
        cout<<"\n\n enter product code:";
        cin>>arrc[c];
        cout<<"\n\n enter the product quintity: ";

        cin>>arrq[c];
        for(int i=0;i<c;i++){

            if(arrc[c]==arrc[i]){


                cout<<"\n\n duplicate product";
                goto m;
            }

        }

        c++;
        cout<<"\n\n buying other product or not ";
        cin>>choice;

    }

    while(choice=="y");

    cout<<"\n\n\t\t\t________________________________recipt______\n";
    cout<<"\n productNo\t product Name\t product quantity\t price\tAmount\t Amount with discount\n  ";

    for(int i=0;i<c;i++){


        data.open("database.txt",ios::in);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){


            if(arrc[i]==pcode){

                amount=price*arrq[i];

                dis=amount-(amount*dis/100);

                total=total+dis;
                cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<< dis;





            }
            data>>pcode>>pname>>price>>dis;




        }
    }

    data.close();


}


cout<<"\n\n Total amount: "<<total;










}


int main(){

shopping s;
s.menu();

}

















