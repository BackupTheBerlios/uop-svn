#ifndef LIBCOMMON_MULTIINDEX_HPP
#define LIBCOMMON_MULTIINDEX_HPP

#include <map>
#include <vector>
#include <string>

// TODO: This template needs a lot of optimizations. For example, references, const, and so on in some places...
// TODO: Eu poderia passar o tipo da chave tambem... mas vale a pena ???

template<class T>
class CMultiIndex {
public:
	struct Item {
		std::string key;
		T value;
		Item(std::string p_key, T p_value) : key(p_key), value(p_value) {}
	};
private:
	std::map<std::string, size_t> _mapIndex;
	std::vector<Item>             _vectorIndex;
public:
	CMultiIndex() {}
	void add(std::string key, T item)
	{
		std::map<std::string, size_t>::iterator pos = _mapIndex.find(key);

		if (pos == _mapIndex.end()) {
			_mapIndex[key] = _vectorIndex.size();
			_vectorIndex.push_back(Item(key, item));
		} else {
			_vectorIndex[pos->second] = Item(key, item);
		}
	}

// 	void add(size_t pos, T item)
// 	{
// 		if (pos >= _vectorIndex.size()) {
// 			_vectorIndex.resize(pos+1);
// 		}
// 		std::map<std::string, size_t>::iterator pos = _mapIndex.find(key);
// 
// 		if (pos == _mapIndex.end()) {
// 			_mapIndex[key] = _vectorIndex.size();
// 			_vectorIndex.push_back(Item(key, item));
// 		} else {
// 			_vectorIndex[pos->second] = Item(key, item);
// 		}
// 	}

	T get(std::string key)
	{
		std::map<std::string, size_t>::iterator pos = _mapIndex.find(key);

		if (pos == _mapIndex.end()) {
			return T("");
		} else {
			return _vectorIndex[pos->second].value;
		}
	}

	T get(size_t pos)
	{
		return _vectorIndex[pos].value;
	}

	size_t size() const
	{
		return _vectorIndex.size();
	}

	class iterator; // Declaration required
	friend class iterator; // Make it a friend
	class iterator { // Now define it
		CMultiIndex& s;
		int index;
	public:
		iterator(CMultiIndex& st): s(st), index(0) {}
		// To create the "end sentinel" iterator:
		iterator(CMultiIndex& st, bool) : s(st), index(s.size()) {}
		Item operator*() const { return s._vectorIndex[index];}
		Item operator++() { // Prefix form
			//     require(index < s.top,
			//         "iterator moved out of range");
			return s._vectorIndex[++index];
		}
		Item operator++(int) { // Postfix form
			//       require(index < s.top,
			//         "iterator moved out of range");
			return s._vectorIndex[index++];
		}
		// Jump an iterator forward
		iterator& operator+=(int amount) {
			//       require(index + amount < s.top,
			//         " StackTemplate::iterator::operator+=() "
			//         "tried to move out of bounds");
			index += amount;
			return *this;
		}
		// To see if you're at the end:
		bool operator==(const iterator& rv) const {
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const {
			return index != rv.index;
		}
		friend std::ostream& operator<<(
			std::ostream& os, const iterator& it) {
			return os << *it;
		}
	};
	iterator begin() { return iterator(*this); }
	// Create the "end sentinel":
	iterator end() { return iterator(*this, true);}
};

// TODO: iterators...
// http://www.daniweb.com/forums/thread185190.html#
// http://www.oreillynet.com/pub/a/network/2005/11/21/what-is-iterator-in-c-plus-plus-part2.html?page=5
// http://stackoverflow.com/questions/148540/c-creating-my-own-iterators

#endif

