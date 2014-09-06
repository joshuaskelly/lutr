/*
 *  Utility.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A utility class primarily for string operations.
 */

#ifndef pal2cube_utility_h
#define pal2cube_utility_h

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>

// trim from start
static inline std::string &left_trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &right_trim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return left_trim(right_trim(s));
}

/*
 *  split
 *  @description: Tokenizes a string given a delimiter.
 *  @param s: The string to process.
 *  @param delim: The delimiter.
 *  @returns: A vector of strings.
 */
static inline std::vector<std::string> split(std::string s, std::string delim) {
    std::vector<std::string> result;
    
    size_t start = 0;
    size_t pos = s.find(delim, start);
    
    while (pos != std::string::npos) {
        std::string sub = s.substr(start, pos - start);
        
        if (sub.length() > 0) {
            result.push_back(sub);
        }
        
        start = pos + delim.length();
        pos = s.find(delim, start);
    }
    
    result.push_back(s.substr(start, s.length() - start));
    
    return result;
}

#endif
