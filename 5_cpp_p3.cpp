// P3. Make the attributes private and see if you can still access them from outside the class.
//
//
#include <iostream>
#include <string>
using namespace std;

class Person {
    private:
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

    private:
        string name;
        int age;
};

int main() {
    // Create a person object with name and age
    Person person1("Alice", 25);

    // Print info
    person1.print_info();

    return 0;
}
/*
Output:
5_cpp_p3.cpp: In function `int main()':
5_cpp_p3.cpp:38:31: error: `Person::Person(std::string, int)' is private within this context
   38 |     Person person1("Alice", 25);
      |                               ^
5_cpp_p3.cpp:11:9: note: declared private here
   11 |         Person(string name, int age) {
      |         ^~~~~~
5_cpp_p3.cpp:41:23: error: `void Person::print_info()' is private within this context
   41 |     person1.print_info();
      |     ~~~~~~~~~~~~~~~~~~^~
5_cpp_p3.cpp:27:14: note: declared private here
   27 |         void print_info() {
 */
