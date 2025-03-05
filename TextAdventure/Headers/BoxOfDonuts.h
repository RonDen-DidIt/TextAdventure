#pragma once
#include "Item.h"

class BoxOfDonuts : public Item {
	 void Description() const override;
	 void Use() override;
private:
	int count = 0;
};
