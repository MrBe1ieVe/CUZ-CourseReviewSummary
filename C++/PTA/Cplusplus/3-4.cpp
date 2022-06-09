#include <iostream>
using namespace std;
class Product{
public:
	void set_value();  
	void total();   
	static void ave_count();   
	static void display(); 
private:
	double price;
	int num;   
	int quantity;
	static double discount;
	static int total_num;
	static double sum;
	static double average;
};

double Product::discount=0.95;
int Product::total_num=0;
double Product::sum=0;
double Product::average=0;
 
 
void Product::set_value(){
	cin>>num>>quantity>>price;
}
void Product::total(){
	total_num+=quantity;  
	if(quantity>10)
		sum+=quantity*price*0.98*discount;
	else
		sum+=quantity*price*discount;
}
void Product::ave_count(){
	average=sum/total_num;
}
void Product::display(){
	cout<<sum<<endl;
	cout<<average<<endl;
}
int main(){
	const int t=3;
	Product p[t];
	for(int i=0;i<t;i++){
		p[i].set_value();
        p[i].total();
	}
	Product::ave_count();
	Product::display();
	return 0;	
}