#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
class medical
{
	private:
	int id,qt;           //ID and Quantity of medicine
	float prate,MRP;     //Purchase rate and MRP of medicine
	string name,edate;    //Name and Expiry date of medicine
	string password,username;

	public:
	void menu();
	void admin();
	void medicine();
	void bill();
	void add();
	void edit();
	void rem();
	void disp();
	void receipt();          //Definitation of method which has logic for cases in receit portal
	void receipt1();         //Having the main logic to generate bill
};
void medical::menu()                //definition of menu method
{
	M:
	int ch;

	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<"\n                         Welcome To Medical Store Management System                                \n";
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<endl;
	cout<<"\t\t\t __________________________________\n";
	cout<<"\t\t\t|              1]Log in            |\n";
	cout<<"\t\t\t|                                  |\n";
	cout<<"\t\t\t|              2]Exit              |\n";
	cout<<"\t\t\t|__________________________________|\n";
	cout<<endl;
	cout<<"Enter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1:
			   cout<<"\n --------------------------Please Login by entering your username and passoword-----------\n";
			   cout<<"\n Enter username:";
		       cin>>username;
		       cout<<"\n Enter password: ";
		       cin>>password;
		       //To check it is correct or not
		       if(username=="group3" && password=="123")
		       {
		       	    cout<<"\n ------------------Your are logged in successfully-----------------------------------\n";
					Sleep(2);
                    system("CLS");
					admin();   // Calling of admin method
			   }
			   else
			   {
			   	system("CLS");
			   	cout<<"\n.....................Invalid email/password ,Please try again................................."<<endl;
			   }
			   break;

		case 2:
			   exit(0);
			   break;

		default:
		       cout<<"Invalid choice please try again\n";
		       break;
	}
	goto M;

}
void medical::admin()                //definition of admin method
{
	A:
	int ch;
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<"\n                         Welcome To Admin Portal                                                  \n";
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<endl;
	cout<<"\t\t\t __________________________________\n";
	cout<<"\t\t\t|          1] Medicine Details     |\n";
	cout<<"\t\t\t|          2] Seller Portal        |\n";
	cout<<"\t\t\t|          3] Go to main menu      |\n";
	cout<<"\t\t\t|          4] Exit                 |\n";
	cout<<"\t\t\t|__________________________________|\n";
	cout<<endl;
	cout<<"Enter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1: Sleep(2);
                system("CLS");
		        medicine(); //Calling of medicine method
		        break;

		case 2: Sleep(2);
                system("CLS");
		        bill();  //Calling of bill method
		        break;

		case 3: Sleep(2);
                system("CLS");
		        menu(); // Calling of main menu
		        break;

	    case 4:exit(0);
	           break;

	    default:
	    	   cout<<"Invalid choice please try again\n";
	           break;
	}
	goto A;
}
void medical::medicine()        //definition of medicine function
{
	m:
	int ch;
	char x;
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<"\n                         Medicine Details                                                         \n";
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<endl;
	cout<<"\t\t\t __________________________________\n";
	cout<<"\t\t\t|        1] Add the medicine       |\n";
	cout<<"\t\t\t|        2] Modify the medicine    |\n";
	cout<<"\t\t\t|        3] Delete the medicine    |\n";
	cout<<"\t\t\t|        4] List the medicines     |\n";
	cout<<"\t\t\t|        5] Go to admin portal     |\n";
	cout<<"\t\t\t|        6] Go to main menu        |\n";
	cout<<"\t\t\t|        7] Exit                   |\n";
	cout<<"\t\t\t|__________________________________|\n";
	cout<<endl;
	cout<<"Enter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1:Sleep(2);
               system("CLS");
               do
               {
               	  add();   //Calling of method to add new medicine 
               	  cout<<"\n Add another medicine -> (y/n)";
               	  cin>>x;

			   }while(x=='y' || x=='Y');

		       goto m;
		       break;

		case 2:Sleep(2);
               system("CLS");
		       edit();  //Calling of method to modify medicine details

		       break;

		case 3:Sleep(2);
               system("CLS");
		       rem();   //Calling of method to delete medicine details
		       break;

		case 4:Sleep(2);
               system("CLS");
		       disp();  //Callling of method to display medicine details
		       break;

		case 5:Sleep(2);
               system("CLS");
		       admin();   //Calling of admin method (Going to admin portal)
		       break;

		case 6:Sleep(2);
               system("CLS");
		       menu(); //Calling of menu method (Going to main menu)
		       break;

		case 7: exit(0);
		       break;

		default:
			   cout<<"Invalid choice please try again\n";
	           break;
	}
	goto m;
}
void medical::bill() //Definition od=f method bill for seller portal
{
	b:
	int ch;
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<"\n                         Welcome to Seller Portal                                                  \n";
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<endl;
	cout<<"\t\t\t __________________________________\n";
	cout<<"\t\t\t|        1] Sell medicine          |\n";
    cout<<"\t\t\t|        2] Go to admin portal     |\n";
	cout<<"\t\t\t|        3] Go to main menu        |\n";
	cout<<"\t\t\t|        4] Exit                   |\n";
	cout<<"\t\t\t|__________________________________|\n";
	cout<<endl;
	cout<<"Enter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1:Sleep(2);
               system("CLS");
		       receipt();  //Calling of method for sell and generate bill
		       break;

		case 2:Sleep(2);
               system("CLS");
		       admin(); //Calling of admin method (Going to admin portal)
		       break;

		case 3:Sleep(2);
               system("CLS");
		       menu();   //Calling of menu method (Going to main menu)
		       break;


		case 4:exit(0);
		       break;

		default:
			   cout<<"Invalid choice please try again\n";
	           break;
	}
	goto b;




}
void medical::add()  //This method is used for adding new medicine details
{

	a:
	fstream item;
	int QT;
	float Prate,Mrate;
	string n,date;
	int token=0;                    //for checking esxisting and new id of medicine 
	int cid;

	cout<<"\n--------------------------------->Add new medicine<---------------------------------------\n";
	cout<<"Enter ID:";
	cin>>id;
	cout<<"Enter quantity:";
	cin>>qt;
	cout<<"Enter Purchase rate :";
	cin>>prate;
	cout<<"Enter MRP:";
	cin>>MRP;
	cout<<"Enter name:";
	cin>>name;
	cout<<"Enter Expiry Date:";
	cin>>edate;

	item.open("itembase.txt",ios::in);   //Open file for reading
	if(!item)                            //if not opened for reading then open for writing
	{
		item.open("itembase.txt",ios::app|ios::out);  //Open file for writing but don't do re-write
		item<<" "<<id<<" "<<qt<<" "<<prate<<" "<<MRP<<" "<<name<<" "<<edate<<"\n";  //write on to file  without re-writing
		item.close();
	}
	else
	{
		item>>cid>>QT>>Prate>>Mrate>>n>>date;  //read from file
		while(!item.eof())
		{
			if(cid==id)
			{
				token++;
			}
			item>>cid>>QT>>Prate>>Mrate>>n>>date;  //read from file :for iteration purpose
		}
		item.close();

	   if(token==1)
	   {
		   cout<<"ID is already used ,Enter another ID"<<endl;
		   goto a;
       }
	   else
	   {
		 item.open("itembase.txt",ios::app | ios::out);  //Open file for writing but don't do over-writing
		 item<<" "<<id<<" "<<qt<<" "<<prate<<" "<<MRP<<" "<<name<<" "<<edate<<"\n";
		 item.close();
	   }
    }
	cout<<"\n.................................Record inserted successfully...............................\n";
}
void medical::edit() //to edit medicine details
{


      fstream item,item1;
	  int QT,cid;                          //ID and Quantity of new medicine
	  float Prate,Mrate;                   //Purchase rate and MRP for new medicine
	  string n,date;                     //Name and expiry date for new medicine
	  int token=0;                    //To finding the record is available or not
      int key ;                     //ID of edited medicine

	 cout<<"\n--------------------------------->Modify old medicine<---------------------------------------\n";
	 cout<<"\n Enter ID of medicine to be modified:";
	 cin>>key;


	  item.open("itembase.txt",ios::in); //Open for read 
	  if(!item)
	  {
		    cout<<"\n Sorry , file does not exit";
      }
	 else
	 {
		item1.open("itembase1.txt",ios::app | ios::out);
		item>>id>>qt>>prate>>MRP>>name>>edate;  //read from old file
		while(!item.eof())
		{
			if(key==id)
			{

			    cout<<"\nEnter ID:";
                cin>>cid;
                cout<<"\nEnter quantity:";
                cin>>QT;
                cout<<"\nEnter Purchase rate :";
	            cin>>Prate;
	            cout<<"\nEnter MRP:";
	            cin>>Mrate;
                cout<<"\nEnter name:";
                cin>>n;
                cout<<"\nEnter Expiry Date:";
	            cin>>date;

	     		item1<<" "<<cid<<" "<<QT<<" "<<Prate<<" "<<Mrate<<" "<<n<<" "<<date<<"\n";  //write on file for second time
				cout<<"\n...................................Record edited................................................";
				token++;

			}
			else
			{
			    item1<<" "<<id<<" "<<qt<<" "<<prate<<" "<<MRP<<" "<<name<<" "<<edate<<"\n";  //write previous part as it is !!
            }
			item>>id>>qt>>prate>>MRP>>name>>edate;  //read from data file
		}

		item.close();
	    item1.close();

        remove("itembase.txt");  //remove item file
	    rename("itembase1.txt","itembase.txt"); //rename item1 file to data

	    if(token==0)
	    {
		    cout<<"Record not found ,sorry !";
        }

	}

}
void medical::rem() //to remove medicine and it's detail
{
	fstream item,item1;
	int key;
	int token=0;

	cout<<"\n--------------------------------->Delete medicien<---------------------------------------\n";
	cout<<"\n Enter ID of medicine to be deleted:";
	cin>>key;

	item.open("itembase.txt",ios::in);  //open file in read mode
	if(!item)
	{
	    cout<<"\n Sorry , file doesn't exist";
    }
	 else
	{
		item1.open("itembase1.txt",ios::app | ios::out);   //write on second file
		item>>id>>qt>>prate>>MRP>>name>>edate;  //read from old file
		while(!item.eof())
		{
			if(key==id)
			{
				cout<<"\n ............................Medicine deleted successfully.......................";
				token++;
			}
			else
			{
				item<<" "<<id<<" "<<qt<<" "<<prate<<" "<<MRP<<" "<<name<<" "<<edate<<"\n";
			}
			item>>id>>qt>>prate>>MRP>>name>>edate;

		}
		item.close();
		item1.close();

        remove("itembase.txt");  //remove item file
	    rename("itembase1.txt","itembase.txt"); //rename item1 file to data

       if(token==0)
       {
       	  cout<<"\n Record not found !!";
	   }
    }
}
void medical::disp() //To display list of medicine
{
   fstream item ;
   item.open("itembase.txt",ios::in);  //open the file in read mode
   cout<<"\n--------------------------------->List of medicines<---------------------------------------\n";
   cout<<"\n";

   cout<<"ID"<<" "<<" "<<" Quantity"<<" "<<" "<<" "<<"Purchase Rate"<<" "<<" "<<" "<<"MRP"<<" "<<" "<<" "<<" "<<"\t"<<"Name"<<" "<<" "<<" "<<" "<<"Expiry Date"<<"\n";
   if(!item)
   {
   	cout<<"\n File not founded !!";
   }
   else
   {

   	  while(!item.eof())
      {
      	item>>id>>qt>>MRP>>prate>>edate>>name;
      	if(item.eof())
      	{
      		break;
		}
   	    else
		{
   	        cout<<"\n";
   	        cout<<id<<"\t"<<qt<<"\t"<<" "<<MRP<<"\t\t"<<prate<<"\t"<<edate<<"\t"<<name<<"\n";
		}

      }
   }
   item.close();
}
void medical::receipt()       //Definitation of method which has logic for cases in receit portal
{
    int ch;

    cout<<"\n__________________________________________________________________________________________________\n";
	cout<<"\n                         Receipt Portal                                                            \n";
	cout<<"\n__________________________________________________________________________________________________\n";
	cout<<endl;
	cout<<"\t\t\t __________________________________\n";
    cout<<"\t\t\t|        1] Generate Bill          |\n";
    cout<<"\t\t\t|        2] Go to admin portal     |\n";
    cout<<"\t\t\t|        3] Go to main menu        |\n";
    cout<<"\t\t\t|        4] Exit                   |\n";
	cout<<"\t\t\t|__________________________________|\n";
	cout<<endl;
	cout<<"Enter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1:Sleep(2);
               system("CLS");
		       receipt1(); //Calling of receipt1 for billl generating logic
		       break;

		case 2:Sleep(2);
               system("CLS");
		       admin();  //Calling of admin method (Going to admin portal)
		       break;

		case 3:Sleep(2);
               system("CLS");
		       menu(); //Calling of menu method (Going to main menu)
		       break;


		case 4:exit(0);
		       break;

		default:
			   cout<<"Invalid choice please try again\n";
	           break;
	}

}
void medical::receipt1()  //Having the main logic to generate bill
{
	f:
	int idkey,qtkey,ch;
	int total=0;
	cout<<"\n Press '1' to show list of available medicines and sell medicine.............";
	cin>>ch;
	while(ch==1)
	{
		string person;
		disp();           //calling of disp function to show list of medicine
		fstream item;
		item.open("itembase.txt",ios::in);
		item>>id>>qt>>prate>>MRP>>name>>edate;
		cout<<"\n Enter the name of customer:";
		cin>>person;
		cout<<"\n Enter ID :";
		cin>>idkey;
		if(idkey==id)
		{
			cout<<"\n Record found !!";
			cout<<"\n Enter the quantity of medicine do you want to sell:";
			cin>>qtkey;
			if(qtkey<=qt)
			{
				cout<<"\n Quantity is available.....";

				cout<<"\n Generating a bill.......Please wait...";
				Sleep(1);
			    total=MRP*qtkey;
			    item>>name>>qt;

			    cout<<"\n__________________________________________________________________________________________________\n";
	            cout<<"\n                                 Final Receipt                                                    \n";
	            cout<<"\n__________________________________________________________________________________________________\n";
           	    cout<<endl;
	            cout<<"\t\t\t _________________________________________________\n";
                cout<<"\t\t\t        * Customer name *  ->     "<<person<<"\n";
                cout<<"\t\t\t        * Total Price   *  ->     "<<total<<"\n";
                cout<<"\t\t\t        * Medicine Name *  ->     "<<name<<"\n";
                cout<<"\t\t\t        * Quantity      *  ->     "<<qtkey<<"\n";
	            cout<<"\t\t\t_________________________________________________\n";
	            cout<<endl;
			}
			else
			{
				cout<<"\n Insufficient qauntity....";
			}

		}
		else
		{
			cout<<"\n Invalid choice !!";
		}
	    break;
		goto f;

	}
}

int main()
{
	medical m;
	m.menu();
}
