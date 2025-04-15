#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

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

    std::vector<std::string> getStudents() {
        return students;
    }

    void clear() {
        students.clear();
    }
};



#ifndef UNIT_TEST
int main() {
    StudentManager manager;

    manager.addStudent("oyon");
    manager.addStudent("Tajul");
    manager.displayStudents();

    manager.removeStudent("Tajul");
    manager.displayStudents();

    return 0;
}
#endif

#ifdef UNIT_TEST
TEST(StudentManagerTest, AddStudent) {
    StudentManager manager;
    manager.clear();
    manager.addStudent("tajul");


    std::cout << "After adding student 'tajul':\n";
    for (const auto& student : manager.getStudents()) {
        std::cout << "- " << student << "\n";
    }

    EXPECT_EQ(manager.getStudents().size(), 1);
    EXPECT_EQ(manager.getStudents()[0], "tajul");
}

TEST(StudentManagerTest, RemoveStudent) {
    StudentManager manager;
    manager.clear();
    manager.addStudent("nahid");
    manager.removeStudent("nahid");

    
    std::cout << "After removing student 'nahid':\n";
    for (const auto& student : manager.getStudents()) {
        std::cout << "- " << student << "\n";
    }

    
    EXPECT_TRUE(manager.getStudents().empty());
}
#endif