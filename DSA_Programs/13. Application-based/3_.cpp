#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class FileSystemNode
{
public:
    string name;
    bool isDirectory;
    vector<FileSystemNode *> children;

    FileSystemNode(string name, bool isDirectory = false)
    {
        this->name = name;
        this->isDirectory = isDirectory;
    }

    void addChild(FileSystemNode *childNode)
    {
        this->children.push_back(childNode);
    }
};

class FileSystem
{
public:
    FileSystemNode *root;
    FileSystemNode *currentDir;

    FileSystem()
    {
        root = new FileSystemNode("root", true);
        currentDir = root;
    }

    void createDirectory(string dirname)
    {
        FileSystemNode *newFile = new FileSystemNode(dirname, true);
        currentDir->addChild(newFile);
    }
    void createFile(string filename)
    {
        FileSystemNode *newFile = new FileSystemNode(filename);
        currentDir->addChild(newFile);
    }

    void changeDirectory(string dirname)
    {
        for (FileSystemNode *child : currentDir->children)
        {
            if (child->isDirectory == true && child->name == dirname)
            {
                currentDir = child;
                cout << "Directory changed to " << currentDir->name << endl;
                return;
            }
        }
        cout << "Directory is not found" << endl;
    }

    void listContents()
    {
        cout << "Contents of " << currentDir->name << endl;
        for (FileSystemNode *child : currentDir->children)
        {
            cout << (child->isDirectory ? "Directory -> " : "File -> ") << child->name << endl;
        }
        cout << endl;
    }
};

int main()
{
    FileSystem fileSystem;

    fileSystem.createDirectory("documents");
    fileSystem.changeDirectory("documents");
    fileSystem.createFile("divyesh.txt");
    fileSystem.createFile("milan.txt");

    fileSystem.changeDirectory("..");
    fileSystem.createDirectory("pictures");
    fileSystem.changeDirectory("pictures");
    fileSystem.createFile("photo.jpg");

    fileSystem.changeDirectory("..");
    fileSystem.listContents();

    fileSystem.changeDirectory("pictures");
    fileSystem.listContents();
    return 0;
}