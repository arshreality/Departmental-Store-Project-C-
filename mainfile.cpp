#include<fstream.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

class product 
{
  char name[50];
  char section[50];
  char code[5];
  int quantity;
  float cost;
  
  public:

  void getdata();
  void showdata();

  int	Check1(char nm[]);
  int	Check2(char sec[]);
  int	Check3(char cd[]);

  void edit();
  void buy();
};

//	INPUT A PRODUCT
void product::getdata() 
{
  cout<<"\nEnter name of the product to be added to the Inventory: ";
  gets(name);

cout<<"\nEnter the section the product belongs to: "; gets(section);

cout<<"\nEnter the code associated to the product: "; cin>>code;

cout<<"\nEnter the cost of the product: "; cin>>cost;

cout<<"\nEnter the number of the product: "; cin>>quantity;

}

//	DISPLAY A PRODUCT AND ITS INFORMATION void product::showdata() {

cout<<"\nName: "<<name<<endl;
cout<<"Section: "<<section<<endl;
 
cout<<"Cost: "<<cost<<endl;
cout<<"Quantity: "<<quantity<<endl;
cout<<"Code: "<<code<<endl;
}

//	CHECK THE NAME OF THE PRODUCT

int product::Check1(char nm[]) { if (strcmp(nm, name) == 0)
return 1;

else

return 0;
}

//	CHECK THE SECTION OF THE PRODUCT

int product::Check2(char sec[]) { if (strcmp(sec, section) == 0)

return 1;

else
return 0;

}

//	CHECK THE CODE OF THE PRODUCT

int product::Check3(char cd[]) { if (strcmp(cd, code) == 0)

return 1;
else

return 0;

}

//	UPDATE DETAILS OF AN OBJECT

void product::edit() {
int x=0, n;
cout<<"\n Current details of the object: ";

showdata();
do {
cout<<"\nTo change the name of the item, press 1:

\n";

cout<<"\nTo change the code of the item, press 2:
\n";

cout<<"\nTo change the price of the item, press 3:

\n";
cout<<"\nTo increase the number (inventory) of the item, press 4: \n";
 
cout<<"\nTo decrease the number (inventory) of the item, press 5: \n";

cout<<"\nTo quit editing, press 0: \n";
cin>>n;

cout<<endl;

switch(n) {
case 1: cout<<"\nEnter the new name of the

object: ";

gets(name);
break;

case 2: cout<<"\nEnter the new code of the

object: ";
cin>>code;
break;
case 3: cout<<"\nEnter the new cost of the

object: ";

cin>>cost;
break;

case 4: cout<<"\nEnter the amount by which the

inventory to be increased: ";
cin>>x;

quantity= quantity + x;

break;
case 5: cout<<"\n Enter the amount by which
the inventory to be decreased: ";
quantity = quantity - x;

break;
case 0: cout<<"\n Closing this branch of the
program";

break;

default: cout<<"\n Try again please. ";
}

cout<<"\n Updated";

cout<<"\n New details of the product: "; showdata();

} while(n!=0);
}

//	PURCHASING AN ITEM

void product::buy() {

int n, totalcost,m=0;
do {

cout<<"\nEnter the quantity to be bought: "; cin>>n;

if(n> quantity) {
 
cout<<"\nInsufficient Inventory. Try
Again\n\n";
m=1;
}

else {

totalcost=cost*n;
cout<<"\nName:"<<name<<"\nQuantity to be

bought:"<<n<<"\nTotal Cost:"<<totalcost<<"\n"; cout<<"Are you sure you want to
purchase?(Enter 1 to proceed, else enter 2.\n"; int j;

cin>>j;
if(j==1) {
quantity -=n;
cout<<"\nSuccessfully Purchased "<<n<<"

"<<name<<".";

cout<<"\nInventory Remaining:
"<<quantity<<endl<<endl;

cout<<"\n\nPress any key to continue."; getch();clrscr();
}

else {

cout<<"Purchase Canceled!!"<<endl; cout<<"\n\nPress any key to continue."; getch();clrscr();

}

m=0;
}
} while(m==1);

}

//	EDIT/ MODIFY A PRODUCT

void modify() {
int modified=0;
char ch[100];

fstream f1("data.dat", ios::binary|ios::in); fstream f2("temp.dat", ios::binary|ios::out);

product a;

cout<<"\nEnter the name or code of the product to be updated: ";

gets(ch);

while(f1.read((char*)&a,sizeof(a))) {
if(a.Check1(ch)||a.Check3(ch)) { a.edit();
 
modified++;
}
f2.write((char*)&a,sizeof(a));
}

if(modified!=0) {
remove("data.dat");

rename("temp.dat", "data.dat");

cout<<"\nRecord updated";
}

else

cout<<"\nTry again. No record found.";
}

//	APPEND A NEW RECORD

void append() {
product A;

fstream n;

n.open("data.dat",ios::binary|ios::app);
A.getdata();

n.write((char*)&A, sizeof(A));

n.close();
}

//	DISPLAY ALL RECORDS

void displayall() {
int counter=0;

product D;

fstream f1;
f1.open("data.dat",ios::binary|ios::in); while( f1.read((char*) &D, sizeof(D)) ) {

D.showdata();
counter++;
}
f1.close();

if (counter==0)
cout<<"\nInventory empty";
else

cout<<"\nTotal number of records: "<<counter;

}

//	SEARCH A PRODUCT BY NAME

void search1() {

char sn[100];
 
product S;
int f = 0;
cout<<"\n\nEnter the name to be searched : ";
gets(sn);

fstream f1;

f1.open("data.dat",ios::binary|ios::in); while( f1.read((char*) &S, sizeof(S)) ) { if(S.Check1(sn)==1) {

f++ ;
S.showdata();

}

}
f1.close();
if (f == 0)
cout<<"\n\n NO MATCH FOUND\n\n";

else

cout<<"\n\nTotal quantity in store available of
"	<<sn<<" is "<<f<<endl;

}

//	SEARCH A PRODUCT BY CATEGORY/SECTION

void search2() {
char sec[30];
product C;
int f = 0;

cout<<"\n\nEnter the Section to be searched : ";
gets(sec);
fstream f1;

f1.open("data.dat",ios::binary|ios::in); while( f1.read((char*) &C, sizeof(C)) ) {
if(C.Check2(sec)) {

f++ ;

C.showdata();
}
}
f1.close();

if (f == 0)
cout<<"\n\n NO MATCH FOUND \n\n";
else

cout<<"\n\n Total quantity in store available in

"	<<sec<<" is "<<f<<endl;
}

//	SEARCH A PRODUCT BY CODE void search3() {
 
char cd[20];
product C;
cout<<"\n\nEnter the code to be searched : ";
gets(cd);

fstream f1;

f1.open("data.dat",ios::binary|ios::in); while( f1.read((char*) &C, sizeof(C)) ) {

if(C.Check3(cd)) {

C.showdata();
}

}

f1.close();
}

//	DELETE A PRODUCT

void Delete() {
char sn[100];

product P;

int counter = 0;
cout<<"\n\nEnter the name or code of the product to be deleted : ";

gets(sn);
fstream f1,f2;
f1.open("data.dat",ios::binary|ios::in);

f2.open("temp.dat", ios::binary|ios::out); while( f1.read((char*) &P, sizeof(P)) ) {

if(P.Check1(sn)|| P.Check3(sn))
counter ++ ;

else

f2.write((char *) &P, sizeof(P));
}

f1.close();

f2.close();
if (counter == 0)
cout<<"\n\n NO MATCH FOUND \n\n";
else {

remove("data.dat");
rename("temp.dat" , "data.dat");
}

}

//	BUY DETAILS

void buys() { char sn[128]; int found=0; product a;
 

fstream f1,f2;
f1.open("data.dat", ios::binary|ios::in);
f2.open("temp.dat", ios::binary|ios::out);

cout<<"Enter the name/code of the product that needs to be bought:\n";

gets(sn);

while(f1.read((char*)&a,sizeof(a))) { if(a.Check1(sn)||a.Check3(sn)) {

a.buy();
found++;
}
f2.write((char*)&a,sizeof(a));

}

if(found!=0) {

remove("data.dat");

rename("temp.dat", "data.dat");
}

else

cout<<"\nPurchase Failed. Try Again.";
}

//	STORE MENU

void st() {
int opt;

clrscr();

do {
cout<<"\n\t\t\t\tMODERN DEPARTMENTAL STORE"; cout<<"\n\n\t\tOwner Menu\n"; cout<<"Press: "<<endl;

cout<<"1: Add a product to the database\n";
cout<<"2: Modify a product’s details\n";
cout<<"3: Delete a product from the database\n";

cout<<"0: Exit\n";
cin>>opt;
switch(opt) {

case 1: cout<<"Add product";

append();
break;

case 2: cout<<"Modify details";

modify();
break;

case 3: cout<<"Delete product";
 
Delete();
break;
case 0: cout<<"Exit";
exit(0);

break;

default: cout<<"Try again.";
clrscr();

}

} while(opt!=0);
}

//	BUYER MENU

void buyer() { clrscr(); int m; product a; do {

cout<<"\n\t\t\t\tMODERN DEPARTMENTAL STORE"; cout<<"Press: "<<endl;

cout<<"1: To buy\n";
cout<<"2: To search by section\n";

cout<<"3: To search by code\n";

cout<<"4: To search by name\n";
cout<<"5: To display all items\n";

cout<<"0: Exit\n"; cin>>m; switch(m) {

case 1: clrscr();
buys();

break;

case 2: clrscr();
search2();

break;

case 3: clrscr();
search3();
break;
case 4: clrscr();

search1();
break;
case 5: clrscr();

displayall();

break;
case 0: cout<<"Exiting";

exit(0);

break;
default: cout<<"Try again";

}
 
} while(m!=0);
}

//	MENU

void menu() { clrscr(); int a;

do {

cout<<"\n\n\t\t\t\t Departmental Store"; cout<<"\nPress: \n";

cout<<"1: Owner\n";

cout<<"2: Customer\n";

cout<<"0: Exit\n"; cin>>a; switch(a) {

case 1: clrscr();

st();
break;

case 2: clrscr();

buyer();
break;

case 0: cout<<"Exiting";

exit(0);
break;
default: cout<<"Try again";
}

} while(a!=0);
}

//	INTRODUCTION

void intro() {

clrscr();

cout<<"\n\n\t\t\t\t Departmental Store"; cout<<"\n\nMade by: Abhishek Goel and Arshdeep Singh"; cout<<"\n\n\nModern School, Barakhamba Road"; cout<<"\n\n\nPress any key to continue"; getch();

}

//	MAIN BODY

void main() {

intro();

clrscr();
menu();

}
