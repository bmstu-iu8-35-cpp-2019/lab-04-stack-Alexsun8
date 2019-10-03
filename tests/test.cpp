// Copyright 2019 ALEXSUN.8 <your_email>

#include <gtest/gtest.h>

#include <header.hpp>
#include "/home/alexsun8/CLionProjects/lab-04-stack-Alexsun8/sources/source.cpp"

TEST(STACK, first){
    stack<int> first;
   // stack<int> sec(std::move(first));
stack<int>sec();

    sec.push(-80);
    sec.push(180);


    EXPECT_EQ(180, sec.head());
    sec.pop();
    EXPECT_EQ(-80, sec.head());

    stack<int> third;

    int a = 2903;
    third.push(a);
    a++;
    third.push(a);

    EXPECT_EQ(2904, third.head());
    third.pop();
    EXPECT_EQ(2903, third.head());
    EXPECT_TRUE(std::is_move_constructible<stack<int>>::value);
}

TEST(Stack, second){
    EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);

    Stack<std::string> first;
    first.push("string 1!");

    first.push("string 2!");
    std::string test = "string 2!";
    EXPECT_EQ(test, first.pop());

    test = "string 1!";
    EXPECT_EQ(test, first.head());

 /*   Stack<std::string> second(std::move(first));
    EXPECT_EQ(test, second.head());

    Stack<std::vector<int>> third;
    third.push_emplace(4);
    EXPECT_EQ(4, second.head().size());
*/
}