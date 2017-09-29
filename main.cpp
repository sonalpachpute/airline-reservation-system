#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <map>
#include <iterator>
#include <sstream>
#include <string>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;

#include "includes/class.cpp"
#include "includes/admin.cpp"

void checkFlight();
void preBookFlight();
void exportTicket(int refNo);


//MAIN FUNCTION TO GENERATE MENU FOR THE PROGRAM
int main() {
	char time[sizeClockT];
	char date[sizeClockD];
	airline A;
	booking B;
	query Q;
	airport AP;
	sortTickets S;
	clear();
	while(true) {
		int ch;
		ascii();
		cout<<"\n\t1. Check Flight \n\t2. Book Flight \n\t3. Check Ticket \n\t4. Cancel Booking \n\t5. Check Airport Codes \n\t6. Check Airport Info. \n\t8. Admin Menu \n\t9. About\n\t0. EXIT"<<endl;
		cout<<"\n\t\033[1;36mCurrent Date and Time: "<<getDate(date)<<" "<<getTime(time)<<"\033[0m"<<endl;

		cout<<"\n\tENTER: ";
		cin>>ch;
		clear();
		switch(ch) {
			case 1: { //CHECK FLIGHT
				checkFlight();
				break;
			}
			case 2: { //BOOK FLIGHT
				preBookFlight();
				clear();
				ascii();
				int fno;
				cout<<"\n\t\033[1;36mEnter Flight No. to Proceed: ";
				cin>>fno;
				int refNo = B.bookTicket(fno);
				if(refNo != -1)
					exportTicket(refNo);
				break;
			}
			case 3: { //CHECK TICKET DETAILS
				bool flag = true;
				long long int refNo;
				while(flag) {
					string a;
					ascii();
					cout<<"\n\t\033[1;36mPlease Enter Your 10 Digit Alpha-Numeric PRN CODE: \033[0m";
					cin>>a;
					clear();
					for(map<int,ticket>::iterator it=B.Tdatabase.begin(); it!=B.Tdatabase.end(); ++it){
						ticket T = it->second;
						if(contains(T.prn,a) && (a.length() == 10)){
							B.displayTicket(it->first);
							refNo = it -> first;
							flag = false;
						}
					}
					if(!flag) {
						cout<<"\n\tDo You Want to Download this Ticket? Y/N: ";
						char choice;
						cin>>choice;
						clear();
						if (choice == 'y' || choice == 'Y') {
							B.downloadTicket(refNo);
						}
						int ch;
						cout<<"\n\t1. Previous Menu \n\t0. Exit\n\n\tENTER: ";
						cin>>ch;
						if(ch == 0) {
							return 0;
						}
					}
					else {
						cout<<"\tPlease Enter a Valid PRN Code\n"<<endl;
					}
				}
				break;
			}
			case 4: { //CANCEL FLIGHT
				bool flag = true;
				string prn;
				while(flag) {
					string a;
					ascii();
					cout<<"\tPlease Enter Your 10 Digit Alpha-Numeric PRN CODE: ";
					cin>>a;
					clear();
					for(map<int,ticket>::iterator it=B.Tdatabase.begin(); it!=B.Tdatabase.end(); ++it){
						ticket T = it->second;
						if(contains(T.prn,a) && (a.length() == 10)){
							B.displayTicket(it->first);
							prn = T.prn;
							flag = false;
						}
					}
					if(!flag) {
						cout<<"\n\t\033[1;31mDo You Want to Cancel this Ticket? Y/N: ";
						char choice;
						cin>>choice;
						clear();
						if (choice == 'y' || choice == 'Y') {
							S.cancelTicket(prn);
						}
						int ch;
						cout<<"\t\033[1;32mTicket Cancelled."<<endl;
						cout<<"\n\t1. Previous Menu \n\t0. Exit\n\n\tENTER: ";
						cin>>ch;
						if(ch == 0) {
							return 0;
						}
					}
					else {
						cout<<"\t\033[1;31mPlease Enter a Valid PRN Code\n"<<endl;
					}
				}
				break;
			}
			case 5: { //CHECK AIRPORT CODES
				Q.IATA();
				break;
			}
			case 6: { //CHECK AIRPORT INFO
				AP.airportInfo();
				break;
			}
			case 8: { //ADMIN MENU
				admin();
				break;
			}
			case 9: { //ABOUT THE MINI PROJECT
				about();
				break;
			}
			case 0: { //EXIT
				exit(0);
			}
		}
	}
}

void checkFlight() { // CHECK FLIGHT FUNCTION -- CALLED THROUGHT ABOVE SWITCH CASE.
	airline A;
	int choice;
	while (true) {
		ascii();
		cout<<"\tSEARCH: \n\t1. By Destination \n\t2. By Flight No. \n\t3. By Airline \n\t0. Return to Previous Menu \n\n\tENTER: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				string a,b;
				cout<<"\n\t\033[1;36mPlease Enter Boarding Airport: \033[0m";
				cin>>b;
				cout<<"\t\033[1;36mPlease Enter Destination Airport: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByDest(a,b);
				break;
			}
			case 2: {
				int a;
				cout<<"\n\t\033[1;36mPlease Enter Flight No.: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByNo(a);
				break;
			}
			case 3: {
				string a;
				cout<<"\n\t\033[1;36mPlease Enter Airline Name: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByAirline(a);
				break;
			}
			case 0: {
				main();
			}
			default: clear();
		}
	}
}

void preBookFlight() {
	airline A;
	int choice;
	bool flag = true;
	while (flag) {
		ascii();
		cout<<"\tSEARCH: \n\t1. By Destination \n\t2. By Flight No. \n\t3. By Airline \n\t9. Proceed to Book Ticket \n\t0. Return to Previous Menu \n\n\tENTER: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				string a,b;
				cout<<"\n\t\033[1;36mPlease Enter Boarding Airport: \033[0m";
				cin>>b;
				cout<<"\t\033[1;36mPlease Enter Destination Airport: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByDest(a,b);
				break;
			}
			case 2: {
				int a;
				cout<<"\n\t\033[1;36mPlease Enter Flight No.: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByNo(a);
				break;
			}
			case 3: {
				string a;
				cout<<"\n\t\033[1;36mPlease Enter Airline Name: \033[0m";
				cin>>a;
				clear();
				A.searchFlightByAirline(a);
				break;
			}
			case 9: {
				flag = false;
				break;
			}
			case 0: {
				main();
				break;
			}
			default: clear();
		}
	}
}

void exportTicket(int refNo) {
	booking BO;
	BO.downloadTicket(refNo);
}