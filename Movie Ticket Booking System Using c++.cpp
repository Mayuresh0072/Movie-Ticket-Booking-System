#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>


// USERNAME -  admin
// PASSWORD =  pass



class movie
{


public:
char name[30];
char time1[20];
char time2[20];
char time3[20];
char time4[20];
int screen1;
int screen2;
char price[4];
int id;
int cost;
int rm;

movie()																	//CONSTRUCTOR
{

strcpy(name,"N/A");
strcpy(time1,"N/A");
strcpy(time2,"N/A");
strcpy(time3,"N/A");
strcpy(time4,"N/A");
screen1=0;
screen2=0;
id=0;
cost=0;
rm=0;

}




~movie()																//DESTRUCTOR															
{
cout<<"\n\n\t\t******Data Released From Memory******";
}

void operator %(int n)													//OPERATOR OVERLOADING
{
	cout<<"\n\t\t\t  # - B I L L - #";
	cout<<"\n\t\t Ticket             : "<<n<<"x"<<cost<<" = "<<n*cost;
	cout<<"\n\t\t Service Tax ( 5 %) : "<< n*cost*0.05 ;
	cout<<"\n\t\t G.S.T ( 9 %)       : "<< n*cost*0.09 ;
	cout<<"\n\t\t TOTAL              : "<< n*cost+ n*cost*0.05+n*cost*0.09 ; 
	
}

virtual void modify(int id=0)										//	VIRTUAL POLYMORPHISM(dynamic binding)
{ char a,t[1];
	cout<<"\nID         : "<<id;
	cout<<"\n\t\tModify name ?(y/n)";cin>>a;
	if(a=='y' || a=='Y')
	{

			cout<<"\nEnter \nMovie Name : ";cin>>name;
	}
	cout<<"\n\t\tModify Screens/time ?(y/n)";cin>>a;
		if(a=='y' || a=='Y')
	{
							cout<<"\nAvailable at Screen no 1 (y/n): ";
				cin>>t;
				if(strcmp(t,"y")==0 || strcmp(t,"Y")==0 )
				{
				screen1=1;
				cout<<"\t\t\t Time 1   : ";cin>>time1;
				cout<<"\t\t\t Time 2   : ";cin>>time2;
				}
				else{
					strcpy(time1,"N/A");
					strcpy(time2,"N/A");

					screen1=0;
				}
				
				cout<<"\nAvailable at Screen no 2 (y/n): ";
				cin>>t;
				if(strcmp(t,"y")==0 || strcmp(t,"Y")==0 )
				{
				screen2=1;
				cout<<"\t\t\t Time 1   : ";cin>>time3;
				cout<<"\t\t\t Time 2   : ";cin>>time4;
				}
								else{
					strcpy(time3,"N/A");
					strcpy(time4,"N/A");

					screen2=0;
				}
	}
		cout<<"\n\t\tModify Ticket Price ?(y/n)";cin>>a;
	if(a=='y' || a=='Y')
		{
			cout<<"\n\t\tEnter price : ";cin>>cost;
		}
		cout<<"Movie details modified successfully ";

}
int del()
{int t=0;

		strcpy(name,"N/A");
		strcpy(time1,"N/A");
		strcpy(time2,"N/A");
		strcpy(time3,"N/A");
		strcpy(time4,"N/A");
		screen1=0;
		screen2=0;
		rm=1;
		cost=0;
		t=1;
		cout<<"\n\t\t\tMovie deleted Successfully ... ";
	return t;
}


}mov[10];


class customer
{

    public:
    char cname[20];
    char mobile[13];
    char email[30];
    int cid;
    int rm;
   customer()
   {
   	strcpy(cname,"N/A");
   	strcpy(mobile,"N/A");
   	strcpy(email,"N/A");
   	rm=0;
   }
   
   int del()
{
   	strcpy(cname,"N/A");
   	strcpy(mobile,"N/A");
   	strcpy(email,"N/A");
   	rm=1;
	cout<<"\n\t\t\tCustomer record deleted Successfully ... ";
	return rm;
}
   

}cus[101];


class master:public movie,public customer{				//   INHERITANCE
	private:
		char user[20],pass[20];
	public:
	int n1,n2;
	struct bookings
	{
		int movid;
		int scr;
		int tm;
		int cusid;
		int mid;
		int no;
		int seat;
	}book[101];
	friend int login();                                 //-   FRIEND FUNCTION

	friend class MAIN;									//-    FRIEND CLASS
	master()
	{	int j;
		n1=0;
		n2=0;
		for(j=1;j<101;j++)
		{
			book[j].movid=0;
			book[j].cusid=0;
			book[j].scr=0;
			book[j].tm=0;
			book[j].no=0;
			book[j].mid=0;
			book[j].seat=0;
		}
	}
	int vacant()
	{int i;
		for (i=1;i<101;i++)
		{
			if(book[i].no==0)
			{
				break;
			}
		}
		return i;
		
	}
	int getcusid()
	{int i;
	for(i=1;i<101;i++)
		{
			if (cus[i].cid==0 && cus[i].rm==0)
			{

				break;
			}
		}				return i;

	}
	int getmovid()
	{int i;
	for(i=1;i<10;i++)
		{
			if (mov[i].id==0 || mov[i].rm==1)
			{

				break;
			}

		}				return i;
		
	}


	void addm()
			{ char t[4],p;
			int tmp=0;
			ifstream file; 
			file.open("mov.dat", ios::out); 
			file.read((char*)&mov, sizeof(mov)); 
			while (!file.eof()) { 
			p=getmovid();
			mov[p].id=p;
			mov[p].rm=0;

			cout<<"\n\t\tID         : "<<mov[p].id;break;}
			file.close();
			cout<<"\n\t\tEnter \n\t\tMovie Name : ";cin>>mov[p].name;
			cout<<"\n\t\tAvailable at Screen no 1 (y/n): ";
			cin>>t;
			if(strcmp(t,"y")==0 || strcmp(t,"Y")==0 )
			{
			mov[p].screen1=1;
			cout<<"\t\t\t Time 1   : ";cin>>mov[p].time1;
			cout<<"\t\t\t Time 2   : ";cin>>mov[p].time2;
			}
			
			cout<<"\n\t\tAvailable at Screen no 2 (y/n): ";
			cin>>t;
			if(strcmp(t,"y")==0 || strcmp(t,"Y")==0 )
			{
			mov[p].screen2=1;
			cout<<"\t\t\t Time 1   : ";cin>>mov[p].time3;
			cout<<"\t\t\t Time 2   : ";cin>>mov[p].time4;
			}
			
			while(tmp==0)
			{
			try{
			cout<<"\n\t\tTicket cost : ";cin>>mov[p].cost;								// EXCEPTION HANDLING
			
			if (mov[p].cost<=0)
			throw 1;
			else
			tmp=1;
			}
			catch(...)
			{
				cout<<"\n\t\t\tINVALID COST ENTERED \n\t\tEnter valid cost";
				cout<<"\n\t\t\tTicket cost : ";cin>>mov[p].cost;
			}
			
			}
			ofstream file2;
			file2.open("mov.dat");
			file2.write((char*)&mov, sizeof(mov));	

			

}

int showm()
				{	int p=1,tmp=0;
			ifstream file; 
			file.open("mov.dat", ios::out); 
			file.read((char*)&mov, sizeof(mov)); 
			while (!file.eof()) { 
				while(mov[p].id!=0){
				if(mov[p].rm==0)	{
					tmp=1;
				cout<<"\n\n\t\tID = "<<mov[p].id;					
				cout<<"\n\t\tName= "<<mov[p].name;

				if(mov[p].screen1==1)
				{cout<<"\n\t\tAvailable at screen :"; 
				cout<<"1";
				cout<<"\t\t\tTime 1 : "<<mov[p].time1;
				cout<<"\t\t\tTime 2 : "<<mov[p].time2;
				}				
				if(mov[p].screen2==1)
				{cout<<"\n\t\tAvailable at screen :"; 
				cout<<"2";
				cout<<"\t\t\tTime 1 : "<<mov[p].time3;
				cout<<"\t\t\tTime 2 : "<<mov[p].time4;
				}
				cout<<"\n\t\tTotal Fare Amount : "<<mov[p].cost;
				cout<<"\n\t  ---------------------------------------------------------------------------------------------";

				}				p++;

				}if(mov[p].id!=0);

					break;
				}
				if(tmp==0)
				cout<<"\n\t\t\t--No Movie Available--";
				return tmp; 
				}
		int mov_avl()
		{	int p=1,tmp=0;
		while(mov[p].id!=0){
		if(mov[p].id!=0)
		tmp=1;
		p++;}
		return tmp;
				}

    void add()
    {int i,j,k,tmp4=1,tmp5=1,t1,t2,t3,v,p,nt=0,time=1;

    cout<<"\n\t\t\tEnter the no of tickets to book : ";cin>>nt;
    cout<<"\n\t\tEnter the details to book a ticket";
    cout<<"\n\t\t\tEnter Movie ID     : ";cin>>t1;


		cout<<"\n\t\t\tEnter Screen (1/2) : ";cin>>t2;
		cout<<"\n\t\t\tEnter time   (1/2) : ";cin>>t3;
	    			ifstream file; 
	file.open("cus.dat", ios::out); 
	file.read((char*)&cus, sizeof(cus)); 
	while (!file.eof()) { 	
    for(i=0;i<nt;i++)
    {
    p=getcusid();

  //  v=vacant();
    //if(v!=1)
    //v--;
    cout<<"\n\t\tEnter details below :- \n\t\t\tBooking no : "<<p<<"\n\t\t\tName : ";
    cin>>cus[p].cname;
    cout<<"\t\t\tMobile no :";
    cin>>cus[p].mobile;
    cout<<"\t\t\tEmail id :";
    cin>>cus[p].email;
    cus[p].cid=p;

		
	//if((t2==1 || t2==2) && (t3==1 || t3==2 ) )
//	{		

			if(time==1)
			book[p].mid=p;
			else
			book[p].mid=book[p-1].mid;
			
			book[p].movid=t1;
			book[p].scr=t2;
			book[p].tm=t3;
			book[p].cusid=p;
			book[p].no=p;
			if(book[p].scr==1)
			{
				book[p].seat=100+book[p].no;
			}
			else
				book[p].seat=200+book[p].no;
			
			time++;
	//	}	

}break;
}
			ofstream file2;
			file2.open("cus.dat");
			file2.write((char*)&cus, sizeof(cus));	
}
    void disp()
			    { int t=1,tmp=0,t2=0;
				ifstream file;
				file.open("cus.dat", ios::out); 
				file.read((char*)&cus, sizeof(cus)); 
				while (!file.eof()) { 
			    while(cus[t].cid!=0){
			    	if(cus[t].rm!=1){
			    	tmp=1;
			    cout<<"\n\n\t\tID     : "<<cus[t].cid;
			    cout<<"\n\t\tName   : "<<cus[t].cname;
			    cout<<"\n\t\tMobile : "<<cus[t].mobile;
			    cout<<"\n\t\tEmail  : "<<cus[t].email;
			    cout<<"\n\n\t\t\t --&& Booking details &&--";
				t2=getbook(cus[t].cid);			    
			    cout<<"\n\t\tMID            : "<<book[t2].mid;
			    cout<<"\n\t\tMovie          : "<<mov[book[t2].movid].name;
			    cout<<"\n\t\tShow Screen    : "<<book[t2].scr;
			    cout<<"\n\t\tShow time      : ";		if(book[t2].tm==1 && book[t2].scr==1) 
															cout<<mov[book[t2].movid].time1;
															else	if(book[t2].tm==2 && book[t2].scr==1) 
															cout<<mov[book[t2].movid].time2;
															else	if(book[t2].tm==1 && book[t2].scr==2) 
															cout<<mov[book[t2].movid].time3;

															else
															cout<<mov[book[t2].movid].time4;
				cout<<"\n\t\tSeat No        : "<<book[t2].seat;
				cout<<"\n\t  ---------------------------------------------------------------------------------------------";
														
				 } t++; }break;}
				if(tmp==0)
			cout<<"\n\t\t\t--No Booked Ticked Available--";

}

int searchcus(int z)
    { int t=1,tmp=0,t2=0;
	ifstream file;
	file.open("cus.dat", ios::out); 
	file.read((char*)&cus, sizeof(cus)); 
	while (!file.eof()) { 
    while(cus[t].cid!=0){
    if(z==cus[t].cid && cus[t].rm!=1)
	{cout<<"\n\t\t\t Record Found - ";
    	tmp=1;
			    cout<<"\n\t\tID     : "<<cus[t].cid;
			    cout<<"\n\t\tName   : "<<cus[t].cname;
			    cout<<"\n\t\tMobile : "<<cus[t].mobile;
			    cout<<"\n\t\tEmail  : "<<cus[t].email;
			    cout<<"\n\t\t-------------------------------------------------------";
			    cout<<"\n\t\t ## Booking details ##";
				t2=getbook(cus[t].cid);			    
			    cout<<"\n\n\t\tMID            : "<<book[t2].mid;
			    cout<<"\n\n\t\tMovie          : "<<mov[book[t2].movid].name;
			    cout<<"\n\n\t\tShow Screen    : "<<book[t2].scr;
			    cout<<"\n\n\t\tShow time      : ";		if(book[t2].tm==1 && book[t2].scr==1) 
															cout<<mov[book[t2].movid].time1;
															else	if(book[t2].tm==2 && book[t2].scr==1) 
															cout<<mov[book[t2].movid].time2;
															else	if(book[t2].tm==1 && book[t2].scr==2) 
															cout<<mov[book[t2].movid].time3;

															else
															cout<<mov[book[t2].movid].time4;
				cout<<"\n\t\tSeat No        : "<<book[t2].seat;
    cout<<"\n\t\t-------------------------------------------------------";
	break;
 }
 
		t++;		}break;}
	if(tmp==0)
cout<<"\n\t\t\t--No Customer Found--";
return tmp;

}
void searchmov()															//FUNCTION OVERLOADING
{	int i=1,tmp=0;
	char search1[20];
		ifstream file; 
	file.open("mov.dat", ios::out); 
	file.read((char*)&mov, sizeof(mov)); 
	cout<<"\n\n\t\tEnter Movie name to search : ";
	cin>>search1;
	while(mov[i].id!=0)
	{
		if(strcmp(search1,mov[i].name)==0 && mov[i].rm!=1)
		{	tmp=1;
			cout<<"\n\n\t\t\tMovie Found... ";
				cout<<"\n\t\tName= "<<mov[i].name;
				cout<<"\n\t\tAvailable at screen :";
				if(mov[i].screen1==1)
				{ cout<<"1";
				cout<<"\t\t\tTime 1 : "<<mov[i].time1;
				cout<<"\t\t\tTime 2 : "<<mov[i].time2;
				}
				cout<<"\n\t\tAvailable at screen :";
				if(mov[i].screen2==1)
				{ cout<<"2";
				cout<<"\t\t\tTime 1 : "<<mov[i].time3;
				cout<<"\t\t\tTime 2 : "<<mov[i].time4;
				}
			}
			i++;	
	}
	if(tmp==0)
	cout<<"\n\t\t\t--Movie not found--";
	
	
}
int searchmov(int z)															// FUNCTION OVERLOADING
{	int i=1,tmp=0;
	ifstream file; 
	file.open("mov.dat", ios::out); 
	file.read((char*)&mov, sizeof(mov)); 
	while(mov[i].id!=0)
	{
		if(z==mov[i].id && mov[i].rm==0)
		{	tmp=1;
			cout<<"\n\n\t\t\tMovie Found...";
				cout<<"\n\t\tName= "<<mov[i].name;
				cout<<"\n\t\tAvailable at screen :";
				if(mov[i].screen1==1)
				{ cout<<"1";
				cout<<"\t\t\tTime 1 : "<<mov[i].time1;
				cout<<"\t\t\tTime 2 : "<<mov[i].time2;
				}
				cout<<"\n\t\tAvailable at screen :";
				if(mov[i].screen2==1)
				{ cout<<"2";
				cout<<"\t\t\tTime 1 : "<<mov[i].time3;
				cout<<"\t\t\tTime 2 : "<<mov[i].time4;
				}
			}
			i++;	
	}
	if(tmp==0)
	cout<<"\n\t\t\t--Movie not found--";
	return tmp;
	
}
void ticket(int m)
{	int t1=0,t2=0,i=1,j,temp=0,tmid;
		ifstream file;
	file.open("cus.dat", ios::out); 
	file.read((char*)&cus, sizeof(cus)); 
	while(book[i].no!=0)
	{
		if(book[i].cusid==m)
		{
			temp=1;
			tmid=book[i].mid;
			break;	
		}i++;
	}

	j=1;
	while(book[j].no!=0)
	{
		if(book[j].mid==tmid)
		{
			t1=book[j].no;
			
			break;
		}
		j++;
	}
		while(book[j].no!=0)
	{
		if(book[j].mid==tmid)
		{
			t2=book[j].no;
		}
		else
		break;
		j++;
	}
	cout<<" \n";
	if(temp==1)
	{
	cout<<"\n\t  ---------------------------------------------";
	cout<<"\n\t\t\t E-TICKET \n\t\t(i n c l u d i n g   b i l l)";
	cout<<"\n\t\t\tName      : "<<cus[book[t1].cusid].cname;
	cout<<"\n\t\t\tMobile no : "<<cus[book[t1].cusid].mobile;
	cout<<"\n\t\t\tEmail 	  : "<<cus[book[t1].cusid].email;
	cout<<"\n\t\t\t # BOOKING DETAILS # ";
	cout<<"\n\t\tMovie name : "<<mov[book[t1].movid].name;
	cout<<"\n\t\tScreen     : "<<book[t1].scr;
	cout<<"\n\t\tShow Timing: ";
		if(book[t1].tm==1 && book[t1].scr==1) 
	cout<<mov[book[t1].movid].time1;
	else	if(book[t1].tm==2 && book[t1].scr==1) 
	cout<<mov[book[t1].movid].time2;
	else	if(book[t1].tm==1 && book[t1].scr==2) 
	cout<<mov[book[t1].movid].time3;
	//	if(book[t1].tm==2 && book[t1].scr==2) 
	else
	cout<<mov[book[t1].movid].time4;
	cout<<"\n\t\tSeats : ";
	
	for(i=t1;i<=t2;i++)
	{
		/* if(book[t1].scr==1)
		cout<<"\t\t\t A-"<<i;
		else
		cout<<"\n\t\t\t B-"<<i; */
		if(book[i].scr==1)
		cout<<"\n\t\t\tA-"<<book[i].seat;
		else
		cout<<"\n\t\t\tB-"<<book[i].seat;
		
	}
	mov[book[t1].movid]%(t2);	//operator overloading
	cout<<"\n\t  ---------------------------------------------";				
		}
	else cout<<"\n\t\t\t\t ID not available ";
}
int getbook(int k)
{int i=1;
	ifstream file; 
	file.open("mov.dat", ios::out); 
	file.read((char*)&mov, sizeof(mov)); 
	while (!file.eof()) { 
	while(book[i].no!=0){
	if(book[i].cusid==k){
	return book[i].no;break;}
	i++;
}break;}
return 0;
}
void delbook(int t){
		ifstream file;
	file.open("cus.dat", ios::out); 
	file.read((char*)&cus, sizeof(cus)); 
	book[t].cusid=0;
	book[t].movid=0;
	book[t].scr=0;
	book[t].mid=0;
	book[t].seat=0;
	book[t].tm=0;
	cout<<"\n\t\t\t Deleted Successfully";
		ofstream file2;
	file2.open("cus.dat");
	file2.write((char*)&cus, sizeof(cus));	
	
}


template <class T> 												//FUNCTION TEMPLATE
int remove(T x[],int i) 
{ int y;
	cout<<"\n\t\t\tDeleting....";
	ifstream file; 
	file.open("mov.dat", ios::out); 
	file.read((char*)&mov, sizeof(mov)); 
	ifstream file2;
	file2.open("cus.dat", ios::out); 
	file2.read((char*)&cus, sizeof(cus)); 
	y=x[i].del();
	ofstream file3;
	file3.open("cus.dat");
	file3.write((char*)&cus, sizeof(cus));	
	

	return y;
}


void modify(int id=0)
{ char a;
		ifstream file;
	file.open("cus.dat", ios::out); 
	file.read((char*)&cus, sizeof(cus)); 
	cout<<"\n\t\tBooking no : "<<id;
		cout<<"\n\t\tModify name ?(y/n)";cin>>a;
		{
			if(a=='y' || a=='Y'){
			cout<<"\n\t\tEnter new name : ";
			cin>>cus[book[id].cusid].cname;}
		}
			cout<<"\n\t\tModify Mobile no ?(y/n)";cin>>a;
		{
			if(a=='y' || a=='Y'){
			cout<<"\n\t\tEnter new Mobile no : ";	
			cin>>cus[book[id].cusid].mobile;}
		}
			cout<<"\n\t\tModify Email ?(y/n)";cin>>a;
		{
			if(a=='y' || a=='Y'){
			cout<<"\n\t\tEnter new Email : ";
			cin>>cus[book[id].cusid].email;}
		}
		cout<<"Customer details modified successfully ";
	
				fstream file3;
				file3.open("cus.dat");
				file3.write((char*)&cus, sizeof(cus));
	
 } 
void print1(int i)
	{if(i==-1)cout<<"V";
	 else cout<<"B";
	}
void dispseat(int m1=1,int m2=1,int m3=1)
			    { int t=1,tmp=0,t2=0,count=0;
				ifstream file;
				file.open("cus.dat", ios::out); 
				file.read((char*)&cus, sizeof(cus)); 
				while (!file.eof()) { 
				int k1=1,k2=1,i,tmp1[102];
				    for(i=1;i<102;i++){

    if(book[i].cusid!=0 && book[i].movid==m3 && book[i].scr==m2 && book[i].tm==m1){
    	tmp1[i]=(book[i].seat-m1*100);count++;
    }
    else
				    tmp1[i]=-1;
					}cout<<"\n\n\n";

					
				cout<<"\n\n\t\t\t\t    # MOVIE #\n\t\tName : "<<mov[m3].name;
				cout<<"\t\tScreen : "<<m1;
				cout<<"\t\tTime    : ";	
								if(m2==1 && m1==1) 
								cout<<mov[m3].time1;
								else	if(m2==2 && m1==1) 
								cout<<mov[m3].time2;
								else	if(m2==1 && m1==2) 
								cout<<mov[m3].time3;
								else
								cout<<mov[m3].time4;
i=1;
cout<<"\n\n\n";
cout<<"----------------------------------------<-{--SCREEN (this way)--}->----------------------------------------"<<"\n\n";


cout<<"\t[";print1(tmp1[1]);cout<<"]"<<"\t\t\t\t\t\t\t\t\t\t\t"<<"  [";print1(tmp1[2]);cout<<"]\n";
i=3;
for(k1=1;k1<=5;k1++)
{cout<<" "<<k1<<"\t";
for(k2=1;k2<=10;k2++){
   if((k1==1 && (k2==5) )||( (k1==1) && (k2==6) ))
  { cout<<" "<<" "<<"        ";i++;}
   else{

   cout<<"[";print1(tmp1[i]);cout<<"]       ";i++;
	}
   }
cout<<"\n"	;
		
}
cout<<"\t";for(int j=1;j<11;j++){ cout<<" "<<j<<"        ";i++;}cout<<"\n";
cout<<"-----------------------------------------------------------------------------------------------------------";
cout<<"\n";			 
cout<<"\n\n\t\tTotal seats Booked : "<<count<<"/50";
cout<<"\n\t\tVacant seats : "<<50-count;	 
break;}


}




}mas;

class MAIN														//FRIEND CLASS
{
	public:
			void edit(int b){
						int id;
					if(b==1)
							{
					movie *p;
					cout<<"\n\t\t--Available Movies -- ";
					mas.showm();
					cout<<"\n\t\tEnter Movie ID : ";cin>>id;		
					p=&mov[id];												//VIRTUAL POLYMORPHISM(dynamic binding)
					if(mas.searchmov(id)!=0){
					p->modify(id);
					return;
					}		}
					else
					cout<<"\n\t\tEnter Booking No : ";cin>>id;
					master *p;
					p=&mas;
					if(mas.searchcus(id)!=0){
						mas.modify(mas.getbook(id));
						return;
					}
						
							
				}	
	void menu()
{ int ch1=0,ch2=0,p,m1=1,m2=1,i,sid,nt,tid,k1,k2,k3;
	do{
		
		cout<<"\n\n\t\t+++--Movie Ticket Booking--+++\n\n\t\t\t--Main Menu--\n\n\t1.Admin Menu \n\t2.Booking Menu\n\t3.Log out\n\t\t\tEnter your choice : ";    
		cin>>ch2;system("CLS");
		switch (ch2)
		{
	case 1:
			do{
              cout<<"\n\n\t\t\t#-Admin Menu-# \n\n\t1.Add New Movie \n\t2.Show Movies List\n\t3.Search Movie (By Name) \n\t4.Search Movie (By ID) \n\t5.Delete Movie \n\t6.Modify Movie \n\t7.Display Booked/Vacant Seats\n\t8.Back\n\t\t\tEnter your choice : ";
              cin>>ch1;
              system("CLS");
              switch (ch1)
              {
              case 1:system("CLS");cout<<"\n\t##--Add movie--##";
              mas.addm(); 
              break;
              case 2:system("CLS");cout<<"\n\t##--Movies Available--##";
              mas.showm();
              break;
              case 3:system("CLS");cout<<"\n\t##--Search Movie (By Name)--##";
              mas.searchmov();
  			  break;
  			  case 4:system("CLS");cout<<"\n\t##--Search Movie (By ID)--##";
  			  cout<<"\n\tEnter ID to search : ";
  			  cin>>sid;
  			  mas.searchmov(sid);
  			  break;
  			  case 5:system("CLS");cout<<"\n\t##--Delete Movie--##";
  			  cout<<"\n\t\tEnter Movie ID to Delete : ";cin>>sid;
  			  if(mas.searchmov(sid)==1){
  			  mas.remove(mov,sid);
				ofstream file2;
				file2.open("mov.dat");
				file2.write((char*)&mov, sizeof(mov));	}

  			  break;
  			  case 6:system("CLS");cout<<"\n\t##--Modify Movie--##";
  			  edit(1);
  			  if(true){	ofstream file2;
			file2.open("mov.dat");
			file2.write((char*)&mov, sizeof(mov));}
  			  break;
  			  case 7:system("CLS");cout<<"\n\t##--Show Booked Seats--##";
  			   cout<<"\n\t\tEnter\n\t\tMovie ID : ";cin>>k3;
  			   cout<<"\n\t\tScreen : ";cin>>k1;
  			  	if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 
				mas.dispseat(k1,1,k3);
				mas.dispseat(k1,2,k3);
				break;}
              }
				
				break;
  			  case 8:system("CLS");break;
  			  default:cout<<"\n\tINVALID INPUT\n";
  			}
			}while(ch1!=8);
			break;
	case 2:
			do{
              cout<<"\n\n\t\t#-Booking Menu-#\n\n\t1.Book Ticket \n\t2.View all tickets \n\t3.Generate E-ticket \n\t4.Delete\n\t5.Modify\n\t6.Search\n\t7.Back\n\t\t\tEnter your choice : ";
              cin>>ch1;system("CLS");
              switch (ch1)
              {
 
              case 1:system("CLS");cout<<"\n\t##--Book Ticket--##";
                cout<<"\n\t---------# Available Movies #--------- \n";
                
              if(mas.showm()==1)
              {
	            ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				while (!file.eof()) { 
				mas.add();break;}
				ofstream file2;
				file2.open("mov.dat");
				file2.write((char*)&mas, sizeof(mas));
			  }
			  
              break;
              case 2:system("CLS");cout<<"\n\t##--All Booked Ticket--##";
	           if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 
				mas.disp();break;}
              }
  			  break;
			  case 3:system("CLS");cout<<"\n\t##--Generate E-ticket--##";
			  if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 
			  cout<<"\n\tEnter Customer ID :";cin>>tid;
			  mas.ticket(tid);break;}
              }
			  

  			  break;
			  case 4:system("CLS");cout<<"\n\t##--Delete--##";
			  			  if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 
			  cout<<"\n\tEnter Customer ID to delete :";cin>>tid;
			  if(mas.searchcus(tid)==1)
			  {
			  	if(mas.remove(cus,tid)!=0)
			  	mas.delbook(mas.getbook(tid));
			  }break;}
			  	ofstream file3;
				file3.open("mov.dat");
				file3.write((char*)&mas, sizeof(mas));
              }

			  break;

			  case 5:system("CLS");cout<<"\n\t##--Modify--##";
 				if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 

			  edit(2);break;}
			  	ofstream file3;
				file3.open("mov.dat");
				file3.write((char*)&mas, sizeof(mas));
			  }
			  break;
			  case 6:system("CLS");cout<<"\n\t##--Search--##";
 				if(true){
			   ifstream file; 
				file.open("mov.dat", ios::out); 
				file.read((char*)&mas, sizeof(mas)); 
				ifstream file2; 
				file2.open("mov.dat", ios::out); 
				file2.read((char*)&mov, sizeof(mov)); 
				while (!file.eof()) { 
			  cout<<"\n\t\tEnter ID to search : ";cin>>tid;
			  mas.searchcus(tid);break;}}break;
			  case 7:system("CLS");break;
  				default:cout<<"\n\tINVALID INPUT\n";break;
  			}
			}while(ch1!=7);
			break;
		}
	}while(ch2!=3);
}
}M;
	
	
	int login(){	int i;char ch;												//FRIEND FUNCTION
    cout<<"\nEnter Username : ";
    cin>>mas.user;
    cout<<"\nEnter Password : ";
     string s(mas.user,true);
    ch = getch();
   while(ch != 13){
      s.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<s;
    if((strcmp(mas.user,"admin")==0)&&(s=="apass"))
    {
        return 1;
    }
    else
    {

        return -1;

    }
}

 
 
main()
{int ch0=0,x;
 system("color E1");
cout<<"\n\t\t-----Login Screen-----\n\n1.Login\n2.Exit\n\t\tEnter your choice : ";
cin>>ch0;

  do{
     switch (ch0)
     {

         case 1:x=login();
         if(x==1)
          {	
          	system("CLS");
          	system("color B2");
              cout<<"\t\t---Login Successfull---";

              M.menu();
              
}
             
        else
        cout<<"\t\t---Invalid username or password :(---";

         break;
         case 2:
         break;
         default:cout<<"\n\tINVALID INPUT";
         break;
         
         
     }
     cout<<"\n1.Login Again\n2.Exit\n\tEnter your choice : ";
cin>>ch0;
  }while(ch0!=2);
  
}


