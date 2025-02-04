#include <iostream>
#include <vector>
#include <string>

namespace ns {
    struct Sub {
        std::string subject;
    };

    struct Stu {
        int id;
        std::vector<Sub> subjects;
    };
}

int main() {
    std::vector<ns::Stu> ray;
    ns::Stu s1;
    s1.id = 1;
    s1.subjects.push_back({"Math"});
    s1.subjects.push_back({"Science"});
    ray.push_back(s1);

    ns::Stu s2;
    s2.id = 2;
    s2.subjects.push_back({"History"});
    s2.subjects.push_back({"English"});
    ray.push_back(s2);

    for (auto& stu : ray) {
        std::cout << "ID: " << stu.id << "\n";
        for (auto& sub : stu.subjects) {
            std::cout << "  Subject: " << sub.subject << "\n";
        }
    }

    return 0;
}
