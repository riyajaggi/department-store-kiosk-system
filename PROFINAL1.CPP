/*
Name: Riya Jaggi
Class: XII A
Year: 2017-18
Computer Science Project

-----Files used-----
1. Customer Record: customer.dat (stores all customer records)
2. Store Items: itemlist.dat (stores list of items; accessed only by manager; uses password)

>>>>>Please store a copy of itemlist.dat file in your TURBO>BIN folder before executing the program.<<<<<

 All prices are in AED
*/

#include<fstream.h>	//for file-handling and i/o controls
#include<conio.h>	//for clrscr() and getch()
#include<stdio.h>	//for gets()
#include<string.h>	//for string functions like strcpy
#include<ctype.h>	//for tolower(), toupper()
#include<process.h>	//for exit()
#include<iomanip.h>	//for setw()
#include<dos.h>		//for delay()


void welcome()	//function for welcome screen
{

	cout<<endl<<endl;
	cout<<"\t  "<<"========================================================"<<endl<<endl;
	cout<<"\t  "<<"\t \t \t Welcome"<<endl<<endl;
	cout<<"\t  "<<"========================================================"<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"\t \t     C++ Project"<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"\t \t     Riya Jaggi"<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"\t \t     Grade XII A"<<endl<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"      Program for City Department Store Management"<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"========================================================"<<endl;
	cout<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"\tPress enter to continue."<<endl;
	getch();
	cout<<endl;
}

void instructions()	//function to display instructions on screen
{
	cout<<endl<<endl;
	cout<<"\t  "<<"========================================================"<<endl;
	cout<<"\t  "<<"\t \t      Instructions"<<endl;
	cout<<"\t  "<<"========================================================"<<endl<<endl;
	delay(300);
	cout<<"1. Follow on screen instructions to use the application. "<<endl;
	cout<<"2. This application uses delays to enhance readibilty. "<<endl;
	cout<<"3. To abort the application, enter 'n' (no) when the "<<endl;
	cout<<"    application asks to go back to Main Menu."<<endl;
	cout<<"4. All payment is via credit card only. No cash, gift cards or coupons"<<endl;
	cout<<"5. Please remember customer ID and password"<<endl;
	cout<<"6. If you quit the application, before taking receipt and fulfilling payment,"<<endl;
	cout<<"	then your cart items will be deleted."<<endl<<endl;
	delay(300);
	cout<<"\t  "<<"========================================================"<<endl;
	cout<<"\t  "<<"   Thanks for shopping here. We hope you come again"<<endl;
	cout<<"\t  "<<"========================================================"<<endl;
	cout<<endl;
	cout<<"\t  "<<"\tPress enter to continue."<<endl;
	getch();
	cout<<endl;

}

void storedetails()	//function for store details
{
	clrscr();
	cout<<"------------WELCOME TO CITY DEPARTMENT STORE------------"<<endl;
	delay(200);
	cout<<endl<<endl;
	cout<<"=============================================="<<endl;
	cout<<"\t \t Store Details"<<endl;
	cout<<"=============================================="<<endl;
	delay(300);
	cout<<"1. Store Timings: "<<endl;
	cout<<"		8:00am to 10:00pm (Sun to Thurs)"<<endl;
	cout<<"		8:00am to 11:30pm (Fri and Sat)"<<endl;
	cout<<"2. Items once sold cannot be exchanged"<<endl;
	cout<<"3. Items sold cannot be returned/refunded"<<endl;
	cout<<"4. All payment is via credit card only"<<endl;
	cout<<"5. Please remember customer ID and password"<<endl;
	cout<<"6. For further queries, email "<<endl;
	cout<<"		citystore@gmail.com"<<endl;
	delay(300);
	cout<<"=============================================="<<endl;
	cout<<endl;
}



class Date	//class to store date
{
private:
	int day, month, year;
public:
	Date();
	void dateenter();
	void datedisplay();
};

Date::Date()
{
	day=0;
	month=0;
	year=0;
}
void Date::dateenter()
{
	cout<<"(DD MM YYYY) ";
	cin>>day>>month>>year;
}
void Date::datedisplay()
{
	cout<<day<<"/"<<month<<"/"<<year;
}


class customer		//class to store customer records
{
private:
	int id;
	char name[50];
	Date dob;	//dob (date of birth) is object of class Date
	char address[75];
	char phone[11];
	char creditcard[13];
public:
	char password[25];
	customer();
	void cus_enter();
	void cus_display();
	int getid();
}current_cus;

customer::customer()	//constructor
{
	id=0;
	strcpy(name,"NONAME");
	strcpy(address, "NOADDRESS");
	strcpy(phone, "NOPHONE");
	strcpy(creditcard, "NOCREDITCARD");
	strcpy(password, "NOPASSWORD");
}

void customer::cus_enter()
{
	cout<<"Enter Customer ID number: ";
	cin>>id;
	cout<<"Enter name: ";
	gets(name);
	cout<<"Enter date of birth ";
	dob.dateenter();
	cout<<"Enter address: ";
	gets(address);
	cout<<"Enter phone (10 digits): ";
	cin>>phone;

		while(strlen(phone)<10 || strlen(phone)>10)
			{
			cout<<endl<<"*The phone number must have 10 digits.  Please enter again."<<endl;
			cin>>phone;
			}

	cout<<"Enter credit card number (XXX XXX XXXX) : ";
	gets(creditcard);
		

		while(strlen(creditcard)>12 || strlen(creditcard)<12 || creditcard[3]!=' ' || creditcard[7]!=' ')
			{
			cout<<endl<<"*Credit card number must have 10 digits in the format XXX XXX XXXX. Please enter again."<<endl;
			gets(creditcard);
			}

	cout<<endl<<"Set password. Password must be atmost 25 characters."<<endl;
	cout<<"Password is case sensitive. Please remember your password."<<endl;
	cout<<"Enter password: ";
	gets(password);

		while(strlen(password)>25)
			{
			cout<<"Password must have less than 25 characters. Please enter again."<<endl;
			cin>>password;
			}
	cout<<endl;
}

void customer::cus_display()
{
	cout<<"Customer Id: "<<id<<endl;
	delay(100);
	cout<<"Customer Name: "<<name<<"\t \t DOB: ";
	dob.datedisplay();
	delay(100);
	cout<<endl;
	cout<<"Address: "<<address<<"\t \t Phone: "<<phone<<endl;
	delay(100);
	cout<<"Credit Card: "<<creditcard<<endl;
	cout<<endl;
}

int customer::getid()	//returns customer id
{
	return id;
}

void newcustomer()	//function to make new customer record
{
	customer c;
	ofstream fout("customer.dat", ios::app|ios::binary);
	cout<<endl<<"-----------CREATING NEW CUSTOMER RECORD-----------"<<endl;
	delay(200);
	cout<<endl;
	cout<<"Fill out the required details to create new customer record"<<endl;
	cout<<endl;
	c.cus_enter();
	fout.write((char*)&c, sizeof(customer));
	fout.close();
	clrscr();
	cout<<"The following record has been added: "<<endl;
	delay(500);
	c.cus_display();
	cout<<endl;
}

void deletecustomer()	//function to delete an existing customer record
{
	customer c;
	char x, pass[25];
	int i, flag=0;
	cout<<endl<<"-----------DELETING CUSTOMER RECORD-----------"<<endl;
	delay(200);
	cout<<endl;
	ifstream fin("customer.dat", ios::in|ios::binary);
	ofstream fout("temp.dat", ios::out|ios::binary);
	cout<<"Enter customer id to delete: ";
	cin>>i;
	while(fin.read((char*)&c, sizeof(customer)))
	{
	if(c.getid()==i)
		{
		flag=1;
		c.cus_display();
		delay(500);
		cout<<"Are you sure you want to delete this record? (y/n) ";
		cin>>x;
		if(tolower(x)=='y')
			{
			cout<<endl<<"Enter password: ";
			gets(pass);
			if(strcmp(pass, c.password)!=0)
				{
				delay(500);
				cout<<"Incorrect password. "<<endl;
				delay(500);
				cout<<"You are not authorised to modify this record"<<endl;
				break;
				}
			else
				{
				cout<<endl<<"Your customer record has been deleted."<<endl;
				break;
				}
			}

		}
	else
		fout.write((char*)&c, sizeof(customer));
	}

	if(flag==0)
		cout<<"Record not found!"<<endl;

	fin.close();
	fout.close();
	remove("customer.dat");
	rename("temp.dat", "customer.dat");
	delay(400);
	cout<<endl;
}

void modifycustomer()	//function for modifying existing records
{
	customer c;
	int pos, i, flag=0;
	char x, pass[25];
	cout<<endl<<"-----------MODIFYING NEW CUSTOMER RECORD-----------"<<endl;
	delay(200);
	cout<<endl;
	cout<<"Enter customer id to modify: ";
	cin>>i;
	fstream file("customer.dat", ios::in | ios::out | ios::binary);
	while(file.read((char*)&c, sizeof(customer)))
		{
		if(c.getid()==i)
			{
			c.cus_display();
			flag=1;
			cout<<endl<<"Are you sure you want to modify this record? (y/n) ";
			cin>>x;
			if (tolower(x)=='y')
				{
				delay(500);
				cout<<endl<<"Enter password: ";
				gets(pass);
				if(strcmp(pass, c.password)!=0)
					{
					delay(500);
					cout<<"Incorrect password. "<<endl;
					delay(500);
					cout<<"You are not authorised to modify this record"<<endl;
					}
				else
					{
					clrscr();
					cout<<"Enter new details: "<<endl;
					c.cus_enter();
					pos=-1*sizeof(customer);
					file.seekp(pos, ios::cur);
					file.write((char*)&c, sizeof(customer));
					clrscr();
					cout<<"The modified record is: "<<endl;
					c.cus_display();
					}
				}


			}

		}
	if(flag==0)
		cout<<"Record not found!"<<endl;
	file.close();
	cout<<endl;
	delay(500);
	cout<<endl;

}


class items	//class to store items available in store
{
private:
	int itemcode;
	char name[50];
	float price;

public:
	char section[50];
	items();
	void it_enter();
	void it_display();
	int getcode();
	float returnprice();

};

items::items()
{
	strcpy(name, "NONAME");
	price=0;
	itemcode=0;
	strcpy(section, "NOSECTION");
}
void items::it_enter()
{
	cout<<"Enter itemcode: ";
	cin>>itemcode;
	cout<<"Enter name of item: ";
	gets(name);
	cout<<"Enter price: ";
	cin>>price;
	cout<<"Enter section: ";
	gets(section);
}

void items::it_display()
{
	cout<<itemcode<<setw(25)<<name<<setw(15)<<price;
}

int items::getcode()
{
	return itemcode;
}

float items::returnprice()
{
	return price;
}


void managerenter()
{
	items i;
	char ch;
	ofstream fout("itemlist.dat", ios::app|ios::binary);
do {
	clrscr();
	cout<<"--------------------MANAGER-Adding Item--------------------"<<endl;
	delay(1000);
	cout<<endl;
	i.it_enter();
	cout<<endl;
	fout.write((char*)&i, sizeof(items));
	delay(500);
	cout<<"Do you want to enter another item? ";
	cin>>ch;
	}while(tolower(ch)=='y');
	fout.close();
	cout<<endl;
}

void managermodify()
{
	clrscr();
	items i;
	int pos, cd,flag=0;
	char x;
	cout<<"--------------------MANAGER-Modifying Item--------------------"<<endl;
	delay(500);
	cout<<endl;
	cout<<"Enter item code to modify item details: ";
	cin>>cd;
	fstream file("itemlist.dat", ios::in | ios::out | ios::binary);
	file.seekg(0);
	while(file.read((char*)&i, sizeof(items)))
		{
		if(i.getcode()==cd)
			{
			cout<<endl;
			cout<<"Item No"<<setw(20)<<"Item"<<setw(15)<<"Price/pack"<<endl;
			cout<<"========================================================"<<endl;
			i.it_display();
			cout<<endl;
			flag=1;
			cout<<endl<<"Are you sure you want to modify this record? (y/n) ";
			cin>>x;
			if (tolower(x)=='y')
					{
					clrscr();
					delay(500);
					cout<<"Enter new details: "<<endl;
					i.it_enter();
					pos=-1*sizeof(items);
					file.seekp(pos, ios::cur);
					file.write((char*)&i, sizeof(items));
					clrscr();
					delay(500);
					cout<<"The modified item is: "<<endl;
					delay(500);
					i.it_display();
					}


			break;
			}

		}
	if(flag==0)
		cout<<"Item not found!"<<endl;
	file.close();
	delay(500);
	cout<<endl;
}

void managermenu()
{
	clrscr();
	char ch;
	cout<<"--------------------MANAGER--------------------"<<endl;
	delay(500);
	cout<<"A. Enter Items"<<endl;
	cout<<"B. Modify Items"<<endl;
	cout<<"C. Main Menu"<<endl;
	delay(500);
	cout<<"Enter choice "<<endl;
	cin>>ch;
	switch(tolower(ch))
		{
		case 'a':
			managerenter();
			break;
		case 'b':
			managermodify();
			break;
		case 'c':
			return;

		default:
			cout<<"Invalid operator"<<endl; break;
		}
}


void manager()	//manager function to set items available in store
{
	char p[25], ch;
	cout<<"--------------------MANAGER--------------------"<<endl;
	delay(200);
	cout<<"Enter password: "<<endl;
	gets(p);
	if(strcmp(p, "managerpassword")==0)
	{
	do{
		managermenu();
		delay(250);
		cout<<"Do you want to go back to manager menu? (y/n) ";
		cin>>ch;
	  }while(tolower(ch)=='y');

	}
	else
		cout<<"Invalid password"<<endl;
	cout<<endl;
	delay(300);
	cout<<"Press enter to continue. ";
	getch();
	cout<<endl;
}

class purchased_items	//class to keep track of items purchased by user
{
private:
	items p_item;
	float quantity;
	float item_total;

public:
	void pur_enter(items, float);
	void pur_display();
	float get_itemtotal();
};

void purchased_items::pur_enter(items i, float q)
{
	p_item=i;
	quantity=q;
	item_total=q*p_item.returnprice();
}

void purchased_items::pur_display()
{
	p_item.it_display();
	cout<<setw(15)<<quantity<<setw(15)<<item_total<<endl;
}

float purchased_items::get_itemtotal()
{
	return item_total;
}

class cart	//class for shopping cart
{
private:

	float totalcost;
	int itemcount;
public:
	purchased_items p_it[100];
	cart();
	void updatetotal(float);
	void updatecount();
	int getcount();
	void display();
}crt;

cart::cart()
{
	totalcost=0;
	itemcount=0;
}

void cart::updatetotal(float amt)
{
	totalcost+=amt;
}

void cart::updatecount()
{
	itemcount++;
}

int cart::getcount()
{
	return itemcount;
}

void cart::display()
{
	int i;
	cout<<"Item Code"<<setw(15)<<"Name"<<setw(18)<<"Price/pack"<<setw(18)<<"Quantity"<<setw(18)<<"Item Total"<<endl;
	cout<<endl<<"==============================================================================="<<endl;
	for(i=0; i<itemcount; i++)
		{
		crt.p_it[i].pur_display();
		delay(500);
		}
	cout<<endl;
	cout<<"==============================================================================="<<endl;
		delay(500);
	cout<<"\t \t Total Items Purchased: "<<itemcount<<endl;
		delay(500);
	cout<<"\t \t Total Cost: "<<totalcost<<" AED"<<endl;
	cout<<endl;
}

void payment(customer c)
{
	clrscr();
	char pass[25];
	cout<<endl<<"-------------------------PAYMENT------------------------"<<endl<<endl;
	delay(500);
	c.cus_display();
	cout<<"========================================================"<<endl;
	delay(500);
	cout<<"Enter your password to pay using your credit card."<<endl;
	cout<<"Password: ";
	gets(pass);
	if(strcmp(pass, c.password)!=0)
		{
		delay(500);
		cout<<"Incorrect password. "<<endl;
		cout<<"Payment not done. "<<endl;
		}
	else
		{
		delay(500);
		cout<<"Amount has been charged to your credit card."<<endl;
		delay(250);
		cout<<"Payment successful"<<endl;
		delay(250);
		cout<<endl<<"========================================================"<<endl;
		cout<<"Thanks for shopping! Come again soon!"<<endl;
		}
	delay(200);
	cout<<endl<<"Press enter to exit";
	getch();
	exit(0);
}
	
void receipt()	//function to display receipt and to checkout
{
	
	int id, flag=0;
	customer c;
	char pass[25];
	cout<<"Enter customer ID to proceed to cart: ";
	cin>>id;
	ifstream fin("customer.dat", ios::in|ios::binary);
	while(fin.read((char*)&c, sizeof(customer)))
		{
		if(c.getid()==id)
			{
			flag=1;
			cout<<endl<<"Enter password: ";
			gets(pass);
			if(strcmp(pass, c.password)!=0)
				{
				delay(200);
				cout<<"Incorrect password. "<<endl;
				delay(200);
				cout<<"You are not authorised to use this record"<<endl;
				}
			else
				{
				clrscr();
				c.cus_display();
				delay(500);
				cout<<endl<<"-------------------------------YOUR CART------------------------------"<<endl<<endl;
				delay(500);
				crt.display();
				cout<<"Press enter to proceed to payment. ";
				getch();
				cout<<endl;
				payment(c);
				break;
				}
			}
		}
	if(flag==0)
		cout<<"Customer id not found"<<endl;
	cout<<endl<<endl;
	
}

void purchase_message()		//function used to confirm purchase of an item
{
	int n, flag=0;
	items i;
	float q;
	cout<<"Enter item no to purchase item: ";
	cin>>n;
	delay(200);
	cout<<"Enter quantity: ";
	cin>>q;
	ifstream fin("itemlist.dat", ios::in|ios::binary);
	while(fin.read((char*)&i, sizeof(items)))
	{
		if(i.getcode()==n)
		{
			crt.p_it[crt.getcount()].pur_enter(i, q);
			cout<<"The item has been added to your cart."<<endl;
			crt.updatetotal(crt.p_it[crt.getcount()].get_itemtotal());
			crt.updatecount();
			flag=1;
			break;
		} 	
	}
	if(flag==0)
		cout<<"Invalid input"<<endl;
	fin.close();
	delay(1000);
		
}

void display_section(char sec[])	//function used to display items of a particular section
{       char x;
do{
	clrscr();
	ifstream fin("itemlist.dat", ios::in|ios::binary);
	items i;

	cout<<"------------------------"<<sec<<"------------------------"<<endl;
	delay(1000);
	cout<<endl;
	cout<<"Item No"<<setw(20)<<"Item"<<setw(15)<<"Price/pack"<<endl;
	cout<<"========================================================"<<endl;
	delay(500);
	while(fin.read((char*)&i, sizeof(items)))
	{
		if(strcmpi(i.section,sec)==0)
			{
			i.it_display();
			delay(100);
			cout<<endl;
			}
	}
	delay(200);
	cout<<"========================================================"<<endl;
	cout<<endl;
	fin.close();

	purchase_message();
	delay(200);
	cout<<endl<<"Do you want to purchase anything more from "<<sec<<" ? (y/n) ";
	cin>>x;
   }while(tolower(x)=='y');

}


void	purchasemenu()	//function for purchase menu
{ char x;
do{     clrscr();
	char ch;
	cout<<"------------------PURCHASE MENU------------------"<<endl<<endl;
	delay(100);
	cout<<"\t \t Store Sections "<<endl;
	cout<<"================================================="<<endl;
	delay(500);
	cout<<"\t A. Fruits and Vegetables"<<endl;
	cout<<"\t B. Snacks "<<endl;
	cout<<"\t C. Bakery"<<endl;
	cout<<"\t D. Confectionery"<<endl;
	cout<<"\t E. Dairy and Butchery"<<endl;
	cout<<"\t F. Games and Sports"<<endl;
	cout<<"\t G. Stationery"<<endl;
	cout<<"\t Z. Main menu"<<endl;
	delay(500);
	cout<<"================================================="<<endl;
	cout<<endl;
	cout<<"Enter your choice: ";
	cin>>ch;
	clrscr();
	switch(toupper(ch))
		{
		case 'A':
			display_section("Fruits and Vegetables");
			break;
		case 'B':
			display_section("Snacks");
			break;
		case 'C':
			display_section("Bakery");
			break;
		case 'D':
			display_section("Confectionery");
			break;
		case 'E':
			display_section("Dairy and Butchery");
			break;
		case 'F':
			display_section("Games and Sports");
			break;
		case 'G':
			display_section("Stationery");
			break;
		case 'Z':
			return;
		default:
			cout<<"Invalid input! "<<endl;
		}
	cout<<endl<<"Do you want to go back to PURCHASE MENU?(y/n) ";
	cin>>x;
	}while(x=='y'||x=='Y');
	cout<<endl;
}


void menu()	//function for mainmenu
{
char x;
do {
	clrscr();
	char ch;
	delay(300);
	cout<<"-----WELCOME TO CITY DEPARTMENT STORE-----"<<endl;
	cout<<endl;
	delay(300);
	cout<<"=========================================="<<endl;
	cout<<"\t \t MAIN MENU"<<endl;
	cout<<"=========================================="<<endl;
	delay(250);
	cout<<"\t A. New Customer"<<endl;
	cout<<"\t B. Delete Customer"<<endl;
	cout<<"\t C. Modify Customer"<<endl;
	cout<<"\t D. Purchase Menu"<<endl;
	cout<<"\t E. Checkout"<<endl;
	cout<<"\t F. Store Details"<<endl;
	cout<<"\t Y. Manager Only"<<endl;
	cout<<"\t Z. Exit"<<endl;
	cout<<"=========================================="<<endl;
	cout<<endl;
	delay(250);
	cout<<"Enter your choice: ";
	cin>>ch;
	clrscr();
	switch(toupper(ch))
		{
		case 'A':
			newcustomer();
			break;
		case 'B':
			deletecustomer();
			break;
		case 'C':
			modifycustomer();
			break;
		case 'D':
			purchasemenu();
			break;
		case 'E':
			receipt();
			break;
		case 'F':
			storedetails();
			break;
		case 'Y':
			manager();
			break;
		case 'Z':
			exit(0);
			break;
		default:
			cout<<"Invalid input! "<<endl;
		}
	cout<<"Do you want to go back to MAIN MENU?(y/n) ";
	cin>>x;
	}while(x=='y'||x=='Y');

}

void main()
{
clrscr();
welcome();
clrscr();
instructions();
clrscr();
menu();
getch();
}






