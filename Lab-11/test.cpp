#include "pch.h"
#include "SortClass.h"

TEST(Frunza, Jack) {
	int* a;
	a = new int[100];
	a[1] = 12;
	a[2] = 124;
	a[3] = 55;
	a[4] = 55;
	a[5] = NULL;
	SortClass<int> S;
	S.Sort(a,false);
	EXPECT_EQ(a[1],12);
	EXPECT_EQ(a[2],55);
	EXPECT_EQ(a[3],55);
	EXPECT_EQ(a[4],124);
}

TEST(Frunza, Queen) {
	int* a;
	a = new int[100];
	a[1] = 3;
	a[2] = 2;
	a[3] = 1;
	a[4] = NULL;
	SortClass<int> S;
	S.Sort(a,true);
	EXPECT_EQ(a[1], 3);
	EXPECT_EQ(a[2], 2);
	EXPECT_EQ(a[3], 1);
}

