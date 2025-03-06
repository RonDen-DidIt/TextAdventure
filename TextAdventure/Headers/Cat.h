#pragma once
#include "Item.h"

class Cat : public Item {
public:
	Cat();
	void Description() const override;
	void Use() override;
private:
	bool purring = false;
};
