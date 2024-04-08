#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/Memory.h>
#include <lib/List.h>

class KeyNotFoundException : public Exception { };
class KeyAlreadyExistException : public Exception { };

template<class TKey, class TValue>
class Dictionary : public Object
{
    class Hasher : public Object
    {
    public:
        unsigned int GetHashKey(TKey value, int capacity)
        {
            return GetHash(value) % capacity;
        }

    private:
        unsigned int GetHash(char value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(unsigned char value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(wchar_t value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(short value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(unsigned short value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(int value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(unsigned int value)
        {
            return value;
        }

        unsigned int GetHash(long value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(unsigned long value)
        {
            return value;
        }

        unsigned int GetHash(long long value)
        {
            return (unsigned int)value;
        }

        unsigned int GetHash(unsigned long long value)
        {
            return value;
        }

        unsigned int GetHash(float value)
        {
            union { float f; unsigned int i; } u{};
            u.f = value;

            return u.i;
        }

        unsigned int GetHash(double value)
        {
            union { double d; unsigned int i[2]; } u{};
            u.d = value;

            return u.i[0] ^ u.i[1];
        }

        unsigned int GetHash(Object& value)
        {
            return (unsigned int)value.GetHashCode();
        }
    };

    class Node : public Object
    {
    public:
        TKey Key;
        TValue Value;
        unsigned int HashKey;
        Node* Next;

        Node(TKey key, TValue value)
        {
            Key = key;
            Value = value;
            HashKey = 0;
            Next = nullptr;
        }
    };

    int _capacity;
    Node** _items;
    Hasher _hasher;

public:
    Dictionary(int capacity = 1000)
    {
        if (capacity <= 0) throw ArgumentException();
        _capacity = capacity;
        _items = Memory::AllocAndZero<Node*>(_capacity);
    }

    ~Dictionary() override
    {
        Clear();
        Memory::Release(_items);
    }

    void Add(TKey key, TValue value)
    {
        if (ContainsKey(key))
        {
            throw KeyAlreadyExistException();
        }
        Node* newNode = new Node(key, value);
        newNode->HashKey = _hasher.GetHashKey(key, _capacity);
        if (_items[newNode->HashKey] == nullptr)
        {
            _items[newNode->HashKey] = newNode;
        }
        else
        {
            Node* parent = _items[newNode->HashKey];
            while (parent->Next != nullptr)
            {
                parent = parent->Next;
            }
            parent->Next = newNode;
        }
    }

    void Delete(TKey key)
    {
        Node* parent = nullptr;
        Node* node = nullptr;
        unsigned int hashKey = _hasher.GetHashKey(key, _capacity);
        if (!FindNodeWithParent(key, hashKey, parent, node))
        {
            throw KeyNotFoundException();
        }
        if (parent != nullptr)
        {
            parent->Next = node->Next;
        }
        else if (node->Next != nullptr)
        {
            _items[hashKey] = node->Next;
        }
        else
        {
            _items[hashKey] = nullptr;
        }
        delete node;
    }

    bool ContainsKey(TKey key)
    {
        return TryGet(key) != nullptr;
    }

    TValue* TryGet(TKey key)
    {
        unsigned int hashKey = _hasher.GetHashKey(key, _capacity);
        Node* node = _items[hashKey];
        while (node != nullptr)
        {
            if (node->Key == key)
            {
                return &node->Value;
            }
            else
            {
                node = node->Next;
            }
        }

        return nullptr;
    }

    TValue& Get(TKey key)
    {
        TValue* value = TryGet(key);
        if (value != nullptr)
        {
            return *value;
        }
        else
        {
            throw KeyNotFoundException();
        }
    }

    TValue& operator[](TKey key)
    {
        return Get(key);
    }

    void GetAllKeys(List<TKey>& keys)
    {
        for (int i = 0; i < _capacity; i++)
        {
            Node* node = _items[i];
            while (node != nullptr)
            {
                keys.Add(node->Key);
                node = node->Next;
            }
        }
    }

    void GetAllValues(List<TValue>& values)
    {
        for (int i = 0; i < _capacity; i++)
        {
            Node* node = _items[i];
            while (node != nullptr)
            {
                values.Add(node->Value);
                node = node->Next;
            }
        }
    }

    void Clear()
    {
        for (int itemIndex = 0; itemIndex < _capacity; itemIndex++)
        {
            if (_items[itemIndex] != nullptr)
            {
                ReleaseNodeList(_items[itemIndex]);
                _items[itemIndex] = nullptr;
            }
        }
    }

private:
    bool FindNodeWithParent(TKey key, unsigned int hashKey, Node*& parent, Node*& node)
    {
        node = _items[hashKey];
        while (node != nullptr)
        {
            if (node->Key == key)
            {
                return true;
            }
            else
            {
                parent = node;
                node = node->Next;
            }
        }

        return false;
    }

    void ReleaseNodeList(Node* node)
    {
        if (node->Next != nullptr)
        {
            ReleaseNodeList(node->Next);
        }
        delete node;
    }
};
