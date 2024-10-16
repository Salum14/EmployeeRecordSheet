#include <iostream>
#include <string>
using namespace std;

class Employee {
// creating the variables for the employees data
// can only be access through public member functions
private:           
    string name;
    double salary;

// enables the employee name and data to be accessed by any function
public:
    void setName(const string& empName) {       
        name = empName;
    }
    void setSalary(double empSalary) {
        salary = empSalary;
    }
    string getName() const {
        return name;
    }
    double getSalary() const {
        return salary;
    }
};
// function prototypes
// allowing the compiler to know about the function and its signatures before implementation
// using arrays to store the 'employee` objects to store the employee data.
void input_employee_data(Employee employees[], int count);
void display_employee_data(const Employee employees[], int count);
double calculate_average_salary(const Employee employees[], int count);

int main() {
    // allowing the user to input up to 5 employees
    const int empCount = 5;
    Employee employees[empCount];

    // using input_employee_data & display_employee_data calculate & display the employees data
    input_employee_data(employees, empCount);
    display_employee_data(employees, empCount);

    // calculating and displaying the average salary using calculate_average_salary function
    double averageSalary = calculate_average_salary(employees, empCount);
    cout << "Average Salary: $" << averageSalary << endl;
    return 0;
}

void input_employee_data(Employee employees[], int count) {
    // using for loop to take in the employee's data
    for (int i = 0; i < count; i++) {
        string name;
        double salary;

        cout << "Enter name for employee " << (i + 1) << ": ";
        cin >> ws;      // To ignore whitespace
        getline(cin, name);
        employees[i].setName(name);     // storing names to the employee object

        cout << "Enter salary for employee " << (i + 1) << ": ";
        cin >> salary;
        employees[i].setSalary(salary);  // storing salary to the employee object
    }
}

void display_employee_data(const Employee employees[], int count) {
    cout << "\nEmployee Data:\n";
    cout << "....................\n";

    // getting each employee name and salary from the (void setSalary & getName)object class to display their data
    for (int i = 0; i < count; i++) {
        cout << left << "Employee Name: " << employees[i].getName()
        << " || Salary: "<< "$" << employees[i].getSalary() << endl;
    }
}

double calculate_average_salary(const Employee employees[], int count) {
    // calculating the average salary from the (void setSalary) object class
    double totalSalary = 0;
    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].getSalary();
    }
    return totalSalary / count;
}
