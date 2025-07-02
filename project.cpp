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
    }
}