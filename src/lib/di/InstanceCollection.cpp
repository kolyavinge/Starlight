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

InstanceHolder*& InstanceCollection::operator[](const type_info& type)
{
    unsigned int key = (unsigned int)type.hash_code();
    return _instances[key];
}

bool InstanceCollection::ContainsType(const type_info& type)
{
    unsigned int key = (unsigned int)type.hash_code();
    return _instances.ContainsKey(key);
}

void InstanceCollection::Add(const type_info& type, InstanceHolder* instanceHolder)
{
    unsigned int key = (unsigned int)type.hash_code();
    _instances.Add(key, instanceHolder);
}

void InstanceCollection::GetUnusedInstances(List<String>& unusedInstances)
{
    List<InstanceHolder*> allInstances;
    _instances.GetAllValues(allInstances);
    for (int i = 0; i < allInstances.GetCount(); i++)
    {
        if (allInstances[i]->InstancesCount == 0)
        {
            unusedInstances.Add(allInstances[i]->GetInstanceName());
        }
    }
}
