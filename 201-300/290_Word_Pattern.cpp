/*给一个模式串和一个字符串，问该字符串和模式串是不是相同的模式，比如pattern = "abba", str = "dog cat cat dog"，结果是对的，如果换成了
str = "dog cat cat fish"就是错误。这个题目用hash表，C++中可以用map，非常方便，我的解法是定义了两个hash表,这题和P204类似。结果是0ms,打败100%,
需要注意的是str的空格处理，要把子字符串一个个的分隔出来，与模式串对应。*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map <char,string> hash;
        map <string,char> hash1;
        vector<string> t;
        string temp;
        int i,begin=0,end=0;
        for(i=0;i<str.length();i++)
        {
             if(str[i]==' ')
             {
                 end=i;
                 t.push_back(str.substr(begin,end-begin));
                 begin=end+1;
             }
             
        }
        end=str.length();
        t.push_back(str.substr(begin,end-begin));
        if(pattern.length()!=t.size()) return false;
        else 
        {
          for(i=0;i<pattern.length();i++)
          {
             if(hash.count(pattern[i])==0) hash[pattern[i]]=t[i];   
             else if(hash[pattern[i]]!=t[i]) return false;
          } 
          for(i=0;i<t.size();i++)
          {
             if(hash1.count(t[i])==0) hash1[t[i]]=pattern[i];   
             else if(hash1[t[i]]!=pattern[i]) return false;
          } 
        }
        return true;
    }
};
