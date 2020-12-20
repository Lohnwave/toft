/*
 * @Author: Lohnwave
 * @Email: waveluozu@163.com
 * @Date: 2020-12-20 14:07:11
 * @Last Modified by: Lohnwave
 * @Last Modified time: 2020-12-20 14:47:48
 * @Description: Description
 */
#ifndef TOFT_BASE_STRING_UTIL_H
#define TOFT_BASE_STRING_UTIL_H
#include <vector>
#include <string>

namespace toft{

    namespace StringUtil{
        
        int split(const std::string& str, char seperator, std::vector<std::string>& str_vec) {
            size_t current_pos = 0;
            size_t count = 0;
            while(1) {
                size_t next_pos = str.find(seperator, current_pos);
                if (next_pos == std::string::npos) {
                    std::string current_str = str.substr(current_pos);
                    if (current_str != " ") {
                        str_vec.push_back(current_str);
                        count ++;
                    }
                    break;
                }
                std::string current_str = str.substr(current_pos, next_pos - current_pos);
                str_vec.push_back(current_str);
                current_pos = next_pos + 1;
                count ++;
            }
            return count;
        }
        bool splitKeyValue(const std::string& str, char seperator, std::vector<std::string>& str_vec) {
            size_t current_pos = 0;
            size_t next_pos = str.find(seperator, current_pos);
            if (next_pos == std::string::npos) {
                return false;
            }
            std::string key = str.substr(current_pos, next_pos - current_pos);
            current_pos = next_pos + 1;
            std::string value = str.substr(current_pos);
            str_vec.push_back(key);
            str_vec.push_back(value);
            return true;
        }
    }


}


#endif // TOFT_BASE_STRING_UTIL_H