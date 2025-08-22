#pragma once

#include <unordered_map>

class IDManager {
public:
	template<typename T> 
	static int getMaxID(const unordered_map<int, T> &curr) {
		int maxID = 0; 
		for (auto it = curr.begin(); it != curr.end(); it++) {
			if (it->first > maxID) {
				maxID = it->first; 
			}
		}
		return maxID; 
	}

	template<typename T>
	static int generateNextID(const unordered_map<int, T> &curr) {
		return getMaxID(curr) + 1;
	} 

	template<typename T> 
	static vector<int> getIDSet(const unordered_map<int, T> &curr) {
		vector<int> data; 
		for (auto it = curr.begin(); it != curr.end(); it++) {
			data.push_back(it->first); 
		}
		return data; 
	}
}; 