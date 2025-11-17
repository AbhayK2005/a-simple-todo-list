#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todo_list.hpp"

TEST_CASE("Can add tasks") {
    TodoList list;
    list.add("Buy milk");
    REQUIRE(list.all().size() == 1);
    list.add("Buy eggs");
    REQUIRE(list.all().size() == 2);
}

TEST_CASE("Can mark tasks as complete") {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.complete("Buy eggs");
    REQUIRE(list.completed().size() == 1);
    REQUIRE(list.incomplete().size() == 1);
}

TEST_CASE("All returns all tasks") {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Prepare lesson");
    list.complete("Buy eggs");
    REQUIRE(list.all().size() == 3);
}

TEST_CASE("Completed returns only completed tasks") {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Prepare lesson");
    list.complete("Buy eggs");
    list.complete("Buy milk");
    std::vector<Task> done = list.completed();
    REQUIRE(done.size() == 2);
}

TEST_CASE("Incomplete returns only incomplete tasks") {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Prepare lesson");
    list.complete("Buy eggs");
    std::vector<Task> not_done = list.incomplete();
    REQUIRE(not_done.size() == 2);
}

TEST_CASE("Clear removes all tasks") {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.clear();
    REQUIRE(list.all().size() == 0);
}
