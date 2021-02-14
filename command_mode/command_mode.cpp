#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

class Group
{
private:
    /* data */
public:
    virtual void Find() = 0;
    virtual void Add() = 0;
    virtual void Delete() = 0;
    virtual void Change() = 0;
    virtual void Plan() = 0;
};

class RequirementGroup : public Group
{
private:
    /* data */
public:
    void Find()
    {
        cout << "Find RequirementGroup" << endl;
    }

    void Add()
    {
        cout << "Add a Requirement" << endl;
    }

    void Delete()
    {
        cout << "Delete a Requirement" << endl;
    }

    void Change()
    {
        cout << "Change a Requirement" << endl;
    }

    void Plan()
    {
        cout << "Change the plan" << endl;
    }
};


class PageGroup : public Group
{
private:
    /* data */
public:
    void Find()
    {
        cout << "Find PageGroup" << endl;
    }

    void Add()
    {
        cout << "Add a Page" << endl;
    }

    void Delete()
    {
        cout << "Delete a Page" << endl;
    }

    void Change()
    {
        cout << "Change a Page" << endl;
    }

    void Plan()
    {
        cout << "Change the plan" << endl;
    }
};


class CodeGroup : public Group
{
private:
    /* data */
public:
    void Find()
    {
        cout << "Find CodeGroup" << endl;
    }

    void Add()
    {
        cout << "Add a function" << endl;
    }

    void Delete()
    {
        cout << "Delete a function" << endl;
    }

    void Change()
    {
        cout << "Change a function" << endl;
    }

    void Plan()
    {
        cout << "Change the plan" << endl;
    }
};

class Command
{
private:
    /* data */
public:
    RequirementGroup rgObj;
    PageGroup pgObj;
    CodeGroup cgObj;
    virtual void Execute()
    {
        cout << "base Command execute" << endl;
    }
};

class AddRequirementCommand : public Command
{
private:
    /* data */
public:
    virtual void Execute()
    {
        this->rgObj.Find();
        this->rgObj.Add();
        this->rgObj.Plan();
    }
};

class DelRequirementCommand : public Command
{
private:
    /* data */
public:
    virtual void Execute()
    {
        this->rgObj.Find();
        this->rgObj.Delete();
        this->rgObj.Plan();
    }
};

class Invoker
{
private:
    Command* command = NULL;
public:
    void SetCommand(Command* command)
    {
        this->command = command;
    }
    void Action()
    {
        this->command->Execute();
    }
};

class Client
{
private:
    /* data */
public:
    void AddReq()
    {
        Invoker invoker;
        AddRequirementCommand* command = new AddRequirementCommand;
        invoker.SetCommand(command);
        invoker.Action();
    }

    void DelReq()
    {
        Invoker invoker;
        DelRequirementCommand* command = new DelRequirementCommand;
        invoker.SetCommand(command);
        invoker.Action();
    }    
};


int main()
{
    cout<<"main func"<<endl;
    Client client;
    client.AddReq();
    client.DelReq();
    return 0;
}