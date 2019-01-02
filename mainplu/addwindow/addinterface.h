#ifndef ADDINTERFACE_H
#define ADDINTERFACE_H


#include <QString>

class AddInterface
{
public:
    virtual ~AddInterface() {}
    virtual int add(int a, int b) = 0;
};


QT_BEGIN_NAMESPACE

#define AddInterface_iid "Qt.test.AddInterface"

Q_DECLARE_INTERFACE(AddInterface, AddInterface_iid)
QT_END_NAMESPACE

#endif // ADDINTERFACE_H
