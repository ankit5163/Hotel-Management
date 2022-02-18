#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>


class hotel
{
  private:
  int room_no;
  int days;
  char name[30];
  char address[50];
  char phone[10];


  public:
  void input(int r);
  void main_menu();
  void bookaroom();
  void checkrecords();
  void roomsalloted();
  void editrecord();
  int checkstatus(int);
  void modifyrecord(int);
  void deleterecord(int);
  void bill(int);

}waiter;

class protect
{ private:
  char password[50];

  public:
  void takepassword();
  void changepassword();
}server;

void protect::takepassword()
{ clrscr();
  char *pass;
  gotoxy(25,12);
  cout<<"Enter The Password: ";
  pass= getpass("");

  fstream h("password.dat",ios::in);

  while(!h.eof())
   { clrscr();
     h.read((char*)&server,sizeof(protect));
     if(strcmp(password,pass)==0)
      { clrscr();
	gotoxy(26,12);
	cout<<"WELCOME!!! DIRECTING YOU TO THE MENU";
	getch();
	waiter.main_menu();
	break;
      }
     else
      { clrscr();
	gotoxy(25,12);
	cout<<"INTRUDER ALERT....!!!!";
	getch();
      }
   }
  h.close();
}



void hotel::main_menu()
{  int choice;
   do
    { clrscr();
      cout<<endl<<'\t'<<'\t'<<'\t'<<"*********************************";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"         * MAIN MENU *";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"*********************************";
      cout<<endl<<endl<<endl<<'\t'<<'\t'<<'\t'<<"1.Book A Room";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"2.Customer Records";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"3.Rooms Allotted";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"4.Edit Record /Generate Bill";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"5.Change Password";
      cout<<endl<<'\t'<<'\t'<<'\t'<<"6.Exit";
      cout<<endl<<endl<<'\t'<<'\t'<<'\t'<<"Enter Your Choice: ";
      cin>>choice;

      switch(choice)
       {  case 1:bookaroom();
	  break;
	  case 2:checkrecords();
	  break;
	  case 3:roomsalloted();
	  break;
	  case 4:editrecord();
	  break;
	  case 5:server.changepassword();
	  break;
	  case 6:
	  break;
	  default:
	   { cout<<endl<<endl<<'\t'<<'\t'<<'\t'<<"Wrong choice.....!!!";
	     gotoxy(38,22);
	     cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
	     cout<<"Press any key to continue....!!";
	     getch();
	   }
       }
    }while(choice!=6);

}

void hotel::input(int r)
   { room_no=r;
     cout<<" Name: ";
     gets(name);
     cout<<" Address: ";
     gets(address);
     cout<<" Phone No: ";
     gets(phone);
     cout<<" No. of days to be stayed: ";
     cin>>days;
   }
int hotel::checkstatus(int r)
{ int pointer=0;
  fstream h("data.dat",ios::in);
  while(!h.eof())
   { h.read((char*)&waiter,sizeof(hotel));
     if(room_no==r)
      {
	pointer=1;
	break;
      }
   }
  h.close();
  return pointer;

}
void hotel::bookaroom()
{ book:
  clrscr();
  int r,pointer;
  char c;

  fstream t("data.dat",ios::app);

  cout<<endl<<"Type of rooms   Room No.  Floor   Price(per day)";
  cout<<endl<<"  Ordinary:     1 - 10     1        2500          ";
  cout<<endl<<"  Ordinary:     10 - 20    2        2500          ";
  cout<<endl<<"  Ordinary:     20 - 30    3        2500          ";
  cout<<endl<<"  Luxuary:      31 - 38    1        4500          ";
  cout<<endl<<"  Luxuary:      39 - 45    2        4500          ";
  cout<<endl<<"  Royal:        46 - 50    3        6500          ";


  cout<<endl<<endl<<endl<<"Enter The Room No. to be booked:- "<<endl;
  cin>>r;

  if(r<1||r>50)
   { cout<<"Sorry...!!! Our Hotel has no such rooms";
     goto end;
   }

  pointer=checkstatus(r);
  if(pointer==1)
   { cout<<endl<<endl<<"Room is not vacant....!!!";
     goto end;
   }

  input(r);
  t.write((char*)&waiter,sizeof(hotel));
  cout<<endl<<endl<<"Room is booked...!!!";


  end:
  t.close();

  cout<<endl<<endl<<"Any More Bookings...(y/n): ";
  cin>>c;
  if(c=='y')
  goto book;

  gotoxy(38,22);
  cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"Press any key to continue.....!!";
  getch();
}


void hotel::checkrecords()
{ clrscr();
  int r,pointer=0;
  fstream h("data.dat",ios::in);

  cout<<endl<<"Enter room no. for customer`s details :- ";
  cin>>r;

  while(!h.eof())
   { clrscr();
     h.read((char*)&waiter,sizeof(hotel));

     if(r==room_no)
      { cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"    Details     ";
	cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"----------------";
	cout<<endl<<endl<<"Room no: "<<room_no;
	cout<<endl<<"Floor no.: ";
	if(room_no>=1&&room_no<=10)
	 { cout<<"1";
	 }
	else if(room_no>=10&&room_no<=20)
	 { cout<<"2";
	 }
	else if(room_no>=20&&room_no<=30)
	 { cout<<"3";
	 }
	else if(room_no>=31&&room_no<=38)
	 { cout<<"1";
	 }
	else if(room_no>=39&&room_no<=45)
	 { cout<<"2";
	 }
	else if(room_no>=46&&room_no<=50)
	 { cout<<"3";
	 }
	cout<<endl<<"Name: ";
	puts(name);
	cout<<"Address: ";
	puts(address);
	cout<<"Phone no: ";
	puts(phone);
	cout<<"Days to be stayed in: "<<days;
	pointer=1;
	break;
      }
   }
  if(pointer==0)
  cout<<endl<<"Sorry..!!!Room is vacant";

  gotoxy(38,22);
  cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"Press any key to continue....!!";

  getch();
  h.close();
}



void hotel::roomsalloted()
{ clrscr();
  char t[10];
  int f;
  fstream h("data.dat",ios::in);
  cout<<endl<<'\t'<<"Enter the type of room  (Ordinary,Luxary,Royal)  :";
  gets(t);

  if(strcmp(t,"Royal")==0||strcmp(t,"royal")==0||strcmp(t,"ROYAL")==0)
   { clrscr();
     cout<<"Room No. : Name : Address : Phone No : Days to be stayed"<<endl<<endl;
     do
      { h.read((char*)&waiter,sizeof(hotel));

	if(room_no>=46&&room_no<=50)
	{ if(h.eof())
	   { break;
	   }
	  cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	}
      }while(!h.eof());
   }

  else if(strcmp(t,"Luxary")==0||strcmp(t,"luxary")==0||strcmp(t,"LUXARY")==0)
   { cout<<"Floor No.:";
     cin>>f;
     clrscr();
     cout<<"Room No. : Name : Address : Phone No : Days to be stayed"<<endl<<endl;
     do
      { h.read((char*)&waiter,sizeof(hotel));
	if(f==1)
	 { if(room_no>=31&&room_no<=38)
	    { if(h.eof())
	       { break;
	       }
	      cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	    }
	 }
	if(f==2)
	 { if(room_no>=39&&room_no<=45)
	    { if(h.eof())
	       { break;
	       }
	     cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	    }
	 }
      }while(!h.eof());
   }
  else if(strcmp(t,"Ordinary")==0||strcmp(t,"ordinary")==0||strcmp(t,"ORDINARY")==0)
   { cout<<"Floor No.:";
     cin>>f;
     clrscr();
     cout<<"Room No. : Name : Address : Phone No : Days to be stayed"<<endl<<endl;
     do
      { h.read((char*)&waiter,sizeof(hotel));
	if(f==1)
	 { if(room_no>=1&&room_no<=10)
	    { if(h.eof())
	       { break;
	       }
	      cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	    }
	 }
	if(f==2)
	 { if(room_no>=11&&room_no<=20)
	    { if(h.eof())
	       { break;
	       }
	      cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	    }
	 }
      if(f==3)
	 { if(room_no>=21&&room_no<=30)
	    { if(h.eof())
	       { break;
	       }
	      cout<<endl<<room_no<<" : "<<name<<" : "<<address<<" : "<<phone<<" : "<<days;
	    }
	 }
      }while(!h.eof());
   }
  else
  { gotoxy(25,12);
    cout<<"We don't have such rooms....!!!!";
  }
  gotoxy(38,22);
  cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"Press any key to continue.....!!";
  getch();
  h.close();
}

void hotel::editrecord()
{ clrscr();
  int choice,r;
  cout<<endl<<'\t'<<'\t'<<"  EDIT MENU";
  cout<<endl<<'\t'<<'\t'<<"-------------";
  cout<<endl<<"1.Modify Customer Record";
  cout<<endl<<"2.Delete Customer Record";
  cout<<endl<<"3. Bill Of Customer";
  cout<<endl<<"Enter your choice: ";
  cin>>choice;

  if(choice!=1&&choice!=2&&choice!=3)
   { cout<<endl<<"Wrong Choice.....!!";
     goto end;
   }

  clrscr();

  cout<<endl<<"Enter room no: " ;
  cin>>r;

  switch(choice)
   { case 1:modifyrecord(r);
     break;
     case 2:deleterecord(r);
     break;
     case 3:bill(r);
     break;
   }

  end:
  gotoxy(38,22);
  cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"Press any key to continue....!!!";
  getch();
}


void hotel::modifyrecord(int r)
{ clrscr();
  long p,pointer=0;
  fstream h("data.dat",ios::in|ios::out|ios::binary);
  while(!h.eof())
   { p=h.tellg();
     h.read((char*)&waiter,sizeof(hotel));
     if(room_no==r)
      { pointer=1;
	if(h.eof())
	 { break;
	 }
	cout<<endl<<'\t'<<'\t'<<"    Old Details";
	cout<<endl<<'\t'<<'\t'<<"---------------------";
	cout<<endl<<"Name: ";
	puts(name);
	cout<<"Address: ";
	puts(address);
	cout<<"Phone no: ";
	puts(phone);
	cout<<"Days to be stayed: "<<days<<endl<<endl;

	cout<<endl<<'\t'<<'\t'<<"  Enter New Details";
	cout<<endl<<'\t'<<'\t'<<"---------------------";
	cout<<endl<<"Name: ";
	gets(name);
	cout<<"Address: ";
	gets(address);
	cout<<"Phone no: ";
	gets(phone);
	cout<<"Days to be stayed: ";
	cin>>days;
	h.seekg(p);
	h.write((char*)&waiter,sizeof(hotel));
	cout<<endl<<"Record is modified....!!";
	break;
      }
   }

  if(pointer==0)
  cout<<endl<<"Sorry Room no. not found or vacant...!!";

  h.close();
}




void hotel::deleterecord(int r)
{ clrscr();
  int pointer=0;
  char ch;
  fstream t("data.dat",ios::in);
  fstream h("change.dat",ios::out);
  while(!t.eof())
   { t.read((char*)&waiter,sizeof(hotel));
     if(t.eof())
      { break;
      }

     if(room_no==r)
      {  pointer=1;
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone No: ";
	 puts(phone);
	 cout<<"Days to be stayed: "<<days;
	 cout<<endl<<endl<<"Do you want to delete this record(y/n): ";
	 cin>>ch;
	 if(ch=='n'||ch=='N')
	 h.write((char*)&waiter,sizeof(hotel));
      }

     else
      {  h.write((char*)&waiter,sizeof(hotel));
      }
   }


  if(pointer==0)
   { cout<<endl<<"Sorry room no. not found or vacant...!!";
   }

  h.close();
  t.close();
  remove("data.dat");
  rename("change.dat","data.dat");
}



void hotel::bill(int r)
{ clrscr();
  int pointer=0;
  fstream t("data.dat",ios::in);
  long long bill;
  while(!t.eof())
  { t.read((char*)&waiter,sizeof(hotel));
    if(t.eof())
    break;
    if(room_no==r)
     { if(room_no>=1&&room_no<=10)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:1 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*25;
	 cout<<"Bill:"<<bill*100;
       }

      else if(room_no>=11&&room_no<=20)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:2 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*25;
	 cout<<"Bill:"<<bill*100;
       }

      else if(room_no>=21&&room_no<=30)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:3 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*25;
	 cout<<"Bill:"<<bill*100;
       }
      else if(room_no>=31&&room_no<=38)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:1 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*45;
	 cout<<"Bill:"<<bill*100;
       }
      else if(room_no>=39&&room_no<=45)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:2 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*45;
	 cout<<"Bill:"<<bill*100;
       }
      else if(room_no>=46&&room_no<=50)
       { cout<<endl<<endl<<"Room no: "<<room_no;
	 cout<<endl<<"Floor no.:3 ";
	 cout<<endl<<"Name: ";
	 puts(name);
	 cout<<"Address: ";
	 puts(address);
	 cout<<"Phone no: ";
	 puts(phone);
	 cout<<"Days to be stayed in: "<<days<<endl;
	 bill=days*65;
	 cout<<"Bill:"<<bill*100;
       }
      cout<<endl<<endl<<"Thanks For Booking Our Room...!!!"<<endl;
      cout<<endl<<'\t'<<"THANKYOU!!!!";
      pointer=1;
      break;
     }
  }

  if(pointer==0)
   { cout<<endl<<"No record found.....!!!";
   }
  getch();
  t.close();
}

void protect::changepassword()
{ clrscr();
  fstream h("password.dat",ios::in);
  char  *ch1,*ch2;
  int pointer=0;
  gotoxy(25,8);
  cout<<"Enter The Old Password: ";
  ch1=getpass("");


  while(!h.eof())
   { h.read((char*)&server,sizeof(protect));

     if(strcmp(password,ch1)==0)
      { pointer=1;
	break;
      }
   }

  h.close();

  if(pointer==0)
   { gotoxy(25,9);
     cout<<"Wrong Password...!!! Try Again!";
   }
  else
   { fstream t("password.dat",ios::out);
     gotoxy(25,10);
     cout<<"New password: ";
     ch2=getpass("");
     gotoxy(25,11);
     cout<<"Password Entered: "<<ch2;
     strcpy(password,ch2);

     t.write((char*)&server,sizeof(protect));
     gotoxy(25,13);
     cout<<"Password changed";
     t.close();
   }

  gotoxy(38,22);
  cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"Press any key to continue....!!!";
  getch();

}


main()
{ textbackground(WHITE);
  textcolor(BLACK);
  clrscr();
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<'\t'<<'\t';
  cout<<"               *****************"<<endl;
  cout<<'\t'<<'\t'<<"     **********                 **********";
  gotoxy(25,10);
  cout<<"WELCOME TO GM GROUPS OF HOTELS";
  cout<<endl<<endl<<'\t'<<'\t';
  cout<<"     **********                 **********"<<endl;
  cout<<'\t'<<'\t'<<"               *****************";
  gotoxy(38,22);
  cout<<"MADE BY AKSHAT GUPTA AND ANKIT MANGLA";
  cout<<endl<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
  cout<<"PRESS ANY KEY TO CONTINUE.........";
  getch();
  clrscr();
  server.takepassword();

}