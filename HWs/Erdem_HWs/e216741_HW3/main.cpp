#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
BinSTree<int> MyTree;
TreeNode<int> * TreeP1, * TreeP2;
MyTree.Insert(90);
MyTree.Insert(150);
MyTree.Insert(180);
MyTree.Insert(75);
MyTree.Insert(100);
MyTree.Insert(120);
MyTree.Insert(130);
MyTree.Insert(110);
MyTree.Insert(40);
MyTree.TreePrint(MyTree.GetRoot());
TreeP1=MyTree.FindNode(120,TreeP2);
std::cout<<TreeP2->data << std::endl;

MyTree.Delete(130);
MyTree.TreePrint(MyTree.GetRoot());
std::cout << MyTree.GetRoot()->data << std::endl;

MyTree.Delete(110);
MyTree.TreePrint(MyTree.GetRoot());
std::cout << MyTree.GetRoot()->data << std::endl;

    return 0;
}
