#include "lib.hpp"

#include <vector>

namespace Lib
{

void AddressBook::Add(const Employee& employee)
{
    m_size++;
    if (!m_list) {
        m_list = new Node(employee);
        return;
    }
    Node* cur = m_list;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new Node(employee);
}

void AddressBook::Delete(const size_t id)
{
    if (!m_list) {
        return;
    }

    if (m_list->m_data.id == id) {
        m_size--;
        Node* tmp = m_list;
        m_list = m_list->next;
        delete tmp;
        return;
    }

    bool found = false;
    Node* cur = m_list;
    while (cur->next) {
        if (cur->next->m_data.id == id) {
            found = true;
            break;
        }
        cur = cur->next;
    }

    if (!found) {
        return;
    }

    m_size--;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

Employee* AddressBook::Find(const size_t id)
{
    if (!m_list) {
        return nullptr;
    }

    Node* cur = m_list;
    while (cur && cur->m_data.id != id) {
        cur = cur->next;
    }
    if (!cur) {
        return nullptr;
    }

    return &cur->m_data;
}

std::vector<Employee> AddressBook::Find(const std::string& name)
{
    std::vector<Employee> employees;
    if (!m_list) {
        return employees;
    }

    Node* cur = m_list;
    for (size_t i = 0; i < m_size; i++) {
        if (cur->m_data.name == name) {
            employees.push_back(cur->m_data);
        }
        cur = cur->next;
    }
    return employees;
}

void AddressBook::Clear()
{
    if (!m_list) {
        return;
    }

    Node* cur = m_list;
    while (cur) {
        m_size--;
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    m_list = nullptr;
}
};  // namespace Lib