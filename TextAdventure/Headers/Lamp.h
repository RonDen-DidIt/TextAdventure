#pragma once
#include "Item.h"

class Lamp : public Item {
	 void Description() const override;
	 void Use() override;
private:
	bool turnedOn = false;
};

