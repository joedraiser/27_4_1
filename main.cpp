#include <iostream>
#include <vector>
#include <random>
#include <ctime>

class middleBranch
{
private:
    std::string name;
public:
    middleBranch(int middleBranchNum, int bigBranchNum, int treeNum)
    {
        std::cout << "Type elf name living on " << middleBranchNum+1 << " middle branch of " << bigBranchNum+1 << " big branch of " << treeNum+1 << " tree: ";
        std::cin >> name;
        if(name=="None")
            name="";
    }

};

class bigBranch
{
private:
    std::string name;
    int middleBranchesQty=rand()%2+2;
    std::vector<middleBranch*> middleBranches;
public:
    bigBranch(int bigBranchNum, int treeNum)
    {
        for(int i;i<middleBranchesQty;i++)
        {
            middleBranches.push_back(new middleBranch(i,bigBranchNum,treeNum));
        }
        std::cout << "Type elf name living on " << bigBranchNum+1 << " big branch of " << treeNum+1 << " tree: ";
        std::cin >> name;
        if(name=="None")
            name="";
    }
};

class tree
{
private:
    int bigBranchesQty=rand()%3+3;
    std::vector<bigBranch*> bigBranches;
public:
    tree(int treeNum)
    {
        for(int i;i<bigBranchesQty;i++)
        {
            bigBranches.push_back(new bigBranch(i,treeNum));
        }
    }
};

class forrest
{
private:
    tree* trees[5];
public:
    forrest()
    {
        for(int i=0;i<5;i++)
        {
            trees[i]=new tree(i);
        }
    }
};

int main()
{
    forrest elves;



    return 0;
}
