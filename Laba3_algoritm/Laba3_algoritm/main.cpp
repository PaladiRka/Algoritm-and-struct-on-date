#include "intHashMap.h"
#include <iostream>
#include "binary_tree.h"
#include "Set.h"
#include"HashMapSequence.h"

int main()
{
	//HashMapSequence A, B, C;

	//int buf;

	//for (int i = 0; i < 8; i++)
	//{
	//	std::cin >> buf;
	//	A.put(i, buf);
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cin >> buf;
	//	B.put(i, buf);
	//}
	//C = A.ERASE(1, 3);
	//std::cout << "C = A.ERASE(1, 3)" << std::endl;
	//std::cout << "A" << '	' << "B" << '	' << "C" << std::endl;

	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << A.get(i) << '	' << B.get(i) << '	' << C.get(i) << std::endl;
	//}
	//system("pause");
	//
	//A.CHANGE(B, 3);
	//std::cout << "A.CHANGE(B, 3)" << std::endl;
	//std::cout << "A" << '	' << "B" << '	' << "C" << std::endl;

	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << A.get(i) << '	' << B.get(i) << '	' << C.get(i) << std::endl;
	//}
	//system("pause");

	//C = B.EXCL(C);
	//std::cout << "C = B.EXCL(C)" << std::endl;
	//std::cout << "A" << '	' << "B" << '	' << "C" << std::endl;

	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << A.get(i) << '	' << B.get(i) << '	' << C.get(i) << std::endl;
	//}
	//system("pause");

	//IntHashMap map3;
	//for (int i = 0; i < 32; i++)
	//{
	//	map3.put(i, map3.rand_value());
	//}
	//IntHashMap map4;
	//for (int i = 0; i < 32; i++)
	//{
	//	map4.put(i, map4.rand_value());
	//}
	//IntHashMap map5;
	//for (int i = 0; i < 32; i++)
	//{
	//	map5.put(i, map5.rand_value());
	//}
	//
	//IntHashMap map6 = (map1 * map2);
	//IntHashMap buf = (map3 * map4);
	//map6 = map6 / buf + map5;
	//std::cout << "map6" << '	' << "map1" << '	' << "map2" << '	' << "map3" << '	' << "map4" << '	' << "map5" << std::endl;

	//for (int i = 0; i < 32; i++)
	//{
	//	std::cout << map6.get(i) << '	' << map1.get(i) << '	' << map2.get(i) << '	' << map3.get(i) << '	' << map4.get(i) << '	' << map5.get(i) << std::endl;
	//}
	//system("pause");

	////----------------------------------------------------
	auto f1 = []() { return rand() * 5 % MAX_INT + 1; };


	BinaryTree tree1;
	for (int i = 1; i < 33; i++)
	{
		tree1.put(i, f1());
	}
	BinaryTree tree2;
	for (int i = 1; i < 33; i++)
	{
		tree2.put(i, f1());
	}
	BinaryTree tree3;
	for (int i = 1; i < 33; i++)
	{
		tree3.put(i, f1());
	}
	BinaryTree tree4;
	for (int i = 1; i < 33; i++)
	{
		tree4.put(i, f1());
	}
	BinaryTree tree5;
	for (int i = 1; i < 33; i++)
	{
		tree5.put(i, f1());
	}
	BinaryTree tree6 = (tree1 & tree2);
	BinaryTree buf1 = (tree3 & tree4);

	std::cout << std::endl << "tree1: ";
	tree1.out();
	std::cout << std::endl << "tree2: ";
	tree2.out();
	std::cout << std::endl << "tree1 & tree2: ";
	tree6.out();
	std::cout << std::endl;
	system("pause");
	std::cout << std::endl << "tree3: ";
	tree3.out();
	std::cout << std::endl << "tree4: ";
	tree4.out();
	std::cout << std::endl << "tree3 & tree4: ";
	buf1.out();
	std::cout << std::endl;
	system("pause");


	std::cout << std::endl << "tree1 & tree2: ";
	tree6.out();

	tree6 = tree6 / buf1;

	std::cout << std::endl << "tree3 & tree4: ";
	buf1.out();
	std::cout << std::endl << "(tree1 & tree2)\(tree3 & tree4): ";
	tree6.out();
	std::cout << std::endl;
	system("pause");

	std::cout << std::endl << "tree5: ";
	tree5.out();

	tree6 = tree6 + tree5;

	std::cout << std::endl << "(tree1 & tree2)\(tree3 & tree4) + tree5: ";
	tree6.out();
	std::cout << std::endl;
	system("pause");

}