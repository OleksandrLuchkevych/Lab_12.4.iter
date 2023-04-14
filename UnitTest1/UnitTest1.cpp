#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4.iter/Lab_12.4.iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;
			for (int i = -2; i < 3; i++)
			{
				Elem* tmp = new Elem;
				tmp->info = i;
				if (L != NULL)
				{
					Elem* T = L;
					while (T->link != L)
						T = T->link;
					T->link = tmp;
				}
				else
				{
					L = tmp;
				}
				tmp->link = L;
			}

			int t = Count(L);
			Assert::AreEqual(t, 2);
		}
	};
}
