//It is part of input/output library.Behaves as if it defines a static strorage duration object of type std::ios_base::init.
#include <iostream>
#include<exception>

using namespace std;
//Exception class to handel runtime errors

class SearchError
{
    public:
    string msg;

    SearchError()
    {
        this->msg="";
    }

    SearchError(string msg)
    {
        this->msg=msg;
    }

    void showError()
    {
        cout<<"Error message is:"<<endl;
        cout<<msg<<endl;
    }
};


class PayError
{
    public:
    string errorMsg;

    PayError()
    {
        this->errorMsg="";
    }

    PayError(string errorMsg)
    {
        this->errorMsg=errorMsg;
    }

    void displayError()
    {
        cout<<"Error message is:"<<endl;
        cout<<errorMsg<<endl;
    }
};


class Spotify { static Spotify *instance;
Spotify() {}
public:
static Spotify *getInstance()
 { if (!instance) instance = new Spotify;
return instance; }

void printSpotify(int ty)
     {
        static double total_balance=0;
         double spotifyBal=0;
         cout<<"Spotify Balance"<<endl;
         if(ty==1)
         {
             spotifyBal=199;
             total_balance=spotifyBal+total_balance;
         }
         else if(ty==2)
         {
             spotifyBal=299;
             total_balance=spotifyBal+total_balance;

         }
         else if(ty==3)
         {
             spotifyBal=399;
             total_balance=spotifyBal+total_balance;

         }
         else if(ty==4)
         {
             spotifyBal=599;
             total_balance=spotifyBal+total_balance;

         }
         cout<<spotifyBal<<endl;
     }



};

class Premium{
  public:
      Spotify* sp;

      void payAmount()
      {
          int choice;
          cout<<"Welcome to Spotify Premium Subscription"<<endl;
          cout<<"Enter your choice of Subscription"<<endl;
          cout<<"1. For 1 month Spotify Premium Subscription"<<endl;
          cout<<"3. For 3 month Spotify Premium Subscription"<<endl;
          cout<<"6. For 6 month Spotify Premium Subscription"<<endl;
          cout<<"12. For 1 Year Spotify Premium Subscription"<<endl;
          cin>>choice;
          if(choice==1)
          {
              cout<<"You have successfully subscribed Spotify premium of 1 month"<<endl;
              sp->printSpotify(1);
          }
          else if(choice==3)
          {
             cout<<"You have Successfully subscribed Spotify premium of 3 month's"<<endl;
             sp->printSpotify(2);
          }
          else if(choice==6)
          {
              cout<<"You have Successfully subscribed Spotify premium of 6 month's"<<endl;
              sp->printSpotify(3);
          }
          else if(choice==12)
          {
              cout<<"You have Successfully subscribed Spotify premium of 1 Year"<<endl;
              sp->printSpotify(4);

          }
          else
          {
               throw PayError("Invalid choice");
          }

      }
};
class Content
{
public:
    string id;
    string name;
    string r_date;
    float duration;

    Content()
    {
        this->id="";
        this->name="";
        this->r_date="";
        this->duration=0;
    }

    Content(string id,string name,string r_date,float duration)
    {
        this->id=id;
        this->name=name;
        this->r_date=r_date;
        this->duration=duration;
    }
    void printContent()
    {

        cout<<"id:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Release Date:"<<r_date<<endl;
        cout<<"Duration:"<<duration<<endl;
    }

    virtual void searchFun(string sname)
    {

    }


};

class Song : public Content
{
public:
    double like;
    string lyrics;

    Song():Content()
    {
        this->like=0;
        this->lyrics="";
    }

    Song(string id,string name,string r_date,float duration,int like,string lyrics):Content(id,name,r_date,duration)
    {
        this->like=like;
        this->lyrics=lyrics;
    }
    void printSong()
    {
        Content::printContent();
        cout<<"Likes given to the songs:"<<like<<endl;
        cout<<"Lyrics of the song:"<<lyrics<<endl;
    }

    void searchFun(string sname){

        if(sname==name)
        {
            cout<<"Song found"<<endl;
            cout<<"printing the song details"<<endl;
            printContent();
        }
        else
        {
          throw  SearchError("Song not found");
        }
    }

    static void printAllSongs(Song songs[],int size)
    {
        for(int i=0;i<=size;i++)
        {
            songs[i].printSong();
        }
    }
};

class Podcast : public Content
{
public:
    int follow;
    string transcript;

    Podcast():Content()
    {
        this->follow=0;
        this->transcript="";
    }

    Podcast(string id,string name,string r_date,float duration,int follow,string transcript):Content(id,name,r_date,duration)
    {
        this->follow=follow;
        this->transcript=transcript;
    }
    void printPodcast()
    {
        Content::printContent();
        cout<<"Number of followers:"<<follow<<endl;
        cout<<"transcript of podcast:"<<transcript<<endl;
    }
    void searchFun(string sname){


        if(sname==name)
        {
            cout<<"Podcast found"<<endl;
            cout<<"printing the podcast details"<<endl;
            printContent();
        }
        else
        {
          //throw  SearchError(msg);
        }
    }
};


class User
{
public:
    int uId;
    string uName;
    string email;

   //Playlist *pa;

    User()
    {
        this->uId=0;
        this->uName="";
        this->email="";
    }

    User(int uId,string uName,string email)
    {
        this->uId=uId;
        this->uName=uName;
        this->email=email;
    }

    void printUserDetails()
    {
        //cout<<"Printing User Details:"<<endl;
        cout<<"User ID:"<<uId<<endl;
        cout<<"User name:"<<uName<<endl;
        cout<<"User Email:"<<email<<endl;
       //pa->printPlaylist();
    }

};
class Artist : public User
{
public:
    string content;
    int views;
    int follow;
    string genre;


    Artist(): User()
    {
      this->content="";
      this->views=0;
      this->follow=0;
      this->genre="";

    }
    Artist(int uId,string uName,string email,string content,int views,int follow,string genre):User(uId,uName,email)
    {
        this->content=content;
        this->views=views;
        this->follow=follow;
        this->genre=genre;

    }


    void printUserDetails()
    {
        User::printUserDetails();
        cout<<"content:"<<content<<endl;
        cout<<"Number of views:"<<views<<endl;
        cout<<"NUmber of Follow:"<<follow<<endl;
        cout<<"Genre:"<<genre<<endl;


    }

    void addContent(Content ca)
    {
     ca.printContent();
    }

    double payToArtist()
    {
      double  amount=0;
      if(content=="Song")
      {
         if(genre=="Indian Classical" && views>500)
         {
            amount+=15000;
         }
         else if(genre=="K-pop" && views>500)
         {
            amount+=18000;
         }
         else if(genre=="TV & Movies" && views>1000)
         {
            amount+=20000;
         }
         else if(genre=="Anime" && views>1000)
         {
            amount+=17000;
         }
         else if(genre=="Party" && views>800)
         {
             amount+=15000;
         }
         else if(genre=="Happy Holiday" && views>1200)
         {
             amount+=12000;
         }
         else
        {
            amount+=10000;
        }
      }
     else if(content=="Podcast" )
        {
         if(follow>10000)
         {
             amount+=20000;
         }
         else if(follow>8000)
         {
             amount+=18000;
         }
         else if(follow>5000)
         {
             amount+=15000;
         }
         else if(follow>3000)
         {
             amount+=10000;
         }
         else
         {
             amount+=8000;
         }
        }

        cout<<"Amount to be paid to Artist:"<<amount<<endl;
    }

};

class Listener : public User
{
public:
    int listened;

    Listener(): User()
    {
      this->listened=0;
    }
    Listener(int uId,string uName,string email,int listened):User(uId,uName,email)
    {
        this->listened=listened;
    }

    void printUserDetails()
    {
        User::printUserDetails();
        cout<<"Number of Listened:"<<listened<<endl;

    }
};

class Playlist
{

public:
    Song* sa;
    void printPlaylist()
    {
    sa->printSong();
    }

};
class Advertisement
{
    public:
    int addId;
    string addTitle;
    float duration;
    //double amount;

    Advertisement()
    {
        this->addId=0;
        this->addTitle="";
        this->duration=0;
        //this->amount=0;
    }

    Advertisement(int id,string title,float dur)
    {
        this->addId=addId;
        this->addTitle=addTitle;
        this->duration=duration;
        //this->amount=amount;
    }

    void printAdvertisement()
    {
        //cout<<"Advertisement"<<endl;
        cout<<"Advertisement id:"<<addId<<endl;
        cout<<"Title:"<<addTitle<<endl;
        cout<<"Duration:"<<duration<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Enjoy next 30 Minutes of uninterruped songs"<<endl;
        //_sleep(2);
    }

    double addAmount()
    {
        double amount;
        static double totalamount=0;
        if(duration>=2.0 )
        {
            amount=1000;
            totalamount=amount+totalamount;
        }
        else if(duration<2.0 && duration>=1.30)
        {
            amount=800;
            totalamount=amount+totalamount;
        }
        else if(duration<1.30 && duration>=1.0)
        {
            amount=700;
            totalamount=amount+totalamount;
        }
        else if(duration<1.0 && duration>=0.30)
        {
            amount=500;
            totalamount=amount+totalamount;
        }
        else if(duration<0.30 && duration>=0.20)
        {
            amount=400;
            totalamount=amount+totalamount;
        }
        else if(duration<0.20 && duration>=0.10)
        {
            amount=300;
            totalamount=amount+totalamount;
        }
        else
        {
           amount=200;
           totalamount=amount+totalamount;
        }
        return totalamount;
    }
};
class Company{
public:
    string cName;
    Advertisement ad1;

    Company()
    {
    this->cName="";
    }
    Company(string cName,Advertisement ad){
    this->cName=cName;
    }
    void printCompany()
    {


        cout<<cName<<endl;
        ad1.printAdvertisement();

    }

};



class Free
{
    public:
    Advertisement *add;

    void printFreeDetails()
    {
        add->printAdvertisement();
    }

};

class History
{
public:
    string p_date;
    History()
    {
    this->p_date="";
    }
    History(string date)
    {
        this->p_date=p_date;
    }
    Song *s;
    Podcast *p;

    void printHistory()
    {
        cout<<"Printing History Details"<<endl;
        s->printSong();
        p->printPodcast();
    }

};

int main()
{

cout<<"\t\t /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$"<<endl;
cout<<"\t\t| $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/"<<endl;
cout<<"\t\t| $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$"<<endl;
cout<<"\t\t| $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$"<<endl;
cout<<"\t\t| $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/"<<endl;
cout<<"\t\t| $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$"<<endl;
cout<<"\t\t| $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$"<<endl;
cout<<"\t\t|__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/"<<endl;

cout<<"\n"<<endl;



cout<<"\t\t\t\t\t   /$$$$$$$$ /$$$$$$"<<endl;
cout<<"\t\t\t\t\t  |__  $$__//$$__  $$"<<endl;
cout<<"\t\t\t\t\t     | $$  | $$  \\ $$"<<endl;
cout<<"\t\t\t\t\t     | $$  | $$  | $$"<<endl;
cout<<"\t\t\t\t\t     | $$  | $$  | $$"<<endl;
cout<<"\t\t\t\t\t     | $$  | $$  | $$"<<endl;
cout<<"\t\t\t\t\t     | $$  |  $$$$$$/"<<endl;
cout<<"\t\t\t\t\t     |__/   \\______/"<<endl;

cout<<"\n"<<endl;


cout<<"\t\t  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$     /$$"<<endl;
cout<<"\t\t /$$__  $$| $$__  $$ /$$__  $$|__  $$__/|_  $$_/| $$_____/|  $$   /$$/"<<endl;
cout<<"\t\t| $$  \\__/| $$  \\ $$| $$  \\ $$   | $$     | $$  | $$       \\  $$ /$$/"<<endl;
cout<<"\t\t|  $$$$$$ | $$$$$$$/| $$  | $$   | $$     | $$  | $$$$$     \\  $$$$/"<<endl;
cout<<"\t\t\\____   $$| $$____/ | $$  | $$   | $$     | $$  | $$__/      \\  $$/"<<endl;
cout<<"\t\t /$$  \\ $$| $$      | $$  | $$   | $$     | $$  | $$          | $$"<<endl;
cout<<"\t\t|  $$$$$$/| $$      |  $$$$$$/   | $$    /$$$$$$| $$          | $$"<<endl;
cout<<"\t\t \\______/ |__/       \\______/    |__/   |______/|__/          |__/"<<endl;




cout<<"\n"<<endl;

    cout<<"Displaying Arist Details"<<endl;
    cout<<"-----------------------------"<<endl;
    Artist a1(1,"Della","della01@gmail.com","Song",50,10000,"K-pop");
    a1.printUserDetails();
    a1.payToArtist();

    cout<<"\n"<<endl;

    Artist a2(2,"Shyam","shyam02@gamil.com","Podcast",50,10000,"");
    a2.printUserDetails();
    a2.payToArtist();

    cout<<"\n"<<endl;

    Artist a3(3,"Pratibha","pratibha05@gamil.com","Podcast",110,20000,"");
    a3.printUserDetails();
    a3.payToArtist();

    cout<<"\n"<<endl;

    Artist a4(4,"Kavana","kavana04@gamil.com","Song",1000,500,"Party");
    a4.printUserDetails();
    a4.payToArtist();


    cout<<"\n"<<endl;

    cout<<"Artist is adding Content"<<endl;
    cout<<"------------------------------"<<endl;
    Content ca1("s1","Sir tirboki jeevana","22-May-2020",4.5);
    a4.addContent(ca1);

    cout<<"\n"<<endl;

    Content ca2("p1","Learning to say no","10-April-2015",18.9);
    a4.addContent(ca2);

    cout<<"\n"<<endl;


   cout<<"Song details"<<endl;
   cout<<"------------------------------"<<endl;
   Song s1("s1","Sir Tirboki jeevana","20-December-2018",3.20,10000,"Sir Tirboki jeevana nammdalla");
   s1.printSong();

   cout<<"\n"<<endl;

   cout<<"Playing Advertisement"<<endl;
    cout<<"----------------------------"<<endl;
    Advertisement ad1(1,"Amazon Shopping",1.0);
    Company c1("Amazon",ad1);
    c1.printCompany();

    cout<<"\n"<<endl;

   cout<<"Song details"<<endl;
   cout<<"------------------------------"<<endl;
   Song s2("s2","Power Star","21-March-2014",4.5,2000,"Power Star,Power Star");
   s2.printSong();

   cout<<"\n"<<endl;

   cout<<"Playing Advertisement"<<endl;
    cout<<"----------------------------"<<endl;
    Advertisement ad2(2,"LinkedIn",0.30);
    Company c2("LinkedIn",ad2);
    c2.printCompany();

     cout<<"\n"<<endl;

   cout<<"Song details"<<endl;
   cout<<"------------------------------"<<endl;
   Song s3("s3","Karevole Karevavole","12-November-2020",3.6,10000,"Karevole Karevavole karemadi karedole");
   s3.printSong();

   cout<<"\n"<<endl;

    cout<<"Playing Advertisement"<<endl;
    cout<<"----------------------------"<<endl;
    Advertisement ad3(3,"Jio Mart",0.40);
    Company c3("Reliance",ad3);
    c3.printCompany();

   cout<<"\n"<<endl;

    cout<<"Song details"<<endl;
   cout<<"------------------------------"<<endl;
   Song s4("s4","Innunu bekagide","7-June-2021",3.6,10000,"Innunu bekagide ovalu Innunu bekagide");
   s4.printSong();

   Song songs[]={s1,s2,s3,s4};


   cout<<"\n"<<endl;

   Song s5("s5","Katheyond helide","02-april-2020",4.5,677,"Katheyond helide bari gurutugale collegali");
   try
   {
       s5.searchFun("Dynamite");
   }
   catch(SearchError& e)
   {
     e.showError();
   }

  cout<<"\n"<<endl;

   Premium pr;
   try
   {
    pr.payAmount();
   }
   catch(PayError & e1)
   {
      e1.displayError() ;
   }

   cout<<"\n"<<endl;

   Song s6("s6","Dynamite","02-april-2020",4.5,677,"Dynamite Dynamite");
   try
   {
       s6.searchFun("Dynamite");
   }
   catch(SearchError& e)
   {
     e.showError();
   }

   cout<<"\n"<<endl;


   Premium pr1;
   try
   {
    pr1.payAmount();
   }
   catch(PayError & e2)
   {
      e2.displayError() ;
   }

  cout<<"\n"<<endl;

  //History h1("Today");
  //h1.printHistory();

    cout<<"Displaying Playlist Details"<<endl;
    cout<<"------------------------------"<<endl;
    Playlist p1;
    p1.sa=new Song ("s7","Gagana Nee ","05-December-2021",3.4,200,"Gagana Nee Bhuvana nee");
    p1.printPlaylist();

    cout<<"\n"<<endl;

    Playlist p2;
    p2.sa=new Song ("s8","Paatashaala","13-July-2020",4.6,200,"Deshakke Yodha Nadige Raita Balige guru obba tane");
    p2.printPlaylist();

    return 0;
}


