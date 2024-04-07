#include "gtest.h"
#include "../tablelib/ArrayTable.h"
#include "../tablelib/ListTable.h"
#include "../tablelib/SortedTable.h"
#include "../tablelib/ChainHashTable.h"
#include "../tablelib/DoubleHashTable.h"
#include "../tablelib/AVLTable.h"
using namespace std;


TEST(ArrayTable, Insert) {
    ArrayTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(ArrayTable, Delete) {
    ArrayTable table;
    table.Insert( "one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(ArrayTable, IsEmpty) {
    ArrayTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(ArrayTable, Find) {
    ArrayTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}

TEST(ArrayTable, GoNext) {
    ArrayTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GoNext(), 2);
}

TEST(ArrayTable, GetKey) {
    ArrayTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GetKey(), "one");
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GetKey(), "two");
}

TEST(ListTable, Insert) {
    ListTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(ListTable, Delete) {
    ListTable table;
    table.Insert("one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(ListTable, IsEmpty) {
    ListTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(ListTable, Find) {
    ListTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}
TEST(SortedTable, Insert) {
    SortedTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(SortedTable, Delete) {
    SortedTable table;
    table.Insert("one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(SortedTable, IsEmpty) {
    SortedTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(SortedTable, Find) {
    SortedTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}

TEST(SortedTable, GoNext) {
    SortedTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GoNext(), 2);
}

TEST(SortedTable, GetKey) {
    SortedTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GetKey(), "one");
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GetKey(), "two");
}

TEST(ChainHashTable, Insert) {
    ChainHashTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(ChainHashTable, Delete) {
    ChainHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(ChainHashTable, IsEmpty) {
    ChainHashTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(ChainHashTable, Find) {
    ChainHashTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}

TEST(ChainHashTable, GoNext) {
    ChainHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GoNext(), 2);
    ASSERT_EQ(table.GoNext(), 3);
}

TEST(ChainHashTable, GetKey) {
    ChainHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GetKey(), "one");
    ASSERT_EQ(table.GoNext(), 2);
    ASSERT_EQ(table.GetKey(), "two");
}

TEST(DoubleHashTable, Insert) {
    DoubleHashTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(DoubleHashTable, Delete) {
    DoubleHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(DoubleHashTable, IsEmpty) {
    DoubleHashTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(DoubleHashTable, Find) {
    DoubleHashTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}

TEST(DoubleHashTable, GoNext) {
    DoubleHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GoNext(), 2);
}

TEST(DoubleHashTable, GetKey) {
    DoubleHashTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GetKey(), "one");
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GetKey(), "two");
}

TEST(AVLTable, Insert) {
    AVLTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_EQ(table.GetDataCount(), 1);
}

TEST(AVLTable, Delete) {
    AVLTable table;
    table.Insert("one", TPolinom("1"));
    table.Delete("one");
    ASSERT_EQ(table.GetDataCount(), 0);
    ASSERT_EQ(table.Find("one"), nullptr);
}

TEST(AVLTable, IsEmpty) {
    AVLTable table;
    ASSERT_TRUE(table.IsEmpty());
    table.Insert("one", TPolinom("1"));
    ASSERT_FALSE(table.IsEmpty());
}

TEST(AVLTable, Find) {
    AVLTable table;
    table.Insert("one", TPolinom("1"));
    ASSERT_NE(table.Find("one"), nullptr);
    ASSERT_EQ(table.Find("two"), nullptr);
}

TEST(AVLTable, GoNext) {
    AVLTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GoNext(), 2);
}

TEST(AVLTable, GetKey) {
    AVLTable table;
    table.Insert("one", TPolinom("1"));
    table.Insert("two", TPolinom("2"));
    ASSERT_EQ(table.GetKey(), "one");
    ASSERT_EQ(table.GoNext(), 1);
    ASSERT_EQ(table.GetKey(), "two");
}