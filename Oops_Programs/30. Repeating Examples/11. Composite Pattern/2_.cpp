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
    FileSystem *file1 = new File("Document.txt");
    FileSystem *file2 = new File("Image.jpg");

    FileSystem *directory1 = new Directory("Documents");
    FileSystem *directory2 = new Directory("MyFiles");

    dynamic_cast<Directory *>(directory1)->addFile(file1);
    dynamic_cast<Directory *>(directory2)->addFile(file2);
    dynamic_cast<Directory *>(directory2)->addFile(directory1);

    directory2->display();
    return 0;
}