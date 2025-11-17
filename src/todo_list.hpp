#pragma once
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool is_complete;
};

class TodoList {
private:
    std::vector<Task> tasks;
public:
    void add(std::string description);
    void complete(std::string description);
    std::vector<Task> all();
    std::vector<Task> completed();
    std::vector<Task> incomplete();
    void clear();
};