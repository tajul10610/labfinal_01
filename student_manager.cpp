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
    void add(const std::string& name) {
        students.push_back(name);
    }

    bool remove(const std::string& name) {
        auto it = std::find(students.begin(), students.end(), name);
        if (it != students.end()) {
            students.erase(it);
            return true;
        }
        return false;
    }

    void show() const {
        std::cout << "Students:\n";
        for (const auto& s : students)
            std::cout << "- " << s << "\n";
    }

    std::vector<std::string> list() const { return students; }

    void clear() { students.clear(); } // for test reset
};