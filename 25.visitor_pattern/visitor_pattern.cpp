#include <iostream>
#include <vector>
#include <string.h>
#include <process.h>
#include <windows.h>

using namespace std;

class IVisitor;
class Employee
{
private:
    /* data */
    int salary;
    string name;
public:
    Employee(/* args */){};
    ~Employee(){};
    void SetSalary(int salary)
    {
        this->salary = salary;
    }

    int GetSalary()
    {
        return this->salary;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    string GetName()
    {
        return this->name;
    }

    virtual void Accept(IVisitor* visitor);
};

class CommonEmployee : public Employee
{
private:
    /* data */
public:
    CommonEmployee(/* args */){};
    ~CommonEmployee(){};
    void Accept(IVisitor* visitor);
};


class Manager : public Employee
{
private:
    /* data */
public:
    Manager(/* args */){};
    ~Manager(){};
    void Accept(IVisitor* visitor);
};




class IVisitor
{
private:
    /* data */
public:
    IVisitor(/* args */){};
    ~IVisitor(){};
    virtual void Visit(CommonEmployee* commonEmployee)
    {
        cout << "Base CommonEmployee Visit" << endl;
    }

    virtual void Visit(Manager* manager)
    {
        cout << "Base Manager Visit" << endl;
    }
};

class Visitor : public IVisitor
{
private:
    /* data */
public:
    Visitor(/* args */){};
    ~Visitor(){};
    void Visit(CommonEmployee* commonEmployee)
    {
        cout << "commonEmployee name is " << commonEmployee->GetName() << "salary is " << commonEmployee->GetSalary() << endl;
    }

    void Visit(Manager* manager)
    {
        cout << "manager name is " << manager->GetName() << "salary is " << manager->GetSalary() << endl;
    }
};


void Employee::Accept(IVisitor* visitor)
{
    visitor->Visit(this);
}

void CommonEmployee::Accept(IVisitor* visitor)
{
    visitor->Visit(this);
}

void Manager::Accept(IVisitor* visitor)
{
    visitor->Visit(this);
}

int main()
{
    cout<<"main func"<<endl;
    
    vector<Employee*> allEmployee;
    CommonEmployee* zhangsan = new CommonEmployee();
    Manager* Lisi = new Manager();
    allEmployee.push_back(zhangsan);
    allEmployee.push_back(Lisi);

    Visitor* visitor = new Visitor();
    for (vector<Employee*>::iterator it = allEmployee.begin(); it != allEmployee.end(); it++)
    {
        (*it)->Accept(visitor);
    }

    return 0;
}