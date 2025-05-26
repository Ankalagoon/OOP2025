#pragma once
#include "Catalog.h"
class CatalogRo :public Catalog
{
public:
	CatalogRo(int nrs=30, int nrm=4) : Catalog(nrs, nrm) {
	};
};

