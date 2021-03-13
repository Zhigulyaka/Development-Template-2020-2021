#include "list.h"

#include <gtest.h>


TEST(ListElem, can_create_element)
{
	ASSERT_NO_THROW(ListElem<int> e(5));
}

TEST(ListElem, can_get_element_data)
{
	ListElem<int> e(5);
	EXPECT_EQ(e.GetData(), 5);
}

TEST(ListElem, can_set_element_data)
{
	ListElem<int> e(5);
	ASSERT_NO_THROW(e.SetData(6));
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l());
}


TEST(List, can_insert_first_element)
{

	List<int> l;
	ASSERT_NO_THROW(l.InsFirst(7));
}

TEST(List, can_insert_last_element)
{

	List<int> l;
	ASSERT_NO_THROW(l.InsLast(7));
}



TEST(List, can_get_first_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	l.InsFirst(k);
	l.InsLast(m);
	EXPECT_EQ(7, l.GetFirst()->GetData());
}

TEST(List, can_get_last_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	l.InsFirst(k);
	l.InsLast(m);
	EXPECT_EQ(5, l.GetLast()->GetData());
}

TEST(List, can_get_middle_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	EXPECT_EQ(3, l.GetMiddle(n)->GetData());
}



TEST(List, can_delete_first_element)
{

	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l.DelFirst());
}

TEST(List, can_delete_last_element)
{
	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l.DelLast());
}




TEST(List, can_assign_list_to_itself)
{
	List<int> l;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	ASSERT_NO_THROW(l = l);
}

TEST(List, can_assign_list_to_other_with_equal_size)
{
	List<int> l1;
	List<int> l2;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l2.InsFirst(n);
	l2.InsLast(m);
	ASSERT_NO_THROW(l1 = l2);

}

TEST(List, can_assign_list_to_other_with_non_equal_size)
{
	List<int> l1;
	List<int> l2;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l2.InsFirst(n);
	l2.InsLast(m);
	ASSERT_NO_THROW(l1 = l2);

}


TEST(List, can_create_circle_list)
{
	List<int> l1;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(k);
	ASSERT_NO_THROW(l1.Circle(3));

}

TEST(List, check_rabbit_circle_list)
{
	List<int> l1;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(k);
	l1.Circle(3);
	EXPECT_EQ(1,l1.Rabbit());

}

TEST(List, check_rotate_circle_list)
{
	List<int> l1;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(k);
	l1.Circle(3);
	EXPECT_EQ(true, l1.Rotate());

}

TEST(List, check_rabbit_not_circle_list)
{
	List<int> l1;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(k);
	EXPECT_EQ(0, l1.Rabbit());

}

TEST(List, check_rotate_not_circle_list)
{
	List<int> l1;
	int k = 7;
	int m = 5;
	int n = 3;
	l1.InsFirst(k);
	l1.InsLast(n);
	l1.InsLast(n);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(m);
	l1.InsLast(k);
	EXPECT_EQ(0, l1.Rotate());

}