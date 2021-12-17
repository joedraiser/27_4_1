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

    std::string getName()
    {
        return name;
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
        for(int i=0;i<middleBranchesQty;i++)
        {
            middleBranches.push_back(new middleBranch(i,bigBranchNum,treeNum));
        }
        std::cout << "Type elf name living on " << bigBranchNum+1 << " big branch of " << treeNum+1 << " tree: ";
        std::cin >> name;
        if(name=="None")
            name="";
    }

    ~bigBranch()
    {
        for(int i=0;i<middleBranches.size();i++)
            delete middleBranches[i];

        //std::cout << "\nbigBranch deleted\n";
    }

    void listAllTenants(std::string neighbour="")
    {
        std::cout << "Here are neighbours of " << neighbour;
        if(name!=""&&name!=neighbour)
            std::cout << name << std::endl;
        for(int i=0;i<middleBranchesQty;i++)
        {
            if(middleBranches[i]->getName()!=""&&middleBranches[i]->getName()!=neighbour)
                std::cout << middleBranches[i]->getName() << std::endl;
        }
    }

    void find(std::string searchName)
    {
        if(name==searchName)
        {
            this->listAllTenants(searchName);
            return;
        }

        for(int i=0;i<middleBranchesQty;i++)
        {
            if(middleBranches[i]->getName()==searchName)
            {
                this->listAllTenants(searchName);
                return;
            }
        }
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
        for(int i=0;i<bigBranchesQty;i++)
        {
            bigBranches.push_back(new bigBranch(i,treeNum));
        }
    }

    void find(std::string searchName)
    {
        for(int i=0;i<bigBranchesQty;i++)
        {
            bigBranches[i]->find(searchName);
        }
    }

    ~tree()
    {
        for(int i=0;i<bigBranches.size();i++)
            delete bigBranches[i];

        //std::cout << "\ntree deleted\n";
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

    void find(std::string searchName)
    {
        for(int i=0;i<5;i++)
            trees[i]->find(searchName);
    }

    ~forrest()
    {
        for(int i=0;i<5;i++)
            delete trees[i];

        //std::cout << "\nforrest deleted\n";
    }
};

int main()
{
    forrest elves;

    elves.find("Someone");

    return 0;
}
