#include <iostream>
#include <vector>
#include<string>
//#include "loginCredentialDB.hpp"

class loginCredentialDB
{//Check if the user has access to the database
  public:
    bool checkAccess(std::string dbAccessName, std::string dbAccessPassword)
    {
      if(dbAccessName == "ninja" && dbAccessPassword == "admin")
      { std::cout<<"Access Granted"<<std::endl;
        return true; }
      else
      { std::cout<<"Access Denied"<<std::endl;
        return false; }
    }
};

class CredentialDB{
  private:
    std::vector<std::vector<std::string>> credentials = {
      {"Facebook","Safwan","@123#"},
      {"Instagram","Raven","@7vldd6"},
      {"Twitter","Borax","b6vek"}
    };
  public:
    std::string getsite(int i)
    {
      return credentials[i][0];
    }
    void siteList(){
      for(int i=0; i<credentials.size(); i++)
        { std::cout<<" "<<i+1<<" "<<getsite(i)<<std::endl; }
    }
    void getcredential(int i)
    {
      i-=1;
      std::cout<<"Site: "<<credentials[i][0]<<std::endl;
      std::cout<<"Username: "<<credentials[i][1]<<std::endl;
      std::cout<<"Password: "<<credentials[i][2]<<std::endl;
    }
    void setcredential(std::string site, std::string username, std::string password)
    {
      std::vector<std::string> newCredential = {site, username, password};
      credentials.push_back(newCredential);
    }
};

void selectOption(CredentialDB& credDB);
void outputCredential(CredentialDB& credDB);
void addCredential(CredentialDB& credDB);
//void updateCredential();
//void deleteCredential();


int main()
{
  loginCredentialDB accessManager;
  CredentialDB credDB;
  std::string dbAccessName;
  std::string dbAccessPassword;
  
  std::cout<<"--_-Password Manager-_--"<<std::endl;

  std::cout<<"Enter Database Name: ";
  std::cin>>dbAccessName;
  std::cout<<"Enter Database Password: ";
  std::cin>>dbAccessPassword;

  if(!accessManager.checkAccess(dbAccessName, dbAccessPassword))
    {return 0;}

  std::cout<<"Welcome to "<<dbAccessName<<" Database"<<std::endl<<std::endl;
  while(true)
  {
    selectOption(credDB);
  }

  
  return 0;
}

void selectOption(CredentialDB& credDB)
{
  int optionIndex;
  std::cout<<"--Available Options--"<<std::endl;
  std::cout<<"1. Get Credential"<<std::endl;
  std::cout<<"2. Add Credential"<<std::endl;
  std::cout<<"3. Update Credential"<<std::endl;
  std::cout<<"4. Delete Credential"<<std::endl;
  std::cout<<"5. Exit"<<std::endl;
  std::cout<<std::endl<<"Enter the option index: ";
  std::cin>>optionIndex;

  switch(optionIndex)
  {
    case 1:
      outputCredential(credDB);
      break;
    case 2:
      addCredential(credDB);
      break;
    case 3:
      //updateCredential();
      break;
    case 4:
      //deleteCredential();
      break;
    case 5:
      std::cout<<"Exiting..."<<std::endl;
      exit(0);
      break;
    default:
      std::cout<<"Invalid Option"<<std::endl;
  }
}

void outputCredential(CredentialDB& credDB){
  int siteIndex;
  std::cout<<"--Available sites--"<<std::endl;
  credDB.siteList();
  std::cout<<std::endl<<"Enter the site index: ";
  std::cin>>siteIndex;
  credDB.getcredential(siteIndex);
  std::cout<<std::endl;
}

void addCredential(CredentialDB& credDB){
  std::string site;
  std::string username;
  std::string password;
  std::cout<<"Enter the site: ";
  std::cin>>site;
  std::cout<<"Enter the username: ";
  std::cin>>username;
  std::cout<<"Enter the password: ";
  std::cin>>password;
  credDB.setcredential(site, username, password);
}
