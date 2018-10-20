#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cstdlib>
#include<limits>
#include<cassert>
#include<map>
#include<set>
#include<ctime>
#include<vector>
#include<functional>

using namespace std;

namespace compete
{
	template<typename T>
	T Power(T n, int e)
	{
		T result = 1;
		for (int i = 0; i < e; ++i)
			result *= n;
		return result;
	}

	template<typename T>
	bool IsPrime(T n)
	{
		bool result = true;
		for (T i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				result = false;
				break;
			}
		}
		return result;
	}

	template<typename T>
	T GCD(T a, T b)
	{
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}

	template<typename T>
	T LCM(T a, T b)
	{
		return a / GCD(a, b) * b;
	}

	template<typename K, typename V, typename Compare = std::less<K>>
	class Treap final
	{
	public:
		Treap() : root_node_pointer_(&null_node_)
		{
		}

		Treap(const Treap<K, V, Compare> &other)
		{
			CopyHelp(other.root_node_pointer_, root_node_pointer_);
		}

		~Treap()
		{
			Clear();
		}

		Treap<K, V, Compare> &operator=(const Treap<K, V, Compare> &rhs)
		{
			Clear();
			CopyHelp(rhs.root_node_pointer_, root_node_pointer_);
			return *this;
		}

		V &operator[](const K &key)
		{
			return const_cast<V &>(static_cast<const Treap &>(*this)[key]);
		}

		const V &operator[](const K &key) const
		{
			TreapNode * const &node_pointer_ref = GetNode(key);
			assert(node_pointer_ref != &null_node_);
			return node_pointer_ref->value;
		}

		void Remove(const K &key)
		{
			TreapNode *&node_pointer_ref = const_cast<TreapNode *&>(GetNode(key));
			assert(node_pointer_ref != &null_node_);
			RemoveHelp(node_pointer_ref);
		}

		const bool Put(const K &key, const V &value)
		{
			return PutHelp(key, value, root_node_pointer_);
		}

		const bool Contain(const K &key) const
		{
			return GetNode(key) != &null_node_;
		}

		const K &Select(int rank) const;

		const int Rank(const K &key) const;

		void Clear()
		{
			ClearHelp(root_node_pointer_);
			root_node_pointer_ = &null_node_;
		}

		const int Size() const
		{
			return root_node_pointer_->size;
		}

	private:
		struct TreapNode
		{
			K key;
			V value;
			int size;
			int priority;
			TreapNode *left, *right;
		};

		TreapNode * const &GetNode(const K &key) const;

		void CopyHelp(const TreapNode *other_pointer, TreapNode *&my_pointer);

		const bool PutHelp(const K &key, const V &value, TreapNode *&node);

		void RemoveHelp(TreapNode *&node);

		void ClearHelp(TreapNode *node);

		void LeftRotate(TreapNode *&node)
		{
			TreapNode *new_root = node->right;
			node->right = new_root->left;
			new_root->left = node;
			new_root->size = node->size;
			node->size -= 1 + new_root->right->size;
			node = new_root;
		}

		void RightRotate(TreapNode *&node)
		{
			TreapNode *new_root = node->left;
			node->left = new_root->right;
			new_root->right = node;
			new_root->size = node->size;
			node->size -= 1 + new_root->left->size;
			node = new_root;
		}

		static TreapNode null_node_;
		TreapNode *root_node_pointer_;
		Compare comparator;
	};

	template<typename K, typename V, typename Compare>
	typename Treap<K, V, Compare>::TreapNode Treap<K, V, Compare>::null_node_ = {
		K(), V(), 0, std::numeric_limits<int>::max(), &null_node_, &null_node_
	};

	template<typename K, typename V, typename Compare>
	typename Treap<K, V, Compare>::TreapNode * const &Treap<K, V, Compare>::GetNode(const K &key) const
	{
		TreapNode * const *current = &root_node_pointer_;
		while (*current != &null_node_)
		{
			if (comparator(key, (*current)->key))
				current = &(*current)->left;
			else if (comparator((*current)->key, key))
				current = &(*current)->right;
			else
				break;
		}

		return *current;
	}

	template<typename K, typename V, typename Compare>
	void Treap<K, V, Compare>::CopyHelp(const TreapNode *other_pointer, TreapNode *&my_pointer)
	{
		if (other_pointer == &null_node_)
			my_pointer = &null_node_;
		else
		{
			my_pointer = new TreapNode();
			*my_pointer = *other_pointer;
			CopyHelp(other_pointer->left, my_pointer->left);
			CopyHelp(other_pointer->right, my_pointer->right);
		}
	}

	template<typename K, typename V, typename Compare>
	const bool Treap<K, V, Compare>::PutHelp(const K &key, const V &value, TreapNode *&node)
	{
		if (node == &null_node_)
		{
			node = new TreapNode();
			node->key = key;
			node->value = value;
			node->size = 1;
			node->priority = std::rand() % std::numeric_limits<int>::max();
			node->left = node->right = &null_node_;
			return true;
		}
		else if (comparator(key, node->key))
		{
			bool is_add = PutHelp(key, value, node->left);
			if (is_add)
			{
				++node->size;
				if (node->left->priority < node->priority)
					RightRotate(node);
			}
			return is_add;
		}
		else if (comparator(node->key, key))
		{
			bool is_add = PutHelp(key, value, node->right);
			if (is_add)
			{
				++node->size;
				if (node->right->priority < node->priority)
					LeftRotate(node);
			}
			return is_add;
		}
		else
		{
			node->value = value;
			return false;
		}
	}

	template<typename K, typename V, typename Compare>
	void Treap<K, V, Compare>::RemoveHelp(TreapNode *&node)
	{
		if (node->left == &null_node_ && node->right == &null_node_)
		{
			delete node;
			node = &null_node_;
		}
		else if (node->left->priority < node->right->priority)
		{
			RightRotate(node);
			--node->size;
			RemoveHelp(node->right);
		}
		else
		{
			LeftRotate(node);
			--node->size;
			RemoveHelp(node->left);
		}
	}

	template<typename K, typename V, typename Compare>
	const K &Treap<K, V, Compare>::Select(int rank) const
	{
		assert(rank >= 0 && rank < Size());
		TreapNode *current = root_node_pointer_;
		while (rank != current->left->size)
		{
			if (rank < current->left->size)
				current = current->left;
			else
			{
				rank -= current->left->size + 1;
				current = current->right;
			}
		}

		return current->key;
	}

	template<typename K, typename V, typename Compare>
	const int Treap<K, V, Compare>::Rank(const K &key) const
	{
		int result = root_node_pointer_->left->size;
		TreapNode *current = root_node_pointer_;
		bool is_left_child = false;	// 当key不在treap中时，如果所找到的null_node_在左子树，则结果需+1
		while (current != &null_node_)
		{
			if (comparator(key, current->key))
			{
				result -= current->left->right->size + 1;
				current = current->left;
				is_left_child = true;
			}
			else if (comparator(current->key, key))
			{
				result += current->right->left->size + 1;
				current = current->right;
				is_left_child = false;
			}
			else
				return result;	// key在treap中
		}

		return result + static_cast<int>(is_left_child);	// key不在treap中，返回值为：插入该key后该key所在的rank
	}

	template<typename K, typename V, typename Compare>
	void Treap<K, V, Compare>::ClearHelp(TreapNode *node)
	{
		if (node != &null_node_)
		{
			ClearHelp(node->left);
			ClearHelp(node->right);
			delete node;
		}
	}

	void UnitTest()
	{
		assert(Power(2, 10) == 1024);
		assert(Power(1, 10) == 1);
		assert(Power(-2, 9) == -512);
		assert(Power(-2, 10) == 1024);
		assert(Power(2LL, 40) == 1099511627776);

		int prime_nums[] = {
			2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
			31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
			73, 79, 83, 89, 97, 101 };
		for (int num = 2, index = 0; num <= 100; ++num)
		{
			if (num == prime_nums[index])
			{
				assert(IsPrime(num));
				++index;
			}
			else
				assert(!IsPrime(num));
		}

		assert(GCD(1, 100) == 1);
		assert(GCD(90, 1) == 1);
		assert(GCD(5, 9) == 1);
		assert(GCD(10, 77) == 1);
		assert(GCD(16, 97) == 1);
		assert(GCD(12, 16) == 4);
		assert(GCD(100, 10) == 10);

		assert(LCM(5, 7) == 35);
		assert(LCM(1, 100) == 100);
		assert(LCM(35, 42) == 210);

		Treap<int, int> treap;
		assert(treap.Rank(10) == 0);
		treap.Put(10, 0);
		assert(treap.Rank(10) == 0);
		assert(treap.Rank(9) == 0);
		assert(treap.Rank(11) == 1);
		assert(treap.Select(0) == 10);
		treap.Clear();

		std::map<int, int> map_friend;
		for (int i = 0; i < 100000; ++i)
		{
			std::srand(std::time(NULL));
			int key = std::rand() % 100000;
			int value = std::rand() % 100000;
			treap.Put(key, value);
			map_friend[key] = value;
			assert(treap[key] == map_friend[key]);
		}

		const Treap<int, int> other_treap(treap);

		for (auto it = map_friend.cbegin(); it != map_friend.cend(); ++it)
		{
			assert(treap[it->first] == it->second);
			assert(other_treap[it->first] == it->second);
		}
		for (int i = 0; i < 50000; ++i)
		{
			assert(static_cast<bool>(map_friend.count(i)) == treap.Contain(i));
			if (treap.Contain(i))
			{
				treap.Remove(i);
				map_friend.erase(i);
			}
		}
		for (auto it = map_friend.cbegin(); it != map_friend.cend(); ++it)
			assert(treap[it->first] == it->second);
		assert(treap.Size() == map_friend.size());
		for (int i = 0; i < treap.Size(); ++i)
			assert(treap.Rank(treap.Select(i)) == i);
		treap.Clear();
		assert(treap.Size() == 0);
	}
}

void flipall(vector<string> &all, bool flip[])
{
	for (int i = 0; i < all.size(); ++i)
		for (int j = 0; j < all[i].size(); ++j)
			if (flip[j])
			{
				if (all[i][j] == '0')
					all[i][j] = '1';
				else
					all[i][j] = '0';
			}
}


int main()
{
/*	ios_base::sync_with_stdio(false);
	cout.precision(8);
	cout.setf(ios_base::fixed);
#ifdef ONLINE_JUDGE
	cin.tie(nullptr);
#endif*/
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		int N, L;
		cin >> N >> L;
		vector<string> init;
		vector<string> required;
		for (int i = 0; i < N; ++i)
		{
			string temp;
			cin >> temp;
			init.push_back(temp);
		}
		for (int i = 0; i < N; ++i)
		{
			string temp;
			cin >> temp;
			required.push_back(temp);
		}
		sort(begin(required), end(required));

		int minflipcount = 41;

		bool flip[40];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				int flipcount = 0;
				for (int k = 0; k < L; ++k)
					if (init[i][k] == required[j][k])
						flip[k] = false;
					else
					{
						flip[k] = true;
						++flipcount;
					}

				flipall(init, flip);
				sort(begin(init), end(init));
				if (init == required)
					if (flipcount < minflipcount)
						minflipcount = flipcount;
				flipall(init, flip);
			}

		if (minflipcount == 41)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << minflipcount << endl;
	}
#ifndef ONLINE_JUDGE
	//system("pause");
#endif
}
