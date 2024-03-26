#pragma once

#include <typeinfo>
#include <lib/Object.h>
#include <lib/Dictionary.h>
#include <lib/di/InstanceHolder.h>

class InstanceCollection : public Object
{
    Dictionary<unsigned int, InstanceHolder*> _instances;

public:
    ~InstanceCollection() override;

    InstanceHolder*& operator[](const type_info& type);
    bool ContainsType(const type_info& type);
    void Add(const type_info& type, InstanceHolder* instanceHolder);
};
