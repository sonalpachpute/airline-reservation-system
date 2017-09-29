void listPassengers() {
	booking B;
	int listch;
	while(true) {
		ascii();
		cout<<"\n\tList Passengers, \n\t1. By Name  \n\t2. By Airplane Carrier \n\t3. By Flight No. \n\t0. EXIT \n\n\tENTER: ";
		cin>>listch;
		clear();
		switch(listch) {
			case 1: {
				B.viewTicketsByName();
				break;
			}
			case 2: {
				B.viewTicketsByCarrier();
				break;
			}
			case 3: {
				B.viewTicketsByFlightNo();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}

void sortDatabase() {
	sortTickets S;
	int listch;
	while(true) {
		ascii();
		cout<<"\n\tSort Tickets by Flight No., \n\t1. In Ascending Order  \n\t2. In Descending Order \n\t0. EXIT \n\n\tENTER: ";
		cin>>listch;
		clear();
		switch(listch) {
			case 1: {
				S.sortByFlightA();
				cout<<"\n\t\033[1;32mSorted Ticket Database in Ascending Order!\n"<<endl;
				break;
			}
			case 2: {
				S.sortByFlightD();
				cout<<"\n\t\033[1;32mSorted Ticket Database in Descending Order!\n"<<endl;
				break;
			}
			case 0: {
				return;
			}
		}
	}
}

void admin() {
	int adminCH;
	while(true) {
		ascii();
		cout<<"\n\t1. List Passengers \n\t2. Sort Ticket Database \n\t0. EXIT \n\tENTER: ";
		cin>>adminCH;
		clear();
		switch(adminCH) {
			case 1: {
				listPassengers();
				break;
			}
			case 2: {
				sortDatabase();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}