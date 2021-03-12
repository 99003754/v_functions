#include<iostream>
using namespace std;

class accbase{
std::string accno;
std::string accname;
 double m_balance;

public:

accbase(std::string no,std::string name,double balance):accno(no),accname(name),m_balance(balance)
{

}

accbase(const accbase &copy)
{
accno=copy.accno;
accname=copy.accname;
m_balance=copy.m_balance;
}

virtual void debit(double remove)=0;

virtual void credit(double add)=0;
//virtual void display() const=0;

double getBalance() const
{
return m_balance;
}
};

class savings:public accbase{
public:
double s_balance;
savings();
savings(std::string s_no,std::string s_name,double s_balance):accbase(s_no,s_name,s_balance)
{
}
void debit(double remove)
{
m_balance-=remove;
}

void credit(double add)
{
m_balance+=add;
}





};

class curr:public accbase{
public:
double s_balance;
curr();
curr(std::string c_no,std::string c_name,double c_balance):accbase(c_no,c_name,c_balance)
{
}
void debit(double remove)
{
m_balance-=remove;
}

void credit(double add)
{
m_balance+=add;
}





};



int main()
{
savings obj("123","acd",5000);
obj.debit(500);
double x=obj.getBalance();
cout<<x<<endl;
accbase* ptr;
curr obj2("123","acd",50000);
ptr=&obj2;
ptr->debit(1000);
x=ptr->getBalance();
cout<<x<<endl;
return 0;

}
