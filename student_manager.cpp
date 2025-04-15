#include <iostream>
#include <vector>
#include <string>

class StudentManager {
    std::vector<std::string> students;

public:
    void addStudent(const std::string& name) {
        students.push_back(name);
    }

    void removeStudent(const std::string& name) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i] == name) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    void displayStudents() {
        std::cout << "Students:\n";
        for (const std::string& name : students) {
            std::cout << "- " << name << "\n";
        }
    }
};

int main() {
    StudentManager manager;

    manager.addStudent("oyon");
    manager.addStudent("Tajul");
    manager.displayStudents();

    manager.removeStudent("tajul");
    manager.displayStudents();

    return 0;
}