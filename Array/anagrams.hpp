#pragma once

bool anagrams(std::string a, std::string b, int alphabet=123){
	int length = a.size();
	if(length != b.size()) return false;
	
	int occurences[alphabet];
	for(int i=0; i<alphabet; i++) occurences[i] = 0;
	
	for(int i=0; i<length; i++){
		occurences[a[i]]++;
		occurences[b[i]]--;
	}
	
	for (int i=0; i<alphabet; i++)
		if(occurences[i] != 0) return false;
	return true;
}
