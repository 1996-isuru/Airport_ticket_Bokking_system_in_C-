#include<iostream>
#include<conio.h>
#include<fstream>
#include<bits/stdc++.h>
#include<string.h>
#include<sstream>
#include<cstring>
using namespace std;

int c;

 	struct flightSeat{
	              string seatRow;
	              string seatClass;
	              string seatName;
	
};
	 		 
class flight{
	 public:	
		struct flightSeat k [150];
	 	string flight_number;
	 	string date;
	 	string depature_airport;
	 	string arrival_airport;
	 	int numberofrow;
	 	int numberofeseats;
	 	int numberofbseats;
	 	  
		   flight(){
		   }
		 
	    flight(string flightnum,string dt,string depatr,string arrvl,struct flightSeat r[],int h,int eeseats,int bbseats)
		{
	    	flight_number = flightnum;
	    	date = dt;
	    	depature_airport = depatr;
	    	arrival_airport = arrvl;
	    	numberofrow = h;
	    	numberofeseats = eeseats;
	    	numberofbseats = bbseats;
	    	int i = 0;
	    	while(i!=numberofrow){
	    	    k[i].seatRow = r[i].seatRow;
	    		k[i].seatClass = r[i].seatClass;
	    		k[i].seatName =  r[i].seatName;
	    		i++;
			}
		}
		
		void displayflights();
		void viewflight();
		void displayseats();
};

void flight::displayflights(){ 
    
	cout<<flight_number<<endl<<date<<endl<<depature_airport<<endl<<arrival_airport<<endl;
	cout<<"Available Business Class Seats:"<<numberofbseats<<endl;
	cout<<"Available Economy Class Seats:"<<numberofeseats<<endl;
	cout<<"\n**************************************\n"<<endl;
}

void flight::displayseats(){
	int x = 0;
	while(x < numberofrow){
		cout<<k[x].seatRow<<" ";
		cout<<k[x].seatClass<<" ";
		cout<<k[x].seatName<<endl;
		x++;	
	}
}

int main(){
	
    string str;
    fstream file1; 
    c = 0;
    file1.open("Sample data Set.txt",ios::in); 
    
    if(!file1.is_open()){
    	cout<<"cannot open the file"<<file1<<endl;
    	return false;}
	
    while (!file1.eof()) { 
        
         getline(file1,str);
        	if (str.empty())
    	{ 
    		c++;
		}
    
    } 
    file1.close(); 
  	
  	flight s[c];

  	//fstream file2; 
    ifstream file2("Sample Data Set.txt"); 
    
    if(!file2.is_open()){
    	cout<<"cannot open the file2"<<file2<<endl;
    	return false;
	}

	int x, d = 0, k = 0;
	
	string name;
	string date_time;
	string depature;
	string arrival;
	string line;
	flightSeat seatarry[50];	
	string row;
	string clas;
	string seat;
	string sh;
	string output;
	int count = 0 ;
	int eseats = 0;
	int bseats = 0;
   
     for(x = 0; x < c; x++){
     	 getline(file2,name);
     	 getline(file2,date_time);
     	 getline(file2,depature);
     	 getline(file2,arrival);
     	 
     	 while(1){
     	 	getline(file2,line);
     	 	if(line.empty()){
     	 		
     	 		  flight a(name,date_time,depature,arrival,seatarry,d,eseats,bseats);
     	 		  s[x] = a;
     	 		  d = 0;
     	 		  count = 0;
     	 		  eseats = 0;
     	 		  bseats = 0;
				  break;
				     }
			  
			else{
			    istringstream stringbreak(line);
			    stringbreak>>row>>clas>>seat;
			    seatarry[count].seatRow= row;
			    seatarry[count].seatClass = clas;
			    seatarry[count].seatName = seat;
			    for(int i = 0; i < seat.size(); i++){
			    	if(clas == "E"){
			    		eseats++;
					}else{
						bseats++;
					}
				}
			              		
	    	}
			    count++;
				d++;	
			}
			 
		  }
	file2.close();
	

    int ch,i;
    while(1)
    {   
        cout<<""<<endl;
    	cout << "\t\t\t\t---Welcome To The Virgin Airline Flight Booking Service---\n" << endl;
    	cout<<"1.Display available flights\n";
	    cout<<"2.View flight\n";
	    cout<<"3.Seat availability\n";
	    cout<<"4.Seat booking\n";
	    cout<<"5.Exit\n";
		cout << "\nEnter Your Choice : ";
    	cin >> ch;
    	
    	switch(ch)
    	{
    		case 1 :
			for( i = 0; i < c; i++)
			{
				s[i].displayflights();
			}
    		break;
    		
    		case 2 : {
    			string tmp;
				int t;
				cout<<"Flight Number : ";
				cin >> tmp;
				int flag = 0;
				
				for( t = 0; t < c ; t++){
					if(s[t].flight_number == tmp){
						s[t].displayflights();
						s[t].displayseats();
						flag = 1;
					}
				  }
				    if(flag == 0){
						cout<<"Invalid Flight Number"<<endl;							
				    }
		  }
		    break;
		
    		case 3 : {
    			string test;
    			int e,w,g;
    		    cout<<"Flight Number: ";
    		    cin>>test;
    		    
    		    for(e = 0; e < c; e++){
    		    	if(s[e].flight_number == test){
    		    		cout<<"Enter your Number of required seats: ";
    		    		cin>>w;
    		    		g=s[e].numberofbseats+s[e].numberofeseats;
    		    		if(g >= w){
    		    			s[e].displayseats();
    		    			cout<<"Number of Business seats:"<<s[e].numberofbseats<<endl;
    		    			cout<<"Number of Economy seats:"<<s[e].numberofeseats;
						}
						else{
							cout<<"No Enough Seats"<<endl;
						}
						
					}        
				}
			
			  break;
			}
				
				
			case 4 : {
				 string ptr,y;
				 int q,u,m,v;
				 string x;
				 cout<<"Flight Number:";
				 cin>>ptr;
				 for( q = 0; q < c; q++){
				 	if(s[q].flight_number == ptr){
				 		cout<<"Enter your row number:";
				 		cin>>x;
				 		m=s[q].numberofbseats+s[q].numberofeseats;
				 		for(u = 0; u <= m; u++){
				 		    string y = s[q].k[u].seatRow ;
				 		    if(y == x){
				 			  cout<<"Enter your seat:";
				 			  cin>>y;
				 			  string tmp = s[q].k[u].seatName;
				 			  int pos = tmp.find(y);
				 			  tmp.erase(pos,1);
				 			  s[q].k[u].seatName = tmp;
						     cout << s[q].k[u].seatRow << " " << s[q].k[u].seatName <<endl<<"Seat book"<<endl;
						     
						     
					        	if(s[q].k[u].seatClass == "B"){
					        		s[q].numberofbseats--;
								}
								else{
									s[q].numberofeseats--;
								}
								 }
							 }
						 }
				 	   }				 
				break;
			}
    			
    		case 5 :{
    			int f;
    				ofstream file3;
					file3.open("Sample data Set.txt");
                    if(!file3.is_open()){
    	                cout << "cannot open the file3" << file3 << endl;
    	                return false;
    	         }
    	            else{
    	            	for(f=0;f<=c;f++){
    	            		file3 << s[f].flight_number << endl;
    	            	    file3 << s[f].date << endl;
    	            	    file3 << s[f].depature_airport <<endl;
    	            	    file3 <<s[f].arrival_airport<<endl; 
    	            	    
    	            	    int g = 0;
                         	while(g < s[f].numberofrow){
			                    file3 << s[f].k[g].seatRow<<" ";
			                    file3 << s[f].k[g].seatClass<<" ";
			                    file3 << s[f].k[g].seatName<<endl;
			                    g++;
							}
							file3 << endl;
    	            	
					}
				}
	               file3.close();
    			break;
    	}
			default: {
			
			cout << "Enter A Valid Process..\n" << endl;
		break;
	    	}
     	}
  }
return 0;
}
