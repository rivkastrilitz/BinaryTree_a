#include "doctest.h"
#include <stdexcept>
#include <stdio.h>
#include "BinaryTree.hpp"
#include <array>
using namespace ariel;
TEST_CASE("good"){

    // ######## int tree pre order #########
    BinaryTree<int> tree_int;
    std::array<int,5>arr;
    std::array<int,5>arr_manual={5,7,8,10,6};
    u_int i=0;
    tree_int.add_root(5).add_left(5,4).add_left(5,7).add_right(5,6).add_left(7,8).add_right(7,10);
    CHECK_THROWS(tree_int.add_right(11,23));

    for (auto it=tree_int.begin_preorder(); it!=tree_int.end_preorder(); ++it){
        arr[i++]=(*it);
    }
    for(i=0;i<5;i++){
        CHECK_EQ(arr.at(i),arr_manual.at(i));
    }

    // ######## char tree post order #########
    BinaryTree<char> tree_char;
    std::array<char,5>arr1;
    std::array<char,5>arr_manual1={'u','n','g','t','a'};
    i=0;
    tree_char.add_root('a').add_left('a','n').add_left('n','u').add_right('a','t').add_left('t','g');

   
    for (auto it=tree_char.begin_preorder(); it!=tree_char.end_preorder(); ++it){
        arr1[i++]=(*it);
    }
    for(i=0;i<5;i++){
        CHECK_EQ(arr1.at(i),arr_manual1.at(i));
    }

    // ######## char tree in order #########
    BinaryTree<std::string> tree_string;
    std::array<std::string,5>arr2;
    std::array<std::string,5>arr_manual2={"hola","f","t","al","s"};
    i=0;
    CHECK_NOTHROW(tree_string.add_root("al"));
    CHECK_NOTHROW(tree_string.add_left("al","f"));
    CHECK_NOTHROW(tree_string.add_left("f","hola"));
    CHECK_NOTHROW(tree_string.add_right("f","t"));
    CHECK_NOTHROW(tree_string.add_right("al","s"));

     
    for (auto it=tree_string.begin_preorder(); it!=tree_string.end_preorder(); ++it){
        arr2[i++]=(*it);
    }
    for(i=0;i<5;i++){
        CHECK_EQ(arr2.at(i),arr_manual2.at(i));
    }

}
TEST_CASE("throw"){

    BinaryTree<int> tree_int;
    CHECK_THROWS(tree_int.add_left(10,2));
    
    tree_int.add_root(7);
    CHECK_THROWS(tree_int.add_right(3,8));
    // changing root and trying to add right 
    CHECK_NOTHROW(tree_int.add_left(7,9));
    tree_int.add_root(5);
    CHECK_THROWS(tree_int.add_right(7,6));


}

