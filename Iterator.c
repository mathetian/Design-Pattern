#include <iostream>
#include <vector>

template<class Item> class Iterator;

template<class Item>
class List{
public:
	void add(Item item)
	{
		itemVec.push_back(item);
	}

	Iterator<Item>*begin()
	{
		return new Iterator<Item>(this);
	}
	int getSize()
	{
		return itemVec.size();
	}
	Item getElem(int index)
	{
		if(itemVec.size()<=index)
			return Item(0);
		return itemVec.at(index);
	}
private:
	std::vector<Item>itemVec;
};

template<class Item>
class Iterator{
public:
	Iterator(){index=-1;}
	Iterator(List<Item>*pList):pList(pList){index=-1;}
	virtual ~ Iterator(){}
	Item Next()
	{
		index++;
		return pList->getElem(index);
	}
	Item Empty()
	{
		return pList->getElem(0);
	}
private:
	List<Item>*pList;
	int index;
};

int main()
{
	List<int> iLists;
	iLists.add(8);iLists.add(2);
	iLists.add(3);iLists.add(5);
	iLists.add(4);iLists.add(6);
	Iterator<int>*iterator=iLists.begin();
	while(1)
	{
		int elem=iterator->Next();
		if(elem==0) break;
		std::cout<<elem<<std::endl;
	}
}