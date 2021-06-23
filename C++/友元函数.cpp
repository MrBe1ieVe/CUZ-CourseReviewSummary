#include<iostream>
using namespace std;
class car;
class boat{
	private:
	double weight;
	public:
	boat(double w){weight=w;};
	friend double totalweight(boat w1,car w2);
}; 
class car{
	
	private:
	double weight;	
	public:
	car(double w){weight=w;};
	friend double totalweight(boat w1,car w2);
};
double totalweight(boat w1,car w2){return w1.weight+w2.weight;}
int main() 

{

  car c1(1000); 

 boat b1(2000); 

 cout<<totalweight(b1,c1)<<endl;

}
