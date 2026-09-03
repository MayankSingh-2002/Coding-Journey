#include<iostream>
using namespace std;

class Employee {
    public:
    static int count;
    int EmpID;
    string name;
    int salary;

    Employee(int EmpId,string name, int salary) {
        this->EmpID = EmpId;
        this->name = name;
        this->salary = salary;
        count++;
    }
    void getdata(){
        cout << "Employee ID: " << EmpID << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary " << salary << endl;
    }

    void Emp_count(){
        cout << "No. of employee: " << count << endl;
    }
};


int Employee::count = 0;

int main(){
    Employee p1(111, "Raj", 25000);
    Employee p2(112, "Manjit", 30000);
    p1.getdata();
    p1.Emp_count();
    p2.getdata();
    p2.Emp_count();
    cout << Employee::count;
}