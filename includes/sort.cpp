class sortTickets : public airline {
public:
	ticket T;
	map <int,ticket> Tdatabase;
	int index, counter;
	string temp, cell;
	sortTickets() {
		//GET ALL TICKET INFO
		Tdatabase = map<int,ticket>();
		int mapindex;
		index = 0;
		ifstream in("data/tickets.csv");
		getline(in, temp);
		while(getline(in, temp)) {
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
	}

	void sortByFlightA() {
		vector<int> v;
		vector<bool> hash(100000,false);
		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it){
			ticket T = it->second;
			if(!hash[T.flightNo]) {
				v.push_back(T.flightNo);
				hash[T.flightNo] = true;
			}
		}

		sort(v.begin(),v.end());

		fstream out;
		out.open("data/tickets.csv",fstream::out);
		out<<"REF NO.;FLIGHT NO.;FIRST NAME;LAST NAME;PRN;SEX;CLASS"<<endl;
		for(int i = 0; i < v.size();i++) {
			for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
				ticket T = it->second;
				if (T.flightNo == v[i]) {
					out<<it->first<<";"<<T.flightNo<<";"<<T.firstName<<";"<<T.lastName<<";"<<T.prn<<";"<<T.date<<";"<<T.sex<<";"<<T.flightClass<<endl;
				}
			}
		}
	}


	void sortByFlightD() {
		vector<int> v;
		vector<bool> hash(100000,false);
		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it){
			ticket T = it->second;
			if(!hash[T.flightNo]) {
				v.push_back(T.flightNo);
				hash[T.flightNo] = true;
			}
		}

		sort(v.rbegin(),v.rend());

		fstream out;
		out.open("data/tickets.csv",fstream::out);
		out<<"REF NO.;FLIGHT NO.;FIRST NAME;LAST NAME;PRN;SEX;CLASS"<<endl;
		for(int i = 0; i < v.size();i++) {
			for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
				ticket T = it->second;
				if (T.flightNo == v[i]) {
					out<<it->first<<";"<<T.flightNo<<";"<<T.firstName<<";"<<T.lastName<<";"<<T.prn<<";"<<T.date<<";"<<T.sex<<";"<<T.flightClass<<endl;
				}
			}
		}
	}

	void cancelTicket(string prn) {
		vector<int> v;
		vector<bool> hash(100000,false);
		for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it){
			ticket T = it->second;
			if(!hash[T.flightNo]) {
				v.push_back(T.flightNo);
				hash[T.flightNo] = true;
			}
		}

		sort(v.begin(),v.end());

		fstream out;
		out.open("data/tickets.csv",fstream::out);
		out<<"REF NO.;FLIGHT NO.;FIRST NAME;LAST NAME;PRN;SEX;CLASS"<<endl;
		for(int i = 0; i < v.size();i++) {
			for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
				ticket T = it->second;
				if (T.flightNo == v[i] && !contains(T.prn,prn)) {
					out<<it->first<<";"<<T.flightNo<<";"<<T.firstName<<";"<<T.lastName<<";"<<T.prn<<";"<<T.date<<";"<<T.sex<<";"<<T.flightClass<<endl;
				}
			}
		}
	}
};