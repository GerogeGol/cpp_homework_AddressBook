#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <vector>

namespace Lib
{

struct Employee {
    uint32_t id;
    std::string name;
    uint16_t grade;
};

class AddressBook
{
   private:
    class Node
    {
       public:
        Employee m_data;
        Node* next = nullptr;
        Node(const Employee& data) : m_data(data) {}
    };

    Node* m_list = nullptr;
    size_t m_size = 0;

   public:
    void Add(const Employee& employee);
    void Delete(const size_t id);
    Employee* Find(const size_t id);  // Возвращаю указатель т.к. , если сотрудник не найдётся вернётся nullptr;
    std::vector<Employee> Find(const std::string& name);
    void Clear();
};

}  // namespace Lib

#endif