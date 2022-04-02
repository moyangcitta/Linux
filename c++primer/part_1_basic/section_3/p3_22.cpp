#include<iostream>
#include<vector>
#include<string.h>
//把text的第一段都改成大写并输出
int main(){
    std::string text = "jfal;skdjfoqwhe;n;thajfjad;kfsja; jdfklja;jdfkjiw jakldjfa;iemn kjfa;ljdioa";
    for(std::string::iterator it = text.begin(); it != text.end() && !isspace(*it); it++){
        *it = toupper(*it);
    }
    std::cout << text << std::endl;
    return 0;
}