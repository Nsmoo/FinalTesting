#include <iostream>
#include<string>
#include <vector>
#include <memory>

struct Student {
    int id;
    std::string name;
    int age;
};

class StudData {
private:
    std::vector<std::shared_ptr<Student>> students;

public:
    void add(int id, const std::string& name, int age) {
        if (id < 0) {
            std::cerr << "Error: ID must be greater than or equal to zero." << std::endl;
            return;
        }
        if (age < 15) {
            std::cerr << "Error: Age must be greater than or equal to 15." << std::endl;
            return;
        }
        for (const auto& student : students) {
            if (student->id == id) {
                std::cerr << "Error: Student with ID " << id << " already exists." << std::endl;
                return;
            }
        }
        auto newStudent = std::make_shared<Student>();
        newStudent->id = id;
        newStudent->name = name;
        newStudent->age = age;
        students.push_back(newStudent);
    }

    void del(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->id == id) {
                students.erase(it);
                return;
            }
        }
        std::cerr << "Error: Student with ID " << id << " not found." << std::endl;
    }

    std::shared_ptr<Student> get(int id) {
        for (const auto& student : students) {
            if (student->id == id) {
                return student;
            }
        }
        std::cerr << "Error: Student with ID " << id << " not found." << std::endl;
        return nullptr;
    }
};

int main() {
    StudData st;

    st.add(0, "Nikita", 23);
    st.add(1, "Ivan", 22);

    auto student = st.get(0);
    std::cout << "ID: " << student->id << ", Name: " << student->name << ", Age: " << student->age << std::endl;

    st.del(0);
    return 0;
}