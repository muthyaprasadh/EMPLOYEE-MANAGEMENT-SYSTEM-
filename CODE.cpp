#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    
    Employee(int id, string name, string department, double salary)
        : id(id), name(name), department(department), salary(salary) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }

    void setName(const string& newName) { name = newName; }
    void setDepartment(const string& newDepartment) { department = newDepartment; }
    void setSalary(double newSalary) { salary = newSalary; }

    void display() const {
        cout << "ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "Department: " << department << "\n"
             << "Salary: $" << salary << "\n";
    }
};

class EmployeeManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee(int id, const string& name, const string& department, double salary) {
        employees.push_back(Employee(id, name, department, salary));
        cout << "Employee added successfully!\n";
    }

    void displayAllEmployees() const {
        for (const auto& employee : employees) {
            employee.display();
            cout << "-----------------------\n";
        }
    }

    void updateEmployee(int id) {
        for (auto& employee : employees) {
            if (employee.getId() == id) {
                string newName, newDepartment;
                double newSalary;
                cout << "Enter new name: ";
                cin >> newName;
                cout << "Enter new department: ";
                cin >> newDepartment;
                cout << "Enter new salary: ";
                cin >> newSalary;
                employee.setName(newName);
                employee.setDepartment(newDepartment);
                employee.setSalary(newSalary);
                cout << "Employee information updated successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }
};

int main() {
    EmployeeManagementSystem system;
    int choice;

    while (true) {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, department;
                double salary;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter Salary: ";
                cin >> salary;
                system.addEmployee(id, name, department, salary);
                break;
            }
            case 2:
                system.displayAllEmployees();
                break;
            case 3: {
                int id;
                cout << "Enter the ID of the employee to update: ";
                cin >> id;
                system.updateEmployee(id);
                break;
            }
            case 4:
                cout << "Exiting Employee Management System.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
