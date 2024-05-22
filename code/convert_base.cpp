ll convert_to_10(const string &input, int base) {
    assert(base >= 2 && base <= 36);
    bool is_neg = (input[0] == '-'); 
    int start = input.length() - 1;
    int end = is_neg ? 1 : 0;
    ll res = 0, digit_value = 1;
    for(int i = start; i >= end; i--) {
        char c = input[i];
        if (c >= '0' && c <= '9') c -= '0';
        else c = c - 'A' + 10;
        assert(c < base);
        res += c * digit_value;
        digit_value *= base;
    }
    if (is_neg) res *= -1;
    return res;
}
string convert_from_10(ll value, int base) {
    assert(base >= 2 && base <= 36);
    bool is_neg = (value < 0);
    if (is_neg) value *= -1;
    string res;
    do {
        char digit = value % base;
        if (digit < 10) digit += '0';
        else digit = digit + 'A' - 10;
        res += digit;
        value /= base;
        
    } while (value > 0);
    if (is_neg) res += '-';
    reverse(res.begin(), res.end());
    return res;
}
string convert_base(const string input, int base_from, int base_to) {
    return convert_from_10(convert_to_10(input, base_from), base_to);
}
