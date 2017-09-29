int booking :: bookTicket(int flightNo) {
	booking BK;
	int cost, refNo = -1;
	bool flag = false;
	for(map<int,ticket>::iterator it=Tdatabase.begin(); it!=Tdatabase.end(); ++it) {
		ticket T = it->second;
		for(map<int,flight>::iterator it=Fdatabase.begin(); it!=Fdatabase.end(); ++it){
			if(it -> first == T.flightNo){
				flight F = it->second;
			}
		}
		if(T.flightNo == flightNo) {
			flag = true;

			T.flightNo = flightNo;
			T.prn = prnGenerator();
			cout<<"\tEnter First Name: ";
			cin>>T.firstName;
			cout<<"\tEnter Last Name: ";
			cin>>T.lastName;

			for(int i = 0; i < T.firstName.length(); i++) {
				T.firstName[i] = toupper(T.firstName[i]);
			}
			for(int i = 0; i < T.lastName.length(); i++) {
				T.lastName[i] = toupper(T.lastName[i]);
			}

			bool loop = true;
			while (loop) {
				try {
					string sex;
					cout<<"\t\033[1;36mEnter Gender (M/F): ";
					cin>>sex;
					if(sex != "M" && sex != "F") {
						throw "Invalid Entry!";
					}
					else {
						T.sex = sex;
						loop = false;
					}
				}
				catch (char const *msg) {
					cout<<"\n\t\033[1;31m"<<msg<<"\n\033[0m"<<endl;
				}
			}
			loop = true;
			while (loop) {
				try {
					char date[10];
					cout<<"\t\033[1;36mEnter Date of Journey (MM/DD/YYYY): ";
					cin>>date;

					struct tm TIME;
					int year = (date[7] - '0')*1000 + (date[8] - '0')*100 + (date[9] - '0')*10 + (date[10] - '0');
					int month = (date[4] - '0')*10 + (date[5] - '0');
					if (!strptime(date, "%d/%m/%Y", &TIME) && !(year >= 2017) && !(month >= 9)) {
						throw "Invalid Date! Required format is MM/DD/YYYY";
					} else {
						T.date = date;
						loop = false;
					}
				}
				catch (char const *msg) {
					cout<<"\n\t\033[1;31m"<<msg<<"\n\033[0m"<<endl;
				}
			}


			int cls;
			cout<<"\n\tSELECT,\n\t1. Business — "<<F.costPerTicket*2<<" ₹"<<"\n\t2. Premium Economy — "<<F.costPerTicket*1.5<<" ₹"<<"\n\t3. Economy — "<<F.costPerTicket<<" ₹"<<" \n\tENTER: ";
			cin>>cls;
			top:
			switch(cls) {
				case 1: {
					T.flightClass = "BUSINESS";
					cost = F.costPerTicket*2;
					break;
				}
				case 2: {
					T.flightClass = "PREMIUM ECONOMY";
					cost = F.costPerTicket*1.5;
					break;
				}
				case 3: {
					T.flightClass = "ECONOMY";
					cost = F.costPerTicket;
					break;
				}
				default: {
					goto top;
				}
			}

			ofstream out;
  			out.open("data/tickets.csv", std::ios_base::app);
  			refNo = rand()%1000000;
  			out << endl << refNo <<";"<< T.flightNo <<";"<< T.firstName <<";"<< T.lastName <<";"<< T.prn <<";"<<T.date<<";"<< T.sex <<";"<< T.flightClass;
  			cout<<"\n\t\t\033[1;32mPLEASE PAY "<<cost<<" ₹ AT THE PAYMENT COUNTER!\033[0m"<<endl;
  			return refNo;
		}
	}
	if (!flag) {
		cout<<"\n\t\t\033[1;31mNO SUCH FLIGHT EXISTS. PLEASE CHECK AGAIN. \033[0m"<<endl;
		return -1;
	}
}