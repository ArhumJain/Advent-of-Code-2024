#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <regex>
#include <sstream>
#include <utility>
#include <complex>


using namespace std;
using namespace std::complex_literals;

namespace aoc {
    using F = std::ifstream;

    template <typename T>
    using vec3d = std::vector<std::vector<std::vector<T>>>;

    template <typename T>
    using vec2d = std::vector<std::vector<T>>;

    template<typename T>
    using vec = std::vector<T>;

    template<typename T1, typename T2>
    using umap = std::unordered_map<T1, T2>;

    template<typename T>
    using uset = std::unordered_set<T>;

    template<typename T1, typename T2>
    using tup = std::tuple<T1, T2>;

    using ul = unsigned long;
    using ll = long long;
    using ull = unsigned long long;

    using cfloat = std::complex<float>;
    using cdouble = std::complex<double>;

    using sstream = std::stringstream;

    static const vec<std::pair<int, int>> DIRECTIONS = {{0,-1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}}; // Starts West, then clockwise
    static const vec<cfloat> CCARDINALS = {-1.0f + 0if, 0.0f + 1if, 1.0f + 0if, 0.0f + -1if};
    static const vec<std::pair<int,int>> CARDINALS = {{-1,0}, {0,1}, {1, 0}, {0, -1}}; // Starts West, then clockwise
    static const vec<std::pair<int,int>> DIAGONALS = {{-1,-1}, {-1, 1}, {1, 1}, {1, -1}}; // Starts top left, then clockwise


    template <typename T> 
    void print1d(std::vector<T> &v, string delimiter="\n") {
        for (T i: v) std::cout << i << delimiter;
    }

    template <typename T> 
    std::ostream &operator<<(ostream &o, std::vector<T> &v) {
        for_each(v.begin(), v.end(), [&](T &a){o << a << " ";});
        return o;
    }


    template <typename T> 
    void print2d(std::vector<std::vector<T>> &v, string delimitColumn=" ", string delimitRow="\n") {
        for (auto _: v) {
            for(T i: _) std::cout << i << delimitColumn;
            std::cout << delimitRow;
        }
    }

    bool gridOutOfBounds(int row, int col, int maxRow, int maxCol) {
      return !(row >= 0 && row < maxRow && col >= 0 && col < maxCol);
    }

    template <typename T>
    inline bool sign(T n) {
        return n >= 0 ? true : false;
    }

    std::vector<std::string> split(std::string s, std::string d = " ") { // thanks stackoverflow!
        std::vector<std::string> sp;
        int start, end = -1*d.size();
        do {
            start = end + d.size();
            end = s.find(d, start);
            sp.push_back(s.substr(start, end-start));
        } while (end != -1);
        return sp;
    }

    std::vector<int> splitInt(std::string s, std::string d = " ") { // thanks stackoverflow!
        std::vector<int> sp;
        int start, end = -1*d.size();
        do {
            start = end + d.size();
            end = s.find(d, start);
            sp.push_back(stoi(s.substr(start, end-start)));
        } while (end != -1);
        return sp;
    }

    std::vector<long> splitLong(std::string s, std::string d = " ") { // thanks stackoverflow!
        std::vector<long> sp;
        int start, end = -1*d.size();
        do {
            start = end + d.size();
            end = s.find(d, start);
            sp.push_back(stol(s.substr(start, end-start)));
        } while (end != -1);
        return sp;
    }

    std::vector<long long> splitLongLong(std::string s, std::string d = " ") { // thanks stackoverflow!
        std::vector<long long> sp;
        int start, end = -1*d.size();
        do {
            start = end + d.size();
            end = s.find(d, start);
            sp.push_back(stoll(s.substr(start, end-start)));
        } while (end != -1);
        return sp;
    }

    string read(std::ifstream &f) {
        std::string r((std::istreambuf_iterator<char>(f)),
                            (std::istreambuf_iterator<char>()));
        return r;   
    }

    void readlines(std::ifstream &f, std::vector<std::string> &r) {
        std::string _;
        while (getline(f, _)) r.push_back(_);
    }
    
    std::vector<std::string> readlines(std::ifstream &f) {
        std::vector<std::string> lines;
        std::string r;
        while (getline(f, r)) {
            lines.push_back(r);
        }
        return lines;
    }

}
