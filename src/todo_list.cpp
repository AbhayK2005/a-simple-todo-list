#include "todo_list.hpp"

void TodoList::add(std::string description) {
   Task new_task;
   new_task.description = description;
   new_task.is_complete = false;
   tasks.push_back(new_task);
}

void TodoList::complete(std::string description) {
   for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i].description == description) {
         tasks[i].is_complete = true;
         return;
      }
   }
}

std::vector<Task> TodoList::all() {
   return tasks;
}

std::vector<Task> TodoList::completed() {
   std::vector<Task> result;
   for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i].is_complete) {
         result.push_back(tasks[i]);
      }
   }
   return result;
}

std::vector<Task> TodoList::incomplete() {
   std::vector<Task> result;
   for (int i = 0; i < tasks.size(); i++) {
      if (!tasks[i].is_complete) {
         result.push_back(tasks[i]);
      }
   }
   return result;
}

void TodoList::clear() {
   tasks.clear();
}