#pragma once

#include <typeinfo>
#include <lib/Object.h>
#include <lib/List.h>
#include <lib/Dictionary.h>
#include <lib/di/InstanceHolder.h>

class InstanceCollection : public Object
{
    Dictionary<unsigned int, InstanceHolder*> _instances;
    Dictionary<unsigned int, const type_info*> _types;

public:
    ~InstanceCollection() override;

    unsigned int GetTypeHashKey(const type_info& type);
    InstanceHolder*& operator[](const type_info& type);
    bool ContainsType(const type_info& type);
    void Add(const type_info& type, InstanceHolder* instanceHolder);
    const type_info& GetTypeInfo(unsigned int typeHashKey);
    void GetAllTypeHashKeys(List<unsigned int>& typeHashKeys);
};
