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

TEST_CASE("Correct Node is found for given Path", "[vectree]") {
    const auto tree1 = new TreeType(21);
    const auto tree2 = new TreeType(13);
    const auto tree3 = new TreeType(22, *tree1, *tree2);

    // tree2 should be on the right of tree3
    REQUIRE(tree3->getByPath("R") == 13);
    // there are no paths coming from a tree with no leaves
    REQUIRE_THROWS(tree1->getByPath("L"));
    REQUIRE_THROWS(tree1->getByPath("R"));
    // No path should return the root
    REQUIRE(tree1->getByPath("") == 21);
    // can't go too deep
    REQUIRE_THROWS(tree3->getByPath("RR"));

    delete tree3;
    delete tree2;
    delete tree1;


}
