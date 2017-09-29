struct apt {
	string airportName;
	string iata;
	string icao;
	int established;
	string type;
	string location;
	string coordinates;
	int elevation;
	long long int aircrafts;
	long long int passengers;
	long long int cargo;
};

class airport {
public:
	apt AP;
	map <int,apt> APdatabase;
	int index, counter;
	string temp, cell;

	airport() {
		APdatabase= map<int,apt>();
		int mapindex;
		index = 0;
		counter= 0;
		ifstream in("data/airport.csv");
		getline(in, temp);
		while(getline(in, temp)) {
			stringstream lineStream(temp);
			getline(lineStream,cell,';');
			stringstream serial(cell);
			serial>>mapindex;
			getline(lineStream,AP.airportName,';');
			getline(lineStream,AP.iata,';');
			getline(lineStream,AP.icao,';');

			getline(lineStream,cell,';');
			stringstream dataone(cell);
			dataone>>AP.established;

			getline(lineStream,AP.type,';');
			getline(lineStream,AP.location,';');
			getline(lineStream,AP.coordinates,';');

			getline(lineStream,cell,';');
			stringstream datatwo(cell);
			datatwo>>AP.elevation;

			getline(lineStream,cell,';');
			stringstream datathree(cell);
			datathree>>AP.aircrafts;

			getline(lineStream,cell,';');
			stringstream datafour(cell);
			datafour>>AP.passengers;

			getline(lineStream,cell,';');
			stringstream datafive(cell);
			datafive>>AP.cargo;

			APdatabase[mapindex] = AP;
			index++;
			counter++;
		}
	}
	void airportInfo() {
		string searchTemp;
		cout<<"\t\033[1;36mENTER Name of AIRPORT / IATA Code of the Airport: \033[0m";
		cin>>searchTemp;
		clear();
		int counter = 0;
		for(map<int,apt>::iterator it=APdatabase.begin(); it!=APdatabase.end(); ++it) {
			apt AP = it->second;
			if(contains(AP.iata,searchTemp) || contains(AP.airportName,searchTemp)){
				//TABLE DECORATION START
				cout <<"+";
				for (int i = 0; i < 124; ++i)
					cout<<"—";
					cout<<"+\n";
				//END
				display(it->first);
				counter++;
				//TABLE DECORATION START
				cout <<"+";
				for (int i = 0; i < 124; ++i)
					cout<<"—";
					cout<<"+\n"<<endl;
				//END
			}
		}
		if(counter == 0) {
			cout<<"\t\t\033[1;31mNO SUCH AIRPORT EXISTS. PLEASE CHECK AGAIN. \033[0m"<<endl;
		}
	}

	void display(int airportNo) {
		apt AP = APdatabase[airportNo];

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Airport Name"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.airportName<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"International Air Transport Association Code"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.iata<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"International Civil Aviation Organization Code"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.icao<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Established"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.established<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Type of Airport"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.type<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Location"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.location<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Coordinates"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.coordinates<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Elevation above Sea Level"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.elevation<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Aircrafts Movement per Month"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.aircrafts<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Passengers Movement per Month"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.passengers<<"|"<<endl;

		cout <<"| "<< left << setw(50) << setfill(' ') <<"Cargo Tonnage per Month"<<" — ";
		cout << left << setw(70) << setfill(' ') << AP.cargo<<"|"<<endl;
	}
};