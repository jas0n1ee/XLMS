#ifndef EMPLOYEE
#include<iostream>
#include<cstring>
#include<cstdlib> 
#include<fstream>
#include<time.h>
using namespace std;
/*-----------------------------
由于原版本是按照课程要求一点点更改的
其中许多函数都是多余的，如构造函数等等
因此在这个版本中，在实际过程中用不到的构造函数予以删除
同样的，作为友元的运算符重载，在程序中一次都没用到
但念想到当初敲那么多不容易，以后的后续功能加入可以调用
便予以保留
-----------------------------*/ 
//设定编号起始、小时工资、提成比例、枚举型 
char *rout= "data.dat";
int em_sum,em_num;	//员工编号为年份+三位如2013001 
const int hour_pay=260; 		//设定每小时工资 
const double pay_percent=0.05; 	//设定提成比例 
enum type{_manager,_technican,_saleman,_salemanager};
//设定存储的结构体内容
struct data
{
	enum type _type; 
	char name[24]; 
	int id;
	int grade; 
	float accumPay;
	float work_hour;
	float sale_sum;
};
//以下为类定义 
class employee	//虚基类删去了无用的构造函数 
{
protected:
	char name[10]; 
	int individualEmpNo;
	int grade; 
	double accumPay;
public:
	employee(){} 
	virtual ~employee(){}
	virtual data transport()=0;
	virtual void upgrade() =0;
	friend istream& operator>>(istream&,employee&);
	friend ostream& operator<<(ostream&,employee&);
	virtual bool search(int id)=0;
	virtual bool search(char *name)=0;
	virtual void change_detail(int num)=0;
};
class manager: virtual public employee
{
	public:
		manager():employee(){}
		manager(data p);
		void upgrade();
		bool search(int id);
		bool search(char *name);
		data transport();
		void change_detail(int);
		friend istream& operator>>(istream&,manager&);
		friend ostream& operator<<(ostream&,manager&);
};
class technician : public employee
{
	public:
		technician():employee(){}
		technician(data p);
		void upgrade();
		bool search(int id);
		bool search(char *name);
		data transport();
		void change_detail(int);
		friend istream& operator>>(istream&,technician&);
		friend ostream& operator<<(ostream&,technician&);
	private: 
		int work_hour;
};
class saleman: virtual public employee	
{
	public:
		saleman():employee(){}
		saleman(data p);	
		void upgrade();
		bool search(int id);
		bool search(char *name);
		data transport();
		void change_detail(int);
		friend istream& operator>>(istream&,saleman&);
		friend ostream& operator<<(ostream&,saleman&);
	protected:
		int sale_sum;	
}; 
class salemanager:public saleman,public manager
{
	public: 
		salemanager():manager(),saleman(){}
		salemanager(data p); 
		void upgrade();
		bool search(int id);
		bool search(char *name);
		data transport();
		void change_detail(int);
		friend istream& operator>>(istream&,salemanager&);
		friend ostream& operator<<(ostream&,salemanager&);
}; 
bool check_name(char* name)
{
	fstream check(rout,ios::binary|ios::in);
	data temp;
	bool flag=0;
	for(int i=0;i<em_sum;i++)
	{
		check.read((char*)&temp,sizeof(data));
		if(strcmp(name,temp.name)==0) flag=1;
	}
	check.close();
	return flag;
}
bool check_name(char* name,int num)
{
	fstream check(rout,ios::binary|ios::in);
	data temp;
	bool flag=0;
	for(int i=0;i<em_sum;i++)
	{
		check.read((char*)&temp,sizeof(data));
		if(strcmp(name,temp.name)==0&&i!=num) flag=1;
	}
	check.close();
	return flag;
}
istream& operator >>(istream& cin,employee & temp)		
{
	cout<<"Please input Grade:";
	cin>>temp.grade;
	cout<<"Please input Payment:";
	cin>>temp.accumPay;
	return cin;
}
ostream& operator <<(ostream& cout,employee & temp)
{
	cout<<temp.individualEmpNo<<endl<<temp.grade<<endl<<temp.accumPay<<endl<<endl;		//id,grade,accumpay 
	return cout;
}
istream& operator >>(istream& cin,manager & temp)			//重载各种输入输出 
{
	cout<<"Please input Grade:";
	cin>>temp.grade;
	return cin;
}
ostream& operator <<(ostream& cout,manager & temp)
{
	cout<<"NO:"<<temp.individualEmpNo<<endl<<"Grade"<<temp.grade<<endl<<"Payment:"<<temp.accumPay<<endl<<endl;
	return cout;
}
istream& operator >>(istream& cin,technician & temp)
{
	cout<<"Please input Grade:";
	cin>>temp.grade;
	cout<<"Please input Work Hours:";
	cin>>temp.work_hour;
	return cin;
}
ostream& operator <<(ostream& cout,technician & temp)
{
	cout<<"NO:"<<temp.individualEmpNo<<endl<<"Grade"<<temp.grade<<endl<<"Payment:"<<temp.accumPay<<endl<<endl;
	return cout;
}
istream& operator >>(istream& cin,saleman & temp)
{
	cout<<"Please input Grade:";
	cin>>temp.grade;
	cout<<"Please input Saleroom:";
	cin>>temp.sale_sum;
	return cin;
}
ostream& operator <<(ostream& cout,saleman & temp)
{
	cout<<"NO:"<<temp.individualEmpNo<<endl<<"Grade"<<temp.grade<<endl<<"Payment:"<<temp.accumPay<<endl<<endl;
	return cout;
}
istream& operator >>(istream& cin,salemanager & temp)
{
	cout<<"Please input Grade:";
	cin>>temp.grade;
	cout<<"Please input Saleroom:";
	cin>>temp.sale_sum;
	return cin;
}
ostream& operator <<(ostream& cout,salemanager & temp)
{
	cout<<"NO:"<<temp.individualEmpNo<<endl<<"Grade"<<temp.grade<<endl<<"Payment:"<<temp.accumPay<<endl<<endl;
	return cout;
}
//-------------------
//以下为搜索函数 
bool manager::search(int id)
{
	if (individualEmpNo==id) 
	{
		cout<<"MANAGER\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<id<<endl
			<<"Grade:"<<grade<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool manager::search(char *name)
{
	if (strcmp(this->name,name)==0) 
	{
		cout<<"MANAGER\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<individualEmpNo<<endl
			<<"Grade:"<<grade<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool technician::search(int id)
{
	if (individualEmpNo==id) 
	{
		cout<<"TECHNICIAN\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<id<<endl
			<<"Grade:"<<grade<<endl
			<<"Workhour:"<<work_hour<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool technician::search(char *name)
{
	if (strcmp(this->name,name)==0) 
	{
		cout<<"TECHNICIAN\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<individualEmpNo<<endl
			<<"Grade:"<<grade<<endl
			<<"Workhour:"<<work_hour<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool saleman::search(int id)
{
	if (individualEmpNo==id) 
	{
		cout<<"SALEMAN\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<id<<endl
			<<"Grade:"<<grade<<endl
			<<"Salesum"<<sale_sum<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool saleman::search(char *name)
{
	if (strcmp(this->name,name)==0) 
	{
		cout<<"SALEMAN\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<individualEmpNo<<endl
			<<"Grade:"<<grade<<endl
			<<"Salesum:"<<sale_sum<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool salemanager::search(int id)
{
	if (individualEmpNo==id) 
	{
		cout<<"SALEMANAGER\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<id<<endl
			<<"Grade:"<<grade<<endl
			<<"Salesum"<<sale_sum<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
bool salemanager::search(char *name)
{
	if (strcmp(this->name,name)==0) 
	{
		cout<<"SALEMANAGER\n"
			<<"Name:"<<name<<endl 
			<<"ID:"<<individualEmpNo<<endl
			<<"Grade:"<<grade<<endl
			<<"Salesum:"<<sale_sum<<endl
			<<"Payment:"<<accumPay<<endl; 
		return 1;
	}
	else return 0;
}
//------------
//以下为依靠结构体构建类函数
manager::manager(data p)
{
	strcpy(name,p.name);
	individualEmpNo=p.id;
	grade=p.grade;
	accumPay=p.accumPay; 
	if(p.id>em_sum) em_num=p.id;
}
technician::technician(data p)
{
	strcpy(name,p.name);
	individualEmpNo=p.id;
	grade=p.grade;
	work_hour=p.work_hour;
	accumPay=p.accumPay; 
	if(p.id>em_sum) em_num=p.id;
}
saleman::saleman(data p)
{
	strcpy(name,p.name);
	individualEmpNo=p.id;
	grade=p.grade;
	sale_sum=p.sale_sum;
	accumPay=p.accumPay; 
	if(p.id>em_sum) em_num=p.id;
}
salemanager::salemanager(data p)
{
	strcpy(name,p.name);
	individualEmpNo=p.id;
	grade=p.grade;
	sale_sum=p.sale_sum;
	accumPay=p.accumPay; 
	if(p.id>em_sum) em_num=p.id;
}
//--------------
//以下为升级函数
void manager::upgrade()
{
	grade++;
	accumPay++;
	accumPay=accumPay*1.1;
} 
void technician::upgrade()
{
	grade++;
	accumPay*=1.2;
} 
void saleman::upgrade()
{
	grade++;
	accumPay*=1.2;
}
void salemanager::upgrade()
{
	grade++;
	accumPay=1.1*(accumPay-sale_sum*pay_percent)+sale_sum*pay_percent*1.2;
} 
//--------------------
//以下为类生成结构体的函数
data manager::transport()
{
	data temp;
	temp._type=(type)0;
	temp.accumPay=accumPay;
	temp.grade=grade;
	temp.id=individualEmpNo;
	temp.sale_sum=0;
	temp.work_hour=0;
	strcpy(temp.name,name);
	return temp;
}
data technician::transport()
{
	data temp;
	temp._type=(type)1;
	temp.accumPay=accumPay;
	temp.grade=grade;
	temp.id=individualEmpNo;
	temp.sale_sum=0;
	temp.work_hour=work_hour;
	strcpy(temp.name,name);
	return temp;
}
data saleman::transport()
{
	data temp;
	temp._type=(type)2;
	temp.accumPay=accumPay;
	temp.grade=grade;
	temp.id=individualEmpNo;
	temp.sale_sum=sale_sum;
	temp.work_hour=0;
	strcpy(temp.name,name);
	return temp;
}
data salemanager::transport()
{
	data temp;
	temp._type=(type)3;
	temp.accumPay=accumPay;
	temp.grade=grade;
	temp.id=individualEmpNo;
	temp.sale_sum=sale_sum;
	temp.work_hour=0;
	strcpy(temp.name,name);
	return temp;
}
//----------------
//以下为更改对象数据的函数
void manager::change_detail(int num)
{
	char temp[24];
	cout<<"Input New Name:" ;
	cin>>temp;
	if(!check_name(temp,num))strcpy(name,temp);
	else
		cout<<"Name exits! You need to retype a new name\nLike: \n\tif Jason exist\n\ttry Jason(1)";
}
void technician::change_detail(int num)
{
	char temp[24];
	cout<<"Input New Name:" ;
	cin>>temp;
	if(!check_name(temp,num))
	{
		strcpy(name,temp);
		cout<<"Input New Workhour:" ;
		cin>>work_hour;
		accumPay=work_hour*hour_pay;
	}
	else
		cout<<"Name exits! You need to retype a new name\nLike: \n\tif Jason exist\n\ttry Jason(1)";

}
void saleman::change_detail(int num)
{
	char temp[24];
	cout<<"Input New Name:" ;
	cin>>temp;
	if(!check_name(temp,num))
	{
		strcpy(name,temp);
		cout<<"Input New Salesum:" ;
		cin>>sale_sum;
		accumPay=sale_sum*pay_percent;
	}
	else
		cout<<"Name exits! You need to retype a new name\nLike: \n\tif Jason exist\n\ttry Jason(1)";

}
void salemanager::change_detail(int num)
{
	char temp[24];
	cout<<"Input New Name:" ;
	cin>>temp;
	if(!check_name(temp,num))
	{
		strcpy(name,temp);
		cout<<"Input New Salesum:" ;
		cin>>sale_sum;
		accumPay=8000+sale_sum*pay_percent*0.8;
	}
	else
		cout<<"Name exits! You need to retype a new name\nLike: \n\tif Jason exist\n\ttry Jason(1)";

}

#define EMPLOYEE
#endif