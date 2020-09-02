
//                            COMPUTER SCIENCE PROJECT
//                             CLASS XII-G  2016-2017

//				    DEVELOPED BY:
//			    ANISHA SRIVASTAVA, ROLL NO.3
//                             ANUSHA DAS, ROLL NO.4

//                             TOPIC: STUDENT DATABASE



#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>


void Mainmenu();
void Exit();
void secA();
void secB();
void secC();
void secD();
void modify();
void searchname();
void searchrange();
void sortname();
void sortmarks();
void deletion();


class stud
{
	char name[30];
	int S1,S2,S3,S4,S5;
	char SS1[20],SS2[20], SS3[20],SS4[20],SS5[20];

public:

	void datain();
	void dataout(int Y);
	void grade(int avg);
	void modify1();
	float retavg(){
			float Savg=(S1+S2+S3+S4+S5)/5;
			return Savg;
		      }

	char* getname(){
			return name;
		       }


};

void stud::grade(int avg)
{
  if(avg>85)
	cprintf("A");

  else if (avg>70 && avg<=85)
	cprintf("B");

  else if (avg>55 && avg<=75)
	cprintf("C");

  else if(avg>40 && avg<=55)
	cprintf("D");

  else
	cprintf("F");
}


const char VL=179,HL=196,TL=218,TR=191,BL=192,BR=217;
const char DVL=186,DHL=205,DTL=201,DTR=187,DBL=200,DBR=188;
int N;



void color(int TC,int BC)//For Changing Text Color and Text Background
{
	textcolor(TC);
	textbackground(BC);
}



void showxy(int X,int Y,char CH)//Displays a character at X,Y position
{
	gotoxy(X,Y);
	cprintf("%c",CH);  //cout<<CH;
}


void showxy(int X,int Y,char CH[])//Displays a string at X,Y position
{
	gotoxy(X,Y);
	cprintf("%s",CH);  //cout<<CH;
}




void Vline(int X,int Y,int L)//To vertical line by joining vert. characters
{
	for (int i=Y;i<=Y+L;i++)
		showxy(X,i,VL);
}



void Hline(int X,int Y,int L)//To horizontal line by joining hor.characters
{
	for (int i=X;i<=X+L;i++)
		showxy(i,Y,HL);
}

void DVline(int X,int Y,int L)
{
	for (int i=Y;i<=Y+L;i++)
		showxy(X,i,DVL);
}


void DHline(int X,int Y,int L)
{
	for (int i=X;i<=X+L;i++)
		showxy(i,Y,DHL);
}


void Recta(int C1,int R1,int C2,int R2)
{
	showxy(C1,R1,TL);             //
	showxy(C1,R2,BL);             //Placing corner characters
	showxy(C2,R1,TR);             //
	showxy(C2,R2,BR);             //
	Vline(C1,R1+1,R2-R1-2);       //
	Vline(C2,R1+1,R2-R1-2);       //Joining Corners by Vertical lines
	Hline(C1+1,R1,C2-C1-2);       //
	Hline(C1+1,R2,C2-C1-2);       //Joining Corners by Horizontal lines
}

void DRecta(int C1,int R1,int C2,int R2)
{
	showxy(C1,R1,DTL);
	showxy(C1,R2,DBL);
	showxy(C2,R1,DTR);
	showxy(C2,R2,DBR);
	DVline(C1,R1+1,R2-R1-2);
	DVline(C2,R1+1,R2-R1-2);
	DHline(C1+1,R1,C2-C1-2);
	DHline(C1+1,R2,C2-C1-2);
}


int Vmenu(int X,int Y,char Mnu[][80],int Noc)   // to create vertical menu
{
	DRecta(X,Y,X+strlen(Mnu[0])+11,Y+Noc+1);
	color(57,BLACK);
	for (int i=0;i<Noc;i++)
		showxy(X+1,Y+i+1,Mnu[i]);

	int Sel=0,Exit=0;//Sel - Current Selected Option
									 //Exit- Control Variable for loop
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		color(WHITE,57);

		showxy(X+1,Y+Sel+1,Mnu[Sel]);
		color(57,BLACK);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 72:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 80:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1; //Enter Key
			 break;
		 case 27:Sel=-1; //Escape
			 Exit=1;
			 break;
		}
		showxy(X+1,Y+Tsel+1,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}




int Hmenu(int X,int Y,char Mnu[][200],int Noc)       // to create horizontal menu
{

	color(RED,BLACK);
	for (int i=0;i<Noc;i++)
		showxy(X+15*i+1,Y,Mnu[i]);
	int Sel=0,Exit=0;
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		color(WHITE,RED);
		showxy(X+15*Sel+1,Y,Mnu[Sel]);
		color(RED,BLACK);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 75:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 77:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1;
			 break;
		 case 27:Sel=-1;
			 Exit=1;
			 break;
		}
		showxy(X+15*Tsel+1,Y,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}


// Initial Welcome Screen is displayed here...

void intro()
{
	clrscr();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	textcolor(BLUE);


 cprintf("                   ≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤");cout<<endl;
 cprintf("                   ≤≤€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€          €€€        €€€€€      €€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€ €€€ €€€€€€ €€€ €€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€ €€€ €€€€€€ €€€ €€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€€ €€ €€€€€ €€€€€ €€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€");
 textcolor(YELLOW+BLINK);
 textbackground(LIGHTBLUE);
 cprintf(" S T U D E N T   D A T A B A S E" );
 textbackground(DARKGRAY);
 textcolor(BLUE);
 cprintf("€€≤≤");  cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€€ €€      €€€€€€€      €€≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€€ €€  €€€€€€€€€€€€€€€€€ €≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€ €€€  €€€€€€€€€€€€€€€€€ €≤≤");cout<<endl;
 cprintf("                   ≤≤€€  €€€€€€€ €€€  €€€€€€€€€€€€€€€€ €€≤≤");cout<<endl;
 cprintf("                   ≤≤€          €€€    €€€€€€€€€      €€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€≤≤");cout<<endl;
 cprintf("                   ≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤");cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;

	textcolor(CYAN);
	delay(200);
	for(int i=0; i<=80; i++)
	{
		cprintf("≤");
		delay(20);

	}
}



int checkname(char word[])                 // to check if input is alphabet
{        int n=0,a,f;
	 a=strlen(word);
	 for (int i=0;i<a;i++)
	 { if(isdigit(word[i]))
	 n++;

	 }

	 return (n);
}


int checkno(char number[])               // to check if input is digit
{        int n=0,a;
	 a=strlen(number);
	 for (int i=0;i<a;i++)
	 {	if(!isdigit(number[i]))
		 n++;

	 }

	 return (n);
}


void transfer()           //transfer data from one file to another
{
	fstream fil1,fil2;

	if(N==0)
		remove("STUDENT1.DAT");
	else if (N==1)
		remove("STUDENT2.DAT");
	else if (N==2)
		remove("STUDENT3.DAT");
	else if (N==3)
		remove("STUDENT4.DAT");
	else
		return;

	if(N==0)
		fil2.open("STUDENT1.DAT",ios::binary|ios::app);
	else if (N==1)
		fil2.open("STUDENT2.DAT",ios::binary|ios::app);
	else if (N==2)
		fil2.open("STUDENT3.DAT",ios::binary|ios::app);
	else if (N==3)
		fil2.open("STUDENT4.DAT",ios::binary|ios::app);
	else
		return;

	fil1.open("TEMP.DAT",ios::binary|ios::in);
	stud A;
	while(fil1.read((char*)&A,sizeof(A))) {
		fil2.write((char*)&A,sizeof(A));
	}
	fil2.flush ();
	fil1.close();
	fil2.close();
}


void table()                //to create a table for input
{
	color(YELLOW,BLACK);
	Hline(9,13,64);
	Vline(20,11,6);
	Vline(30,11,6);
	Vline(42,11,6);
	Vline(55,11,6);

 }

void stud::datain()	   // function to take input of details
{
	textcolor(57);
	itoa(S1,SS1,10);
	itoa(S2,SS2,10);
	itoa(S3,SS3,10);
	itoa(S4,SS4,10);
	itoa(S5,SS5,10);
	if(N==0)
	{
		 color(CYAN, BLACK);



		do
		{ gotoxy(30,8);
		cprintf("Name :                      ");
		gotoxy(38,8);
		gets(name);
		}while(checkname(name)!=0);


		table();
		do
		{ gotoxy(12,12);
		  cprintf("English");
		  gotoxy(15,15);
		  gets(SS1);
		}while(checkno(SS1)!=0);
		 S1=atoi(SS1);

		 do
		{ gotoxy(22,12);
		  cprintf("History");
		  gotoxy(24,15);
		  gets(SS2);
		}while(checkno(SS2)!=0);
		 S2=atoi(SS2);

		 do
		{
		  gotoxy(32,12);
		  cprintf("Sociology");
		  gotoxy(35,15);
		  gets(SS3);
		}while(checkno(SS3)!=0);
		 S3=atoi(SS3);

		 do
		{ gotoxy(44,12);
		  cprintf("Geography");
		  gotoxy(48,15);
		  gets(SS4);
		}while(checkno(SS4)!=0);
		 S4=atoi(SS4);

		 do
		{
		  gotoxy(57,12);
		  cprintf("Political Sc.");
		  gotoxy(64,15);
		  gets(SS5);
		}while(checkno(SS5)!=0);
		 S5=atoi(SS5);
	}

	else if(N==1)
	{

		do
		{gotoxy(30,8);
		 cprintf("Name :                      ");
		 gotoxy(38,8);
		 gets(name);
		 }while(checkname(name)!=0);
		table();

		do
		{
		  gotoxy(12,12);
		  cprintf("English");
		  gotoxy(15,15);
		  gets(SS1);
		}while(checkno(SS1)!=0);
		 S1=atoi(SS1);

		 do
		{
		  gotoxy(22,12);
		  cprintf("Physics");
		  gotoxy(24,15);
		  gets(SS2);
		}while(checkno(SS2)!=0);
		 S2=atoi(SS2);

		 do
		{ gotoxy(32,12);
		  cprintf("Chemistry");
		  gotoxy(35,15);
		  gets(SS3);
		}while(checkno(SS3)!=0);
		 S3=atoi(SS3);

		 do
		{
		  gotoxy(44,12);
		  cprintf("Biology");
		  gotoxy(48,15);
		  gets(SS4);
		}while(checkno(SS4)!=0);
		 S4=atoi(SS4);

		 do
		{
		  gotoxy(57,12);
		  cprintf("Maths");
		  gotoxy(64,15);
		  gets(SS5);
		}while(checkno(SS5)!=0);
		 S5=atoi(SS5);
	}

	else if(N==2)
	{
		 color(CYAN, BLACK);


		do
		{
		  gotoxy(30,8);
		  cprintf("Name :                      ");
		  gotoxy(38,8);
		   gets(name);
		 }while(checkname(name)!=0);
		   table();

		do
		{
		  gotoxy(12,12);
		  cprintf("English");
		  gotoxy(15,15);
		  gets(SS1);
		}while(checkno(SS1)!=0);
		 S1=atoi(SS1);

		 do
		{
		  gotoxy(22,12);
		  cprintf("Accounts");
		  gotoxy(24,15);
		  gets(SS2);
		}while(checkno(SS2)!=0);
		 S2=atoi(SS2);

		 do
		{
		  gotoxy(32,12);
		  cprintf("Maths");
		  gotoxy(35,15);
		  gets(SS3);
		}while(checkno(SS3)!=0);
		 S3=atoi(SS3);

		 do
		{
		  gotoxy(44,12);
		  cprintf("Economics");
		  gotoxy(48,15);
		  gets(SS4);
		}while(checkno(SS4)!=0);
		 S4=atoi(SS4);

		 do
		{
		  gotoxy(57,12);
		  cprintf("Business St.");
		  gotoxy(64,15);
		  gets(SS5);
		}while(checkno(SS5)!=0);
		 S5=atoi(SS5);
	}
	else if(N==3)
	{
		 color(CYAN, BLACK);




		do
		{
		  gotoxy(30,8);
		  cprintf("Name :                      ");
		  gotoxy(38,8);
		  gets(name);
		 }while(checkname(name)!=0);
		   table();

		do
		{ gotoxy(12,12);
		  cprintf("English");
		  gotoxy(15,15);
		  gets(SS1);
		}while(checkno(SS1)!=0);
		 S1=atoi(SS1);

		 do
		{
		  gotoxy(22,12);
		  cprintf("Physics");gotoxy(24,15);
		  gets(SS2);
		}while(checkno(SS2)!=0);
		 S2=atoi(SS2);

		 do
		{
		  gotoxy(32,12);
		  cprintf("Chemistry");
		  gotoxy(35,15);
		  gets(SS3);
		}while(checkno(SS3)!=0);
		 S3=atoi(SS3);

		 do
		{
		  gotoxy(44,12);
		  cprintf("Comp. Sc.");
		  gotoxy(48,15);
		  gets(SS4);
		}while(checkno(SS4)!=0);
		 S4=atoi(SS4);

		 do
		{
		  gotoxy(57,12);
		  cprintf("Mathematics");
		  gotoxy(64,15);
		  gets(SS5);
		}while(checkno(SS5)!=0);
		 S5=atoi(SS5);
	}
}


void stud::dataout(int Y)       //to display the entered values
{ color(WHITE,BLACK);

   itoa(S1,SS1,10);
   itoa(S2,SS2,10);
   itoa(S3,SS3,10);
   itoa(S4,SS4,10);
   itoa(S5,SS5,10);
     gotoxy(15,10+Y);
     cprintf(name);
	gotoxy(35,10+Y);
	cprintf(SS1);
		gotoxy(40,10+Y);
		cprintf(SS2);
			gotoxy(45,10+Y);
			cprintf(SS3);
		gotoxy(50,10+Y);
		cprintf(SS4);
	gotoxy(55,10+Y);
	cprintf(SS5);
     gotoxy(60,10+Y);
     cout<<retavg()<<"%"<<endl;
     gotoxy(67,10+Y);
     grade(retavg());

     }


void create(){                           //for creating records
	clrscr();
	char choice[][200]={ "  YES  ",
				"  NO  "
				};
	int ch;
	fstream filA;

	if(N==0)
		filA.open("STUDENT1.DAT",ios::binary|ios::app);
	else if (N==1)
		filA.open("STUDENT2.DAT",ios::binary|ios::app);
	else if (N==2)
		filA.open("STUDENT3.DAT",ios::binary|ios::app);
	else if (N==3)
		filA.open("STUDENT4.DAT",ios::binary|ios::app);
	else
		return;

	do {
	gotoxy(1,3);
		color(YELLOW+BLINK,BLUE);

		for (int i=1;i<=80;i++)
			cprintf(" ");

		gotoxy(35,3);
		cprintf("NEW RECORD");
			stud A;
				color(CYAN,BLACK);
				A.datain();
				filA.write((char*)&A, sizeof(A));
				filA.flush();
				filA.close();
			gotoxy(15,23);
		color(WHITE,BLACK);
		cprintf("CONTINUE?");

		ch = Hmenu(27,23,choice,2);

		switch(ch)
		{
			case 0:create(); break;
			case 1:{
				if(N==0)
				secA();
				else if(N==1)
				secB();
				else if(N==2)
				secC();
				else if(N==3)
				secD();
				ch=2;
				}
		}

	}while(ch!=2);
}


void display()                             //for displaying records
{
	clrscr();

	color(WHITE,BLACK);

	Hline(13,9,56);
	Vline(33,7,17);
	Vline(38,7,17);
	Vline(43,7,17);
	Vline(48,7,17);
	Vline(53,7,17);
	Vline(58,7,17);
	Vline(65,7,17);
	Recta(13,7,70,25);
	fstream filA;

	if(N==0)
		filA.open("STUDENT1.DAT",ios::binary|ios::in);
	else if (N==1)
		filA.open("STUDENT2.DAT",ios::binary|ios::in);
	else if (N==2)
		filA.open("STUDENT3.DAT",ios::binary|ios::in);
	else if (N==3)
		filA.open("STUDENT4.DAT",ios::binary|ios::in);
	else
		return;

	if(N==0)
	{
	gotoxy(1,3);
	color(MAGENTA+BLINK,BLUE);

	for (int i=1;i<=80;i++)
		cprintf(" ");

		gotoxy(32,3);
		cprintf("CLASS XII-A RECORDS");

			color(WHITE,BLACK);
			gotoxy(20,8);
			cprintf("NAME");
			gotoxy(34,8);
			cprintf("ENG");
			gotoxy(39,8);
			cprintf("HIS");
			gotoxy(44,8);
			cprintf("SOC");
			gotoxy(49,8);
			cprintf("GEO");
			gotoxy(54,8);
			cprintf("POL");
			gotoxy(60,8);
			cprintf("%age");
			gotoxy(66,8);
			cprintf("GRD");

	}


	else if (N==1)
	{
	gotoxy(1,3);
	color(GREEN+BLINK,BLUE);
	for (int i=1;i<=80;i++)
		cprintf(" ");

	gotoxy(32,3);
	cprintf("CLASS XII-B RECORDS");
	color(WHITE,BLACK);
			gotoxy(20,8);
			cprintf("NAME");
			gotoxy(34,8);
			cprintf("ENG");
			gotoxy(39,8);
			cprintf("PHY");
			gotoxy(44,8);
			cprintf("CHE");
			gotoxy(49,8);
			cprintf("BIO");
			gotoxy(54,8);
			cprintf("MAT");
			gotoxy(60,8);
			cprintf("%age");
			gotoxy(66,8);
			cprintf("GRD");

	}


	else if (N==2)
	{
	gotoxy(1,3);
	color(YELLOW+BLINK,BLUE);
	for (int i=1;i<=80;i++)
		cprintf(" ");
	gotoxy(32,3);
	cprintf("CLASS XII-C RECORDS");
	color(WHITE,BLACK);
			gotoxy(20,8);
			cprintf("NAME");
			gotoxy(34,8);
			cprintf("ENG");
			gotoxy(39,8);
			cprintf("ACC");
			gotoxy(44,8);
			cprintf("MAT");
			gotoxy(49,8);
			cprintf("ECO");
			gotoxy(54,8);
			cprintf("B.ST");
			gotoxy(60,8);
			cprintf("%age");
			gotoxy(66,8);
			cprintf("GRD");

	}

	else if (N==3)
	{
	gotoxy(1,3);
	color(CYAN+BLINK,BLUE);
	for (int i=1;i<=80;i++)
		cprintf(" ");
	gotoxy(32,3);
	cprintf("CLASS XII-D RECORDS");
	color(WHITE,BLACK);
			gotoxy(20,8);
			cprintf("NAME");
			gotoxy(34,8);
			cprintf("ENG");
			gotoxy(39,8);
			cprintf("PHY");
			gotoxy(44,8);
			cprintf("CHE");
			gotoxy(49,8);
			cprintf("C.SC");
			gotoxy(54,8);
			cprintf("MAT");
			gotoxy(60,8);
			cprintf("%age");
			gotoxy(66,8);
			cprintf("GRD");
	}

	stud A; int Y=0;
	while(filA.read((char*)&A,sizeof(A)))
	{       gotoxy(10,10+Y);
	cout<<Y+1<<".";
		A.dataout(Y);
		Y++;
	 }

	filA.close();
	getch();

	if(N==0)
		secA();
	else if(N==1)
		secB();
	else if(N==2)
		secC();
	else if(N==3)
		secD();

}


void Edit()
{
	char EMenu[][200] = {	" *CREATE " ,
				" *DELETE " ,
				" *MODIFY " ,
			    };
	int Ch;

	Ch = Hmenu(21,20,EMenu,3);

	switch(Ch)
	{
		case 0:	create(); break;
		case 1:	deletion(); break;
		case 2:	modify();
	}

	if((Ch!=0)||(Ch!=1)||(Ch!=2))
	 {
		clrscr();

		if(N==0)
			secA();
		else if(N==1)
			secB();
		else if(N==2)
			secC();
		else if(N==3)
			secD();
	}

color(WHITE,BLACK);
}

void Sort()
 {

  char SoMenu[][200] = {	" *BY NAME " ,
				" *BY %AGE "
		       };
	int Ch;
	Ch = Hmenu(28,20,SoMenu,2);
	switch(Ch)	{
		case 0:	sortname(); break;
		case 1: sortmarks();

	}

	if(Ch!=0)
	{
		clrscr();

		if(N==0)
			secA();
		else if(N==1)
			secB();
		else if(N==2)
			secC();
		else if(N==3)
			secD();
	 }
	color(WHITE,BLACK);
}


void Search()
 {

  char SMenu[][200] = {	" *BY NAME " ,
			" *BY %AGE "
		       };
	int Ch;
	Ch = Hmenu(28,20,SMenu,2);
	switch(Ch)	{
		case 0:	searchname(); break;
		case 1: searchrange();

	}

	if(Ch!=0)
	{
		clrscr();

		if(N==0)
			secA();
		else if(N==1)
			secB();
		else if(N==2)
			secC();
		else if(N==3)
			secD();
	 }
	color(WHITE,BLACK);
}

void menu()
{
	char Menu2[][80]={	" EDIT a record ",
				" DISPLAY records ",
				" SORT records ",
				" SEARCH records ",
				" BACK to Main Menu "
			  };

	int Ch;
    do {
		Ch = Vmenu(28,10,Menu2,5);

		switch(Ch){
			case 0:Edit();break;
			case 1:display();break;
			case 2:Sort();break;
			case 3:Search();break;
			case 4:{Mainmenu();Ch=5;}
		}
	}while(Ch!=5);
}

void Mainmenu()            //introduction screen
{
	clrscr();
	stud A,B,C,D;

	color(CYAN,BLACK);
	clrscr();
	gotoxy(1,3);
	color(WHITE,GREEN);

	for (int i=1;i<=80;i++)
		cprintf(" ");

	gotoxy(31,3);
	cprintf("DELHI PUBLIC SCHOOL");

	gotoxy(1,4);
	color(YELLOW+BLINK,BLUE);
	for (int j=1;j<=80;j++)
		cprintf(" ");

	gotoxy(22,4);
	cprintf("C L A S S    X I I    R E C O R D S");
	color(CYAN,BLACK);
	gotoxy(5,7);
	cout<<"  This is Class XIIth Student Database. Here you can access records of";
	gotoxy(1,8);
	cout<<"   students of sections A,B,C and D. You can enter upto 15 records, delete old ";
	gotoxy(4,9);
	cout<<"records, sort the records in ascending/descending order, search for records  ";
	gotoxy(24,10);
	cout<<"and modify any record of your choice.";
	gotoxy(10,13);
	textcolor(WHITE);
	cprintf("               Select the class you want to access\n");


	char MainMenu[][200] = {	"  XII A  ",
					"  XII B  ",
					"  XII C  ",
					"  XII D  ",
					"  EXIT   "
				};
		 do{
		color(WHITE,BLACK);
		DHline(1,18,79);
		DHline(1,22,79);

		N = Hmenu(6,20,MainMenu,5);

		switch(N)
		{
			case 0:secA(); break;
			case 1:secB(); break;
			case 2:secC(); break;
			case 3:secD(); break;
			case 4:{
				Exit();
				N=5;
				}
		}
	}while(N!=5);
}

void secA()
{
	clrscr(); stud A;
	gotoxy(1,3);
	color(WHITE+BLINK,MAGENTA);

	for (int i=1;i<=80;i++)
		cprintf(" ");

		gotoxy(32,3);
		cprintf("CLASS XII A RECORDS");
			gotoxy(1,4);
			color(WHITE,BLUE);

			for (int j=1;j<=80;j++)
			cprintf(" ");
		gotoxy(32,4);
		cprintf("HUMANITIES  SECTION");
	color(WHITE,BLACK);
	menu();
}

void secB()
{
	clrscr();
	stud B;
			gotoxy(1,3);
			color(WHITE+BLINK,GREEN);

			for (int i=1;i<=80;i++)
			cprintf(" ");

				gotoxy(32,3);
				cprintf("CLASS XII B RECORDS");

			gotoxy(1,4);
			color(WHITE,BLUE);

		for (int j=1;j<=80;j++)
		cprintf(" ");

	gotoxy(27,4);
	cprintf("SCIENCE WITH BIOLOGY  SECTION");

	color(WHITE,BLACK);
	menu();
}

void secC()
{
	clrscr();
	stud C;
		gotoxy(1,3);
		color(WHITE+BLINK,YELLOW);

			for (int i=1;i<=80;i++)
				cprintf(" ");

			gotoxy(32,3);
			cprintf("CLASS XII C RECORDS");

				gotoxy(1,4);
				color(WHITE,BLUE);

				for (int j=1;j<=80;j++)
				cprintf(" ");

			gotoxy(33,4);
			cprintf("COMMERCE  SECTION");
	color(WHITE,BLACK);
	menu();
}

void secD()
{
	clrscr();
	stud D;
		gotoxy(1,3);
		color(WHITE+BLINK,CYAN);

			for (int i=1;i<=80;i++)
			cprintf(" ");

			gotoxy(32,3);
			cprintf("CLASS XII D RECORDS");
				gotoxy(1,4);
				color(WHITE,BLUE);

				for (int j=1;j<=80;j++)
				cprintf(" ");

			gotoxy(25,4);
			cprintf("SCIENCE WITH COMPUTER SC. SECTION");
	color(WHITE,BLACK);
	menu();
}


void main()
 {
	clrscr();
	intro();
	Mainmenu();
 }



void deletion()                  //delete a record
{
	    char choice[][200]={ " YES ",
				 " NO "
				 };
		fstream fil1,fil2;

		int del=0,ch;


			if(N==0)
			fil1.open("STUDENT1.DAT",ios::binary|ios::in);
			else if (N==1)
			fil1.open("STUDENT2.DAT",ios::binary|ios::in);
			else if (N==2)
			fil1.open("STUDENT3.DAT",ios::binary|ios::in);
			else if (N==3)
			fil1.open("STUDENT4.DAT",ios::binary|ios::in);
			else
			return;

				fil2.open("TEMP.DAT",ios::binary|ios::out);

				stud A;
				char n[20];

				do
				{
				clrscr();
				gotoxy(1,4);
				color(YELLOW,BLUE);

				for (int i=1;i<=80;i++)
				cprintf(" ");

				gotoxy(30,4);
				cprintf("DELETE RECORD");
				do
				{
				color(WHITE,BLACK);
				gotoxy(10,12);
				cprintf("     Enter name of the student record to be deleted:");
				gets(n);
				}while(checkname(n)!=0);

					while(fil1.read((char*)&A,sizeof(A)))
					{
					if(strcmpi (A.getname(),n) == 0)
						del++;
					else
						fil2.write((char*)&A,sizeof(A));

					 }
	fil1.close();
	fil2.close();

	if(!del)
	{
		color(RED+BLINK,BLACK);
		gotoxy(30,15);
		cprintf("No record deleted!");
		getch();
	}
	else
	{
		color(GREEN+BLINK,BLACK);
		transfer();
		gotoxy(32,15);
		cprintf("Record deleted!");
		getch();
	}
	gotoxy(25,23);
	color(WHITE,BLACK);
	cprintf("CONTINUE?");

	ch = Hmenu(37,23,choice,2);
	switch(ch)
	{
	case 0:deletion(); break;
	case 1:{if(N==0)
		secA();
	else if (N==1)
		secB();
	else if (N==2)
		secC();
	else if (N==3)
		secD();
		ch=2;
		}
	}
   }while(ch!=2);
}


void sortname()                 // sort records in ascending order of name
{
	clrscr();
	gotoxy(1,4);
	color(YELLOW,BLUE);

	for (int u=1;u<=80;u++)
		cprintf(" ");

	gotoxy(35,4);
	cprintf("SORT NAME");

	fstream fil;

			if(N==0)
			fil.open("STUDENT1.DAT",ios::binary|ios::in|ios::out);
			else if (N==1)
			fil.open("STUDENT2.DAT",ios::binary|ios::in|ios::out);
			else if (N==2)
			fil.open("STUDENT3.DAT",ios::binary|ios::in|ios::out);
			else if (N==3)
			fil.open("STUDENT4.DAT",ios::binary|ios::in|ios::out);
			else
			return;

				stud A, A1;
				fil.seekg(0,ios::end);
				int nor=fil.tellg()/sizeof(A);

					for(int i=0;i<nor-1;i++)
					{
						for(int j=0;j<nor-i-1;j++)
						{	fil.seekg(j*sizeof(A));
							fil.read((char*)&A,sizeof(A));
							fil.read((char*)&A1,sizeof(A1));
							if(strcmpi(A.getname(),A1.getname())>0)
							{	fil.seekp(j*sizeof(A));
								fil.write((char*)&A1,sizeof(A1));
								fil.write((char*)&A,sizeof(A));
							}
						}
					}

				color
				(GREEN+BLINK,BLACK);
				gotoxy(34,15);
				cprintf("Record sorted!");
				getch();

		fil.flush ();
		fil.close ();

	clrscr();
	color(WHITE,BLACK);
	display();





	if(N==0)
		secA();
	else if (N==1)
		secB();
	else if (N==2)
		secC();
	else if (N==3)
		secD();

}

void sortmarks()            //sort records in descending order of marks
{
	clrscr();
	gotoxy(1,4);
	color(YELLOW,BLUE);

		for (int u=1;u<=80;u++)
		cprintf(" ");

		gotoxy(38,4);
		cprintf("SORT MARKS");

		fstream fil;

			if(N==0)
			fil.open("STUDENT1.DAT",ios::binary|ios::in|ios::out);
			else if (N==1)
			fil.open("STUDENT2.DAT",ios::binary|ios::in|ios::out);
			else if (N==2)
			fil.open("STUDENT3.DAT",ios::binary|ios::in|ios::out);
			else if (N==3)
			fil.open("STUDENT4.DAT",ios::binary|ios::in|ios::out);
			else
			return;

				stud A, A1;
				fil.seekg(0,ios::end);
				int nor=fil.tellg()/sizeof(A);

					for(int i=0;i<nor-1;i++)
					{	for(int j=0;j<nor-i-1;j++)
						{	fil.seekg(j*sizeof(A));
							fil.read((char*)&A,sizeof(A));
							fil.read((char*)&A1,sizeof(A1));
							if(A.retavg()<A1.retavg())
							{	fil.seekp(j*sizeof(A));
								fil.write((char*)&A1,sizeof(A1));
								fil.write((char*)&A,sizeof(A));
							}
						}
					}

			color(GREEN+BLINK,BLACK);
			gotoxy(34,15);
			cprintf("Record sorted!");
		getch();

	fil.flush ();
	fil.close ();

	clrscr();
	color(WHITE,BLACK);
	display();

	if(N==0)
		secA();
	else if (N==1)
		secB();
	else if (N==2)
		secC();
	else if (N==3)
		secD();

}

void searchname()           //search for a record using name
{
	clrscr();
	fstream fil;
	gotoxy(1,4);
	color(YELLOW,BLUE);

	for (int i=1;i<=80;i++)
		cprintf(" ");

	gotoxy(33,4);
	cprintf("SEARCH FOR RECORD");


		if(N==0)
		fil.open("STUDENT1.DAT",ios::binary|ios::in);
		else if (N==1)
		fil.open("STUDENT2.DAT",ios::binary|ios::in);
		else if (N==2)
		fil.open("STUDENT3.DAT",ios::binary|ios::in);
		else if (N==3)
		fil.open("STUDENT4.DAT",ios::binary|ios::in);
		else
		return;


			stud A; char t[20];
			int found=0;

			do {
				gotoxy(15,12);
				color(WHITE,BLACK);
				cprintf("       Enter name of student to be searched:");gets(t);
			    }while(checkname(t)!=0);

				while(fil.read((char*)&A,sizeof(A)))
					if(strcmpi(A.getname(),t)==0)
					{
						color(GREEN+BLINK,BLACK);
						gotoxy(35,15);
						cprintf("RECORD FOUND");
						getch();

					// Logic for record writing to be provided here...
						clrscr();
						color(WHITE,BLACK);
						Hline(15,11,56);
						Vline(33,9,5);
						Vline(38,9,5);
						Vline(43,9,5);
						Vline(48,9,5);
						Vline(53,9,5);
						Vline(58,9,5);
						Vline(65,9,5);

					gotoxy(1,3);
					color(MAGENTA,BLUE);

					for (int i=1;i<=80;i++)
					cprintf(" ");

					gotoxy(37,3);
					cprintf("SEARCH RESULT");
					color(WHITE,BLACK);
					if(N==0)
					{
					 color(WHITE,BLACK);
					 gotoxy(20,10);
					 cprintf("NAME");
					 gotoxy(34,10);
					 cprintf("ENG");
					 gotoxy(39,10);
					 cprintf("HIS");
					 gotoxy(44,10);
					 cprintf("SOC");
					 gotoxy(49,10);
					 cprintf("GEO");
					 gotoxy(54,10);
					 cprintf("POL");
					 gotoxy(60,10);
					 cprintf("%age");
					 gotoxy(67,10);
					 cprintf("GRD");
					 A.dataout(2);
					getch();
					}

				else if (N==1)
				{ color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("PHY");
				gotoxy(44,10);
				cprintf("CHE");
				gotoxy(49,10);
				cprintf("BIO");
				gotoxy(54,10);
				cprintf("MAT");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");
				A.dataout(2);
				getch();
				}

				else if (N==2)
				{
				color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("ACC");
				gotoxy(44,10);
				cprintf("MAT");
				gotoxy(49,10);
				cprintf("ECO");
				gotoxy(54,10);
				cprintf("B.ST");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");
				A.dataout(2);
				getch();
				}

				else if(N==3)
				{
				color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("PHY");
				gotoxy(44,10);
				cprintf("CHE");
				gotoxy(49,10);
				cprintf("C.SC");
				gotoxy(54,10);
				cprintf("MAT");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");
				A.dataout(2);
				getch();
			}
		found++;
	 }

	if(found==0)
	{
		color(RED+BLINK,BLACK);
		gotoxy(35,16);
		cprintf("RECORD NOT FOUND");
		getch();
	}


	fil.close();

	if(N==0)
		secA();
	else if (N==1)
		secB();
	else if (N==2)
		secC();
	else if (N==3)
		secD();

}


void searchrange()
{	clrscr();
	fstream fil;
	gotoxy(1,4);
	color(YELLOW,BLUE);

	for (int i=1;i<=80;i++)
		cprintf(" ");

	gotoxy(33,4);
	cprintf("SEARCH FOR RECORD");


		if(N==0)
		fil.open("STUDENT1.DAT",ios::binary|ios::in);
		else if (N==1)
		fil.open("STUDENT2.DAT",ios::binary|ios::in);
		else if (N==2)
		fil.open("STUDENT3.DAT",ios::binary|ios::in);
		else if (N==3)
		fil.open("STUDENT4.DAT",ios::binary|ios::in);
		else
		return;

		stud A; int x, y, found=0, k=0;
		char X[10],Y[10];

		itoa(x,X,10);
		itoa(y,Y,10);

		gotoxy(9,9);
		color(WHITE,BLACK);
		cprintf("Enter range of marks in which you want the records to be searched");
		gotoxy(35,14);
		cprintf("From");
		gotoxy(43,14);
		cprintf("%  to");
		gotoxy(51,14);
		cprintf("%");
		do
		{
		gotoxy(40,14);
		gets(X);
		}while(checkno(X)!=0);
		x=atoi(X);
		do
		{
		gotoxy(49,14);
		gets(Y);
		}while(checkno(Y)!=0);
		y=atoi(Y);




		clrscr();
		while(fil.read((char*)&A,sizeof(A)))
		if(A.retavg()>=x && A.retavg()<=y)
		{

					gotoxy(1,3);
					color(MAGENTA+BLINK,BLUE);

					for (int l=1;l<=80;l++)
					cprintf(" ");

					gotoxy(37,3);
					cprintf("SEARCH RESULT");


					color(WHITE,BLACK);
						Hline(15,11,56);
						Vline(33,9,4+k);
						Vline(38,9,4+k);
						Vline(43,9,4+k);
						Vline(48,9,4+k);
						Vline(53,9,4+k);
						Vline(58,9,4+k);
						Vline(65,9,4+k);

					if(N==0)
					{
					 color(WHITE,BLACK);
					 gotoxy(20,10);
					 cprintf("NAME");
					 gotoxy(34,10);
					 cprintf("ENG");
					 gotoxy(39,10);
					 cprintf("HIS");
					 gotoxy(44,10);
					 cprintf("SOC");
					 gotoxy(49,10);
					 cprintf("GEO");
					 gotoxy(54,10);
					 cprintf("POL");
					 gotoxy(60,10);
					 cprintf("%age");
					 gotoxy(67,10);
					 cprintf("GRD");


					}

				else if (N==1)
				{ color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("PHY");
				gotoxy(44,10);
				cprintf("CHE");
				gotoxy(49,10);
				cprintf("BIO");
				gotoxy(54,10);
				cprintf("MAT");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");


				}

				else if (N==2)
				{
				color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("ACC");
				gotoxy(44,10);
				cprintf("MAT");
				gotoxy(49,10);
				cprintf("ECO");
				gotoxy(54,10);
				cprintf("B.ST");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");


				}

				else if(N==3)
				{
				color(WHITE,BLACK);
				gotoxy(20,10);
				cprintf("NAME");
				gotoxy(34,10);
				cprintf("ENG");
				gotoxy(39,10);
				cprintf("PHY");
				gotoxy(44,10);
				cprintf("CHE");
				gotoxy(49,10);
				cprintf("C.SC");
				gotoxy(54,10);
				cprintf("MAT");
				gotoxy(60,10);
				cprintf("%age");
				gotoxy(67,10);
				cprintf("GRD");


			}

			A.dataout(2+k);
			k++;
			found++;
	 }

	if(found==0)
	{
		gotoxy(1,3);
		color(MAGENTA+BLINK,BLUE);

		for (int l=1;l<=80;l++)
		cprintf(" ");

		gotoxy(37,3);
		cprintf("SEARCH RESULT");

		color(RED+BLINK,BLACK);
		gotoxy(35,12);
		cprintf("RECORD NOT FOUND");

	}


	fil.close();
	getch();
	if(N==0)
		secA();
	else if (N==1)
		secB();
	else if (N==2)
		secC();
	else if (N==3)
		secD();

}





void modify()               //modify marks of a particular record
{
	  clrscr();
	fstream fil;
	gotoxy(1,4);
	color(YELLOW,BLUE);

	for (int i=1;i<=80;i++)
		cprintf(" ");

	gotoxy(33,4);
	cprintf("MODIFY RECORD");


		if(N==0)
			fil.open("STUDENT1.DAT",ios::binary|ios::in|ios::out);
		else if (N==1)
			fil.open("STUDENT2.DAT",ios::binary|ios::in|ios::out);
		else if (N==2)
			fil.open("STUDENT3.DAT",ios::binary|ios::in|ios::out);
		else if (N==3)
			fil.open("STUDENT4.DAT",ios::binary|ios::in|ios::out);
		else
			return;
			long pos;  char nam[30];
		stud A;    int f=0;
		color(WHITE,BLACK);

			do
			{
			gotoxy(10,10);
			cprintf("Enter name of the student whose record is to be updated: ") ;
			gets(nam);
			}while(checkname(nam)!=0);

			while(fil.read((char*)&A,sizeof(A)))
			{
				if(strcmpi(A.getname(),nam)==0)
				{
					A.modify1();
					pos=fil.tellg();
					fil.seekp(pos-sizeof(A));
					fil.write((char*)&A,sizeof(A));
						textcolor(GREEN+BLINK);
						gotoxy(31,24);
						cprintf("RECORD MODIFIED");
						f++;
				}

			}

		fil.close();
		if(f==0)
		{
			textcolor(RED+BLINK);
			gotoxy(31,13);
			cprintf("RECORD NOT FOUND");

		}

	getch();
}

void stud::modify1()
{
 color(CYAN,BLACK);
 int mks1,mks2,mks3,mks4,mks5;
	if(N==0)
	{color(CYAN,BLACK);
	gotoxy(18,15);
	cprintf("( Press -1 to retain old data in any field )");
	gotoxy(32,18);
	color(WHITE,BLACK);
		 cprintf("ENTER NEW DATA");
		 gotoxy(15,20);
		 cprintf("ENG: ");
		 gotoxy(25,20);
		 cprintf("HIST: ");
		 gotoxy(35,20);
		 cprintf("SOC: ");
		 gotoxy(45,20);
		 cprintf("GEO: ");
		 gotoxy(55,20);
		 cprintf("POL.SC: ");

			gotoxy(20,20);
			cin>>mks1;
			gotoxy(31,20);
			cin>>mks2;
			gotoxy(40,20);
			cin>>mks3;
			gotoxy(50,20);
			cin>>mks4;
			gotoxy(63,20);
			cin>>mks5;

		if(mks1!= -1)
			S1=mks1;
		if(mks2!= -1)
			S2=mks2;
		if(mks3!= -1)
			S3=mks3;
		if(mks4!= -1)
			S4=mks4;
		if(mks5!= -1)
			S5=mks5;
	}

	else if(N==1)

	{
		color(CYAN,BLACK);
		gotoxy(18,15);
		cprintf("( Press -1 to retain old data in any field )");
		gotoxy(32,18);
		color(WHITE,BLACK);
			cprintf("ENTER NEW DATA");
			gotoxy(15,20);
			cprintf("ENG: ");
			gotoxy(25,20);
			cprintf("PHY: ");
			gotoxy(35,20);
			cprintf("CHEM: ");
			gotoxy(45,20);
			cprintf("BIO: ");
			gotoxy(55,20);
			cprintf("MATHS: ");

				gotoxy(20,20);
				cin>>mks1;
				gotoxy(30,20);
				cin>>mks2;
				gotoxy(41,20);
				cin>>mks3;
				gotoxy(50,20);
				cin>>mks4;
				gotoxy(62,20);
				cin>>mks5;

		if(mks1!= -1)
			S1=mks1;
		if(mks2!= -1)
			S2=mks2;
		if(mks3!= -1)
			S3=mks3;
		if(mks4!= -1)
			S4=mks4;
		if(mks5!= -1)
			S5=mks5;
	}

		else if(N==2)
		{
		color(CYAN,BLACK);
		gotoxy(18,15);
		cprintf("( Press -1 to retain old data in any field )");
		gotoxy(32,18);
		color(WHITE,BLACK);
			cprintf("ENTER NEW DATA");
			gotoxy(15,20);
			cprintf("ENG: ");
			gotoxy(25,20);
			cprintf("ACC: ");
			gotoxy(35,20);
			cprintf("MATHS: ");
			gotoxy(45,20);
			cprintf("ECO: ");
			gotoxy(55,20);
			cprintf("B.ST: ");

				gotoxy(20,20);
				cin>>mks1;
				gotoxy(30,20);
				cin>>mks2;
				gotoxy(42,20);
				cin>>mks3;
				gotoxy(50,20);
				cin>>mks4;
				gotoxy(61,20);
				cin>>mks5;

			if(mks1!= -1)
				S1=mks1;
			if(mks2!= -1)
				S2=mks2;
			if(mks3!= -1)
				S3=mks3;
			if(mks4!= -1)
				S4=mks4;
			if(mks5!= -1)
				S5=mks5;
		}

		else if(N==3)
		{
		color(CYAN,BLACK);
		gotoxy(18,15);
		cprintf("( Press -1 to retain old data in any field )");
		gotoxy(32,18);
		color(WHITE,BLACK);
			cprintf("ENTER NEW DATA");
			gotoxy(15,20);
			cprintf("ENG: ");
			gotoxy(25,20);
			cprintf("PHY: ");
			gotoxy(35,20);
			cprintf("CHEM: ");
			gotoxy(45,20);
			cprintf("C.SC: ");
			gotoxy(55,20);
			cprintf("MATHS: ");

				gotoxy(20,20);
				cin>>mks1;
				gotoxy(30,20);
				cin>>mks2;
				gotoxy(41,20);
				cin>>mks3;
				gotoxy(51,20);
				cin>>mks4;
				gotoxy(62,20);
				cin>>mks5;


		if(mks1!= -1)
			S1=mks1;
		if(mks2!= -1)
			S2=mks2;
		if(mks3!= -1)
			S3=mks3;
		if(mks4!= -1)
			S4=mks4;
		if(mks5!= -1)
			S5=mks5;
	 }
}


void Exit()                      //exit screen
{
	clrscr();
	char choice[][200]={" YES ",
			    " NO "};
	int ch;
	do
	{
		gotoxy(27,10);
		textcolor(WHITE);
		cprintf("Are you sure you want to exit?");
		DRecta(24,8,59,15);
		ch = Hmenu(31,13,choice,2);
		switch(ch)
		{case 0:exit(0);
			break;
		 case 1:Mainmenu();ch=2;

		 }
		}while(ch!=2);


}


				//END OF PROGRAM