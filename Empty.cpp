# include "Empty.h"

void Empty(Person& Data) {

	int i, j;

	for (i = 0; i < Data.Quantity + 1; i++) {

		for (j = 0; j < Data.Quantity; j++) {

			Data.Data[j] = Data.Data[j + 1];
		}
	}

	Data.Quantity = 0;
}