#include "m_register.h"

QString m_register::getName() const
{
    return m_Name;
}

void m_register::setField_1(const std::map<int, QString> field)
{
    m_Field_1 = field;
}

std::map<int, QString> m_register::getField_1() const
{
    return m_Field_1;
}

void m_register::setField_2(const std::map<int, QString> field)
{
    m_Field_2 = field;
}

std::map<int, QString> m_register::getField_2() const
{
    return m_Field_2;
}

void m_register::setField_3(const std::map<int, QString> field)
{
    m_Field_3 = field;
}

std::map<int, QString> m_register::getField_3() const
{
    return m_Field_3;
}
