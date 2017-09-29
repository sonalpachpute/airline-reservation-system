//CONTAINS
bool contains(string a, string b){

	char *c= new char[100];
	char *d= new char[100];
	strcpy(c,a.c_str());
	strcpy(d,b.c_str());

	for(int k=0;k<a.size();k++){
		d[k]=tolower(d[k]);
		c[k]=tolower(c[k]);

	}
	if(strstr(c,d)==NULL)
		return false;
	else
		return true;

}
//CLEAR
void clear() {
	cout << string( 100, '\n' );
}
//TIME
#define formatTime "%H:%M"
#define sizeClockT 6
static char *getTime (char *buff) {
    time_t t = time (0);
    strftime (buff, sizeClockT, formatTime, localtime (&t));
    return buff;
}
//DATE
#define formatDate "%d/%m/%Y"
#define sizeClockD 20
static char *getDate (char *buff) {
    time_t t = time (0);
    strftime (buff, sizeClockD, formatDate, localtime (&t));
    return buff;
}
//PRN GENERATOR
string prnGenerator() {
	int random = rand();
	srand((int)time(0));

	int i = 0;
	string prn;
	while(i < 10) {
		int r = (rand()*random % 100) + 1;
		if(((r >= 65) && (r <= 90)) || ((r >= 48)&&(r <= 57))) {
			prn = prn + (char)r;
			i++;
		}
	}
	return prn;
}

//ASCII ART
void ascii() {
	cout<<"\n\t\033[1;32m+——————————————————————————————————————————————————————————————————————+\033[0m"<<endl;
	cout<<"\t\033[1;32m|                                                                      |\033[0m"<<endl;
	cout<<"\t\033[1;32m| o     o      .oo  o   o .oPYo. o     o o   o ooooo  .oPYo. o  .oPYo. |\033[0m"<<endl;
	cout<<"\t\033[1;32m| 8b   d8     .P 8  8  .P 8.     8b   d8 `b d'   8    8   `8 8  8    8 |\033[0m"<<endl;
	cout<<"\t\033[1;32m| 8`b d'8    .P  8 o8ob'  `boo   8`b d'8  `b'    8   o8YooP' 8 o8YooP' |\033[0m"<<endl;
	cout<<"\t\033[1;32m| 8 `o' 8   oPooo8  8  `b .P     8 `o' 8   8     8    8   `b 8  8      |\033[0m"<<endl;
	cout<<"\t\033[1;32m| 8     8  .P    8  8   8 8      8     8   8     8    8    8 8  8      |\033[0m"<<endl;
	cout<<"\t\033[1;32m| 8     8 .P     8  8   8 `YooP' 8     8   8     8    8    8 8  8      |\033[0m"<<endl;
	cout<<"\t\033[1;32m|                                                                      |\033[0m"<<endl;
	cout<<"\t\033[1;32m+—————————————— JUST ANOTHER AIRLINE RESERVATION SYSTEM ———————————————+\033[0m\n\n"<<endl;
	//cout << "\033[1;31mbold red text\033[0m\n";
}

//ABOUT
void about() {
	cout<<"\n\t\033[1;32mMADE BY:\033[0m\n"<<endl;
	cout<<"\t\033[1;33mASHWIN PATIL   — 3162081 \033[0m"<<endl;
	cout<<"\t\033[1;33mSUSHRUT PATIL  — 3162083"<<endl;
	cout<<"\t\033[1;33mSONAL PACHPUTE — 3162073"<<endl;
	cout<<"\t\033[1;33mSAREEN SHAH    — 3162098\n\n"<<endl;
}