#ifndef M_REGISTER_H
#define M_REGISTER_H

#include <QString>
#include <map>

class m_register
{
    QString m_Name;
    std::map<int, QString> m_Field_1;
    std::map<int, QString> m_Field_2;
    std::map<int, QString> m_Field_3;

public:
    m_register(QString name) : m_Name(name) {}
    QString getName(void) const;
    void setField_1(const std::map<int, QString> field);
    std::map<int, QString> getField_1(void) const;
    void setField_2(const std::map<int, QString> field);
    std::map<int, QString> getField_2(void) const;
    void setField_3(const std::map<int, QString> field);
    std::map<int, QString> getField_3(void) const;
};

#endif // M_REGISTER_H
