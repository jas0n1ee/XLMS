#include"employee.h"
void init()
{
	time_t t;
	t=time(NULL);
	em_num=1000*(t/31104000+1969);
	fstream infile(rout,ios::in|ios::out|ios::binary|ios::ate);
	em_sum=infile.tellg()/sizeof(data);
	infile.seekp((em_sum-1)*sizeof(data),ios::beg);	//寻找最大编号
	data temp;
	infile.read((char *)&temp,sizeof(data));
	if(temp.id>em_num) em_num=temp.id;
	infile.close();
}

void addinfo()
{
	system("cls");
	int ch;
	data temp; 
	cout<<"Please choose the type of the employee.\n1.Manager\n2.Technician\n3.Saleman\n4.Salemanager.\n";
	cin>>ch;
	temp._type=(type)(ch-1);				//设定种类 
	switch(ch)
	{
		case 1:					//输入manager类 
			temp.accumPay=12000; //系统设定
			temp.id=++em_num;
			cout<<"Input Name:" ;
			cin>>temp.name;
			temp.grade=1;
			break;
		case 2:
			temp.id=++em_num;
			cout<<"Input Name:" ;
			cin>>temp.name;
			temp.grade=1;
			cout<<"Input Workhour:";
			cin>>temp.work_hour;
			temp.accumPay=temp.work_hour*hour_pay;
			break;
		case 3:
			temp.id=++em_num;
			cout<<"Input Name:" ;
			cin>>temp.name;
			temp.grade=1;
			cout<<"Input Salesum:";
			cin>>temp.sale_sum;
			temp.accumPay=temp.sale_sum*pay_percent;
			break;
		case 4:
			temp.id=++em_num;
			cout<<"Input Name:" ;
			cin>>temp.name;
			temp.grade=1;
			cout<<"Input Salesum:";
			cin>>temp.sale_sum;
			temp.accumPay=8000+temp.sale_sum*pay_percent*0.8;
			break;
		default:
			cout<<"Wrong input! Try again.\n";
			getchar();getchar();		//提供停顿的老办法 
			addinfo();return;					//递归重新输入 
	}
	for(int i=0;i<em_sum;i++)
	{
		
	}
	if(check_name(temp.name))
	{
		cout<<"Name exits! You need to retype a new name\nLike: \n\tif Jason exist\n\ttry Jason(1)";
		getchar();getchar();
		addinfo();
		return;
	}
	ofstream outfile;
	outfile.open(rout,ios::binary|ios::out|ios::app);
	outfile.write((char *)&temp,sizeof(data)); 
	outfile.close();
	em_sum++;
}
void readwrite()
{
	system("cls");		//清个屏
	int wrong_int;
	int count=0;
	int flag=-1;
	data temp;			//建立临时读取结构体
	employee **temp_em = new employee*[em_sum];		//为全体员工创建数组
	fstream infile(rout,ios::in|ios::out|ios::binary);
	if(!infile) 
	{
		throw wrong_int;
		return;
	}	

	infile.seekg(ios::beg);
	//下面读入了文件中的所有数据
	for(int i=0;i<em_sum;i++)
	{
		infile.read ((char*)&temp,sizeof(data));
		switch(temp._type)
		{
			case 0:
				temp_em[i]=new manager(temp);
				break;
			case 1:
				temp_em[i]=new technician(temp);
				break;
			case 2:
				temp_em[i]=new saleman(temp);
				break;
			case 3:
				temp_em[i]=new salemanager(temp);
				break;
		}
		cout<<i+1<<" item(s) read"<<endl;
	}
	infile.close(); 
	//下面开始搜索
	cout<<"**********************\nSearch for\n1.Name\n2.ID\n";
	cin>>wrong_int;
	switch(wrong_int)
	{
	case 1:
		system("cls");
		cout<<"Name:\n";
		cin>>temp.name;
		system("cls");
		for(int i=0;i<em_sum;i++) count+=(1+i)*temp_em[i]->search(temp.name);
		break;
	case 2:
		system("cls");
		cout<<"ID:\n";
		cin>>temp.id;
		system("cls");
		for(int i=0;i<em_sum;i++) count+=(i+1)*temp_em[i]->search(temp.id);
		break;
	default: 
		system("cls");
		cout<<"Wrong Input\n";
		break;
	}
	if (count==0) cout<<"No Match Item\n";
	else
	{
		count--;
		cout<<"\nWhat do you want to do on this Employee?\n1.Change Detail\n2.Delete Employee\n3.Upgrade\n4.Nothing\n";
		cin>>wrong_int;
		switch(wrong_int)
		{
			case 1:
				temp_em[count]->change_detail(count);
				break;
			case 2:
				flag=count;
				break;
			case 3:
				temp_em[count]->upgrade();
				break;
			case 4:
				break;
			default:
				cout<<"Wrong Input\n";
				getchar();getchar();
		}
		fstream change(rout,ios::out|ios::trunc|ios::beg|ios::binary);
		for(int i=0;i<em_sum;i++) {if(i!=flag) change.write((char *)&temp_em[i]->transport(),sizeof(data));} 
		change.close();
		init();
	}
	for(int i=0;i<em_sum;i++) delete temp_em[i];
	delete [] temp_em;
	getchar();
} 
void printscreen()
{
	int chose_temp;
	system("cls");
	cout<<"     :BBBBBBBBBBBBBBBBBBBB.  .,i:L7LZBBBB.       1B1        \n     iBO.,:,:::,:,:,:::.BB:  BBBBBBBMXJvr  ,Bv   YBL        \n     :B0.,,:::::,,,:::,.OB.       7B       iBF   YBL        \n     :BBMBM0GOBBBBBBB8GPMB        FB,   .  ,BJ   vB7        \n     :Br BBk;.  ,B.   :uBB. FBBBBBBBBBBBBB ,Bj   YBL        \n     :Br  .;NB. rB: rBG7,        rBB       ,BY   LB7        \n     iBF ,i7kBBUiB.iBBBPYri     .BBBiL     :BJ   LBL        \n     vBXBBNGL    8.   :70BBi   ,BjvBUBBU   ,BY   vB7        \n     8B   .B1    BP           iBB YB  FBB7 :Bu   LBv        \n     BB  NBBBBBBBBBBBBBBBB   XBB  kB   .B: iBS   vB7        \n    ,Bk BB       Bu         rB0   SB       .N:   vBv        \n    BB 8BBBBBBBBBBBBBBBBBBBj :    NB.            rBL        \n   2BM ::::iii::iBB,:iiii;;,      8B.       .GYLjBBr        \n   ;B            B0               kB.        BBBBBY     \n";
	cout<<"\n\t犀利人事管理系统\n\t1、数据录入\n\t2、数据查询\n\t3、退出\n"; 
	cin>>chose_temp;
	try
	{ 
		switch(chose_temp)
		{
			case 1:
				addinfo(); 
				printscreen(); 
				break;
			case 2:
				readwrite(); 
				printscreen(); 
				break;
			case 3:
				return;
				break;
			default: break;
		}
	}
	catch(int)
	{
		cout<<"File does not exist!"<<endl;
		getchar(); getchar();
		printscreen();
	} 
}
int main()					
{
	init();
	printscreen(); 
	system("cls"); 
	cout<<"BYEBYE"<<endl;
	return 0;
}