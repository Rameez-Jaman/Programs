// P9. Create a class called Teacher that inherits from Person. Add a field called salary. Add a constructor that takes a name, age and salary.
// Add a method called print_info() that prints out the name, age and salary of the teacher

#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        // Constructor that accepts both name and age
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }

        // Getter for the name
        string getName() {
            return name;
        }

        // Getter for the age (returns int instead of string)
        int getAge() {
            return age;
        }

        // Print information
        virtual void print_info() {
            cout << "I am " << name << " and I am " << age << " years old." << endl;
        }

    public:
        string name;
        int age;
};

class Student:public Person{
        public:
                Student(string name,int age,string department ):Person(name,age){
                        this->department=department;
                }

                void print_info() override{
                        cout << "I am " <<getName() <<", I am " <<getAge() <<" years old and I study in the " <<department << " department." <<endl;
                }
        private:
                string department;
};
class Teacher:public Person{
        public:
                Teacher(string name,int age,int salary):Person(name,age){
                        this->salary = salary;
                }
                void print_info() override{
                        cout<< "I am " << name << ", I am " << age << " years old and my salary is " << salary << "."<<endl;
                }
        private:
                int salary;
};

int main() {
    // Create a person object with name and age
    Person person1("Rameez", 22);
    Student student1("Jaman",21,"ECE");
    Teacher teacher1("Manna",26,50000);
    person1.print_info();
    student1.print_info();
    teacher1.print_info();

    return 0;
}
/*
Output:
I am Rameez and I am 22 years old.
I am Jaman, I am 21 years old and I study in the ECE department.
I am Manna, I am 26 years old and my salary is 50000.
*/
