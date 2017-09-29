// IATA - International Air Transport Association
struct searchIATA {
	string airportName;
	string iata;
};

class query {
public:
	searchIATA S;
	map <int,searchIATA> Idatabase;
	int index, counter;
	string temp, cell;
	//BOOKING MEMBER FUNCTIONS

	query() {
		Idatabase= map<int,searchIATA>();
		int mapindex;
		index = 0;
		counter= 0;
		ifstream in("data/iata.csv");
		getline(in, temp);
		while(getline(in, temp)) {
			stringstream lineStream(temp);
			getline(lineStream,cell,';');
			stringstream serial(cell);
			serial>>mapindex;
			getline(lineStream,S.airportName,';');
			getline(lineStream,S.iata,';');
			Idatabase[mapindex] = S;
			index++;
			counter++;
		}
	}

	void IATA() {
		while (true) {
			int choice;
			ascii();
			cout<<"\n\t1. Airport / City -> IATA Code \n\t2. IATA Code -> Airport \n\t0. Return to Previous Menu \n\n\tENTER: ";
			cin>>choice;
			clear();
			switch(choice) {
				case 1: { //AIRPORT / CITY -> IATA
					string searchTemp;
					int counter = 0;
					ascii();
					cout<<"\t\033[1;36mENTER Name of City / Airport: ";
					cin>>searchTemp;
					clear();
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+"<<endl;
					// END
					cout <<"| "<< left << setw(70) << setfill(' ') <<"AIRPORT NAME"<<"| ";
					cout <<left << setw(10)  << setfill(' ') <<"IATA"<<"| "<< endl;
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+"<<endl;
					// END
					for(map<int,searchIATA>::iterator it=Idatabase.begin(); it!=Idatabase.end(); ++it){
						searchIATA c = it->second;
						if(contains(c.airportName,searchTemp)){
							display(it->first);
							counter++;
						}
					}
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+\n"<<endl;
					//END
					cout<<"\t— "<<counter<<" Results "<<endl;
					break;
				}
				case 2: { // IATA -> AIRPORT AND CITY
					string searchTemp;
					int counter = 0;
					ascii();
					cout<<"\t\033[1;36mENTER IATA Code: ";
					cin>>searchTemp;
					clear();
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+"<<endl;
					// END
					cout <<"| "<< left << setw(70) << setfill(' ') <<"AIRPORT NAME"<<"| ";
					cout <<left << setw(10)  << setfill(' ') <<"IATA"<<"| "<< endl;
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+"<<endl;
					// END
					for(map<int,searchIATA>::iterator it=Idatabase.begin(); it!=Idatabase.end(); ++it){
						searchIATA c = it->second;
						if(contains(c.iata,searchTemp)){
							display(it->first);
							counter++;
						}
					}
					//TABLE DECORATION START
					cout <<"+";
					for (int i = 0; i < 83; ++i)
						cout<<"-";
					cout<<"+\n"<<endl;
					// END
					break;
				}
				case 0: { //RETURN TO PREVIOUS MENU
					return;
				}
			}
		}
	}

	void display(int refno){
		searchIATA c = Idatabase[refno];
		cout <<"| "<< left << setw(70) << setfill(' ') << c.airportName<<"| ";
		cout <<left << setw(10)  << setfill(' ') << c.iata <<"| "<< endl;
	}
};