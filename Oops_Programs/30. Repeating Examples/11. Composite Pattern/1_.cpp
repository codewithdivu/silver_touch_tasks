#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class FileSystem
{
public:
    virtual void display() const = 0;
    virtual ~FileSystem() = default;
};

class File : public FileSystem
{
public:
    string name;

    File(string name) : name(name) {}

    void display() const override
    {
        cout << "file is " << name << endl;
    }
};

class Directory : public FileSystem
{
public:
    string name;
    vector<FileSystem *> files;
    Directory(string name) : name(name) {}

    void addFile(FileSystem *file)
    {
        files.push_back(file);
    }

    void display() const override
    {
        cout << "Directory: " << name << endl;
        for (auto file : files)
        {
            file->display();
        }
    }
};

int main()
{

    return 0;
}