#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

enum RequestLevel
{
    FATHER_LEVEL_REQUEST = 0,
    HUSBAND_LEVEL_REQUEST,
    SON_LEVEL_REQUEST
};

class Woman
{
private:
    int type = -1;
    string request = "";
public:
    Woman(/* args */){};
    ~Woman(){};
    Woman(int type, const string& request)
    {
        this->type = type;
        this->request = request;
    }
    //获得自己的状况
    int GetType()
    {
        return this->type;
    }
    //获得妇女的请求
    string GetRequest()
    {
        return this->request;
    }
};


class Handler
{
private:
    /* data */
    int level = -1;
    Handler* nextHandler = NULL;
public:
    Handler(/* args */){};
    ~Handler(){};
    Handler(int level)
    {
        this->level = level;
    }
    virtual void Response(Woman woman)
    {
        cout << "base Response" << endl;
    }
    virtual void HandleMessage(Woman woman) final
    {
        if (woman.GetType() == this->level) {
            this->Response(woman);
        } else {
            if (this->nextHandler != NULL)
            {
                this->nextHandler->HandleMessage(woman);
            } else {
                cout << "no handler!" << endl;
            }
        }       
    }
    void SetNext(Handler* nextHandler)
    {
        this->nextHandler = nextHandler;
    }
    void SetLevel(RequestLevel level)
    {
        this->level = level;
    }
};

class Father : public Handler
{
private:
public:
    Father(/* args */)
    {
        this->SetLevel(FATHER_LEVEL_REQUEST);
    };
    ~Father(){};
    void Response(Woman woman)
    {
        cout << "daughter request:" << endl;
        cout << woman.GetRequest() << endl;
        cout << "agree!" << endl;
    }
};

class Husband : public Handler
{
private:
    /* data */
public:
    Husband(/* args */)
    {
        this->SetLevel(HUSBAND_LEVEL_REQUEST);
    };
    ~Husband(){};
    void Response(Woman woman)
    {
        cout << "wife request:" << endl;
        cout << woman.GetRequest() << endl;
        cout << "agree!" << endl;
    }
};

class Son : public Handler
{
private:
    /* data */
public:
    Son(/* args */)
    {
        this->SetLevel(SON_LEVEL_REQUEST);
    };
    ~Son(){};
    void Response(Woman woman)
    {
        cout << "mother request:" << endl;
        cout << woman.GetRequest() << endl;
        cout << "agree!" << endl;
    }
};


// class Client
// {
// private:
//     /* data */
// public:

// };


int main()
{
    cout<<"main func"<<endl;
    // Client client;
    vector<Woman>women;
    for (int i = 0; i < 4; i++) {
        Woman woman(i, "shopping");
        women.push_back(woman);
    }

    Father* father = new Father;
    Husband* husband = new Husband;
    Son* son = new Son;
    father->SetNext(husband);
    husband->SetNext(son);

    vector<Woman>::iterator it;
    for (vector<Woman>::iterator it = women.begin(); it != women.end(); it++)
    {
        father->HandleMessage(*it);
    }
        
    return 0;
}