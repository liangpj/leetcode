#include "../header.h"

/**Restore IP Addresses
Given a string containing only digits,
restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


inline
bool isIp(string str) {
    if (atol(str.c_str()) > 255
        || str[0] == '0' && str.size() > 1)
        return false;
    return true;

}

void backtrack(string s, int start, vector<string> &ip, vector<string> &ipaddr)
{
    if (start == s.size() && ip.size() == 4) {
        string addr = "";
        for (int i = 0; i < ip.size(); ++i) {
            addr += ip[i];
            if (i != ip.size()-1) addr += ".";
        }
        ipaddr.push_back(addr);
    }else {
        for (int i = start+1; i <= s.size(); ++i) {
            string ss = s.substr(start, i-start);
            if (ip.size() <= 3 && isIp(ss)){
                ip.push_back(ss);
                backtrack(s, i, ip, ipaddr);
                ip.pop_back();
            }
        }
    }
}
vector<string> restoreIpAddresses_bt(string s) {
    vector<string> ipAddr;
    vector<string> ip;
    backtrack(s, 0, ip, ipAddr);
    return ipAddr;
}

/*使用蛮力法
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ipAddr;
        int len = s.size();
        //i < len-2 防止只有四位数字时越界
        for (int i = 1; i < 4 && i < (len-2); ++i) {
            for (int j = i+1; j < i+4 && j < (len-1); ++j) {
                for (int k = j+1; k < j+4 && k < len; ++k) {
                    if (len -k > 3) //最后一个地址
                        continue;
                    string a = s.substr(0, i);
                    string b = s.substr(i, j-i);
                    string c = s.substr(j, k-j);
                    string d = s.substr(k, len-k);
                    if (isIp(a) && isIp(b) && isIp(c) && isIp(d))
                        ipAddr.push_back(a+"." + b + "." + c + "." + d);
                }
            }
        }
        return ipAddr;
    }
private:
    bool isIp(string str) {
        if (atoi(str.c_str()) > 255
            || str[0] == '0' && str.size() > 1)
            return false;
        return true;
    }
};

