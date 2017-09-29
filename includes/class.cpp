#include "functions.cpp"	//FUNCTIONS
#include "query.cpp"	//IATA SHORTCODES
#include "airport.cpp"	//AIRPORT INFO

struct flight {
	int flightNo;
	string airlineName;
	string aeroplaneMake;
	string from;
	string to;
	string depart;
	string arrival;
	float costPerTicket;
	int capacity;
	int available;
};

//AIRLINE CLASS
class airline {
	//AIRLINE DATA MEMBERS
public:
	flight F;
	map <int,flight> Fdatabase;
	int index, counter;
	string temp, cell;
	airline() {
		Fdatabase= map<int,flight>();
		int mapindex;
		index = 0;
		ifstream in("data/flight.csv");
		getline(in, temp);
		while(getline(in, temp)) {
			stringstream lineStream(temp);
			getline(lineStream,cell,';');
			stringstream serial(cell);
			serial>>mapindex;
			getline(lineStream,F.airlineName,';');
			getline(lineStream,F.aeroplaneMake,';');
			getline(lineStream,F.from,';');
			getline(lineStream,F.to,';');
			getline(lineStream,F.depart,';');
			getline(lineStream,F.arrival,';');
			getline(lineStream,cell,';');
			stringstream dataone(cell);
			dataone>>F.costPerTicket;
			getline(lineStream,cell,';');
			stringstream datatwo(cell);
			datatwo>>F.capacity;
			getline(lineStream,cell,';');
			stringstream datathree(cell);
			datathree>>F.available;
			Fdatabase[mapindex] = F;
			index++;
		}
	}
	//AIRLINE MEMBER FUNCTIONS
	void searchFlightByDest(string A, string B) {
		clear();
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(10) << setfill(' ') <<"AIRLINE"<<"| ";
		cout <<left << setw(18)  << setfill(' ') <<"MAKE"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"FROM"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"TO"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"DEP"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"ARR"<<"| ";
		cout <<left << setw(7)  << setfill(' ') <<"COST"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"CAPACITY"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"AVAILABLE"<<"| "<<endl;
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		int counter = 0;
		for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
			flight F = it->second;
			if(contains(F.from,B) && contains(F.to,A)){
				display(it->first);
				counter++;
			}
		}
		if(counter == 0) {
			cout<<"|"<<left << setw(102)  << setfill(' ') <<"\t\t\033[1;31m        NO SUCH FLIGHT EXISTS. PLEASE CHECK AGAIN. \033[0m"<<"|"<<endl;
		}
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+\n"<<endl;
		//END
		cout<<"— "<<counter<<" Results "<<endl;
	}


	void searchFlightByNo(long long int A) {
		clear();
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(10) << setfill(' ') <<"AIRLINE"<<"| ";
		cout <<left << setw(18)  << setfill(' ') <<"MAKE"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"FROM"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"TO"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"DEP"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"ARR"<<"| ";
		cout <<left << setw(7)  << setfill(' ') <<"COST"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"CAPACITY"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"AVAILABLE"<<"| "<<endl;
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		int counter = 0;
		for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
			if(A == it -> first){
				display(it->first);
				counter++;
			}
		}
		if(counter == 0) {
			cout<<"|"<<left << setw(102)  << setfill(' ') <<"\t\t\033[1;31m        NO SUCH FLIGHT EXISTS. PLEASE CHECK AGAIN. \033[0m"<<"|"<<endl;
		}
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+\n"<<endl;
		//END
		cout<<"— "<<counter<<" Results "<<endl;
	}

	void searchFlightByAirline(string A) {
		clear();
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(10) << setfill(' ') <<"AIRLINE"<<"| ";
		cout <<left << setw(18)  << setfill(' ') <<"MAKE"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"FROM"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"TO"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"DEP"<<"| ";
		cout <<left << setw(5)  << setfill(' ') <<"ARR"<<"| ";
		cout <<left << setw(7)  << setfill(' ') <<"COST"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"CAPACITY"<<"| ";
		cout <<left << setw(10)  << setfill(' ') <<"AVAILABLE"<<"| "<<endl;
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+"<<endl;
		// END
		int counter = 0;
		for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
			flight F = it->second;
			if(contains(F.airlineName,A)){
				display(it->first);
				counter++;
			}
		}
		if(counter == 0) {
			cout<<"|"<<left << setw(102)  << setfill(' ') <<"\t\t\033[1;31m        NO SUCH FLIGHT EXISTS. PLEASE CHECK AGAIN. \033[0m"<<"|"<<endl;
		}
		//TABLE DECORATION START
		cout <<"+";
		for (int i = 0; i < 104; ++i)
			cout<<"—";
		cout<<"+\n"<<endl;
		//END
		cout<<"— "<<counter<<" Results "<<endl;
	}
	void display(int airno){
		flight F = Fdatabase[airno];
		cout <<"| "<< left << setw(10) << setfill(' ') <<airno<<"| ";
		cout << left << setw(10) << setfill(' ') << F.airlineName<<"| ";
		cout << left << setw(18)  << setfill(' ') << F.aeroplaneMake <<"| ";
		cout << left << setw(5)  << setfill(' ') << F.from <<"| ";
		cout << left << setw(5)  << setfill(' ') << F.to <<"| ";
		cout << left << setw(5)  << setfill(' ') << F.depart <<"| ";
		cout << left << setw(5)  << setfill(' ') << F.arrival <<"| ";
		cout << left << setw(5)  << setfill(' ') << F.costPerTicket <<"₹ "<<"| ";
		cout << left << setw(10)  << setfill(' ') << F.capacity <<"| ";
		cout << left << setw(10)  << setfill(' ') << F.available <<"| "<< endl;
	}
};

//TICKET BOOKING

struct ticket {
	long long int refNo;
	long long int flightNo;
	string firstName;
	string lastName;
	string prn;
	string date;
	string sex;
	string flightClass;
};

class booking : public airline {
public:
	ticket T;
	map <int,ticket> Tdatabase;
	int index, counter;
	string temp, cell;
	booking() {
		//GET ALL TICKET INFO
		Tdatabase = map<int,ticket>();
		int mapindex;
		index = 0;
		ifstream inT("data/tickets.csv");
		getline(inT, temp);
		while(getline(inT, temp)) {
			stringstream lineStream(temp);
			getline(lineStream,cell,';');
			stringstream serial(cell);
			serial>>mapindex;

			getline(lineStream,cell,';');
			stringstream dataone(cell);
			dataone>>T.flightNo;

			getline(lineStream,T.firstName,';');
			getline(lineStream,T.lastName,';');
			getline(lineStream,T.prn,';');
			getline(lineStream,T.date,';');
			getline(lineStream,T.sex,';');
			getline(lineStream,T.flightClass,';');
			Tdatabase[mapindex] = T;
			index++;
		}

		//GET FLIGHT INFO
		Fdatabase= map<int,flight>();
		index = 0;
		ifstream inF("data/flight.csv");
		getline(inF, temp);
		while(getline(inF, temp)) {
			stringstream lineStream(temp);
			getline(lineStream,cell,';');
			stringstream serial(cell);
			serial>>mapindex;
			getline(lineStream,F.airlineName,';');
			getline(lineStream,F.aeroplaneMake,';');
			getline(lineStream,F.from,';');
			getline(lineStream,F.to,';');
			getline(lineStream,F.depart,';');
			getline(lineStream,F.arrival,';');
			getline(lineStream,cell,';');
			stringstream dataone(cell);
			dataone>>F.costPerTicket;
			getline(lineStream,cell,';');
			stringstream datatwo(cell);
			datatwo>>F.capacity;
			getline(lineStream,cell,';');
			stringstream datathree(cell);
			datathree>>F.available;
			Fdatabase[mapindex] = F;
			index++;
		}
	}
	void displayTicket(long long int refNo){
		ticket T = Tdatabase[refNo];
		cout<<"\t\t\tTICKET DETAILS \n"<<endl;

		cout<<"\t+";
		for(int i = 0; i<46;i++)
			cout<<"—";
		cout<<"+\n";

		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"NAME: "<< left << setw(15) << setfill(' ') <<T.lastName<< left << setw(15) << setfill(' ') <<T.firstName<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"PRN: "<< left << setw(30) << setfill(' ') <<T.prn<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"CARRIER: "<< left << setw(30) << setfill(' ') <<F.airlineName<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"FLIGHT NO.: "<< left << setw(30) << setfill(' ') <<T.flightNo<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"SEAT.: "<< left << setw(30) << setfill(' ') <<"UNASSIGNED"<<"| "<< endl;

		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"DATE: "<< left << setw(30) << setfill(' ') <<T.date<<"| "<< endl;

		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"FROM: "<< left << setw(30) << setfill(' ') <<F.from<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"DESTINATION: "<< left << setw(30) << setfill(' ') <<F.to<<"| "<< endl;

		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"DEPARTURE: "<< left << setw(30) << setfill(' ') <<F.depart<<"| "<< endl;
		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"ARRIVAL: "<< left << setw(30) << setfill(' ') <<F.arrival<<"| "<< endl;

		cout<<"\t| "<< left << setw(15) << setfill(' ') <<"CLASS: "<< left << setw(30) << setfill(' ') <<T.flightClass<<"| "<< endl;

		cout<<"\t+";
		for(int i = 0; i<46;i++)
			cout<<"—";
		cout<<"+\n\n";
	}

	void downloadTicket(long long int refNo) {
		ticket T = Tdatabase[refNo];
		for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
			if(it -> first == T.flightNo){
				flight F = it->second;
			}
		}

		fstream out;
		const string fName = "mTicket_" + T.prn +".txt";
		cout<<"\t\033[1;32mTicket Downloaded in PROGRAM FOLDER with Name: "<<fName<<"\n"<<endl;
		const char* fileName = fName.c_str();
		out.open(fileName,fstream::out);

		out<<"\n\t+——————————————————————————————————————————————————————————————————————+"<<endl;
		out<<"\t|                                                                      |"<<endl;
		out<<"\t| o     o      .oo  o   o .oPYo. o     o o   o ooooo  .oPYo. o  .oPYo. |"<<endl;
		out<<"\t| 8b   d8     .P 8  8  .P 8.     8b   d8 `b d'   8    8   `8 8  8    8 |"<<endl;
		out<<"\t| 8`b d'8    .P  8 o8ob'  `boo   8`b d'8  `b'    8   o8YooP' 8 o8YooP' |"<<endl;
		out<<"\t| 8 `o' 8   oPooo8  8  `b .P     8 `o' 8   8     8    8   `b 8  8      |"<<endl;
		out<<"\t| 8     8  .P    8  8   8 8      8     8   8     8    8    8 8  8      |"<<endl;
		out<<"\t| 8     8 .P     8  8   8 `YooP' 8     8   8     8    8    8 8  8      |"<<endl;
		out<<"\t|                                                                      |"<<endl;
		out<<"\t+—————————————— JUST ANOTHER AIRLINE RESERVATION SYSTEM ———————————————+\n\n"<<endl;
		out<<"\t                            BOARDING PASS\n\n"<<endl;

		out<<"\tPASSENGER NAME: "<<T.lastName<<" "<<T.firstName<<endl;
		out<<"\tPRN: "<<T.prn<<endl;
		out<<"\tCARRIER: "<<F.airlineName<<endl;
		out<<"\tFLIGHT NO.: "<<T.flightNo<<endl;
		out<<"\tSEAT.: "<<"UNASSIGNED"<<"\n"<<endl;

		out<<"\n\tDATE:"<<T.date<<"\n"<<endl;

		out<<"\tFROM: "<<F.from<<endl;
		out<<"\tDESTINATION: "<<F.to<<"\n"<<endl;

		out<<"\tDEPARTURE: "<<F.depart<<endl;
		out<<"\tARRIVAL: "<<F.arrival<<endl;

		out<<"\tCLASS: "<<T.flightClass<<endl;

		out<<"\n\n\t+——————————————————————————— HAPPY JOURNEY ————————————————————————————+\n\n"<<endl;

	}

	void viewTicketsByName() {
		string search;
		ascii();
		cout<<"\t\033[1;36mSearching Database by Name,\n\tEnter Search Query: \033[0m";
		cin>>search;
		clear();
		int ct = 0;
		//HEADER
		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END

		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(15) << setfill(' ') <<"CARRIER"<<"| ";
		cout << left << setw(10) << setfill(' ') <<"FIRST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "LAST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "PRN"<<"| ";
		cout << left << setw(10) << setfill(' ') << "DATE"<<"| ";
		cout << left << setw(5) << setfill(' ') << "SEX"<<"| ";
		cout << left << setw(20) << setfill(' ') << "CLASS"<<"| "<<endl;

		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END
		flight F;
		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
			ticket T = it->second;
			for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
				if(it -> first == T.flightNo) {
					F = it->second;
					break;
				}
			}

			if (contains(T.firstName+T.lastName,search)) {
				ct++;
				cout <<"| "<< left << setw(10) << setfill(' ') << T.flightNo<<"| ";
				cout << left << setw(15) << setfill(' ') << F.airlineName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.firstName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.lastName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.prn<<"| ";
				cout << left << setw(10) << setfill(' ') << T.date<<"| ";
				cout << left << setw(5) << setfill(' ') << T.sex<<"| ";
				cout << left << setw(20) << setfill(' ') << T.flightClass<<"| "<<endl;
			}
		}
		if (ct == 0) {
			cout<<"| "<< left << setw(91) <<"\t\t\033[1;31m        NO RESULTS TO DISPLAY\033[0m"<<"|"<<endl;
		}
		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END
		cout<<"\n— "<<ct<<" Results "<<endl;
	}

	void viewTicketsByCarrier() {
		string search;
		ascii();
		cout<<"\t\033[1;36mSearching Database by Carrier,\n\tEnter Search Query: \033[0m";
		cin>>search;
		clear();
		int ct = 0;
		clear();
		//HEADER
		//START
		cout<<"+";
		for(int i = 0; i < 106;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END

		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(16) << setfill(' ') <<"CARRIER"<<"| ";
		cout << left << setw(10) << setfill(' ') <<"FIRST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "LAST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "PRN"<<"| ";
		cout << left << setw(10) << setfill(' ') << "DATE"<<"| ";
		cout << left << setw(5) << setfill(' ') << "SEX"<<"| ";
		cout << left << setw(20) << setfill(' ') << "CLASS"<<"| "<<endl;

		//START
		cout<<"+";
		for(int i = 0; i < 106;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END

		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
			ticket T = it->second;
			flight F;
			for(map<int,flight>::iterator itone=Fdatabase.begin(); itone!=Fdatabase.end(); ++itone){
				if(itone -> first == T.flightNo){
					F = itone->second;
					break;
				}
			}

			if (contains(F.airlineName,search)) {
				ct++;
				cout <<"| "<< left << setw(10) << setfill(' ') << T.flightNo<<"| ";
				cout << left << setw(16) << setfill(' ') << F.airlineName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.firstName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.lastName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.prn<<"| ";
				cout << left << setw(10) << setfill(' ') << T.date<<"| ";
				cout << left << setw(5) << setfill(' ') << T.sex<<"| ";
				cout << left << setw(20) << setfill(' ') << T.flightClass<<"| "<<endl;
			}
		}
		if (ct == 0) {
			cout<<"| "<< left << setw(92) <<"\t\t\033[1;31m        NO RESULTS TO DISPLAY\033[0m"<<"|"<<endl;
		}
		//START
		cout<<"+";
		for(int i = 0; i < 106;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END
		cout<<"\n— "<<ct<<" Results "<<endl;
	}

	void viewTicketsByFlightNo() {
		string search;
		ascii();
		cout<<"\t\033[1;36mSearching Database by Flight No.,\n\tEnter Search Query: \033[0m";
		cin>>search;
		int ct = 0;
		clear();
		//HEADER
		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END

		cout <<"| "<< left << setw(10) << setfill(' ') <<"FLIGHT NO."<<"| ";
		cout << left << setw(15) << setfill(' ') <<"CARRIER"<<"| ";
		cout << left << setw(10) << setfill(' ') <<"FIRST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "LAST NAME"<<"| ";
		cout << left << setw(10) << setfill(' ') << "PRN"<<"| ";
		cout << left << setw(10) << setfill(' ') << "DATE"<<"| ";
		cout << left << setw(5) << setfill(' ') << "SEX"<<"| ";
		cout << left << setw(20) << setfill(' ') << "CLASS"<<"| "<<endl;

		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END
		flight F;
		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
			ticket T = it->second;
			for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
				if(it -> first == T.flightNo){
					F = it->second;
				}
			}

			//UNCONVENTIONAL WAY TO CONVERT LONG LONG INT TO STRING // TO_STRING DOESN'T SEEM TO WORK
			std::ostringstream ss;
			ss << T.flightNo;
			std::string result = ss.str();

			if (contains(result,search) && (search.length() == 4)) {
				ct++;
				cout <<"| "<< left << setw(10) << setfill(' ') << T.flightNo<<"| ";
				cout << left << setw(15) << setfill(' ') << F.airlineName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.firstName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.lastName<<"| ";
				cout << left << setw(10) << setfill(' ') << T.prn<<"| ";
				cout << left << setw(10) << setfill(' ') << T.date<<"| ";
				cout << left << setw(5) << setfill(' ') << T.sex<<"| ";
				cout << left << setw(20) << setfill(' ') << T.flightClass<<"| "<<endl;
			}
		}
		if (ct == 0) {
			cout<<"| "<< left << setw(91) <<"\t\t\033[1;31m        NO RESULTS TO DISPLAY\033[0m"<<"|"<<endl;
		}
		//START
		cout<<"+";
		for(int i = 0; i < 105;i++) {
			cout<<"—";
		}
		cout<<"+"<<endl;
		//END
		cout<<"\n— "<<ct<<" Results "<<endl;
	}

	int bookTicket(int flightNo);
};
#include "booking.cpp"
#include "sort.cpp"