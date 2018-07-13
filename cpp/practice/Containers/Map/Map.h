#ifndef _MAP_H
#define _MAP_H

template <typename T, typename V>
class Map final
{
	private:
		struct node
		{
			T key;
			V value;
			struct node *left;
			struct node *right;
		};
		node *root;
		int (*Cmp)(T, T);
		int defaultCmp(T, T);
	
	public:
		typedef node* MapIterator;
		Map(int (*Cmp)(T, T) = &defaultCmp);
		~Map();
		MapIterator begin();
		MapIterator end();
		MapIterator insert(std::pair<T, V> &);
		MapIterator erase(T);
};
