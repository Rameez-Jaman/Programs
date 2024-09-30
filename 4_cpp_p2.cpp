// P2. Create two instances of Person and call print_info() on the
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
        void print_info() {
            cout << "I am " << name << " and I am " << age << " years old." << endl;
        }

    public:
        string name;
        int age;
};

int main() {
    // Create a person object with name and age
    Person person1("Rameez", 22);
    Person person2("Jaman",21);
    person1.print_info();
    person2.print_info();

    return 0;
}


