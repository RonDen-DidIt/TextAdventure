#pragma once
#include "Item.h"

class Cat : public Item {
	 void Description() const override;
	 void Use() override;
private:
	bool purring = false;
};
