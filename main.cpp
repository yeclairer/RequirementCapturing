
// 1.1 1.2 2.1 2.2 5.1 6.1 
// 3.1 3.2 3.3 4.1 4.2 4.3 4.4 

// 헤더 선언
#include <string>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
// 함수 선언
void doTask();
void join();
void program_exit();
// 변수 선언
FILE* in_fp, *out_fp;
int num= -1;
// 회원 entity class
class Client{
private: 
  string id;
  string pw;
  string name;
  string socialSecurityNum;

public: 
  void createNewClient(string name, string socialSecurityNum,string id, string pw){
    this->id= id;
    this->pw= pw;
    this->name= name;
    this->socialSecurityNum= socialSecurityNum;
  }
  void removeClient(Client* client){
    delete[] client;
  }
  string getClientId(){
    return this->id;
  }
};

Client * clientList[100];

//회원가입 control class
class signUp{ //addclient-> signup 변경 (다이어그램)
  public:
    signUp(string name, string socialSecurityNum,string id, string pw){
      clientList[++num]= new Client();
      clientList[num]->createNewClient(name, socialSecurityNum, id, pw);
    }
};

//로그인 control class
class login{
  private:
    char* loginClient;
  public:
     login(char* id, string pw){
        this->loginClient= id;
    }
    char* getCurrentClient(){
      return this->loginClient;
    }
};

//로그아웃 control class
class logout{
  private:
    char* logoutClient;
  public:
    logout(login* loginClient){
      this->logoutClient= loginClient->getCurrentClient();
    }
    char* getLogoutClient(){
      return this->logoutClient;
    }
};

//회원탈퇴 control class
class signOut{ //deleteclient-> signOut 변경 (다이어그램)
  private:
    char* signOutClient;
  public:
    signOut(login* loginClient){
      this->signOutClient= loginClient->getCurrentClient();
    }
  char* getSignOutClient(){
      return this->signOutClient;
    }
};

int main()
{
  // 파일 입출력을 위한 초기화
  in_fp = fopen(INPUT_FILE_NAME, "r+");
  out_fp = fopen(OUTPUT_FILE_NAME, "w+");
  
  doTask();
  return 0;
}


void doTask()
{
  signUp * signUpClient;
  signOut * signOutClient;
  login * loginClient;
  logout * logoutClient;
  char name[MAX_STRING], socialSecurityNum[MAX_STRING], id[MAX_STRING], pw[MAX_STRING];
  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 1, menu_level_2 = 1;
  int is_program_exit = 0;
  int readcount;
  while(!feof(in_fp))
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    fscanf(in_fp, "%d %d", &menu_level_1, &menu_level_2);
    // 메뉴 구분 및 해당 연산 수행
    switch(menu_level_1)
    {
      case 1:
      {
        switch(menu_level_2)
        {
          case 1:  // "1.1. 회원가입“ 
            {
            fscanf(in_fp, "%s %s %s %s", name, socialSecurityNum, id, pw);
            signUpClient= new signUp(name, socialSecurityNum, id, pw);
            fprintf(out_fp, "1.1. 회원가입\n");
            fprintf(out_fp, "%s %s %s %s\n", name, socialSecurityNum, id, pw);
            break;
            }
          case 2: // "1.2. 회원탈퇴"
            {
            //삭제어떻게함..?
            signOutClient= new signOut(loginClient);
            fprintf(out_fp, "1.2. 회원탈퇴\n");
            fprintf(out_fp, "%s\n", signOutClient->getSignOutClient());
            break;
            }
        }
        break;
      }
      
      case 2:
       {
         switch(menu_level_2)
          {
          case 1: //"2.1. 로그인"
            { 
              int i;
              bool existed= false;
              fscanf(in_fp, "%s %s", id, pw);
              
              for(i=0 ; i< num+1 ; i++){
                if(clientList[i]->getClientId() == id){
                  existed= true;
                }
              }

              if(existed == true){
                loginClient= new login(id, pw);
                fprintf(out_fp, "2.1. 로그인\n");
                fprintf(out_fp, "%s %s\n", id, pw);                
              }

              break;
            }
            
          case 2: //"2.2. 로그아웃"
            {
              logoutClient= new logout(loginClient);
              fprintf(out_fp, "2.2. 로그아웃\n");
              fprintf(out_fp, "%s\n", logoutClient->getLogoutClient());
              break;
            }          
          }
         break;
        }
    }
  }
}


/*


      case 3:
        {
          switch(menu_level_2)
            {
              case1:
                //판매의류등록();
              case2:
                //등록상품조회();
              case3:
                //판매완료상품조회();
            }
        }
      case 4:
        {
          switch(menu_level_2)
            {
              case1:
                //상품정보검색();
              case2:
                //상품구매();
              case3:
                //상품구매내역조회();
              case4:
                //상품구매만족도평가();
            }
        }
      case 5:
        {
          switch(menu_level_2)
            {
              case 1:
                //판매상품통계();
            }
        }
      case 6:
        {
          switch(menu_level_2)
            {
              case 1:
                //종료();
            }
        }
  } 
  return;
}
 
 
void join() 
{
   char user_type[MAX_STRING], name[MAX_STRING], SSN[[MAX_STRING], 
        address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
   // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
   fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);
   // 해당 기능 수행  
 
   // 출력 형식
   fprintf(out_fp, "1.1. 회원가입\n");
   fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}
*/
/*
void program_exit()    
{

}
*/