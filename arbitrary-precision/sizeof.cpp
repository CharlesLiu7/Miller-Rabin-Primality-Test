#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <iostream>
int main() {
    using namespace std;
    namespace mp = boost::multiprecision;
    cout << "size_t: " << sizeof(size_t) << endl;
    cout << "uint1024_t: " << sizeof(mp::uint1024_t) << endl;
    cout << "cpp_int: " << sizeof(mp::cpp_int) << endl;
    cout << "signed_magnitude: " << sizeof(mp::signed_magnitude) << endl;
    cout << "gmp_int: " << sizeof(mp::gmp_int) << endl;
}
