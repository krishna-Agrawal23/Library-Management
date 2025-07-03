/*This Code is Coded By Krishna Agrawal*/

#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#define infinity 999999999

using namespace std;

struct store
{
	long long int cost[20];
	int array[20];
}travel[15];

struct initialdata{
	long long int cost[20];
}ini[15];

class datamodule{
	public:
	string city[15];
	
	//datamodule() constructor is used to initialize values of cities...
	
	datamodule():city{"Delhi","Mumbai","Chennai","Kolkata","Kerala","Hyderabad","Pune","Goa","Bangalore","Amritsar","Jaipur","Patna","Puducherry","Srinagar","Bhopal"}{}
	
	void costdeclaration(){
		int N,i,j;
		N=15;
		
		//Ten different major cities are considered

		//The cost of travelling between any two cities in direct flight is initialized. In further steps the minimum fare will be calculated
long long int arr[15][15]={{0,3500,2000,infinity,1000,infinity,infinity,infinity,infinity,7000,4000,1500,infinity,6500,infinity},
								   {3500,0,infinity,1520,infinity,infinity,infinity,2500,infinity,infinity,infinity,infinity,infinity,infinity,5000},
							       {2000,infinity,0,1500,infinity,3000,infinity,infinity,infinity,infinity,2000,1000,infinity,infinity,1500},
							       {infinity,1520,1500,0,infinity,1200,4500,infinity,6000,infinity,infinity,infinity,infinity,infinity,1000},
							       {1000,infinity,infinity,infinity,0,1500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,3000,1200,1500,0,1950,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,infinity,4500,infinity,1950,0,infinity,infinity,2050,infinity,infinity,infinity,infinity,infinity},
							       {infinity,2500,infinity,infinity,infinity,infinity,infinity,0,5000,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,infinity,6000,infinity,infinity,infinity,5000,0,7000,infinity,infinity,infinity,infinity,infinity},
							       {7000,infinity,infinity,infinity,infinity,infinity,2050,infinity,7000,0,infinity,infinity,infinity,infinity,infinity},
							       {4000,infinity,2000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity,infinity},
							       {1500,infinity,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity},
							       {infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity},
							       {6500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity},
							       {infinity,5000,1500,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0}};

	//the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
	//minimum possible fare between any origin and destination

		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				travel[i].cost[j]=arr[i][j];
				travel[i].array[j]=j;
				ini[i].cost[j]=arr[i][j];
			}
		}
	}
};

class bellmanfordalgorithm:public datamodule{
	public:
	int N,i,j,k;
	bellmanfordalgorithm(){
		N=15;
	}
	void algorithmic_implementation(){
	
		//3 different loops are executed
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				for(k=0;k<N;k++){
					if(travel[i].cost[j]>travel[i].cost[k]+travel[k].cost[j])
					{
						//if low fare is found for the same origin and destination, the minimum possible fare is changed.
					
						travel[i].cost[j]=travel[i].cost[k]+travel[k].cost[j];
						travel[i].array[j]=k;
					}
				}
			}
		}
	}
};
class filehandlingmodule{
	public:
	string username1,password1;
	bool log_in(string username,string password){
		ifstream fileread;
		fileread.open("login.txt");
		while(fileread>>username1>>password1){
			if((username==username1)&&(password==password1)){
				cout<<endl<<"                 Account Login Successful..."<<endl;
				return true;
			}
		}
		cout<<endl<<"                 Account Login Failed..."<<endl;
		return false;
	 }
	void createaccount(string username,string password){
		ofstream filewrite;
		filewrite.open("login.txt",ios::app);
		filewrite<<username<<" "<<password<<"\n";
		filewrite.close();
		cout<<endl<<"                 Account Created ..."<<endl;
	}
	void ticket(string username,string firstname[],string lastname[],string sex[],int age[],int no){
		ofstream filewrite;
		filewrite.open("ticket.txt",ios::app);
		for(int i=0;i<no;i++){
			filewrite<<username<<" "<<firstname[i]<<" "<<lastname[i]<<" "<<sex[i]<<" "<<age[i]<<"\n";
		}
		filewrite.close();
	}
};

class inputmodule{
	public:
	string source,destination;
	string username,password;
	void user_input(string userchoice[]){
		system("CLS");
		cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
		cout<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 Enter Your City:";
		cin>>source;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 Enter Your Destination:";
		cin>>destination;
		cout<<"                 *****************************************"<<endl;
		userchoice[0]=source;
		userchoice[1]=destination;
	}
	string login(){
		while(1){
		cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
		cout<<"\n\n\n\n";
		cout<<"                 ENTER                     "<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   1. To Login                  *****"<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   2. To Create New Account     ****"<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"\n                 Enter Your Choice:";
		int ch;
		bool res;
			filehandlingmodule fobj;
			cin>>ch;
			 switch(ch){
				case 1:
					system("CLS");
					cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
					cout<<endl;
					cout<<"                 *****************************************"<<endl;
					cout<<"                 Enter Username:";
					cin>>username;
					cout<<"                 *****************************************"<<endl;
					cout<<"                 Enter Your Password:";
					cin>>password;
					cout<<"                 *****************************************"<<endl;
					res=fobj.log_in(username,password);
					break;
				case 2:
					system("CLS");
					cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
					cout<<endl;
					cout<<"                 *****************************************"<<endl;
					cout<<"                 Enter Username:";
					cin>>username;
					cout<<"                 *****************************************"<<endl;
					cout<<"                 Enter Your Password:";
					cin>>password;
					cout<<"                 *****************************************"<<endl;
					fobj.createaccount(username,password);
					break;
			}
			if(res==true)
				return username;
		}
	}
	int noofpassenger(){
		int no;
		cout<<endl<<"                 Enter the no of passengers:";
		cin>>no;
		return no;
	}
};

class outputmodule{
	public:
	string source,destination;
	void initial(){
		system("CLS");
		cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
		cout<<"\n\n";
		cout<<"                 ***************************"<<endl;
		cout<<"                 *  Facilities Available:  *"<<endl;
		cout<<"                 ***************************"<<endl;
		cout<<"\n\n";
		cout<<"                 ENTER                     "<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   1. To Display List of Cities  ****"<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   2. To Book Ticket             ****"<<endl;
		cout<<"                 *****************************************"<<endl;
	}
	void list_cities(int N){
		datamodule o;
		cout<<endl;
		system("CLS");
		cout<<"\n\n                                             ****************************        Welcome to Travel Management System       **************************"<<endl;
		cout<<"\n\n";
		cout<<"                 The listed cities are:"<<endl;
		cout<<"                 *****************************************"<<endl;
		for(int i=0;i<N;i++){
		cout<<"                 *          "<<o.city[i]<<"            "<<endl;
		cout<<"                 *"<<endl;
		}
		cout<<"                 *****************************************"<<endl;
	}
	
	void ticket(int total_price,int no,string source,string destination,string username){
		system("CLS");
		cout<<"\n\n                                     ****************************       E-TICKET       **************************"<<endl;
		cout<<endl<<"                                     This Ticket is issued for :"<<username<<endl;
		cout<<endl<<"                                     Source:"<<source<<endl;
		cout<<endl<<"                                     Destination:"<<destination<<endl;
		cout<<endl<<"                                     Total No of Passengers:"<<no<<endl;
		cout<<endl<<"                                     Total Cost:"<<total_price<<endl;
		cout<<"\n\n                                     ****************************************************************************"<<endl;
	}
	
	void passengerdetailedticket(int no,string firstname[],string lastname[],string sex[],int age[]){
		for(int i=0;i<no;i++){
			cout<<"                                     Passenger "<<(i+1)<<" Details:"<<endl<<endl;
			cout<<"                                     First Name: "<<firstname[i]<<endl;
			cout<<"                                     Last Name: "<<lastname[i]<<endl;
			cout<<"                                     Sex: "<<sex[i]<<endl;
			cout<<"                                     Age: "<<age[i]<<endl;
			cout<<"\n\n                                     ****************************************************************************"<<endl;
		}
//}
