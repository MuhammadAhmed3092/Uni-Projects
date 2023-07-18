#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Structures
struct name{
	char firstn[20];
	char midn[20];
	char lastn[20];
};
struct data { struct name name;
double cnic;
struct name fhname;
char gender;
}info;
struct flightdata{
	struct data info;
    char hoteltype[30];
    int flighttime;
    char flightlocation[30];
};




//Final Bill 
void finalbill(int totalbill){
	printf("\t\t\t\t\t-----------------------------------\t\t\n");
	printf("\t\t\t\t\t***********FINAL BILL**************\n");
	printf("\t\t\t\t\t-----------------------------------\t\t\n\n");
	FILE *fptr;
	fptr=fopen("finalrpoject.txt","r");
	if(fptr==NULL)
	{
		printf("Error ! No File Found");
	}
	else
	{
	printf("\nName:%s %s %s",info.name.firstn,info.name.midn,info.name.lastn);
	printf("\nFather/Husband Name:%s %s %s",info.fhname.firstn,info.fhname.midn,info.fhname.lastn);
	printf("\nCNIC: %d",info.cnic);
	printf("\nGender: %c",info.gender);
	printf("\nFinal Bill is :%dUSD",totalbill);
	fprintf(fptr,"\t\t\t\t\t-----------------------------------\t\t\n");
	fprintf(fptr,"\t\t\t\t\tFinal Bill\t\t\n");
	fprintf(fptr,"\t\t\t\t\t-----------------------------------\t\t\n");
	fscanf(fptr,"%s ",info.name.firstn);
	fscanf(fptr,"%s ",info.name.midn);
	fscanf(fptr,"%s",info.name.lastn);
	fclose(fptr);
}
	}



//Inputting Information
struct data information(){
		FILE *fptr;
		fptr=fopen("finalrpoject.txt","w+");
		if(fptr==NULL)
		{
		printf("Error!No File Found");exit(0);
		}
		else
		{
		printf("\nYour Personal Details :-\n");
		printf("Enter your First Name: ");
		gets(info.name.firstn);		
		gets(info.name.firstn);
		fprintf(fptr,"First Name : %s",info.name.firstn);
		
		printf("Enter your middle name: ");
		gets(info.name.midn);
		fprintf(fptr,"\n");
		fprintf(fptr,"Middle Name : %s",info.name.midn);
		
		printf("Enter your last name: ");
		gets(info.name.lastn);
		fprintf(fptr,"\n");
		fprintf(fptr,"Last Name : %s",info.name.lastn);
		
		printf("\nYour Father/Husband Details :-\n");
        printf("Enter your Father/Husband first name : ");
        gets(info.fhname.firstn);
        fprintf(fptr,"\n");
        fprintf(fptr,"Father/Husband First Name : %s",info.fhname.firstn);
        
        printf("Enter your Father/Husbands middle name : ");
        gets(info.fhname.midn);
        fprintf(fptr,"\n");
        fprintf(fptr,"Father/Husband Middle Name : %s",info.fhname.midn);
        
        printf("Enter your Father/Husband last name : ");
        gets(info.fhname.lastn);
        fprintf(fptr,"\n");
        fprintf(fptr,"Father/Husband Last Name : %s",info.fhname.lastn);
        
        label:
        printf("Enter your Gender");
		printf("\nPress M/m for male");
		printf("\nPress F/f for female:");
        scanf(" %c",&info.gender);
        fprintf(fptr,"\n");
        fprintf(fptr,"Your Gender : %c",info.gender);
        
        if(info.gender=='M' || info.gender=='m')
        {
        	fprintf(fptr,"\n");
        	fprintf(fptr,"Your Gender Is Male\n");
        	printf("Your Gender Is Male\n");
		}
		else if(info.gender=='F' || info.gender=='f')
		{
			fprintf(fptr,"\n");
        	fprintf(fptr,"Your Gender Is Female");
			printf("Your Gender Is Female");
		}
		else
		{
			printf("Invalid Input! Please Try Again\n");
			goto label;
		}
		
        printf("\nEnter Your CNIC Number: ");
        scanf("%d",&info.cnic);
        fprintf(fptr,"\n");
        fprintf(fptr,"Your CNIC %d",info.cnic);
        return info;
		}
        fclose(fptr);
}




//Choosing Location And Calculations for Ticket
int ticket(){
int location,tickettype,tc,hc,amountticket,wttc;
label:
    printf("\n\t\tEnter your trip location type\t\t");
	printf("\n\t\t1 for Great Wall Of China Cost=150USD\t\t");
	printf("\n\t\t2 for Taj Mahal:200USD\t\t");
	printf("\n\t\t3 for Eifel Tower in France: 450USD\t\t");
	printf("\n\t\t4 for Grand Canyon in USACost=300USD\t\t");
	printf("\n\t\t5 for Chich�n Itz� in Mexico Cost=400USD\t\t");
	printf("\n\t\t6 for Petra in Jordan Cost=350USD\t\t");
	printf("\n\t\t7 for Machu Picchu in Peru Cost=275USD\n\t\t");
	printf("\nEnter Your Choice : ");
    
    scanf("%d",&location);
    
    printf("\nIs it a return ticket or one way trip ? 0 for return\n1 for one way trip: ");
    printf("\nEnter Your Choice : ");
    scanf("%d",&tickettype);
    
    if (tickettype>1){
    	printf("\n***********************Invalid Input*************************");
    	goto label;
	} 
	else{
	
    printf("How many tickets do you want: ");
    scanf("%d",&amountticket);
    
    if (amountticket<0){
    	printf("\n****************************Invalid Input******************************");
    	goto label;
	};
	
    if(tickettype==0){
         switch(location){
         	case 1:
         		tc=100*amountticket*2;
         	    break;
         	case 2:
         		tc=250*amountticket*2;
         		break;
         	case 3:
         		tc=450*amountticket*2;
         	    break;
    		case 4:
    			tc=300*amountticket*2;
    			break;
    		case 5:
    			tc=150*amountticket*2;
    			break;
    		case 6:
    			tc=350*amountticket*2;
    			break;
    		default :
    			printf("Invalid Choice");
    			goto label;
				break;
	}
	} 
	else if (tickettype==1)
	{
	switch(location)
	{
         	case 1:
         		tc=100*amountticket;
         	    break;
         	case 2:
         		tc=250*amountticket;
         		break;
         	case 3:
         		tc=450*amountticket;
         	    break;
    		case 4:
    			tc=300*amountticket;
    			break;
    		case 5:
    			tc=150*amountticket;
    			break;
    		case 6:
    			tc=350*amountticket;
    			break;
    		default :
    			printf("Invalid Choice");
    			break;
	}
}
}}




//Hotel And Food
	hotel(tc){
	 a:
	 printf("\n\nDo you want an Economy class ticket or Business class");
	 printf("\n1 for business class");
	 printf("\n0 for economy");
	 printf("\nNote: Buisness class is an extra 50 USD on base cost.\n");
	 printf("\nEnter Your Choice : ");
	 int tic;
	 scanf("%d",&tic);
	 if (tic==1)
	 {
	 	tc=tc+50;
	 }
	 else if(tic==0)
	 {
	 tc=tc;
	 }
	 else 
	 {
	 	printf("Invalid input: Please try again: ");
	 	goto a;
	 }
	 b:
	 printf("\nDo you want meals?");
	 printf("\nNote : Cost 20USD");
	 printf("\nType 0 for Yes");
	 printf("\nType 1 for No");
	 printf("\nEnter Your Choice : ");
	 int food;
	 scanf("%d",&food);
	  if (food==0){
	 	tc=tc+20;
	 }
	 else if(food==1){tc=tc;
	 }
	 else {
	 	printf("Invalid Input: Please Try Again: ");
	 	goto b;
	 }
	 printf("\nDo you need an hotel room ?");
	 printf("\nType 0 for yes");
	 printf("\nType1 for no: ");
	 printf("\nEnter Your Choice : ");
	 int ch;
	 scanf("%d",&ch);
	 if(ch==0)
	 {
	 c:
	 printf("\nHow many rooms do you need");
	 printf("\nNote : You can have minimum of 1 room and a maximum of 4 rooms with 30USD per room : ");
	 printf("\nEnter Your Choice : ");
	 int r;
	 scanf("%d",&r);
	 switch (r)
	 {
	 	case 1:
	 		tc=tc+30;
	 		break;
	 	case 2:
	 		tc=tc+30*2;
	 		break;
	 	case 3:
	 		tc=tc+30*3;
	 		break;
	 	case 4:
	 		tc=tc+30*4;
	 		break;
	 	default:
	 		printf("Invalid Input Please Try Again:\n");
	 		goto c;
		    break;
	 }
	 }
	 return tc;
}
	
	
	
	//Existing Information
 	existing_account(struct data info)
	{
		FILE *f = fopen("finalrpoject.txt", "r");
   int c = getc(f);
   while (c != EOF) {
      putchar(c);
      c = getc(f);
   }
   fclose(f);
   getchar();
   return 0;
}




















// Introductory Function
void intro(){ 
    int flag;
    printf("\t\t\t\t\t-----------------------------------\t\t\n");
	printf("\t\t\t\t\t\tWelcome To Fast Travels\t\t\n");
	printf("\t\t\t\t\t-----------------------------------\t\t\n\n");
	printf("\nDo you want to make a new ticket or get details for an existing one?");
	printf("\nType 1 for new ticket");
	printf("\nType 2 for Getting Details Of Existing Account Existing Data");
	printf("\nEnter Your Choice : ");
	scanf("%d",&flag);
	if (flag==1)
	{
	information();
	} 
	else if (flag==2)
	{
	existing_account(info);
	exit(0);
	} 
	else 
	{
	printf("Invalid input");
	}
}



 
int main()
{   int bill,ticketcharges;
	intro();
	ticketcharges=ticket();
	existing_account(info);
	bill=hotel(ticketcharges);
	finalbill(bill);
}
