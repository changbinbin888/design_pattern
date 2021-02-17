#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;
class Product
{
private:
    /* data */
public:
    Product(/* args */){};
    ~Product(){};
    virtual void BeProducted()
    {
        cout << "Base BeProducted" << endl;
    }

    virtual void BeSelled()
    {
        cout << "Base BeSelled" << endl;
    }
};

class House : public Product
{
private:
    /* data */
public:
    House(/* args */){};
    ~House(){};
    void BeProducted()
    {
        cout << "build house" << endl;
    }

    void BeSelled()
    {
        cout << "sell house" << endl;
    }

};

class Ipod : public Product
{
private:
    /* data */
public:
    Ipod(/* args */){};
    ~Ipod(){};
    void BeProducted()
    {
        cout << "build ipod" << endl;
    }

    void BeSelled()
    {
        cout << "sell ipod" << endl;
    }

};


class Corp
{
private:
    /* data */
protected:
    Product* product = NULL;
public:
    Corp(/* args */){};
    ~Corp(){};
    Corp(Product* product)
    {
        this->product = product;
    }
    virtual void MakeMoney()
    {
        this->product->BeProducted();
        this->product->BeSelled();
        cout << "Base MakeMoney" << endl;
    }
    
};

class HouseCorp : public Corp
{
private:
    /* data */
public:
    HouseCorp(/* args */){};
    ~HouseCorp(){};
    HouseCorp(Product* product)
    {
        this->product = product;
    }

    void MakeMoney()
    {
        this->product->BeProducted();
        this->product->BeSelled();
        cout << "HouseCorp MakeMoney" << endl;
    }
};

class ShanZhaiCorp : public Corp
{
private:
    /* data */
public:
    ShanZhaiCorp(/* args */){};
    ~ShanZhaiCorp(){};
    ShanZhaiCorp(Product* product)
    {
        this->product = product;
    }

    void MakeMoney()
    {
        this->product->BeProducted();
        this->product->BeSelled();
        cout << "ShanZhaiCorp MakeMoney" << endl;
    }
};

int main()
{
    cout<<"main func"<<endl;
    House* house = new House();
    HouseCorp* houseCorp = new HouseCorp(house);
    houseCorp->MakeMoney();
    ShanZhaiCorp* shanzhaiCorp = new ShanZhaiCorp(new Ipod());
    shanzhaiCorp->MakeMoney();
    return 0;
}