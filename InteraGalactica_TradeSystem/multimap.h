/*
Author - Isaac Richards
Date - 29AUG23
Description - multimap.h contains utility functions for use with std::multimap.
*/
#pragma once

#include <map>
#include <set>

namespace multimap {
	/// <returns>A set of all keys in multimap (without repeats).  Meant to help with accessing all values in a multimap by key.</returns>
	template <typename TKey, typename T>
	std::set<TKey> GetUniqueKeys(std::multimap<TKey, T> multimap) {
		std::set<TKey> keys;
		for (auto it = multimap.begin(); it != multimap.end(); ++it) {
			TKey key = it->first;
			if (keys.find(key) != keys.end())
				continue;

			keys.insert(key);
		}

		return keys;
	}
}