#pragma once

#include <stdio.h>
#include <memory>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace ly
{
	template<typename T>
	using unique = std::unique_ptr<T>;

	template<typename T>
	using shared = std::shared_ptr<T>;

	template<typename T>
	using weak = std::weak_ptr<T>;

	template<typename T>
	using List = std::vector<T>;

	template<typename keyType, typename valType, typename Pr = std::less<keyType>>
	using Map = std::map<keyType, valType, Pr>;

	template<typename keyType, typename valType, typename hasher = std::hash<keyType>>
	using Dictionary = std::unordered_map<keyType, valType, hasher>;

	template<typename T>
	using Set = std::unordered_set<T>;

	using unit8 = unsigned char;

	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	//a macro
	#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}