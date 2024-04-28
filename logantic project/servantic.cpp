#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
ofstream fout;
ofstream sout;
ofstream lout;





class result
{
    public :
     int months[12]={0};
     int hour[24]={0};
     string web[100];
     int success=0;
     int failure=0;
};

class divide:public result
{

    //using different variable to store the data of logs;
    public:
    string ip;
    string username;
    char timestamp;
    string grequest;
    string siteadd;
    string statuscode;
    string port;
    string midum;
    string hypen2;
    string browser;
    string date;
    string month;
    string year;
    string hr;
    string min;
    string sec;
    string utcode;
    string webpage;
    string weblink;
    string http;

    

    //objects to be used in files 
    ifstream fin;
   //  ofstream ipout;

    //using the constructor for opening the file 
    divide(string file)
   {
      fin.open(file,ios::in|ios::out|ios::app);
      // ipout.open("ip.txt",ios::in|ios::out|ios::app);
   }
      void pg_codeSF();

   

    //method to read the data from the files and storing in the variables for processing it 
    void readfromfile()
    {
       while(!fin.eof())
       {
        fin>>ip;
        sout<<ip<<"\n";
        fin>>username;
        if(username[0]=='-')
        {
            string temp;
            getline(fin,temp,'-');
            username+=temp;
        }

        fin>>timestamp;
        if (timestamp == '[') //dividing the timestamp in date month year hr min sec and UTC code
        {
            string temp1;
            getline(fin, temp1, '/');
            date=temp1;
            
            string temp2;
            getline(fin, temp2, '/');
            month = temp2;

            
            string temp3;
            getline(fin, temp3, ':');
            year = temp3;

            
            string temp4;
            getline(fin, temp4, ':');
            hr = temp4;
        
            string temp5;
            getline(fin, temp5, ':');
            min = temp5;
                 
            string temp6;
            getline(fin, temp6, ' ');
            sec = temp6 ;

            string temp7;
            getline(fin, temp7, ']');
            utcode = temp7;
        }

        fin>>grequest;
        fin>>siteadd;
        if(siteadd[0]=='/')
            {
               string temp;
               getline(fin,temp,'H');
               siteadd+=temp;
  

               string temp2;
               getline(fin,temp,'"');
               http=temp2;
            }
        fin>>statuscode;
      //   sout<<statuscode<<"\n";
        fin>>port;
        fin>>midum;
        fin >> browser; // Reads the entire browser string
            if (browser[0] == '"') 
            {
                string temp;
                getline(fin, temp, '"'); // Reads the  browser until the closing double quote
                browser += temp;
            }
        fin>>hypen2;
        pg_codeSF();
        countMH();
      }
      
     
   }
    
   //  method to write the data in the file
    void writetofile()
    {
       fout.seekp(0,ios::beg);
       fout<<"bhajan";
       
    }

    //method to show the data from the file
    void sdata()
    {
        cout<<ip<<"\n"<<month<<"/"<<date<<"/"<<year<<"\n"<<hr<<"/"<<min<<"/"<<sec<<"\n"<<grequest<<"\n"<<siteadd<<"\n"<<statuscode<<"\n"<<port<<"\n"<<midum<<"\n"<<browser<<"\n"<<hypen2<<endl;
        cout<<"\n\n";
        
    }

   //  method to process the data and counting month and year per request
    void countMH()
    {
         // Counting the request per month
         if(month=="Jan")
         {
            months[0]++;   
         }
         else if(month=="Feb")
         {
            months[1]++;   
         }
         else if(month=="Mar")
         {
            months[2]++;   
         }
         else if(month=="Apr")
         {
            months[3]++;   
         }
         else if(month=="May")
         {
            months[4]++;   
         }
         else if(month=="Jun")
         {
            months[5]++;
         }
         else if(month=="Jul")
         {
            months[6]++;
         }
         else if(month=="Aug")
         {
            months[7]++;
         }
         else if(month=="Sep")
         {
            months[8]++;
         }
         else if(month=="Oct")
         {
            months[9]++;
         }
         else if(month=="Nov")
         {
            months[10]++;
         }
         else if(month=="Dec")
         {
            months[11]++;
         }
         else
         {
         cout<<"hii";
         }


      //   counting the request per hour
         if (hr == "1")
         { 
            hour[0]++;
         }
         else if (hr =="2")
         {
            hour[1]++;
         }
         else if (hr =="3")
         {
            hour[2]++;
         }
         else if (hr =="4")
         {
            hour[3]++;
         }
         else if (hr =="5")
         {
            hour[4]++;
         }
         else if (hr =="6")
         {
            hour[5]++;
         }
         else if (hr =="7")
         {
            hour[6]++;
         }
         else if (hr =="8")
         {
            hour[7]++;
         }
         else if (hr =="9")
         {
            hour[8]++;
         }
         else if (hr =="10")
         {
            hour[9]++;
         }
         else if (hr =="11")
         {
            hour[10]++;
         }
         else if (hr =="12")
         { 
            hour[11]++;
         }
         else if (hr =="13")
         {
            hour[12]++;
         }
         else if (hr =="14")
         {
            hour[13]++;
         }
         else if (hr =="15")
         {
            hour[14]++;
         }
         else if (hr =="16")
         {
            hour[15]++;
         }
         else if (hr =="17")
         {
            hour[16]++;
         }
         else if (hr =="18")
         {
            hour[17]++;
         }
         else if (hr =="19")
         {
            hour[18]++;
         }
         else if (hr =="20")
         {
            hour[19]++;
         }
         else if (hr =="21")
         {
            hour[20]++;
         }
         else if (hr =="22")
         {
            hour[21]++;
         }
         else if (hr =="23")
         {
            hour[22]++;
         }
         else if(hr=="24")
         {
            hour[23]++;
         }
         else
         {
            cout<<"ho";
         }
   
    }
    
};


class processing: public divide
{
    public:

   //  using the constructor of derived class to call the constructor of base class
    processing(string file):divide(file)
    {
      // cout<<"File passed..";
    }
};

class filestore
{
    public:
    time_t now = time(0);

   // convert now to string form
   char* date_time = ctime(&now);

   void fstore()
   {

   cout<<"                                                  "" _____ ___________ _   _  ___   _   _ _____ _____ _____ "<<endl;
   cout<<"                                                  ""/  ___|  ___| ___ \\ | | |/ _ \\ | \\ | |_   _|_   _/  __ \\"<<endl;
   cout<<"                                                  ""\\ `--.| |__ | |_/ / | | / /_\\ \\|  \\| | | |   | | | /  \\/"<<endl;
   cout<<"                                                  "" `--. \\  __||    /| | | |  _  || . ` | | |   | | | |    "<<endl;
   cout<<"                                                  ""/\\__/ / |___| |\\ \\  \\_/ / | | || |\\  | | |  _| |_| \\__/\\"<<endl;
   cout<<"                                                  ""\\____/\\____/\\_| \\_|\\___/\\_| |_/\\_| \\_/ \\_/  \\___/ \\____/";
   
   string file;
   cout<<"\n Enter the file: ";
   cin>>file;
   processing p(file);
   p.readfromfile();

   
  
   fout.open("Analyzed log.txt",ios::in|ios::out|ios::app);
   fout<<"                                                    "" _____ ___________ _   _  ___   _   _ _____ _____ _____ "<<endl;
   fout<<"                                                    ""/  ___|  ___| ___ \\ | | |/ _ \\ | \\ | |_   _|_   _/  __ \\"<<endl;
   fout<<"                                                    ""\\ `--.| |__ | |_/ / | | / /_\\ \\|  \\| | | |   | | | /  \\/"<<endl;
   fout<<"                                                    "" `--. \\  __||    /| | | |  _  || . ` | | |   | | | |    "<<endl;
   fout<<"                                                    ""/\\__/ / |___| |\\ \\  \\_/ / | | || |\\  | | |  _| |_| \\__/\\"<<endl;
   fout<<"                                                    ""\\____/\\____/\\_| \\_|\\___/\\_| |_/\\_| \\_/ \\_/  \\___/ \\____/";
   
   
   fout<<"\n\n";
   fout<<"File name: "<<file<<"\n";
   cout<<"\n\n";
   fout<<"\n\n";
   fout<<"Analytics till "<<date_time<<endl;
   cout<<"Analytics till "<<date_time<<endl;
   cout<<"\n";
   fout<<"\n";
   fout<<"Number of Successful request : "<<p.success<<"\n";
   cout<<"Number of Successful request : "<<p.success<<"\n";

   fout<<"Number of Unsuccessful request :"<<p.failure<<"\n";
   cout<<"Number of Unsuccessful request : "<<p.failure<<"\n";
   cout<<"\n\n";

   fout<<"============================================================================================================================="<<"\n";
   cout<<"========================================================================================================================================================="<<"\n";
   
   fout<<"============================================================================================================================="<<endl<<endl;
   cout<<"========================================================================================================================================================="<<"\n\n";
  
    string mon[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    fout<< "\n\n-----Monthly Distribution----- " << endl; 
    cout<< "\n\n-----Monthly Distribution----- " << endl; 
        for (int i = 0; i < 12; i++) {
            fout <<"|"<<"\t"<<mon[i]<<"\t";
            cout <<"|"<<"\t"<<mon[i]<<"\t";
            fout <<"\t"<<p.months[i]<<"\t"<<"|"<<endl<<endl;
            cout <<"\t"<<p.months[i]<<"\t"<<"|"<<endl<<endl;
         }
    
    fout<<"============================================================================================================================"<<"\n";
   cout<<"============================================================================================================================================"<<"\n";
    
    fout<<"============================================================================================================================"<<endl<<endl;
   cout<<"========================================================================================================================================================="<<"\n\n";
    
    fout<<"\n\n";
    cout<<"\n\n";
    fout<< "\n\n-----Hourly Distribution----- " << endl;
    cout<< "\n\n-----Hourly Distribution----- " << endl;

    fout<<"\n";
    for (int i = 0,a=0; i < 24; i++) 
    {
        
        if(i<12)
        {
          fout<<"|"<<"\t"<<i+1<<" AM"<<"\t\t"<<p.hour[i]<<"\t"<<"|"<<endl<<endl;
          cout<<"|"<<"\t"<<i+1<<" AM"<<"\t\t"<<p.hour[i]<<"\t"<<"|"<<endl<<endl;
        }
        else
        {
          fout<<"|"<<"\t"<<a+1<<" PM"<<"\t\t"<<p.hour[i]<<"\t"<<"|"<<endl<<endl;
          cout<<"|"<<"\t"<<a+1<<" PM"<<"\t\t"<<p.hour[i]<<"\t"<<"|"<<endl<<endl;
          a++;
        }
    }
    fout<<"============================================================================================================================"<<"\n";
   cout<<"========================================================================================================================================================="<<"\n";
    
    fout<<"============================================================================================================================"<<endl<<endl;
   cout<<"=========================================================================================================================================================\n";
  }

};


// method of base class divide class for processing the data for counting the number of failed and success requests
void divide::pg_codeSF()
{
      
    
   //  cout<<siteadd<<endl;

    int size = sizeof(web)/sizeof(web[0]);                     
   if(statuscode!="404")
   {
      // sout.open("scode.txt",ios::in|ios::out|ios::app);
               // sout<<statuscode<<"\n";


      for(int a=0;a<size;a++)
      {
         if(web[a]==siteadd)
         {
            // cout<<"exits"<<endl;
            // cout<<siteadd;

            if(statuscode=="200"||statuscode=="302")
            {
               success++;
               // sout<<statuscode<<"\n";

            }
            else
            {
               failure++;
               lout<<statuscode<<"\n";
               
            }
            break;
         }
         else if(web[a]=="")
         {
            // cout<<"not exits"<<endl;
            // cout<<siteadd<<endl;
            web[a]=siteadd;
            if(statuscode=="200"||statuscode=="302")
            {
               success++;
               // sout<<statuscode<<"\n";

               // sout<<ip<<"\n"
            }
            else
            {
               failure++;
               // lout<<statuscode<<"\n";

            }
            break;

         }
         
      }
   }
   else
   {
      // lout.open("fcode.txt",ios::in|ios::out|ios::app);

      failure++;
               // lout<<statuscode<<"\n";

   }
}
int main()
{
   filestore f;
   f.fstore();
   system("pause");
   return 0;
}