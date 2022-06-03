// 헤더 선언
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
int num1 = -1;
// 함수 선언
void doTask();
void join();
void program_exit();
// 변수 선언
FILE* in_fp, * out_fp;
int num = -1;

//UI 선언

// Class : UI
// Descriptiom : signupUI 출력
// created : 2022/05/30
// Author : 윤경
class SignUpUI {
public:

// Function : void fileWrite() - UI 출력
//Discription : UI를 주어진 파일에 Write한다.
//Parameters : x
//Return Value : x
//Created : 2022/05/30
//Author : 윤경
    void fileWrite() {
        fprintf(out_fp, "1.1. 회원가입\n");
    }
};


// Class : UI
// Descriptiom : SignOutUI 출력
// created : 2022/05/30
// Author : 윤경
class SignOutUI {

    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/30
    //Author : 윤경
public:
    void fileWrite() {
        fprintf(out_fp, "1.2. 회원탈퇴\n");
    }
};


// Class : UI
// Descriptiom : LoginUI 출력
// created : 2022/05/30
// Author : 윤경
class LoginUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/30
    //Author : 윤경
public:
    void fileWrite() {
        fprintf(out_fp, "2.1. 로그인\n");
    }
};

// Class : UI
// Descriptiom : LogoutUI 출력
// created : 2022/05/30
// Author : 윤경
class LogoutUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/30
    //Author : 윤경
public:
    void fileWrite() {
        fprintf(out_fp, "2.2. 로그아웃\n");
    }
};

// Class : UI
// Descriptiom : AddSellProductUI 출력
// created : 2022/05/31
// Author : 승환
class AddSellProductUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "3.1. 판매의류등록\n");
    }
};

// Class : UI
// Descriptiom : ShowSellDataUI 출력
// created : 2022/05/31
// Author : 승환
class ShowSellDataUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "3.2. 등록상품조회\n");
    }
};

// Class : UI
// Descriptiom : ShowSoldProductListUI 출력
// created : 2022/05/31
// Author : 승환
class ShowSoldProductListUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "3.3. 판매완료상품조회\n");
    }
};

// Class : UI
// Descriptiom : SearchProductUI 출력
// created : 2022/05/31
// Author : 승환
class SearchProductUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "4.1. 상품정보검색\n");
    }
};

// Class : UI
// Descriptiom : BuyProductUI 출력
// created : 2022/05/31
// Author : 승환
class BuyProductUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "4.2. 상품구매\n");
    }
};

// Class : UI
// Descriptiom : ShowBuyListUI 출력
// created : 2022/05/31
// Author : 승환
class ShowBuyListUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "4.3. 상품 구매내역 조회\n");
    }
};

// Class : UI
// Descriptiom : EvalSatisfyUI 출력
// created : 2022/05/31
// Author : 승환
class EvalSatisfyUI {

    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/05/31
    //Author : 승환
public:
    void fileWrite() {
        fprintf(out_fp, "4.4. 상품 구매만족도 평가\n");
    }
};


// Class : UI
// Descriptiom : Show_static_soldoutUI 출력
// created : 2022/06/01
// Author : 민욱
class ShowStaticSoldoutUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/06/01
    //Author : 민욱
public:
    void fileWrite() {
        fprintf(out_fp, "5.1. 판매 상품 통계\n");
    }
};

// Class : UI
// Descriptiom : Program_ExitUI 출력
// created : 2022/06/01
// Author : 민욱
class ProgramExitUI {
    // Function : void fileWrite() - UI 출력
    //Discription : UI를 주어진 파일에 Write한다.
    //Parameters : x
    //Return Value : x
    //Created : 2022/06/01
    //Author : 민욱
public:
    void fileWrite() {
        fprintf(out_fp, "6.1. 종료\n");
    }
};


// Class : Client
// Descriptiom : 회원의 속성과,생성자,함수들을 선언
// created : 2022/05/28
// Author : 윤경
class Client {
private:
    string id;
    string pw;
    string name;
    string socialSecurityNum;

public:
    // Function :  void createNewClient(string name, string socialSecurityNum, string id,string pw)
    //Discription : 새로운 고객 객체 생성
    //Parameters : string name - 이름, string socialSecurityNum - 주민번호 , string id -아이디,string pw - 비밀번호
    //Return Value : x 
    //Created : 2022/05/28
    //Author : 윤경
    void createNewClient(string name, string socialSecurityNum, string id,
        string pw) {
        this->id = id;
        this->pw = pw;
        this->name = name;
        this->socialSecurityNum = socialSecurityNum;
    }

    // Function : void removeClient(Client* client) 
    //Discription : 등록된 고객 객체 삭제
    //Parameters : client - 고객 객체
    //Return Value : x
    //Created : 2022/05/28
    //Author : 윤경
    void removeClient(Client* client) { delete[] client; }


    // Function : string getClientId()
    //Discription : 고객의 아이디를 반환
    //Parameters : x 
    //Return Value : 고객의 ID
    //Created : 2022/05/28
    //Author : 윤경
    string getClientId() { return this->id; }


    // Function : getClientPw()
    //Discription : 고객의 비밀번호 반환
    //Parameters : x
    //Return Value : 고객의 비밀번호
    //Created : 2022/05/28
    //Author : 윤경
    string getClientPw() { return this->pw; }
};

// Class : Product
// Descriptiom : 제품의 속성과,생성자,함수들을 선언
// created : 2022/05/28
// Author : 민욱
class Product {
private:
    string name;
    string price;
    string company;
    int quantity;
    int satisfied;
    string clientId;
    int buycnt;
    int soldcnt;
public:

    Product(string name, string price, string company, int quantity,
        int satisfied, string clientId, int buycnt , int sellcnt) {
        this->name = name;
        this->price = price;
        this->company = company;
        this->quantity = quantity;
        this->satisfied = satisfied;
        this->clientId = clientId;
        this->buycnt = buycnt;
    }

    // Function : removeProduct(Product* product)
    //Discription : 제품 객체 제거
    //Parameters : product - 제품
    //Return Value : x 
    //Created : 2022/05/28
    //Author : 민욱
    void removeProduct(Product* product) { delete[] product; }

    // Function : string getName()
    //Discription : 제품의 이름 반환
    //Parameters : x
    //Return Value : 제품의 이름
    //Created : 2022/05/28
    //Author : 민욱
    string getName() { return this->name; }

    // Function :   string getPrice() 
    //Discription : 제품의 가격 반환
    //Parameters : x
    //Return Value : 제품의 가격
    //Created : 2022/05/28
    //Author : 민욱
    string getPrice() { return this->price; }


    // Function :  string getCompany()
    //Discription : 제품의 회사 반환
    //Parameters : x
    //Return Value : 제품의 회사
    //Created : 2022/05/28
    //Author : 민욱
    string getCompany() { return this->company; }

    // Function : int getQuantity()
    //Discription : 제품의 수량 반환
    //Parameters : x
    //Return Value : 제품의 수량
    //Created : 2022/05/28
    //Author : 민욱
    int getQuantity() { return this->quantity; }

    // Function : int getSatisfied()
    //Discription : 제품의 만족도 총합 반환
    //Parameters : x
    //Return Value : 제품의 만족도 총합
    //Created : 2022/05/28
    //Author : 민욱
    int getSatisfied() { return this->satisfied; }

    // Function : string getClientId()
    //Discription : 고객의 id 반환
    //Parameters : x
    //Return Value : 고객의 id
    //Created : 2022/05/28
    //Author : 민욱
    string getClientId() { return this->clientId; }

    // Function :  int getBuyCnt() 
    //Discription : 제품의 구매횟수 반환
    //Parameters : x
    //Return Value : 제품의구매횟수
    //Created : 2022/05/28
    //Author : 민욱
    int getBuyCnt() { return this->buycnt; }

    
    // Function : int getSoldCnt()
    //Discription : 제품의 판매횟수 반환
    //Parameters : x
    //Return Value : 제품의 판매 횟수
    //Created : 2022/05/28
    //Author : 민욱
    int getSoldCnt()  { return this->soldcnt; }


    // Function : void setSold() 
    //Discription : 제품 판매시 제품의 수량 감소
    //Parameters :  x
    //Return Value : 제품의 양
    //Created : 2022/05/28
    //Author : 민욱
    void setSold() { this->quantity = quantity - 1; }


    // Function : void setSoldcnt()
    //Discription : 제품 판매시 판매 수량 증가
    //Parameters :  x
    //Return Value : 판매수량
    //Created : 2022/05/28
    //Author : 민욱
    void setSoldcnt() { this->soldcnt = soldcnt + 1; }

    // Function :  void setBuyCnt()
    //Discription : 제품의 구매수량 증가
    //Parameters :  x
    //Return Value :  제품의 구매 수량
    //Created : 2022/05/28
    //Author : 민욱
    void setBuyCnt() { this->buycnt = buycnt + 1; }

    // Function : void setSatisfied
    //Discription : 제품의 구매만족도 추가
    //Parameters : sc - 구매만족도
    //Return Value :   x 
    //Created : 2022/05/28
    //Author : 민욱
    void setSatisfied(int sc) { this->satisfied = satisfied + sc; }


    // Function : int getAvgSatisfied()
    //Discription : 구매만족도 평균을 반환
    //Parameters : x 
    //Return Value : 구매만족도의 평균
    //Created : 2022/05/28
    //Author : 민욱
    int getAvgSatisfied() {
        if (buycnt == 0)
            return 0;
        else
            return satisfied / buycnt;
    }


    // Function : int getTotalPrice()
    //Discription : 제품의 총 판매금액 반환
    //Parameters :  x
    //Return Value : 제품의 총 판매금액
    //Created : 2022/05/28
    //Author : 민욱
    int getTotalPrice() {
        int sum = quantity * 1;
        return sum;

    }

};


// Class : OrderList
// Descriptiom : 주문한 상품리스트의 속성과,함수들을 선언
// created : 2022/05/29
// Author : 승환
class OrderList {
private:
    string clientId;
    vector<Product*> orderVec;

public:
    OrderList(string clientId, Product* product) {
        this->clientId = clientId;
        this->orderVec.push_back(
            new Product(product->getName(), product->getPrice(),
                product->getCompany(), product->getQuantity(),
                product->getSatisfied(), product->getClientId(), product->getBuyCnt(),product->getSoldCnt()));
    }


    // Function : vector<Product*> getProductVec()
    //Discription : 제품의 리스트를 벡터 형태로 구현
    //Parameters :  x
    //Return Value : 제품의 리스트
    //Created : 2022/05/29
    //Author : 승환
    vector<Product*> getProductVec() { return this->orderVec; }


    // Function : string getClientId()
    //Discription : 고객의 id 반환
    //Parameters :  x
    //Return Value : 고객의 id
    //Created : 2022/05/29
    //Author : 승환
    string getClientId() { return this->clientId; }
};


// Class : SignUp
// Descriptiom : 회원가입시 필요한 속성과 함수들을 선언
// created : 2022/05/30
// Author : 윤경
Client* clientList[100];

class SignUp { 
public:
    void signUpClient(string name, string socialSecurityNum, string id, string pw){
      clientList[++num]= new Client();
      clientList[num]->createNewClient(name, socialSecurityNum, id, pw);
    }
};

// Class : Login
// Descriptiom : 로그인시 필요한 속성과 함수들을 선언
// created : 2022/05/30
// Author : 윤경
class Login {
private:
    Client* loginClient;

public:
     void clientLogin(string id, string pw){
      for(int i=0;i<num + 1; i++){
        if(clientList[i]->getClientId() == id){
          if(clientList[i]->getClientPw() == pw)
            this->loginClient = clientList[i];
        }
      }
    }
    // Function : Client* getCurrentClient()
    //Discription : 로그인시 고객의 객체 반환
    //Parameters :  x
    //Return Value : 고객의 객체
    //Created : 2022/05/30
    //Author : 윤경
    Client* getCurrentClient() { return this->loginClient; }
};

// Class : Logout
// Descriptiom : 로그아웃시 필요한 속성과 함수들을 선언
// created : 2022/05/30
// Author : 윤경
class Logout {
private:
    Client* logoutClient;

public:
    void clientLogout(Login* loginClient){
      this->logoutClient= loginClient->getCurrentClient();
    }
    // Function : string getLogoutClientId()
    //Discription : 로그아웃이 고객의 아이디 반환
    //Parameters :  x
    //Return Value : 고객의 아이디 반환
    //Created : 2022/05/30
    //Author : 윤경
    string getLogoutClientId() { return logoutClient->getClientId(); }
};

// Class : SignOut
// Descriptiom : 회원탈퇴시 필요한 속성과 함수들을 선언
// created : 2022/05/30
// Author : 윤경
class SignOut { // deleteclient-> signOut 변경 (다이어그램)
private:
    Client* signOutClient;

public:
    void clientSignOut(Login* loginClient){
      this->signOutClient= loginClient->getCurrentClient();
    }

    // Function : string getSignOutClientId()
    //Discription : 회원가입시 고객의 아이디 반환
    //Parameters :  x
    //Return Value : 고객의 ID
    //Created : 2022/05/30
    //Author : 윤경
    string getSignOutClientId() { return signOutClient->getClientId(); }
};


// Class : AddSellProduct
// Descriptiom : 판매상품들의 속성과,함수들을 선언
// created : 2022/05/29
// Author : 승환
Product* productList[100];
class AddSellProduct {
public:
    AddSellProduct(string name, string price, string company, int quantity,
        int satisfied, string clientId, int buycnt ,int sellcnt)  {
        productList[++num1] =
            new Product(name, price, company, quantity, satisfied, clientId, buycnt,sellcnt);
    }
};


// Class : ShowSoldProductList
// Descriptiom : 판매중인 상품들의 속성과,함수들을 선언
// created : 2022/05/29
// Author : 승환
int num2 = -1;
Product* soldProductList[100];
class ShowSoldProductList {
public:
    ShowSoldProductList() {
        for (int i = 0; i < num1 + 1; i++) {
            if (productList[i]->getQuantity() == 0) {
                soldProductList[++num2] = productList[i];
            }
        }
    }
};

// Class : SearchProduct
// Descriptiom : 상품 탐색리스트의 속성과,함수들을 선언
// created : 2022/05/29
// Author : 승환
class SearchProduct {
public:
    string searchProductByName(string name) {
        for (int i = 0; i < num1 + 1; i++) {
            if (productList[i]->getName() == name)
                return productList[i]->getClientId();
        }
    }
};

// Class : BuyProduct
// Descriptiom : 구매완료한 상품리스트의 속성과,함수들을 선언
// created : 2022/05/29
// Author : 승환
class BuyProduct {
public:
    Product* getProduct(int i) { return productList[i]; }
    void getIntoOrderList(string clientId, Product* product) {
        OrderList(clientId, product);
    }
};


// Function : int main() - 메인함수
//Discription : 입력파일의 읽기,쓰기 변수를 선언 및 주어진 작업 수행
//Parameters : x
//Return Value : 0
//Created : 2022/05/30
//Author : 윤경
int main() {

    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();
    return 0;
}

// Function : void doTask() - 과제에서 요구하는 요구사항들 수행
//Discription : 과제에서 주어진 요구사항을 수행하기위해 구현
//Parameters : x
//Return Value : x
//Created : 2022/05/28
//Author : 민욱

//Revision : 2022/05/30 승환,윤경   // case 1.1~ 4.4 까지 구현
//Revision : 2022/05/31 민욱 //  case 5.1, 6 구현 및 마무리 테스팅 및 디버깅
void doTask() {
    LoginUI* loginOutput;
    LogoutUI* logoutOutput;
    SignUpUI* signUpOutput;
    SignOutUI* signOutOutput;
    AddSellProductUI* addSellProductOutput;
    ShowSellDataUI* showSellDataOutput;
    ShowSoldProductListUI* showSoldProductListOutput;
    SearchProductUI* searchProductOutput;
    BuyProductUI* buyProductOutput;
    ShowBuyListUI* showBuyListUI;
    EvalSatisfyUI* eval_satisfyUI;
    ShowStaticSoldoutUI* show_static_soldoutUI;
    ProgramExitUI* program_ExitUI;
    SignUp* signUpNew;
    SignOut* signOutClient;
    AddSellProduct* addedProduct;
    ShowSoldProductList* soldedProduct;
    Login* loginClient;
    Logout* logoutClient;
    char name[MAX_STRING], socialSecurityNum[MAX_STRING], id[MAX_STRING],pw[MAX_STRING];
    char searchName[MAX_STRING];
    OrderList* orderL;
    int menu_level_1 = 1, menu_level_2 = 1;
    int is_program_exit = 0;
    int readcount;
    int selectedIndex = 0;

    while (!feof(in_fp)) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d", &menu_level_1, &menu_level_2);
        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
        case 1: {
            switch (menu_level_2) {
            case 1: // "1.1. 회원가입“
              fscanf(in_fp, "%s %s %s %s", name, socialSecurityNum, id, pw);
              signUpNew= new SignUp();
              signUpNew->signUpClient(name, socialSecurityNum, id, pw);
              signUpOutput= new SignUpUI();
              signUpOutput->fileWrite();
              fprintf(out_fp, "%s %s %s %s\n", name, socialSecurityNum, id, pw);
              break;
            case 2: // "1.2. 회원탈퇴"
              signOutClient = new SignOut();
              signOutClient->clientSignOut(loginClient);
              signOutOutput= new SignOutUI();
              signOutOutput->fileWrite();
              fprintf(out_fp, "%s\n", signOutClient->getSignOutClientId().c_str());
              break;
            }
            break;
        }

        case 2:
        {
            switch (menu_level_2)
            {
            case 1: //"2.1. 로그인"
            {
              int i;
              fscanf(in_fp, "%s %s", id, pw);
              
              loginClient = new Login();
              loginClient->clientLogin(id,pw);
              loginOutput= new LoginUI();
              loginOutput->fileWrite();
              
              fprintf(out_fp, "%s %s\n", id, pw);                

              break;
            }
            case 2: //"2.2. 로그아웃"
            {
              logoutClient= new Logout();
              logoutClient->clientLogout(loginClient);
              logoutOutput= new LogoutUI();
              logoutOutput->fileWrite();
              fprintf(out_fp, "%s\n", logoutClient->getLogoutClientId().c_str());
              break;
            }

            }
            break;

        }
        case 3: {
            switch (menu_level_2) {
            case 1: { //3.1 판매의류 등록
                char name[MAX_STRING], price[MAX_STRING], company[MAX_STRING];
                int quantity;
                int satisfied1 = 0;
                int buycnt = 1;
                int sellcnt = 0;
                string currId = loginClient->getCurrentClient()->getClientId();
                fscanf(in_fp, "%s %s %s %d", name, company, price, &quantity
                );
                addedProduct = new AddSellProduct(name, price, company, quantity,
                    satisfied1, currId, buycnt , sellcnt);
                addSellProductOutput = new AddSellProductUI();
                addSellProductOutput->fileWrite();
                fprintf(out_fp, "%s %s %s %d\n", name, company, price, quantity
                );
                break;
            }
            case 2: { //3.2 등록상품 조회
                showSellDataOutput = new ShowSellDataUI();
                showSellDataOutput->fileWrite();
                for (int i = 0; i < num1 + 1; i++) {
                    fprintf(out_fp, "%s %s %s %d \n", productList[i]->getName().c_str(),

                        productList[i]->getCompany().c_str(),
                        productList[i]->getPrice().c_str(),
                        productList[i]->getQuantity());
                        
                }
                break;
            }
            case 3: { //3.3 판매완료상품조회
                soldedProduct = new ShowSoldProductList();
                showSoldProductListOutput = new ShowSoldProductListUI();
                showSoldProductListOutput->fileWrite();
                for (int i = 0; i < num2 + 1; i++) {
                    fprintf(out_fp, "%s %s %s %d %d\n",
                        soldProductList[i]->getName().c_str(),
                        soldProductList[i]->getCompany().c_str(),
                        soldProductList[i]->getPrice().c_str(),
                        soldProductList[i]->getQuantity(), //판매된 수량  != 총 수량
                        soldProductList[i]->getSatisfied());
                }
                break;
            }
            }
            break;
        }
        case 4: {
            switch (menu_level_2) {
            case 1: { //4.1 상품정보검색
                fscanf(in_fp, "%s", searchName);
                for (int i = 0; i < num1 + 1; i++) {
                    if (productList[i]->getName() == searchName)
                        selectedIndex = i;
                    searchProductOutput = new SearchProductUI();
                    searchProductOutput->fileWrite();
                    fprintf(out_fp, "%s %s %s %s %d %d\n",
                        productList[i]->getClientId().c_str(),
                        productList[i]->getName().c_str(),
                        productList[i]->getCompany().c_str(),
                        productList[i]->getPrice().c_str(),
                        productList[i]->getQuantity(),
                        productList[i]->getAvgSatisfied());
                }
                break;
            }
            case 2: { //4.2 상품구매
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                p->setBuyCnt();
                p->setSold();
                p->setSoldcnt();
                buyProductOutput = new BuyProductUI();
                buyProductOutput->fileWrite();
                fprintf(out_fp, "%s %s\n", p->getClientId().c_str(),
                    p->getName().c_str());
                break;
            }
            case 3: { //4.3 구매내역 조회
                string cid = loginClient->getCurrentClient()->getClientId();
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                orderL = new OrderList(cid, p);
                Product* vec0 = orderL->getProductVec()[0];
                showBuyListUI = new ShowBuyListUI();
                showBuyListUI->fileWrite();
                fprintf(out_fp, "%s %s %s %s %d %d\n", vec0->getClientId().c_str(),
                    vec0->getName().c_str(), vec0->getCompany().c_str(),
                    vec0->getPrice().c_str(), vec0->getQuantity(),
                    vec0->getAvgSatisfied());
                break;
            }
            case 4: { //4.4 구매만족도 평가
                int score;
                fscanf(in_fp, "%d", &score);
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                p->setSatisfied(score);
                eval_satisfyUI = new EvalSatisfyUI();
                eval_satisfyUI->fileWrite();
                fprintf(out_fp, "%s %s %d\n", p->getClientId().c_str(), p->getName().c_str(), p->getSatisfied());
                break;
            }
            }
            break;
        }
        case 5: {
            switch (menu_level_2) {
            case 1: { //5.1 판매상품통계

                for (int i = 0; i < num1 + 1; i++) {
                    if (productList[i]->getName() == searchName)

                    show_static_soldoutUI = new ShowStaticSoldoutUI();
                    show_static_soldoutUI->fileWrite();
                    fprintf(out_fp, "%s %d %d \n", productList[i]->getName().c_str(), productList[i]->getTotalPrice(),
                        productList[i]->getAvgSatisfied());
                }
                break;
            }
            }
            break;
        }
        case 6: { 
            switch (menu_level_2) {
            case 1: { //6.1 종료
                program_ExitUI = new ProgramExitUI();
                program_ExitUI->fileWrite();
                break;

            }
            }
            break;
        }
        }
    }
}