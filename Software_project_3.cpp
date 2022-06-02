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

// 회원 entity class
class Client {
private:
    string id;
    string pw;
    string name;
    string socialSecurityNum;

public:
    void createNewClient(string name, string socialSecurityNum, string id,
        string pw) {
        this->id = id;
        this->pw = pw;
        this->name = name;
        this->socialSecurityNum = socialSecurityNum;
    }
    void removeClient(Client* client) { delete[] client; }
    string getClientId() { return this->id; }
    string getClientPw() { return this->pw; }
};

class Product {
private:
    string name;
    string price;
    string company;
    int quantity;
    int satisfied;
    string clientId;
    int buycnt;
public:
    Product(string name, string price, string company, int quantity,
        int satisfied, string clientId, int buycnt) {
        this->name = name;
        this->price = price;
        this->company = company;
        this->quantity = quantity;
        this->satisfied = satisfied;
        this->clientId = clientId;
        this->buycnt = buycnt;
    }
    void removeProduct(Product* product) { delete[] product; }
    string getName() { return this->name; }
    string getPrice() { return this->price; }
    string getCompany() { return this->company; }
    int getQuantity() { return this->quantity; }
    int getSatisfied() { return this->satisfied; }
    string getClientId() { return this->clientId; }
    int getBuyCnt() { return this->buycnt; }
    void setBuyCnt() { this->buycnt = buycnt + 1; }
    void setSatisfied(int sc) { this->satisfied = satisfied + sc; }
    int getAvgSatisfied() {
        int ret = satisfied / buycnt;
        return ret;
    }
    int getrateProduct() {
        int sum = quantity + 111;
        return sum;

    }

};

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
                product->getSatisfied(), product->getClientId(), product->getBuyCnt()));
    }
    vector<Product*> getProductVec() { return this->orderVec; }
    string getClientId() { return this->clientId; }
};

Client* clientList[100];

//회원가입 control class
class signUp { // addclient-> signup 변경 (다이어그램)
public:
    signUp(string name, string socialSecurityNum, string id, string pw) {
        clientList[++num] = new Client();
        clientList[num]->createNewClient(name, socialSecurityNum, id, pw);
    }
};

//로그인 control class
class login {
private:
    Client* loginClient;

public:
    login(string id, string pw) {
        for (int i = 0; i < num + 1; i++) {
            if (clientList[i]->getClientId() == id) {
                if (clientList[i]->getClientPw() == pw)
                    this->loginClient = clientList[i];
            }
        }
    }
    Client* getCurrentClient() { return this->loginClient; }
};

//로그아웃 control class
class logout {
private:
    Client* logoutClient;

public:
    logout(login* loginClient) {
        this->logoutClient = loginClient->getCurrentClient();
    }
    string getLogoutClientId() { return logoutClient->getClientId(); }
};

//회원탈퇴 control class
class signOut { // deleteclient-> signOut 변경 (다이어그램)
private:
    Client* signOutClient;

public:
    signOut(login* loginClient) {
        this->signOutClient = loginClient->getCurrentClient();
    }
    string getSignOutClientId() { return signOutClient->getClientId(); }
};

// 판매의류등록
Product* productList[100];

class addSellProduct {
public:
    addSellProduct(string name, string price, string company, int quantity,
        int satisfied, string clientId, int buycnt) {
        productList[++num1] =
            new Product(name, price, company, quantity, satisfied, clientId, buycnt);
    }
};

// 판매완료상품조회
Product* soldProductList[100];
int num2 = -1;
class showSoldProductList {
public:
    showSoldProductList() {
        for (int i = 0; i < num1 + 1; i++) {
            if (productList[i]->getQuantity() == 0) {
                soldProductList[++num2] = productList[i];
            }
        }
    }
};

// 상품정보검색
class SearchProduct {
public:
    string searchProductByName(string name) {
        for (int i = 0; i < num1 + 1; i++) {
            if (productList[i]->getName() == name)
                return productList[i]->getClientId();
        }
    }
};

// 상품구매
class BuyProduct {
public:
    Product* getProduct(int i) { return productList[i]; }
    void getIntoOrderList(string clientId, Product* product) {
        OrderList(clientId, product);
    }
};

// 상품 구매 내역 조회

int main() {
    // 파일 입출력을 위한 초기화
    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();
    return 0;
}

void doTask() {
    signUp* signUpClient;
    signOut* signOutClient;
    addSellProduct* addedProduct;
    showSoldProductList* soldedProduct;
    login* loginClient;
    logout* logoutClient;
    char name[MAX_STRING], socialSecurityNum[MAX_STRING], id[MAX_STRING],
        pw[MAX_STRING];
    char searchName[MAX_STRING];
    OrderList* orderL;
    // 메뉴 파싱을 위한 level 구분을 위한 변수
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
                signUpClient = new signUp(name, socialSecurityNum, id, pw);
                fprintf(out_fp, "1.1. 회원가입\n");
                fprintf(out_fp, "%s %s %s %s\n", name, socialSecurityNum, id, pw);
                break;
            case 2: // "1.2. 회원탈퇴"
                //삭제어떻게함..?
                signOutClient = new signOut(loginClient);
                fprintf(out_fp, "1.2. 회원탈퇴\n");
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

                loginClient = new login(id, pw);
                fprintf(out_fp, "2.1. 로그인\n");
                fprintf(out_fp, "%s %s\n", id, pw);

                break;
            }
            case 2: //"2.2. 로그아웃"
            {
                logoutClient = new logout(loginClient);
                fprintf(out_fp, "2.2. 로그아웃\n");
                fprintf(out_fp, "%s\n", logoutClient->getLogoutClientId().c_str());
                break;
            }

            }
            break;

        }
        case 3: {
            switch (menu_level_2) {
            case 1: {
                char name[MAX_STRING], price[MAX_STRING], company[MAX_STRING];
                int quantity;
                int satisfied1 = 0;
                int buycnt = 1;
                string currId = loginClient->getCurrentClient()->getClientId();
                fscanf(in_fp, "%s %s %s %d", name, price, company, &quantity
                );
                addedProduct = new addSellProduct(name, price, company, quantity,
                    satisfied1, currId, buycnt);
                fprintf(out_fp, "3.1. 판매의류등록\n");
                fprintf(out_fp, "%s %s %s %d\n", name, price, company, quantity
                );
                break;
            }
            case 2: {
                fprintf(out_fp, "3.2. 등록상품조회\n");
                for (int i = 0; i < num1 + 1; i++) {
                    fprintf(out_fp, "%s %s %s %d %d\n", productList[i]->getName().c_str(),
                        productList[i]->getPrice().c_str(),
                        productList[i]->getCompany().c_str(),
                        productList[i]->getQuantity(),
                        productList[i]->getSatisfied());
                }
                break;
            }
            case 3: {
                soldedProduct = new showSoldProductList();
                fprintf(out_fp, "3.3. 판매완료상품조회\n");
                for (int i = 0; i < num2 + 1; i++) {
                    fprintf(out_fp, "%s %s %s %d %d\n",
                        soldProductList[i]->getName().c_str(),
                        soldProductList[i]->getPrice().c_str(),
                        soldProductList[i]->getCompany().c_str(),
                        soldProductList[i]->getQuantity(),
                        soldProductList[i]->getSatisfied());
                }
                break;
            }
            }
            break;
        }
        case 4: {
            switch (menu_level_2) {
            case 1: {
                fscanf(in_fp, "%s", searchName);
                for (int i = 0; i < num1 + 1; i++) {
                    if (productList[i]->getName() == searchName)
                        selectedIndex = i;
                    fprintf(out_fp, "4.1. 상품정보검색\n");
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
            case 2: {
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                p->setBuyCnt();
                fprintf(out_fp, "4.2. 상품구매\n");
                fprintf(out_fp, "%s %s\n", p->getClientId().c_str(),
                    p->getName().c_str());
                break;
            }
            case 3: {
                string cid = loginClient->getCurrentClient()->getClientId();
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                orderL = new OrderList(cid, p);
                Product* vec0 = orderL->getProductVec()[0];
                fprintf(out_fp, "4.3. 상품구매내역조회\n");
                fprintf(out_fp, "%s %s %s %s %d %d\n", vec0->getClientId().c_str(),
                    vec0->getName().c_str(), vec0->getCompany().c_str(),
                    vec0->getPrice().c_str(), vec0->getQuantity(),
                    vec0->getAvgSatisfied());
                break;
            }
            case 4: {
                int score;
                fscanf(in_fp, "%d", &score);
                BuyProduct* by = new BuyProduct();
                Product* p = by->getProduct(selectedIndex);
                p->setSatisfied(score);
                fprintf(out_fp, "4.4. 상품구매내역조회\n");
                fprintf(out_fp, "%s %s %d\n", p->getClientId().c_str(), p->getName().c_str(), p->getSatisfied());
                break;
            }
            }
            break;
        }
        case 5: {
            switch (menu_level_2) {
            case 1: {
                
                for (int i = 0; i < num1 + 1; i++) {
                        if (productList[i]->getName() == searchName)
                            
                        fprintf(out_fp, "5.1. 판매 상품 통계 \n");
                        fprintf(out_fp, "%s %d %d \n",productList[i]->getName().c_str(),productList[i]->getrateProduct(),
                        productList[i]->getAvgSatisfied());
                    }
                break;
            }
            }
            break;
        }
        case 6: {
            switch (menu_level_2) {
            case 1: {
                fprintf(out_fp, "6.1 .종료 \n");
                break;

            }
            }
            break;
        }
        }
    }
}