#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

class SchoolReport
{
private:
    /* data */
public:
    SchoolReport(/* args */){};
    ~SchoolReport(){};
    virtual void Report()
    {
        cout << "The score is 66" << endl;
    }
    virtual void Sign(const string& name)
    {
        cout << "Father:" << name << endl;
    }
};

class Decorator : public SchoolReport
{
protected:
    /* data */
    SchoolReport* sr = NULL;
public:
    Decorator(/* args */){};
    ~Decorator(){};
    Decorator(SchoolReport* sr)
    {
        this->sr = sr;
    }

    virtual void Report()
    {
        this->sr->Report();
    }

    virtual void Sign(const string& name)
    {
        this->sr->Sign(name);
    }
};

class HighScoreDecorator : public Decorator
{
private:
    /* data */
public:
    HighScoreDecorator(/* args */){};
    ~HighScoreDecorator(){};
    HighScoreDecorator(SchoolReport* sr)
    {
        this->sr = sr;
    }
    void ReportHighScore()
    {
        cout << "The highest score is xxx" << endl;
    }

    virtual void Report()
    {
        this->ReportHighScore();
        this->sr->Report();
    }
};

class SortDecorator : public Decorator
{
private:
    /* data */
public:
    SortDecorator(/* args */){};
    ~SortDecorator(){};
    SortDecorator(SchoolReport* sr)
    {
        this->sr = sr;
    }
    void ReportSort()
    {
        cout << "The sort is xxx" << endl;
    }

    void Report()
    {
        this->sr->Report();
        this->ReportSort();
    }
};


int main()
{
    cout<<"main func"<<endl;
    SchoolReport* sr = new SchoolReport;
    //加了最高分说明的成绩单
    sr = new HighScoreDecorator(sr);
    //又加了成绩排名的说明
    sr = new SortDecorator(sr);
    //看成绩单
    sr->Report();
    //然后老爸一看，很开心，就签名了
    sr->Sign("老三");
    return 0;
}