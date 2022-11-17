#include <iostream>

#include "lib.hpp"

int main(int, char **)
{
    Lib::AddressBook book;
    for (size_t id = 0; id < 10000; id++) {
        book.Add(Lib::Employee{static_cast<uint32_t>(id), id % 2 == 0 ? "Peter" : "Jone", static_cast<uint16_t>(id % 1000)});
    }
    for (size_t i = 0; i < 10001; i++) {
        Lib::Employee *emp_f = book.Find(i);
        if (!emp_f) {
            std::cout << "No such employee with id " << i << std::endl;
            continue;
        }
        std::cout << emp_f->id << " " << emp_f->name << " " << emp_f->grade << std::endl;
    }
    std::vector<Lib::Employee> employees = book.Find("Peter");
    for (int i = 0; i < employees.size(); i++) {
        Lib::Employee emp = employees[i];
        std::cout << emp.id << " " << emp.name << " " << emp.grade << std::endl;
    }
    book.Clear();
    std::cout << book.Find(1) << std::endl;
}
