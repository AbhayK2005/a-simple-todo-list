#include <iostream>
#include "src/todo_list.hpp"

void print_tasks(std::vector<Task> tasks, std::string title) {
    std::cout << "\n" << title << std::endl;
    std::cout << "------------------------" << std::endl;

    if (tasks.size() == 0) {
        std::cout << "No tasks." << std::endl;
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            std::cout << (i + 1) << ". ";

            if (tasks[i].is_complete) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }

            std::cout << tasks[i].description << std::endl;
        }
    }
}

int main() {
    TodoList list;
    std::cout << "TODO LIST APP" << std::endl;
    if (list.add("Buy milk")) {
        std::cout << "Added: Buy milk" << std::endl;
    }
    if (list.add("Buy eggs")) {
        std::cout << "Added: Buy eggs" << std::endl;
    }
    if (list.add("Prepare a lesson for CSC 122")) {
        std::cout << "Added: Prepare a lesson for CSC 122" << std::endl;
    }
    if (list.add("Sow beet seeds")) {
        std::cout << "Added: Sow beet seeds" << std::endl;
    }
    if (!list.add("")) {
        std::cout << "Rejected: empty task" << std::endl;
    }
    if (!list.add("   ")) {
        std::cout << "Rejected: whitespace-only task" << std::endl;
    }
    if (list.complete("Buy eggs")) {
        std::cout << "Completed: Buy eggs" << std::endl;
    }
    if (!list.complete("Buy cheese")) {
        std::cout << "Failed: 'Buy cheese' not found" << std::endl;
    }
    if (!list.complete("Buy eggs")) {
        std::cout << "Failed: 'Buy eggs' already complete" << std::endl;
    }
    print_tasks(list.all(), "ALL TASKS");
    print_tasks(list.completed(), "COMPLETED");
    print_tasks(list.incomplete(), "INCOMPLETE");
    list.clear();
    print_tasks(list.all(), "AFTER CLEAR");
    return 0;
}