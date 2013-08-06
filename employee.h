#ifndef EMPLOYEE
#include<iostream>
#include<cstring>
#include<cstdlib> 
#include<fstream>
#include<time.h>
using namespace std;
/*-----------------------------
<<<<<<< HEAD
ÓÉÓÚÔ­°æ±¾ÊÇ°´ÕÕ¿Î³ÌÒªÇóÒ»µãµã¸ü¸ÄµÄ
ÆäÖÐÐí¶àº¯Êý¶¼ÊÇ¶àÓàµÄ£¬Èç¹¹Ôìº¯ÊýµÈµÈ
Òò´ËÔÚÕâ¸ö°æ±¾ÖÐ£¬ÔÚÊµ¼Ê¹ý³ÌÖÐÓÃ²»µ½µÄ¹¹Ôìº¯ÊýÓèÒÔÉ¾³ý
Í¬ÑùµÄ£¬×÷ÎªÓÑÔªµÄÔËËã·ûÖØÔØ£¬ÔÚ³ÌÐòÖÐÒ»´Î¶¼Ã»ÓÃµ½
µ«ÄîÏëµ½µ±³õÇÃÄÇÃ´¶à²»ÈÝÒ×£¬ÒÔºóµÄºóÐø¹¦ÄÜ¼ÓÈë¿ÉÒÔµ÷ÓÃ
±ãÓèÒÔ±£Áô
-----------------------------*/ 
//Éè¶¨±àºÅÆðÊ¼¡¢Ð¡Ê±¹¤×Ê¡¢Ìá³É±ÈÀý¡¢Ã¶¾ÙÐÍ 
char *rout= "data.dat";
int em_sum,em_num;	//Ô±¹¤±àºÅÎªÄê·Ý+ÈýÎ»Èç2013001 
const int hour_pay=260; 		//Éè¶¨Ã¿Ð¡Ê±¹¤×Ê 
const double pay_percent=0.05; 	//Éè¶¨Ìá³É±ÈÀý 
enum type{_manager,_technican,_saleman,_salemanager};
//Éè¶¨´æ´¢µÄ½á¹¹ÌåÄÚÈÝ
=======
ç”±äºŽåŽŸç‰ˆæœ¬æ˜¯æŒ‰ç…§è¯¾ç¨‹è¦æ±‚ä¸€ç‚¹ç‚¹æ›´æ”¹çš„
å…¶ä¸­è®¸å¤šå‡½æ•°éƒ½æ˜¯å¤šä½™çš„ï¼Œå¦‚æž„é€ å‡½æ•°ç­‰ç­‰
å› æ­¤åœ¨è¿™ä¸ªç‰ˆæœ¬ä¸­ï¼Œåœ¨å®žé™…è¿‡ç¨‹ä¸­ç”¨ä¸åˆ°çš„æž„é€ å‡½æ•°äºˆä»¥åˆ é™¤
åŒæ ·çš„ï¼Œä½œä¸ºå‹å…ƒçš„è¿ç®—ç¬¦é‡è½½ï¼Œåœ¨ç¨‹åºä¸­ä¸€æ¬¡éƒ½æ²¡ç”¨åˆ°
ä½†å¿µæƒ³åˆ°å½“åˆæ•²é‚£ä¹ˆå¤šä¸å®¹æ˜“ï¼Œä»¥åŽçš„åŽç»­åŠŸèƒ½åŠ å…¥å¯ä»¥è°ƒç”¨
ä¾¿äºˆä»¥ä¿ç•™
-----------------------------*/ 
//è®¾å®šç¼–å·èµ·å§‹ã€å°æ—¶å·¥èµ„ã€ææˆæ¯”ä¾‹ã€æžšä¸¾åž‹ 
char *rout= "data.dat";
int em_sum,em_num;  //å‘˜å·¥ç¼–å·ä¸ºå¹´ä»½+ä¸‰ä½å¦‚2013001 
const int hour_pay=260; 		//è®¾å®šæ¯å°æ—¶å·¥èµ„ 
const double pay_percent=0.05; 	//è®¾å®šææˆæ¯”ä¾‹ 
enum type{_manager,_technican,_saleman,_salemanager};
//è®¾å®šå­˜å‚¨çš„ç»“æž„ä½“å†…å®¹
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎªÀà¶¨Òå 
class employee	//Ðé»ùÀàÉ¾È¥ÁËÎÞÓÃµÄ¹¹Ôìº¯Êý 
=======
//ä»¥ä¸‹ä¸ºç±»å®šä¹‰ 
class employee	//è™šåŸºç±»åˆ åŽ»äº†æ— ç”¨çš„æž„é€ å‡½æ•° 
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
istream& operator >>(istream& cin,manager & temp)			//ÖØÔØ¸÷ÖÖÊäÈëÊä³ö 
=======
istream& operator >>(istream& cin,manager & temp)			//é‡è½½å„ç§è¾“å…¥è¾“å‡º 
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎªËÑË÷º¯Êý 
=======
//ä»¥ä¸‹ä¸ºæœç´¢å‡½æ•° 
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎªÒÀ¿¿½á¹¹Ìå¹¹½¨Ààº¯Êý
=======
//ä»¥ä¸‹ä¸ºä¾é ç»“æž„ä½“æž„å»ºç±»å‡½æ•°
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎªÉý¼¶º¯Êý
=======
//ä»¥ä¸‹ä¸ºå‡çº§å‡½æ•°
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎªÀàÉú³É½á¹¹ÌåµÄº¯Êý
=======
//ä»¥ä¸‹ä¸ºç±»ç”Ÿæˆç»“æž„ä½“çš„å‡½æ•°
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
<<<<<<< HEAD
//ÒÔÏÂÎª¸ü¸Ä¶ÔÏóÊý¾ÝµÄº¯Êý
=======
//ä»¥ä¸‹ä¸ºæ›´æ”¹å¯¹è±¡æ•°æ®çš„å‡½æ•°
>>>>>>> 03c84e37ba7e1419a3652df2add2fd1947fc8a76
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
