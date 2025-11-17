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
  list.add("Buy milk");
  list.add("Buy eggs");
  list.add("Prepare a lesson for CSC 122");
  list.add("Sow beet seeds");
  list.complete("Buy eggs");
  print_tasks(list.all(), "ALL TASKS");
  print_tasks(list.completed(), "COMPLETED");
  print_tasks(list.incomplete(), "INCOMPLETE");
  list.clear();
  print_tasks(list.all(), "AFTER CLEAR");
  return 0;
}