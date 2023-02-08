#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void setWinStyle();
int userLogin();
void userSignUp();
int adminLogin();
void adminSignUp();
char *setW(char *word);
void displayBusList();
void addBus();
void bookSeat();
void showBookings();

int main(int num){
	int choice,lcheck;
	setWinStyle();
	loop1 :
	system("cls");
	printf("  =====================Welcome To Bus Reservation System======================\n");
	printf("\n\t\t1>>>User Login");
	printf("\n\t\t2>>>User SignUp");
	printf("\n\t\t3>>>Admin Login");
	printf("\n\t\t4>>>Admin SignUp");
	printf("\n\n\n\t\t>>>>Enter Your Choice : ");
	scanf("%d",&choice);
	if(choice==1){
		lcheck=userLogin();
		if(lcheck){
			goto loop2;
		}else{
			goto loop1;
		}
	}else if(choice==2){
		userSignUp();
		goto loop1;
	}else if(choice==3){
		lcheck=adminLogin();
		if(lcheck){
			goto loop3;
		}else{
			goto loop1;
		}
	}else if(choice==4){
		adminSignUp();
		goto loop1;
	}else{
		goto loop1;
	}
	
	loop2 :
	system("cls");
	printf("  =====================Welcome To Bus Reservation System======================\n");
	printf("\n\t\t1>>>View Bus Details");
	printf("\n\t\t2>>>Book Your Seats");
	printf("\n\t\t3>>>Show Booking Details");
	printf("\n\t\t4>>>Log Out");
	printf("\n\n\n\t\t>>>>Enter Your Choice : ");
	scanf("%d",&choice);
	if(choice==1){
		displayBusList();
		goto loop2;
	}else if(choice==2){
		bookSeat();
		goto loop2;
	}else if(choice==3){
		showBookings();
		goto loop2;
	}else{
		goto loop1;
	}
	
	loop3 :
	system("cls");
	printf("  =====================Welcome To Bus Reservation System======================\n");
	printf("\n\t\t1>>>Add Bus Details");
	printf("\n\t\t2>>>Log Out");
	printf("\n\n\n\t\t>>>>Enter Your Choice : ");
	scanf("%d",&choice);
	if(choice==1){
		addBus();
		goto loop3;
	}else if(choice==2){
		goto loop1;
	}else{
		goto loop3;
	}
	
	getch();
}


int userLogin(){
	char lname[15],fname[15],uname[15],upass[15],getu[15],getp[15];
	FILE *pf;
	system("cls");
	printf("  ===============================User Login=============================== \n\n");
	
	pf=fopen("user/user.txt","r");
	if(pf==NULL){
		printf("Error Occcured While Login!");
	}else{
		printf("\n\t\tEnter Username :");
		scanf("%s",&uname);
		printf("\n\t\tEnter Password :");
		scanf("%s",&upass);
		while(!feof(pf)){
			fscanf(pf,"%s\t%s\t%s\t%s\n",fname,lname,getu,getp);
			if(!strcmp(uname,getu) && !strcmp(upass,getp)){
				printf("\n\t\tUser LoggedIn Succesfully");
				printf("\n\n\n\t\t>>>>Press Any Key for Bus Services : ");
				getch();
				return 1;
			}
		}
		fclose(pf);
	}
	printf("\n\t\tInvalid Username or Password");
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
	return 0;
	
}


void userSignUp(){
	char lname[15],fname[15],uname[15],upass[15];
	FILE *pf;
	system("cls");
	printf("  ================================User SignUp================================ \n\n");
	
	pf=fopen("user/user.txt","a");
	if(pf==NULL){
		printf("Error Occcured While Login!");
	}else{
		printf("\n\t\tEnter First Name :");
		scanf("%s",fname);
		printf("\n\t\tEnter Last Name :");
		scanf("%s",lname);
		printf("\n\t\tEnter Username :");
		scanf("%s",&uname);
		printf("\n\t\tNew Password :");
		scanf("%s",&upass);
		fprintf(pf,"%s\t%s\t%s\t%s\n",fname,lname,uname,upass);
		printf("\n\t\tUser Created Succesfully");
		fclose(pf);
	}
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
	
}


int adminLogin(){
	char lname[20],fname[20],uname[20],upass[20],getu[20],getp[20];
	FILE *pf;
	system("cls");
	printf("  ================================Admin Login================================ \n\n");
	
	pf=fopen("admin/admin.txt","r");
	if(pf==NULL){
		printf("Error Occcured While Login!");
	}else{
		printf("\n\t\tEnter Username :");
		scanf("%s",&uname);
		printf("\n\t\tEnter Password :");
		scanf("%s",&upass);
		while(!feof(pf)){
			fscanf(pf,"%s\t%s\t%s\t%s\n",fname,lname,getu,getp);
			if(!strcmp(uname,getu) && !strcmp(upass,getp)){
				printf("\n\t\tLoggedIn Succesfully");
				printf("\n\n\n\t\t>>>>Press Any Key for Bus Services : ");
				getch();
				return 1;
			}
		}
		fclose(pf);
	}
	printf("\n\t\tInvalid Username or Password");
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
	return 0;
	
}


void adminSignUp(){
	char lname[20],fname[20],uname[20],upass[20];
	FILE *pf;
	system("cls");
	printf("  ===============================admin SignUp=============================== \n\n");
	
	pf=fopen("admin/admin.txt","a");
	if(pf==NULL){
		printf("Error Occcured While Login!");
	}else{
		printf("\n\t\tEnter First Name :");
		scanf("%s",fname);
		printf("\n\t\tEnter Last Name :");
		scanf("%s",lname);
		printf("\n\t\tEnter Username :");
		scanf("%s",&uname);
		printf("\n\t\tNew Password :");
		scanf("%s",&upass);
		fprintf(pf,"%s\t%s\t%s\t%s\n",fname,lname,uname,upass);
		printf("\n\t\tAccount Created Succesfully");
		fclose(pf);
	}
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
	
}


void displayBusList(){
	FILE *pf;
	char blname[20],blfrom[20],bldest[20],blnum[20],blseat[20];
	char n[]="Name",f[]="From",d[]="Destination",b[]="BusNo",a[]="Available";
	pf=fopen("bus/buslist.txt","r");
	system("cls");
	if(pf==NULL){
		printf("File Not Open");
	}else{
		printf("  =================================Bus List================================ \n\n");
		printf("%s%s%s%s%s\n\n",setW(n),setW(f),setW(d),setW(b),setW(a));
		while(!feof(pf)){
			fscanf(pf,"%s\t%s\t%s\t%s\t%s\n",blname,blfrom,bldest,blnum,blseat);
			printf("%s%s%s%s%s\n",setW(blname),setW(blfrom),setW(bldest),
			setW(blnum),setW(blseat));
		}
		fclose(pf);
	}
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
}


void addBus(){
	FILE *pf;
	pf=fopen("bus/buslist.txt","a");
	char bname[20],bfrom[20],bdest[20],bnum[20],bseats[20];
	system("cls");
	if(pf==NULL){
		printf("Error Occured While Adding Bus !");
	}else{
		printf("  =================================Add Bus================================= \n\n");
		printf("\t\tEnter Details Accordingly to Add Bus :-\n\t\t");
		printf("\n\t\tBusName : ");
		scanf("%s",&bname);
		printf("\n\t\tBusFrom : ");
		scanf("%s",&bfrom);
		printf("\n\t\tBusDestination : ");
		scanf("%s",&bdest);
		printf("\n\t\tBusNunmber: ");
		scanf("%s",&bnum);
		printf("\n\t\tAvailableSeats : ");
		scanf("%s",&bseats);
		fprintf(pf,"%s\t%s\t%s\t%s\t%s\n",bname,bfrom,bdest,bnum,bseats);	
		fclose(pf);	
		
	}
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
}


void bookSeat(){
	FILE *pf,*nf,*rf;
	pf=fopen("bus/buslist.txt","r");
	char bname[20],bfrom[20],bdest[20];
	char uname[20],uemail[50],filepath[100]="bookings/";
	int busnum,bseats,bnum,tseats;
	system("cls");
	if(pf==NULL){
		printf("Error Occured While Booking Seats !");
	}else{
		printf("  ================================Book Seats=============================== \n\n");
		printf("\t\tEnter Details to Book Seats :-\n\t\t");
		printf("\n\t\tEnter Bus No : ");
		scanf("%d",&busnum);
		while(!feof(pf)){
			fscanf(pf,"%s\t%s\t%s\t%d\t%d\t",&bname,&bfrom,&bdest,&bnum,&bseats);
			if(bnum==busnum){
				break;
			}
		}
		fclose(pf);
		printf("\n\t\tTotal no of seats Available : %d",bseats);
		printf("\n\t\tEnter First Name: ");
		scanf("%s",&uname);
		printf("\n\t\tEnter Email: ");
		scanf("%s",&uemail);
		printf("\n\t\tEnter total no of seats to book : ");
		scanf("%d",&tseats);
		if(tseats<=bseats){
			printf("\n\t\tSeats Booking ........");
			strcat(filepath,strtok(uemail,"@"));
			strcat(filepath,".txt");
			pf=fopen(filepath,"a+");
			if(pf==NULL){
				printf("Error Occured While Booking Seats !");
			}else{
				fprintf(pf,"%s\t%s\t%d\t%s\t%d\t%s\t%s\n",uname,uemail,tseats,bname,bnum,bfrom,bdest);
				printf("\n\t\t%d seats booked Successfully ",tseats);
				fclose(pf);
				nf=fopen("bus/buslist.txt","r");
				rf=fopen("bus/replace.txt","w");
				while(!feof(nf)){
					fscanf(pf,"%s\t%s\t%s\t%d\t%d\n",&bname,&bfrom,&bdest,&bnum,&bseats);
					if(bnum==busnum){
						if(bseats-tseats<=0){
							continue;
						}else{
							fprintf(rf,"%s\t%s\t%s\t%d\t%d\n",bname,bfrom,bdest,bnum,bseats-tseats);
						}
					}else{
						fprintf(rf,"%s\t%s\t%s\t%d\t%d\n",bname,bfrom,bdest,bnum,bseats);
					}
				}
				fclose(nf);
				fclose(rf);
				remove("bus/buslist.txt");
				rename("bus/replace.txt","bus/buslist.txt");
			}	
		}else{
			printf("\n\t\tThat much seats not available !");
		}
		fclose(pf);
	}
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
}


void showBookings(){
	FILE *pf;
	char bname[20],bfrom[20],bdest[20],bnum[15],tseats[15],d[]="Destination";
	char uname[20],uemail[50],filepath[100]="bookings/";
	char n[]="Name",e[]="Email",s[]="Seats",b[]="BusName",bn[]="BusNo",f[]="From";
	system("cls");
	printf("  ==============================Show Bookings============================= \n\n");
	printf("\n\t\tEnter Email: ");
	scanf("%s",&uemail);
	strcat(filepath,strtok(uemail,"@"));
	strcat(filepath,".txt");
	pf=fopen(filepath,"r");
	if(pf==NULL){
		printf("Error Occured While Fetching Details !");
	}else{
		printf("\n%s%s%s%s%s%s%s\n",setW(n),setW(e),setW(s),setW(b),setW(bn),setW(f),setW(d));
		while(!feof(pf)){
			fscanf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",uname,uemail,tseats,bname,bnum,bfrom,bdest);
			printf("\n%s%s%s%s%s%s%s\n",setW(uname),setW(uemail),setW(tseats),
			setW(bname),setW(bnum),setW(bfrom),setW(bdest));
		}
		
	}	
	printf("\n\n\n\t\t>>>>Press Any Key To See Main Menu : ");
	getch();
}


char *setW(char *word){
	int i;
	for(i=strlen(word); i<15; i++){
		word[i]=' ';
	}
	return word;
}


void setWinStyle(){ 
	system("title Bus Reservation System");
	system("mode 80,26");
	system("color f5");
	CONSOLE_FONT_INFOEX cfi = {sizeof(cfi)};
	cfi.dwFontSize.Y = 22;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);
}



