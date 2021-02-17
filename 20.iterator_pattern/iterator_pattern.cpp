#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

typedef map<string, string> InfoMap;

class IUserInfo
{
private:
    /* data */
public:
    IUserInfo(/* args */){};
    ~IUserInfo(){};
    virtual string GetAddress()
    {
        string address = "xian";
        cout << "Base Class The address is" << address << endl;
        return address;
    }

    virtual string GetTel()
    {
        string tel = "130xxxx";
        cout << "Base Class The tel is" << tel << endl;
        return tel;
    }
};



class UserInfo : public IUserInfo
{
private:
    /* data */
public:
    UserInfo(/* args */){};
    ~UserInfo(){};
    string GetAddress()
    {
        string address = "xian";
        cout << "The address is" << address << endl;
        return address;
    }

    string GetTel()
    {
        string tel = "130xxxx";
        cout << "The tel is" << tel << endl;
        return tel;
    }
};

class OuterUser
{
private:
    /* data */
public:
    OuterUser(/* args */){};
    ~OuterUser(){};
    void GetAddress(InfoMap& map)
    {
        map.insert(pair<string, string>("address", "xianyang"));
    }

    void GetTel(InfoMap& map)
    {
        map.insert(pair<string, string>("tel", "123xxxx"));
    }
};

class OuterUserInfo : public IUserInfo
{
private:
    /* data */
    
    
    
public:
    OuterUserInfo(/* args */){};
    ~OuterUserInfo(){};

    
    // outerUser.GetTel(&telMap);

    string GetAddress()
    {
        string address = NULL;
        OuterUser outerUser;
        InfoMap addressMap;
        outerUser.GetAddress(addressMap);
        InfoMap::iterator it = addressMap.find("address");
        if (it != addressMap.end())
        {
            address = it->second;
            cout << "The address is" << address << endl;
        }
        return address;
    }

    string GetTel()
    {
        string tel = NULL;
        OuterUser outerUser;
        InfoMap telMap;
        outerUser.GetTel(telMap);
        InfoMap::iterator it = telMap.find("tel");
        if (it != telMap.end())
        {
            tel = it->second;
            cout << "The tel is" << tel << endl;
        }
        return tel;
    }

};



int main()
{
    cout<<"main func"<<endl;
    
        
    return 0;
}