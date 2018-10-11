#ifndef _ChildrenNode
#define _ChildrenNode


template<class T>
class ChildrenNode{

public:
	ChildrenNode<T>* next;
	T* data;
	ChildrenNode(T*);
	ChildrenNode();
	void AddNode(ChildrenNode<T>*);
	T* DeleteNode();
};




#endif