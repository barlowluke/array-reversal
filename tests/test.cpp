#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "reverse.hpp"
#include <cstring>
#include <sstream>

TEST_CASE("Reverse integer array", "[reverse_array]") {
    int ai[] = {1, 2, 3, 4};
    int ni = sizeof(ai) / sizeof(ai[0]);
    
    SECTION("Original array order") {
        // Test print_array output for original array
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(ai, ni);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[1, 2, 3, 4]\n");
    }
    
    SECTION("Reverse operation") {
        reverse_array<int>(ai, ni);
        REQUIRE(ai[0] == 4);
        REQUIRE(ai[1] == 3);
        REQUIRE(ai[2] == 2);
        REQUIRE(ai[3] == 1);
    }
    
    SECTION("Reversed array print") {
        reverse_array<int>(ai, ni);
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(ai, ni);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[4, 3, 2, 1]\n");
    }
}

TEST_CASE("Reverse double array", "[reverse_array]") {
    double ad[] = {1.5, 2.5, 3.5, 4.5};
    int nd = sizeof(ad) / sizeof(ad[0]);
    
    SECTION("Original array order") {
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<double>(ad, nd);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[1.5, 2.5, 3.5, 4.5]\n");
    }
    
    SECTION("Reverse operation") {
        reverse_array<double>(ad, nd);
        REQUIRE(ad[0] == 4.5);
        REQUIRE(ad[1] == 3.5);
        REQUIRE(ad[2] == 2.5);
        REQUIRE(ad[3] == 1.5);
    }
    
    SECTION("Reversed array print") {
        reverse_array<double>(ad, nd);
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<double>(ad, nd);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[4.5, 3.5, 2.5, 1.5]\n");
    }
}

TEST_CASE("Reverse char array", "[reverse_array]") {
    char letters[] = {'E', 'C', 'E', '3', '5', '1', '4'};
    int nc = sizeof(letters) / sizeof(letters[0]);
    
    SECTION("Original array order") {
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<char>(letters, nc);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[E, C, E, 3, 5, 1, 4]\n");
    }
    
    SECTION("Reverse operation") {
        reverse_array<char>(letters, nc);
        REQUIRE(letters[0] == '4');
        REQUIRE(letters[1] == '1');
        REQUIRE(letters[2] == '5');
        REQUIRE(letters[3] == '3');
        REQUIRE(letters[4] == 'E');
        REQUIRE(letters[5] == 'C');
        REQUIRE(letters[6] == 'E');
    }
    
    SECTION("Reversed array print") {
        reverse_array<char>(letters, nc);
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<char>(letters, nc);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[4, 1, 5, 3, E, C, E]\n");
    }
}

TEST_CASE("Reverse C-string", "[reverse_array]") {
    char word[] = "hello";
    int nw = std::strlen(word);
    
    SECTION("Original string") {
        REQUIRE(std::string(word) == "hello");
    }
    
    SECTION("Reverse operation preserves null terminator") {
        char original_terminator = word[nw]; // Should be '\0'
        reverse_array<char>(word, nw);
        char new_terminator = word[nw]; // Should still be '\0'
        
        REQUIRE(original_terminator == '\0');
        REQUIRE(new_terminator == '\0');
        REQUIRE(std::string(word) == "olleh");
    }
    
    SECTION("Double reverse returns to original") {
        reverse_array<char>(word, nw);
        reverse_array<char>(word, nw);
        REQUIRE(std::string(word) == "hello");
    }
}

TEST_CASE("Edge cases", "[reverse_array]") {
    SECTION("Empty array") {
        int empty[] = {};
        int ne = 0;
        
        // Should not crash
        reverse_array<int>(empty, ne);
        
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(empty, ne);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[]\n");
    }
    
    SECTION("Single element array") {
        int single[] = {42};
        int ns = 1;
        
        reverse_array<int>(single, ns);
        REQUIRE(single[0] == 42);
        
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(single, ns);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[42]\n");
    }
    
    SECTION("Two element array") {
        int two[] = {1, 2};
        int nt = 2;
        
        reverse_array<int>(two, nt);
        REQUIRE(two[0] == 2);
        REQUIRE(two[1] == 1);
    }
}

TEST_CASE("print_array formatting", "[print_array]") {
    SECTION("Correct comma placement") {
        int arr[] = {1, 2, 3};
        int n = 3;
        
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(arr, n);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[1, 2, 3]\n");
    }
    
    SECTION("No trailing comma") {
        int arr[] = {1};
        int n = 1;
        
        std::stringstream ss;
        std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
        print_array<int>(arr, n);
        std::cout.rdbuf(old_cout);
        
        REQUIRE(ss.str() == "[1]\n");
    }
}