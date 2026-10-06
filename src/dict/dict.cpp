// works on open addressing with linear probing
#include <cstdint>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>
typedef struct node {
	size_t hash;
	bool occupied = false;
	bool tombstone = false;
	std::string key;
	std::string value;
} node;

class Dict
{
private:
	std::vector<node> values;
	size_t old_size;
	size_t size;
	size_t total;
	size_t split_index;
	// based on fnv-1a
	size_t hash(const std::string &k)
	{
		// 64 fnv offset idk what this means just some math vro
		uint64_t h = 14695981039346656037ULL;
		for (char ch : k) {
			h ^= static_cast<uint8_t>(ch);
			// 64 bit fnv prime
			h *= 1099511628211ULL;
		}

		return static_cast<size_t>(h);
	}
	size_t offset(size_t hash)
	{
		size_t off = hash % old_size;
		if (off < split_index) {
			off = hash % size;
		}
		return off;
	}
	// programmer math, returns the nearest power of 2 >= n
	inline uint32_t next_pwr(uint32_t n)
	{
		if (n == 0)
			return 1;
		n--;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		return n + 1;
	}
	inline float space_used()
	{
		return (float)total / size;
	}
	void increase_size()
	{
		old_size = size;
		size = size * 2;
		values.resize(size);
		split_index = 0;
	}
	void decrease_size()
	{
		values.resize(size);
	}

public:
	Dict(size_t _size)
			: old_size(next_pwr(_size)), size(next_pwr(_size)), values(next_pwr(_size)), total(0),
				split_index(next_pwr(_size))
	{
	}
	void insert(std::string key, std::string value)
	{
		// if more than 50% space is used then resize the vector
		if (space_used() >= 0.5f) {
			increase_size();
		}

		if (split_index < old_size) {
			node &n = values.at(split_index);
			if (n.occupied) {
				if ((n.hash & old_size) != 0) {
					size_t new_off = split_index + old_size;
					values.at(new_off) = std::move(n);
					values.at(split_index) = node();
				}
			}
			split_index++;
		}

		size_t h = hash(key);
		size_t off = offset(h);
		// linear probing because uhh its good for cache or something
		while (values.at(off).occupied || values.at(off).tombstone) {
			if (values.at(off).hash == h) {
				if (values.at(off).occupied == true && values.at(off).key == key) {
					values.at(off).value = std::move(value);
					return;
				}
			}
			off = (off + 1) % size;
		}
		values.at(off).value = std::move(value);
		values.at(off).key = std::move(key);
		values.at(off).hash = h;
		values.at(off).occupied = true;
		values.at(off).tombstone = false;
		total++;
	}
	std::string get_val(const std::string &key)
	{
		size_t h = hash(key);
		size_t off = offset(h);
		while (values.at(off).occupied || values.at(off).tombstone) {
			if (values.at(off).occupied && values.at(off).hash == h) {
				if (values.at(off).key == key) {
					return values.at(off).value;
				}
			}
			off = (off + 1) % size;
		}
		return "key not found!!";
	}
	void remove_elem(const std::string &key)
	{
		// if less than 25% space is used then resize the vector
		if (space_used() <= 0.25f && split_index == old_size) {
			old_size = (size);
			size = size / 2;
			split_index = old_size - 1;
		}

		if (split_index >= old_size) {
			node &n = values.at(split_index);
			if (n.occupied) {
				size_t new_off = split_index - size;
				values.at(new_off) = std::move(n);
				values.at(split_index) = node();
			}
			split_index--;
			if (split_index < size) {
				decrease_size();
				split_index = size;
				old_size = size;
			}
		}

		size_t h = hash(key);
		size_t off = offset(h);
		while (values.at(off).occupied || values.at(off).tombstone) {
			if (values.at(off).occupied == true && values.at(off).hash == h) {
				if (values.at(off).key == key) {
					values.at(off).occupied = false;
					values.at(off).tombstone = true;
					total--;
					return;
				}
			}
			off = (off + 1) % size;
		}
	}
	void debug()
	{
		std::cout << "###STARTING DICT DEBUG###" << std::endl;
		std::cout << "size is: " << size << " occupied:" << total << std::endl;
		for (const node &n : values) {
			std::cout << "{" << n.key << ":" << n.value << "}" << "@" << n.hash << std::endl;
		}
		std::cout << "###ENDING DICT DEBUG###" << std::endl;
	}
};

int main()
{
	Dict dict = {6};
	dict.insert("gng", "69");
	dict.insert("gn1", "70");
	dict.insert("gn2", "71");
	dict.insert("gn3", "72");
	dict.insert("gn4", "72");
	dict.insert("gn5", "72");
	dict.debug();

	dict.remove_elem("gng");
	dict.remove_elem("gn1");
	dict.remove_elem("gn2");
	dict.remove_elem("gn3");
	dict.remove_elem("gn4");
	dict.debug();

	std::cout << dict.get_val("gn1") << std::endl;
	std::cout << dict.get_val("gn5") << std::endl;
}
