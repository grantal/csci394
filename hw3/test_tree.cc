#define CATCH_CONFIG_MAIN
/*
 * Tree class unit tests
 * Written by Eitan Frachtenberg.
 */

#include "catch.hpp"
#include "tree.hh"
#include "vectree.hh"

using TreeType = tree::VecTree;  // Change this to test other subclasses of Tree

TEST_CASE("size is computed correctly", "[vectree]") {
    const auto tree1 = new TreeType(15);

    SECTION("leaf case") {
        REQUIRE(tree1->size() == 1);
    }

    SECTION("compound tree") {
        const auto tree2 = new TreeType(10);
        const auto tree3 = new TreeType(7, *tree1, *tree2);
        REQUIRE(tree2->size() == 1);
        REQUIRE(tree3->size() == 3);

        delete tree3;
        delete tree2;
    }

    delete tree1;
}


TEST_CASE("Path is computed correctly", "[vectree]") {
    const auto tree1 = new TreeType(15);
    const auto tree2 = new TreeType(10);
    const auto tree3 = new TreeType(7, *tree1, *tree2);

    REQUIRE(tree3->pathTo(15) == "L");
    REQUIRE_THROWS(tree3->pathTo(2));

    delete tree3;
    delete tree2;
    delete tree1;
}

