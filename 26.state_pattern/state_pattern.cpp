#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

enum LiftStatusEnum
{
    OPEN_STATUS = 0,
    CLOSE_STATUS,
    RUN_STATUS,
    STOP_STATUS,
};

class LiftState
{
private:
    /* data */
    Context* context = NULL;
public:
    LiftState(/* args */){};
    ~LiftState(){};
    virtual void Open()
    {
        cout << "Base Open" << endl;
    }
    virtual void Close()
    {
        cout << "Base Close" << endl;
    }
    virtual void Run()
    {
        cout << "Base Run" << endl;
    }
    virtual void Stop()
    {
        cout << "Base Stop" << endl;
    }
    // void SetState(LiftStatusEnum liftState)
    // {
    //     this->state = liftState;
    // }
    void SetContext(Context* context)
    {
        this->context = context;
    }
};

class OpenningState
{
private:
    /* data */
public:
    OpenningState(/* args */){};
    ~OpenningState(){};
    void Open()
    {
        cout << "The lift open" << endl;
    }

    void Close()
    {
        this->context->SetLiftState(CLOSE_STATUS)
    }
};

class Context
{
private:
    /* data */
    LiftState* liftState;
public:
    Context(/* args */){};
    ~Context(){};

    void SetLiftState(LiftStatusEnum liftState)
    {
        this->liftState->SetLiftState(liftState);
    }

    LiftState* GetLiftState()
    {
        return this->liftState;
    }

    void Open()
    {
        this->liftState->Open();
    }

    void Close()
    {
        this->liftState->Close();
    }

    void Run()
    {
        this->liftState->Run();
    }

    void Stop()
    {
        this->liftState->Stop();
    }
};







int main()
{
    cout<<"main func"<<endl;
    
    
    return 0;
}