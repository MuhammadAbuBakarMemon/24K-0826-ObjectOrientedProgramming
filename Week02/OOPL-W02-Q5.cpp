#include <iostream>
#include <vector>
#include <algorithm>

struct Entity {
    int id;
    std::string name;
};

bool compareById(const Entity &a, const Entity &b) {
    return a.id < b.id;
}

bool compareByName(const Entity &a, const Entity &b) {
    return a.name[0] < b.name[0];
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Entity> entities(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> entities[i].id >> entities[i].name;
    }

    std::vector<Entity> sortedById = entities;
    std::sort(sortedById.begin(), sortedById.end(), compareById);

    std::vector<Entity> sortedByName = entities;
    std::sort(sortedByName.begin(), sortedByName.end(), compareByName);

    for (const auto &e : sortedById) {
        std::cout << e.id << " " << e.name << std::endl;
    }

    std::cout << std::endl;

    for (const auto &e : sortedByName) {
        std::cout << e.id << " " << e.name << std::endl;
    }

    return 0;
}
