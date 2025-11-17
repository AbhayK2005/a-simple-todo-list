#include "todo_list.hpp"

bool TodoList::add(std::string description) {
   if (description.empty()) {
      return false;
   }
   bool all_spaces = true;
   for (int i = 0; i < description.size(); i++) {
      if (description[i] != ' ' && description[i] != '\t') {
         all_spaces = false;
         break;
      }
   }
   if (all_spaces) {
      return false;
   }
   Task new_task;
   new_task.description = description;
   new_task.is_complete = false;
   tasks.push_back(new_task);
   return true;
}

bool TodoList::complete(std::string description) {
   if (description.empty()) {
      return false;
   }
   for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i].description == description && !tasks[i].is_complete) {
         tasks[i].is_complete = true;
         return true;
      }
   }
   return false;
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