#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

class Memento
{
private:
    /* data */
    string status = "";
public:
    Memento(/* args */){};
    ~Memento(){};
    Memento(string status)
    {
        this->status = status;
    }

    void SetStatus(string status)
    {
        this->status = status;
    }

    string GetStatus()
    {
        return this->status;
    }
};


class Boy
{
private:
    /* data */
    string status = "";
public:
    Boy(/* args */){};
    ~Boy(){};
    void SetStatus(string status)
    {
        this->status = status;
    }

    string GetStatus()
    {
        return this->status;
    }

    Memento* CreateMemento()
    {
        return new Memento(this->status);
    }

    void RestoreMemento(Memento* memento)
    {
        this->status = memento->GetStatus();
    }

    void ChangeStatus()
    {
        this->status = "unhappy";
    }
};

class Caretaker
{
private:
    /* data */
    Memento* mem = NULL;
public:
    Caretaker(/* args */){};
    ~Caretaker(){};

    Memento* GetMemento()
    {
        return this->mem;
    }

    void SetMemento(Memento* mem)
    {
        this->mem = mem;
    }

};

int main()
{
    cout<<"main func"<<endl;
    
    Boy boy;
    boy.SetStatus("very happy");
    cout << "boy status is " << boy.GetStatus() << endl;
    Caretaker caretaker;
    caretaker.SetMemento(boy.CreateMemento());
    boy.ChangeStatus();
    cout << "boy status is " << boy.GetStatus() << endl;
    boy.RestoreMemento(caretaker.GetMemento());
    cout << "boy status is " << boy.GetStatus() << endl;
    return 0;
}