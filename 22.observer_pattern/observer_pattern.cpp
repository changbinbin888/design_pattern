#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

class Observer
{
private:
    /* data */
public:
    Observer(/* args */){};
    ~Observer(){};
    virtual void Update()
    {
        cout << "base update" << endl;
    }
};

class LiSi : public Observer
{
private:
    /* data */
public:
    LiSi(/* args */){};
    ~LiSi(){};
    void Update()
    {
        cout << "lisi update" << endl;
    }
};

class WangSi : public Observer
{
private:
    /* data */
public:
    WangSi(/* args */){};
    ~WangSi(){};
    void Update()
    {
        cout << "WangSi update" << endl;
    }
};

class HanFeiZi
{
private:
    vector<Observer*> allObserver;
public:
    HanFeiZi(/* args */){};
    ~HanFeiZi(){};
    void AddObserver(Observer* observer)
    {
        allObserver.push_back(observer);
    }

    void DelObserver(Observer* observer)
    {
        for (vector<Observer*>::iterator it = allObserver.begin(); it != allObserver.end(); it++) {
            if (*it == observer) {
                it = allObserver.erase(it);
                break;
            }
        }
    }

    void NotifyObserver()
    {
        vector<Observer*>::iterator it;
        for (it = allObserver.begin(); it != allObserver.end(); it++) {
            (*it)->Update();
        }
    }

    void Cry()
    {
        cout << "hanfeizi cry" << endl;
        NotifyObserver();
    }

};


int main()
{
    cout<<"main func"<<endl;
    
    LiSi lisi;
    WangSi wangsi;
    HanFeiZi hanfeizi;
    hanfeizi.AddObserver(&lisi);
    hanfeizi.AddObserver(&wangsi);
    hanfeizi.Cry();
    return 0;
}