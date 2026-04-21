class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        const data = s.toLowerCase().split('');
        let lp = 0, rp = data.length - 1;
        while (lp < rp) {
            while (lp < rp && !this.alphaNum(data[lp])) {
                lp += 1;
            }
            while (lp < rp && !this.alphaNum(data[rp])) {
                rp -= 1;
            }
            if (data[lp] != data[rp]) {
                return false;
            }
            lp += 1;
            rp -= 1;
        }

        return true;
    }

    alphaNum(c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
}
