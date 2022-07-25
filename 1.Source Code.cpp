
#include<iostream> // required for input output operation
#include <string> //Required for string
#include<fstream> // required for input and output file

using namespace std;

class PersonalInfo
{
   private:
   	 string name, passport;
	 int age, gender;

   public:
    void Name(string name)
    {
        this->name=name;
	}


	void PASSPORT(string passport) {
	    this->passport=passport;
	}
	void AGE (int age){
	    this->age=age;
	}

	void GENDER(int gender)
	{
        this->gender=gender;
	}


    string GetName() { return name;}

    string GetPass() { return passport;}

    int GetAge () {return age;}

    int GetGender () {return gender;}

};

class Vaccine: public PersonalInfo 
{
    private:
    int Vstatus;
    int Vinfo;
    string date;

	public:

    void VaccineStatus(int Vstatus)
    {
        this->Vstatus = Vstatus;
	}

	void VaccineInfo(int Vinfo)
	{
        this->Vinfo = Vinfo;
	}

	void Date(string date)
	{
        this->date = date;
	}

	string getDate(){ return date;}
	int getStatus(){ return Vstatus;}
	int getInfo(){ return Vinfo;}
};



Vaccine createNew(){
    string name,passport,date;
	int age, gender, Vstatus, Vinfo;
    Vaccine vaccine;


    cout<<"\n\t\t\tEnter Your Information as below";
    cout<<"\n\t\t\t___________________________________";
    cout<<"\nEnter Your Full Name : ";
    cin>>name;
    cout<<"\nEnter Your Passport Number: ";
    cin>>passport;
    cout<<"\nEnter your age: ";
    cin>>age;
    cout<<"\nSelect your gender: \n1.Male\n2.Female\n";
    cin>>gender;
	if (gender<1 || gender >2)
	{
	 do
	 {

	  cout<<"\nINVALID GENDER !" ;
	  cout<<"\nSelect your Gender Again \n\t ";
	  cout<<"1 : Male\n";
	  cout<<"2 : Female\n";
	  cin>> gender;
     }
     while (gender<1 || gender>2);
	}
    cout<<"\n\t\t\tUpdate your Vaccination Information as below";
    cout<<"\n\t\t\t_____________________________________________";
    cout<<"\nEnter a step for Your Vaccination Status :\n";
    cout<<"Step-1 : Completed 2 Dose\n";
    cout<<"Step-2 : Partially Completed \n";
    cout<<"Step-3 : Not Taken\n";

	cin>> Vstatus;



	if (Vstatus<1 || Vstatus >3)
	{
	 do
	 {
	  cout<<"\nINVALID VACCINATION STATUS ! " ;
	  cout<<"\nEnter a step for Your Vaccination Status :\n";
      cout<<"Step-1 : Completed 2 Dose\n";
      cout<<"Step-2 : Partially Completed \n";
	  cout<<"Step-3 : Not Taken\n";
	  cin>> Vstatus;
     }
     while (Vstatus<1 || Vstatus >3);
	}



    cout<<"\nChoose an option to update the Type of Vaccine you receive :\n";
    cout<<"1 . Pfizer\n";
    cout<<"2 . Sinovac \n";
    cout<<"3 . AstraZeneca\n";
    cin>> Vinfo;
    if (Vinfo<1 || Vinfo >3)
    {
        do
        {
            cout<<"\nINVALID TYPE OF VACCINE RECEIVE ! " ;
            cout<<"\nChoose an option to update the Type of Vaccine you receive :\n";
            cout<<"1 : Pfizer\n";
            cout<<"2 : Sinovac \n";
            cout<<"3 : AstraZeneca\n";
            cin>> Vinfo;
        }
        while (Vinfo<1 || Vinfo >3);
    }



    cout<<"\nEnter the Date of you receiving vaccine (DD/MM/YY) : ";
    cin>>date;
    vaccine.Name(name);
    vaccine.PASSPORT(passport);
    vaccine.GENDER(gender);
    vaccine.AGE(age);
    vaccine.VaccineInfo(Vinfo);
    vaccine.VaccineStatus(Vstatus);
    vaccine.Date(date);

    return vaccine;
}




void displayInfo(Vaccine vaccine[], string passPort, int total){
    int found=0;
    for(int i=0;i<total;i++){
        if(vaccine[i].GetPass().compare(passPort)==0){
            found=1;
            cout<<"Name: "<<vaccine[i].GetName()<<"\n";
            cout<<"Passport Number: "<<vaccine[i].GetPass()<<"\n";
            cout<<"Age: "<<vaccine[i].GetAge()<<"\n";
            if(vaccine[i].GetGender()==1) cout<<"Gender: "<<"Male\n";
            else cout<<"Gender: "<<"Female\n";

            int info,status;
            status=vaccine[i].getStatus();


            cout<<"Vaccination Status: ";
            if(status==1){
                cout<<"Completed 2 doses\n";
            }
            else if (status==2){
                cout<<"Partially Completed\n";
            }
            else{
                cout<<"Not taken\n";
            }
            if(status!=3){
                info=vaccine[i].getInfo();
                cout<<"Type of Vaccination: ";
                if(info==1){
                    cout<<"Pfizer\n";
                }
                else if (info==2){
                    cout<<"Sinovac\n";
                }
                else{
                    cout<<"AstraZeneca\n";
                }
                cout<<"Date of Receiving vaccine: "<<vaccine[i].getDate()<<"\n";
            }        }
    }
    if(found==0){
        cout<<"No such records\n";
    }
}




void unVaccinated(Vaccine vaccine[], int total){
    for(int i=0;i<total;i++){
        if(vaccine[i].getStatus()==3){
            displayInfo(vaccine,vaccine[i].GetPass(),total);
        }
    }

}



void vaccinated(Vaccine vaccine[], int total){
    cout<<"Vaccination Type: Pfizer\n";
    cout<<"_______________________________\n";
    for(int i=0;i<total;i++){
        if(vaccine[i].getStatus()<=2){
            if(vaccine[i].getInfo()==1){
                displayInfo(vaccine,vaccine[i].GetPass(),total);
            }
        }
        cout<<"_______________________________\n";
    }

    cout<<"Vaccination Type: Sinovac\n";
    cout<<"_______________________________\n";
    for(int i=0;i<total;i++){
        if(vaccine[i].getStatus()<=2){
            if(vaccine[i].getInfo()==2){
                displayInfo(vaccine,vaccine[i].GetPass(),total);
            }
        }
        cout<<"_______________________________\n";
    }

    cout<<"Vaccination Type: AstraZeneca\n";
    cout<<"_______________________________\n";
    for(int i=0;i<total;i++){
        if(vaccine[i].getStatus()<=2){
            if(vaccine[i].getInfo()==3){
                displayInfo(vaccine,vaccine[i].GetPass(),total);
            }
        }
        cout<<"_______________________________\n";
    }

}




void statisticalData(Vaccine vaccine[], int total){
    int max_age=131;
    int age[max_age]={0};
    int fully=0;
    int partial=0;
    int notvacc=0;
    int Pfizer=0;
    int Sinovac=0;
    int AstraZeneca=0;
    int male=0;
    int female=0;
    for(int i=0;i<total;i++){
        if(vaccine[i].getStatus()<=2){
            if(vaccine[i].getStatus()==1){
                fully++;
            }
            else if(vaccine[i].getStatus()==2){
                partial++;
            }
        }
            if(vaccine[i].getInfo()==1){
                Pfizer++;
            }
            else if(vaccine[i].getInfo()==2){
                Sinovac++;
            }
            else if(vaccine[i].getInfo()==3){
                AstraZeneca++;
            }
        else{
            notvacc++;
        }
        age[vaccine[i].GetAge()]++;
        if(vaccine[i].GetGender()==1){
            male++;
        }
        else{
            female++;
        }
    }
    
    
    
    cout<<"Statistical Data:\n";
    cout<<"_________________\n";
    cout<<"Total number of individuals who received vaccine under Pfizer: "<<Pfizer<<"\n";
    cout<<"Total number of individuals who received vaccine under Sinovac: "<<Sinovac<<"\n";
    cout<<"Total number of individuals who received vaccine under AstraZeneca: "<<AstraZeneca<<"\n";
    cout<<"Total number of individuals fully vaccinated: "<<fully<<"\n";
    cout<<"Total number of individuals partially vaccinated: "<<partial<<"\n";
    cout<<"Total number of individuals has not vaccinated yet: "<<notvacc<<"\n\n";
    cout<<"Age wise vaccination details:\n";
    cout<<"_____________________________\n";
    
    
    for(int i=9;i<131;i++){
        if(age[i]>0){
            cout<<"Number of persons vaccinated at the age of "<<i<<": "<<age[i]<<"\n";
        }
    }
    cout<<"Number of Male who got vaccinated: "<<male<<"\n";
    cout<<"Number of Female who got vaccinated: "<<female<<"\n";

}


void updateDetails(Vaccine vaccine[], int total, string passport){
    int found=0;
    int Vstatus=0;
    int Vinfo=0;
    string date;
    for(int i=0;i<total;i++){
       if(vaccine[i].GetPass().compare(passport)==0){
            found=1;
            cout<<"User Found\n";

            cout<<"\n\t\t\tUpdate your Vaccination Information as below ";
            cout<<"\n\t\t\t______________________________________________";
            cout<<"\n\nEnter a step for Your Vaccination Status :\n\t ";
            cout<<"Step-1 : Completed 2 Dose\n\t";
            cout<<"Step-2 : Partially Completed \n\t";
            cout<<"Step-3 : Not Taken\n";

            cin>> Vstatus;


            if (Vstatus<1 || Vstatus >3)
            {
                 do
                 {
                  cout<<"\nINVALID VACCINATION STATUS ! " ;
                  cout<<"\n\nEnter a step for Your Vaccination Status :\n\t ";
                  cout<<"Step-1 : Completed 2 Dose\n\t";
                  cout<<"Step-2 : Partially Completed \n\t";
                  cout<<"Step-3 : Not Taken\n";
                  cin>> Vstatus;
                 }
                 while (Vstatus<1 || Vstatus >3);
            }

                if(Vstatus<=2){
                cout<<"\nChoose an option to update the Type of Vaccine you receive :\n\t ";
                cout<<"1 . Pfizer\n\t";
                cout<<"2 . Sinovac \n\t";
                cout<<"3 . AstraZeneca\n";
                cin>> Vinfo;
                if (Vinfo<1 || Vinfo >3)
                {
                    do
                    {
                        cout<<"\nINVALID TYPE OF VACCINE RECEIVE ! " ;
                        cout<<"\n\nChoose an option to update the Type of Vaccine you receive :\n\t ";
                        cout<<"1 . Pfizer\n\t";
                        cout<<"2 . Sinovac \n\t";
                        cout<<"3 . AstraZeneca\n";
                        cin>> Vinfo;
                    }
                    while (Vinfo<1 || Vinfo >3);
                }


                cout<<"\nEnter the Date of you receiving vaccine (DD/MM/YY) : ";
                cin>>date;
                }
            }
            vaccine[i].VaccineInfo(Vinfo);
            vaccine[i].VaccineStatus(Vstatus);
            vaccine[i].Date(date);
        }
        if(found==0){
            cout<<"Record Not found\n";
        }

}




int main ()
{
    cout<<"\t\t\t Welcome to eCPIS Malaysian Immunization\n\n ";
    Vaccine vaccine[1000];
    int total=0;
    vaccine[total] = createNew();
    total++;
    char choice;
    cout<<"\nDo you want to know more information ? Y else N \n" ;
    cin>>choice;

    while(choice== 'Y' || choice == 'y' )
    {
     int info;
     cout<<"\n\t\t\tOther Information you would like to collect:\n\t";
     cout<<"\n\t\t\t____________________________________________\n\t";
     cout<<"1 : Add a new person. \n\t";
     cout<<"2 : Update Vaccination information.\n\t";
     cout<<"3 : Search each individual vaccination information status via passport no\n\t";
     cout<<"4 : list of unvaccinated persons\n\t";
     cout<<"5 : list of individuals who received certain vaccine such as Pfizer, Sinovac or AstraZeneca\n\t";
     cout<<"6 : Statistical Information\n";
     cin>>info;
     switch(info){
         case 1 :
             vaccine[total] = createNew();
             total++;
             for(int i=0;i<total;i++){
                cout<<vaccine[i].GetAge()<<endl;
                cout<<vaccine[i].GetName()<<endl;
                cout<<vaccine[i].GetGender()<<endl;
            }
             break;
         case 2:{
             string passport;
             cout<<"Enter the Passport Number whose vaccine details you need to change: ";
             cin>>passport;
             updateDetails(vaccine,total,passport);
             break;
         }
         case 3 :
             {
                string passport;
                cout<<"Enter the Passport Number you need to Search: ";
                cin>>passport;
                displayInfo(vaccine,passport,total);
                break;
             }
         case 4 :{
            unVaccinated(vaccine,total);
            break;
         }
        case 5:{
           vaccinated(vaccine,total);
           break;
        }
        case 6:{
            statisticalData(vaccine,total);
            break;
        }
     }
     cout<<"Do you need to continue?(Y/N)\n";
     cin>>choice;

    }
     
     cout<<"Hope You Enjoyed using eCPIS !\n";
     cout<<"Thank You !\n";
	 cout<<"Stay Safe."<<endl;
	 
    return 0;
}
