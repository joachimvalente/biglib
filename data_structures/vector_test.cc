#include "data_structures/vector.h"

#include "gtest/gtest.h"

namespace big {

TEST(VectorTest, DefaultConstructor) {
  vector<int> v;
  EXPECT_EQ(0, v.size());
  EXPECT_EQ(0, v.capacity());
}

TEST(VectorTest, ConstructorWithSize) {
  vector<int> v(5);
  ASSERT_EQ(5, v.size());
  EXPECT_EQ(5, v.capacity());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(0, v[i]);
  }
}

TEST(VectorTest, ConstructorWithSizeAndValue) {
  vector<int> v(10, 2);
  ASSERT_EQ(10, v.size());
  EXPECT_EQ(10, v.capacity());
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(2, v[i]);
  }
}

TEST(VectorTest, CopyConstructor) {
  vector<int> v(10, 2);
  vector<int> w(v);
  ASSERT_EQ(10, w.size());
  EXPECT_EQ(10, w.capacity());
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(2, w[i]);
  }
}

TEST(VectorTest, Assignment) {
  vector<int> v(10, 2);
  vector<int> w;
  w = v;;
  ASSERT_EQ(10, w.size());
  EXPECT_EQ(10, w.capacity());
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(2, w[i]);
  }
}

TEST(VectorTest, AssignmentChangesCapacity) {
  vector<int> v(10, 2);
  vector<int> w(60, 3);
  ASSERT_EQ(60, w.capacity());
  w = v;;
  EXPECT_EQ(10, w.capacity());
}

TEST(VectorTest, Empty) {
  vector<int> v(10, 2);
  vector<int> w;
  EXPECT_FALSE(v.empty());
  EXPECT_TRUE(w.empty());
}

TEST(VectorTest, EmptyWithPositiveCapacity) {
  vector<int> v;
  v.reserve(60);
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, ReserveLessThanCurrent) {
  vector<int> v(10, 2);
  v.reserve(5);
  EXPECT_EQ(10, v.capacity());
}

TEST(VectorTest, ReserveMoreThanCurrent) {
  vector<int> v(10, 2);
  v.reserve(60);
  EXPECT_EQ(60, v.capacity());
}

TEST(VectorTest, ReserveDoesNotChangeContent) {
  vector<int> v(5, 2);
  v.reserve(10);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(2, v[i]);
  }
}

TEST(VectorTest, ResizeSmaller) {
  vector<int> v(5, 2);
  v.resize(3);
  EXPECT_EQ(3, v.size());
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(2, v[i]);
  }
  EXPECT_DEATH(v[3], "");
}

TEST(VectorTest, ResizeSmallerWithValue) {
  vector<int> v(5, 2);
  v.resize(3, 4);
  EXPECT_EQ(3, v.size());
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(2, v[i]);
  }
  EXPECT_DEATH(v[3], "");
}

TEST(VectorTest, ResizeLarger) {
  vector<int> v(5, 2);
  v.resize(10);
  ASSERT_EQ(10, v.size());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(2, v[i]);
  }
  for (int i = 5; i < 10; ++i) {
    EXPECT_EQ(0, v[i]);
  }
}

TEST(VectorTest, ResizeLargeriWithValue) {
  vector<int> v(5, 2);
  v.resize(10, 4);
  ASSERT_EQ(10, v.size());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(2, v[i]);
  }
  for (int i = 5; i < 10; ++i) {
    EXPECT_EQ(4, v[i]);
  }
}

TEST(VectorTest, PushBack) {
  vector<int> v(5, 2);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(3);
  ASSERT_EQ(9, v.size());
  EXPECT_LE(9, v.capacity());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(2, v[i]);
  }
  EXPECT_EQ(1, v[5]);
  EXPECT_EQ(2, v[6]);
  EXPECT_EQ(2, v[7]);
  EXPECT_EQ(3, v[8]);
}

TEST(VectorTest, PopBack) {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  EXPECT_EQ(3, v.size());
  EXPECT_EQ(30, v.back());
  v.pop_back();
  EXPECT_EQ(2, v.size());
  EXPECT_EQ(20, v.back());
  v.pop_back();
  EXPECT_EQ(1, v.size());
  EXPECT_EQ(10, v.back());
  v.pop_back();
  EXPECT_EQ(0, v.size());
  EXPECT_DEATH(v.pop_back(), "");
  EXPECT_DEATH(v.back(), "");
}

TEST(VectorTest, Insert) {
  vector<int> v;
  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
  }
  v.insert(3, 42);
  ASSERT_EQ(6, v.size());
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(i, v[i]);
  }
  EXPECT_EQ(42, v[3]);
  for (int i = 4; i < 6; ++i) {
    EXPECT_EQ(i - 1, v[i]);
  }
}

TEST(VectorTest, InsertInvalidPosition) {
  vector<int> v(5, 2);
  EXPECT_DEATH(v.insert(6, 3), "");
  v.insert(5, 3);
}

TEST(VectorTest, Erase) {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.erase(1);
  ASSERT_EQ(2, v.size());
  EXPECT_EQ(10, v[0]);
  EXPECT_EQ(30, v[1]);
}

TEST(VectorTest, EraseInvalidPosition) {
  vector<int> v(10, 2);
  EXPECT_DEATH(v.erase(10), "");
  v.erase(9);
}

TEST(VectorTest, Clear) {
  vector<int> v(10, 2);
  v.clear();
  EXPECT_EQ(0, v.size());
  EXPECT_EQ(0, v.capacity());
}

TEST(VectorTest, Assign) {
  vector<int> v(10, 2);
  v.assign(5, 3);
  ASSERT_EQ(5, v.size());
  EXPECT_EQ(5, v.capacity());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(3, v[i]);
  }
}

TEST(VectorTest, ElementAccess) {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  ASSERT_EQ(10, v.size());
  for (int i = 0; i < 10; ++i) {
    // Non-const accessors.
    v[i] *= 2;
    v.at(i) *= 5;
  }
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(10 * i, v[i]);
    EXPECT_EQ(10 * i, v.at(i));
  }
}

TEST(VectorTest, BackAndFront) {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  v.front() = 42;
  v.back() = 58;
  ASSERT_EQ(10, v.size());
  EXPECT_EQ(42, v[0]);
  EXPECT_EQ(42, v.front());
  EXPECT_EQ(58, v[9]);
  EXPECT_EQ(58, v.back());
}

TEST(VectorTest, AccessorsFailOnEmptyVector) {
  vector<int> v;
  EXPECT_DEATH(v.back());
  EXPECT_DEATH(v.front());
  EXPECT_DEATH(v.pop_back());
}

}  // namespace big
