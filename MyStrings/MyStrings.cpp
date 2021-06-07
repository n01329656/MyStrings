#include"mystring.h"
#include<algorithm>
#include<iterator>





int main()
{
    
    using namespace Mstring;
    
    // Demo how it works 
    mystring str1("Hello");
    mystring str2("WorldABCDEFG" + str1);
    std::cout << str2 + "\n";
    mystring result("ABCDEFG");
    // possible usage with some STL algorithms
    std::random_shuffle(result.begin(), result.end()); 
    std::copy(result.begin(), result.end(), std::ostream_iterator<char>(std::cout, ", "));
    std::cout << "\n";
    std::sort(result.begin(),result.end()); 
    std::copy(result.begin(),result.end(),std::ostream_iterator<char>(std::cout,", "));
    std::cout<<"\n"<<result;
    result = "HELLOO";
    std::cout << "\n" << result<<"\n";
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i];
    std::cout << std::endl;
    // result[result.size()]; throws an exception 
  
    return 0;

}
