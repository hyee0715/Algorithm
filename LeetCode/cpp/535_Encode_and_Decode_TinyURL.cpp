class Solution {
public:

	unordered_map<string, string> um;
	string shortKey = "a";

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if (shortKey.length() > 1 && longUrl[longUrl.length() - 1] == 'z') {
			shortKey = shortKey + "a";
		}
		else {
			if (shortKey.length() == 1) {
				char c = shortKey[shortKey.length() - 1];

				shortKey = "";
				shortKey += (c + 1);
			}
			else {
				char c = shortKey[shortKey.length() - 1];
				shortKey = shortKey.substr(0, shortKey.length() - 1);

				shortKey = "";
				shortKey += (c + 1);
			}
		}

		um[shortKey] = longUrl;

		return shortKey;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return um[shortUrl];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));