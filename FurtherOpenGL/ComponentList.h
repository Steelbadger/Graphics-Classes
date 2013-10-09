#pragma once
#include <vector>
#include "Component.h"

class ComponentList
{
public:
	ComponentList(void);
	~ComponentList(void);
	template<typename T>
	void AddComponent(T& comp) {
		list.push_back(&comp);
	}
	template<typename T>
	T* GetComponent() {

	}

private:
	std::vector<Component*> list;
};

