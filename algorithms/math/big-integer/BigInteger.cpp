#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// supports only positive integers (for now)
struct BigInteger {
    string s;

    BigInteger(string s) {
        assert(all_of(s.begin(), s.end(), ::isdigit));
        reverse(s.begin(), s.end());
        while(not s.empty() and s.back()=='0') s.pop_back();
        reverse(s.begin(), s.end());
        this->s = s;
    }

    friend ostream& operator<<(ostream& o, const BigInteger& b) {
        if(b.s.empty()) o<<0;
        else o<<b.s;
        return o;
    }

    // addition in O(n) time
    BigInteger operator+(const BigInteger& b) {
        int i = s.size()-1, j = b.s.size()-1, carry = 0;
        string result;

        while(i>=0 or j>=0) {
            int sum = carry;
            if(i>=0) sum += (s[i--]-'0');
            if(j>=0) sum += (b.s[j--]-'0');
            result.push_back('0' + sum%10);
            carry = sum/10;
        }

        if(carry) result.push_back('1');
 
        reverse(result.begin(), result.end());

        return BigInteger(result);
    }

    // do multiplication in O(n^2) time using the naive multiplication algorithm
    BigInteger operator*(const BigInteger& b) {
        BigInteger result("0");
        string s_ = s;
        int i = b.s.size()-1;

        while(i>=0) {
            int d1 = b.s[i--]-'0', j = s_.size()-1, carry = 0;
            string temp;

            while(j >= 0) {
                int d2 = s_[j--]-'0';
                int val = d1 * d2 + carry;
                temp.push_back('0' + val%10);
                carry = val/10;
            }

            if(carry) temp.push_back('0' + carry);

            reverse(temp.begin(), temp.end());

            result = result + BigInteger(temp);

            s_.push_back('0');
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string num1, num2;

    cin>>num1; // 629693659826078926546969286916593405634265348651563041563
    cin>>num2; // 916592658916295624596420516450165724654956495694

    BigInteger b1(num1);
    BigInteger b2(num2);

    // addition
    BigInteger b3 = b1 + b2;

    cout<<num1<<" + "<<num2<<" = "<<b3<<endl; // 629693660742671585463264911513013922084431073306519537257

    // multiplication
    BigInteger b4 = b1 * b2; // // 577172585962719046336216279811715328353766449557291467790078236838104953065824715007810844549826552529722

    cout<<num1<<" * "<<num2<<" = "<<b4<<endl; 

    return 0;
}
