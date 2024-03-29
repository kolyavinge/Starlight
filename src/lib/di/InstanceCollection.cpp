#include <lib/List.h>
#include <lib/di/InstanceCollection.h>

InstanceCollection::~InstanceCollection()
{
    List<InstanceHolder*> allInstances;
    _instances.GetAllValues(allInstances);
    for (int i = 0; i < allInstances.GetCount(); i++)
    {
        delete allInstances[i];
    }
}

unsigned int InstanceCollection::GetTypeHashKey(const type_info& type)
{
    return (unsigned int)type.hash_code();
}

InstanceHolder*& InstanceCollection::operator[](const type_info& type)
{
    unsigned int key = GetTypeHashKey(type);
    return _instances[key];
}

bool InstanceCollection::ContainsType(const type_info& type)
{
    unsigned int key = GetTypeHashKey(type);
    return _instances.ContainsKey(key);
}

void InstanceCollection::Add(const type_info& type, InstanceHolder* instanceHolder)
{
    unsigned int key = GetTypeHashKey(type);
    _instances.Add(key, instanceHolder);
    _types.Add(key, &type);
}

const type_info& InstanceCollection::GetTypeInfo(unsigned int typeHashKey)
{
    return *_types[typeHashKey];
}

void InstanceCollection::GetAllTypeHashKeys(List<unsigned int>& typeHashKeys)
{
    _types.GetAllKeys(typeHashKeys);
}
